/*
 * main.c
 *
 *  Created on: 2015 Okt 24 22:18:22
 *  Author: jannik
 */

#include <XMC1100.h>
#include <DAVE.h>			//Declarations from DAVE Code Generation (includes SFR declaration)
#include "GPIO.h"

//#define DEBUG       // activate debug mode (answer each byte)

// UART baud rate constants for 115.2kbps @ MCLK=8MHz
#define FDR_STEP 590UL
#define BRG_PDIV 3UL
#define BRG_DCTQ 9UL
#define BRG_PCTQ 0UL

struct values {
  unsigned char throttle;
  unsigned char pitch;
  unsigned char roll;
  unsigned char yaw;
} pwm;

int pwmValueId = -1;

uint16_t dutyCycle = 0;

void UART_Init();


int main(void) {
  DAVE_STATUS_t status;
  status = DAVE_Init(); /* Initialization of DAVE Apps  */
  if (status == DAVE_STATUS_FAILURE) {
    /* Placeholder for error handler code. The while loop below can be replaced with an user error handler */
    XMC_DEBUG(("DAVE Apps initialization failed with status %d\n", status));
    while (1U) {
    }
  }

  // Clock configuration
  SCU_GENERAL->PASSWD = 0x000000C0UL; // disable bit protection
  SCU_CLK->CLKCR = 0x3FF00400UL; // MCLK = 8MHz, PCLK = 8MHz
  while ((SCU_CLK->CLKCR & SCU_CLK_CLKCR_VDDC2LOW_Msk))
    ;
  SCU_GENERAL->PASSWD = 0x000000C3UL; // enable bit protection
  SystemCoreClockUpdate();

  // Initialize and start UART
  UART_Init();
  P2_1_enable_digital();
  P2_2_enable_digital();

  // Initialize PWM Apps
  PWM_CCU4_Init(&PWM_CCU4_0); // P0.6
  PWM_CCU4_Init(&PWM_CCU4_1); // P0.7
  PWM_CCU4_Init(&PWM_CCU4_2); // P0.8
  PWM_CCU4_Init(&PWM_CCU4_3); // P0.9

  // status LED
  //P1_0_set_mode(OUTPUT_PP_GP);
  P1_1_set_mode(OUTPUT_PP_GP);  // LED 1
  P2_7_enable_digital();
  P2_7_set_mode(INPUT_PU); // emergency off


  // Initialize output values
  pwm.throttle = 254;
  pwm.pitch    = 127;
  pwm.roll     = 127;
  pwm.yaw      = 127;

  /*
   * main loop
   */
  while (1) {

    /*
     * step 1: get data
     */
    // If data received via UART
    if ((USIC0_CH0->TRBSR & 0x00000008) == 0) {
      unsigned char receivedData = USIC0_CH0->OUTR & 0x0000FFFF;
      if (0xFF == receivedData) {
        pwmValueId = 0;
      }

      P1_1_set(); // set LED1 as status LED

      if (pwmValueId >= 0) {
        switch (pwmValueId) {
        case 0:
          // discard start sequence
          pwmValueId++;
          USIC0_CH0->IN[0] = 0xFF;
          break;
        case 1:
          pwm.throttle = 254-receivedData;
          pwmValueId++;
#ifdef DEBUG
          USIC0_CH0->IN[0] = 0x10;
#endif
          break;
        case 2:
          pwm.pitch = 254-receivedData;
          pwmValueId++;
#ifdef DEBUG
          USIC0_CH0->IN[0] = 0x20;
#endif
          break;
        case 3:
          pwm.roll = 254-receivedData;
          pwmValueId++;
#ifdef DEBUG
          USIC0_CH0->IN[0] = 0x30;
#endif
          break;
        case 4:
          pwm.yaw = 254-receivedData;
          pwmValueId++;
#ifdef DEBUG
          USIC0_CH0->IN[0] = 0x40;
#endif
          break;
        default:
          // means that pwmValueId > 4 --> ERROR
          ;
        }
      }

    }else {
      P1_1_reset(); // reset LED1 as status LED
    }


    /*
     * step 2: set outputs
     */
    if (P2_7_read()) { // if emergency stop high --> stop motors
      PWM_CCU4_SetDutyCycle(&PWM_CCU4_0, 10000); // off (100% duty)
      PWM_CCU4_SetDutyCycle(&PWM_CCU4_1, 5000);  // half
      PWM_CCU4_SetDutyCycle(&PWM_CCU4_2, 5000);  // half
      PWM_CCU4_SetDutyCycle(&PWM_CCU4_3, 5000);  // half

    } else {
      dutyCycle = pwm.throttle * (uint32_t)10000 / 254;
      PWM_CCU4_SetDutyCycle(&PWM_CCU4_0, dutyCycle);
      dutyCycle = pwm.pitch * (uint32_t)10000 / 254;
      PWM_CCU4_SetDutyCycle(&PWM_CCU4_1, dutyCycle);
      dutyCycle = pwm.roll * (uint32_t)10000 / 254;
      PWM_CCU4_SetDutyCycle(&PWM_CCU4_2, dutyCycle);
      dutyCycle = pwm.yaw * (uint32_t)10000 / 254;
      PWM_CCU4_SetDutyCycle(&PWM_CCU4_3, dutyCycle);
    }

  } /* end main loop */
}


