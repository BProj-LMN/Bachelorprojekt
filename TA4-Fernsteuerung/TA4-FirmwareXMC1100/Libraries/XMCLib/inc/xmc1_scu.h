/**
 * @file xmc1_scu.h
 * @date 2015-06-20 
 *
 * @cond
*********************************************************************************************************************
 * XMClib v2.0.0 - XMC Peripheral Driver Library
 *
 * Copyright (c) 2015, Infineon Technologies AG
 * All rights reserved.                        
 *                                             
 * Redistribution and use in source and binary forms, with or without modification,are permitted provided that the 
 * following conditions are met:   
 *                                                                              
 * Redistributions of source code must retain the above copyright notice, this list of conditions and the following 
 * disclaimer.                        
 * 
 * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following 
 * disclaimer in the documentation and/or other materials provided with the distribution.                       
 * 
 * Neither the name of the copyright holders nor the names of its contributors may be used to endorse or promote 
 * products derived from this software without specific prior written permission.                                           
 *                                                                              
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, 
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
 * WHETHER IN CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                                                  
 *                                                                              
 * To improve the quality of the software, users are encouraged to share modifications, enhancements or bug fixes with 
 * Infineon Technologies AG dave@infineon.com).                                                          
 *********************************************************************************************************************
 *
 * Change History
 * --------------
 *
 * 2015-02-20:
 *     - Initial
 *      
 * 2015-05-20:
 *     - Description updated <br>
 *   
 * 2015-06-20:
 *     - XMC_SCU_INTERRUPT_EVENT enum elements are typecasted to int64_t
 * @endcond 
 *
 */

#ifndef XMC1_SCU_H
#define XMC1_SCU_H

/*********************************************************************************************************************
 * HEADER FILES
 ********************************************************************************************************************/
#include "xmc_common.h"

#if UC_FAMILY == XMC1

/**
 * @addtogroup XMClib XMC Peripheral Library
 * @{
 */
 
/**
 * @addtogroup SCU
 * @{
 */
/*********************************************************************************************************************
 * MACROS
 ********************************************************************************************************************/

/**
 * List of events 
 */
