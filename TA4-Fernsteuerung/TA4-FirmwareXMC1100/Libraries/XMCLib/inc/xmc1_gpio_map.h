/**
 * @file xmc1_gpio_map.h
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
 *     - Updated copyright information
 *
 * @endcond
 *
 * @brief XMC pin mapping definitions
 */

#ifndef XMC1_GPIO_MAP_H
#define XMC1_GPIO_MAP_H

#if (UC_DEVICE == XMC1100) && (UC_PACKAGE == VQFN24)
#define P0_0	XMC_GPIO_PORT0, 0
#define P0_1	XMC_GPIO_PORT0, 1
#define P0_2	XMC_GPIO_PORT0, 2
#define P0_3	XMC_GPIO_PORT0, 3
#define P0_5	XMC_GPIO_PORT0, 5
#define P0_6	XMC_GPIO_PORT0, 6
#define P0_7	XMC_GPIO_PORT0, 7
#define P0_8	XMC_GPIO_PORT0, 8
#define P0_9	XMC_GPIO_PORT0, 9
#define P0_12	XMC_GPIO_PORT0, 12
#define P0_13	XMC_GPIO_PORT0, 13
#define P0_14	XMC_GPIO_PORT0, 14
#define P0_15	XMC_GPIO_PORT0, 15
#define P1_0	XMC_GPIO_PORT1, 0
#define P1_1	XMC_GPIO_PORT1, 1
#define P1_2	XMC_GPIO_PORT1, 2
#define P1_3	XMC_GPIO_PORT1, 3
#define P2_0	XMC_GPIO_PORT2, 0
#define P2_1	XMC_GPIO_PORT2, 1
#define P2_2	XMC_GPIO_PORT2, 2
#define P2_6	XMC_GPIO_PORT2, 6
#define P2_7	XMC_GPIO_PORT2, 7
#define P2_8	XMC_GPIO_PORT2, 8
#define P2_9	XMC_GPIO_PORT2, 9
#define P2_10	XMC_GPIO_PORT2, 10
#define P2_11	XMC_GPIO_PORT2, 11


/* Alternate Output Function */
#define P0_0_AF_ERU0_PDOUT0 	(0x8UL)
#define P0_0_AF_ERU0_GOUT0  	(0x18UL)
#define P0_0_AF_CCU40_OUT0  	(0x20UL)
#define P0_0_AF_U0C0_SELO0  	(0x30UL)
#define P0_0_AF_U0C1_SELO0  	(0x38UL)
#define P0_5_AF_CCU40_OUT0  	(0x20UL)
#define P0_5_AF_ACMP2_OUT   	(0x30UL)
#define P0_6_AF_CCU40_OUT0  	(0x20UL)
#define P0_6_AF_U0C1_MCLKOUT	(0x30UL)
#define P0_6_AF_U0C1_DOUT0  	(0x38UL)
#define P0_7_AF_CCU40_OUT1  	(0x20UL)
#define P0_7_AF_U0C0_SCLKOUT	(0x30UL)
#define P0_7_AF_U0C1_DOUT0  	(0x38UL)
#define P0_8_AF_CCU40_OUT2  	(0x20UL)
#define P0_8_AF_U0C0_SCLKOUT	(0x30UL)
#define P0_8_AF_U0C1_SCLKOUT	(0x38UL)
#define P0_9_AF_CCU40_OUT3  	(0x20UL)
#define P0_9_AF_U0C0_SELO0  	(0x30UL)
#define P0_9_AF_U0C1_SELO0  	(0x38UL)
#define P0_12_AF_U0C0_SELO3 	(0x30UL)
#define P0_13_AF_WDT_REQUEST	(0x8UL)
#define P0_13_AF_U0C0_SELO4 	(0x30UL)
#define P0_14_AF_U0C0_DOUT0 	(0x30UL)
#define P0_14_AF_U0C0_SCLKOUT	(0x38UL)
#define P0_15_AF_U0C0_DOUT0 	(0x30UL)
#define P0_15_AF_U0C1_MCLKOUT	(0x38UL)
#define P1_0_AF_CCU40_OUT0  	(0x10UL)
#define P1_0_AF_ACMP1_OUT   	(0x30UL)
#define P1_0_AF_U0C0_DOUT0  	(0x38UL)
#define P1_1_AF_CCU40_OUT1  	(0x10UL)
#define P1_1_AF_U0C0_DOUT0  	(0x30UL)
#define P1_1_AF_U0C1_SELO0  	(0x38UL)
#define P1_2_AF_CCU40_OUT2  	(0x10UL)
#define P1_2_AF_ACMP2_OUT   	(0x30UL)
#define P1_2_AF_U0C1_DOUT0  	(0x38UL)
#define P1_3_AF_CCU40_OUT3  	(0x10UL)
#define P1_3_AF_U0C1_SCLKOUT	(0x30UL)
#define P1_3_AF_U0C1_DOUT0  	(0x38UL)
#define P2_0_AF_ERU0_PDOUT3 	(0x8UL)
#define P2_0_AF_CCU40_OUT0  	(0x10UL)
#define P2_0_AF_ERU0_GOUT3  	(0x18UL)
#define P2_0_AF_U0C0_DOUT0  	(0x30UL)
#define P2_0_AF_U0C0_SCLKOUT	(0x38UL)
#define P2_1_AF_ERU0_PDOUT2 	(0x8UL)
#define P2_1_AF_CCU40_OUT1  	(0x10UL)
#define P2_1_AF_ERU0_GOUT2  	(0x18UL)
#define P2_1_AF_U0C0_DOUT0  	(0x30UL)
#define P2_1_AF_U0C1_SCLKOUT	(0x38UL)
#define P2_10_AF_ERU0_PDOUT1	(0x8UL)
#define P2_10_AF_CCU40_OUT2 	(0x10UL)
#define P2_10_AF_ERU0_GOUT1 	(0x18UL)
#define P2_10_AF_ACMP0_OUT  	(0x30UL)
#define P2_10_AF_U0C1_DOUT0 	(0x38UL)
#define P2_11_AF_ERU0_PDOUT0	(0x8UL)
#define P2_11_AF_CCU40_OUT3 	(0x10UL)
#define P2_11_AF_ERU0_GOUT0 	(0x18UL)
#define P2_11_AF_U0C1_SCLKOUT	(0x30UL)
#define P2_11_AF_U0C1_DOUT0 	(0x38UL)
#endif


#if (UC_DEVICE == XMC1100) && (UC_PACKAGE == VQFN40)
#define P0_0	XMC_GPIO_PORT0, 0
#define P0_1	XMC_GPIO_PORT0, 1
#define P0_2	XMC_GPIO_PORT0, 2
#define P0_3	XMC_GPIO_PORT0, 3
#define P0_4	XMC_GPIO_PORT0, 4
#define P0_5	XMC_GPIO_PORT0, 5
#define P0_6	XMC_GPIO_PORT0, 6
#define P0_7	XMC_GPIO_PORT0, 7
#define P0_8	XMC_GPIO_PORT0, 8
#define P0_9	XMC_GPIO_PORT0, 9
#define P0_10	XMC_GPIO_PORT0, 10
#define P0_11	XMC_GPIO_PORT0, 11
#define P0_12	XMC_GPIO_PORT0, 12
#define P0_13	XMC_GPIO_PORT0, 13
#define P0_14	XMC_GPIO_PORT0, 14
#define P0_15	XMC_GPIO_PORT0, 15
#define P1_0	XMC_GPIO_PORT1, 0
#define P1_1	XMC_GPIO_PORT1, 1
#define P1_2	XMC_GPIO_PORT1, 2
#define P1_3	XMC_GPIO_PORT1, 3
#define P1_4	XMC_GPIO_PORT1, 4
#define P1_5	XMC_GPIO_PORT1, 5
#define P1_6	XMC_GPIO_PORT1, 6
#define P2_0	XMC_GPIO_PORT2, 0
#define P2_1	XMC_GPIO_PORT2, 1
#define P2_2	XMC_GPIO_PORT2, 2
#define P2_3	XMC_GPIO_PORT2, 3
#define P2_4	XMC_GPIO_PORT2, 4
#define P2_5	XMC_GPIO_PORT2, 5
#define P2_6	XMC_GPIO_PORT2, 6
#define P2_7	XMC_GPIO_PORT2, 7
#define P2_8	XMC_GPIO_PORT2, 8
#define P2_9	XMC_GPIO_PORT2, 9
#define P2_10	XMC_GPIO_PORT2, 10
#define P2_11	XMC_GPIO_PORT2, 11


/* Alternate Output Function */
#define P0_0_AF_ERU0_PDOUT0 	(0x8UL)
#define P0_0_AF_ERU0_GOUT0  	(0x18UL)
#define P0_0_AF_CCU40_OUT0  	(0x20UL)
#define P0_0_AF_U0C0_SELO0  	(0x30UL)
#define P0_0_AF_U0C1_SELO0  	(0x38UL)
#define P0_1_AF_ERU0_PDOUT1 	(0x8UL)
#define P0_1_AF_ERU0_GOUT1  	(0x18UL)
#define P0_1_AF_CCU40_OUT1  	(0x20UL)
#define P0_1_AF_SCU_VDROP   	(0x38UL)
#define P0_2_AF_ERU0_PDOUT2 	(0x8UL)
#define P0_2_AF_ERU0_GOUT2  	(0x18UL)
#define P0_2_AF_CCU40_OUT2  	(0x20UL)
#define P0_3_AF_ERU0_PDOUT3 	(0x8UL)
#define P0_3_AF_ERU0_GOUT3  	(0x18UL)
#define P0_3_AF_CCU40_OUT3  	(0x20UL)
#define P0_4_AF_CCU40_OUT1  	(0x20UL)
#define P0_4_AF_WDT_REQUEST 	(0x38UL)
#define P0_5_AF_CCU40_OUT0  	(0x20UL)
#define P0_5_AF_ACMP2_OUT   	(0x30UL)
#define P0_6_AF_CCU40_OUT0  	(0x20UL)
#define P0_6_AF_U0C1_MCLKOUT	(0x30UL)
#define P0_6_AF_U0C1_DOUT0  	(0x38UL)
#define P0_7_AF_CCU40_OUT1  	(0x20UL)
#define P0_7_AF_U0C0_SCLKOUT	(0x30UL)
#define P0_7_AF_U0C1_DOUT0  	(0x38UL)
#define P0_8_AF_CCU40_OUT2  	(0x20UL)
#define P0_8_AF_U0C0_SCLKOUT	(0x30UL)
#define P0_8_AF_U0C1_SCLKOUT	(0x38UL)
#define P0_9_AF_CCU40_OUT3  	(0x20UL)
#define P0_9_AF_U0C0_SELO0  	(0x30UL)
#define P0_9_AF_U0C1_SELO0  	(0x38UL)
#define P0_10_AF_ACMP0_OUT  	(0x20UL)
#define P0_10_AF_U0C0_SELO1 	(0x30UL)
#define P0_10_AF_U0C1_SELO1 	(0x38UL)
#define P0_11_AF_U0C0_MCLKOUT	(0x20UL)
#define P0_11_AF_U0C0_SELO2 	(0x30UL)
#define P0_11_AF_U0C1_SELO2 	(0x38UL)
#define P0_12_AF_U0C0_SELO3 	(0x30UL)
#define P0_13_AF_WDT_REQUEST	(0x8UL)
#define P0_13_AF_U0C0_SELO4 	(0x30UL)
#define P0_14_AF_U0C0_DOUT0 	(0x30UL)
#define P0_14_AF_U0C0_SCLKOUT	(0x38UL)
#define P0_15_AF_U0C0_DOUT0 	(0x30UL)
#define P0_15_AF_U0C1_MCLKOUT	(0x38UL)
#define P1_0_AF_CCU40_OUT0  	(0x10UL)
#define P1_0_AF_ACMP1_OUT   	(0x30UL)
#define P1_0_AF_U0C0_DOUT0  	(0x38UL)
#define P1_1_AF_CCU40_OUT1  	(0x10UL)
#define P1_1_AF_U0C0_DOUT0  	(0x30UL)
#define P1_1_AF_U0C1_SELO0  	(0x38UL)
#define P1_2_AF_CCU40_OUT2  	(0x10UL)
#define P1_2_AF_ACMP2_OUT   	(0x30UL)
#define P1_2_AF_U0C1_DOUT0  	(0x38UL)
#define P1_3_AF_CCU40_OUT3  	(0x10UL)
#define P1_3_AF_U0C1_SCLKOUT	(0x30UL)
#define P1_3_AF_U0C1_DOUT0  	(0x38UL)
#define P1_4_AF_U0C1_SCLKOUT	(0x10UL)
#define P1_4_AF_U0C0_SELO0  	(0x30UL)
#define P1_4_AF_U0C1_SELO1  	(0x38UL)
#define P1_5_AF_U0C0_DOUT0  	(0x10UL)
#define P1_5_AF_U0C0_SELO1  	(0x30UL)
#define P1_5_AF_U0C1_SELO2  	(0x38UL)
#define P1_6_AF_U0C1_DOUT0  	(0x10UL)
#define P1_6_AF_U0C0_SCLKOUT	(0x20UL)
#define P1_6_AF_U0C0_SELO2  	(0x30UL)
#define P1_6_AF_U0C1_SELO3  	(0x38UL)
#define P2_0_AF_ERU0_PDOUT3 	(0x8UL)
#define P2_0_AF_CCU40_OUT0  	(0x10UL)
#define P2_0_AF_ERU0_GOUT3  	(0x18UL)
#define P2_0_AF_U0C0_DOUT0  	(0x30UL)
#define P2_0_AF_U0C0_SCLKOUT	(0x38UL)
#define P2_1_AF_ERU0_PDOUT2 	(0x8UL)
#define P2_1_AF_CCU40_OUT1  	(0x10UL)
#define P2_1_AF_ERU0_GOUT2  	(0x18UL)
#define P2_1_AF_U0C0_DOUT0  	(0x30UL)
#define P2_1_AF_U0C1_SCLKOUT	(0x38UL)
#define P2_10_AF_ERU0_PDOUT1	(0x8UL)
#define P2_10_AF_CCU40_OUT2 	(0x10UL)
#define P2_10_AF_ERU0_GOUT1 	(0x18UL)
#define P2_10_AF_ACMP0_OUT  	(0x30UL)
#define P2_10_AF_U0C1_DOUT0 	(0x38UL)
#define P2_11_AF_ERU0_PDOUT0	(0x8UL)
#define P2_11_AF_CCU40_OUT3 	(0x10UL)
#define P2_11_AF_ERU0_GOUT0 	(0x18UL)
#define P2_11_AF_U0C1_SCLKOUT	(0x30UL)
#define P2_11_AF_U0C1_DOUT0 	(0x38UL)
#endif


#if (UC_DEVICE == XMC1100) && (UC_PACKAGE == TSSOP16)
#define P0_0	XMC_GPIO_PORT0, 0
#define P0_1	XMC_GPIO_PORT0, 1
#define P0_2	XMC_GPIO_PORT0, 2
#define P0_3	XMC_GPIO_PORT0, 3
#define P0_5	XMC_GPIO_PORT0, 5
#define P0_6	XMC_GPIO_PORT0, 6
#define P0_7	XMC_GPIO_PORT0, 7
#define P0_8	XMC_GPIO_PORT0, 8
#define P0_9	XMC_GPIO_PORT0, 9
#define P0_14	XMC_GPIO_PORT0, 14
#define P0_15	XMC_GPIO_PORT0, 15
#define P2_0	XMC_GPIO_PORT2, 0
#define P2_6	XMC_GPIO_PORT2, 6
#define P2_7	XMC_GPIO_PORT2, 7
#define P2_8	XMC_GPIO_PORT2, 8
#define P2_9	XMC_GPIO_PORT2, 9
#define P2_10	XMC_GPIO_PORT2, 10
#define P2_11	XMC_GPIO_PORT2, 11


/* Alternate Output Function */
#define P0_0_AF_ERU0_PDOUT0 	(0x8UL)
#define P0_0_AF_ERU0_GOUT0  	(0x18UL)
#define P0_0_AF_CCU40_OUT0  	(0x20UL)
#define P0_0_AF_U0C0_SELO0  	(0x30UL)
#define P0_0_AF_U0C1_SELO0  	(0x38UL)
#define P0_5_AF_CCU40_OUT0  	(0x20UL)
#define P0_5_AF_ACMP2_OUT   	(0x30UL)
#define P0_6_AF_CCU40_OUT0  	(0x20UL)
#define P0_6_AF_U0C1_MCLKOUT	(0x30UL)
#define P0_6_AF_U0C1_DOUT0  	(0x38UL)
#define P0_7_AF_CCU40_OUT1  	(0x20UL)
#define P0_7_AF_U0C0_SCLKOUT	(0x30UL)
#define P0_7_AF_U0C1_DOUT0  	(0x38UL)
#define P0_8_AF_CCU40_OUT2  	(0x20UL)
#define P0_8_AF_U0C0_SCLKOUT	(0x30UL)
#define P0_8_AF_U0C1_SCLKOUT	(0x38UL)
#define P0_9_AF_CCU40_OUT3  	(0x20UL)
#define P0_9_AF_U0C0_SELO0  	(0x30UL)
#define P0_9_AF_U0C1_SELO0  	(0x38UL)
#define P0_14_AF_U0C0_DOUT0 	(0x30UL)
#define P0_14_AF_U0C0_SCLKOUT	(0x38UL)
#define P0_15_AF_U0C0_DOUT0 	(0x30UL)
#define P0_15_AF_U0C1_MCLKOUT	(0x38UL)
#define P2_0_AF_ERU0_PDOUT3 	(0x8UL)
#define P2_0_AF_CCU40_OUT0  	(0x10UL)
#define P2_0_AF_ERU0_GOUT3  	(0x18UL)
#define P2_0_AF_U0C0_DOUT0  	(0x30UL)
#define P2_0_AF_U0C0_SCLKOUT	(0x38UL)
#define P2_10_AF_ERU0_PDOUT1	(0x8UL)
#define P2_10_AF_CCU40_OUT2 	(0x10UL)
#define P2_10_AF_ERU0_GOUT1 	(0x18UL)
#define P2_10_AF_ACMP0_OUT  	(0x30UL)
#define P2_10_AF_U0C1_DOUT0 	(0x38UL)
#define P2_11_AF_ERU0_PDOUT0	(0x8UL)
#define P2_11_AF_CCU40_OUT3 	(0x10UL)
#define P2_11_AF_ERU0_GOUT0 	(0x18UL)
#define P2_11_AF_U0C1_SCLKOUT	(0x30UL)
#define P2_11_AF_U0C1_DOUT0 	(0x38UL)
#endif


#if (UC_DEVICE == XMC1100) && (UC_PACKAGE == TSSOP38)
#define P0_0	XMC_GPIO_PORT0, 0
#define P0_1	XMC_GPIO_PORT0, 1
#define P0_2	XMC_GPIO_PORT0, 2
#define P0_3	XMC_GPIO_PORT0, 3
#define P0_4	XMC_GPIO_PORT0, 4
#define P0_5	XMC_GPIO_PORT0, 5
#define P0_6	XMC_GPIO_PORT0, 6
#define P0_7	XMC_GPIO_PORT0, 7
#define P0_8	XMC_GPIO_PORT0, 8
#define P0_9	XMC_GPIO_PORT0, 9
#define P0_10	XMC_GPIO_PORT0, 10
#define P0_11	XMC_GPIO_PORT0, 11
#define P0_12	XMC_GPIO_PORT0, 12
#define P0_13	XMC_GPIO_PORT0, 13
#define P0_14	XMC_GPIO_PORT0, 14
#define P0_15	XMC_GPIO_PORT0, 15
#define P1_0	XMC_GPIO_PORT1, 0
#define P1_1	XMC_GPIO_PORT1, 1
#define P1_2	XMC_GPIO_PORT1, 2
#define P1_3	XMC_GPIO_PORT1, 3
#define P1_4	XMC_GPIO_PORT1, 4
#define P1_5	XMC_GPIO_PORT1, 5
#define P2_0	XMC_GPIO_PORT2, 0
#define P2_1	XMC_GPIO_PORT2, 1
#define P2_2	XMC_GPIO_PORT2, 2
#define P2_3	XMC_GPIO_PORT2, 3
#define P2_4	XMC_GPIO_PORT2, 4
#define P2_5	XMC_GPIO_PORT2, 5
#define P2_6	XMC_GPIO_PORT2, 6
#define P2_7	XMC_GPIO_PORT2, 7
#define P2_8	XMC_GPIO_PORT2, 8
#define P2_9	XMC_GPIO_PORT2, 9
#define P2_10	XMC_GPIO_PORT2, 10
#define P2_11	XMC_GPIO_PORT2, 11


