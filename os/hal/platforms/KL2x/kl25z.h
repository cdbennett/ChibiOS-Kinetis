/*
 * Copyright (C) 2013 Fabio Utzig, http://fabioutzig.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef _KL25Z_H_
#define _KL25Z_H_

/*
 * ==============================================================
 * ---------- Interrupt Number Definition -----------------------
 * ==============================================================
 */
typedef enum IRQn
{
/******  Cortex-M0 Processor Exceptions Numbers ****************/
  Reset_IRQn                    = -15,
  NonMaskableInt_IRQn           = -14,
  HardFault_IRQn                = -13,
  SVCall_IRQn                   = -5,
  PendSV_IRQn                   = -2,
  SysTick_IRQn                  = -1,

/******  KL2x Specific Interrupt Numbers ***********************/
  DMA0_IRQn                     = 0,
  DMA1_IRQn                     = 1,
  DMA2_IRQn                     = 2,
  DMA3_IRQn                     = 3,
  Reserved0_IRQn                = 4,
  FTFA_IRQn                     = 5,
  PMC_IRQn                      = 6,
  LLWU_IRQn                     = 7,
  I2C0_IRQn                     = 8,
  I2C1_IRQn                     = 9,
  SPI0_IRQn                     = 10,
  SPI1_IRQn                     = 11,
  UART0_IRQn                    = 12,
  UART1_IRQn                    = 13,
  UART2_IRQn                    = 14,
  ADC0_IRQn                     = 15,
  CMP0_IRQn                     = 16,
  TMP0_IRQn                     = 17,
  TMP1_IRQn                     = 18,
  TMP2_IRQn                     = 19,
  RTC0_IRQn                     = 20,
  RTC1_IRQn                     = 21,
  PIT_IRQn                      = 22,
  Reserved1_IRQn                = 23,
  USB_OTG_IRQn                  = 24,
  DAC0_IRQn                     = 25,
  TSI0_IRQn                     = 26,
  MCG_IRQn                      = 27,
  LPTMR0_IRQn                   = 28,
  Reserved2_IRQn                = 29,
  PINA_IRQn                     = 30,
  PIND_IRQn                     = 31,
} IRQn_Type;

/*
 * ==========================================================================
 * ----------- Processor and Core Peripheral Section ------------------------
 * ==========================================================================
 */

/**
 * @brief KL25Z Interrupt Number Definition, according to the selected device
 *        in @ref Library_configuration_section
 */
#define __MPU_PRESENT             0 /*!< Kinetis L do not provide MPU                  */
#define __NVIC_PRIO_BITS          2 /*!< Kinetis L uses 2 Bits for the Priority Levels */
#define __Vendor_SysTickConfig    0 /*!< Set to 1 if different SysTick Config is used  */

#include "core_cm0plus.h"           /* Cortex-M0+ processor and core peripherals       */

typedef struct
{
  __IO uint32_t SOPT1;
  __IO uint32_t SOPT1CFG;
       uint32_t RESERVED0[1023];
  __IO uint32_t SOPT2;
  __I  uint32_t RESERVED1[1];
  __IO uint32_t SOPT4;
  __IO uint32_t SOPT5;
       uint32_t RESERVED2[1];
  __IO uint32_t SOPT7;
       uint32_t RESERVED3[2];
  __IO uint32_t SDID;
       uint32_t RESERVED4[3];
  __IO uint32_t SCGC4;
  __IO uint32_t SCGC5;
  __IO uint32_t SCGC6;
  __IO uint32_t SCGC7;
  __IO uint32_t CLKDIV1;
       uint32_t RESERVED5[1];
  __IO uint32_t FCFG1;
  __IO uint32_t FCFG2;
       uint32_t RESERVED6[1];
  __IO uint32_t UIDMH;
  __IO uint32_t UIDML;
  __IO uint32_t UIDL;
       uint32_t RESERVED7[39];
  __IO uint32_t COPC;
  __IO uint32_t SRVCOP;
} SIM_TypeDef;

typedef struct
{
  __IO uint32_t PCR[32];
  __IO uint32_t GPCLR;
  __IO uint32_t GPCHR;
       uint32_t RESERVED0[6];
  __IO uint32_t ISFR;
} PORT_TypeDef;

typedef struct
{
  __IO uint8_t  C1;
  __IO uint8_t  C2;
  __IO uint8_t  C3;
  __IO uint8_t  C4;
  __IO uint8_t  C5;
  __IO uint8_t  C6;
  __IO uint8_t  S;
       uint8_t  RESERVED0[1];
  __IO uint8_t  SC;
       uint8_t  RESERVED1[1];
  __IO uint8_t  ATCVH;
  __IO uint8_t  ATCVL;
  __IO uint8_t  C7;
  __IO uint8_t  C8;
  __IO uint8_t  C9;
  __IO uint8_t  C10;
} MCG_TypeDef;

typedef struct
{
  __IO uint8_t  CR;
} OSC_TypeDef;

typedef struct
{
  __IO uint32_t  SAR;
  __IO uint32_t  DAR;
  __IO uint32_t  DSR_BCR;
  __IO uint32_t  DCR;
} DMAChannel_TypeDef;