#define XMC_SCU_INTERRUPT_EVENT_WDT_WARN         SCU_INTERRUPT_SRMSK_PRWARN_Msk /**< WDT pre-warning event. */
#define XMC_SCU_INTERRUPT_EVENT_RTC_PERIODIC     SCU_INTERRUPT_SRCLR_PI_Msk     /**< RTC periodic event. */
#define XMC_SCU_INTERRUPT_EVENT_RTC_ALARM        SCU_INTERRUPT_SRCLR_AI_Msk     /**< RTC alarm event. */
#define XMC_SCU_INTERRUPT_EVENT_VDDPI            SCU_INTERRUPT_SRMSK_VDDPI_Msk  /**< VDDP pre-warning event. */
#if defined(COMPARATOR)
#define XMC_SCU_INTERRUPT_EVENT_ACMP0            SCU_INTERRUPT_SRMSK_ACMP0I_Msk /**< Analog comparator-0 output event. */
#define XMC_SCU_INTERRUPT_EVENT_ACMP1            SCU_INTERRUPT_SRMSK_ACMP1I_Msk /**< Analog comparator-1 output event. */
#define XMC_SCU_INTERRUPT_EVENT_ACMP2            SCU_INTERRUPT_SRMSK_ACMP2I_Msk /**< Analog comparator-2 output event. */
#if UC_SERIES == XMC14  
#define XMC_SCU_INTERRUPT_EVENT_ACMP3            (((int64_t)SCU_INTERRUPT_SRMSK1_ACMP3I_Msk) << 32U) /**< Analog comparator-3 output event. */
#endif  
#endif
#define XMC_SCU_INTERRUPT_EVENT_VDROP            SCU_INTERRUPT_SRMSK_VDROPI_Msk  /**< VDROP event. */
#if UC_SERIES != XMC11
#define XMC_SCU_INTERRUPT_EVENT_ORC0             SCU_INTERRUPT_SRMSK_ORC0I_Msk   /**< Out of range comparator-0 event. */
#define XMC_SCU_INTERRUPT_EVENT_ORC1             SCU_INTERRUPT_SRMSK_ORC1I_Msk   /**< Out of range comparator-1 event. */
#define XMC_SCU_INTERRUPT_EVENT_ORC2             SCU_INTERRUPT_SRMSK_ORC2I_Msk   /**< Out of range comparator-2 event. */
#define XMC_SCU_INTERRUPT_EVENT_ORC3             SCU_INTERRUPT_SRMSK_ORC3I_Msk   /**< Out of range comparator-3 event. */
#define XMC_SCU_INTERRUPT_EVENT_ORC4             SCU_INTERRUPT_SRMSK_ORC4I_Msk   /**< Out of range comparator-4 event. */
#define XMC_SCU_INTERRUPT_EVENT_ORC5             SCU_INTERRUPT_SRMSK_ORC5I_Msk   /**< Out of range comparator-5 event. */
#define XMC_SCU_INTERRUPT_EVENT_ORC6             SCU_INTERRUPT_SRMSK_ORC6I_Msk   /**< Out of range comparator-6 event. */
#define XMC_SCU_INTERRUPT_EVENT_ORC7             SCU_INTERRUPT_SRMSK_ORC7I_Msk   /**< Out of range comparator-7 event. */
#endif
#define XMC_SCU_INTERRUPT_EVENT_LOCI             SCU_INTERRUPT_SRMSK_LOCI_Msk    /**< Loss of clock event. */
#define XMC_SCU_INTERRUPT_EVENT_PESRAM           SCU_INTERRUPT_SRMSK_PESRAMI_Msk /**< PSRAM Parity error event. */
#define XMC_SCU_INTERRUPT_EVENT_PEUSIC0          SCU_INTERRUPT_SRMSK_PEU0I_Msk   /**< USIC0 Parity error event. */
#if defined(USIC1)
#define XMC_SCU_INTERRUPT_EVENT_PEUSIC1          (((int64_t)SCU_INTERRUPT_SRMSK1_PEU1I_Msk) << 32U)   /**< USIC1 Parity error event. */
#endif
#define XMC_SCU_INTERRUPT_EVENT_FLASH_ERROR      SCU_INTERRUPT_SRMSK_FLECC2I_Msk /**< Flash ECC double bit error event. */
#define XMC_SCU_INTERRUPT_EVENT_FLASH_COMPLETED  SCU_INTERRUPT_SRCLR_FLCMPLTI_Msk /**< Flash operation completion event. */
#define XMC_SCU_INTERRUPT_EVENT_VCLIP            SCU_INTERRUPT_SRMSK_VCLIPI_Msk  /**< VCLIP event. */
#define XMC_SCU_INTERRUPT_EVENT_STDBYCLKFAIL     SCU_INTERRUPT_SRMSK_SBYCLKFI_Msk  /**< Standby clock failure event. */
#define XMC_SCU_INTERRUPT_EVENT_RTCCTR_UPDATED   SCU_INTERRUPT_SRMSK_RTC_CTR_Msk  /**< RTCCTR register update event. */
#define XMC_SCU_INTERRUPT_EVENT_RTCATIM0_UPDATED SCU_INTERRUPT_SRMSK_RTC_ATIM0_Msk  /**< RTCATIM0 register update event. */
#define XMC_SCU_INTERRUPT_EVENT_RTCATIM1_UPDATED SCU_INTERRUPT_SRMSK_RTC_ATIM1_Msk  /**< RTCATIM1 register update event. */
#define XMC_SCU_INTERRUPT_EVENT_RTCTIM0_UPDATED  SCU_INTERRUPT_SRMSK_RTC_TIM0_Msk  /**< RTCTIM0 register update event. */
#define XMC_SCU_INTERRUPT_EVENT_RTCTIM1_UPDATED  SCU_INTERRUPT_SRMSK_RTC_TIM1_Msk  /**< RTCTIM1 register update event. */
#define XMC_SCU_INTERRUPT_EVENT_TSE_DONE         SCU_INTERRUPT_SRMSK_TSE_DONE_Msk  /**< Temperature measurement Completion event. */
#define XMC_SCU_INTERRUPT_EVENT_TSE_HIGH         SCU_INTERRUPT_SRMSK_TSE_HIGH_Msk  /**< Temperature too high event. */
#define XMC_SCU_INTERRUPT_EVENT_TSE_LOW          SCU_INTERRUPT_SRMSK_TSE_LOW_Msk /**< Temperature too low event. */
#if defined(CAN)  
#define XMC_SCU_INTERRUPT_EVENT_PEMCAN           (((int64_t)SCU_INTERRUPT_SRMSK1_PEMCI_Msk) << 32U)   /**< MultiCAN SRAM Parity Error Event. */
#endif  
#if (UC_SERIES == XMC14)
#define XMC_SCU_INTERRUPT_EVENT_LOSS_EXT_CLOCK   (((int64_t)SCU_INTERRUPT_SRMSK1_LOECI_Msk) << 32U)  /**< Loss of external OSC_HP clock event. */
#define XMC_SCU_INTERRUPT_EVENT_DCO1_OUT_SYNC    (((int64_t)SCU_INTERRUPT_SRMSK1_DCO1OFSI_Msk) << 32U)   /**< DCO1 Out of SYNC Event. */
#endif
 
/*********************************************************************************************************************
 * ENUMS
 ********************************************************************************************************************/

/**
 *  Defines the cause of last reset. The cause of last reset gets automatically stored in
 *  the \a SCU_RSTSTAT register and can be checked by user software to determine the state of the system and for debug
 *  purpose. All the enum items are tabulated as per bits present in \a SCU_RSTSTAT register.
 *  Use type \a XMC_SCU_RESET_REASON_t for accessing these enum parameters.
 */
