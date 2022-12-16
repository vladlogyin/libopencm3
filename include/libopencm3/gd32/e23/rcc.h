/** @defgroup rcc_defines RCC Defines
 *
 * @brief <b>Defined Constants and Types for the GD32E23 Reset and Clock
 * Control</b>
 *
 * @ingroup GD32E23_defines
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2022
 * Vlad Logyin <vladlogyin@gmail.com>
 * @author @htmlonly &copy; @endhtmlonly 2009
 * Federico Ruiz-Ugalde \<memeruiz at gmail dot com\>
 * @author @htmlonly &copy; @endhtmlonly 2009
 * Uwe Hermann <uwe@hermann-uwe.de>
 *
 * @date 10 December 2022
 *
 * LGPL License Terms @ref lgpl_license
 *  */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2022 Vlad Logyin <vladlogyin@gmail.com>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */
/**@{*/

#ifndef LIBOPENCM3_RCC_H
#define LIBOPENCM3_RCC_H

/* RCC registers */

#define RCC_CR0					MMIO32(RCC_BASE + 0x00)
#define RCC_CFGR0				MMIO32(RCC_BASE + 0x04)
#define RCC_CIR					MMIO32(RCC_BASE + 0x08)
#define RCC_APB2RSTR			MMIO32(RCC_BASE + 0x0c)
#define RCC_APB1RSTR			MMIO32(RCC_BASE + 0x10)
#define RCC_AHBENR				MMIO32(RCC_BASE + 0x14)
#define RCC_APB2ENR				MMIO32(RCC_BASE + 0x18)
#define RCC_APB1ENR				MMIO32(RCC_BASE + 0x1c)
#define RCC_BDCR				MMIO32(RCC_BASE + 0x20)
#define RCC_CSR					MMIO32(RCC_BASE + 0x24)
#define RCC_AHBRSTR				MMIO32(RCC_BASE + 0x28)
#define RCC_CFGR1				MMIO32(RCC_BASE + 0x2c)
#define RCC_CFGR2				MMIO32(RCC_BASE + 0x30)
#define RCC_CR1					MMIO32(RCC_BASE + 0x34)
#define RCC_VKEY				MMIO32(RCC_BASE + 0x100)
#define RCC_DSV					MMIO32(RCC_BASE + 0x134)


/* RCC_CR0 values */

#define RCC_CR0_PLLRDY					(1 << 25)
#define RCC_CR0_PLLON					(1 << 24)
#define RCC_CR0_CSSON					(1 << 19)
#define RCC_CR0_HSEBYP					(1 << 18)
#define RCC_CR0_HSERDY					(1 << 17)
#define RCC_CR0_HSEON					(1 << 16)
#define RCC_CR0_HSI8CAL_SHIFT			8
#define RCC_CR0_HSI8CAL_MASK			(0xff << RCC_CR0_HSI8CAL_SHIFT)
#define RCC_CR0_HSI8ADJ_SHIFT			3
#define RCC_CR0_HSI8ADJ_MASK			(0x1f << RCC_CR0_HSI8ADJ_SHIFT)
#define RCC_CR0_HSI8RDY					(1 << 1)
#define RCC_CR0_HSI8ON					(1 << 0)

/* RCC_CFGR0 values */

#define RCC_CFGR0_PLLNODIV				(1 << 31)

#define RCC_CFGR0_MCOPRE_SHIFT			28
#define RCC_CFGR0_MCOPRE				(7 << RCC_CFGR0_MCOPRE_SHIFT)
#define RCC_CFGR0_MCOPRE_DIV1			(0 << RCC_CFGR0_MCOPRE_SHIFT)
#define RCC_CFGR0_MCOPRE_DIV2			(1 << RCC_CFGR0_MCOPRE_SHIFT)
#define RCC_CFGR0_MCOPRE_DIV4			(2 << RCC_CFGR0_MCOPRE_SHIFT)
#define RCC_CFGR0_MCOPRE_DIV8			(3 << RCC_CFGR0_MCOPRE_SHIFT)
#define RCC_CFGR0_MCOPRE_DIV16			(4 << RCC_CFGR0_MCOPRE_SHIFT)
#define RCC_CFGR0_MCOPRE_DIV32			(5 << RCC_CFGR0_MCOPRE_SHIFT)
#define RCC_CFGR0_MCOPRE_DIV64			(6 << RCC_CFGR0_MCOPRE_SHIFT)
#define RCC_CFGR0_MCOPRE_DIV128			(7 << RCC_CFGR0_MCOPRE_SHIFT)