typedef struct
{
  DMAChannel_TypeDef ch[4];
} DMA_TypeDef;

typedef struct
{
  __IO uint8_t  CHCFG[4];
} DMAMUX_TypeDef;

typedef struct
{
  __IO uint32_t SC;
  __IO uint32_t CNT;
  __IO uint32_t MOD;
  __IO uint32_t C0SC;
  __IO uint32_t C0V;
  __IO uint32_t C1SC;
  __IO uint32_t C1V;
  __IO uint32_t C2SC;
  __IO uint32_t C2V;
  __IO uint32_t C3SC;
  __IO uint32_t C3V;
  __IO uint32_t C4SC;
  __IO uint32_t C4V;
  __IO uint32_t C5SC;
  __IO uint32_t C5V;
       uint32_t RESERVED0[5];
  __IO uint32_t STATUS;
       uint32_t RESERVED1[12];
  __IO uint32_t CONF;
} TPM_TypeDef;

typedef struct
{
  __IO uint32_t PDOR;
  __IO uint32_t PSOR;
  __IO uint32_t PCOR;
  __IO uint32_t PTOR;
  __IO uint32_t PDIR;
  __IO uint32_t PDDR;
} GPIO_TypeDef;

typedef struct
{
  __IO uint8_t  C1;
  __IO uint8_t  C2;
  __IO uint8_t  BR;
  __IO uint8_t  S;
       uint8_t  RESERVED0[1];
  __IO uint8_t  D;
       uint8_t  RESERVED1[1];
  __IO uint8_t  M;
} SPI_TypeDef;

typedef struct
{
  __IO uint8_t  A1;
  __IO uint8_t  F;
  __IO uint8_t  C1;
  __IO uint8_t  S;
  __IO uint8_t  D;
  __IO uint8_t  C2;
  __IO uint8_t  FLT;
  __IO uint8_t  RA;
  __IO uint8_t  SMB;
  __IO uint8_t  A2;
  __IO uint8_t  SLTH;
  __IO uint8_t  SLTL;
} I2C_TypeDef;

typedef struct
{
  __IO uint8_t  BDH;
  __IO uint8_t  BDL;
  __IO uint8_t  C1;
  __IO uint8_t  C2;
  __IO uint8_t  S1;
  __IO uint8_t  S2;
  __IO uint8_t  C3;
  __IO uint8_t  D;
  __IO uint8_t  C4;
} UART_TypeDef;

typedef struct
{
  __IO uint8_t  BDH;
  __IO uint8_t  BDL;
  __IO uint8_t  C1;
  __IO uint8_t  C2;
  __IO uint8_t  S1;
  __IO uint8_t  S2;
  __IO uint8_t  C3;
  __IO uint8_t  D;
  __IO uint8_t  MA1;
  __IO uint8_t  MA2;
  __IO uint8_t  C4;
  __IO uint8_t  C5;
} UARTLP_TypeDef;

/****************************************************************/
/*                  Peripheral memory map                       */
/****************************************************************/
#define DMA_BASE                ((uint32_t)0x40008100)
#define DMAMUX_BASE             ((uint32_t)0x40021000)
#define TPM0_BASE               ((uint32_t)0x40038000)
#define TPM1_BASE               ((uint32_t)0x40039000)
#define TPM2_BASE               ((uint32_t)0x4003A000)
#define SIM_BASE                ((uint32_t)0x40047000)
#define PORTA_BASE              ((uint32_t)0x40049000)
#define PORTB_BASE              ((uint32_t)0x4004A000)
#define PORTC_BASE              ((uint32_t)0x4004B000)
#define PORTD_BASE              ((uint32_t)0x4004C000)
#define PORTE_BASE              ((uint32_t)0x4004D000)
#define MCG_BASE                ((uint32_t)0x40064000)
#define OSC0_BASE               ((uint32_t)0x40065000)
#define I2C0_BASE               ((uint32_t)0x40066000)
#define I2C1_BASE               ((uint32_t)0x40067000)
#define UART0_BASE              ((uint32_t)0x4006A000)
#define UART1_BASE              ((uint32_t)0x4006B000)
#define UART2_BASE              ((uint32_t)0x4006C000)
#define SPI0_BASE               ((uint32_t)0x40076000)
#define SPI1_BASE               ((uint32_t)0x40077000)
#define GPIOA_BASE              ((uint32_t)0x400FF000)
#define GPIOB_BASE              ((uint32_t)0x400FF040)
#define GPIOC_BASE              ((uint32_t)0x400FF080)
#define GPIOD_BASE              ((uint32_t)0x400FF0C0)
#define GPIOE_BASE              ((uint32_t)0x400FF100)

