/** @defgroup rcc_file RCC peripheral API

@ingroup peripheral_apis

@brief <b>libopencm3 GD32E23 Reset and Clock Control</b>

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2022 Vlad Logyin <vladlogyin@gmail.com>
@author @htmlonly &copy; @endhtmlonly 2009
Federico Ruiz-Ugalde \<memeruiz at gmail dot com\>
@author @htmlonly &copy; @endhtmlonly 2009 Uwe Hermann <uwe@hermann-uwe.de>
@author @htmlonly &copy; @endhtmlonly 2010 Thomas Otto <tommi@viadmin.org>

@date 10 December 2022

This library supports the Reset and Clock Control System in the GD32E23
series of ARM Cortex Microcontrollers by GigaDevice.

Clock settings and resets for many peripherals are given here rather than in
the corresponding peripheral library.

The library also provides a number of common configurations for the processor
system clock. Not all possible configurations are included.

LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2022 Vlad Logyin <vladlogyin@gmail.com>
 * Copyright (C) 2019 Icenowy Zheng <icenowy@aosc.io>
 * Copyright (C) 2009 Federico Ruiz-Ugalde <memeruiz at gmail dot com>
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
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

#include <libopencm3/cm3/assert.h>
#include <libopencm3/gd32/rcc.h>
#include <libopencm3/gd32/flash.h>

/** Set the default clock frequencies */
uint32_t rcc_apb1_frequency = 8000000;
uint32_t rcc_apb2_frequency = 8000000;
uint32_t rcc_ahb_frequency = 8000000;
uint32_t rcc_sys_frequency = 8000000;

const struct rcc_clock_scale rcc_hsi8_configs[] = {
	{
		.pll_src=0,
		.pll_mul=0,
		.sysclk_src=RCC_CFGR0_SWS_SYSCLKSEL_HSI8CLK,
		.pre_ahb=RCC_CFGR0_HPRE_DIV2,
		.pre_apb1=RCC_CFGR0_PPRE_NODIV,
		.pre_apb2=RCC_CFGR0_PPRE_NODIV,
		.pre_hse=0,
		.rtc_src=0,
		.freq_ahb=4E3,
		.freq_apb1=4E3,
		.freq_apb2=4E3,
		.freq_sys=72E3,
		.flash_ws=FLASH_ACR_LATENCY_0WS
	},
	{
		.pll_src=RCC_CFGR0_PLLSRC_HSI8_CLK_DIV2,
		.pll_mul=RCC_CFGR0_PLLMUL_PLL_CLK_MUL18,
		.sysclk_src=RCC_CFGR0_SWS_SYSCLKSEL_PLLCLK,
		.pre_ahb=RCC_CFGR0_HPRE_NODIV,
		.pre_apb1=RCC_CFGR0_PPRE_NODIV,
		.pre_apb2=RCC_CFGR0_PPRE_NODIV,
		.pre_hse=0,
		.rtc_src=0,
		.freq_ahb=72E3,
		.freq_apb1=72E3,
		.freq_apb2=72E3,
		.freq_sys=72E3,
		.flash_ws=FLASH_ACR_LATENCY_2WS
	},
};


/** @brief RCC Clear the Oscillator Ready Interrupt Flag

Clear the interrupt flag that was set when a clock oscillator became ready to
use.

@param[in] osc Oscillator ID
*/

