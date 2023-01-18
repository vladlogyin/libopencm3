/** @defgroup adc_defines ADC Defines

@brief <b>Defined Constants and Types for the GD32E23 Analog to Digital
Converter</b>

@ingroup GD32E23_defines

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2023
Vlad Logyin <vladlogyin@gmail.com>

@date 10 January 2023

LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2023 Vlad Logyin <vladlogyin@gmail.com>
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

#ifndef LIBOPENCM3_ADC_H
#define LIBOPENCM3_ADC_H

/* ADC port base addresses (for convenience) */
/****************************************************************************/
/** @defgroup adc_reg_base ADC register base addresses
@ingroup adc_defines

@{*/
#define ADC0					ADC_BASE
#define ADC						ADC_BASE
/**@}*/

#define ADC1_BASE ADC_BASE

#include <libopencm3/stm32/common/adc_common_v1.h>

/* --- Convenience macros -------------------------------------------------- */

/* ADC injected channel data offset register x (ADC_JOFRx) (x=1..4) */
#define ADC_JOFR1(block)		MMIO32((block) + 0x14)
#define ADC_JOFR2(block)		MMIO32((block) + 0x18)
#define ADC_JOFR3(block)		MMIO32((block) + 0x1c)
#define ADC_JOFR4(block)		MMIO32((block) + 0x20)

/* ADC watchdog high threshold register (ADC_HTR) */
#define ADC_HTR(block)			MMIO32((block) + 0x24)

/* ADC watchdog low threshold register (ADC_LTR) */
#define ADC_LTR(block)			MMIO32((block) + 0x28)

/* ADC regular sequence register 1 (ADC_SQR1) */
#define ADC_SQR1(block)			MMIO32((block) + 0x2c)

/* ADC regular sequence register 2 (ADC_SQR2) */
#define ADC_SQR2(block)			MMIO32((block) + 0x30)

/* ADC regular sequence register 3 (ADC_SQR3) */
#define ADC_SQR3(block)			MMIO32((block) + 0x34)

/* ADC injected sequence register (ADC_JSQR) */
#define ADC_JSQR(block)			MMIO32((block) + 0x38)

/* ADC injected data register x (ADC_JDRx) (x=1..4) */
#define ADC_JDR1(block)			MMIO32((block) + 0x3c)
#define ADC_JDR2(block)			MMIO32((block) + 0x40)
#define ADC_JDR3(block)			MMIO32((block) + 0x44)
#define ADC_JDR4(block)			MMIO32((block) + 0x48)

/* ADC regular data register (ADC_DR) */
#define ADC_DR(block)			MMIO32((block) + 0x4c)

/* ADC Oversampling control register (ADC_OSCR) */
#define ADC_OSCR(block)			MMIO32((block) + 0x80)


/* --- ADC_CR1 values ------------------------------------------------------ */

#define ADC_CR1_AWDCH_MAX		17
#define ADC_CR1_DRES_SHIFT		24

/** @defgroup adc_resolution ADC resolution selection
@ingroup adc_defines

@{*/
#define ADC_CR1_DRES_MASK		(0x3 << ADC_CR1_DRES_SHIFT)
#define ADC_CR1_DRES_12bit		(0x0 << ADC_CR1_DRES_SHIFT)
#define ADC_CR1_DRES_10bit		(0x1 << ADC_CR1_DRES_SHIFT)
#define ADC_CR1_DRES_8bit		(0x2 << ADC_CR1_DRES_SHIFT)
#define ADC_CR1_DRES_6bit		(0x3 << ADC_CR1_DRES_SHIFT)
/**@}*/

/* --- ADC_CR2 values ------------------------------------------------------ */

/* TSVREFE: */ /** Temperature sensor and V_REFINT enable. (ADC1 only!) */
#define ADC_CR2_TSVREFE			(1 << 23)

/* SWSTART: */ /** Start conversion of regular channels. */
#define ADC_CR2_SWSTART			(1 << 22)

/* JSWSTART: */ /** Start conversion of injected channels. */
#define ADC_CR2_JSWSTART		(1 << 21)

/* EXTTRIG: */ /** External trigger conversion mode for regular channels. */
#define ADC_CR2_EXTTRIG			(1 << 20)