typedef enum XMC_SCU_RESET_REASON
{
  XMC_SCU_RESET_REASON_PORST        = (1UL << SCU_RESET_RSTSTAT_RSTSTAT_Pos),  /**< Reset due to Power On reset. */
  XMC_SCU_RESET_REASON_MASTER       = (2UL << SCU_RESET_RSTSTAT_RSTSTAT_Pos),  /**< Reset due to Master reset. */
  XMC_SCU_RESET_REASON_SW           = (4UL << SCU_RESET_RSTSTAT_RSTSTAT_Pos),  /**< Reset due to Software initiated reset. */
  XMC_SCU_RESET_REASON_LOCKUP       = (8UL << SCU_RESET_RSTSTAT_RSTSTAT_Pos),  /**< Reset due to CPU lockup. */
  XMC_SCU_RESET_REASON_FLASH        = (16UL << SCU_RESET_RSTSTAT_RSTSTAT_Pos), /**< Reset due to flash error. */
  XMC_SCU_RESET_REASON_WATCHDOG     = (32UL << SCU_RESET_RSTSTAT_RSTSTAT_Pos), /**< Reset due to watchdog. */
  XMC_SCU_RESET_REASON_CLOCK_LOSS   = (64UL << SCU_RESET_RSTSTAT_RSTSTAT_Pos), /**< Reset due to clock loss. */
  XMC_SCU_RESET_REASON_PARITY_ERROR = (128UL << SCU_RESET_RSTSTAT_RSTSTAT_Pos) /**< Reset due to RAM parity error. */
} XMC_SCU_RESET_REASON_t;

/**
 *  Defines the reset sources that can cause device reset. These enums can be used to configure reset source in reset
 *  control \a RSTCON register which enables different reset sources to identify the reset cause. The \a SCU_RSTSTAT
 *  register can be checked by user software to determine the state of the system and for debug
 *  purpose. Use type \a XMC_SCU_SYSTEM_RESET_REQUEST_t for accessing these enum parameters.
 */
typedef enum XMC_SCU_SYSTEM_RESET_REQUEST
{
  XMC_SCU_RESET_REQUEST_FLASH_ECC_ERROR = SCU_RESET_RSTCON_ECCRSTEN_Msk,        /**< Reset when ECC double bit error occurs.*/
  XMC_SCU_RESET_REQUEST_CLOCK_LOSS = SCU_RESET_RSTCON_LOCRSTEN_Msk,             /**< Reset when loss of clock occurs.*/
  XMC_SCU_RESET_REQUEST_SRAM_PARITY_ERROR = SCU_RESET_RSTCON_SPERSTEN_Msk,      /**< Reset when SRAM parity error occurs.*/
  XMC_SCU_RESET_REQUEST_USIC_SRAM_PARITY_ERROR = SCU_RESET_RSTCON_U0PERSTEN_Msk /**< Reset when USIC0 memory parity error occurs.*/
} XMC_SCU_SYSTEM_RESET_REQUEST_t;
 
/**
 *  Defines list of events that can generate SCU interrupt. These enums can be used to configure events 
 *  in \a SRMSK register for assertion of interrupt. All the enum items are tabulated as per bits present
 *  in \a SRMSK register. Use type \a XMC_SCU_INTERRUPT_EVENT_t for accessing these enum parameters. These
 *  enums can also be used for checking the status of events from the \a SRSTAT register.
 */
#if (UC_SERIES == XMC14)
typedef uint64_t XMC_SCU_INTERRUPT_EVENT_t;
#else
typedef uint32_t XMC_SCU_INTERRUPT_EVENT_t;
#endif

/**
 *  Defines possible sources of RTC clock. These enums can be used to configure \a RTCCLKSEL bits of \a CLKCR Clock Control
 *  Register. Use type \a XMC_SCU_CLOCK_RTCCLKSRC_t for accessing these enum parameters.
 */ 
typedef enum XMC_SCU_CLOCK_RTCCLKSRC
{
  XMC_SCU_CLOCK_RTCCLKSRC_DCO2 = (0x0UL << SCU_CLK_CLKCR_RTCCLKSEL_Pos), /**< RTC clock source is standby clock. */
  XMC_SCU_CLOCK_RTCCLKSRC_ERU_IOUT0 = (0x1UL << SCU_CLK_CLKCR_RTCCLKSEL_Pos), /**< RTC clock source is external clock from 
                                                                                   ERU0.IOUT0. */
  XMC_SCU_CLOCK_RTCCLKSRC_ACMP0_OUT = (0x2UL << SCU_CLK_CLKCR_RTCCLKSEL_Pos), /**< RTC clock source is external clock from 
                                                                                   ACMP0.OUT. */
  XMC_SCU_CLOCK_RTCCLKSRC_ACMP1_OUT = (0x3UL << SCU_CLK_CLKCR_RTCCLKSEL_Pos), /**< RTC clock source is external clock from 
                                                                                  ACMP1.OUT. */
  XMC_SCU_CLOCK_RTCCLKSRC_ACMP2_OUT = (0x4UL << SCU_CLK_CLKCR_RTCCLKSEL_Pos) /**< RTC clock source is external clock from 
                                                                                  ACMP2.OUT. */
} XMC_SCU_CLOCK_RTCCLKSRC_t;