void UART_Init() {
  // Disable clock gating to USIC0
  SCU_GENERAL->PASSWD = 0x000000C0UL; // disable bit protection
  SCU_CLK->CGATCLR0 |= SCU_CLK_CGATCLR0_USIC0_Msk;
  SCU_GENERAL->PASSWD = 0x000000C3UL; // enable bit protection

  /* Enable the module kernel clock and the module functionality  */
  USIC0_CH0->KSCFG |= USIC_CH_KSCFG_MODEN_Msk | USIC_CH_KSCFG_BPMODEN_Msk;

  /* fFD = fPB */
  /* FDR.DM = 02b (Fractional divider mode) */
  USIC0_CH0->FDR &= ~(USIC_CH_FDR_DM_Msk | USIC_CH_FDR_STEP_Msk);
  USIC0_CH0->FDR |= (0x02UL << USIC_CH_FDR_DM_Pos) | (FDR_STEP << USIC_CH_FDR_STEP_Pos);

  /* Configure baud rate generator */
  /* BAUDRATE = fCTQIN/(BRG.PCTQ x BRG.DCTQ) */
  /* CLKSEL = 0 (fPIN = fFD), CTQSEL = 00b (fCTQIN = fPDIV), PPPEN = 0 (fPPP=fPIN) */
  USIC0_CH0->BRG &= ~(USIC_CH_BRG_PCTQ_Msk | USIC_CH_BRG_DCTQ_Msk | USIC_CH_BRG_PDIV_Msk | USIC_CH_BRG_CLKSEL_Msk
      | USIC_CH_BRG_PPPEN_Msk);
  USIC0_CH0->BRG |= (BRG_PCTQ << USIC_CH_BRG_PCTQ_Pos) | (BRG_DCTQ << USIC_CH_BRG_DCTQ_Pos)
      | (BRG_PDIV << USIC_CH_BRG_PDIV_Pos);

  /* Configuration of USIC Shift Control */
  /* SCTR.FLE = 8 (Frame Length) */
  /* SCTR.WLE = 8 (Word Length) */
  /* SCTR.TRM = 1 (Transmission Mode) */
  /* SCTR.PDL = 1 (This bit defines the output level at the shift data output signal when no data is available for transmission) */
  USIC0_CH0->SCTR &= ~(USIC_CH_SCTR_TRM_Msk | USIC_CH_SCTR_FLE_Msk | USIC_CH_SCTR_WLE_Msk);
  USIC0_CH0->SCTR |= USIC_CH_SCTR_PDL_Msk | (0x01UL << USIC_CH_SCTR_TRM_Pos) | (0x07UL << USIC_CH_SCTR_FLE_Pos)
      | (0x07UL << USIC_CH_SCTR_WLE_Pos);

  /* Configuration of USIC Transmit Control/Status Register */
  /* TBUF.TDEN = 1 (TBUF Data Enable: A transmission of the data word in TBUF can be started if TDV = 1 */
  /* TBUF.TDSSM = 1 (Data Single Shot Mode: allow word-by-word data transmission which avoid sending the same data several times*/
  USIC0_CH0->TCSR &= ~(USIC_CH_TCSR_TDEN_Msk);
  USIC0_CH0->TCSR |= USIC_CH_TCSR_TDSSM_Msk | (0x01UL << USIC_CH_TCSR_TDEN_Pos);

  /* Configuration of Protocol Control Register */
  /* PCR.SMD = 1 (Sample Mode based on majority) */
  /* PCR.STPB = 0 (1x Stop bit) */
  /* PCR.SP = 5 (Sample Point) */
  /* PCR.PL = 0 (Pulse Length is equal to the bit length) */
  USIC0_CH0->PCR &= ~(USIC_CH_PCR_ASCMode_STPB_Msk | USIC_CH_PCR_ASCMode_SP_Msk | USIC_CH_PCR_ASCMode_PL_Msk);
  USIC0_CH0->PCR |= USIC_CH_PCR_ASCMode_SMD_Msk | (5 << USIC_CH_PCR_ASCMode_SP_Pos);

  /* Configure Transmit Buffer */
  /* Standard transmit buffer event is enabled */
  /* Define start entry of Transmit Data FIFO buffer DPTR = 0*/
  USIC0_CH0->TBCTR &= ~(USIC_CH_TBCTR_SIZE_Msk | USIC_CH_TBCTR_DPTR_Msk);

  /* Set Transmit Data Buffer to 32 and set data pointer to position 0*/
  USIC0_CH0->TBCTR |= ((0x05 << USIC_CH_TBCTR_SIZE_Pos) | (0x00 << USIC_CH_TBCTR_DPTR_Pos));

  /* Initialize UART_RX (DX0)*/
  /* P2.2 as input */
  P2_2_set_mode(INPUT);

  /* Select P2.2 as input for USIC DX3 -> UCIC DX0 */
  USIC0_CH0->DX3CR &= ~(USIC_CH_DX3CR_DSEL_Msk);

  /* Route USIC DX3 input signal to USIC DX0 (DSEL=DX0G) */
  USIC0_CH0->DX0CR &= ~(USIC_CH_DX0CR_DSEL_Msk);
  USIC0_CH0->DX0CR |= 6 << USIC_CH_DX0CR_DSEL_Pos;

  /* Configure Receive Buffer */
  /* Standard Receive buffer event is enabled */
  /* Define start entry of Receive Data FIFO buffer DPTR = 32*/
  USIC0_CH0->RBCTR &= ~(USIC_CH_RBCTR_SIZE_Msk | USIC_CH_RBCTR_DPTR_Msk);

  /* Set Receive Data Buffer Size to 32 and set data pointer to position 32*/
  USIC0_CH0->RBCTR |= ((0x05UL << USIC_CH_RBCTR_SIZE_Pos) | (32 << USIC_CH_RBCTR_DPTR_Pos));

  /* Initialize UART_TX (DOUT)*/
  /* P2.1 as output controlled by ALT6 = U0C0.DOUT0 */
  P2_1_set_mode(OUTPUT_PP_AF6);

  /* Configuration of Channel Control Register */
  /* CCR.PM = 00 ( Disable parity generation) */
  /* CCR.MODE = 2 (ASC mode enabled. Note: 0 (USIC channel is disabled)) */
  USIC0_CH0->CCR &= ~(USIC_CH_CCR_PM_Msk | USIC_CH_CCR_MODE_Msk);
  USIC0_CH0->CCR |= 0x02UL << USIC_CH_CCR_MODE_Pos;
}