/****************************************************************/
/*                 Peripheral declaration                       */
/****************************************************************/
#define DMA                     ((DMA_TypeDef *)     DMA_BASE)
#define DMAMUX                  ((DMAMUX_TypeDef *)  DMAMUX_BASE)
#define TPM0                    ((TPM_TypeDef *)     TPM0_BASE)
#define TPM1                    ((TPM_TypeDef *)     TPM1_BASE)
#define TPM2                    ((TPM_TypeDef *)     TPM2_BASE)
#define SIM                     ((SIM_TypeDef  *)    SIM_BASE)
#define PORTA                   ((PORT_TypeDef  *)   PORTA_BASE)
#define PORTB                   ((PORT_TypeDef  *)   PORTB_BASE)
#define PORTC                   ((PORT_TypeDef  *)   PORTC_BASE)
#define PORTD                   ((PORT_TypeDef  *)   PORTD_BASE)
#define PORTE                   ((PORT_TypeDef  *)   PORTE_BASE)
#define MCG                     ((MCG_TypeDef  *)    MCG_BASE)
#define OSC0                    ((OSC_TypeDef  *)    OSC0_BASE)
#define SPI0                    ((SPI_TypeDef *)     SPI0_BASE)
#define SPI1                    ((SPI_TypeDef *)     SPI1_BASE)
#define I2C0                    ((I2C_TypeDef *)     I2C0_BASE)
#define I2C1                    ((I2C_TypeDef *)     I2C1_BASE)
#define UART0                   ((UARTLP_TypeDef *)  UART0_BASE)
#define UART1                   ((UART_TypeDef *)    UART1_BASE)
#define UART2                   ((UART_TypeDef *)    UART2_BASE)
#define GPIOA                   ((GPIO_TypeDef  *)   GPIOA_BASE)
#define GPIOB                   ((GPIO_TypeDef  *)   GPIOB_BASE)
#define GPIOC                   ((GPIO_TypeDef  *)   GPIOC_BASE)
#define GPIOD                   ((GPIO_TypeDef  *)   GPIOD_BASE)
#define GPIOE                   ((GPIO_TypeDef  *)   GPIOE_BASE)

/****************************************************************/
/*           Peripheral Registers Bits Definition               */
/****************************************************************/

/****************************************************************/
/*                                                              */
/*             System Integration Module (SIM)                  */
/*                                                              */
/****************************************************************/
/*********  Bits definition for SIM_SOPT1 register  *************/
#define SIM_SOPT1_USBREGEN           ((uint32_t)0x80000000)    /*!< USB voltage regulator enable */
#define SIM_SOPT1_USBSSTBY           ((uint32_t)0x40000000)    /*!< USB voltage regulator in standby mode during Stop, VLPS, LLS and VLLS modes */
#define SIM_SOPT1_USBVSTBY           ((uint32_t)0x20000000)    /*!< USB voltage regulator in standby mode during VLPR and VLPW modes */
#define SIM_SOPT1_OSC32KSEL          ((uint32_t)0x000C0000)    /*!< 32K oscillator clock select */

/*******  Bits definition for SIM_SOPT1CFG register  ************/
#define SIM_SOPT1CFG_USSWE           ((uint32_t)0x04000000)    /*!< USB voltage regulator stop standby write enable */
#define SIM_SOPT1CFG_UVSWE           ((uint32_t)0x02000000)    /*!< USB voltage regulator VLP standby write enable */
#define SIM_SOPT1CFG_URWE            ((uint32_t)0x01000000)    /*!< USB voltage regulator voltage regulator write enable */

/*******  Bits definition for SIM_SOPT2 register  ************/
#define SIM_SOPT2_UART0SRC           ((uint32_t)0x0C000000)    /*!< UART0 clock source select */
#define SIM_SOPT2_TPMSRC             ((uint32_t)0x03000000)    /*!< TPM clock source select */
#define SIM_SOPT2_USBSRC             ((uint32_t)0x00040000)    /*!< USB clock source select */
#define SIM_SOPT2_PLLFLLSEL          ((uint32_t)0x00010000)    /*!< PLL/FLL clock select */
#define SIM_SOPT2_CLKOUTSEL          ((uint32_t)0x000000E0)    /*!< CLKOUT select */
#define SIM_SOPT2_RTCCLKOUTSEL       ((uint32_t)0x00000010)    /*!< RTC clock out select */

#define SIM_SOPT2_UART0SRC_SHIFT     26

/*******  Bits definition for SIM_SCGC4 register  ************/
#define SIM_SCGC4_SPI1               ((uint32_t)0x00800000)    /*!< SPI1 Clock Gate Control */
#define SIM_SCGC4_SPI0               ((uint32_t)0x00400000)    /*!< SPI0 Clock Gate Control */
#define SIM_SCGC4_CMP                ((uint32_t)0x00080000)    /*!< Comparator Clock Gate Control */
#define SIM_SCGC4_USBOTG             ((uint32_t)0x00040000)    /*!< USB Clock Gate Control */
#define SIM_SCGC4_UART2              ((uint32_t)0x00001000)    /*!< UART2 Clock Gate Control */
#define SIM_SCGC4_UART1              ((uint32_t)0x00000800)    /*!< UART1 Clock Gate Control */
#define SIM_SCGC4_UART0              ((uint32_t)0x00000400)    /*!< UART0 Clock Gate Control */
#define SIM_SCGC4_I2C1               ((uint32_t)0x00000080)    /*!< I2C1 Clock Gate Control */
#define SIM_SCGC4_I2C0               ((uint32_t)0x00000040)    /*!< I2C0 Clock Gate Control */

