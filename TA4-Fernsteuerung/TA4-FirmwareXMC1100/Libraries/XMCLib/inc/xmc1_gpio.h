/**
 * @file xmc1_gpio.h
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
 *     - Initial draft<br>
 *      
 * 2015-06-20:
 *     - Removed version macros and declaration of GetDriverVersion API
 *
 * @endcond
 *
 */

#ifndef XMC1_GPIO_H
#define XMC1_GPIO_H

/*******************************************************************************
 * HEADER FILES
 *******************************************************************************/

#include "xmc_common.h"

#if UC_FAMILY == XMC1

#include "xmc1_gpio_map.h"

/**
 * @addtogroup XMClib XMC Peripheral Library
 * @{
 */

/**
 * @addtogroup GPIO
 * @{
 */

/*******************************************************************************
 * MACROS
 *******************************************************************************/

#define XMC_GPIO_PORT0 ((XMC_GPIO_PORT_t *) PORT0_BASE)  /**<  Port0 module base address  */
#define XMC_GPIO_PORT1 ((XMC_GPIO_PORT_t *) PORT1_BASE)  /**<  Port1 module base address  */
#define XMC_GPIO_PORT2 ((XMC_GPIO_PORT_t *) PORT2_BASE)  /**<  Port2 module base address  */

#define XMC_GPIO_CHECK_PORT(port) ((port == XMC_GPIO_PORT0) || \
                                   (port == XMC_GPIO_PORT1) || \
                                   (port == XMC_GPIO_PORT2))

#define XMC_GPIO_CHECK_OUTPUT_PORT(port) XMC_GPIO_CHECK_PORT(port)
                                   
#define XMC_GPIO_CHECK_ANALOG_PORT(port) (port == XMC_GPIO_PORT2)

#define XMC_GPIO_CHECK_MODE(mode) ((mode == XMC_GPIO_MODE_INPUT_TRISTATE) ||\
                                   (mode == XMC_GPIO_MODE_INPUT_PULL_DOWN) ||\
                                   (mode == XMC_GPIO_MODE_INPUT_PULL_UP) ||\
                                   (mode == XMC_GPIO_MODE_INPUT_SAMPLING) ||\
                                   (mode == XMC_GPIO_MODE_INPUT_INVERTED_TRISTATE) ||\
                                   (mode == XMC_GPIO_MODE_INPUT_INVERTED_PULL_DOWN) ||\
                                   (mode == XMC_GPIO_MODE_INPUT_INVERTED_PULL_UP) ||\
                                   (mode == XMC_GPIO_MODE_INPUT_INVERTED_SAMPLING) ||\
                                   (mode == XMC_GPIO_MODE_OUTPUT_PUSH_PULL) ||\
                                   (mode == XMC_GPIO_MODE_OUTPUT_PUSH_PULL_ALT1) ||\
                                   (mode == XMC_GPIO_MODE_OUTPUT_PUSH_PULL_ALT2) ||\
                                   (mode == XMC_GPIO_MODE_OUTPUT_PUSH_PULL_ALT3) ||\
                                   (mode == XMC_GPIO_MODE_OUTPUT_PUSH_PULL_ALT4) ||\
                                   (mode == XMC_GPIO_MODE_OUTPUT_PUSH_PULL_ALT5) ||\
                                   (mode == XMC_GPIO_MODE_OUTPUT_PUSH_PULL_ALT6) ||\
                                   (mode == XMC_GPIO_MODE_OUTPUT_PUSH_PULL_ALT7) ||\
                                   (mode == XMC_GPIO_MODE_OUTPUT_OPEN_DRAIN) ||\
                                   (mode == XMC_GPIO_MODE_OUTPUT_OPEN_DRAIN_ALT1) ||\
                                   (mode == XMC_GPIO_MODE_OUTPUT_OPEN_DRAIN_ALT2) ||\
                                   (mode == XMC_GPIO_MODE_OUTPUT_OPEN_DRAIN_ALT3) ||\
                                   (mode == XMC_GPIO_MODE_OUTPUT_OPEN_DRAIN_ALT4) ||\
                                   (mode == XMC_GPIO_MODE_OUTPUT_OPEN_DRAIN_ALT5) ||\
                                   (mode == XMC_GPIO_MODE_OUTPUT_OPEN_DRAIN_ALT6) ||\
                                   (mode == XMC_GPIO_MODE_OUTPUT_OPEN_DRAIN_ALT7))
                                   
#define XMC_GPIO_CHECK_INPUT_HYSTERESIS(hysteresis) ((hysteresis == XMC_GPIO_INPUT_HYSTERESIS_STANDARD) || \
                                                     (hysteresis == XMC_GPIO_INPUT_HYSTERESIS_LARGE))