/* Alternate Output Function */
#define P0_0_AF_ERU0_PDOUT0 	(0x8UL)
#define P0_0_AF_ERU0_GOUT0  	(0x18UL)
#define P0_0_AF_CCU40_OUT0  	(0x20UL)
#define P0_0_AF_U0C0_SELO0  	(0x30UL)
#define P0_0_AF_U0C1_SELO0  	(0x38UL)
#define P0_1_AF_ERU0_PDOUT1 	(0x8UL)
#define P0_1_AF_ERU0_GOUT1  	(0x18UL)
#define P0_1_AF_CCU40_OUT1  	(0x20UL)
#define P0_1_AF_SCU_VDROP   	(0x38UL)
#define P0_2_AF_ERU0_PDOUT2 	(0x8UL)
#define P0_2_AF_ERU0_GOUT2  	(0x18UL)
#define P0_2_AF_CCU40_OUT2  	(0x20UL)
#define P0_3_AF_ERU0_PDOUT3 	(0x8UL)
#define P0_3_AF_ERU0_GOUT3  	(0x18UL)
#define P0_3_AF_CCU40_OUT3  	(0x20UL)
#define P0_4_AF_CCU40_OUT1  	(0x20UL)
#define P0_4_AF_WDT_REQUEST 	(0x38UL)
#define P0_5_AF_CCU40_OUT0  	(0x20UL)
#define P0_5_AF_ACMP2_OUT   	(0x30UL)
#define P0_6_AF_CCU40_OUT0  	(0x20UL)
#define P0_6_AF_U0C1_MCLKOUT	(0x30UL)
#define P0_6_AF_U0C1_DOUT0  	(0x38UL)
#define P0_7_AF_CCU40_OUT1  	(0x20UL)
#define P0_7_AF_U0C0_SCLKOUT	(0x30UL)
#define P0_7_AF_U0C1_DOUT0  	(0x38UL)
#define P0_8_AF_CCU40_OUT2  	(0x20UL)
#define P0_8_AF_U0C0_SCLKOUT	(0x30UL)
#define P0_8_AF_U0C1_SCLKOUT	(0x38UL)
#define P0_9_AF_CCU40_OUT3  	(0x20UL)
#define P0_9_AF_U0C0_SELO0  	(0x30UL)
#define P0_9_AF_U0C1_SELO0  	(0x38UL)
#define P0_10_AF_ACMP0_OUT  	(0x20UL)
#define P0_10_AF_U0C0_SELO1 	(0x30UL)
#define P0_10_AF_U0C1_SELO1 	(0x38UL)
#define P0_11_AF_U0C0_MCLKOUT	(0x20UL)
#define P0_11_AF_U0C0_SELO2 	(0x30UL)
#define P0_11_AF_U0C1_SELO2 	(0x38UL)
#define P0_12_AF_U0C0_SELO3 	(0x30UL)
#define P0_13_AF_WDT_REQUEST	(0x8UL)
#define P0_13_AF_U0C0_SELO4 	(0x30UL)
#define P0_14_AF_U0C0_DOUT0 	(0x30UL)
#define P0_14_AF_U0C0_SCLKOUT	(0x38UL)
#define P0_15_AF_U0C0_DOUT0 	(0x30UL)
#define P0_15_AF_U0C1_MCLKOUT	(0x38UL)
#define P1_0_AF_CCU40_OUT0  	(0x10UL)
#define P1_0_AF_ACMP1_OUT   	(0x30UL)
#define P1_0_AF_U0C0_DOUT0  	(0x38UL)
#define P1_1_AF_CCU40_OUT1  	(0x10UL)
#define P1_1_AF_U0C0_DOUT0  	(0x30UL)
#define P1_1_AF_U0C1_SELO0  	(0x38UL)
#define P1_2_AF_CCU40_OUT2  	(0x10UL)
#define P1_2_AF_ACMP2_OUT   	(0x30UL)
#define P1_2_AF_U0C1_DOUT0  	(0x38UL)
#define P1_3_AF_CCU40_OUT3  	(0x10UL)
#define P1_3_AF_U0C1_SCLKOUT	(0x30UL)
#define P1_3_AF_U0C1_DOUT0  	(0x38UL)
#define P1_4_AF_U0C1_SCLKOUT	(0x10UL)
#define P1_4_AF_U0C0_SELO0  	(0x30UL)
#define P1_4_AF_U0C1_SELO1  	(0x38UL)
#define P1_5_AF_U0C0_DOUT0  	(0x10UL)
#define P1_5_AF_U0C0_SELO1  	(0x30UL)
#define P1_5_AF_U0C1_SELO2  	(0x38UL)
#define P2_0_AF_ERU0_PDOUT3 	(0x8UL)
#define P2_0_AF_CCU40_OUT0  	(0x10UL)
#define P2_0_AF_ERU0_GOUT3  	(0x18UL)
#define P2_0_AF_U0C0_DOUT0  	(0x30UL)
#define P2_0_AF_U0C0_SCLKOUT	(0x38UL)
#define P2_1_AF_ERU0_PDOUT2 	(0x8UL)
#define P2_1_AF_CCU40_OUT1  	(0x10UL)
#define P2_1_AF_ERU0_GOUT2  	(0x18UL)
#define P2_1_AF_U0C0_DOUT0  	(0x30UL)
#define P2_1_AF_U0C1_SCLKOUT	(0x38UL)
#define P2_10_AF_ERU0_PDOUT1	(0x8UL)
#define P2_10_AF_CCU40_OUT2 	(0x10UL)
#define P2_10_AF_ERU0_GOUT1 	(0x18UL)
#define P2_10_AF_ACMP0_OUT  	(0x30UL)
#define P2_10_AF_U0C1_DOUT0 	(0x38UL)
#define P2_11_AF_ERU0_PDOUT0	(0x8UL)
#define P2_11_AF_CCU40_OUT3 	(0x10UL)
#define P2_11_AF_ERU0_GOUT0 	(0x18UL)
#define P2_11_AF_U0C1_SCLKOUT	(0x30UL)
#define P2_11_AF_U0C1_DOUT0 	(0x38UL)
#endif


#if (UC_DEVICE == XMC1200) && (UC_PACKAGE == TSSOP38)
#define P0_0	XMC_GPIO_PORT0, 0
#define P0_1	XMC_GPIO_PORT0, 1
#define P0_2	XMC_GPIO_PORT0, 2
#define P0_3	XMC_GPIO_PORT0, 3
#define P0_4	XMC_GPIO_PORT0, 4
#define P0_5	XMC_GPIO_PORT0, 5
#define P0_6	XMC_GPIO_PORT0, 6
#define P0_7	XMC_GPIO_PORT0, 7
#define P0_8	XMC_GPIO_PORT0, 8
#define P0_9	XMC_GPIO_PORT0, 9
#define P0_10	XMC_GPIO_PORT0, 10
#define P0_11	XMC_GPIO_PORT0, 11
#define P0_12	XMC_GPIO_PORT0, 12
#define P0_13	XMC_GPIO_PORT0, 13
#define P0_14	XMC_GPIO_PORT0, 14
#define P0_15	XMC_GPIO_PORT0, 15
#define P1_0	XMC_GPIO_PORT1, 0
#define P1_1	XMC_GPIO_PORT1, 1
#define P1_2	XMC_GPIO_PORT1, 2
#define P1_3	XMC_GPIO_PORT1, 3
#define P1_4	XMC_GPIO_PORT1, 4
#define P1_5	XMC_GPIO_PORT1, 5
#define P2_0	XMC_GPIO_PORT2, 0
#define P2_1	XMC_GPIO_PORT2, 1
#define P2_2	XMC_GPIO_PORT2, 2
#define P2_3	XMC_GPIO_PORT2, 3
#define P2_4	XMC_GPIO_PORT2, 4
#define P2_5	XMC_GPIO_PORT2, 5
#define P2_6	XMC_GPIO_PORT2, 6
#define P2_7	XMC_GPIO_PORT2, 7
#define P2_8	XMC_GPIO_PORT2, 8
#define P2_9	XMC_GPIO_PORT2, 9
#define P2_10	XMC_GPIO_PORT2, 10
#define P2_11	XMC_GPIO_PORT2, 11


/* Alternate Output Function */
#define P0_0_AF_ERU0_PDOUT0 	(0x8UL)
#define P0_0_AF_LEDTS0_LINE7	(0x10UL)
#define P0_0_AF_ERU0_GOUT0  	(0x18UL)
#define P0_0_AF_CCU40_OUT0  	(0x20UL)
#define P0_0_AF_U0C0_SELO0  	(0x30UL)
#define P0_0_AF_U0C1_SELO0  	(0x38UL)
#define P0_1_AF_ERU0_PDOUT1 	(0x8UL)
#define P0_1_AF_LEDTS0_LINE6	(0x10UL)
#define P0_1_AF_ERU0_GOUT1  	(0x18UL)
#define P0_1_AF_CCU40_OUT1  	(0x20UL)
#define P0_1_AF_BCCU0_OUT8  	(0x30UL)
#define P0_1_AF_SCU_VDROP   	(0x38UL)
#define P0_2_AF_ERU0_PDOUT2 	(0x8UL)
#define P0_2_AF_LEDTS0_LINE5	(0x10UL)
#define P0_2_AF_ERU0_GOUT2  	(0x18UL)
#define P0_2_AF_CCU40_OUT2  	(0x20UL)
#define P0_2_AF_VADC_EMUX2_IN	(0x30UL)
#define P0_3_AF_ERU0_PDOUT3 	(0x8UL)
#define P0_3_AF_LEDTS0_LINE4	(0x10UL)
#define P0_3_AF_ERU0_GOUT3  	(0x18UL)
#define P0_3_AF_CCU40_OUT3  	(0x20UL)
#define P0_3_AF_VADC_EMUX1_IN	(0x30UL)
#define P0_4_AF_BCCU0_OUT0  	(0x8UL)
#define P0_4_AF_LEDTS0_LINE3	(0x10UL)
#define P0_4_AF_LEDTS0_COL3 	(0x18UL)
#define P0_4_AF_CCU40_OUT1  	(0x20UL)
#define P0_4_AF_VADC_EMUX0_IN	(0x30UL)
#define P0_4_AF_WDT_REQUEST 	(0x38UL)
#define P0_5_AF_BCCU0_OUT1  	(0x8UL)
#define P0_5_AF_LEDTS0_LINE2	(0x10UL)
#define P0_5_AF_LEDTS0_COL2 	(0x18UL)
#define P0_5_AF_CCU40_OUT0  	(0x20UL)
#define P0_5_AF_ACMP2_OUT   	(0x30UL)
#define P0_6_AF_BCCU0_OUT2  	(0x8UL)
#define P0_6_AF_LEDTS0_LINE1	(0x10UL)
#define P0_6_AF_LEDTS0_COL1 	(0x18UL)
#define P0_6_AF_CCU40_OUT0  	(0x20UL)
#define P0_6_AF_U0C1_MCLKOUT	(0x30UL)
#define P0_6_AF_U0C1_DOUT0  	(0x38UL)
#define P0_7_AF_BCCU0_OUT3  	(0x8UL)
#define P0_7_AF_LEDTS0_LINE0	(0x10UL)
#define P0_7_AF_LEDTS0_COL0 	(0x18UL)
#define P0_7_AF_CCU40_OUT1  	(0x20UL)
#define P0_7_AF_U0C0_SCLKOUT	(0x30UL)
#define P0_7_AF_U0C1_DOUT0  	(0x38UL)
#define P0_8_AF_BCCU0_OUT4  	(0x8UL)
#define P0_8_AF_LEDTS1_LINE0	(0x10UL)
#define P0_8_AF_LEDTS0_COLA 	(0x18UL)
#define P0_8_AF_CCU40_OUT2  	(0x20UL)
#define P0_8_AF_U0C0_SCLKOUT	(0x30UL)
#define P0_8_AF_U0C1_SCLKOUT	(0x38UL)
#define P0_9_AF_BCCU0_OUT5  	(0x8UL)
#define P0_9_AF_LEDTS1_LINE1	(0x10UL)
#define P0_9_AF_LEDTS0_COL6 	(0x18UL)
#define P0_9_AF_CCU40_OUT3  	(0x20UL)
#define P0_9_AF_U0C0_SELO0  	(0x30UL)
#define P0_9_AF_U0C1_SELO0  	(0x38UL)
#define P0_10_AF_BCCU0_OUT6 	(0x8UL)
#define P0_10_AF_LEDTS1_LINE2	(0x10UL)
#define P0_10_AF_LEDTS0_COL5	(0x18UL)
#define P0_10_AF_ACMP0_OUT  	(0x20UL)
#define P0_10_AF_U0C0_SELO1 	(0x30UL)
#define P0_10_AF_U0C1_SELO1 	(0x38UL)
#define P0_11_AF_BCCU0_OUT7 	(0x8UL)
#define P0_11_AF_LEDTS1_LINE3	(0x10UL)
#define P0_11_AF_LEDTS0_COL4	(0x18UL)
#define P0_11_AF_U0C0_MCLKOUT	(0x20UL)
#define P0_11_AF_U0C0_SELO2 	(0x30UL)
#define P0_11_AF_U0C1_SELO2 	(0x38UL)
#define P0_12_AF_BCCU0_OUT6 	(0x8UL)
#define P0_12_AF_LEDTS1_LINE4	(0x10UL)
#define P0_12_AF_LEDTS0_COL3	(0x18UL)
#define P0_12_AF_LEDTS1_COL3	(0x20UL)
#define P0_12_AF_U0C0_SELO3 	(0x30UL)
#define P0_13_AF_WDT_REQUEST	(0x8UL)
#define P0_13_AF_LEDTS1_LINE5	(0x10UL)
#define P0_13_AF_LEDTS0_COL2	(0x18UL)
#define P0_13_AF_LEDTS1_COL2	(0x20UL)
#define P0_13_AF_U0C0_SELO4 	(0x30UL)
#define P0_14_AF_BCCU0_OUT7 	(0x8UL)
#define P0_14_AF_LEDTS1_LINE6	(0x10UL)
#define P0_14_AF_LEDTS0_COL1	(0x18UL)
#define P0_14_AF_LEDTS1_COL1	(0x20UL)
#define P0_14_AF_U0C0_DOUT0 	(0x30UL)
#define P0_14_AF_U0C0_SCLKOUT	(0x38UL)
#define P0_15_AF_BCCU0_OUT8 	(0x8UL)
#define P0_15_AF_LEDTS1_LINE7	(0x10UL)
#define P0_15_AF_LEDTS0_COL0	(0x18UL)
#define P0_15_AF_LEDTS1_COL0	(0x20UL)
#define P0_15_AF_U0C0_DOUT0 	(0x30UL)
#define P0_15_AF_U0C1_MCLKOUT	(0x38UL)
#define P1_0_AF_BCCU0_OUT0  	(0x8UL)
#define P1_0_AF_CCU40_OUT0  	(0x10UL)
#define P1_0_AF_LEDTS0_COL0 	(0x18UL)
#define P1_0_AF_LEDTS1_COLA 	(0x20UL)
#define P1_0_AF_ACMP1_OUT   	(0x30UL)
#define P1_0_AF_U0C0_DOUT0  	(0x38UL)
#define P1_1_AF_VADC_EMUX0_IN	(0x8UL)
#define P1_1_AF_CCU40_OUT1  	(0x10UL)
#define P1_1_AF_LEDTS0_COL1 	(0x18UL)
#define P1_1_AF_LEDTS1_COL0 	(0x20UL)
#define P1_1_AF_U0C0_DOUT0  	(0x30UL)
#define P1_1_AF_U0C1_SELO0  	(0x38UL)
#define P1_2_AF_VADC_EMUX1_IN	(0x8UL)
#define P1_2_AF_CCU40_OUT2  	(0x10UL)
#define P1_2_AF_LEDTS0_COL2 	(0x18UL)
#define P1_2_AF_LEDTS1_COL1 	(0x20UL)
#define P1_2_AF_ACMP2_OUT   	(0x30UL)
#define P1_2_AF_U0C1_DOUT0  	(0x38UL)
#define P1_3_AF_VADC_EMUX2_IN	(0x8UL)
#define P1_3_AF_CCU40_OUT3  	(0x10UL)
#define P1_3_AF_LEDTS0_COL3 	(0x18UL)
#define P1_3_AF_LEDTS1_COL2 	(0x20UL)
#define P1_3_AF_U0C1_SCLKOUT	(0x30UL)
#define P1_3_AF_U0C1_DOUT0  	(0x38UL)
#define P1_4_AF_VADC_EMUX0_IN	(0x8UL)
#define P1_4_AF_U0C1_SCLKOUT	(0x10UL)
#define P1_4_AF_LEDTS0_COL4 	(0x18UL)
#define P1_4_AF_LEDTS1_COL3 	(0x20UL)
#define P1_4_AF_U0C0_SELO0  	(0x30UL)
#define P1_4_AF_U0C1_SELO1  	(0x38UL)
#define P1_5_AF_VADC_EMUX1_IN	(0x8UL)
#define P1_5_AF_U0C0_DOUT0  	(0x10UL)
#define P1_5_AF_LEDTS0_COLA 	(0x18UL)
#define P1_5_AF_BCCU0_OUT1  	(0x20UL)
#define P1_5_AF_U0C0_SELO1  	(0x30UL)
#define P1_5_AF_U0C1_SELO2  	(0x38UL)
#define P2_0_AF_ERU0_PDOUT3 	(0x8UL)
#define P2_0_AF_CCU40_OUT0  	(0x10UL)
#define P2_0_AF_ERU0_GOUT3  	(0x18UL)
#define P2_0_AF_LEDTS1_COL5 	(0x20UL)
#define P2_0_AF_U0C0_DOUT0  	(0x30UL)
#define P2_0_AF_U0C0_SCLKOUT	(0x38UL)
#define P2_1_AF_ERU0_PDOUT2 	(0x8UL)
#define P2_1_AF_CCU40_OUT1  	(0x10UL)
#define P2_1_AF_ERU0_GOUT2  	(0x18UL)
#define P2_1_AF_LEDTS1_COL6 	(0x20UL)
#define P2_1_AF_U0C0_DOUT0  	(0x30UL)
#define P2_1_AF_U0C1_SCLKOUT	(0x38UL)
#define P2_10_AF_ERU0_PDOUT1	(0x8UL)
#define P2_10_AF_CCU40_OUT2 	(0x10UL)
#define P2_10_AF_ERU0_GOUT1 	(0x18UL)
#define P2_10_AF_LEDTS1_COL4	(0x20UL)
#define P2_10_AF_ACMP0_OUT  	(0x30UL)
#define P2_10_AF_U0C1_DOUT0 	(0x38UL)
#define P2_11_AF_ERU0_PDOUT0	(0x8UL)
#define P2_11_AF_CCU40_OUT3 	(0x10UL)
#define P2_11_AF_ERU0_GOUT0 	(0x18UL)
#define P2_11_AF_LEDTS1_COL3	(0x20UL)
#define P2_11_AF_U0C1_SCLKOUT	(0x30UL)
#define P2_11_AF_U0C1_DOUT0 	(0x38UL)
#endif


#if (UC_DEVICE == XMC1201) && (UC_PACKAGE == VQFN40)
#define P0_0	XMC_GPIO_PORT0, 0
#define P0_1	XMC_GPIO_PORT0, 1
#define P0_2	XMC_GPIO_PORT0, 2
#define P0_3	XMC_GPIO_PORT0, 3
#define P0_4	XMC_GPIO_PORT0, 4
#define P0_5	XMC_GPIO_PORT0, 5
#define P0_6	XMC_GPIO_PORT0, 6
#define P0_7	XMC_GPIO_PORT0, 7
#define P0_8	XMC_GPIO_PORT0, 8
#define P0_9	XMC_GPIO_PORT0, 9
#define P0_10	XMC_GPIO_PORT0, 10
#define P0_11	XMC_GPIO_PORT0, 11
#define P0_12	XMC_GPIO_PORT0, 12
#define P0_13	XMC_GPIO_PORT0, 13
#define P0_14	XMC_GPIO_PORT0, 14
#define P0_15	XMC_GPIO_PORT0, 15
#define P1_0	XMC_GPIO_PORT1, 0
#define P1_1	XMC_GPIO_PORT1, 1
#define P1_2	XMC_GPIO_PORT1, 2
#define P1_3	XMC_GPIO_PORT1, 3
#define P1_4	XMC_GPIO_PORT1, 4
#define P1_5	XMC_GPIO_PORT1, 5
#define P1_6	XMC_GPIO_PORT1, 6
#define P2_0	XMC_GPIO_PORT2, 0
#define P2_1	XMC_GPIO_PORT2, 1
#define P2_2	XMC_GPIO_PORT2, 2
#define P2_3	XMC_GPIO_PORT2, 3
#define P2_4	XMC_GPIO_PORT2, 4
#define P2_5	XMC_GPIO_PORT2, 5
#define P2_6	XMC_GPIO_PORT2, 6
#define P2_7	XMC_GPIO_PORT2, 7
#define P2_8	XMC_GPIO_PORT2, 8
#define P2_9	XMC_GPIO_PORT2, 9
#define P2_10	XMC_GPIO_PORT2, 10
#define P2_11	XMC_GPIO_PORT2, 11