/**
 *  Defines possible sources of peripheral clock (PCLK). These enums can be used to configure \a PCLKSEL bits of \a CLKCR
 *  Clock Control Register. Use type \a XMC_SCU_CLOCK_PCLKSRC_t for accessing these enum parameters.
 */ 
typedef enum XMC_SCU_CLOCK_PCLKSRC
{
  XMC_SCU_CLOCK_PCLKSRC_MCLK = (0UL << SCU_CLK_CLKCR_PCLKSEL_Pos), /**< MCLK as the source for PCLK. */
  XMC_SCU_CLOCK_PCLKSRC_DOUBLE_MCLK = (1UL << SCU_CLK_CLKCR_PCLKSEL_Pos) /**< Source of PCLK is twice the MCLK. */
} XMC_SCU_CLOCK_PCLKSRC_t;

/**
 *  Defines th list of various sources that support gating of clock to peripherals. After a master reset, only core, memories, SCU 
 *  and PORT peripheral are not clock gated. The rest of the peripherals are default clock gated.
 *  All the enum items are tabulated as per bits present in \a CGATSTAT0 register.
 *  Use type \a XMC_SCU_PERIPHERAL_CLOCK_t for accessing these enum parameters.
 */
typedef enum XMC_SCU_PERIPHERAL_CLOCK
{
  XMC_SCU_PERIPHERAL_CLOCK_VADC   = SCU_CLK_CGATSTAT0_VADC_Msk, /**< VADC peripheral clock gate. */
#if defined(CCU80)
  XMC_SCU_PERIPHERAL_CLOCK_CCU80  = SCU_CLK_CGATSTAT0_CCU80_Msk, /**< CCU80 peripheral clock gate. */
#endif
  XMC_SCU_PERIPHERAL_CLOCK_CCU40  = SCU_CLK_CGATSTAT0_CCU40_Msk, /**< CCU40 peripheral clock gate. */
  XMC_SCU_PERIPHERAL_CLOCK_USIC0  = SCU_CLK_CGATSTAT0_USIC0_Msk, /**< USIC0 peripheral clock gate. */
#if defined(BCCU0)
  XMC_SCU_PERIPHERAL_CLOCK_BCCU0  = SCU_CLK_CGATSTAT0_BCCU0_Msk, /**< BCCU0 peripheral clock gate. */
#endif
#if defined(LEDTS0)
  XMC_SCU_PERIPHERAL_CLOCK_LEDTS0 = SCU_CLK_CGATSTAT0_LEDTS0_Msk, /**< LEDTS0 peripheral clock gate. */
#endif
#if defined(LEDTS1)
  XMC_SCU_PERIPHERAL_CLOCK_LEDTS1 = SCU_CLK_CGATSTAT0_LEDTS1_Msk, /**< LEDTS1 peripheral clock gate. */
#endif
#if defined(POSIF0)
  XMC_SCU_PERIPHERAL_CLOCK_POSIF0 = SCU_CLK_CGATSTAT0_POSIF0_Msk, /**< POSIF0 peripheral clock gate. */
#endif
#if defined(MATH)
  XMC_SCU_PERIPHERAL_CLOCK_MATH   = SCU_CLK_CGATSTAT0_MATH_Msk, /**< MATH peripheral clock gate. */
#endif
  XMC_SCU_PERIPHERAL_CLOCK_WDT    = SCU_CLK_CGATSTAT0_WDT_Msk, /**< WDT peripheral clock gate. */
  XMC_SCU_PERIPHERAL_CLOCK_RTC    = SCU_CLK_CGATSTAT0_RTC_Msk /**< RTC peripheral clock gate. */
} XMC_SCU_PERIPHERAL_CLOCK_t;

/**
 *  Defines different states used while changing the device sleep modes. 
 *  Use type \a XMC_SCU_SLEEP_CLK_INSTR_t for accessing these enum parameters.
 */
typedef enum XMC_SCU_SLEEP_CLK_INSTR 
{
  XMC_SCU_SLEEP_CLK_INSTR_ENTER = 0UL, /**< Enter sleep mode : In this state, a snapshot of clocks that are
                 active is taken. All peripheral clocks are disabled before sleep mode instruction (WFI) is executed. */
  XMC_SCU_SLEEP_CLK_INSTR_EXIT     , /**< Exit sleep mode : In this state, all the peripheral clocks
                 that were active before entering the sleep mode are enabled. */
} XMC_SCU_SLEEP_CLK_INSTR_t;