/*******  Bits definition for SIM_SCGC5 register  ************/
#define SIM_SCGC5_PORTE              ((uint32_t)0x00002000)    /*!< Port E Clock Gate Control */
#define SIM_SCGC5_PORTD              ((uint32_t)0x00001000)    /*!< Port D Clock Gate Control */
#define SIM_SCGC5_PORTC              ((uint32_t)0x00000800)    /*!< Port C Clock Gate Control */
#define SIM_SCGC5_PORTB              ((uint32_t)0x00000400)    /*!< Port B Clock Gate Control */
#define SIM_SCGC5_PORTA              ((uint32_t)0x00000200)    /*!< Port A Clock Gate Control */
#define SIM_SCGC5_TSI                ((uint32_t)0x00000020)    /*!< TSI Access Control */
#define SIM_SCGC5_LPTMR              ((uint32_t)0x00000001)    /*!< Low Power Timer Access Control */

/****************************************************************/
/*                                                              */
/*           Port Control and interrupts (PORT)                 */
/*                                                              */
/****************************************************************/
/********  Bits definition for PORTx_PCRn register  *************/
#define PORTx_PRCn_ISR               ((uint32_t)0x01000000)    /*!< Interrupt Status Flag */
#define PORTx_PRCn_IRQC              ((uint32_t)0x000F0000)    /*!< Interrupt Configuration */
#define PORTx_PRCn_MUX               ((uint32_t)0x00000700)    /*!< Pin Mux Control */
#define PORTx_PRCn_DSE               ((uint32_t)0x00000040)    /*!< Drive Strength Enable */
#define PORTx_PRCn_PFE               ((uint32_t)0x00000010)    /*!< Passive Filter Enable */
#define PORTx_PRCn_SRE               ((uint32_t)0x00000004)    /*!< Slew Rate Enable */
#define PORTx_PRCn_PE                ((uint32_t)0x00000002)    /*!< Pull Enable */
#define PORTx_PRCn_PS                ((uint32_t)0x00000001)    /*!< Pull Select */

#define PORTx_PRCn_MUX_SHIFT         8

/****************************************************************/
/*                                                              */
/*                   Oscillator (OSC)                           */
/*                                                              */
/****************************************************************/
/***********  Bits definition for OSC_CR register  **************/
#define OSC_CR_ERCLKEN               ((uint8_t)0x80)    /*!< External Reference Enable */
#define OSC_CR_EREFSTEN              ((uint8_t)0x20)    /*!< External Reference Stop Enable */
#define OSC_CR_SC2P                  ((uint8_t)0x08)    /*!< Oscillator 2pF Capacitor Load Configure */
#define OSC_CR_SC4P                  ((uint8_t)0x04)    /*!< Oscillator 4pF Capacitor Load Configure */
#define OSC_CR_SC8P                  ((uint8_t)0x02)    /*!< Oscillator 8pF Capacitor Load Configure */
#define OSC_CR_SC16P                 ((uint8_t)0x01)    /*!< Oscillator 16pF Capacitor Load Configure */

/****************************************************************/
/*                                                              */
/*                 Direct Memory Access (DMA)                   */
/*                                                              */
/****************************************************************/
/***********  Bits definition for DMA_BCRn register  ************/
#define DMA_DSR_BCRn_CE              ((uint32_t)1 << 30)    /*!< Configuration Error */
#define DMA_DSR_BCRn_BES             ((uint32_t)1 << 29)    /*!< Bus Error on Source */
#define DMA_DSR_BCRn_BED             ((uint32_t)1 << 28)    /*!< Bus Error on Destination */
#define DMA_DSR_BCRn_REQ             ((uint32_t)1 << 26)    /*!< Request */
#define DMA_DSR_BCRn_BSY             ((uint32_t)1 << 25)    /*!< Busy */
#define DMA_DSR_BCRn_DONE            ((uint32_t)1 << 24)    /*!< Transactions done */
#define DMA_DSR_BCRn_BCR_MASK        ((uint32_t)0x00FFFFFF) /*!< Bytes yet to be transferred for block */
/***********  Bits definition for DMA_DCRn register  ************/
#define DMA_DCRn_EINT            ((uint32_t)1 << 31)    /*!< Enable interrupt on completion of transfer */
#define DMA_DCRn_ERQ             ((uint32_t)1 << 30)    /*!< Enable peripheral request */
#define DMA_DCRn_CS              ((uint32_t)1 << 29)    /*!< Cycle steal */
#define DMA_DCRn_AA              ((uint32_t)1 << 28)    /*!< Auto-align */
#define DMA_DCRn_EADREQ          ((uint32_t)1 << 23)    /*!< Enable asynchronous DMA requests */
#define DMA_DCRn_SINC            ((uint32_t)1 << 22)    /*!< Source increment */
#define DMA_DCRn_SSIZE1          ((uint32_t)1 << 21)    /*!< Source size (bit 1) */
#define DMA_DCRn_SSIZE0          ((uint32_t)1 << 20)    /*!< Source size (bit 0) */
#define DMA_DCRn_DINC            ((uint32_t)1 << 19)    /*!< Destination increment */
#define DMA_DCRn_DSIZE1          ((uint32_t)1 << 18)    /*!< Destination size (bit 1) */
#define DMA_DCRn_DSIZE0          ((uint32_t)1 << 17)    /*!< Destination size (bit 0) */
#define DMA_DCRn_START           ((uint32_t)1 << 16)    /*!< Start transfer */
#define DMA_DCRn_SMOD3           ((uint32_t)1 << 15)    /*!< Source address modulo (bit 3) */
#define DMA_DCRn_SMOD2           ((uint32_t)1 << 14)    /*!< Source address modulo (bit 2) */
#define DMA_DCRn_SMOD1           ((uint32_t)1 << 13)    /*!< Source address modulo (bit 1) */
#define DMA_DCRn_SMOD0           ((uint32_t)1 << 12)    /*!< Source address modulo (bit 0) */
#define DMA_DCRn_DMOD3           ((uint32_t)1 << 11)    /*!< Destination address modulo (bit 3) */
#define DMA_DCRn_DMOD2           ((uint32_t)1 << 10)    /*!< Destination address modulo (bit 2) */
#define DMA_DCRn_DMOD1           ((uint32_t)1 <<  9)    /*!< Destination address modulo (bit 1) */
#define DMA_DCRn_DMOD0           ((uint32_t)1 <<  8)    /*!< Destination address modulo (bit 0) */
#define DMA_DCRn_D_REQ           ((uint32_t)1 <<  7)    /*!< Disable request */
#define DMA_DCRn_LINKCC1         ((uint32_t)1 <<  5)    /*!< Link channel control (bit 1) */
#define DMA_DCRn_LINKCC0         ((uint32_t)1 <<  4)    /*!< Link channel control (bit 0) */
#define DMA_DCRn_LCH1_1          ((uint32_t)1 <<  3)    /*!< Link channel 1 (bit 1) */
#define DMA_DCRn_LCH1_0          ((uint32_t)1 <<  2)    /*!< Link channel 1 (bit 0) */
#define DMA_DCRn_LCH2_1          ((uint32_t)1 <<  1)    /*!< Link channel 2 (bit 1) */
#define DMA_DCRn_LCH2_0          ((uint32_t)1 <<  0)    /*!< Link channel 2 (bit 0) */