/* Alternate Output Function */
#define P0_0_AF_ERU0_PDOUT0 	(0x8UL)
#define P0_0_AF_LEDTS0_LINE7	(0x10UL)
#define P0_0_AF_ERU0_GOUT0  	(0x18UL)
#define P0_0_AF_CCU40_OUT0  	(0x20UL)
#define P0_0_AF_U0C0_SELO0  	(0x30UL)
#define P0_0_AF_U0C1_SELO0  	(0x38UL)
#define P0_1_AF_ERU0_PDOUT1 	(0x8UL)
#define P0_1_AF_LEDTS0_LINE6	(0x10UL)
#define P0_1_AF_ERU0_GOUT1  	(0x18UL)
#define P0_1_AF_CCU40_OUT1  	(0x20UL)
#define P0_1_AF_SCU_VDROP   	(0x38UL)
#define P0_2_AF_ERU0_PDOUT2 	(0x8UL)
#define P0_2_AF_LEDTS0_LINE5	(0x10UL)
#define P0_2_AF_ERU0_GOUT2  	(0x18UL)
#define P0_2_AF_CCU40_OUT2  	(0x20UL)
#define P0_2_AF_VADC_EMUX2_IN	(0x30UL)
#define P0_3_AF_ERU0_PDOUT3 	(0x8UL)
#define P0_3_AF_LEDTS0_LINE4	(0x10UL)
#define P0_3_AF_ERU0_GOUT3  	(0x18UL)
#define P0_3_AF_CCU40_OUT3  	(0x20UL)
#define P0_3_AF_VADC_EMUX1_IN	(0x30UL)
#define P0_4_AF_LEDTS0_LINE3	(0x10UL)
#define P0_4_AF_LEDTS0_COL3 	(0x18UL)
#define P0_4_AF_CCU40_OUT1  	(0x20UL)
#define P0_4_AF_VADC_EMUX0_IN	(0x30UL)
#define P0_4_AF_WDT_REQUEST 	(0x38UL)
#define P0_5_AF_LEDTS0_LINE2	(0x10UL)
#define P0_5_AF_LEDTS0_COL2 	(0x18UL)
#define P0_5_AF_CCU40_OUT0  	(0x20UL)
#define P0_6_AF_LEDTS0_LINE1	(0x10UL)
#define P0_6_AF_LEDTS0_COL1 	(0x18UL)
#define P0_6_AF_CCU40_OUT0  	(0x20UL)
#define P0_6_AF_U0C1_MCLKOUT	(0x30UL)
#define P0_6_AF_U0C1_DOUT0  	(0x38UL)
#define P0_7_AF_LEDTS0_LINE0	(0x10UL)
#define P0_7_AF_LEDTS0_COL0 	(0x18UL)
#define P0_7_AF_CCU40_OUT1  	(0x20UL)
#define P0_7_AF_U0C0_SCLKOUT	(0x30UL)
#define P0_7_AF_U0C1_DOUT0  	(0x38UL)
#define P0_8_AF_LEDTS1_LINE0	(0x10UL)
#define P0_8_AF_LEDTS0_COLA 	(0x18UL)
#define P0_8_AF_CCU40_OUT2  	(0x20UL)
#define P0_8_AF_U0C0_SCLKOUT	(0x30UL)
#define P0_8_AF_U0C1_SCLKOUT	(0x38UL)
#define P0_9_AF_LEDTS1_LINE1	(0x10UL)
#define P0_9_AF_LEDTS0_COL6 	(0x18UL)
#define P0_9_AF_CCU40_OUT3  	(0x20UL)
#define P0_9_AF_U0C0_SELO0  	(0x30UL)
#define P0_9_AF_U0C1_SELO0  	(0x38UL)
#define P0_10_AF_LEDTS1_LINE2	(0x10UL)
#define P0_10_AF_LEDTS0_COL5	(0x18UL)
#define P0_10_AF_U0C0_SELO1 	(0x30UL)
#define P0_10_AF_U0C1_SELO1 	(0x38UL)
#define P0_11_AF_LEDTS1_LINE3	(0x10UL)
#define P0_11_AF_LEDTS0_COL4	(0x18UL)
#define P0_11_AF_U0C0_MCLKOUT	(0x20UL)
#define P0_11_AF_U0C0_SELO2 	(0x30UL)
#define P0_11_AF_U0C1_SELO2 	(0x38UL)
#define P0_12_AF_LEDTS1_LINE4	(0x10UL)
#define P0_12_AF_LEDTS0_COL3	(0x18UL)
#define P0_12_AF_LEDTS1_COL3	(0x20UL)
#define P0_12_AF_U0C0_SELO3 	(0x30UL)
#define P0_13_AF_WDT_REQUEST	(0x8UL)
#define P0_13_AF_LEDTS1_LINE5	(0x10UL)
#define P0_13_AF_LEDTS0_COL2	(0x18UL)
#define P0_13_AF_LEDTS1_COL2	(0x20UL)
#define P0_13_AF_U0C0_SELO4 	(0x30UL)
#define P0_14_AF_LEDTS1_LINE6	(0x10UL)
#define P0_14_AF_LEDTS0_COL1	(0x18UL)
#define P0_14_AF_LEDTS1_COL1	(0x20UL)
#define P0_14_AF_U0C0_DOUT0 	(0x30UL)
#define P0_14_AF_U0C0_SCLKOUT	(0x38UL)
#define P0_15_AF_LEDTS1_LINE7	(0x10UL)
#define P0_15_AF_LEDTS0_COL0	(0x18UL)
#define P0_15_AF_LEDTS1_COL0	(0x20UL)
#define P0_15_AF_U0C0_DOUT0 	(0x30UL)
#define P0_15_AF_U0C1_MCLKOUT	(0x38UL)
#define P1_0_AF_CCU40_OUT0  	(0x10UL)
#define P1_0_AF_LEDTS0_COL0 	(0x18UL)
#define P1_0_AF_LEDTS1_COLA 	(0x20UL)
#define P1_0_AF_U0C0_DOUT0  	(0x38UL)
#define P1_1_AF_VADC_EMUX0_IN	(0x8UL)
#define P1_1_AF_CCU40_OUT1  	(0x10UL)
#define P1_1_AF_LEDTS0_COL1 	(0x18UL)
#define P1_1_AF_LEDTS1_COL0 	(0x20UL)
#define P1_1_AF_U0C0_DOUT0  	(0x30UL)
#define P1_1_AF_U0C1_SELO0  	(0x38UL)
#define P1_2_AF_VADC_EMUX1_IN	(0x8UL)
#define P1_2_AF_CCU40_OUT2  	(0x10UL)
#define P1_2_AF_LEDTS0_COL2 	(0x18UL)
#define P1_2_AF_LEDTS1_COL1 	(0x20UL)
#define P1_2_AF_U0C1_DOUT0  	(0x38UL)
#define P1_3_AF_VADC_EMUX2_IN	(0x8UL)
#define P1_3_AF_CCU40_OUT3  	(0x10UL)
#define P1_3_AF_LEDTS0_COL3 	(0x18UL)
#define P1_3_AF_LEDTS1_COL2 	(0x20UL)
#define P1_3_AF_U0C1_SCLKOUT	(0x30UL)
#define P1_3_AF_U0C1_DOUT0  	(0x38UL)
#define P1_4_AF_VADC_EMUX0_IN	(0x8UL)
#define P1_4_AF_U0C1_SCLKOUT	(0x10UL)
#define P1_4_AF_LEDTS0_COL4 	(0x18UL)
#define P1_4_AF_LEDTS1_COL3 	(0x20UL)
#define P1_4_AF_U0C0_SELO0  	(0x30UL)
#define P1_4_AF_U0C1_SELO1  	(0x38UL)
#define P1_5_AF_VADC_EMUX1_IN	(0x8UL)
#define P1_5_AF_U0C0_DOUT0  	(0x10UL)
#define P1_5_AF_LEDTS0_COLA 	(0x18UL)
#define P1_5_AF_U0C0_SELO1  	(0x30UL)
#define P1_5_AF_U0C1_SELO2  	(0x38UL)
#define P1_6_AF_VADC_EMUX2_IN	(0x8UL)
#define P1_6_AF_U0C1_DOUT0  	(0x10UL)
#define P1_6_AF_LEDTS0_COL5 	(0x18UL)
#define P1_6_AF_U0C0_SCLKOUT	(0x20UL)
#define P1_6_AF_U0C0_SELO2  	(0x30UL)
#define P1_6_AF_U0C1_SELO3  	(0x38UL)
#define P2_0_AF_ERU0_PDOUT3 	(0x8UL)
#define P2_0_AF_CCU40_OUT0  	(0x10UL)
#define P2_0_AF_ERU0_GOUT3  	(0x18UL)
#define P2_0_AF_LEDTS1_COL5 	(0x20UL)
#define P2_0_AF_U0C0_DOUT0  	(0x30UL)
#define P2_0_AF_U0C0_SCLKOUT	(0x38UL)
#define P2_1_AF_ERU0_PDOUT2 	(0x8UL)
#define P2_1_AF_CCU40_OUT1  	(0x10UL)
#define P2_1_AF_ERU0_GOUT2  	(0x18UL)
#define P2_1_AF_LEDTS1_COL6 	(0x20UL)
#define P2_1_AF_U0C0_DOUT0  	(0x30UL)
#define P2_1_AF_U0C1_SCLKOUT	(0x38UL)
#define P2_10_AF_ERU0_PDOUT1	(0x8UL)
#define P2_10_AF_CCU40_OUT2 	(0x10UL)
#define P2_10_AF_ERU0_GOUT1 	(0x18UL)
#define P2_10_AF_LEDTS1_COL4	(0x20UL)
#define P2_10_AF_U0C1_DOUT0 	(0x38UL)
#define P2_11_AF_ERU0_PDOUT0	(0x8UL)
#define P2_11_AF_CCU40_OUT3 	(0x10UL)
#define P2_11_AF_ERU0_GOUT0 	(0x18UL)
#define P2_11_AF_LEDTS1_COL3	(0x20UL)
#define P2_11_AF_U0C1_SCLKOUT	(0x30UL)
#define P2_11_AF_U0C1_DOUT0 	(0x38UL)
#endif


#if (UC_DEVICE == XMC1201) && (UC_PACKAGE == TSSOP38)
#define P0_0	XMC_GPIO_PORT0, 0
#define P0_1	XMC_GPIO_PORT0, 1
#define P0_2	XMC_GPIO_PORT0, 2
#define P0_3	XMC_GPIO_PORT0, 3
#define P0_4	XMC_GPIO_PORT0, 4
#define P0_5	XMC_GPIO_PORT0, 5
#define P0_6	XMC_GPIO_PORT0, 6
#define P0_7	XMC_GPIO_PORT0, 7
#define P0_8	XMC_GPIO_PORT0, 8
#define P0_9	XMC_GPIO_PORT0, 9
#define P0_10	XMC_GPIO_PORT0, 10
#define P0_11	XMC_GPIO_PORT0, 11
#define P0_12	XMC_GPIO_PORT0, 12
#define P0_13	XMC_GPIO_PORT0, 13
#define P0_14	XMC_GPIO_PORT0, 14
#define P0_15	XMC_GPIO_PORT0, 15
#define P1_0	XMC_GPIO_PORT1, 0
#define P1_1	XMC_GPIO_PORT1, 1
#define P1_2	XMC_GPIO_PORT1, 2
#define P1_3	XMC_GPIO_PORT1, 3
#define P1_4	XMC_GPIO_PORT1, 4
#define P1_5	XMC_GPIO_PORT1, 5
#define P2_0	XMC_GPIO_PORT2, 0
#define P2_1	XMC_GPIO_PORT2, 1
#define P2_2	XMC_GPIO_PORT2, 2
#define P2_3	XMC_GPIO_PORT2, 3
#define P2_4	XMC_GPIO_PORT2, 4
#define P2_5	XMC_GPIO_PORT2, 5
#define P2_6	XMC_GPIO_PORT2, 6
#define P2_7	XMC_GPIO_PORT2, 7
#define P2_8	XMC_GPIO_PORT2, 8
#define P2_9	XMC_GPIO_PORT2, 9
#define P2_10	XMC_GPIO_PORT2, 10
#define P2_11	XMC_GPIO_PORT2, 11


/* Alternate Output Function */
#define P0_0_AF_ERU0_PDOUT0 	(0x8UL)
#define P0_0_AF_LEDTS0_LINE7	(0x10UL)
#define P0_0_AF_ERU0_GOUT0  	(0x18UL)
#define P0_0_AF_CCU40_OUT0  	(0x20UL)
#define P0_0_AF_U0C0_SELO0  	(0x30UL)
#define P0_0_AF_U0C1_SELO0  	(0x38UL)
#define P0_1_AF_ERU0_PDOUT1 	(0x8UL)
#define P0_1_AF_LEDTS0_LINE6	(0x10UL)
#define P0_1_AF_ERU0_GOUT1  	(0x18UL)
#define P0_1_AF_CCU40_OUT1  	(0x20UL)
#define P0_1_AF_SCU_VDROP   	(0x38UL)
#define P0_2_AF_ERU0_PDOUT2 	(0x8UL)
#define P0_2_AF_LEDTS0_LINE5	(0x10UL)
#define P0_2_AF_ERU0_GOUT2  	(0x18UL)
#define P0_2_AF_CCU40_OUT2  	(0x20UL)
#define P0_2_AF_VADC_EMUX2_IN	(0x30UL)
#define P0_3_AF_ERU0_PDOUT3 	(0x8UL)
#define P0_3_AF_LEDTS0_LINE4	(0x10UL)
#define P0_3_AF_ERU0_GOUT3  	(0x18UL)
#define P0_3_AF_CCU40_OUT3  	(0x20UL)
#define P0_3_AF_VADC_EMUX1_IN	(0x30UL)
#define P0_4_AF_LEDTS0_LINE3	(0x10UL)
#define P0_4_AF_LEDTS0_COL3 	(0x18UL)
#define P0_4_AF_CCU40_OUT1  	(0x20UL)
#define P0_4_AF_VADC_EMUX0_IN	(0x30UL)
#define P0_4_AF_WDT_REQUEST 	(0x38UL)
#define P0_5_AF_LEDTS0_LINE2	(0x10UL)
#define P0_5_AF_LEDTS0_COL2 	(0x18UL)
#define P0_5_AF_CCU40_OUT0  	(0x20UL)
#define P0_6_AF_LEDTS0_LINE1	(0x10UL)
#define P0_6_AF_LEDTS0_COL1 	(0x18UL)
#define P0_6_AF_CCU40_OUT0  	(0x20UL)
#define P0_6_AF_U0C1_MCLKOUT	(0x30UL)
#define P0_6_AF_U0C1_DOUT0  	(0x38UL)
#define P0_7_AF_LEDTS0_LINE0	(0x10UL)
#define P0_7_AF_LEDTS0_COL0 	(0x18UL)
#define P0_7_AF_CCU40_OUT1  	(0x20UL)
#define P0_7_AF_U0C0_SCLKOUT	(0x30UL)
#define P0_7_AF_U0C1_DOUT0  	(0x38UL)
#define P0_8_AF_LEDTS1_LINE0	(0x10UL)
#define P0_8_AF_LEDTS0_COLA 	(0x18UL)
#define P0_8_AF_CCU40_OUT2  	(0x20UL)
#define P0_8_AF_U0C0_SCLKOUT	(0x30UL)
#define P0_8_AF_U0C1_SCLKOUT	(0x38UL)
#define P0_9_AF_LEDTS1_LINE1	(0x10UL)
#define P0_9_AF_LEDTS0_COL6 	(0x18UL)
#define P0_9_AF_CCU40_OUT3  	(0x20UL)
#define P0_9_AF_U0C0_SELO0  	(0x30UL)
#define P0_9_AF_U0C1_SELO0  	(0x38UL)
#define P0_10_AF_LEDTS1_LINE2	(0x10UL)
#define P0_10_AF_LEDTS0_COL5	(0x18UL)
#define P0_10_AF_U0C0_SELO1 	(0x30UL)
#define P0_10_AF_U0C1_SELO1 	(0x38UL)
#define P0_11_AF_LEDTS1_LINE3	(0x10UL)
#define P0_11_AF_LEDTS0_COL4	(0x18UL)
#define P0_11_AF_U0C0_MCLKOUT	(0x20UL)
#define P0_11_AF_U0C0_SELO2 	(0x30UL)
#define P0_11_AF_U0C1_SELO2 	(0x38UL)
#define P0_12_AF_LEDTS1_LINE4	(0x10UL)
#define P0_12_AF_LEDTS0_COL3	(0x18UL)
#define P0_12_AF_LEDTS1_COL3	(0x20UL)
#define P0_12_AF_U0C0_SELO3 	(0x30UL)
#define P0_13_AF_WDT_REQUEST	(0x8UL)
#define P0_13_AF_LEDTS1_LINE5	(0x10UL)
#define P0_13_AF_LEDTS0_COL2	(0x18UL)
#define P0_13_AF_LEDTS1_COL2	(0x20UL)
#define P0_13_AF_U0C0_SELO4 	(0x30UL)
#define P0_14_AF_LEDTS1_LINE6	(0x10UL)
#define P0_14_AF_LEDTS0_COL1	(0x18UL)
#define P0_14_AF_LEDTS1_COL1	(0x20UL)
#define P0_14_AF_U0C0_DOUT0 	(0x30UL)
#define P0_14_AF_U0C0_SCLKOUT	(0x38UL)
#define P0_15_AF_LEDTS1_LINE7	(0x10UL)
#define P0_15_AF_LEDTS0_COL0	(0x18UL)
#define P0_15_AF_LEDTS1_COL0	(0x20UL)
#define P0_15_AF_U0C0_DOUT0 	(0x30UL)
#define P0_15_AF_U0C1_MCLKOUT	(0x38UL)
#define P1_0_AF_CCU40_OUT0  	(0x10UL)
#define P1_0_AF_LEDTS0_COL0 	(0x18UL)
#define P1_0_AF_LEDTS1_COLA 	(0x20UL)
#define P1_0_AF_U0C0_DOUT0  	(0x38UL)
#define P1_1_AF_VADC_EMUX0_IN	(0x8UL)
#define P1_1_AF_CCU40_OUT1  	(0x10UL)
#define P1_1_AF_LEDTS0_COL1 	(0x18UL)
#define P1_1_AF_LEDTS1_COL0 	(0x20UL)
#define P1_1_AF_U0C0_DOUT0  	(0x30UL)
#define P1_1_AF_U0C1_SELO0  	(0x38UL)
#define P1_2_AF_VADC_EMUX1_IN	(0x8UL)
#define P1_2_AF_CCU40_OUT2  	(0x10UL)
#define P1_2_AF_LEDTS0_COL2 	(0x18UL)
#define P1_2_AF_LEDTS1_COL1 	(0x20UL)
#define P1_2_AF_U0C1_DOUT0  	(0x38UL)
#define P1_3_AF_VADC_EMUX2_IN	(0x8UL)
#define P1_3_AF_CCU40_OUT3  	(0x10UL)
#define P1_3_AF_LEDTS0_COL3 	(0x18UL)
#define P1_3_AF_LEDTS1_COL2 	(0x20UL)
#define P1_3_AF_U0C1_SCLKOUT	(0x30UL)
#define P1_3_AF_U0C1_DOUT0  	(0x38UL)
#define P1_4_AF_VADC_EMUX0_IN	(0x8UL)
#define P1_4_AF_U0C1_SCLKOUT	(0x10UL)
#define P1_4_AF_LEDTS0_COL4 	(0x18UL)
#define P1_4_AF_LEDTS1_COL3 	(0x20UL)
#define P1_4_AF_U0C0_SELO0  	(0x30UL)
#define P1_4_AF_U0C1_SELO1  	(0x38UL)
#define P1_5_AF_VADC_EMUX1_IN	(0x8UL)
#define P1_5_AF_U0C0_DOUT0  	(0x10UL)
#define P1_5_AF_LEDTS0_COLA 	(0x18UL)
#define P1_5_AF_U0C0_SELO1  	(0x30UL)
#define P1_5_AF_U0C1_SELO2  	(0x38UL)
#define P2_0_AF_ERU0_PDOUT3 	(0x8UL)
#define P2_0_AF_CCU40_OUT0  	(0x10UL)
#define P2_0_AF_ERU0_GOUT3  	(0x18UL)
#define P2_0_AF_LEDTS1_COL5 	(0x20UL)
#define P2_0_AF_U0C0_DOUT0  	(0x30UL)
#define P2_0_AF_U0C0_SCLKOUT	(0x38UL)
#define P2_1_AF_ERU0_PDOUT2 	(0x8UL)
#define P2_1_AF_CCU40_OUT1  	(0x10UL)
#define P2_1_AF_ERU0_GOUT2  	(0x18UL)
#define P2_1_AF_LEDTS1_COL6 	(0x20UL)
#define P2_1_AF_U0C0_DOUT0  	(0x30UL)
#define P2_1_AF_U0C1_SCLKOUT	(0x38UL)
#define P2_10_AF_ERU0_PDOUT1	(0x8UL)
#define P2_10_AF_CCU40_OUT2 	(0x10UL)
#define P2_10_AF_ERU0_GOUT1 	(0x18UL)
#define P2_10_AF_LEDTS1_COL4	(0x20UL)
#define P2_10_AF_U0C1_DOUT0 	(0x38UL)
#define P2_11_AF_ERU0_PDOUT0	(0x8UL)
#define P2_11_AF_CCU40_OUT3 	(0x10UL)
#define P2_11_AF_ERU0_GOUT0 	(0x18UL)
#define P2_11_AF_LEDTS1_COL3	(0x20UL)
#define P2_11_AF_U0C1_SCLKOUT	(0x30UL)
#define P2_11_AF_U0C1_DOUT0 	(0x38UL)
#endif