#define RCC_CFGR0_MCO_SHIFT				24
#define RCC_CFGR0_MCO_MASK				0x7
#define RCC_CFGR0_MCO_NOCLK				0
#define RCC_CFGR0_MCO_HSI28				1
#define RCC_CFGR0_MCO_LSI				2
#define RCC_CFGR0_MCO_LSE				3
#define RCC_CFGR0_MCO_SYSCLK			4
#define RCC_CFGR0_MCO_HSI8				5
#define RCC_CFGR0_MCO_HSE				6
#define RCC_CFGR0_MCO_PLL				7

#define RCC_CFGR0_PLLMUL_SHIFT			18
#define RCC_CFGR0_PLLMUL_MASK			(0x20F << RCC_CFGR0_PLLMUL_SHIFT)

#define RCC_CFGR0_PLLXTPRE				(1 << 17)
#define RCC_CFGR0_PLLSRC				(1 << 16)

#define RCC_CFGR0_ADCPRE_SHIFT			14
#define RCC_CFGR0_ADCPRE_MASK			(0x3 << RCC_CFGR0_ADCPRE_SHIFT)

#define RCC_CFGR0_PPRE2_SHIFT			11
#define RCC_CFGR0_PPRE2_MASK			(0x7 << RCC_CFGR0_PPRE2_SHIFT)

#define RCC_CFGR0_PPRE1_SHIFT			8
#define RCC_CFGR0_PPRE1_MASK			(0x7 << RCC_CFGR0_PPRE1_SHIFT)

#define RCC_CFGR0_HPRE_SHIFT			4
#define RCC_CFGR0_HPRE_MASK				(0xF << RCC_CFGR0_HPRE_SHIFT)

#define RCC_CFGR0_SWS_SHIFT				2
#define RCC_CFGR0_SWS_MASK				(0x3 << RCC_CFGR0_SWS_SHIFT)

#define RCC_CFGR0_SW_SHIFT				0
#define RCC_CFGR0_SW_MASK				(0x3 << RCC_CFGR0_SW_SHIFT)

/** @defgroup rcc_cfgr0_pmf PLLMUL: PLL multiplication factor
 * @{
 */