/****************************************************************/
/*                                                              */
/*         Direct Memory Access Multiplexer (DMAMUX)            */
/*                                                              */
/****************************************************************/
/********  Bits definition for DMAMUX_CHCFGn register  **********/
#define DMAMUX_CHCFGn_ENBL           ((uint8_t)1 << 7)  /*!< DMA Channel Enable */
#define DMAMUX_CHCFGn_TRIG           ((uint8_t)1 << 6)  /*!< DMA Channel Trigger Enable */
#define DMAMUX_CHCFGn_SOURCE_MASK    ((uint8_t)0x3F)    /*!< DMA Channel Source (Slot) */
#define DMAMUX_CHCFGn_SOURCE_POS     (0)                /*!< DMA Channel Source (Slot) */

/****************************************************************/
/*                                                              */
/*             Serial Peripheral Interface (SPI)                */
/*                                                              */
/****************************************************************/
/***********  Bits definition for SPIx_C1 register  *************/
#define SPIx_C1_SPIE                 ((uint8_t)0x80)    /*!< SPI Interrupt Enable */
#define SPIx_C1_SPE                  ((uint8_t)0x40)    /*!< SPI System Enable */
#define SPIx_C1_SPTIE                ((uint8_t)0x20)    /*!< SPI Transmit Interrupt Enable */
#define SPIx_C1_MSTR                 ((uint8_t)0x10)    /*!< Master/Slave Mode Select */
#define SPIx_C1_CPOL                 ((uint8_t)0x08)    /*!< Clock Polarity */
#define SPIx_C1_CPHA                 ((uint8_t)0x04)    /*!< Clock Phase */
#define SPIx_C1_SSOE                 ((uint8_t)0x02)    /*!< Slave Select Output Enable */
#define SPIx_C1_LSBFE                ((uint8_t)0x01)    /*!< LSB First */

/***********  Bits definition for SPIx_C2 register  *************/
#define SPIx_C2_SPMIE                ((uint8_t)0x80)    /*!< SPI Match Interrupt Enable */
#define SPIx_C2_TXDMAE               ((uint8_t)0x20)    /*!< Transmit DMA Enable */
#define SPIx_C2_MODFEN               ((uint8_t)0x10)    /*!< Master Mode-Fault Function Enable */
#define SPIx_C2_BIDIROE              ((uint8_t)0x08)    /*!< Bidirectional Mode Output Enable */
#define SPIx_C2_RXDMAE               ((uint8_t)0x04)    /*!< Receive DMA Enable */
#define SPIx_C2_SPISWAI              ((uint8_t)0x02)    /*!< SPI Stop in Wait Mode */
#define SPIx_C2_SPC0                 ((uint8_t)0x01)    /*!< SPI Pin Control 0 */

/***********  Bits definition for SPIx_BR register  *************/
#define SPIx_BR_SPPR                 ((uint8_t)0x70)    /*!< SPI Baud rate Prescaler Divisor */
#define SPIx_BR_SPR                  ((uint8_t)0x0F)    /*!< SPI Baud rate Divisor */

#define SPIx_BR_SPPR_SHIFT           4