#if (UC_DEVICE == XMC1202) && (UC_PACKAGE == VQFN24)
#define P0_0	XMC_GPIO_PORT0, 0
#define P0_1	XMC_GPIO_PORT0, 1
#define P0_2	XMC_GPIO_PORT0, 2
#define P0_3	XMC_GPIO_PORT0, 3
#define P0_5	XMC_GPIO_PORT0, 5
#define P0_6	XMC_GPIO_PORT0, 6
#define P0_7	XMC_GPIO_PORT0, 7
#define P0_8	XMC_GPIO_PORT0, 8
#define P0_9	XMC_GPIO_PORT0, 9
#define P0_12	XMC_GPIO_PORT0, 12
#define P0_13	XMC_GPIO_PORT0, 13
#define P0_14	XMC_GPIO_PORT0, 14
#define P0_15	XMC_GPIO_PORT0, 15
#define P1_0	XMC_GPIO_PORT1, 0
#define P1_1	XMC_GPIO_PORT1, 1
#define P1_2	XMC_GPIO_PORT1, 2
#define P1_3	XMC_GPIO_PORT1, 3
#define P2_0	XMC_GPIO_PORT2, 0
#define P2_1	XMC_GPIO_PORT2, 1
#define P2_2	XMC_GPIO_PORT2, 2
#define P2_6	XMC_GPIO_PORT2, 6
#define P2_7	XMC_GPIO_PORT2, 7
#define P2_8	XMC_GPIO_PORT2, 8
#define P2_9	XMC_GPIO_PORT2, 9
#define P2_10	XMC_GPIO_PORT2, 10
#define P2_11	XMC_GPIO_PORT2, 11


/* Alternate Output Function */
#define P0_0_AF_ERU0_PDOUT0 	(0x8UL)
#define P0_0_AF_ERU0_GOUT0  	(0x18UL)
#define P0_0_AF_CCU40_OUT0  	(0x20UL)
#define P0_0_AF_U0C0_SELO0  	(0x30UL)
#define P0_0_AF_U0C1_SELO0  	(0x38UL)
#define P0_5_AF_BCCU0_OUT1  	(0x8UL)
#define P0_5_AF_CCU40_OUT0  	(0x20UL)
#define P0_5_AF_ACMP2_OUT   	(0x30UL)
#define P0_6_AF_BCCU0_OUT2  	(0x8UL)
#define P0_6_AF_CCU40_OUT0  	(0x20UL)
#define P0_6_AF_U0C1_MCLKOUT	(0x30UL)
#define P0_6_AF_U0C1_DOUT0  	(0x38UL)
#define P0_7_AF_BCCU0_OUT3  	(0x8UL)
#define P0_7_AF_CCU40_OUT1  	(0x20UL)
#define P0_7_AF_U0C0_SCLKOUT	(0x30UL)
#define P0_7_AF_U0C1_DOUT0  	(0x38UL)
#define P0_8_AF_BCCU0_OUT4  	(0x8UL)
#define P0_8_AF_CCU40_OUT2  	(0x20UL)
#define P0_8_AF_U0C0_SCLKOUT	(0x30UL)
#define P0_8_AF_U0C1_SCLKOUT	(0x38UL)
#define P0_9_AF_BCCU0_OUT5  	(0x8UL)
#define P0_9_AF_CCU40_OUT3  	(0x20UL)
#define P0_9_AF_U0C0_SELO0  	(0x30UL)
#define P0_9_AF_U0C1_SELO0  	(0x38UL)
#define P0_12_AF_BCCU0_OUT6 	(0x8UL)
#define P0_12_AF_U0C0_SELO3 	(0x30UL)
#define P0_13_AF_WDT_REQUEST	(0x8UL)
#define P0_13_AF_U0C0_SELO4 	(0x30UL)
#define P0_14_AF_BCCU0_OUT7 	(0x8UL)
#define P0_14_AF_U0C0_DOUT0 	(0x30UL)
#define P0_14_AF_U0C0_SCLKOUT	(0x38UL)
#define P0_15_AF_BCCU0_OUT8 	(0x8UL)
#define P0_15_AF_U0C0_DOUT0 	(0x30UL)
#define P0_15_AF_U0C1_MCLKOUT	(0x38UL)
#define P1_0_AF_BCCU0_OUT0  	(0x8UL)
#define P1_0_AF_CCU40_OUT0  	(0x10UL)
#define P1_0_AF_ACMP1_OUT   	(0x30UL)
#define P1_0_AF_U0C0_DOUT0  	(0x38UL)
#define P1_1_AF_VADC_EMUX0_IN	(0x8UL)
#define P1_1_AF_CCU40_OUT1  	(0x10UL)
#define P1_1_AF_U0C0_DOUT0  	(0x30UL)
#define P1_1_AF_U0C1_SELO0  	(0x38UL)
#define P1_2_AF_VADC_EMUX1_IN	(0x8UL)
#define P1_2_AF_CCU40_OUT2  	(0x10UL)
#define P1_2_AF_ACMP2_OUT   	(0x30UL)
#define P1_2_AF_U0C1_DOUT0  	(0x38UL)
#define P1_3_AF_VADC_EMUX2_IN	(0x8UL)
#define P1_3_AF_CCU40_OUT3  	(0x10UL)
#define P1_3_AF_U0C1_SCLKOUT	(0x30UL)
#define P1_3_AF_U0C1_DOUT0  	(0x38UL)
#define P2_0_AF_ERU0_PDOUT3 	(0x8UL)
#define P2_0_AF_CCU40_OUT0  	(0x10UL)
#define P2_0_AF_ERU0_GOUT3  	(0x18UL)
#define P2_0_AF_U0C0_DOUT0  	(0x30UL)
#define P2_0_AF_U0C0_SCLKOUT	(0x38UL)
#define P2_1_AF_ERU0_PDOUT2 	(0x8UL)
#define P2_1_AF_CCU40_OUT1  	(0x10UL)
#define P2_1_AF_ERU0_GOUT2  	(0x18UL)
#define P2_1_AF_U0C0_DOUT0  	(0x30UL)
#define P2_1_AF_U0C1_SCLKOUT	(0x38UL)
#define P2_10_AF_ERU0_PDOUT1	(0x8UL)
#define P2_10_AF_CCU40_OUT2 	(0x10UL)
#define P2_10_AF_ERU0_GOUT1 	(0x18UL)
#define P2_10_AF_ACMP0_OUT  	(0x30UL)
#define P2_10_AF_U0C1_DOUT0 	(0x38UL)
#define P2_11_AF_ERU0_PDOUT0	(0x8UL)
#define P2_11_AF_CCU40_OUT3 	(0x10UL)
#define P2_11_AF_ERU0_GOUT0 	(0x18UL)
#define P2_11_AF_U0C1_SCLKOUT	(0x30UL)
#define P2_11_AF_U0C1_DOUT0 	(0x38UL)
#endif


#if (UC_DEVICE == XMC1202) && (UC_PACKAGE == VQFN40)
#define P0_0	XMC_GPIO_PORT0, 0
#define P0_1	XMC_GPIO_PORT0, 1
#define P0_2	XMC_GPIO_PORT0, 2
#define P0_3	XMC_GPIO_PORT0, 3
#define P0_4	XMC_GPIO_PORT0, 4
#define P0_5	XMC_GPIO_PORT0, 5
#define P0_6	XMC_GPIO_PORT0, 6
#define P0_7	XMC_GPIO_PORT0, 7
#define P0_8	XMC_GPIO_PORT0, 8
#define P0_9	XMC_GPIO_PORT0, 9
#define P0_10	XMC_GPIO_PORT0, 10
#define P0_11	XMC_GPIO_PORT0, 11
#define P0_12	XMC_GPIO_PORT0, 12
#define P0_13	XMC_GPIO_PORT0, 13
#define P0_14	XMC_GPIO_PORT0, 14
#define P0_15	XMC_GPIO_PORT0, 15
#define P1_0	XMC_GPIO_PORT1, 0
#define P1_1	XMC_GPIO_PORT1, 1
#define P1_2	XMC_GPIO_PORT1, 2
#define P1_3	XMC_GPIO_PORT1, 3
#define P1_4	XMC_GPIO_PORT1, 4
#define P1_5	XMC_GPIO_PORT1, 5
#define P1_6	XMC_GPIO_PORT1, 6
#define P2_0	XMC_GPIO_PORT2, 0
#define P2_1	XMC_GPIO_PORT2, 1
#define P2_2	XMC_GPIO_PORT2, 2
#define P2_3	XMC_GPIO_PORT2, 3
#define P2_4	XMC_GPIO_PORT2, 4
#define P2_5	XMC_GPIO_PORT2, 5
#define P2_6	XMC_GPIO_PORT2, 6
#define P2_7	XMC_GPIO_PORT2, 7
#define P2_8	XMC_GPIO_PORT2, 8
#define P2_9	XMC_GPIO_PORT2, 9
#define P2_10	XMC_GPIO_PORT2, 10
#define P2_11	XMC_GPIO_PORT2, 11


/* Alternate Output Function */
#define P0_0_AF_ERU0_PDOUT0 	(0x8UL)
#define P0_0_AF_ERU0_GOUT0  	(0x18UL)
#define P0_0_AF_CCU40_OUT0  	(0x20UL)
#define P0_0_AF_U0C0_SELO0  	(0x30UL)
#define P0_0_AF_U0C1_SELO0  	(0x38UL)
#define P0_1_AF_ERU0_PDOUT1 	(0x8UL)
#define P0_1_AF_ERU0_GOUT1  	(0x18UL)
#define P0_1_AF_CCU40_OUT1  	(0x20UL)
#define P0_1_AF_SCU_VDROP   	(0x38UL)
#define P0_2_AF_ERU0_PDOUT2 	(0x8UL)
#define P0_2_AF_ERU0_GOUT2  	(0x18UL)
#define P0_2_AF_CCU40_OUT2  	(0x20UL)
#define P0_2_AF_VADC_EMUX2_IN	(0x30UL)
#define P0_3_AF_ERU0_PDOUT3 	(0x8UL)
#define P0_3_AF_ERU0_GOUT3  	(0x18UL)
#define P0_3_AF_CCU40_OUT3  	(0x20UL)
#define P0_3_AF_VADC_EMUX1_IN	(0x30UL)
#define P0_4_AF_BCCU0_OUT0  	(0x8UL)
#define P0_4_AF_CCU40_OUT1  	(0x20UL)
#define P0_4_AF_VADC_EMUX0_IN	(0x30UL)
#define P0_4_AF_WDT_REQUEST 	(0x38UL)
#define P0_5_AF_BCCU0_OUT1  	(0x8UL)
#define P0_5_AF_CCU40_OUT0  	(0x20UL)
#define P0_5_AF_ACMP2_OUT   	(0x30UL)
#define P0_6_AF_BCCU0_OUT2  	(0x8UL)
#define P0_6_AF_CCU40_OUT0  	(0x20UL)
#define P0_6_AF_U0C1_MCLKOUT	(0x30UL)
#define P0_6_AF_U0C1_DOUT0  	(0x38UL)
#define P0_7_AF_BCCU0_OUT3  	(0x8UL)
#define P0_7_AF_CCU40_OUT1  	(0x20UL)
#define P0_7_AF_U0C0_SCLKOUT	(0x30UL)
#define P0_7_AF_U0C1_DOUT0  	(0x38UL)
#define P0_8_AF_BCCU0_OUT4  	(0x8UL)
#define P0_8_AF_CCU40_OUT2  	(0x20UL)
#define P0_8_AF_U0C0_SCLKOUT	(0x30UL)
#define P0_8_AF_U0C1_SCLKOUT	(0x38UL)
#define P0_9_AF_BCCU0_OUT5  	(0x8UL)
#define P0_9_AF_CCU40_OUT3  	(0x20UL)
#define P0_9_AF_U0C0_SELO0  	(0x30UL)
#define P0_9_AF_U0C1_SELO0  	(0x38UL)
#define P0_10_AF_BCCU0_OUT6 	(0x8UL)
#define P0_10_AF_ACMP0_OUT  	(0x20UL)
#define P0_10_AF_U0C0_SELO1 	(0x30UL)
#define P0_10_AF_U0C1_SELO1 	(0x38UL)
#define P0_11_AF_U0C0_MCLKOUT	(0x20UL)
#define P0_11_AF_U0C0_SELO2 	(0x30UL)
#define P0_11_AF_U0C1_SELO2 	(0x38UL)
#define P0_12_AF_BCCU0_OUT6 	(0x8UL)
#define P0_12_AF_U0C0_SELO3 	(0x30UL)
#define P0_13_AF_WDT_REQUEST	(0x8UL)
#define P0_13_AF_U0C0_SELO4 	(0x30UL)
#define P0_14_AF_BCCU0_OUT7 	(0x8UL)
#define P0_14_AF_U0C0_DOUT0 	(0x30UL)
#define P0_14_AF_U0C0_SCLKOUT	(0x38UL)
#define P0_15_AF_BCCU0_OUT8 	(0x8UL)
#define P0_15_AF_U0C0_DOUT0 	(0x30UL)
#define P0_15_AF_U0C1_MCLKOUT	(0x38UL)
#define P1_0_AF_BCCU0_OUT0  	(0x8UL)
#define P1_0_AF_CCU40_OUT0  	(0x10UL)
#define P1_0_AF_ACMP1_OUT   	(0x30UL)
#define P1_0_AF_U0C0_DOUT0  	(0x38UL)
#define P1_1_AF_VADC_EMUX0_IN	(0x8UL)
#define P1_1_AF_CCU40_OUT1  	(0x10UL)
#define P1_1_AF_U0C0_DOUT0  	(0x30UL)
#define P1_1_AF_U0C1_SELO0  	(0x38UL)
#define P1_2_AF_VADC_EMUX1_IN	(0x8UL)
#define P1_2_AF_CCU40_OUT2  	(0x10UL)
#define P1_2_AF_ACMP2_OUT   	(0x30UL)
#define P1_2_AF_U0C1_DOUT0  	(0x38UL)
#define P1_3_AF_VADC_EMUX2_IN	(0x8UL)
#define P1_3_AF_CCU40_OUT3  	(0x10UL)
#define P1_3_AF_U0C1_SCLKOUT	(0x30UL)
#define P1_3_AF_U0C1_DOUT0  	(0x38UL)
#define P1_4_AF_VADC_EMUX0_IN	(0x8UL)
#define P1_4_AF_U0C1_SCLKOUT	(0x10UL)
#define P1_4_AF_U0C0_SELO0  	(0x30UL)
#define P1_4_AF_U0C1_SELO1  	(0x38UL)
#define P1_5_AF_VADC_EMUX1_IN	(0x8UL)
#define P1_5_AF_U0C0_DOUT0  	(0x10UL)
#define P1_5_AF_U0C0_SELO1  	(0x30UL)
#define P1_5_AF_U0C1_SELO2  	(0x38UL)
#define P1_6_AF_VADC_EMUX2_IN	(0x8UL)
#define P1_6_AF_U0C1_DOUT0  	(0x10UL)
#define P1_6_AF_U0C0_SCLKOUT	(0x20UL)
#define P1_6_AF_U0C0_SELO2  	(0x30UL)
#define P1_6_AF_U0C1_SELO3  	(0x38UL)
#define P2_0_AF_ERU0_PDOUT3 	(0x8UL)
#define P2_0_AF_CCU40_OUT0  	(0x10UL)
#define P2_0_AF_ERU0_GOUT3  	(0x18UL)
#define P2_0_AF_U0C0_DOUT0  	(0x30UL)
#define P2_0_AF_U0C0_SCLKOUT	(0x38UL)
#define P2_1_AF_ERU0_PDOUT2 	(0x8UL)
#define P2_1_AF_CCU40_OUT1  	(0x10UL)
#define P2_1_AF_ERU0_GOUT2  	(0x18UL)
#define P2_1_AF_U0C0_DOUT0  	(0x30UL)
#define P2_1_AF_U0C1_SCLKOUT	(0x38UL)
#define P2_10_AF_ERU0_PDOUT1	(0x8UL)
#define P2_10_AF_CCU40_OUT2 	(0x10UL)
#define P2_10_AF_ERU0_GOUT1 	(0x18UL)
#define P2_10_AF_ACMP0_OUT  	(0x30UL)
#define P2_10_AF_U0C1_DOUT0 	(0x38UL)
#define P2_11_AF_ERU0_PDOUT0	(0x8UL)
#define P2_11_AF_CCU40_OUT3 	(0x10UL)
#define P2_11_AF_ERU0_GOUT0 	(0x18UL)
#define P2_11_AF_U0C1_SCLKOUT	(0x30UL)
#define P2_11_AF_U0C1_DOUT0 	(0x38UL)
#endif


#if (UC_DEVICE == XMC1202) && (UC_PACKAGE == TSSOP16)
#define P0_0	XMC_GPIO_PORT0, 0
#define P0_1	XMC_GPIO_PORT0, 1
#define P0_2	XMC_GPIO_PORT0, 2
#define P0_3	XMC_GPIO_PORT0, 3
#define P0_5	XMC_GPIO_PORT0, 5
#define P0_6	XMC_GPIO_PORT0, 6
#define P0_7	XMC_GPIO_PORT0, 7
#define P0_8	XMC_GPIO_PORT0, 8
#define P0_9	XMC_GPIO_PORT0, 9
#define P0_14	XMC_GPIO_PORT0, 14
#define P0_15	XMC_GPIO_PORT0, 15
#define P2_0	XMC_GPIO_PORT2, 0
#define P2_6	XMC_GPIO_PORT2, 6
#define P2_7	XMC_GPIO_PORT2, 7
#define P2_8	XMC_GPIO_PORT2, 8
#define P2_9	XMC_GPIO_PORT2, 9
#define P2_10	XMC_GPIO_PORT2, 10
#define P2_11	XMC_GPIO_PORT2, 11