/**
 *  Defines options for Capture/Compare unit timer slice trigger that enables synchronous start function available on the \a SCU,
 *  \a CCUCON register. Use type \a XMC_SCU_CCU_TRIGGER_t for accessing these enum parameters.
 */
typedef enum XMC_SCU_CCU_TRIGGER
{ 
  XMC_SCU_CCU_TRIGGER_CCU40 = SCU_GENERAL_CCUCON_GSC40_Msk, /**< Trigger CCU40 peripheral. */
#if defined(CCU80)
  XMC_SCU_CCU_TRIGGER_CCU80 = SCU_GENERAL_CCUCON_GSC80_Msk, /**< Trigger CCU80 peripheral. */
#endif
} XMC_SCU_CCU_TRIGGER_t;

/*********************************************************************************************************************
 * DATA STRUCTURES
 ********************************************************************************************************************/
/**
 *  Defines a data structure for initializing the data of the supply voltage monitoring block.
 *  Supply voltage monitoring block consists of 2 detectors namely External voltage detector (VDEL) and External brownout
 *  detector (BDE) in the EVR that are used to monitor the VDDP. \a VDEL detector compares the supply voltage against a
 *  pre-warning threshold voltage. 
 *  Use type \a XMC_SCU_SUPPLYMONITOR_t for accessing these structure parameters.
 */
typedef struct XMC_SCU_SUPPLYMONITOR
{
  uint32_t ext_supply_threshold;   /**<  External supply range (VDEL Range Select).\n
                                         \b Range:\n
                                         00B sets threshold value to 2.25V, 01B sets threshold value to 3.0V and
                                         10B sets threshold value to 4.4V */
  uint32_t ext_supply_monitor_speed; /**<  Speed of the voltage monitor(VDEL Timing Setting).\n
                                           \b Range: \n
                                           00B sets monitor speed typ 1µs - slowest response time, 01B sets monitor
                                           speed typ 500n,  10B sets monitor speed typ 250n, 11B sets monitor speed
                                           with no delay - fastest response time. */
  bool     enable_prewarning_int;    /**< Configure pre-warning interrupt generation.\n
                                          \b Range: \a true to enable the interrupt.*/
  bool     enable_vdrop_int;         /**< Configure VDROP interrupt generation. \n
                                          \b Range: \a true to enable the interrupt.*/
  bool     enable_vclip_int;         /**< Configure VCLIP interrupt . 
                                          \b Range: \a true to enable the interrupt.*/
  bool     enable_at_init;           /**< Whether the monitor has to be enabled (VDEL unit Enable)
                                          after initialization. \n
                                          \b Range: \a true to enable after initialization.*/
} XMC_SCU_SUPPLYMONITOR_t;
 
/**
 *  Defines a data structure for initializing the data of the clock functional block.
 *  Clock functional block configures clock dividers, peripheral and RTC clock source by configuring corresponding 
 *  bits in \a CLKCR clock control register.
 *  Use type \a XMC_SCU_CLOCK_CONFIG_t for accessing these structure parameters.
 */
typedef struct XMC_SCU_CLOCK_CONFIG
{
  XMC_SCU_CLOCK_PCLKSRC_t pclk_src; /**<  Source of PCLK Clock.\n
                                     \b Range: \n 
                                     XMC_SCU_CLOCK_PCLKSRC_MCLK- PCLK as a MCLK, \n 
                                     XMC_SCU_CLOCK_PCLKSRC_DOUBLE_MCLK- PCLK as twice the MCLK. */
  XMC_SCU_CLOCK_RTCCLKSRC_t rtc_src; /**<  Source of RTC Clock.\n
                                    \b Range: \n
                                    XMC_SCU_CLOCK_RTCCLKSRC_DCO2- standby clock as RTC clock, \n 
                                    XMC_SCU_CLOCK_RTCCLKSRC_ERU_IOUT0- external clock from ERU0.IOUT0, \n
                                    XMC_SCU_CLOCK_RTCCLKSRC_ACMP0_OUT- external clock from ACMP0.OUT, \n 
                                    XMC_SCU_CLOCK_RTCCLKSRC_ACMP1_OUT- external clock from ACMP1.OUT, \n 
                                    XMC_SCU_CLOCK_RTCCLKSRC_ACMP2_OUT- external clock from ACMP2.OUT
                                    */
  uint8_t fdiv; /**<  Fractional divider selection(FDIV). \b Range: 0 to 255. */
  uint8_t idiv; /**<  Clock divider value(IDIV). \b Range:\n
                      00H- Divider is bypassed,\n 
                      01H- MCLK = 32 MHz,\n 
                      02H- MCLK = 16 MHz,\n
                      03H- MCLK = 10.67 MHz,\n 
                      04H- MCLK = 8 MHz,\n
                      FEH- MCLK = 126 kHz,\n 
                      FFH- MCLK = 125.5 kHz */
} XMC_SCU_CLOCK_CONFIG_t;