/***********  Bits definition for SPIx_S register  **************/
#define SPIx_S_SPRF                  ((uint8_t)0x80)    /*!< SPI Read Buffer Full Flag */
#define SPIx_S_SPMF                  ((uint8_t)0x40)    /*!< SPI Match Flag */
#define SPIx_S_SPTEF                 ((uint8_t)0x20)    /*!< SPI Transmit Buffer Empty Flag */
#define SPIx_S_MODF                  ((uint8_t)0x10)    /*!< Master Mode Fault Flag */

/***********  Bits definition for SPIx_D register  **************/
#define SPIx_D_DATA                  ((uint8_t)0xFF)    /*!< Data */

/***********  Bits definition for SPIx_M register  **************/
#define SPIx_M_DATA                  ((uint8_t)0xFF)    /*!< SPI HW Compare value for Match */

/****************************************************************/
/*                                                              */
/*             Inter-Integrated Circuit (I2C)                   */
/*                                                              */
/****************************************************************/
/***********  Bits definition for I2Cx_A1 register  *************/
#define I2Cx_A1_AD                   ((uint8_t)0xFE)    /*!< Address [7:1] */

#define I2Cx_A1_AD_SHIT              1

/***********  Bits definition for I2Cx_F register  **************/
#define I2Cx_F_MULT                  ((uint8_t)0xC0)    /*!< Multiplier factor */
#define I2Cx_F_ICR                   ((uint8_t)0x3F)    /*!< Clock rate */

#define I2Cx_F_MULT_SHIFT            5

/***********  Bits definition for I2Cx_C1 register  *************/
#define I2Cx_C1_IICEN                ((uint8_t)0x80)    /*!< I2C Enable */
#define I2Cx_C1_IICIE                ((uint8_t)0x40)    /*!< I2C Interrupt Enable */
#define I2Cx_C1_MST                  ((uint8_t)0x20)    /*!< Master Mode Select */
#define I2Cx_C1_TX                   ((uint8_t)0x10)    /*!< Transmit Mode Select */
#define I2Cx_C1_TXAK                 ((uint8_t)0x08)    /*!< Transmit Acknowledge Enable */
#define I2Cx_C1_RSTA                 ((uint8_t)0x04)    /*!< Repeat START */
#define I2Cx_C1_WUEN                 ((uint8_t)0x02)    /*!< Wakeup Enable */
#define I2Cx_C1_DMAEN                ((uint8_t)0x01)    /*!< DMA Enable */

/***********  Bits definition for I2Cx_S register  **************/
#define I2Cx_S_TCF                   ((uint8_t)0x80)    /*!< Transfer Complete Flag */
#define I2Cx_S_IAAS                  ((uint8_t)0x40)    /*!< Addressed As A Slave */
#define I2Cx_S_BUSY                  ((uint8_t)0x20)    /*!< Bus Busy */
#define I2Cx_S_ARBL                  ((uint8_t)0x10)    /*!< Arbitration Lost */
#define I2Cx_S_RAM                   ((uint8_t)0x08)    /*!< Range Address Match */
#define I2Cx_S_SRW                   ((uint8_t)0x04)    /*!< Slave Read/Write */
#define I2Cx_S_IICIF                 ((uint8_t)0x02)    /*!< Interrupt Flag */
#define I2Cx_S_RXAK                  ((uint8_t)0x01)    /*!< Receive Acknowledge */

/***********  Bits definition for I2Cx_D register  **************/
#define I2Cx_D_DATA                  ((uint8_t)0xFF)    /*!< Data */

/***********  Bits definition for I2Cx_C2 register  *************/
#define I2Cx_C2_GCAEN                ((uint8_t)0x80)    /*!< General Call Address Enable */
#define I2Cx_C2_ADEXT                ((uint8_t)0x40)    /*!< Address Extension */
#define I2Cx_C2_HDRS                 ((uint8_t)0x20)    /*!< High Drive Select */
#define I2Cx_C2_SBRC                 ((uint8_t)0x10)    /*!< Slave Baud Rate Control */
#define I2Cx_C2_RMEN                 ((uint8_t)0x08)    /*!< Range Address Matching Enable */
#define I2Cx_C2_AD_10_8              ((uint8_t)0x03)    /*!< Slave Address [10:8] */

/***********  Bits definition for I2Cx_FLT register  ************/
#define I2Cx_FLT_SHEN                ((uint8_t)0x80)    /*!< Stop Hold Enable */
#define I2Cx_FLT_STOPF               ((uint8_t)0x40)    /*!< I2C Bus Stop Detect Flag */
#define I2Cx_FLT_STOPIE              ((uint8_t)0x20)    /*!< I2C Bus Stop Interrupt Enable */
#define I2Cx_FLT_FLT                 ((uint8_t)0x1F)    /*!< I2C Programmable Filter Factor */

/***********  Bits definition for I2Cx_RA register  *************/
#define I2Cx_RA_RAD                  ((uint8_t)0xFE)    /*!< Range Slave Address */

#define I2Cx_RA_RAD_SHIFT            1