/*******************************************************************************
 * ENUMS
 *******************************************************************************/

/**
 * Configures input hysteresis mode of pin. Use type \a XMC_GPIO_INPUT_HYSTERESIS_t for this enum.
 * Selecting the appropriate pad hysteresis allows optimized pad oscillation behavior
 * for touch-sensing applications.
 */
typedef enum XMC_GPIO_INPUT_HYSTERESIS
{
  XMC_GPIO_INPUT_HYSTERESIS_STANDARD = 0x0U, /**< Standard hysteresis */
  XMC_GPIO_INPUT_HYSTERESIS_LARGE    = 0x4U  /**< Large hysteresis */
} XMC_GPIO_INPUT_HYSTERESIS_t;


/*******************************************************************************
 * DATA STRUCTURES
 *******************************************************************************/
/**
 *  Structure points  port hardware registers. Use type XMC_GPIO_PORT_t for this structure.
 */
typedef struct XMC_GPIO_PORT {
  __IO uint32_t  OUT;				/**< The port output register determines the value of a GPIO pin when it is
  	  	  	  	  	  	  	  	  	  	 selected by Pn_IOCRx as output */
  __O  uint32_t  OMR;				/**< The port output modification register contains control bits that make it
  	  	  	  	  	  	  	  	  	  	 possible to individually set, reset, or toggle the logic state of a single port
  	  	  	  	  	  	  	  	  	     line*/
  __I  uint32_t  RESERVED0[2];
  __IO uint32_t  IOCR[4];			/**< The port input/output control registers select the digital output and input
  	  	  	  	  	  	  	  	  	  	 driver functionality and characteristics of a GPIO port pin */
  __I  uint32_t  RESERVED1;
  __I  uint32_t  IN;				/**< The logic level of a GPIO pin can be read via the read-only port input register
   	   	   	   	   	   	   	   	   	   	 Pn_IN */
  __I  uint32_t  RESERVED2[6];
  __IO uint32_t  PHCR[2];			/**< Pad hysteresis control register */
  __I  uint32_t  RESERVED3[6];
  __IO uint32_t  PDISC;				/**< Pin Function Decision Control Register is to disable/enable the digital pad
  	  	  	  	  	  	  	  	  	  	 structure in shared analog and digital ports*/
  __I  uint32_t  RESERVED4[3];
  __IO uint32_t  PPS;				/**< Pin Power Save Register */
  __IO uint32_t  HWSEL;				/**< Pin Hardware Select Register */
} XMC_GPIO_PORT_t;

/**
 *  Structure initializes port pin. Use type XMC_GPIO_CONFIG_t for this structure.
 */
typedef struct XMC_GPIO_CONFIG
{
  XMC_GPIO_MODE_t mode;								/**< Defines the direction and characteristics of a pin */
  XMC_GPIO_INPUT_HYSTERESIS_t input_hysteresis;		/**< Defines input pad hysteresis of a pin */
  XMC_GPIO_OUTPUT_LEVEL_t output_level;				/**< Defines output level of a pin */
} XMC_GPIO_CONFIG_t;

/*******************************************************************************
 * API PROTOTYPES
 *******************************************************************************/


/**
 * @brief Sets pad hysteresis.
 * @param  port		  Constant pointer pointing to GPIO port, to access hardware register Pn_PHCR.
 * @param  pin		  Port pin number.
 * @param  hysteresis input hysteresis selection. Refer data structure @ref XMC_GPIO_INPUT_HYSTERESIS_t
 * 					  for details.
 *
 * @return None
 *
 * \par<b>Description:</b><br>
 * Sets port pin input hysteresis. It configures hardware registers Pn_PHCR.\a hysteresis is initially configured during
 * initialization in XMC_GPIO_Init(). Call this API to alter pad hysteresis as needed later in the program.
 *
 * \par<b>Related APIs:</b><BR>
 * None
 *
 * \par<b>Note:</b><br>
 * Prior to this api, user has to configure port pin to input mode using XMC_GPIO_SetMode().
 *
 */

void XMC_GPIO_SetInputHysteresis(XMC_GPIO_PORT_t *const port, 
                                 const uint8_t pin, 
                                 const XMC_GPIO_INPUT_HYSTERESIS_t hysteresis);

/**
 * @} (end addtogroup GPIO)
 */

/**
 * @} (end addtogroup XMClib)
 */

#endif /* UC_FAMILY == XMC1 */

#endif /* XMC1_GPIO_H */
 