/* Alternate Output Function */
#define P0_0_AF_ERU0_PDOUT0 	(0x8UL)
#define P0_0_AF_ERU0_GOUT0  	(0x18UL)
#define P0_0_AF_CCU40_OUT0  	(0x20UL)
#define P0_0_AF_U0C0_SELO0  	(0x30UL)
#define P0_0_AF_U0C1_SELO0  	(0x38UL)
#define P0_5_AF_BCCU0_OUT1  	(0x8UL)
#define P0_5_AF_CCU40_OUT0  	(0x20UL)
#define P0_6_AF_BCCU0_OUT2  	(0x8UL)
#define P0_6_AF_CCU40_OUT0  	(0x20UL)
#define P0_6_AF_U0C1_MCLKOUT	(0x30UL)
#define P0_6_AF_U0C1_DOUT0  	(0x38UL)
#define P0_7_AF_BCCU0_OUT3  	(0x8UL)
#define P0_7_AF_CCU40_OUT1  	(0x20UL)
#define P0_7_AF_U0C0_SCLKOUT	(0x30UL)
#define P0_7_AF_U0C1_DOUT0  	(0x38UL)
#define P0_8_AF_BCCU0_OUT4  	(0x8UL)
#define P0_8_AF_CCU40_OUT2  	(0x20UL)
#define P0_8_AF_U0C0_SCLKOUT	(0x30UL)
#define P0_8_AF_U0C1_SCLKOUT	(0x38UL)
#define P0_9_AF_BCCU0_OUT5  	(0x8UL)
#define P0_9_AF_CCU40_OUT3  	(0x20UL)
#define P0_9_AF_U0C0_SELO0  	(0x30UL)
#define P0_9_AF_U0C1_SELO0  	(0x38UL)
#define P0_14_AF_BCCU0_OUT7 	(0x8UL)
#define P0_14_AF_U0C0_DOUT0 	(0x30UL)
#define P0_14_AF_U0C0_SCLKOUT	(0x38UL)
#define P0_15_AF_BCCU0_OUT8 	(0x8UL)
#define P0_15_AF_U0C0_DOUT0 	(0x30UL)
#define P0_15_AF_U0C1_MCLKOUT	(0x38UL)
#define P2_0_AF_ERU0_PDOUT3 	(0x8UL)
#define P2_0_AF_CCU40_OUT0  	(0x10UL)
#define P2_0_AF_ERU0_GOUT3  	(0x18UL)
#define P2_0_AF_U0C0_DOUT0  	(0x30UL)
#define P2_0_AF_U0C0_SCLKOUT	(0x38UL)
#define P2_10_AF_ERU0_PDOUT1	(0x8UL)
#define P2_10_AF_CCU40_OUT2 	(0x10UL)
#define P2_10_AF_ERU0_GOUT1 	(0x18UL)
#define P2_10_AF_ACMP0_OUT  	(0x30UL)
#define P2_10_AF_U0C1_DOUT0 	(0x38UL)
#define P2_11_AF_ERU0_PDOUT0	(0x8UL)
#define P2_11_AF_CCU40_OUT3 	(0x10UL)
#define P2_11_AF_ERU0_GOUT0 	(0x18UL)
#define P2_11_AF_U0C1_SCLKOUT	(0x30UL)
#define P2_11_AF_U0C1_DOUT0 	(0x38UL)
#endif


#if (UC_DEVICE == XMC1202) && (UC_PACKAGE == TSSOP28)
#define P0_0	XMC_GPIO_PORT0, 0
#define P0_1	XMC_GPIO_PORT0, 1
#define P0_2	XMC_GPIO_PORT0, 2
#define P0_3	XMC_GPIO_PORT0, 3
#define P0_4	XMC_GPIO_PORT0, 4
#define P0_5	XMC_GPIO_PORT0, 5
#define P0_6	XMC_GPIO_PORT0, 6
#define P0_7	XMC_GPIO_PORT0, 7
#define P0_8	XMC_GPIO_PORT0, 8
#define P0_9	XMC_GPIO_PORT0, 9
#define P0_10	XMC_GPIO_PORT0, 10
#define P0_12	XMC_GPIO_PORT0, 12
#define P0_13	XMC_GPIO_PORT0, 13
#define P0_14	XMC_GPIO_PORT0, 14
#define P0_15	XMC_GPIO_PORT0, 15
#define P1_0	XMC_GPIO_PORT1, 0
#define P1_1	XMC_GPIO_PORT1, 1
#define P1_2	XMC_GPIO_PORT1, 2
#define P1_3	XMC_GPIO_PORT1, 3
#define P2_0	XMC_GPIO_PORT2, 0
#define P2_1	XMC_GPIO_PORT2, 1
#define P2_2	XMC_GPIO_PORT2, 2
#define P2_5	XMC_GPIO_PORT2, 5
#define P2_6	XMC_GPIO_PORT2, 6
#define P2_7	XMC_GPIO_PORT2, 7
#define P2_8	XMC_GPIO_PORT2, 8
#define P2_9	XMC_GPIO_PORT2, 9
#define P2_10	XMC_GPIO_PORT2, 10
#define P2_11	XMC_GPIO_PORT2, 11


/* Alternate Output Function */
#define P0_0_AF_ERU0_PDOUT0 	(0x8UL)
#define P0_0_AF_ERU0_GOUT0  	(0x18UL)
#define P0_0_AF_CCU40_OUT0  	(0x20UL)
#define P0_0_AF_U0C0_SELO0  	(0x30UL)
#define P0_0_AF_U0C1_SELO0  	(0x38UL)
#define P0_4_AF_BCCU0_OUT0  	(0x8UL)
#define P0_4_AF_CCU40_OUT1  	(0x20UL)
#define P0_4_AF_VADC_EMUX0_IN	(0x30UL)
#define P0_4_AF_WDT_REQUEST 	(0x38UL)
#define P0_5_AF_BCCU0_OUT1  	(0x8UL)
#define P0_5_AF_CCU40_OUT0  	(0x20UL)
#define P0_5_AF_ACMP2_OUT   	(0x30UL)
#define P0_6_AF_BCCU0_OUT2  	(0x8UL)
#define P0_6_AF_CCU40_OUT0  	(0x20UL)
#define P0_6_AF_U0C1_MCLKOUT	(0x30UL)
#define P0_6_AF_U0C1_DOUT0  	(0x38UL)
#define P0_7_AF_BCCU0_OUT3  	(0x8UL)
#define P0_7_AF_CCU40_OUT1  	(0x20UL)
#define P0_7_AF_U0C0_SCLKOUT	(0x30UL)
#define P0_7_AF_U0C1_DOUT0  	(0x38UL)
#define P0_8_AF_BCCU0_OUT4  	(0x8UL)
#define P0_8_AF_CCU40_OUT2  	(0x20UL)
#define P0_8_AF_U0C0_SCLKOUT	(0x30UL)
#define P0_8_AF_U0C1_SCLKOUT	(0x38UL)
#define P0_9_AF_BCCU0_OUT5  	(0x8UL)
#define P0_9_AF_CCU40_OUT3  	(0x20UL)
#define P0_9_AF_U0C0_SELO0  	(0x30UL)
#define P0_9_AF_U0C1_SELO0  	(0x38UL)
#define P0_10_AF_BCCU0_OUT6 	(0x8UL)
#define P0_10_AF_ACMP0_OUT  	(0x20UL)
#define P0_10_AF_U0C0_SELO1 	(0x30UL)
#define P0_10_AF_U0C1_SELO1 	(0x38UL)
#define P0_12_AF_BCCU0_OUT6 	(0x8UL)
#define P0_12_AF_U0C0_SELO3 	(0x30UL)
#define P0_13_AF_WDT_REQUEST	(0x8UL)
#define P0_13_AF_U0C0_SELO4 	(0x30UL)
#define P0_14_AF_BCCU0_OUT7 	(0x8UL)
#define P0_14_AF_U0C0_DOUT0 	(0x30UL)
#define P0_14_AF_U0C0_SCLKOUT	(0x38UL)
#define P0_15_AF_BCCU0_OUT8 	(0x8UL)
#define P0_15_AF_U0C0_DOUT0 	(0x30UL)
#define P0_15_AF_U0C1_MCLKOUT	(0x38UL)
#define P1_0_AF_BCCU0_OUT0  	(0x8UL)
#define P1_0_AF_CCU40_OUT0  	(0x10UL)
#define P1_0_AF_ACMP1_OUT   	(0x30UL)
#define P1_0_AF_U0C0_DOUT0  	(0x38UL)
#define P1_1_AF_VADC_EMUX0_IN	(0x8UL)
#define P1_1_AF_CCU40_OUT1  	(0x10UL)
#define P1_1_AF_U0C0_DOUT0  	(0x30UL)
#define P1_1_AF_U0C1_SELO0  	(0x38UL)
#define P1_2_AF_VADC_EMUX1_IN	(0x8UL)
#define P1_2_AF_CCU40_OUT2  	(0x10UL)
#define P1_2_AF_ACMP2_OUT   	(0x30UL)
#define P1_2_AF_U0C1_DOUT0  	(0x38UL)
#define P1_3_AF_VADC_EMUX2_IN	(0x8UL)
#define P1_3_AF_CCU40_OUT3  	(0x10UL)
#define P1_3_AF_U0C1_SCLKOUT	(0x30UL)
#define P1_3_AF_U0C1_DOUT0  	(0x38UL)
#define P2_0_AF_ERU0_PDOUT3 	(0x8UL)
#define P2_0_AF_CCU40_OUT0  	(0x10UL)
#define P2_0_AF_ERU0_GOUT3  	(0x18UL)
#define P2_0_AF_U0C0_DOUT0  	(0x30UL)
#define P2_0_AF_U0C0_SCLKOUT	(0x38UL)
#define P2_1_AF_ERU0_PDOUT2 	(0x8UL)
#define P2_1_AF_CCU40_OUT1  	(0x10UL)
#define P2_1_AF_ERU0_GOUT2  	(0x18UL)
#define P2_1_AF_U0C0_DOUT0  	(0x30UL)
#define P2_1_AF_U0C1_SCLKOUT	(0x38UL)
#define P2_10_AF_ERU0_PDOUT1	(0x8UL)
#define P2_10_AF_CCU40_OUT2 	(0x10UL)
#define P2_10_AF_ERU0_GOUT1 	(0x18UL)
#define P2_10_AF_ACMP0_OUT  	(0x30UL)
#define P2_10_AF_U0C1_DOUT0 	(0x38UL)
#define P2_11_AF_ERU0_PDOUT0	(0x8UL)
#define P2_11_AF_CCU40_OUT3 	(0x10UL)
#define P2_11_AF_ERU0_GOUT0 	(0x18UL)
#define P2_11_AF_U0C1_SCLKOUT	(0x30UL)
#define P2_11_AF_U0C1_DOUT0 	(0x38UL)
#endif


#if (UC_DEVICE == XMC1301) && (UC_PACKAGE == VQFN24)
#define P0_0	XMC_GPIO_PORT0, 0
#define P0_1	XMC_GPIO_PORT0, 1
#define P0_2	XMC_GPIO_PORT0, 2
#define P0_3	XMC_GPIO_PORT0, 3
#define P0_5	XMC_GPIO_PORT0, 5
#define P0_6	XMC_GPIO_PORT0, 6
#define P0_7	XMC_GPIO_PORT0, 7
#define P0_8	XMC_GPIO_PORT0, 8
#define P0_9	XMC_GPIO_PORT0, 9
#define P0_12	XMC_GPIO_PORT0, 12
#define P0_13	XMC_GPIO_PORT0, 13
#define P0_14	XMC_GPIO_PORT0, 14
#define P0_15	XMC_GPIO_PORT0, 15
#define P1_0	XMC_GPIO_PORT1, 0
#define P1_1	XMC_GPIO_PORT1, 1
#define P1_2	XMC_GPIO_PORT1, 2
#define P1_3	XMC_GPIO_PORT1, 3
#define P2_0	XMC_GPIO_PORT2, 0
#define P2_1	XMC_GPIO_PORT2, 1
#define P2_2	XMC_GPIO_PORT2, 2
#define P2_6	XMC_GPIO_PORT2, 6
#define P2_7	XMC_GPIO_PORT2, 7
#define P2_8	XMC_GPIO_PORT2, 8
#define P2_9	XMC_GPIO_PORT2, 9
#define P2_10	XMC_GPIO_PORT2, 10
#define P2_11	XMC_GPIO_PORT2, 11


/* Alternate Output Function */
#define P0_0_AF_ERU0_PDOUT0 	(0x8UL)
#define P0_0_AF_ERU0_GOUT0  	(0x18UL)
#define P0_0_AF_CCU40_OUT0  	(0x20UL)
#define P0_0_AF_CCU80_OUT00 	(0x28UL)
#define P0_0_AF_U0C0_SELO0  	(0x30UL)
#define P0_0_AF_U0C1_SELO0  	(0x38UL)
#define P0_5_AF_CCU40_OUT0  	(0x20UL)
#define P0_5_AF_CCU80_OUT12 	(0x28UL)
#define P0_5_AF_ACMP2_OUT   	(0x30UL)
#define P0_5_AF_CCU80_OUT01 	(0x38UL)
#define P0_6_AF_CCU40_OUT0  	(0x20UL)
#define P0_6_AF_CCU80_OUT11 	(0x28UL)
#define P0_6_AF_U0C1_MCLKOUT	(0x30UL)
#define P0_6_AF_U0C1_DOUT0  	(0x38UL)
#define P0_7_AF_CCU40_OUT1  	(0x20UL)
#define P0_7_AF_CCU80_OUT10 	(0x28UL)
#define P0_7_AF_U0C0_SCLKOUT	(0x30UL)
#define P0_7_AF_U0C1_DOUT0  	(0x38UL)
#define P0_8_AF_CCU40_OUT2  	(0x20UL)
#define P0_8_AF_CCU80_OUT20 	(0x28UL)
#define P0_8_AF_U0C0_SCLKOUT	(0x30UL)
#define P0_8_AF_U0C1_SCLKOUT	(0x38UL)
#define P0_9_AF_CCU40_OUT3  	(0x20UL)
#define P0_9_AF_CCU80_OUT21 	(0x28UL)
#define P0_9_AF_U0C0_SELO0  	(0x30UL)
#define P0_9_AF_U0C1_SELO0  	(0x38UL)
#define P0_12_AF_CCU80_OUT33	(0x28UL)
#define P0_12_AF_U0C0_SELO3 	(0x30UL)
#define P0_12_AF_CCU80_OUT20	(0x38UL)
#define P0_13_AF_WDT_REQUEST	(0x8UL)
#define P0_13_AF_CCU80_OUT32	(0x28UL)
#define P0_13_AF_U0C0_SELO4 	(0x30UL)
#define P0_13_AF_CCU80_OUT21	(0x38UL)
#define P0_14_AF_CCU80_OUT31	(0x28UL)
#define P0_14_AF_U0C0_DOUT0 	(0x30UL)
#define P0_14_AF_U0C0_SCLKOUT	(0x38UL)
#define P0_15_AF_CCU80_OUT30	(0x28UL)
#define P0_15_AF_U0C0_DOUT0 	(0x30UL)
#define P0_15_AF_U0C1_MCLKOUT	(0x38UL)
#define P1_0_AF_CCU40_OUT0  	(0x10UL)
#define P1_0_AF_CCU80_OUT00 	(0x28UL)
#define P1_0_AF_ACMP1_OUT   	(0x30UL)
#define P1_0_AF_U0C0_DOUT0  	(0x38UL)
#define P1_1_AF_VADC_EMUX0_IN	(0x8UL)
#define P1_1_AF_CCU40_OUT1  	(0x10UL)
#define P1_1_AF_CCU80_OUT01 	(0x28UL)
#define P1_1_AF_U0C0_DOUT0  	(0x30UL)
#define P1_1_AF_U0C1_SELO0  	(0x38UL)
#define P1_2_AF_VADC_EMUX1_IN	(0x8UL)
#define P1_2_AF_CCU40_OUT2  	(0x10UL)
#define P1_2_AF_CCU80_OUT10 	(0x28UL)
#define P1_2_AF_ACMP2_OUT   	(0x30UL)
#define P1_2_AF_U0C1_DOUT0  	(0x38UL)
#define P1_3_AF_VADC_EMUX2_IN	(0x8UL)
#define P1_3_AF_CCU40_OUT3  	(0x10UL)
#define P1_3_AF_CCU80_OUT11 	(0x28UL)
#define P1_3_AF_U0C1_SCLKOUT	(0x30UL)
#define P1_3_AF_U0C1_DOUT0  	(0x38UL)
#define P2_0_AF_ERU0_PDOUT3 	(0x8UL)
#define P2_0_AF_CCU40_OUT0  	(0x10UL)
#define P2_0_AF_ERU0_GOUT3  	(0x18UL)
#define P2_0_AF_CCU80_OUT20 	(0x28UL)
#define P2_0_AF_U0C0_DOUT0  	(0x30UL)
#define P2_0_AF_U0C0_SCLKOUT	(0x38UL)
#define P2_1_AF_ERU0_PDOUT2 	(0x8UL)
#define P2_1_AF_CCU40_OUT1  	(0x10UL)
#define P2_1_AF_ERU0_GOUT2  	(0x18UL)
#define P2_1_AF_CCU80_OUT21 	(0x28UL)
#define P2_1_AF_U0C0_DOUT0  	(0x30UL)
#define P2_1_AF_U0C1_SCLKOUT	(0x38UL)
#define P2_10_AF_ERU0_PDOUT1	(0x8UL)
#define P2_10_AF_CCU40_OUT2 	(0x10UL)
#define P2_10_AF_ERU0_GOUT1 	(0x18UL)
#define P2_10_AF_CCU80_OUT30	(0x28UL)
#define P2_10_AF_ACMP0_OUT  	(0x30UL)
#define P2_10_AF_U0C1_DOUT0 	(0x38UL)
#define P2_11_AF_ERU0_PDOUT0	(0x8UL)
#define P2_11_AF_CCU40_OUT3 	(0x10UL)
#define P2_11_AF_ERU0_GOUT0 	(0x18UL)
#define P2_11_AF_CCU80_OUT31	(0x28UL)
#define P2_11_AF_U0C1_SCLKOUT	(0x30UL)
#define P2_11_AF_U0C1_DOUT0 	(0x38UL)
#endif


#if (UC_DEVICE == XMC1301) && (UC_PACKAGE == VQFN40)
#define P0_0	XMC_GPIO_PORT0, 0
#define P0_1	XMC_GPIO_PORT0, 1
#define P0_2	XMC_GPIO_PORT0, 2
#define P0_3	XMC_GPIO_PORT0, 3
#define P0_4	XMC_GPIO_PORT0, 4
#define P0_5	XMC_GPIO_PORT0, 5
#define P0_6	XMC_GPIO_PORT0, 6
#define P0_7	XMC_GPIO_PORT0, 7
#define P0_8	XMC_GPIO_PORT0, 8
#define P0_9	XMC_GPIO_PORT0, 9
#define P0_10	XMC_GPIO_PORT0, 10
#define P0_11	XMC_GPIO_PORT0, 11
#define P0_12	XMC_GPIO_PORT0, 12
#define P0_13	XMC_GPIO_PORT0, 13
#define P0_14	XMC_GPIO_PORT0, 14
#define P0_15	XMC_GPIO_PORT0, 15
#define P1_0	XMC_GPIO_PORT1, 0
#define P1_1	XMC_GPIO_PORT1, 1
#define P1_2	XMC_GPIO_PORT1, 2
#define P1_3	XMC_GPIO_PORT1, 3
#define P1_4	XMC_GPIO_PORT1, 4
#define P1_5	XMC_GPIO_PORT1, 5
#define P1_6	XMC_GPIO_PORT1, 6
#define P2_0	XMC_GPIO_PORT2, 0
#define P2_1	XMC_GPIO_PORT2, 1
#define P2_2	XMC_GPIO_PORT2, 2
#define P2_3	XMC_GPIO_PORT2, 3
#define P2_4	XMC_GPIO_PORT2, 4
#define P2_5	XMC_GPIO_PORT2, 5
#define P2_6	XMC_GPIO_PORT2, 6
#define P2_7	XMC_GPIO_PORT2, 7
#define P2_8	XMC_GPIO_PORT2, 8
#define P2_9	XMC_GPIO_PORT2, 9
#define P2_10	XMC_GPIO_PORT2, 10
#define P2_11	XMC_GPIO_PORT2, 11