#define RCC_CFGR0_PLLMUL_PLL_CLK_MUL2			0x0
#define RCC_CFGR0_PLLMUL_PLL_CLK_MUL3			0x1
#define RCC_CFGR0_PLLMUL_PLL_CLK_MUL4			0x2
#define RCC_CFGR0_PLLMUL_PLL_CLK_MUL5			0x3
#define RCC_CFGR0_PLLMUL_PLL_CLK_MUL6			0x4
#define RCC_CFGR0_PLLMUL_PLL_CLK_MUL7			0x5
#define RCC_CFGR0_PLLMUL_PLL_CLK_MUL8			0x6
#define RCC_CFGR0_PLLMUL_PLL_CLK_MUL9			0x7
#define RCC_CFGR0_PLLMUL_PLL_CLK_MUL10			0x8
#define RCC_CFGR0_PLLMUL_PLL_CLK_MUL11			0x9
#define RCC_CFGR0_PLLMUL_PLL_CLK_MUL12			0xA
#define RCC_CFGR0_PLLMUL_PLL_CLK_MUL13			0xB
#define RCC_CFGR0_PLLMUL_PLL_CLK_MUL14			0xC
#define RCC_CFGR0_PLLMUL_PLL_CLK_MUL15			0xD
#define RCC_CFGR0_PLLMUL_PLL_CLK_MUL16			0xE
/* TODO test that this is not a typo in the reference manual */
#define RCC_CFGR0_PLLMUL_PLL_CLK_MUL16_2		0xF
#define RCC_CFGR0_PLLMUL_PLL_CLK_MUL17			0x200
#define RCC_CFGR0_PLLMUL_PLL_CLK_MUL18			0x201
#define RCC_CFGR0_PLLMUL_PLL_CLK_MUL19			0x202
#define RCC_CFGR0_PLLMUL_PLL_CLK_MUL20			0x203
#define RCC_CFGR0_PLLMUL_PLL_CLK_MUL21			0x204
#define RCC_CFGR0_PLLMUL_PLL_CLK_MUL22			0x205
#define RCC_CFGR0_PLLMUL_PLL_CLK_MUL23			0x206
#define RCC_CFGR0_PLLMUL_PLL_CLK_MUL24			0x207
#define RCC_CFGR0_PLLMUL_PLL_CLK_MUL25			0x208
#define RCC_CFGR0_PLLMUL_PLL_CLK_MUL26			0x209
#define RCC_CFGR0_PLLMUL_PLL_CLK_MUL27			0x20A
#define RCC_CFGR0_PLLMUL_PLL_CLK_MUL28			0x20B
#define RCC_CFGR0_PLLMUL_PLL_CLK_MUL29			0x20C
#define RCC_CFGR0_PLLMUL_PLL_CLK_MUL30			0x20D
#define RCC_CFGR0_PLLMUL_PLL_CLK_MUL31			0x20E
#define RCC_CFGR0_PLLMUL_PLL_CLK_MUL32			0x20F
/**@}*/

/** @defgroup rcc_cfgr0_hsepre PLLXTPRE: HSE divider for PLL entry
 * @{
 */
#define RCC_CFGR0_PLLXTPRE_HSE_CLK				0x0
#define RCC_CFGR0_PLLXTPRE_HSE_CLK_DIV2			0x1
/**@}*/

/** @defgroup rcc_cfgr0_pcs PLLSRC: PLL entry clock source
 * @{
 */
#define RCC_CFGR0_PLLSRC_HSI8_CLK_DIV2			0x0
#define RCC_CFGR0_PLLSRC_HSE_CLK				0x1
/**@}*/

/** @defgroup rcc_cfgr0_adcpre ADCPRE: ADC prescaler
 * @{
 */
#define RCC_CFGR0_ADCPRE_APB2_DIV2				0x0
#define RCC_CFGR0_ADCPRE_AHB_DIV3				0x0
#define RCC_CFGR0_ADCPRE_APB2_DIV4				0x1
#define RCC_CFGR0_ADCPRE_AHB_DIV5				0x1
#define RCC_CFGR0_ADCPRE_APB2_DIV6				0x2
#define RCC_CFGR0_ADCPRE_AHB_DIV7				0x2
/**@}*/

#define RCC_CFGR0_PPRE2_SHIFT					11
#define RCC_CFGR0_PPRE2_MASK					(0x7 << RCC_CFGR0_PPRE2_SHIFT)

#define RCC_CFGR0_PPRE1_SHIFT					8
#define RCC_CFGR0_PPRE1_MASK					(0x7 << RCC_CFGR0_PPRE1_SHIFT)
/** @defgroup rcc_cfgr0_apbxpre RCC_CFGR0 APBx prescale factors
 * These can be used for both APB1 and APB2 prescaling
 * @{
 */
#define RCC_CFGR0_PPRE_NODIV					0x0
#define RCC_CFGR0_PPRE_DIV2						0x4
#define RCC_CFGR0_PPRE_DIV4						0x5
#define RCC_CFGR0_PPRE_DIV8						0x6
#define RCC_CFGR0_PPRE_DIV16					0x7
/**@}*/

/** @defgroup rcc_cfgr0_ahbpre HPRE: AHB prescaler
 * @{
 */