/***********  Bits definition for I2Cx_SMB register  ************/
#define I2Cx_SMB_FACK                ((uint8_t)0x00)    /*!< Fast NACK/ACK Enable */
#define I2Cx_SMB_ALERTEN             ((uint8_t)0x00)    /*!< SMBus Alert Response Address Enable */
#define I2Cx_SMB_SIICAEN             ((uint8_t)0x00)    /*!< Second I2C Address Enable */
#define I2Cx_SMB_TCKSEL              ((uint8_t)0x00)    /*!< Timeout Counter Clock Select */
#define I2Cx_SMB_SLTF                ((uint8_t)0x00)    /*!< SCL Low Timeout Flag */
#define I2Cx_SMB_SHTF1               ((uint8_t)0x00)    /*!< SCL High Timeout Flag 1 */
#define I2Cx_SMB_SHTF2               ((uint8_t)0x00)    /*!< SCL High Timeout Flag 2 */
#define I2Cx_SMB_SHTF2IE             ((uint8_t)0x00)    /*!< SHTF2 Interrupt Enable */

/***********  Bits definition for I2Cx_A2 register  *************/
#define I2Cx_A2_SAD                  ((uint8_t)0xFE)    /*!< SMBus Address */

#define I2Cx_A2_SAD_SHIFT            1

/***********  Bits definition for I2Cx_SLTH register  ***********/
#define I2Cx_SLTH_SSLT               ((uint8_t)0xFF)    /*!< MSB of SCL low timeout value */

/***********  Bits definition for I2Cx_SLTL register  ***********/
#define I2Cx_SLTL_SSLT               ((uint8_t)0xFF)    /*!< LSB of SCL low timeout value */

/****************************************************************/
/*                                                              */
/*     Universal Asynchronous Receiver/Transmitter (UART)       */
/*                                                              */
/****************************************************************/
/*********  Bits definition for UARTx_BDH register  *************/
#define UARTx_BDH_LBKDIE             ((uint8_t)0x80)    /*!< LIN Break Detect Interrupt Enable */
#define UARTx_BDH_RXEDGIE            ((uint8_t)0x40)    /*!< RX Input Active Edge Interrupt Enable */
#define UARTx_BDH_SBNS               ((uint8_t)0x20)    /*!< Stop Bit Number Select */
#define UARTx_BDH_SBR                ((uint8_t)0x1F)    /*!< Baud Rate Modulo Divisor */

/*********  Bits definition for UARTx_BDL register  *************/
#define UARTx_BDL_SBR                ((uint8_t)0xFF)    /*!< Baud Rate Modulo Divisor */

/*********  Bits definition for UARTx_C1 register  **************/
#define UARTx_C1_LOOPS               ((uint8_t)0x80)    /*!< Loop Mode Select */
#define UARTx_C1_DOZEEN              ((uint8_t)0x40)    /*!< Doze Enable */
#define UARTx_C1_UARTSWAI            ((uint8_t)0x40)    /*!< UART Stops in Wait Mode */
#define UARTx_C1_RSRC                ((uint8_t)0x20)    /*!< Receiver Source Select */
#define UARTx_C1_M                   ((uint8_t)0x10)    /*!< 9-Bit or 8-Bit Mode Select */
#define UARTx_C1_WAKE                ((uint8_t)0x08)    /*!< Receiver Wakeup Method Select */
#define UARTx_C1_ILT                 ((uint8_t)0x04)    /*!< Idle Line Type Select */
#define UARTx_C1_PE                  ((uint8_t)0x02)    /*!< Parity Enable */
#define UARTx_C1_PT                  ((uint8_t)0x01)    /*!< Parity Type */

/*********  Bits definition for UARTx_C2 register  **************/
#define UARTx_C2_TIE                 ((uint8_t)0x80)    /*!< Transmit Interrupt Enable for TDRE */
#define UARTx_C2_TCIE                ((uint8_t)0x40)    /*!< Transmission Complete Interrupt Enable for TC */
#define UARTx_C2_RIE                 ((uint8_t)0x20)    /*!< Receiver Interrupt Enable for RDRF */
#define UARTx_C2_ILIE                ((uint8_t)0x10)    /*!< Idle Line Interrupt Enable for IDLE */
#define UARTx_C2_TE                  ((uint8_t)0x08)    /*!< Transmitter Enable */
#define UARTx_C2_RE                  ((uint8_t)0x04)    /*!< Receiver Enable */
#define UARTx_C2_RWU                 ((uint8_t)0x02)    /*!< Receiver Wakeup Control */
#define UARTx_C2_SBK                 ((uint8_t)0x01)    /*!< Send Break */

/*********  Bits definition for UARTx_S1 register  **************/
#define UARTx_S1_TDRE                ((uint8_t)0x80)    /*!< Transmit Data Register Empty Flag */
#define UARTx_S1_TC                  ((uint8_t)0x40)    /*!< Transmission Complete Flag */
#define UARTx_S1_RDRF                ((uint8_t)0x20)    /*!< Receiver Data Register Full Flag */
#define UARTx_S1_IDLE                ((uint8_t)0x10)    /*!< Idle Line Flag */
#define UARTx_S1_OR                  ((uint8_t)0x08)    /*!< Receiver Overrun Flag */
#define UARTx_S1_NF                  ((uint8_t)0x04)    /*!< Noise Flag */
#define UARTx_S1_FE                  ((uint8_t)0x02)    /*!< Framing Error Flag */
#define UARTx_S1_PF                  ((uint8_t)0x01)    /*!< Parity Error Flag */