/* EXTSEL[2:0]: External event select for regular group. */
/****************************************************************************/
/* ADC_CR2 EXTSEL[2:0] ADC Trigger Identifier */
/** @defgroup adc_trigger_regular_12 ADC Trigger Identifier
@ingroup adc_defines

@{*/
/** Timer 0 Compare Output 0 */
#define ADC_CR2_EXTSEL_TIM0_CC0		(0x0 << 17)
/** Timer 0 Compare Output 1 */
#define ADC_CR2_EXTSEL_TIM0_CC1		(0x1 << 17)
/** Timer 0 Compare Output 2 */
#define ADC_CR2_EXTSEL_TIM0_CC2		(0x2 << 17)
/** Timer 1 Compare Output 1 */
#define ADC_CR2_EXTSEL_TIM1_CC1		(0x3 << 17)
/** Timer 2 Trigger Output */
#define ADC_CR2_EXTSEL_TIM2_TRGO	(0x4 << 17)
/** Timer 14 Compare Output 0 */
#define ADC_CR2_EXTSEL_TIM14_CC0	(0x5 << 17)
/** External Interrupt 11 */
#define ADC_CR2_EXTSEL_EXTI11		(0x6 << 17)
/** Software Trigger */
#define ADC_CR2_EXTSEL_SWSTART		(0x7 << 17)
/**@}*/

#define ADC_CR2_EXTSEL_MASK		(0x7 << 17)
#define ADC_CR2_EXTSEL_SHIFT		17

/* Note: Bit 16 is reserved, must be kept at reset value. */

/* JEXTTRIG: External trigger conversion mode for injected channels. */
#define ADC_CR2_JEXTTRIG		(1 << 15)


#define ADC_CR2_JEXTSEL_SHIFT		12
#define ADC_CR2_JEXTSEL_MASK		(0x7 << 12)

/* JEXTSEL[2:0]: External event selection for injected group. */
/****************************************************************************/
/* ADC_CR2 JEXTSEL[2:0] ADC Injected Trigger Identifier*/
/** @defgroup adc_trigger_injected_12 ADC Injected Trigger Identifier
@ingroup adc_defines

@{*/
/** Timer 0 Trigger Output */
#define ADC_CR2_JEXTSEL_TIM0_TRGO	(0x0 << 12)
/** Timer 0 Compare Output 3 */
#define ADC_CR2_JEXTSEL_TIM0_CC3	(0x1 << 12)
/***** reserved 0x2 ****/
/***** reserved 0x3 ****/
/** Timer 2 Compare Output 3 */
#define ADC_CR2_JEXTSEL_TIM2_CC3	(0x4 << 12)
/** Timer 14 Trigger Output */
#define ADC_CR2_JEXTSEL_TIM14_TRGO	(0x5 << 12)
/** External Interrupt 15 */
#define ADC_CR2_JEXTSEL_EXTI15		(0x6 << 12)
/** Injected Software Trigger */
#define ADC_CR2_JEXTSEL_JSWSTART	(0x7 << 12) /* Software start. */
/**@}*/


/* ALIGN: Data alignment. */
#define ADC_CR2_ALIGN_RIGHT             (0 << 11)
#define ADC_CR2_ALIGN_LEFT              (1 << 11)
#define ADC_CR2_ALIGN			(1 << 11)

/* Note: Bits [10:9] are reserved and must be kept at reset value. */

/* DMA: Direct memory access mode. */
#define ADC_CR2_DMA			(1 << 8)

/* Note: Bits [7:4] are reserved and must be kept at reset value. */

/* RSTCAL: Reset calibration. */
#define ADC_CR2_RSTCAL			(1 << 3)

/* CAL: A/D Calibration. */
#define ADC_CR2_CAL			(1 << 2)

/* CONT: Continuous conversion. */
#define ADC_CR2_CONT			(1 << 1)

/* ADON: A/D converter On/Off. */
/* Note: If any other bit in this register apart from ADON is changed at the
 * same time, then conversion is not triggered. This is to prevent triggering
 * an erroneous conversion.
 * Conclusion: Must be separately written.
 */
#define ADC_CR2_ADON			(1 << 0)




/* --- ADC_SMPRx values --------------------------------------------------- */
/****************************************************************************/
/* ADC_SMPRG ADC Sample Time Selection for Channels */
/** @defgroup adc_sample_rg ADC Sample Time Selection for All Channels
@ingroup adc_defines

@{*/
#define ADC_SMPR_SMP_1DOT5CYC		0x0
#define ADC_SMPR_SMP_7DOT5CYC		0x1
#define ADC_SMPR_SMP_13DOT5CYC		0x2
#define ADC_SMPR_SMP_28DOT5CYC		0x3
#define ADC_SMPR_SMP_41DOT5CYC		0x4
#define ADC_SMPR_SMP_55DOT5CYC		0x5
#define ADC_SMPR_SMP_71DOT5CYC		0x6
#define ADC_SMPR_SMP_239DOT5CYC		0x7
/**@}*/

#define ADC_SQR_MAX_CHANNELS_REGULAR	16


/* --- ADC_JDRx, ADC_DR values --------------------------------------------- */