#define RCC_CFGR0_HPRE_NODIV					0x0
#define RCC_CFGR0_HPRE_DIV2						0x8
#define RCC_CFGR0_HPRE_DIV4						0x9
#define RCC_CFGR0_HPRE_DIV8						0xa
#define RCC_CFGR0_HPRE_DIV16					0xb
#define RCC_CFGR0_HPRE_DIV64					0xc
#define RCC_CFGR0_HPRE_DIV128					0xd
#define RCC_CFGR0_HPRE_DIV256					0xe
#define RCC_CFGR0_HPRE_DIV512					0xf
/**@}*/
/** @defgroup rcc_cfgr0_sws SWS: System clock switch status
 * @{
 */
#define RCC_CFGR0_SWS_SYSCLKSEL_HSI8CLK			0x0
#define RCC_CFGR0_SWS_SYSCLKSEL_HSECLK			0x1
#define RCC_CFGR0_SWS_SYSCLKSEL_PLLCLK			0x2

/**@}*/
/** @defgroup rcc_cfgr0_scs SW: System clock switch
 * @{
 */
#define RCC_CFGR0_SW_SYSCLKSEL_HSI8CLK			0x0
#define RCC_CFGR0_SW_SYSCLKSEL_HSECLK			0x1
#define RCC_CFGR0_SW_SYSCLKSEL_PLLCLK			0x2
/**@}*/

/** Older compatible definitions to ease migration
 *  rcc_cfgr0_deprecated RCC_CFGR Deprecated dividers
 *  Use _CFGR_xPRE_DIVn form instead, across all families
 *
TODO delete this?
#define RCC_CFGR0_ADCPRE_PCLK2_DIV2		0x0
#define RCC_CFGR0_ADCPRE_PCLK2_DIV4		0x1
#define RCC_CFGR0_ADCPRE_PCLK2_DIV6		0x2
#define RCC_CFGR0_ADCPRE_PCLK2_DIV8		0x3

#define RCC_CFGR0_PPRE2_HCLK_NODIV		0x0
#define RCC_CFGR0_PPRE2_HCLK_DIV2		0x4
#define RCC_CFGR_PPRE2_HCLK_DIV4		0x5
#define RCC_CFGR_PPRE2_HCLK_DIV8		0x6
#define RCC_CFGR_PPRE2_HCLK_DIV16		0x7

#define RCC_CFGR_PPRE1_HCLK_NODIV		0x0
#define RCC_CFGR_PPRE1_HCLK_DIV2		0x4
#define RCC_CFGR_PPRE1_HCLK_DIV4		0x5
#define RCC_CFGR_PPRE1_HCLK_DIV8		0x6
#define RCC_CFGR_PPRE1_HCLK_DIV16		0x7

#define RCC_CFGR_HPRE_SYSCLK_NODIV		0x0
#define RCC_CFGR_HPRE_SYSCLK_DIV2		0x8
#define RCC_CFGR_HPRE_SYSCLK_DIV4		0x9
#define RCC_CFGR_HPRE_SYSCLK_DIV8		0xa
#define RCC_CFGR_HPRE_SYSCLK_DIV16		0xb
#define RCC_CFGR_HPRE_SYSCLK_DIV64		0xc
#define RCC_CFGR_HPRE_SYSCLK_DIV128		0xd
#define RCC_CFGR_HPRE_SYSCLK_DIV256		0xe
#define RCC_CFGR_HPRE_SYSCLK_DIV512		0xf
*/

/* RCC_CIR values */

/* Clock security system interrupt clear bit */
#define RCC_CIR_CSSC					(1 << 23)

/* OSC ready interrupt clear bits */
#define RCC_CIR_HSI28RDYC				(1 << 21)
#define RCC_CIR_PLLRDYC					(1 << 20)
#define RCC_CIR_HSERDYC					(1 << 19)
#define RCC_CIR_HSI8RDYC				(1 << 18)
#define RCC_CIR_LSERDYC					(1 << 17)
#define RCC_CIR_LSIRDYC					(1 << 16)

/* OSC ready interrupt enable bits */
#define RCC_CIR_HSI28RDYIE				(1 << 13)
#define RCC_CIR_PLLRDYIE				(1 << 12)
#define RCC_CIR_HSERDYIE				(1 << 11)
#define RCC_CIR_HSI8RDYIE				(1 << 10)
#define RCC_CIR_LSERDYIE				(1 << 9)
#define RCC_CIR_LSIRDYIE				(1 << 8)