/*********  Bits definition for UARTx_S2 register  **************/
#define UARTx_S2_LBKDIF              ((uint8_t)0x80)    /*!< LIN Break Detect Interrupt Flag */
#define UARTx_S2_RXEDGIF             ((uint8_t)0x40)    /*!< UART_RX Pin Active Edge Interrupt Flag */
#define UARTx_S2_MSBF                ((uint8_t)0x20)    /*!< MSB First */
#define UARTx_S2_RXINV               ((uint8_t)0x10)    /*!< Receive Data Inversion */
#define UARTx_S2_RWUID               ((uint8_t)0x08)    /*!< Receive Wake Up Idle Detect */
#define UARTx_S2_BRK13               ((uint8_t)0x04)    /*!< Break Character Generation Length */
#define UARTx_S2_LBKDE               ((uint8_t)0x02)    /*!< LIN Break Detect Enable */
#define UARTx_S2_RAF                 ((uint8_t)0x01)    /*!< Receiver Active Flag */

/*********  Bits definition for UARTx_C3 register  **************/
#define UARTx_C3_R8T9                ((uint8_t)0x80)    /*!< Receive Bit 8 / Transmit Bit 9 */
#define UARTx_C3_R8                  ((uint8_t)0x80)    /*!< Ninth Data Bit for Receiver */
#define UARTx_C3_R9T8                ((uint8_t)0x40)    /*!< Receive Bit 9 / Transmit Bit 8 */
#define UARTx_C3_T8                  ((uint8_t)0x40)    /*!< Ninth Data Bit for Transmitter */
#define UARTx_C3_TXDIR               ((uint8_t)0x20)    /*!< UART_TX Pin Direction in Single-Wire Mode */
#define UARTx_C3_TXINV               ((uint8_t)0x10)    /*!< Transmit Data Inversion */
#define UARTx_C3_ORIE                ((uint8_t)0x08)    /*!< Overrun Interrupt Enable */
#define UARTx_C3_NEIE                ((uint8_t)0x04)    /*!< Noise Error Interrupt Enable */
#define UARTx_C3_FEIE                ((uint8_t)0x02)    /*!< Framing Error Interrupt Enable */
#define UARTx_C3_PEIE                ((uint8_t)0x01)    /*!< Parity Error Interrupt Enable */

/*********  Bits definition for UARTx_D register  ***************/
#define UARTx_D_R7T7                 ((uint8_t)0x80)    /*!< Read receive data buffer 7 or write transmit data buffer 7 */
#define UARTx_D_R6T6                 ((uint8_t)0x40)    /*!< Read receive data buffer 6 or write transmit data buffer 6 */
#define UARTx_D_R5T5                 ((uint8_t)0x20)    /*!< Read receive data buffer 5 or write transmit data buffer 5 */
#define UARTx_D_R4T4                 ((uint8_t)0x10)    /*!< Read receive data buffer 4 or write transmit data buffer 4 */
#define UARTx_D_R3T3                 ((uint8_t)0x08)    /*!< Read receive data buffer 3 or write transmit data buffer 3 */
#define UARTx_D_R2T2                 ((uint8_t)0x04)    /*!< Read receive data buffer 2 or write transmit data buffer 2 */
#define UARTx_D_R1T1                 ((uint8_t)0x02)    /*!< Read receive data buffer 1 or write transmit data buffer 1 */
#define UARTx_D_R0T0                 ((uint8_t)0x01)    /*!< Read receive data buffer 0 or write transmit data buffer 0 */

/*********  Bits definition for UARTx_MA1 register  *************/
#define UARTx_MA1_MA                 ((uint8_t)0xFF)    /*!< Match Address */

/*********  Bits definition for UARTx_MA2 register  *************/
#define UARTx_MA2_MA                 ((uint8_t)0xFF)    /*!< Match Address */

/*********  Bits definition for UARTx_C4 register  **************/
#define UARTx_C4_MAEN1               ((uint8_t)0x80)    /*!< Match Address Mode Enable 1 */
#define UARTx_C4_TDMAS               ((uint8_t)0x80)    /*!< Transmitter DMA Select */
#define UARTx_C4_MAEN2               ((uint8_t)0x40)    /*!< Match Address Mode Enable 2 */
#define UARTx_C4_M10                 ((uint8_t)0x20)    /*!< 10-bit Mode Select */
#define UARTx_C4_RDMAS               ((uint8_t)0x80)    /*!< Receiver Full DMA Select */
#define UARTx_C4_OSR                 ((uint8_t)0x1F)    /*!< Over Sampling Ratio */

/*********  Bits definition for UARTx_C5 register  **************/
#define UARTx_C5_TDMAE               ((uint8_t)0x80)    /*!< Transmitter DMA Enable */
#define UARTx_C5_RDMAE               ((uint8_t)0x20)    /*!< Receiver Full DMA Enable */
#define UARTx_C5_BOTHEDGE            ((uint8_t)0x02)    /*!< Both Edge Sampling */
#define UARTx_C5_RESYNCDIS           ((uint8_t)0x01)    /*!< Resynchronization Disable */

#endif