/* Alternate Output Function */
#define P0_0_AF_ERU0_PDOUT0 	(0x8UL)
#define P0_0_AF_ERU0_GOUT0  	(0x18UL)
#define P0_0_AF_CCU40_OUT0  	(0x20UL)
#define P0_0_AF_CCU80_OUT00 	(0x28UL)
#define P0_0_AF_U0C0_SELO0  	(0x30UL)
#define P0_0_AF_U0C1_SELO0  	(0x38UL)
#define P0_1_AF_ERU0_PDOUT1 	(0x8UL)
#define P0_1_AF_ERU0_GOUT1  	(0x18UL)
#define P0_1_AF_CCU40_OUT1  	(0x20UL)
#define P0_1_AF_CCU80_OUT01 	(0x28UL)
#define P0_1_AF_SCU_VDROP   	(0x38UL)
#define P0_2_AF_ERU0_PDOUT2 	(0x8UL)
#define P0_2_AF_ERU0_GOUT2  	(0x18UL)
#define P0_2_AF_CCU40_OUT2  	(0x20UL)
#define P0_2_AF_CCU80_OUT02 	(0x28UL)
#define P0_2_AF_VADC_EMUX2_IN	(0x30UL)
#define P0_2_AF_CCU80_OUT10 	(0x38UL)
#define P0_3_AF_ERU0_PDOUT3 	(0x8UL)
#define P0_3_AF_ERU0_GOUT3  	(0x18UL)
#define P0_3_AF_CCU40_OUT3  	(0x20UL)
#define P0_3_AF_CCU80_OUT03 	(0x28UL)
#define P0_3_AF_VADC_EMUX1_IN	(0x30UL)
#define P0_3_AF_CCU80_OUT11 	(0x38UL)
#define P0_4_AF_CCU40_OUT1  	(0x20UL)
#define P0_4_AF_CCU80_OUT13 	(0x28UL)
#define P0_4_AF_VADC_EMUX0_IN	(0x30UL)
#define P0_4_AF_WDT_REQUEST 	(0x38UL)
#define P0_5_AF_CCU40_OUT0  	(0x20UL)
#define P0_5_AF_CCU80_OUT12 	(0x28UL)
#define P0_5_AF_ACMP2_OUT   	(0x30UL)
#define P0_5_AF_CCU80_OUT01 	(0x38UL)
#define P0_6_AF_CCU40_OUT0  	(0x20UL)
#define P0_6_AF_CCU80_OUT11 	(0x28UL)
#define P0_6_AF_U0C1_MCLKOUT	(0x30UL)
#define P0_6_AF_U0C1_DOUT0  	(0x38UL)
#define P0_7_AF_CCU40_OUT1  	(0x20UL)
#define P0_7_AF_CCU80_OUT10 	(0x28UL)
#define P0_7_AF_U0C0_SCLKOUT	(0x30UL)
#define P0_7_AF_U0C1_DOUT0  	(0x38UL)
#define P0_8_AF_CCU40_OUT2  	(0x20UL)
#define P0_8_AF_CCU80_OUT20 	(0x28UL)
#define P0_8_AF_U0C0_SCLKOUT	(0x30UL)
#define P0_8_AF_U0C1_SCLKOUT	(0x38UL)
#define P0_9_AF_CCU40_OUT3  	(0x20UL)
#define P0_9_AF_CCU80_OUT21 	(0x28UL)
#define P0_9_AF_U0C0_SELO0  	(0x30UL)
#define P0_9_AF_U0C1_SELO0  	(0x38UL)
#define P0_10_AF_ACMP0_OUT  	(0x20UL)
#define P0_10_AF_CCU80_OUT22	(0x28UL)
#define P0_10_AF_U0C0_SELO1 	(0x30UL)
#define P0_10_AF_U0C1_SELO1 	(0x38UL)
#define P0_11_AF_U0C0_MCLKOUT	(0x20UL)
#define P0_11_AF_CCU80_OUT23	(0x28UL)
#define P0_11_AF_U0C0_SELO2 	(0x30UL)
#define P0_11_AF_U0C1_SELO2 	(0x38UL)
#define P0_12_AF_CCU80_OUT33	(0x28UL)
#define P0_12_AF_U0C0_SELO3 	(0x30UL)
#define P0_12_AF_CCU80_OUT20	(0x38UL)
#define P0_13_AF_WDT_REQUEST	(0x8UL)
#define P0_13_AF_CCU80_OUT32	(0x28UL)
#define P0_13_AF_U0C0_SELO4 	(0x30UL)
#define P0_13_AF_CCU80_OUT21	(0x38UL)
#define P0_14_AF_CCU80_OUT31	(0x28UL)
#define P0_14_AF_U0C0_DOUT0 	(0x30UL)
#define P0_14_AF_U0C0_SCLKOUT	(0x38UL)
#define P0_15_AF_CCU80_OUT30	(0x28UL)
#define P0_15_AF_U0C0_DOUT0 	(0x30UL)
#define P0_15_AF_U0C1_MCLKOUT	(0x38UL)
#define P1_0_AF_CCU40_OUT0  	(0x10UL)
#define P1_0_AF_CCU80_OUT00 	(0x28UL)
#define P1_0_AF_ACMP1_OUT   	(0x30UL)
#define P1_0_AF_U0C0_DOUT0  	(0x38UL)
#define P1_1_AF_VADC_EMUX0_IN	(0x8UL)
#define P1_1_AF_CCU40_OUT1  	(0x10UL)
#define P1_1_AF_CCU80_OUT01 	(0x28UL)
#define P1_1_AF_U0C0_DOUT0  	(0x30UL)
#define P1_1_AF_U0C1_SELO0  	(0x38UL)
#define P1_2_AF_VADC_EMUX1_IN	(0x8UL)
#define P1_2_AF_CCU40_OUT2  	(0x10UL)
#define P1_2_AF_CCU80_OUT10 	(0x28UL)
#define P1_2_AF_ACMP2_OUT   	(0x30UL)
#define P1_2_AF_U0C1_DOUT0  	(0x38UL)
#define P1_3_AF_VADC_EMUX2_IN	(0x8UL)
#define P1_3_AF_CCU40_OUT3  	(0x10UL)
#define P1_3_AF_CCU80_OUT11 	(0x28UL)
#define P1_3_AF_U0C1_SCLKOUT	(0x30UL)
#define P1_3_AF_U0C1_DOUT0  	(0x38UL)
#define P1_4_AF_VADC_EMUX0_IN	(0x8UL)
#define P1_4_AF_U0C1_SCLKOUT	(0x10UL)
#define P1_4_AF_CCU80_OUT20 	(0x28UL)
#define P1_4_AF_U0C0_SELO0  	(0x30UL)
#define P1_4_AF_U0C1_SELO1  	(0x38UL)
#define P1_5_AF_VADC_EMUX1_IN	(0x8UL)
#define P1_5_AF_U0C0_DOUT0  	(0x10UL)
#define P1_5_AF_CCU80_OUT21 	(0x28UL)
#define P1_5_AF_U0C0_SELO1  	(0x30UL)
#define P1_5_AF_U0C1_SELO2  	(0x38UL)
#define P1_6_AF_VADC_EMUX2_IN	(0x8UL)
#define P1_6_AF_U0C1_DOUT0  	(0x10UL)
#define P1_6_AF_U0C0_SCLKOUT	(0x20UL)
#define P1_6_AF_U0C0_SELO2  	(0x30UL)
#define P1_6_AF_U0C1_SELO3  	(0x38UL)
#define P2_0_AF_ERU0_PDOUT3 	(0x8UL)
#define P2_0_AF_CCU40_OUT0  	(0x10UL)
#define P2_0_AF_ERU0_GOUT3  	(0x18UL)
#define P2_0_AF_CCU80_OUT20 	(0x28UL)
#define P2_0_AF_U0C0_DOUT0  	(0x30UL)
#define P2_0_AF_U0C0_SCLKOUT	(0x38UL)
#define P2_1_AF_ERU0_PDOUT2 	(0x8UL)
#define P2_1_AF_CCU40_OUT1  	(0x10UL)
#define P2_1_AF_ERU0_GOUT2  	(0x18UL)
#define P2_1_AF_CCU80_OUT21 	(0x28UL)
#define P2_1_AF_U0C0_DOUT0  	(0x30UL)
#define P2_1_AF_U0C1_SCLKOUT	(0x38UL)
#define P2_10_AF_ERU0_PDOUT1	(0x8UL)
#define P2_10_AF_CCU40_OUT2 	(0x10UL)
#define P2_10_AF_ERU0_GOUT1 	(0x18UL)
#define P2_10_AF_CCU80_OUT30	(0x28UL)
#define P2_10_AF_ACMP0_OUT  	(0x30UL)
#define P2_10_AF_U0C1_DOUT0 	(0x38UL)
#define P2_11_AF_ERU0_PDOUT0	(0x8UL)
#define P2_11_AF_CCU40_OUT3 	(0x10UL)
#define P2_11_AF_ERU0_GOUT0 	(0x18UL)
#define P2_11_AF_CCU80_OUT31	(0x28UL)
#define P2_11_AF_U0C1_SCLKOUT	(0x30UL)
#define P2_11_AF_U0C1_DOUT0 	(0x38UL)
#endif


#if (UC_DEVICE == XMC1301) && (UC_PACKAGE == TSSOP16)
#define P0_0	XMC_GPIO_PORT0, 0
#define P0_1	XMC_GPIO_PORT0, 1
#define P0_2	XMC_GPIO_PORT0, 2
#define P0_3	XMC_GPIO_PORT0, 3
#define P0_5	XMC_GPIO_PORT0, 5
#define P0_6	XMC_GPIO_PORT0, 6
#define P0_7	XMC_GPIO_PORT0, 7
#define P0_8	XMC_GPIO_PORT0, 8
#define P0_9	XMC_GPIO_PORT0, 9
#define P0_14	XMC_GPIO_PORT0, 14
#define P0_15	XMC_GPIO_PORT0, 15
#define P2_0	XMC_GPIO_PORT2, 0
#define P2_6	XMC_GPIO_PORT2, 6
#define P2_7	XMC_GPIO_PORT2, 7
#define P2_8	XMC_GPIO_PORT2, 8
#define P2_9	XMC_GPIO_PORT2, 9
#define P2_10	XMC_GPIO_PORT2, 10
#define P2_11	XMC_GPIO_PORT2, 11


/* Alternate Output Function */
#define P0_0_AF_ERU0_PDOUT0 	(0x8UL)
#define P0_0_AF_ERU0_GOUT0  	(0x18UL)
#define P0_0_AF_CCU40_OUT0  	(0x20UL)
#define P0_0_AF_CCU80_OUT00 	(0x28UL)
#define P0_0_AF_U0C0_SELO0  	(0x30UL)
#define P0_0_AF_U0C1_SELO0  	(0x38UL)
#define P0_2_AF_CCU80_OUT10 	(0x38UL)
#define P0_5_AF_CCU40_OUT0  	(0x20UL)
#define P0_5_AF_CCU80_OUT12 	(0x28UL)
#define P0_5_AF_CCU80_OUT01 	(0x38UL)
#define P0_6_AF_CCU40_OUT0  	(0x20UL)
#define P0_6_AF_CCU80_OUT11 	(0x28UL)
#define P0_6_AF_U0C1_MCLKOUT	(0x30UL)
#define P0_6_AF_U0C1_DOUT0  	(0x38UL)
#define P0_7_AF_CCU40_OUT1  	(0x20UL)
#define P0_7_AF_CCU80_OUT10 	(0x28UL)
#define P0_7_AF_U0C0_SCLKOUT	(0x30UL)
#define P0_7_AF_U0C1_DOUT0  	(0x38UL)
#define P0_8_AF_CCU40_OUT2  	(0x20UL)
#define P0_8_AF_CCU80_OUT20 	(0x28UL)
#define P0_8_AF_U0C0_SCLKOUT	(0x30UL)
#define P0_8_AF_U0C1_SCLKOUT	(0x38UL)
#define P0_9_AF_CCU40_OUT3  	(0x20UL)
#define P0_9_AF_CCU80_OUT21 	(0x28UL)
#define P0_9_AF_U0C0_SELO0  	(0x30UL)
#define P0_9_AF_U0C1_SELO0  	(0x38UL)
#define P0_14_AF_CCU80_OUT31	(0x28UL)
#define P0_14_AF_U0C0_DOUT0 	(0x30UL)
#define P0_14_AF_U0C0_SCLKOUT	(0x38UL)
#define P0_15_AF_CCU80_OUT30	(0x28UL)
#define P0_15_AF_U0C0_DOUT0 	(0x30UL)
#define P0_15_AF_U0C1_MCLKOUT	(0x38UL)
#define P2_0_AF_ERU0_PDOUT3 	(0x8UL)
#define P2_0_AF_CCU40_OUT0  	(0x10UL)
#define P2_0_AF_ERU0_GOUT3  	(0x18UL)
#define P2_0_AF_CCU80_OUT20 	(0x28UL)
#define P2_0_AF_U0C0_DOUT0  	(0x30UL)
#define P2_0_AF_U0C0_SCLKOUT	(0x38UL)
#define P2_10_AF_ERU0_PDOUT1	(0x8UL)
#define P2_10_AF_CCU40_OUT2 	(0x10UL)
#define P2_10_AF_ERU0_GOUT1 	(0x18UL)
#define P2_10_AF_CCU80_OUT30	(0x28UL)
#define P2_10_AF_ACMP0_OUT  	(0x30UL)
#define P2_10_AF_U0C1_DOUT0 	(0x38UL)
#define P2_11_AF_ERU0_PDOUT0	(0x8UL)
#define P2_11_AF_CCU40_OUT3 	(0x10UL)
#define P2_11_AF_ERU0_GOUT0 	(0x18UL)
#define P2_11_AF_CCU80_OUT31	(0x28UL)
#define P2_11_AF_U0C1_SCLKOUT	(0x30UL)
#define P2_11_AF_U0C1_DOUT0 	(0x38UL)
#endif


#if (UC_DEVICE == XMC1301) && (UC_PACKAGE == TSSOP38)
#define P0_0	XMC_GPIO_PORT0, 0
#define P0_1	XMC_GPIO_PORT0, 1
#define P0_2	XMC_GPIO_PORT0, 2
#define P0_3	XMC_GPIO_PORT0, 3
#define P0_4	XMC_GPIO_PORT0, 4
#define P0_5	XMC_GPIO_PORT0, 5
#define P0_6	XMC_GPIO_PORT0, 6
#define P0_7	XMC_GPIO_PORT0, 7
#define P0_8	XMC_GPIO_PORT0, 8
#define P0_9	XMC_GPIO_PORT0, 9
#define P0_10	XMC_GPIO_PORT0, 10
#define P0_11	XMC_GPIO_PORT0, 11
#define P0_12	XMC_GPIO_PORT0, 12
#define P0_13	XMC_GPIO_PORT0, 13
#define P0_14	XMC_GPIO_PORT0, 14
#define P0_15	XMC_GPIO_PORT0, 15
#define P1_0	XMC_GPIO_PORT1, 0
#define P1_1	XMC_GPIO_PORT1, 1
#define P1_2	XMC_GPIO_PORT1, 2
#define P1_3	XMC_GPIO_PORT1, 3
#define P1_4	XMC_GPIO_PORT1, 4
#define P1_5	XMC_GPIO_PORT1, 5
#define P2_0	XMC_GPIO_PORT2, 0
#define P2_1	XMC_GPIO_PORT2, 1
#define P2_2	XMC_GPIO_PORT2, 2
#define P2_3	XMC_GPIO_PORT2, 3
#define P2_4	XMC_GPIO_PORT2, 4
#define P2_5	XMC_GPIO_PORT2, 5
#define P2_6	XMC_GPIO_PORT2, 6
#define P2_7	XMC_GPIO_PORT2, 7
#define P2_8	XMC_GPIO_PORT2, 8
#define P2_9	XMC_GPIO_PORT2, 9
#define P2_10	XMC_GPIO_PORT2, 10
#define P2_11	XMC_GPIO_PORT2, 11


/* Alternate Output Function */
#define P0_0_AF_ERU0_PDOUT0 	(0x8UL)
#define P0_0_AF_ERU0_GOUT0  	(0x18UL)
#define P0_0_AF_CCU40_OUT0  	(0x20UL)
#define P0_0_AF_CCU80_OUT00 	(0x28UL)
#define P0_0_AF_U0C0_SELO0  	(0x30UL)
#define P0_0_AF_U0C1_SELO0  	(0x38UL)
#define P0_1_AF_ERU0_PDOUT1 	(0x8UL)
#define P0_1_AF_ERU0_GOUT1  	(0x18UL)
#define P0_1_AF_CCU40_OUT1  	(0x20UL)
#define P0_1_AF_CCU80_OUT01 	(0x28UL)
#define P0_1_AF_SCU_VDROP   	(0x38UL)
#define P0_2_AF_ERU0_PDOUT2 	(0x8UL)
#define P0_2_AF_ERU0_GOUT2  	(0x18UL)
#define P0_2_AF_CCU40_OUT2  	(0x20UL)
#define P0_2_AF_CCU80_OUT02 	(0x28UL)
#define P0_2_AF_VADC_EMUX2_IN	(0x30UL)
#define P0_2_AF_CCU80_OUT10 	(0x38UL)
#define P0_3_AF_ERU0_PDOUT3 	(0x8UL)
#define P0_3_AF_ERU0_GOUT3  	(0x18UL)
#define P0_3_AF_CCU40_OUT3  	(0x20UL)
#define P0_3_AF_CCU80_OUT03 	(0x28UL)
#define P0_3_AF_VADC_EMUX1_IN	(0x30UL)
#define P0_3_AF_CCU80_OUT11 	(0x38UL)
#define P0_4_AF_CCU40_OUT1  	(0x20UL)
#define P0_4_AF_CCU80_OUT13 	(0x28UL)
#define P0_4_AF_VADC_EMUX0_IN	(0x30UL)
#define P0_4_AF_WDT_REQUEST 	(0x38UL)
#define P0_5_AF_CCU40_OUT0  	(0x20UL)
#define P0_5_AF_CCU80_OUT12 	(0x28UL)
#define P0_5_AF_ACMP2_OUT   	(0x30UL)
#define P0_5_AF_CCU80_OUT01 	(0x38UL)
#define P0_6_AF_CCU40_OUT0  	(0x20UL)
#define P0_6_AF_CCU80_OUT11 	(0x28UL)
#define P0_6_AF_U0C1_MCLKOUT	(0x30UL)
#define P0_6_AF_U0C1_DOUT0  	(0x38UL)
#define P0_7_AF_CCU40_OUT1  	(0x20UL)
#define P0_7_AF_CCU80_OUT10 	(0x28UL)
#define P0_7_AF_U0C0_SCLKOUT	(0x30UL)
#define P0_7_AF_U0C1_DOUT0  	(0x38UL)
#define P0_8_AF_CCU40_OUT2  	(0x20UL)
#define P0_8_AF_CCU80_OUT20 	(0x28UL)
#define P0_8_AF_U0C0_SCLKOUT	(0x30UL)
#define P0_8_AF_U0C1_SCLKOUT	(0x38UL)
#define P0_9_AF_CCU40_OUT3  	(0x20UL)
#define P0_9_AF_CCU80_OUT21 	(0x28UL)
#define P0_9_AF_U0C0_SELO0  	(0x30UL)
#define P0_9_AF_U0C1_SELO0  	(0x38UL)
#define P0_10_AF_ACMP0_OUT  	(0x20UL)
#define P0_10_AF_CCU80_OUT22	(0x28UL)
#define P0_10_AF_U0C0_SELO1 	(0x30UL)
#define P0_10_AF_U0C1_SELO1 	(0x38UL)
#define P0_11_AF_U0C0_MCLKOUT	(0x20UL)
#define P0_11_AF_CCU80_OUT23	(0x28UL)
#define P0_11_AF_U0C0_SELO2 	(0x30UL)
#define P0_11_AF_U0C1_SELO2 	(0x38UL)
#define P0_12_AF_CCU80_OUT33	(0x28UL)
#define P0_12_AF_U0C0_SELO3 	(0x30UL)
#define P0_12_AF_CCU80_OUT20	(0x38UL)
#define P0_13_AF_WDT_REQUEST	(0x8UL)
#define P0_13_AF_CCU80_OUT32	(0x28UL)
#define P0_13_AF_U0C0_SELO4 	(0x30UL)
#define P0_13_AF_CCU80_OUT21	(0x38UL)
#define P0_14_AF_CCU80_OUT31	(0x28UL)
#define P0_14_AF_U0C0_DOUT0 	(0x30UL)
#define P0_14_AF_U0C0_SCLKOUT	(0x38UL)
#define P0_15_AF_CCU80_OUT30	(0x28UL)
#define P0_15_AF_U0C0_DOUT0 	(0x30UL)
#define P0_15_AF_U0C1_MCLKOUT	(0x38UL)
#define P1_0_AF_CCU40_OUT0  	(0x10UL)
#define P1_0_AF_CCU80_OUT00 	(0x28UL)
#define P1_0_AF_ACMP1_OUT   	(0x30UL)
#define P1_0_AF_U0C0_DOUT0  	(0x38UL)
#define P1_1_AF_VADC_EMUX0_IN	(0x8UL)
#define P1_1_AF_CCU40_OUT1  	(0x10UL)
#define P1_1_AF_CCU80_OUT01 	(0x28UL)
#define P1_1_AF_U0C0_DOUT0  	(0x30UL)
#define P1_1_AF_U0C1_SELO0  	(0x38UL)
#define P1_2_AF_VADC_EMUX1_IN	(0x8UL)
#define P1_2_AF_CCU40_OUT2  	(0x10UL)
#define P1_2_AF_CCU80_OUT10 	(0x28UL)
#define P1_2_AF_ACMP2_OUT   	(0x30UL)
#define P1_2_AF_U0C1_DOUT0  	(0x38UL)
#define P1_3_AF_VADC_EMUX2_IN	(0x8UL)
#define P1_3_AF_CCU40_OUT3  	(0x10UL)
#define P1_3_AF_CCU80_OUT11 	(0x28UL)
#define P1_3_AF_U0C1_SCLKOUT	(0x30UL)
#define P1_3_AF_U0C1_DOUT0  	(0x38UL)
#define P1_4_AF_VADC_EMUX0_IN	(0x8UL)
#define P1_4_AF_U0C1_SCLKOUT	(0x10UL)
#define P1_4_AF_CCU80_OUT20 	(0x28UL)
#define P1_4_AF_U0C0_SELO0  	(0x30UL)
#define P1_4_AF_U0C1_SELO1  	(0x38UL)
#define P1_5_AF_VADC_EMUX1_IN	(0x8UL)
#define P1_5_AF_U0C0_DOUT0  	(0x10UL)
#define P1_5_AF_CCU80_OUT21 	(0x28UL)
#define P1_5_AF_U0C0_SELO1  	(0x30UL)
#define P1_5_AF_U0C1_SELO2  	(0x38UL)
#define P2_0_AF_ERU0_PDOUT3 	(0x8UL)
#define P2_0_AF_CCU40_OUT0  	(0x10UL)
#define P2_0_AF_ERU0_GOUT3  	(0x18UL)
#define P2_0_AF_CCU80_OUT20 	(0x28UL)
#define P2_0_AF_U0C0_DOUT0  	(0x30UL)
#define P2_0_AF_U0C0_SCLKOUT	(0x38UL)
#define P2_1_AF_ERU0_PDOUT2 	(0x8UL)
#define P2_1_AF_CCU40_OUT1  	(0x10UL)
#define P2_1_AF_ERU0_GOUT2  	(0x18UL)
#define P2_1_AF_CCU80_OUT21 	(0x28UL)
#define P2_1_AF_U0C0_DOUT0  	(0x30UL)
#define P2_1_AF_U0C1_SCLKOUT	(0x38UL)
#define P2_10_AF_ERU0_PDOUT1	(0x8UL)
#define P2_10_AF_CCU40_OUT2 	(0x10UL)
#define P2_10_AF_ERU0_GOUT1 	(0x18UL)
#define P2_10_AF_CCU80_OUT30	(0x28UL)
#define P2_10_AF_ACMP0_OUT  	(0x30UL)
#define P2_10_AF_U0C1_DOUT0 	(0x38UL)
#define P2_11_AF_ERU0_PDOUT0	(0x8UL)
#define P2_11_AF_CCU40_OUT3 	(0x10UL)
#define P2_11_AF_ERU0_GOUT0 	(0x18UL)
#define P2_11_AF_CCU80_OUT31	(0x28UL)
#define P2_11_AF_U0C1_SCLKOUT	(0x30UL)
#define P2_11_AF_U0C1_DOUT0 	(0x38UL)
#endif