void rcc_osc_ready_int_clear(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		RCC_CIR |= RCC_CIR_PLLRDYC;
		break;
	case RCC_HSE:
		RCC_CIR |= RCC_CIR_HSERDYC;
		break;
	case RCC_HSI8:
		RCC_CIR |= RCC_CIR_HSI8RDYC;
		break;
	case RCC_HSI28:
		RCC_CIR |= RCC_CIR_HSI28RDYC;
		break;
	case RCC_LSE:
		RCC_CIR |= RCC_CIR_LSERDYC;
		break;
	case RCC_LSI:
		RCC_CIR |= RCC_CIR_LSIRDYC;
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Enable the Oscillator Ready Interrupt

@param[in] osc Oscillator ID
*/

void rcc_osc_ready_int_enable(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		RCC_CIR |= RCC_CIR_PLLRDYIE;
		break;
	case RCC_HSE:
		RCC_CIR |= RCC_CIR_HSERDYIE;
		break;
	case RCC_HSI8:
		RCC_CIR |= RCC_CIR_HSI8RDYIE;
		break;
	case RCC_HSI28:
		RCC_CIR |= RCC_CIR_HSI28RDYIE;
		break;
	case RCC_LSE:
		RCC_CIR |= RCC_CIR_LSERDYIE;
		break;
	case RCC_LSI:
		RCC_CIR |= RCC_CIR_LSIRDYIE;
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Disable the Oscillator Ready Interrupt

@param[in] osc Oscillator ID
*/

void rcc_osc_ready_int_disable(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		RCC_CIR &= ~RCC_CIR_PLLRDYIE;
		break;
	case RCC_HSE:
		RCC_CIR &= ~RCC_CIR_HSERDYIE;
		break;
	case RCC_HSI8:
		RCC_CIR &= ~RCC_CIR_HSI8RDYIE;
		break;
	case RCC_HSI28:
		RCC_CIR &= ~RCC_CIR_HSI28RDYIE;
		break;
	case RCC_LSE:
		RCC_CIR &= ~RCC_CIR_LSERDYIE;
		break;
	case RCC_LSI:
		RCC_CIR &= ~RCC_CIR_LSIRDYIE;
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Read the Oscillator Ready Interrupt Flag

@param[in] osc Oscillator ID
@returns int. Boolean value for flag set.
*/

int rcc_osc_ready_int_flag(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		return ((RCC_CIR & RCC_CIR_PLLRDYF) != 0);
		break;
	case RCC_HSE:
		return ((RCC_CIR & RCC_CIR_HSERDYF) != 0);
		break;
	case RCC_HSI8:
		return ((RCC_CIR & RCC_CIR_HSI8RDYF) != 0);
		break;
	case RCC_HSI28:
		return ((RCC_CIR & RCC_CIR_HSI28RDYF) != 0);
		break;
	case RCC_LSE:
		return ((RCC_CIR & RCC_CIR_LSERDYF) != 0);
		break;
	case RCC_LSI:
		return ((RCC_CIR & RCC_CIR_LSIRDYF) != 0);
		break;
	}

	cm3_assert_not_reached();
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Clear the Clock Security System Interrupt Flag

*/

void rcc_css_int_clear(void)
{
	RCC_CIR |= RCC_CIR_CSSC;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Read the Clock Security System Interrupt Flag

@returns int. Boolean value for flag set.
*/

int rcc_css_int_flag(void)
{
	return ((RCC_CIR & RCC_CIR_CSSF) != 0);
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Wait for Oscillator Ready.

@param[in] osc Oscillator ID
*/

void rcc_wait_for_osc_ready(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		while ((RCC_CR0 & RCC_CR0_PLLRDY) == 0);
		break;
	case RCC_HSE:
		while ((RCC_CR0 & RCC_CR0_HSERDY) == 0);
		break;
	case RCC_HSI8:
		while ((RCC_CR0 & RCC_CR0_HSI8RDY) == 0);
		break;
	case RCC_HSI28:
		while ((RCC_CR1 & RCC_CR1_HSI28RDY) == 0);
		break;
	case RCC_LSE:
		while ((RCC_BDCR & RCC_BDCR_LSERDY) == 0);
		break;
	case RCC_LSI:
		while ((RCC_CSR & RCC_CSR_LSIRDY) == 0);
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Turn on an Oscillator.

Enable an oscillator and power on. Each oscillator requires an amount of time
to settle to a usable state. Refer to datasheets for time delay information. A
status flag is available to indicate when the oscillator becomes ready (see
@ref rcc_osc_ready_int_flag and @ref rcc_wait_for_osc_ready).

@note The LSE clock is in the backup domain and cannot be enabled until the
backup domain write protection has been removed (see @ref
pwr_disable_backup_domain_write_protect).

@param[in] osc Oscillator ID
*/

void rcc_osc_on(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		RCC_CR0 |= RCC_CR0_PLLON;
		break;
	case RCC_HSE:
		RCC_CR0 |= RCC_CR0_HSEON;
		break;
	case RCC_HSI8:
		RCC_CR0 |= RCC_CR0_HSI8ON;
		break;
	case RCC_HSI28:
		RCC_CR1 |= RCC_CR1_HSI28ON;
		break;
	case RCC_LSE:
		RCC_BDCR |= RCC_BDCR_LSEON;
		break;
	case RCC_LSI:
		RCC_CSR |= RCC_CSR_LSION;
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Turn off an Oscillator.

Disable an oscillator and power off.

@note An oscillator cannot be turned off if it is selected as the system clock.
@note The LSE clock is in the backup domain and cannot be disabled until the
backup domain write protection has been removed (see
@ref pwr_disable_backup_domain_write_protect) or the backup domain has been
(see reset @ref rcc_backupdomain_reset).

@param[in] osc Oscillator ID
*/

void rcc_osc_off(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		RCC_CR0 &= ~RCC_CR0_PLLON;
		break;
	case RCC_HSE:
		RCC_CR0 &= ~RCC_CR0_HSEON;
		break;
	case RCC_HSI8:
		RCC_CR0 &= ~RCC_CR0_HSI8ON;
		break;
	case RCC_HSI28:
		RCC_CR1 &= ~RCC_CR1_HSI28ON;
		break;
	case RCC_LSE:
		RCC_BDCR &= ~RCC_BDCR_LSEON;
		break;
	case RCC_LSI:
		RCC_CSR &= ~RCC_CSR_LSION;
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Enable the Clock Security System.

*/

void rcc_css_enable(void)
{
	RCC_CR0 |= RCC_CR0_CSSON;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Disable the Clock Security System.

*/

void rcc_css_disable(void)
{
	RCC_CR0 &= ~RCC_CR0_CSSON;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the Source for the System Clock.

@param[in] clk System Clock Selection @ref rcc_cfgr_scs
*/

void rcc_set_sysclk_source(uint32_t clk)
{
	RCC_CFGR0 = (RCC_CFGR0 & ~RCC_CFGR0_SW_MASK) |
			(clk << RCC_CFGR0_SW_SHIFT);
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the PLL Multiplication Factor.

@note This only has effect when the PLL is disabled.

@param[in] mul PLL multiplication factor @ref rcc_cfgr_pmf
*/

void rcc_set_pll_multiplication_factor(uint32_t mul)
{
	RCC_CFGR0 = (RCC_CFGR0 & ~RCC_CFGR0_PLLMUL_MASK) |
			(mul << RCC_CFGR0_PLLMUL_SHIFT);
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the PLL Clock Source.

@note This only has effect when the PLL is disabled.

@param[in] pllsrc PLL clock source @ref rcc_cfgr_pcs
*/

void rcc_set_pll_source(uint32_t pllsrc)
{
	RCC_CFGR0 = (RCC_CFGR0 & ~RCC_CFGR0_PLLSRC) |
			(pllsrc << 16);
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the HSE Frequency Divider used as PLL Clock Source.

@note This only has effect when the PLL is disabled.

@param[in] pllxtpre HSE division factor @ref rcc_cfgr_hsepre
*/

void rcc_set_pllxtpre(uint32_t pllxtpre)
{
	RCC_CFGR0 = (RCC_CFGR0 & ~RCC_CFGR0_PLLXTPRE) |
			(pllxtpre << 17);
}

/*---------------------------------------------------------------------------*/
/** @brief RCC RTC Clock Enabled Flag

@returns uint32_t. Nonzero if the RTC Clock is enabled.
*/

uint32_t rcc_rtc_clock_enabled_flag(void)
{
	return RCC_BDCR & RCC_BDCR_RTCEN;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Enable the RTC clock

*/

void rcc_enable_rtc_clock(void)
{
	RCC_BDCR |= RCC_BDCR_RTCEN;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the Source for the RTC clock

@param[in] clock_source RTC clock source. Only HSE/32, LSE and LSI.
*/

void rcc_set_rtc_clock_source(enum rcc_osc clock_source)
{
	uint8_t clksel = RCC_BDCR_RTCSEL_NONE;
	switch (clock_source) {
	case RCC_LSE:
		clksel=RCC_BDCR_RTCSEL_LSE;
		break;
	case RCC_LSI:
		clksel=RCC_BDCR_RTCSEL_LSI;
		break;
	case RCC_HSE:
		clksel=RCC_BDCR_RTCSEL_HSE_DIV32;
		break;
	case RCC_PLL:
	case RCC_HSI8:
	case RCC_HSI28:
		/* Unusable clock sources, here to prevent warnings. */
		/* Turn off clock sources to RTC. */
		clksel=RCC_BDCR_RTCSEL_NONE;
		break;
	}
	/* Select the RTC clock source. */
	RCC_BDCR &= ~RCC_BDCR_RTCSEL_MASK;
	RCC_BDCR |= (clksel << RCC_BDCR_RTCSEL_SHIFT);
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Setup the A/D Clock

The ADC's have a common clock prescale setting.

@param[in] adcsrc Clock source taken from @ref rcc_cfgr0_adcclk
@param[in] adcpre Prescale divider taken from @ref rcc_cfgr_adcpre
*/

void rcc_set_adc_clock(uint8_t adcsrc, uint8_t adcpre)
{
	RCC_CFGR2 = (RCC_CFGR2 & ~(1<<RCC_CFGR2_ADCCLK_SHIFT)) |
				(adcsrc << RCC_CFGR2_ADCCLK_SHIFT);
	RCC_CFGR0 = (RCC_CFGR0 & ~RCC_CFGR0_ADCPRE_MASK) |
				(adcpre << RCC_CFGR0_ADCPRE_SHIFT);
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the APB2 Prescale Factor.

@note The APB2 clock frequency must not exceed 72MHz.

@param[in] ppre2 APB2 prescale factor @ref rcc_cfgr0_apbxpre
*/

void rcc_set_ppre2(uint32_t ppre2)
{
	RCC_CFGR0 = (RCC_CFGR0 & ~RCC_CFGR0_PPRE2_MASK) |
				(ppre2 << RCC_CFGR0_PPRE2_SHIFT);
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the APB1 Prescale Factor.

@note The APB1 clock frequency must not exceed 72MHz.

@param[in] ppre1 APB1 prescale factor @ref rcc_cfgr0_apbxpre
*/

void rcc_set_ppre1(uint32_t ppre1)
{
	RCC_CFGR0 = (RCC_CFGR0 & ~RCC_CFGR0_PPRE1_MASK) |
			(ppre1 << RCC_CFGR0_PPRE1_SHIFT);

}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the AHB Prescale Factor.

@note The AHB clock frequency must not exceed 72MHz.

@param[in] hpre AHB prescale factor @ref rcc_cfgr_ahbpre
*/

void rcc_set_hpre(uint32_t hpre)
{
	RCC_CFGR0 = (RCC_CFGR0 & ~RCC_CFGR0_HPRE_MASK) |
			(hpre << RCC_CFGR0_HPRE_SHIFT);

}


void rcc_set_prediv(uint32_t prediv)
{
	RCC_CFGR1 = (RCC_CFGR1 & ~RCC_CFGR1_PREDIV_MASK) | prediv;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Get the System Clock Source.

@returns Unsigned int32. System clock source. See @ref rcc_cfgr0_sws
*/

uint32_t rcc_system_clock_source(void)
{
	/* Return the clock source which is used as system clock. */
	return (RCC_CFGR0 & RCC_CFGR0_SWS_MASK) >> RCC_CFGR0_SWS_SHIFT;
}

/*---------------------------------------------------------------------------*/
/*
 * These functions are setting up the whole clock system for the most common
 * input clock and output clock configurations.
 */
/*---------------------------------------------------------------------------*/
/**
 * Setup clocks to run from PLL.
 * The arguments provide the pll source, multipliers, dividers, all that's
 * needed to establish a system clock.
 * @param clock clock information structure
 */
void rcc_clock_setup_pll(const struct rcc_clock_scale *clock)
{

	/*
	 * Set prescalers for AHB, ADC, APB1, APB2 and USB.
	 * Do this before touching the PLL (TODO: why?).
	 */
	rcc_set_hpre(clock->pre_ahb);
	rcc_set_ppre1(clock->pre_apb1);
	rcc_set_ppre2(clock->pre_apb2);

	flash_set_ws(clock->flash_ws);

	enum rcc_osc sysclk = clock->sysclk_src == RCC_CFGR0_SW_SYSCLKSEL_HSECLK ? RCC_HSE
	: (clock->sysclk_src == RCC_CFGR0_SW_SYSCLKSEL_PLLCLK ? RCC_PLL : RCC_HSI8);

	if(sysclk == RCC_PLL)
	{

		enum rcc_osc pllsrc = clock->pll_src==RCC_CFGR0_PLLSRC_HSE_CLK?RCC_HSE:RCC_HSI8;

		/* Turn on PLL input clock */
		rcc_osc_on(pllsrc);
		rcc_wait_for_osc_ready(pllsrc);

		if(pllsrc==RCC_HSE)
			rcc_set_prediv(clock->pre_hse);

		/* Set the PLL multiplication factor. */
		rcc_set_pll_multiplication_factor(clock->pll_mul);
		rcc_set_pll_source(clock->pll_src);

	}


	/* Turn on sysclk input */
	rcc_osc_on(sysclk);
	rcc_wait_for_osc_ready(sysclk);
	/* Change over */
	rcc_set_sysclk_source(clock->sysclk_src);

	/* Set the peripheral clock frequencies used */
	rcc_ahb_frequency = clock->freq_ahb*1E3;
	rcc_apb1_frequency = clock->freq_apb1*1E3;
	rcc_apb2_frequency = clock->freq_apb2*1E3;
	rcc_sys_frequency = clock->freq_sys*1E3;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Reset the Backup Domain

The backup domain registers are reset to disable RTC controls and clear user
data.
*/

void rcc_backupdomain_reset(void)
{
	/* Set the backup domain software reset. */
	RCC_BDCR |= RCC_BDCR_BDRST;

	/* Clear the backup domain software reset. */
	RCC_BDCR &= ~RCC_BDCR_BDRST;
}

/*---------------------------------------------------------------------------*/
/** @brief Set the USART0 clock source
*
* @param usart0_sel periphral clock source @ref rcc_cfgr2_usart0sw
*/

void rcc_set_usart0_sel(uint32_t usart0_sel)
{
	RCC_CFGR2 &= ~RCC_CFGR2_USART0SW_MASK;
	RCC_CFGR2 |= (usart0_sel << RCC_CFGR2_USART0SW_SHIFT);
}

/**@}*/