/* Clock security system interrupt flag bit */
#define RCC_CIR_CSSF					(1 << 7)

/* OSC ready interrupt flag bits */
#define RCC_CIR_HSI28RDYF				(1 << 5)
#define RCC_CIR_PLLRDYF					(1 << 4)
#define RCC_CIR_HSERDYF					(1 << 3)
#define RCC_CIR_HSI8RDYF				(1 << 2)
#define RCC_CIR_LSERDYF					(1 << 1)
#define RCC_CIR_LSIRDYF					(1 << 0)

/** @defgroup rcc_apb2rstr_rst RCC_APB2RSTR reset values values
@{*/
#define RCC_APB2RSTR_TIM16RST			(1 << 18)
#define RCC_APB2RSTR_TIM15RST			(1 << 17)
#define RCC_APB2RSTR_TIM14RST			(1 << 16)
#define RCC_APB2RSTR_USART0RST			(1 << 14)
#define RCC_APB2RSTR_SPI0RST			(1 << 12)
#define RCC_APB2RSTR_TIM0RST			(1 << 11)
#define RCC_APB2RSTR_ADCRST				(1 << 9)
#define RCC_APB2RSTR_SYSCFGRST			(1 << 0)
/**@}*/

/** @defgroup rcc_apb1rstr_rst RCC_APB1RSTR reset values values
@{*/
#define RCC_APB1RSTR_PWRRST			(1 << 28)
#define RCC_APB1RSTR_I2C1RST			(1 << 22)
#define RCC_APB1RSTR_I2C0RST			(1 << 21)
#define RCC_APB1RSTR_USART1RST			(1 << 17)
#define RCC_APB1RSTR_SPI1RST			(1 << 14)
#define RCC_APB1RSTR_WWDGRST			(1 << 11)
#define RCC_APB1RSTR_TIM13RST			(1 << 8)
#define RCC_APB1RSTR_TIM5RST			(1 << 4)
#define RCC_APB1RSTR_TIM2RST			(1 << 1)
/**@}*/

/** @defgroup rcc_ahbenr_en RCC_AHBENR enable values
@{*/
#define RCC_AHBENR_GPIOFEN			(1 << 22)
#define RCC_AHBENR_GPIOCEN			(1 << 19)
#define RCC_AHBENR_GPIOBEN			(1 << 18)
#define RCC_AHBENR_GPIOAEN			(1 << 17)
#define RCC_AHBENR_CRCEN			(1 << 6)
#define RCC_AHBENR_FLTFEN			(1 << 4)
#define RCC_AHBENR_SRAMEN			(1 << 2)
#define RCC_AHBENR_DMAEN			(1 << 0)
/**@}*/

/** @defgroup rcc_apb2enr_en RCC_APB2ENR enable values
@{*/
#define RCC_APB2ENR_DBGEN			(1 << 22)
#define RCC_APB2ENR_TIM16EN			(1 << 18)
#define RCC_APB2ENR_TIM15EN			(1 << 17)
#define RCC_APB2ENR_TIM14EN			(1 << 16)
#define RCC_APB2ENR_USART0EN			(1 << 14)
#define RCC_APB2ENR_SPI0EN			(1 << 12)
#define RCC_APB2ENR_TIM0EN			(1 << 11)
#define RCC_APB2ENR_ADCEN			(1 << 9)
#define RCC_APB2ENR_SYSCFGCOMPEN		(1 << 0)
/**@}*/

/** @defgroup rcc_apb1enr_en RCC_APB1ENR enable values
@{*/
#define RCC_APB1ENR_PWREN			(1 << 28)
#define RCC_APB1ENR_I2C1EN			(1 << 22)
#define RCC_APB1ENR_I2C0EN			(1 << 21)
#define RCC_APB1ENR_USART1EN			(1 << 17)
#define RCC_APB1ENR_SPI1EN			(1 << 14)
#define RCC_APB1ENR_WWDGEN			(1 << 11)
#define RCC_APB1ENR_TIM13EN			(1 << 8)
#define RCC_APB1ENR_TIM5EN			(1 << 4)
#define RCC_APB1ENR_TIM2EN			(1 << 1)
/**@}*/