/**
 *  Defines the data structure for initializing the deep sleep mode.
 *  During deep sleep mode peripheral clock is disabled and flash is powered down.
 *  Use type \a XMC_SCU_CLOCK_DEEP_SLEEP_t for accessing these structure parameters.
 */
typedef struct XMC_SCU_CLOCK_DEEP_SLEEP
{
  bool     flash_power_down;   /**< Whether the device flash memory has to be powered down
                                    during deep sleep mode.\n 
                                    \b Range: Set true to disable flash in deep sleep mode.*/
  uint32_t clock_gating_mask; /**< Configures mask value of clocks to be gated during deep sleep.\n
                                    \b Range: Use type @ref XMC_SCU_PERIPHERAL_CLOCK_t to get the bitmask
                                    of the peripheral clocks. Multiple peripherals can be combined by
                                    using the \a OR operation.*/
} XMC_SCU_CLOCK_DEEP_SLEEP_t;
 
/*********************************************************************************************************************
 * API PROTOTYPES
 ********************************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/**
 *
 * @return None
 *
 * \par<b>Description</b><br>
 * Locks access to protected bit fields of the SCU.\n\n
 * The bit protection scheme prevents changing selected register bits by unauthorized code. 
 * Bit protection scheme is enabled by writing 000000C3H to \a PASSWD register. By writing 
 * this value, the API is setting the \a MODE bit field to bit protection enabled state.\n
 * List of Protected Register Bit Fields are mentioned below. \n
 * <table>
 *   <tr><td> \a Register    </td> <td>\a Bit fields                  </td></tr>
 *   <tr><td> SCU_CLKCR      </td> <td> FDIV, IDIV, PCLKSEL, RTCLKSEL </td></tr>
 *   <tr><td> SCU_CGATSET0   </td> <td> All bits                      </td></tr>
 *   <tr><td> SCU_CGATCLR0   </td> <td> All bits                      </td></tr>
 *   <tr><td> SCU_ANAOFFSET  </td> <td> ADJL_OFFSET                   </td></tr>
 *   <tr><td> VADC0_ACCPROT0 </td> <td> All bits                      </td></tr>
 *   <tr><td> VADC0_ACCPROT1 </td> <td> All bits                      </td></tr>
 * </table>
 * 
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_UnlockProtectedBits() \n\n\n
 */
void XMC_SCU_LockProtectedBits(void);
 
/**
 *
 * @return None
 *
 * \par<b>Description</b><br>
 * Unlocks access to protected bit fields of the SCU.\n\n
 * The bit protection scheme prevents changing selected register bits by unauthorized code. 
 * Bit protection scheme can be temporarily(for 32 MCLK cycles) disabled by writing 000000C0H to \a PASSWD register. 
 * By writing this value, the API is setting the \a MODE bit field to bit protection disabled state. The API
 * waits for the protection to be disabled after changing the \a MODE.\n
 * User can change the values of the protected bit fields within 32 MCLK cycles. After 32 MCLK cycles the lock will
 * be enabled automatically. 
 * List of Protected Register Bit Fields are mentioned below. \n
 * <table>
 *   <tr><td> \a Register    </td> <td>\a Bit fields                  </td></tr>
 *   <tr><td> SCU_CLKCR      </td> <td> FDIV, IDIV, PCLKSEL, RTCLKSEL </td></tr>
 *   <tr><td> SCU_CGATSET0   </td> <td> All bits                      </td></tr>
 *   <tr><td> SCU_CGATCLR0   </td> <td> All bits                      </td></tr>
 *   <tr><td> SCU_ANAOFFSET  </td> <td> ADJL_OFFSET                   </td></tr>
 *   <tr><td> VADC0_ACCPROT0 </td> <td> All bits                      </td></tr>
 *   <tr><td> VADC0_ACCPROT1 </td> <td> All bits                      </td></tr>
 * </table>
 * 
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_LockProtectedBits() \n\n\n
 */
void XMC_SCU_UnlockProtectedBits(void);

/**
 *
 * @param obj   Pointer to data structure consisting voltage monitoring block configuration.\n
 *               \b Range: Use type @ref XMC_SCU_SUPPLYMONITOR_t for detailed description of structure members.
 *
 * @return None
 *
 * \par<b>Description</b><br>
 * Initializes power supply monitoring unit.\n\n
 * Supply voltage monitoring block consist of 2 detectors namely External voltage detector (VDEL) and External brownout
 * detector (BDE) in the EVR that are used to monitor the VDDP. \a VDEL detector compares the supply voltage against a
 * pre-warning threshold voltage \a ext_supply_threshold. The threshold level is programmable via register \a ANAVDEL.VDEL_SELECT. An interrupt
 * if enabled via \a enable_prewarning_int, will be triggered if a level below this threshold is detected and the flag, VDDPI,
 * in SRRAW register bit is set. Similarly interrupts can be enabled for the events of VCLIP and prewarning, using the structure members,
 * \a enable_vclip_int and \a enable_prewarning_int.  The handlers for these interrupts have to be explicitly defined using
 * the API XMC_SCU_INTERRUPT_SetEventHandler().
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_INTERRUPT_SetEventHandler()\n\n\n
 */