#if (UC_DEVICE == XMC1302) && (UC_PACKAGE == VQFN24)
#define P0_0	XMC_GPIO_PORT0, 0
#define P0_1	XMC_GPIO_PORT0, 1
#define P0_2	XMC_GPIO_PORT0, 2
#define P0_3	XMC_GPIO_PORT0, 3
#define P0_5	XMC_GPIO_PORT0, 5
#define P0_6	XMC_GPIO_PORT0, 6
#define P0_7	XMC_GPIO_PORT0, 7
#define P0_8	XMC_GPIO_PORT0, 8
#define P0_9	XMC_GPIO_PORT0, 9
#define P0_12	XMC_GPIO_PORT0, 12
#define P0_13	XMC_GPIO_PORT0, 13
#define P0_14	XMC_GPIO_PORT0, 14
#define P0_15	XMC_GPIO_PORT0, 15
#define P1_0	XMC_GPIO_PORT1, 0
#define P1_1	XMC_GPIO_PORT1, 1
#define P1_2	XMC_GPIO_PORT1, 2
#define P1_3	XMC_GPIO_PORT1, 3
#define P2_0	XMC_GPIO_PORT2, 0
#define P2_1	XMC_GPIO_PORT2, 1
#define P2_2	XMC_GPIO_PORT2, 2
#define P2_6	XMC_GPIO_PORT2, 6
#define P2_7	XMC_GPIO_PORT2, 7
#define P2_8	XMC_GPIO_PORT2, 8
#define P2_9	XMC_GPIO_PORT2, 9
#define P2_10	XMC_GPIO_PORT2, 10
#define P2_11	XMC_GPIO_PORT2, 11


/* Alternate Output Function */
#define P0_0_AF_ERU0_PDOUT0 	(0x8UL)
#define P0_0_AF_ERU0_GOUT0  	(0x18UL)
#define P0_0_AF_CCU40_OUT0  	(0x20UL)
#define P0_0_AF_CCU80_OUT00 	(0x28UL)
#define P0_0_AF_U0C0_SELO0  	(0x30UL)
#define P0_0_AF_U0C1_SELO0  	(0x38UL)
#define P0_5_AF_BCCU0_OUT1  	(0x8UL)
#define P0_5_AF_CCU40_OUT0  	(0x20UL)
#define P0_5_AF_CCU80_OUT12 	(0x28UL)
#define P0_5_AF_ACMP2_OUT   	(0x30UL)
#define P0_5_AF_CCU80_OUT01 	(0x38UL)
#define P0_6_AF_BCCU0_OUT2  	(0x8UL)
#define P0_6_AF_CCU40_OUT0  	(0x20UL)
#define P0_6_AF_CCU80_OUT11 	(0x28UL)
#define P0_6_AF_U0C1_MCLKOUT	(0x30UL)
#define P0_6_AF_U0C1_DOUT0  	(0x38UL)
#define P0_7_AF_BCCU0_OUT3  	(0x8UL)
#define P0_7_AF_CCU40_OUT1  	(0x20UL)
#define P0_7_AF_CCU80_OUT10 	(0x28UL)
#define P0_7_AF_U0C0_SCLKOUT	(0x30UL)
#define P0_7_AF_U0C1_DOUT0  	(0x38UL)
#define P0_8_AF_BCCU0_OUT4  	(0x8UL)
#define P0_8_AF_CCU40_OUT2  	(0x20UL)
#define P0_8_AF_CCU80_OUT20 	(0x28UL)
#define P0_8_AF_U0C0_SCLKOUT	(0x30UL)
#define P0_8_AF_U0C1_SCLKOUT	(0x38UL)
#define P0_9_AF_BCCU0_OUT5  	(0x8UL)
#define P0_9_AF_CCU40_OUT3  	(0x20UL)
#define P0_9_AF_CCU80_OUT21 	(0x28UL)
#define P0_9_AF_U0C0_SELO0  	(0x30UL)
#define P0_9_AF_U0C1_SELO0  	(0x38UL)
#define P0_12_AF_BCCU0_OUT6 	(0x8UL)
#define P0_12_AF_CCU80_OUT33	(0x28UL)
#define P0_12_AF_U0C0_SELO3 	(0x30UL)
#define P0_12_AF_CCU80_OUT20	(0x38UL)
#define P0_13_AF_WDT_REQUEST	(0x8UL)
#define P0_13_AF_CCU80_OUT32	(0x28UL)
#define P0_13_AF_U0C0_SELO4 	(0x30UL)
#define P0_13_AF_CCU80_OUT21	(0x38UL)
#define P0_14_AF_BCCU0_OUT7 	(0x8UL)
#define P0_14_AF_CCU80_OUT31	(0x28UL)
#define P0_14_AF_U0C0_DOUT0 	(0x30UL)
#define P0_14_AF_U0C0_SCLKOUT	(0x38UL)
#define P0_15_AF_BCCU0_OUT8 	(0x8UL)
#define P0_15_AF_CCU80_OUT30	(0x28UL)
#define P0_15_AF_U0C0_DOUT0 	(0x30UL)
#define P0_15_AF_U0C1_MCLKOUT	(0x38UL)
#define P1_0_AF_BCCU0_OUT0  	(0x8UL)
#define P1_0_AF_CCU40_OUT0  	(0x10UL)
#define P1_0_AF_CCU80_OUT00 	(0x28UL)
#define P1_0_AF_ACMP1_OUT   	(0x30UL)
#define P1_0_AF_U0C0_DOUT0  	(0x38UL)
#define P1_1_AF_VADC_EMUX0_IN	(0x8UL)
#define P1_1_AF_CCU40_OUT1  	(0x10UL)
#define P1_1_AF_CCU80_OUT01 	(0x28UL)
#define P1_1_AF_U0C0_DOUT0  	(0x30UL)
#define P1_1_AF_U0C1_SELO0  	(0x38UL)
#define P1_2_AF_VADC_EMUX1_IN	(0x8UL)
#define P1_2_AF_CCU40_OUT2  	(0x10UL)
#define P1_2_AF_CCU80_OUT10 	(0x28UL)
#define P1_2_AF_ACMP2_OUT   	(0x30UL)
#define P1_2_AF_U0C1_DOUT0  	(0x38UL)
#define P1_3_AF_VADC_EMUX2_IN	(0x8UL)
#define P1_3_AF_CCU40_OUT3  	(0x10UL)
#define P1_3_AF_CCU80_OUT11 	(0x28UL)
#define P1_3_AF_U0C1_SCLKOUT	(0x30UL)
#define P1_3_AF_U0C1_DOUT0  	(0x38UL)
#define P2_0_AF_ERU0_PDOUT3 	(0x8UL)
#define P2_0_AF_CCU40_OUT0  	(0x10UL)
#define P2_0_AF_ERU0_GOUT3  	(0x18UL)
#define P2_0_AF_CCU80_OUT20 	(0x28UL)
#define P2_0_AF_U0C0_DOUT0  	(0x30UL)
#define P2_0_AF_U0C0_SCLKOUT	(0x38UL)
#define P2_1_AF_ERU0_PDOUT2 	(0x8UL)
#define P2_1_AF_CCU40_OUT1  	(0x10UL)
#define P2_1_AF_ERU0_GOUT2  	(0x18UL)
#define P2_1_AF_CCU80_OUT21 	(0x28UL)
#define P2_1_AF_U0C0_DOUT0  	(0x30UL)
#define P2_1_AF_U0C1_SCLKOUT	(0x38UL)
#define P2_10_AF_ERU0_PDOUT1	(0x8UL)
#define P2_10_AF_CCU40_OUT2 	(0x10UL)
#define P2_10_AF_ERU0_GOUT1 	(0x18UL)
#define P2_10_AF_CCU80_OUT30	(0x28UL)
#define P2_10_AF_ACMP0_OUT  	(0x30UL)
#define P2_10_AF_U0C1_DOUT0 	(0x38UL)
#define P2_11_AF_ERU0_PDOUT0	(0x8UL)
#define P2_11_AF_CCU40_OUT3 	(0x10UL)
#define P2_11_AF_ERU0_GOUT0 	(0x18UL)
#define P2_11_AF_CCU80_OUT31	(0x28UL)
#define P2_11_AF_U0C1_SCLKOUT	(0x30UL)
#define P2_11_AF_U0C1_DOUT0 	(0x38UL)
#endif


#if (UC_DEVICE == XMC1302) && (UC_PACKAGE == VQFN40)
#define P0_0	XMC_GPIO_PORT0, 0
#define P0_1	XMC_GPIO_PORT0, 1
#define P0_2	XMC_GPIO_PORT0, 2
#define P0_3	XMC_GPIO_PORT0, 3
#define P0_4	XMC_GPIO_PORT0, 4
#define P0_5	XMC_GPIO_PORT0, 5
#define P0_6	XMC_GPIO_PORT0, 6
#define P0_7	XMC_GPIO_PORT0, 7
#define P0_8	XMC_GPIO_PORT0, 8
#define P0_9	XMC_GPIO_PORT0, 9
#define P0_10	XMC_GPIO_PORT0, 10
#define P0_11	XMC_GPIO_PORT0, 11
#define P0_12	XMC_GPIO_PORT0, 12
#define P0_13	XMC_GPIO_PORT0, 13
#define P0_14	XMC_GPIO_PORT0, 14
#define P0_15	XMC_GPIO_PORT0, 15
#define P1_0	XMC_GPIO_PORT1, 0
#define P1_1	XMC_GPIO_PORT1, 1
#define P1_2	XMC_GPIO_PORT1, 2
#define P1_3	XMC_GPIO_PORT1, 3
#define P1_4	XMC_GPIO_PORT1, 4
#define P1_5	XMC_GPIO_PORT1, 5
#define P1_6	XMC_GPIO_PORT1, 6
#define P2_0	XMC_GPIO_PORT2, 0
#define P2_1	XMC_GPIO_PORT2, 1
#define P2_2	XMC_GPIO_PORT2, 2
#define P2_3	XMC_GPIO_PORT2, 3
#define P2_4	XMC_GPIO_PORT2, 4
#define P2_5	XMC_GPIO_PORT2, 5
#define P2_6	XMC_GPIO_PORT2, 6
#define P2_7	XMC_GPIO_PORT2, 7
#define P2_8	XMC_GPIO_PORT2, 8
#define P2_9	XMC_GPIO_PORT2, 9
#define P2_10	XMC_GPIO_PORT2, 10
#define P2_11	XMC_GPIO_PORT2, 11


/* Alternate Output Function */
#define P0_0_AF_ERU0_PDOUT0 	(0x8UL)
#define P0_0_AF_ERU0_GOUT0  	(0x18UL)
#define P0_0_AF_CCU40_OUT0  	(0x20UL)
#define P0_0_AF_CCU80_OUT00 	(0x28UL)
#define P0_0_AF_U0C0_SELO0  	(0x30UL)
#define P0_0_AF_U0C1_SELO0  	(0x38UL)
#define P0_1_AF_ERU0_PDOUT1 	(0x8UL)
#define P0_1_AF_ERU0_GOUT1  	(0x18UL)
#define P0_1_AF_CCU40_OUT1  	(0x20UL)
#define P0_1_AF_CCU80_OUT01 	(0x28UL)
#define P0_1_AF_BCCU0_OUT8  	(0x30UL)
#define P0_1_AF_SCU_VDROP   	(0x38UL)
#define P0_2_AF_ERU0_PDOUT2 	(0x8UL)
#define P0_2_AF_ERU0_GOUT2  	(0x18UL)
#define P0_2_AF_CCU40_OUT2  	(0x20UL)
#define P0_2_AF_CCU80_OUT02 	(0x28UL)
#define P0_2_AF_VADC_EMUX2_IN	(0x30UL)
#define P0_2_AF_CCU80_OUT10 	(0x38UL)
#define P0_3_AF_ERU0_PDOUT3 	(0x8UL)
#define P0_3_AF_ERU0_GOUT3  	(0x18UL)
#define P0_3_AF_CCU40_OUT3  	(0x20UL)
#define P0_3_AF_CCU80_OUT03 	(0x28UL)
#define P0_3_AF_VADC_EMUX1_IN	(0x30UL)
#define P0_3_AF_CCU80_OUT11 	(0x38UL)
#define P0_4_AF_BCCU0_OUT0  	(0x8UL)
#define P0_4_AF_CCU40_OUT1  	(0x20UL)
#define P0_4_AF_CCU80_OUT13 	(0x28UL)
#define P0_4_AF_VADC_EMUX0_IN	(0x30UL)
#define P0_4_AF_WDT_REQUEST 	(0x38UL)
#define P0_5_AF_BCCU0_OUT1  	(0x8UL)
#define P0_5_AF_CCU40_OUT0  	(0x20UL)
#define P0_5_AF_CCU80_OUT12 	(0x28UL)
#define P0_5_AF_ACMP2_OUT   	(0x30UL)
#define P0_5_AF_CCU80_OUT01 	(0x38UL)
#define P0_6_AF_BCCU0_OUT2  	(0x8UL)
#define P0_6_AF_CCU40_OUT0  	(0x20UL)
#define P0_6_AF_CCU80_OUT11 	(0x28UL)
#define P0_6_AF_U0C1_MCLKOUT	(0x30UL)
#define P0_6_AF_U0C1_DOUT0  	(0x38UL)
#define P0_7_AF_BCCU0_OUT3  	(0x8UL)
#define P0_7_AF_CCU40_OUT1  	(0x20UL)
#define P0_7_AF_CCU80_OUT10 	(0x28UL)
#define P0_7_AF_U0C0_SCLKOUT	(0x30UL)
#define P0_7_AF_U0C1_DOUT0  	(0x38UL)
#define P0_8_AF_BCCU0_OUT4  	(0x8UL)
#define P0_8_AF_CCU40_OUT2  	(0x20UL)
#define P0_8_AF_CCU80_OUT20 	(0x28UL)
#define P0_8_AF_U0C0_SCLKOUT	(0x30UL)
#define P0_8_AF_U0C1_SCLKOUT	(0x38UL)
#define P0_9_AF_BCCU0_OUT5  	(0x8UL)
#define P0_9_AF_CCU40_OUT3  	(0x20UL)
#define P0_9_AF_CCU80_OUT21 	(0x28UL)
#define P0_9_AF_U0C0_SELO0  	(0x30UL)
#define P0_9_AF_U0C1_SELO0  	(0x38UL)
#define P0_10_AF_BCCU0_OUT6 	(0x8UL)
#define P0_10_AF_ACMP0_OUT  	(0x20UL)
#define P0_10_AF_CCU80_OUT22	(0x28UL)
#define P0_10_AF_U0C0_SELO1 	(0x30UL)
#define P0_10_AF_U0C1_SELO1 	(0x38UL)
#define P0_11_AF_BCCU0_OUT7 	(0x8UL)
#define P0_11_AF_U0C0_MCLKOUT	(0x20UL)
#define P0_11_AF_CCU80_OUT23	(0x28UL)
#define P0_11_AF_U0C0_SELO2 	(0x30UL)
#define P0_11_AF_U0C1_SELO2 	(0x38UL)
#define P0_12_AF_BCCU0_OUT6 	(0x8UL)
#define P0_12_AF_CCU80_OUT33	(0x28UL)
#define P0_12_AF_U0C0_SELO3 	(0x30UL)
#define P0_12_AF_CCU80_OUT20	(0x38UL)
#define P0_13_AF_WDT_REQUEST	(0x8UL)
#define P0_13_AF_CCU80_OUT32	(0x28UL)
#define P0_13_AF_U0C0_SELO4 	(0x30UL)
#define P0_13_AF_CCU80_OUT21	(0x38UL)
#define P0_14_AF_BCCU0_OUT7 	(0x8UL)
#define P0_14_AF_CCU80_OUT31	(0x28UL)
#define P0_14_AF_U0C0_DOUT0 	(0x30UL)
#define P0_14_AF_U0C0_SCLKOUT	(0x38UL)
#define P0_15_AF_BCCU0_OUT8 	(0x8UL)
#define P0_15_AF_CCU80_OUT30	(0x28UL)
#define P0_15_AF_U0C0_DOUT0 	(0x30UL)
#define P0_15_AF_U0C1_MCLKOUT	(0x38UL)
#define P1_0_AF_BCCU0_OUT0  	(0x8UL)
#define P1_0_AF_CCU40_OUT0  	(0x10UL)
#define P1_0_AF_CCU80_OUT00 	(0x28UL)
#define P1_0_AF_ACMP1_OUT   	(0x30UL)
#define P1_0_AF_U0C0_DOUT0  	(0x38UL)
#define P1_1_AF_VADC_EMUX0_IN	(0x8UL)
#define P1_1_AF_CCU40_OUT1  	(0x10UL)
#define P1_1_AF_CCU80_OUT01 	(0x28UL)
#define P1_1_AF_U0C0_DOUT0  	(0x30UL)
#define P1_1_AF_U0C1_SELO0  	(0x38UL)
#define P1_2_AF_VADC_EMUX1_IN	(0x8UL)
#define P1_2_AF_CCU40_OUT2  	(0x10UL)
#define P1_2_AF_CCU80_OUT10 	(0x28UL)
#define P1_2_AF_ACMP2_OUT   	(0x30UL)
#define P1_2_AF_U0C1_DOUT0  	(0x38UL)
#define P1_3_AF_VADC_EMUX2_IN	(0x8UL)
#define P1_3_AF_CCU40_OUT3  	(0x10UL)
#define P1_3_AF_CCU80_OUT11 	(0x28UL)
#define P1_3_AF_U0C1_SCLKOUT	(0x30UL)
#define P1_3_AF_U0C1_DOUT0  	(0x38UL)
#define P1_4_AF_VADC_EMUX0_IN	(0x8UL)
#define P1_4_AF_U0C1_SCLKOUT	(0x10UL)
#define P1_4_AF_CCU80_OUT20 	(0x28UL)
#define P1_4_AF_U0C0_SELO0  	(0x30UL)
#define P1_4_AF_U0C1_SELO1  	(0x38UL)
#define P1_5_AF_VADC_EMUX1_IN	(0x8UL)
#define P1_5_AF_U0C0_DOUT0  	(0x10UL)
#define P1_5_AF_BCCU0_OUT1  	(0x20UL)
#define P1_5_AF_CCU80_OUT21 	(0x28UL)
#define P1_5_AF_U0C0_SELO1  	(0x30UL)
#define P1_5_AF_U0C1_SELO2  	(0x38UL)
#define P1_6_AF_VADC_EMUX2_IN	(0x8UL)
#define P1_6_AF_U0C1_DOUT0  	(0x10UL)
#define P1_6_AF_U0C0_SCLKOUT	(0x20UL)
#define P1_6_AF_BCCU0_OUT2  	(0x28UL)
#define P1_6_AF_U0C0_SELO2  	(0x30UL)
#define P1_6_AF_U0C1_SELO3  	(0x38UL)
#define P2_0_AF_ERU0_PDOUT3 	(0x8UL)
#define P2_0_AF_CCU40_OUT0  	(0x10UL)
#define P2_0_AF_ERU0_GOUT3  	(0x18UL)
#define P2_0_AF_CCU80_OUT20 	(0x28UL)
#define P2_0_AF_U0C0_DOUT0  	(0x30UL)
#define P2_0_AF_U0C0_SCLKOUT	(0x38UL)
#define P2_1_AF_ERU0_PDOUT2 	(0x8UL)
#define P2_1_AF_CCU40_OUT1  	(0x10UL)
#define P2_1_AF_ERU0_GOUT2  	(0x18UL)
#define P2_1_AF_CCU80_OUT21 	(0x28UL)
#define P2_1_AF_U0C0_DOUT0  	(0x30UL)
#define P2_1_AF_U0C1_SCLKOUT	(0x38UL)
#define P2_10_AF_ERU0_PDOUT1	(0x8UL)
#define P2_10_AF_CCU40_OUT2 	(0x10UL)
#define P2_10_AF_ERU0_GOUT1 	(0x18UL)
#define P2_10_AF_CCU80_OUT30	(0x28UL)
#define P2_10_AF_ACMP0_OUT  	(0x30UL)
#define P2_10_AF_U0C1_DOUT0 	(0x38UL)
#define P2_11_AF_ERU0_PDOUT0	(0x8UL)
#define P2_11_AF_CCU40_OUT3 	(0x10UL)
#define P2_11_AF_ERU0_GOUT0 	(0x18UL)
#define P2_11_AF_CCU80_OUT31	(0x28UL)
#define P2_11_AF_U0C1_SCLKOUT	(0x30UL)
#define P2_11_AF_U0C1_DOUT0 	(0x38UL)
#endif