/* RCC_BDCR values */

#define RCC_BDCR_BDRST				(1 << 16)
#define RCC_BDCR_RTCEN				(1 << 15)

#define RCC_BDCR_RTCSEL_SHIFT		8
#define RCC_BDCR_RTCSEL_MASK		(0x3 << RCC_BDCR_RTCSEL_SHIFT)

/** @defgroup rcc_bdcr_rtcsel RCC_BDCR RTCSEL values
@{*/
#define RCC_BDCR_RTCSEL_NONE		0
#define RCC_BDCR_RTCSEL_LSE			1
#define RCC_BDCR_RTCSEL_LSI			2
#define RCC_BDCR_RTCSEL_HSE_DIV32	3
/**@}*/

#define RCC_BDCR_LSEDRIVE_SHIFT		3
#define RCC_BDCR_LSEDRIVE_MASK		(0x3 << RCC_BDCR_LSEDRIVE_SHIFT)

/** @defgroup rcc_bdcr_lsedrive RCC_BDCR LSEDRIVE / LXTALDRI values
@{*/
#define RCC_BDCR_LSEDRIVE_LOW		0
#define RCC_BDCR_LSEDRIVE_MEDLOW	1
#define RCC_BDCR_LSEDRIVE_MEDHIGH	2
#define RCC_BDCR_LSEDRIVE_HIGH		3
/**@}*/

#define RCC_BDCR_LSEBYP				(1 << 2)
#define RCC_BDCR_LSERDY				(1 << 1)
#define RCC_BDCR_LSEON				(1 << 0)

/* RCC_CSR values */

#define RCC_CSR_LPWRRSTF			(1 << 31)
#define RCC_CSR_WWDGRSTF			(1 << 30)
#define RCC_CSR_IWDGRSTF			(1 << 29)
#define RCC_CSR_SFTRSTF				(1 << 28)
#define RCC_CSR_PORRSTF				(1 << 27)
#define RCC_CSR_PINRSTF				(1 << 26)
#define RCC_CSR_RMVF				(1 << 24)
#define RCC_CSR_V12RSTF				(1 << 23)
#define RCC_CSR_LSIRDY				(1 << 1)
#define RCC_CSR_LSION				(1 << 0)

/** @defgroup rcc_ahbrstr_rst RCC_AHBRSTR reset values values
@{*/
#define RCC_AHBRSTR_GPIOFRST			(1 << 22)
#define RCC_AHBRSTR_GPIOCRST			(1 << 19)
#define RCC_AHBRSTR_GPIOBRST			(1 << 18)
#define RCC_AHBRSTR_GPIOARST			(1 << 17)
/**@}*/

/* RCC_CFGR1 values */

#define RCC_CFGR1_PREDIV_MASK			0xf
#define RCC_CFGR1_PREDIV_NODIV			0x0
#define RCC_CFGR1_PREDIV_DIV2			0x1
#define RCC_CFGR1_PREDIV_DIV3			0x2
#define RCC_CFGR1_PREDIV_DIV4			0x3
#define RCC_CFGR1_PREDIV_DIV5			0x4
#define RCC_CFGR1_PREDIV_DIV6			0x5
#define RCC_CFGR1_PREDIV_DIV7			0x6
#define RCC_CFGR1_PREDIV_DIV8			0x7
#define RCC_CFGR1_PREDIV_DIV9			0x8
#define RCC_CFGR1_PREDIV_DIV10			0x9
#define RCC_CFGR1_PREDIV_DIV11			0xa
#define RCC_CFGR1_PREDIV_DIV12			0xb
#define RCC_CFGR1_PREDIV_DIV13			0xc
#define RCC_CFGR1_PREDIV_DIV14			0xd
#define RCC_CFGR1_PREDIV_DIV15			0xe
#define RCC_CFGR1_PREDIV_DIV16			0xf

/* RCC_CFGR2 values */