void XMC_SCU_SupplyMonitorInit(const XMC_SCU_SUPPLYMONITOR_t *obj);

/**
 *
 * @param lower_temp  Lower threshold value for the die temperature.\n
 *          \b Range: 0 to 65535(16 bit unsigned value).
 * @param upper_temp  Upper threshold value for the die temperature.\n
 *          \b Range: 0 to 65535(16 bit unsigned value).
 *
 * @return None
 *
 * \par<b>Description</b><br>
 * Configures upper and lower thresholds of die temperature as raw digital values into temperature sensor.\n\n
 * The API configures \a ANATSEIH and \a ANATSEIL registers for upper and lower die temperature threshold limits
 * respectively.\n
 * It is recommended to use following steps:\n
 * - Call \a XMC_SCU_StopTempMeasurement to stop temperature measurement if it was started previously.\n
 * - Call \a XMC_SCU_SetRawTempLimits with desired lower and upper temperature threshold limit values.\n
 * - Finally call \a XMC_SCU_StartTempMeasurement to start temperature measurement.\n
 *
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_StopTempMeasurement(), XMC_SCU_StartTempMeasurement() \n\n\n
 */

void XMC_SCU_SetRawTempLimits(const uint32_t lower_temp, const uint32_t upper_temp);

// /* API to program temperature limits in centigrade into temperature sensor unit */ // need to implement in future
// void XMC_SCU_SetTempLimits(const uint32_t lower_temp, const uint32_t upper_temp);
/**
 *
 * @return XMC_SCU_STATUS_t   Status of starting the temperature measurement.\n
 *                  \b Range: Use type @ref XMC_SCU_STATUS_t to identify the result.\n
 *                  XMC_SCU_STATUS_OK- Temperature measurement started successfully.\n
 *                  Always returns the above status.
 *
 * \par<b>Description</b><br>
 * Starts die temperature measurement using internal temperature sensor.\n\n
 * The API, enables die temperature measurement and waits for about 10000 cycles until 
 * temperature measurement result is available on \a SCU_ANALOG->ANATSEMON bit fields.\n
 * It is recommended to use following steps:\n
 * - Call \a XMC_SCU_StopTempMeasurement to stop temperature measurement if it was started previously.\n
 * - Call \a XMC_SCU_SetRawTempLimits with desired lower and upper temperature threshold limit values if it is needed.\n
 * - Call \a XMC_SCU_StartTempMeasurement to start temperature measurement.\n
 * - Read die temperature value using \a XMC_SCU_GetTemperature API.\n
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_StopTempMeasurement(), XMC_SCU_SetRawTempLimits(), XMC_SCU_GetTemperature() \n\n\n
 */
void XMC_SCU_StartTempMeasurement(void);

/**
 * @return None   
 *
 * \par<b>Description</b><br>
 * Stops the die temperature measurement.\n\n
 * Die temperature measurement is stopped by disabling the sensor using \a TSE_EN bit of 
 * \a ANATSECTRL register.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_StartTempMeasurement(), XMC_SCU_SetRawTempLimits(), XMC_SCU_GetTemperature() \n\n\n
 */
void XMC_SCU_StopTempMeasurement(void);

/**
 *
 * @return bool  Result of checking whether the die temperature is more than the upper threshold.\n
 *            \b Range: \a false if temperature is below the upper threshold. \a true if temperature 
 *            has exceeded the upper threshold configured in \a ANATSEIH register.
 *
 * \par<b>Description</b><br>
 * Check if the temperature has exceeded the upper threshold value.\n\n
 * The API checks for \a TSE_HIGH bit (TSE Compare High Temperature Event Status bit) of \a SRRAW register.
 * The bit will be set when the \a TSE_MON value in \a ANATSEMON register exceeds the value of 
 * \a TSE_IH value in \a ANATSEIH register.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_StartTempMeasurement(), XMC_SCU_SetRawTempLimits(), XMC_SCU_GetTemperature(), XMC_SCU_LowTemperature() \n\n\n
 */
bool XMC_SCU_HighTemperature(void);