#if (UC_DEVICE == XMC1302) && (UC_PACKAGE == TSSOP16)
#define P0_0	XMC_GPIO_PORT0, 0
#define P0_1	XMC_GPIO_PORT0, 1
#define P0_2	XMC_GPIO_PORT0, 2
#define P0_3	XMC_GPIO_PORT0, 3
#define P0_5	XMC_GPIO_PORT0, 5
#define P0_6	XMC_GPIO_PORT0, 6
#define P0_7	XMC_GPIO_PORT0, 7
#define P0_8	XMC_GPIO_PORT0, 8
#define P0_9	XMC_GPIO_PORT0, 9
#define P0_14	XMC_GPIO_PORT0, 14
#define P0_15	XMC_GPIO_PORT0, 15
#define P2_0	XMC_GPIO_PORT2, 0
#define P2_6	XMC_GPIO_PORT2, 6
#define P2_7	XMC_GPIO_PORT2, 7
#define P2_8	XMC_GPIO_PORT2, 8
#define P2_9	XMC_GPIO_PORT2, 9
#define P2_10	XMC_GPIO_PORT2, 10
#define P2_11	XMC_GPIO_PORT2, 11


/* Alternate Output Function */
#define P0_0_AF_ERU0_PDOUT0 	(0x8UL)
#define P0_0_AF_ERU0_GOUT0  	(0x18UL)
#define P0_0_AF_CCU40_OUT0  	(0x20UL)
#define P0_0_AF_CCU80_OUT00 	(0x28UL)
#define P0_0_AF_U0C0_SELO0  	(0x30UL)
#define P0_0_AF_U0C1_SELO0  	(0x38UL)
#define P0_2_AF_CCU80_OUT10 	(0x38UL)
#define P0_5_AF_BCCU0_OUT1  	(0x8UL)
#define P0_5_AF_CCU40_OUT0  	(0x20UL)
#define P0_5_AF_CCU80_OUT12 	(0x28UL)
#define P0_5_AF_ACMP2_OUT   	(0x30UL)
#define P0_5_AF_CCU80_OUT01 	(0x38UL)
#define P0_6_AF_BCCU0_OUT2  	(0x8UL)
#define P0_6_AF_CCU40_OUT0  	(0x20UL)
#define P0_6_AF_CCU80_OUT11 	(0x28UL)
#define P0_6_AF_U0C1_MCLKOUT	(0x30UL)
#define P0_6_AF_U0C1_DOUT0  	(0x38UL)
#define P0_7_AF_BCCU0_OUT3  	(0x8UL)
#define P0_7_AF_CCU40_OUT1  	(0x20UL)
#define P0_7_AF_CCU80_OUT10 	(0x28UL)
#define P0_7_AF_U0C0_SCLKOUT	(0x30UL)
#define P0_7_AF_U0C1_DOUT0  	(0x38UL)
#define P0_8_AF_BCCU0_OUT4  	(0x8UL)
#define P0_8_AF_CCU40_OUT2  	(0x20UL)
#define P0_8_AF_CCU80_OUT20 	(0x28UL)
#define P0_8_AF_U0C0_SCLKOUT	(0x30UL)
#define P0_8_AF_U0C1_SCLKOUT	(0x38UL)
#define P0_9_AF_BCCU0_OUT5  	(0x8UL)
#define P0_9_AF_CCU40_OUT3  	(0x20UL)
#define P0_9_AF_CCU80_OUT21 	(0x28UL)
#define P0_9_AF_U0C0_SELO0  	(0x30UL)
#define P0_9_AF_U0C1_SELO0  	(0x38UL)
#define P0_14_AF_BCCU0_OUT7 	(0x8UL)
#define P0_14_AF_CCU80_OUT31	(0x28UL)
#define P0_14_AF_U0C0_DOUT0 	(0x30UL)
#define P0_14_AF_U0C0_SCLKOUT	(0x38UL)
#define P0_15_AF_BCCU0_OUT8 	(0x8UL)
#define P0_15_AF_CCU80_OUT30	(0x28UL)
#define P0_15_AF_U0C0_DOUT0 	(0x30UL)
#define P0_15_AF_U0C1_MCLKOUT	(0x38UL)
#define P2_0_AF_ERU0_PDOUT3 	(0x8UL)
#define P2_0_AF_CCU40_OUT0  	(0x10UL)
#define P2_0_AF_ERU0_GOUT3  	(0x18UL)
#define P2_0_AF_CCU80_OUT20 	(0x28UL)
#define P2_0_AF_U0C0_DOUT0  	(0x30UL)
#define P2_0_AF_U0C0_SCLKOUT	(0x38UL)
#define P2_10_AF_ERU0_PDOUT1	(0x8UL)
#define P2_10_AF_CCU40_OUT2 	(0x10UL)
#define P2_10_AF_ERU0_GOUT1 	(0x18UL)
#define P2_10_AF_CCU80_OUT30	(0x28UL)
#define P2_10_AF_ACMP0_OUT  	(0x30UL)
#define P2_10_AF_U0C1_DOUT0 	(0x38UL)
#define P2_11_AF_ERU0_PDOUT0	(0x8UL)
#define P2_11_AF_CCU40_OUT3 	(0x10UL)
#define P2_11_AF_ERU0_GOUT0 	(0x18UL)
#define P2_11_AF_CCU80_OUT31	(0x28UL)
#define P2_11_AF_U0C1_SCLKOUT	(0x30UL)
#define P2_11_AF_U0C1_DOUT0 	(0x38UL)
#endif


#if (UC_DEVICE == XMC1302) && (UC_PACKAGE == TSSOP38)
#define P0_0	XMC_GPIO_PORT0, 0
#define P0_1	XMC_GPIO_PORT0, 1
#define P0_2	XMC_GPIO_PORT0, 2
#define P0_3	XMC_GPIO_PORT0, 3
#define P0_4	XMC_GPIO_PORT0, 4
#define P0_5	XMC_GPIO_PORT0, 5
#define P0_6	XMC_GPIO_PORT0, 6
#define P0_7	XMC_GPIO_PORT0, 7
#define P0_8	XMC_GPIO_PORT0, 8
#define P0_9	XMC_GPIO_PORT0, 9
#define P0_10	XMC_GPIO_PORT0, 10
#define P0_11	XMC_GPIO_PORT0, 11
#define P0_12	XMC_GPIO_PORT0, 12
#define P0_13	XMC_GPIO_PORT0, 13
#define P0_14	XMC_GPIO_PORT0, 14
#define P0_15	XMC_GPIO_PORT0, 15
#define P1_0	XMC_GPIO_PORT1, 0
#define P1_1	XMC_GPIO_PORT1, 1
#define P1_2	XMC_GPIO_PORT1, 2
#define P1_3	XMC_GPIO_PORT1, 3
#define P1_4	XMC_GPIO_PORT1, 4
#define P1_5	XMC_GPIO_PORT1, 5
#define P2_0	XMC_GPIO_PORT2, 0
#define P2_1	XMC_GPIO_PORT2, 1
#define P2_2	XMC_GPIO_PORT2, 2
#define P2_3	XMC_GPIO_PORT2, 3
#define P2_4	XMC_GPIO_PORT2, 4
#define P2_5	XMC_GPIO_PORT2, 5
#define P2_6	XMC_GPIO_PORT2, 6
#define P2_7	XMC_GPIO_PORT2, 7
#define P2_8	XMC_GPIO_PORT2, 8
#define P2_9	XMC_GPIO_PORT2, 9
#define P2_10	XMC_GPIO_PORT2, 10
#define P2_11	XMC_GPIO_PORT2, 11


/* Alternate Output Function */
#define P0_0_AF_ERU0_PDOUT0 	(0x8UL)
#define P0_0_AF_ERU0_GOUT0  	(0x18UL)
#define P0_0_AF_CCU40_OUT0  	(0x20UL)
#define P0_0_AF_CCU80_OUT00 	(0x28UL)
#define P0_0_AF_U0C0_SELO0  	(0x30UL)
#define P0_0_AF_U0C1_SELO0  	(0x38UL)
#define P0_1_AF_ERU0_PDOUT1 	(0x8UL)
#define P0_1_AF_ERU0_GOUT1  	(0x18UL)
#define P0_1_AF_CCU40_OUT1  	(0x20UL)
#define P0_1_AF_CCU80_OUT01 	(0x28UL)
#define P0_1_AF_BCCU0_OUT8  	(0x30UL)
#define P0_1_AF_SCU_VDROP   	(0x38UL)
#define P0_2_AF_ERU0_PDOUT2 	(0x8UL)
#define P0_2_AF_ERU0_GOUT2  	(0x18UL)
#define P0_2_AF_CCU40_OUT2  	(0x20UL)
#define P0_2_AF_CCU80_OUT02 	(0x28UL)
#define P0_2_AF_VADC_EMUX2_IN	(0x30UL)
#define P0_2_AF_CCU80_OUT10 	(0x38UL)
#define P0_3_AF_ERU0_PDOUT3 	(0x8UL)
#define P0_3_AF_ERU0_GOUT3  	(0x18UL)
#define P0_3_AF_CCU40_OUT3  	(0x20UL)
#define P0_3_AF_CCU80_OUT03 	(0x28UL)
#define P0_3_AF_VADC_EMUX1_IN	(0x30UL)
#define P0_3_AF_CCU80_OUT11 	(0x38UL)
#define P0_4_AF_BCCU0_OUT0  	(0x8UL)
#define P0_4_AF_CCU40_OUT1  	(0x20UL)
#define P0_4_AF_CCU80_OUT13 	(0x28UL)
#define P0_4_AF_VADC_EMUX0_IN	(0x30UL)
#define P0_4_AF_WDT_REQUEST 	(0x38UL)
#define P0_5_AF_BCCU0_OUT1  	(0x8UL)
#define P0_5_AF_CCU40_OUT0  	(0x20UL)
#define P0_5_AF_CCU80_OUT12 	(0x28UL)
#define P0_5_AF_ACMP2_OUT   	(0x30UL)
#define P0_5_AF_CCU80_OUT01 	(0x38UL)
#define P0_6_AF_BCCU0_OUT2  	(0x8UL)
#define P0_6_AF_CCU40_OUT0  	(0x20UL)
#define P0_6_AF_CCU80_OUT11 	(0x28UL)
#define P0_6_AF_U0C1_MCLKOUT	(0x30UL)
#define P0_6_AF_U0C1_DOUT0  	(0x38UL)
#define P0_7_AF_BCCU0_OUT3  	(0x8UL)
#define P0_7_AF_CCU40_OUT1  	(0x20UL)
#define P0_7_AF_CCU80_OUT10 	(0x28UL)
#define P0_7_AF_U0C0_SCLKOUT	(0x30UL)
#define P0_7_AF_U0C1_DOUT0  	(0x38UL)
#define P0_8_AF_BCCU0_OUT4  	(0x8UL)
#define P0_8_AF_CCU40_OUT2  	(0x20UL)
#define P0_8_AF_CCU80_OUT20 	(0x28UL)
#define P0_8_AF_U0C0_SCLKOUT	(0x30UL)
#define P0_8_AF_U0C1_SCLKOUT	(0x38UL)
#define P0_9_AF_BCCU0_OUT5  	(0x8UL)
#define P0_9_AF_CCU40_OUT3  	(0x20UL)
#define P0_9_AF_CCU80_OUT21 	(0x28UL)
#define P0_9_AF_U0C0_SELO0  	(0x30UL)
#define P0_9_AF_U0C1_SELO0  	(0x38UL)
#define P0_10_AF_BCCU0_OUT6 	(0x8UL)
#define P0_10_AF_ACMP0_OUT  	(0x20UL)
#define P0_10_AF_CCU80_OUT22	(0x28UL)
#define P0_10_AF_U0C0_SELO1 	(0x30UL)
#define P0_10_AF_U0C1_SELO1 	(0x38UL)
#define P0_11_AF_BCCU0_OUT7 	(0x8UL)
#define P0_11_AF_U0C0_MCLKOUT	(0x20UL)
#define P0_11_AF_CCU80_OUT23	(0x28UL)
#define P0_11_AF_U0C0_SELO2 	(0x30UL)
#define P0_11_AF_U0C1_SELO2 	(0x38UL)
#define P0_12_AF_BCCU0_OUT6 	(0x8UL)
#define P0_12_AF_CCU80_OUT33	(0x28UL)
#define P0_12_AF_U0C0_SELO3 	(0x30UL)
#define P0_12_AF_CCU80_OUT20	(0x38UL)
#define P0_13_AF_WDT_REQUEST	(0x8UL)
#define P0_13_AF_CCU80_OUT32	(0x28UL)
#define P0_13_AF_U0C0_SELO4 	(0x30UL)
#define P0_13_AF_CCU80_OUT21	(0x38UL)
#define P0_14_AF_BCCU0_OUT7 	(0x8UL)
#define P0_14_AF_CCU80_OUT31	(0x28UL)
#define P0_14_AF_U0C0_DOUT0 	(0x30UL)
#define P0_14_AF_U0C0_SCLKOUT	(0x38UL)
#define P0_15_AF_BCCU0_OUT8 	(0x8UL)
#define P0_15_AF_CCU80_OUT30	(0x28UL)
#define P0_15_AF_U0C0_DOUT0 	(0x30UL)
#define P0_15_AF_U0C1_MCLKOUT	(0x38UL)
#define P1_0_AF_BCCU0_OUT0  	(0x8UL)
#define P1_0_AF_CCU40_OUT0  	(0x10UL)
#define P1_0_AF_CCU80_OUT00 	(0x28UL)
#define P1_0_AF_ACMP1_OUT   	(0x30UL)
#define P1_0_AF_U0C0_DOUT0  	(0x38UL)
#define P1_1_AF_VADC_EMUX0_IN	(0x8UL)
#define P1_1_AF_CCU40_OUT1  	(0x10UL)
#define P1_1_AF_CCU80_OUT01 	(0x28UL)
#define P1_1_AF_U0C0_DOUT0  	(0x30UL)
#define P1_1_AF_U0C1_SELO0  	(0x38UL)
#define P1_2_AF_VADC_EMUX1_IN	(0x8UL)
#define P1_2_AF_CCU40_OUT2  	(0x10UL)
#define P1_2_AF_CCU80_OUT10 	(0x28UL)
#define P1_2_AF_ACMP2_OUT   	(0x30UL)
#define P1_2_AF_U0C1_DOUT0  	(0x38UL)
#define P1_3_AF_VADC_EMUX2_IN	(0x8UL)
#define P1_3_AF_CCU40_OUT3  	(0x10UL)
#define P1_3_AF_CCU80_OUT11 	(0x28UL)
#define P1_3_AF_U0C1_SCLKOUT	(0x30UL)
#define P1_3_AF_U0C1_DOUT0  	(0x38UL)
#define P1_4_AF_VADC_EMUX0_IN	(0x8UL)
#define P1_4_AF_U0C1_SCLKOUT	(0x10UL)
#define P1_4_AF_CCU80_OUT20 	(0x28UL)
#define P1_4_AF_U0C0_SELO0  	(0x30UL)
#define P1_4_AF_U0C1_SELO1  	(0x38UL)
#define P1_5_AF_VADC_EMUX1_IN	(0x8UL)
#define P1_5_AF_U0C0_DOUT0  	(0x10UL)
#define P1_5_AF_BCCU0_OUT1  	(0x20UL)
#define P1_5_AF_CCU80_OUT21 	(0x28UL)
#define P1_5_AF_U0C0_SELO1  	(0x30UL)
#define P1_5_AF_U0C1_SELO2  	(0x38UL)
#define P2_0_AF_ERU0_PDOUT3 	(0x8UL)
#define P2_0_AF_CCU40_OUT0  	(0x10UL)
#define P2_0_AF_ERU0_GOUT3  	(0x18UL)
#define P2_0_AF_CCU80_OUT20 	(0x28UL)
#define P2_0_AF_U0C0_DOUT0  	(0x30UL)
#define P2_0_AF_U0C0_SCLKOUT	(0x38UL)
#define P2_1_AF_ERU0_PDOUT2 	(0x8UL)
#define P2_1_AF_CCU40_OUT1  	(0x10UL)
#define P2_1_AF_ERU0_GOUT2  	(0x18UL)
#define P2_1_AF_CCU80_OUT21 	(0x28UL)
#define P2_1_AF_U0C0_DOUT0  	(0x30UL)
#define P2_1_AF_U0C1_SCLKOUT	(0x38UL)
#define P2_10_AF_ERU0_PDOUT1	(0x8UL)
#define P2_10_AF_CCU40_OUT2 	(0x10UL)
#define P2_10_AF_ERU0_GOUT1 	(0x18UL)
#define P2_10_AF_CCU80_OUT30	(0x28UL)
#define P2_10_AF_ACMP0_OUT  	(0x30UL)
#define P2_10_AF_U0C1_DOUT0 	(0x38UL)
#define P2_11_AF_ERU0_PDOUT0	(0x8UL)
#define P2_11_AF_CCU40_OUT3 	(0x10UL)
#define P2_11_AF_ERU0_GOUT0 	(0x18UL)
#define P2_11_AF_CCU80_OUT31	(0x28UL)
#define P2_11_AF_U0C1_SCLKOUT	(0x30UL)
#define P2_11_AF_U0C1_DOUT0 	(0x38UL)
#endif

#endif