#define RCC_CFGR2_ADCCLK_SHIFT			31
/** @defgroup rcc_cfgr0_adcclk ADCCLK: ADC clock source
 * @{
 */
#define RCC_CFGR2_ADCCLK_APB2			0
#define RCC_CFGR2_ADCCLK_AHB			1
/**@}*/

#define RCC_CFGR2_ADCSW				(1 << 8)

#define RCC_CFGR2_USART0SW_SHIFT		0
#define RCC_CFGR2_USART0SW				(0x3 << RCC_CFGR2_USART0SW_SHIFT)
#define RCC_CFGR2_USART0SW_PCLK			(0 << RCC_CFGR2_USART0SW_SHIFT)
#define RCC_CFGR2_USART0SW_SYSCLK		(1 << RCC_CFGR2_USART0SW_SHIFT)
#define RCC_CFGR2_USART0SW_LSE			(2 << RCC_CFGR2_USART0SW_SHIFT)
#define RCC_CFGR2_USART0SW_HSI			(3 << RCC_CFGR2_USART0SW_SHIFT)

/* RCC_CR1 values */

#define RCC_CR1_HSI28CAL_SHIFT			8
#define RCC_CR1_HSI28CAL_MASK			(0xff << RCC_CR1_HSI28CAL_SHIFT)
#define RCC_CR1_HSI28ADJ_SHIFT			3
#define RCC_CR1_HSI28ADJ_MASK			(0x1f << RCC_CR1_HSI28ADJ_SHIFT)
#define RCC_CR1_HSI28RDY				(1 << 1)
#define RCC_CR1_HSI28ON					(1 << 0)

/* Variable definitions */
extern uint32_t rcc_ahb_frequency;
extern uint32_t rcc_apb1_frequency;
extern uint32_t rcc_apb2_frequency;

/* Function prototypes */

enum rcc_clock_hsi {
	RCC_CLOCK_HSI_48MHZ,
	RCC_CLOCK_HSI_64MHZ,
	RCC_CLOCK_HSI_END
};

struct rcc_clock_scale {
	uint16_t pllmul;
	uint8_t hpre;
	uint8_t ppre1;
	uint8_t ppre2;
	uint8_t adcpre;
	uint8_t adcclk;
	uint8_t usbpre; /* Only valid if HSE used */
	bool use_hse; /* PLL source is HSE if set, HSI/2 if unset */
	uint8_t pll_hse_prediv; /* Only valid if HSE used */
	uint32_t ahb_frequency;
	uint32_t apb1_frequency;
	uint32_t apb2_frequency;
};

extern const struct rcc_clock_scale rcc_hsi_configs[RCC_CLOCK_HSI_END];

enum rcc_osc {
	RCC_PLL, RCC_HSE, RCC_HSI8, RCC_HSI28, RCC_LSE, RCC_LSI
};

#define _REG_BIT(base, bit)		(((base) << 5) + (bit))

/* V = value line F100
 * N = standard line F101, F102, F103
 * C = communication line F105, F107
 */
enum rcc_periph_clken {

	/* AHB peripherals */
	RCC_DMA		= _REG_BIT(0x14, 0),
	RCC_SRAM	= _REG_BIT(0x14, 2),
	RCC_FLTF	= _REG_BIT(0x14, 4),
	RCC_CRC		= _REG_BIT(0x14, 6),
	RCC_GPIOA	= _REG_BIT(0x14, 17),
	RCC_GPIOB	= _REG_BIT(0x14, 18),
	RCC_GPIOC	= _REG_BIT(0x14, 19),
	RCC_GPIOF	= _REG_BIT(0x14, 22),

	/* APB2 peripherals */
	RCC_SYSCFG_COMP	= _REG_BIT(0x18, 0),
	RCC_ADC		= _REG_BIT(0x18, 9),
	RCC_TIM0	= _REG_BIT(0x18, 11),
	RCC_SPI0	= _REG_BIT(0x18, 12),
	RCC_USART0	= _REG_BIT(0x18, 14),
	RCC_TIM14	= _REG_BIT(0x18, 16),
	RCC_TIM15	= _REG_BIT(0x18, 17),
	RCC_TIM16	= _REG_BIT(0x18, 18),
	RCC_DBG		= _REG_BIT(0x18, 18),