/**
 *
 * @return bool  Result of checking whether the die temperature is less than the lower threshold.\n
 *            \b Range: \a false if temperature is higher than the lower threshold. \a true if temperature 
 *            has dropped below the lower threshold configured in \a ANATSEIL register.
 *
 * \par<b>Description</b><br>
 * Check if the temperature has dropped below the lower threshold value.\n\n
 * The API checks for \a TSE_LOW bit (TSE Compare Low Temperature Event Status bit) of \a SRRAW register.
 * The bit will be set when the \a TSE_MON value in \a ANATSEMON register drops below the value of 
 * \a TSE_IL value in \a ANATSEIL register.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_StartTempMeasurement(), XMC_SCU_SetRawTempLimits(), XMC_SCU_GetTemperature(), XMC_SCU_HighTemperature() \n\n\n
 */
bool XMC_SCU_LowTemperature(void);

/**
 * @return uint32_t  Die temperature value. \b Range: 16 bit value.
 *
 * \par<b>Description</b><br>
 * Provides the die temperature value.\n\n
 * The API reads temperature measurement result from \a SCU_ANALOG->ANATSEMON bit fields.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_StartTempMeasurement(), XMC_SCU_SetRawTempLimits(), XMC_SCU_HighTemperature() \n\n\n
 */

uint32_t XMC_SCU_GetTemperature(void);
 
/**
 *
 * @return
 */
__STATIC_INLINE bool XMC_SCU_IsTempMeasurementDone(void)
{
  return ((SCU_INTERRUPT->SRRAW & SCU_INTERRUPT_SRRAW_TSE_DONE_Msk) != 0U);
}

/**
 * @return None
 *
 * \par<b>Description</b><br>
 * Trigger device master reset.\n\n
 * The API triggers master reset by setting the \a MRSTEN bit of \a RSTCON register.
 * It also internally triggers system reset. Almost all the logics of the device are affected by this reset.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_RESET_EnableResetRequest() \n\n\n
 */
__STATIC_INLINE void XMC_SCU_RESET_AssertMasterReset(void)
{
  SCU_RESET->RSTCON |= SCU_RESET_RSTCON_MRSTEN_Msk;
}
/**
 *
 * @param request  Reset source to trigger the device reset.\n
 *          \b Range: Use type @ref XMC_SCU_SYSTEM_RESET_REQUEST_t to identify the reset source.\n
 *          XMC_SCU_RESET_REQUEST_FLASH_ECC_ERROR- Reset when flash memory double bit error is detected.\n
 *          XMC_SCU_RESET_REQUEST_CLOCK_LOSS- Reset when loss of clock is detected.\n
 *          XMC_SCU_RESET_REQUEST_SRAM_PARITY_ERROR- Reset when SRAM parity error is detected.\n
 *          XMC_SCU_RESET_REQUEST_USIC_SRAM_PARITY_ERROR- Reset when USIC0 SRAM parity error is detected.\n
 *
 * @return None
 *
 * \par<b>Description</b><br>
 * Configures trigger for system reset from the selected source.\n\n
 * The API configures the reset source specific bit in the \a RSTCON register.
 * Multiple reset sources can be combined using \a OR operation. By enabling
 * the reset using this API will not trigger the reset. The reset will happen when 
 * the configured source event is detected.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_RESET_AssertMasterReset() \n\n\n
 */
__STATIC_INLINE void XMC_SCU_RESET_EnableResetRequest(uint32_t request)
{
  SCU_RESET->RSTCON |= request;
}


/**
 *
 * @return uint32_t  Fast peripheral clock frequency in Hertz.
 *
 * \par<b>Description</b><br>
 * Provides the clock frequency of peripherals on the peripheral bus that are using a shared functional clock.\n\n
 * The value is derived using the bitfield \a PCLKSEL from \a CLKCR register. Peripheral clock
 * can have 2 times the frequency of system clock if the \a PCLKSEL is set. 
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_SetFastPeripheralClockSource() \n\n\n
 */
uint32_t XMC_SCU_CLOCK_GetFastPeripheralClockFrequency(void);


/**
 *
 * @param source  Fast peripheral clock source.\n
 *          \b Range: Use type @ref XMC_SCU_CLOCK_PCLKSRC_t to identify the clock source.\n
 *          XMC_SCU_CLOCK_PCLKSRC_MCLK- Use MCLK as the peripheral clock.\n
 *          XMC_SCU_CLOCK_PCLKSRC_DOUBLE_MCLK- peripheral clock will be 2 times the MCLK frequency.
 *
 * @return None
 *
 * \par<b>Description</b><br>
 * Configures the source of peripheral clock. \n\n
 * The peripheral clock can be either same as MCLK or twice the frequency of MCLK.
 * \par<b>Related APIs:</b><BR>
 * XMC_SCU_CLOCK_GetFastPeripheralClockFrequency() \n\n\n
 */
void XMC_SCU_CLOCK_SetFastPeripheralClockSource(const XMC_SCU_CLOCK_PCLKSRC_t source);

#ifdef __cplusplus
}
#endif

/**
 * @}
 */
 
/**
 * @}
 */

#endif /* UC_FAMILY == XMC1 */
 
#endif /* XMC1_SCU_H */