#define ADC_JDATA_LSB			0
#define ADC_DATA_LSB			0
#define ADC_ADC2DATA_LSB		16 /* ADC1 only (dual mode) */
#define ADC_JDATA_MSK			(0xffff << ADC_JDATA_LSB)
#define ADC_DATA_MSK			(0xffff << ADC_DA)
					/* ADC1 only (dual mode) */

/** @defgroup adc_channel ADC Channel Numbers
 * @ingroup adc_defines
 *
 *@{*/
#define ADC_CHANNEL_TEMP	16
#define ADC_CHANNEL_VREF	17
/**@}*/

/* --- ADC_JDRx, ADC_DR values --------------------------------------------- */

#define ADC_OSCR_TOS_EACH				(0x0<<9)
#define ADC_OSCR_TOS_ONCE				(0x1<<9)

#define ADC_OSCR_OSSHIFT_SHIFT		5
#define ADC_OSCR_OSSHIFT_MASK		(0x15<<ADC_OSCR_OSSHIFT_SHIFT)

/** @defgroup adc_os_shift ADC Oversampling Ratio
 * @ingroup adc_defines
 *
 *@{*/
#define ADC_OSCR_OSSHIFT_NONE		(0x0<<ADC_OSCR_OSSHIFT_SHIFT)
#define ADC_OSCR_OSSHIFT_1			(0x1<<ADC_OSCR_OSSHIFT_SHIFT)
#define ADC_OSCR_OSSHIFT_2			(0x2<<ADC_OSCR_OSSHIFT_SHIFT)
#define ADC_OSCR_OSSHIFT_3			(0x3<<ADC_OSCR_OSSHIFT_SHIFT)
#define ADC_OSCR_OSSHIFT_4			(0x4<<ADC_OSCR_OSSHIFT_SHIFT)
#define ADC_OSCR_OSSHIFT_5			(0x5<<ADC_OSCR_OSSHIFT_SHIFT)
#define ADC_OSCR_OSSHIFT_6			(0x6<<ADC_OSCR_OSSHIFT_SHIFT)
#define ADC_OSCR_OSSHIFT_7			(0x7<<ADC_OSCR_OSSHIFT_SHIFT)
#define ADC_OSCR_OSSHIFT_8			(0x8<<ADC_OSCR_OSSHIFT_SHIFT)
/**@}*/

#define ADC_OSCR_OSRATIO_SHIFT		2
#define ADC_OSCR_OSRATIO_MASK		(0x7<<ADC_OSCR_OSRATIO_SHIFT)

/** @defgroup adc_os_ratio ADC Oversampling Ratio
 * @ingroup adc_defines
 *
 *@{*/
#define ADC_OSCR_OSRATIO_2			(0x0<<ADC_OSCR_OSRATIO_SHIFT)
#define ADC_OSCR_OSRATIO_4			(0x1<<ADC_OSCR_OSRATIO_SHIFT)
#define ADC_OSCR_OSRATIO_8			(0x2<<ADC_OSCR_OSRATIO_SHIFT)
#define ADC_OSCR_OSRATIO_16			(0x3<<ADC_OSCR_OSRATIO_SHIFT)
#define ADC_OSCR_OSRATIO_32			(0x4<<ADC_OSCR_OSRATIO_SHIFT)
#define ADC_OSCR_OSRATIO_64			(0x5<<ADC_OSCR_OSRATIO_SHIFT)
#define ADC_OSCR_OSRATIO_128		(0x6<<ADC_OSCR_OSRATIO_SHIFT)
#define ADC_OSCR_OSRATIO_256		(0x7<<ADC_OSCR_OSRATIO_SHIFT)
/**@}*/

#define ADC_OSCR_OSEN 				(1 << 0)

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void adc_start_conversion_direct(uint32_t adc);
void adc_set_dual_mode(uint32_t mode);
void adc_enable_temperature_sensor(void);
void adc_disable_temperature_sensor(void);
void adc_enable_external_trigger_regular(uint32_t adc, uint32_t trigger);
void adc_enable_external_trigger_injected(uint32_t adc, uint32_t trigger);
void adc_reset_calibration(uint32_t adc);
void adc_calibration(uint32_t adc)
	LIBOPENCM3_DEPRECATED("see adc_calibrate/_async");
void adc_calibrate_async(uint32_t adc);
bool adc_is_calibrating(uint32_t adc);
void adc_calibrate(uint32_t adc);
void adc_set_resolution(uint32_t adc, uint32_t res);
void adc_enable_oversampling(uint32_t adc, uint32_t ratio, uint32_t shift, uint32_t trigger);
void adc_disable_oversampling(uint32_t adc);

END_DECLS

#endif
/**@}*/