	/* APB1 peripherals */
	RCC_TIM2	= _REG_BIT(0x1C, 1),
	RCC_TIM5	= _REG_BIT(0x1C, 4),
	RCC_TIM13	= _REG_BIT(0x1C, 8),
	RCC_WWDG	= _REG_BIT(0x1C, 11),
	RCC_SPI1	= _REG_BIT(0x1C, 14),
	RCC_USART1	= _REG_BIT(0x1C, 17),
	RCC_I2C0	= _REG_BIT(0x1C, 21),
	RCC_I2C1	= _REG_BIT(0x1C, 22),
	RCC_PWR		= _REG_BIT(0x1C, 28),
};

enum rcc_periph_rst {

	/* Advanced peripherals */
	RST_BACKUPDOMAIN = _REG_BIT(0x20, 16),/* BDCR[16] */

	/* AHB peripherals */
	RST_GPIOA	= _REG_BIT(0x28, 17),
	RST_GPIOB	= _REG_BIT(0x28, 18),
	RST_GPIOC	= _REG_BIT(0x28, 19),
	RST_GPIOF	= _REG_BIT(0x28, 22),

	/* APB2 peripherals */
	RST_SYSCFG	= _REG_BIT(0x0C, 0),
	RST_ADC		= _REG_BIT(0x0C, 9),
	RST_TIM0	= _REG_BIT(0x0C, 11),
	RST_SPI0	= _REG_BIT(0x0C, 12),
	RST_USART0	= _REG_BIT(0x0C, 14),
	RST_TIM14	= _REG_BIT(0x0C, 16),
	RST_TIM15	= _REG_BIT(0x0C, 17),
	RST_TIM16	= _REG_BIT(0x0C, 18),

	/* APB1 peripherals */
	RST_TIM2	= _REG_BIT(0x10, 1),
	RST_TIM5	= _REG_BIT(0x10, 4),
	RST_TIM13	= _REG_BIT(0x10, 8),
	RST_WWDG	= _REG_BIT(0x10, 11),
	RST_SPI1	= _REG_BIT(0x10, 14),
	RST_USART1	= _REG_BIT(0x10, 17),
	RST_I2C0	= _REG_BIT(0x10, 21),
	RST_I2C1	= _REG_BIT(0x10, 22),
	RST_PWR		= _REG_BIT(0x10, 28),
};

#include <libopencm3/stm32/common/rcc_common_all.h>

BEGIN_DECLS

void rcc_osc_ready_int_clear(enum rcc_osc osc);
void rcc_osc_ready_int_enable(enum rcc_osc osc);
void rcc_osc_ready_int_disable(enum rcc_osc osc);
int rcc_osc_ready_int_flag(enum rcc_osc osc);
void rcc_css_int_clear(void);
int rcc_css_int_flag(void);
void rcc_osc_on(enum rcc_osc osc);
void rcc_osc_off(enum rcc_osc osc);
void rcc_css_enable(void);
void rcc_css_disable(void);
void rcc_set_sysclk_source(uint32_t clk);
void rcc_set_pll_multiplication_factor(uint32_t mul);
void rcc_set_pll_source(uint32_t pllsrc);
void rcc_set_pllxtpre(uint32_t pllxtpre);
uint32_t rcc_rtc_clock_enabled_flag(void);
void rcc_enable_rtc_clock(void);
void rcc_set_rtc_clock_source(enum rcc_osc clock_source);
void rcc_set_adc_clock(uint8_t adcsrc, uint8_t adcpre);
void rcc_set_ppre2(uint32_t ppre1);
void rcc_set_ppre1(uint32_t ppre1);
void rcc_set_hpre(uint32_t hpre);
void rcc_set_usbpre(uint32_t usbpre);
void rcc_set_prediv(uint32_t prediv);
uint32_t rcc_system_clock_source(void);
void rcc_clock_setup_pll(const struct rcc_clock_scale *clock);
void rcc_backupdomain_reset(void);

END_DECLS

#endif
/**@}*/

