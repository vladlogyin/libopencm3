/** @addtogroup timer_defines
 *
 * @author @htmlonly &copy; @endhtmlonly 2023 Vlad Logyin <vladlogyin@gmail.com>
 *
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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA TIMER.H
The order of header inclusion is important. timer.h includes the device
specific memorymap.h header before including this header file.*/

#pragma once
/* --- Convenience macros -------------------------------------------------- */

/* Timer register base addresses (for convenience) */
/****************************************************************************/
/** @defgroup tim_reg_base Timer register base addresses
@{*/

#if defined(TIM0_BASE)
#define TIM0				TIM0_BASE
#endif
#if defined(TIM1_BASE)
#define TIM1				TIM1_BASE
#endif
#if defined(TIM2_BASE)
#define TIM2				TIM2_BASE
#endif
#if defined(TIM3_BASE)
#define TIM3				TIM3_BASE
#endif
#if defined(TIM4_BASE)
#define TIM4				TIM4_BASE
#endif
#if defined(TIM5_BASE)
# define TIM5				TIM5_BASE
#endif
#if defined(TIM6_BASE)
# define TIM6				TIM6_BASE
#endif
#if defined(TIM7_BASE)
# define TIM7				TIM7_BASE
#endif
#if defined(TIM8_BASE)
# define TIM8				TIM8_BASE
#endif
#if defined(TIM9_BASE)
# define TIM9				TIM9_BASE
#endif
#if defined(TIM10_BASE)
# define TIM10				TIM10_BASE
#endif
#if defined(TIM11_BASE)
# define TIM11				TIM11_BASE
#endif
#if defined(TIM12_BASE)
# define TIM12				TIM12_BASE
#endif
#if defined(TIM13_BASE)
# define TIM13				TIM13_BASE
#endif
#if defined(TIM14_BASE)
# define TIM14				TIM14_BASE
#endif
#if defined(TIM15_BASE)
# define TIM15				TIM15_BASE
#endif
#if defined(TIM16_BASE)
# define TIM16				TIM16_BASE
#endif
#if defined(TIM17_BASE)
# define TIM17				TIM17_BASE
#endif
#if defined(TIM21_BASE)
# define TIM21				TIM21_BASE
#endif
#if defined(TIM22_BASE)
# define TIM22				TIM22_BASE
#endif
/**@}*/

/* --- Timer registers ----------------------------------------------------- */

/* Control register 1 (TIMx_CR1) */
#define TIM_CR1(tim_base)               MMIO32((tim_base) + 0x00)
/* Control register 2 (TIMx_CR2) */
#define TIM_CR2(tim_base)		MMIO32((tim_base) + 0x04)
/* Slave mode control register (TIMx_SMCR) */
#define TIM_SMCR(tim_base)		MMIO32((tim_base) + 0x08)
/* DMA/Interrupt enable register (TIMx_DIER) */
#define TIM_DIER(tim_base)		MMIO32((tim_base) + 0x0C)
/* Status register (TIMx_SR) */
#define TIM_SR(tim_base)		MMIO32((tim_base) + 0x10)
/* Event generation register (TIMx_EGR) */
#define TIM_EGR(tim_base)		MMIO32((tim_base) + 0x14)
/* Capture/compare mode register 1 (TIMx_CCMR1) */
#define TIM_CCMR1(tim_base)		MMIO32((tim_base) + 0x18)
/* Capture/compare mode register 2 (TIMx_CCMR2) */
#define TIM_CCMR2(tim_base)		MMIO32((tim_base) + 0x1C)
/* Capture/compare enable register (TIMx_CCER) */
#define TIM_CCER(tim_base)		MMIO32((tim_base) + 0x20)
/* Counter (TIMx_CNT) */
#define TIM_CNT(tim_base)		MMIO32((tim_base) + 0x24)
/* Prescaler (TIMx_PSC) */
#define TIM_PSC(tim_base)		MMIO32((tim_base) + 0x28)
/* Auto-reload register (TIMx_ARR) */
#define TIM_ARR(tim_base)		MMIO32((tim_base) + 0x2C)
/* Repetition counter register (TIMx_RCR) */
#define TIM_RCR(tim_base)		MMIO32((tim_base) + 0x30)
/* Capture/compare register 1 (TIMx_CCR1) */
#define TIM_CCR1(tim_base)		MMIO32((tim_base) + 0x34)
/* Capture/compare register 2 (TIMx_CCR2) */
#define TIM_CCR2(tim_base)		MMIO32((tim_base) + 0x38)
/* Capture/compare register 3 (TIMx_CCR3) */
#define TIM_CCR3(tim_base)		MMIO32((tim_base) + 0x3C)
/* Capture/compare register 4 (TIMx_CCR4) */
#define TIM_CCR4(tim_base)		MMIO32((tim_base) + 0x40)
/* Break and dead-time register (TIMx_BDTR) */
#define TIM_BDTR(tim_base)		MMIO32((tim_base) + 0x44)
/* DMA control register (TIMx_DCR) */
#define TIM_DCR(tim_base)		MMIO32((tim_base) + 0x48)
/* DMA address for full transfer (TIMx_DMAR) */
#define TIM_DMAR(tim_base)		MMIO32((tim_base) + 0x4C)

/* --- TIMx_CR1 values ----------------------------------------------------- */

/****************************************************************************/
/** @defgroup tim_x_cr1_cdr TIMx_CR1 CKD[1:0] Clock Division Ratio
@{*/
/* CKD[1:0]: Clock division */
#define TIM_CR1_CKD_CK_INT		(0x0 << 8)
#define TIM_CR1_CKD_CK_INT_MUL_2	(0x1 << 8)
#define TIM_CR1_CKD_CK_INT_MUL_4	(0x2 << 8)
#define TIM_CR1_CKD_CK_INT_MASK		(0x3 << 8)
/**@}*/

/* ARPE: Auto-reload preload enable */
#define TIM_CR1_ARPE			(1 << 7)

/* CMS[1:0]: Center-aligned mode selection */
/****************************************************************************/
/** @defgroup tim_x_cr1_cms TIMx_CR1 CMS[1:0]: Center-aligned Mode Selection
@{*/
#define TIM_CR1_CMS_EDGE		(0x0 << 5)
#define TIM_CR1_CMS_CENTER_1		(0x1 << 5)
#define TIM_CR1_CMS_CENTER_2		(0x2 << 5)
#define TIM_CR1_CMS_CENTER_3		(0x3 << 5)
#define TIM_CR1_CMS_MASK		(0x3 << 5)
/**@}*/

/* DIR: Direction */
/****************************************************************************/
/** @defgroup tim_x_cr1_dir TIMx_CR1 DIR: Direction
@{*/
#define TIM_CR1_DIR_UP			(0 << 4)
#define TIM_CR1_DIR_DOWN		(1 << 4)
/**@}*/

/* OPM: One pulse mode */
#define TIM_CR1_OPM			(1 << 3)

/* URS: Update request source */
#define TIM_CR1_URS			(1 << 2)

/* UDIS: Update disable */
#define TIM_CR1_UDIS			(1 << 1)

/* CEN: Counter enable */
#define TIM_CR1_CEN			(1 << 0)

/* --- TIMx_CR2 values ----------------------------------------------------- */

/****************************************************************************/
/** @defgroup tim_x_cr2_ois TIMx_CR2_OIS: Force Output Idle State Control Values
@{*/
/* OIS3:*//** Output idle state 3 (OC3 output) */
#define TIM_CR2_OIS3			(1 << 14)

/* OIS2N:*//** Output idle state 2 (OC2N output) */
#define TIM_CR2_OIS2N			(1 << 13)

/* OIS2:*//** Output idle state 2 (OC2 output) */
#define TIM_CR2_OIS2			(1 << 12)

/* OIS1N:*//** Output idle state 1 (OC1N output) */
#define TIM_CR2_OIS1N			(1 << 11)

/* OIS1:*//** Output idle state 1 (OC1 output) */
#define TIM_CR2_OIS1			(1 << 10)

/* OIS0N:*//** Output idle state 0 (OC0N output) */
#define TIM_CR2_OIS0N			(1 << 9)

/* OIS0:*//** Output idle state 0 (OC0 output) */
#define TIM_CR2_OIS0			(1 << 8)
#define TIM_CR2_OIS_MASK		(0x7f << 8)
/**@}*/

/* TI1S: TI1 selection */
#define TIM_CR2_TI1S			(1 << 7)

/* MMS[2:0]: Master mode selection */
/****************************************************************************/
/** @defgroup tim_mastermode TIMx_CR2 MMS[6:4]: Master Mode Selection
@{*/
#define TIM_CR2_MMS_RESET		(0x0 << 4)
#define TIM_CR2_MMS_ENABLE		(0x1 << 4)
#define TIM_CR2_MMS_UPDATE		(0x2 << 4)
#define TIM_CR2_MMS_COMPARE_PULSE	(0x3 << 4)
#define TIM_CR2_MMS_COMPARE_OC0REF	(0x4 << 4)
#define TIM_CR2_MMS_COMPARE_OC1REF	(0x5 << 4)
#define TIM_CR2_MMS_COMPARE_OC2REF	(0x6 << 4)
#define TIM_CR2_MMS_COMPARE_OC3REF	(0x7 << 4)
#define TIM_CR2_MMS_MASK		(0x7 << 4)
/**@}*/

/* CCDS: Capture/compare DMA selection */
#define TIM_CR2_CCDS			(1 << 3)

/* CCUS: Capture/compare control update selection */
#define TIM_CR2_CCUS			(1 << 2)

/* CCPC: Capture/compare preload control */
#define TIM_CR2_CCPC			(1 << 0)

/* --- TIMx_SMCR values ---------------------------------------------------- */

/* ETP: External trigger polarity */
#define TIM_SMCR_ETP			(1 << 15)

/* ECE: External clock enable */
#define TIM_SMCR_ECE			(1 << 14)

/* ETPS[1:0]: External trigger prescaler */
#define TIM_SMCR_ETPS_OFF		(0x0 << 12)
#define TIM_SMCR_ETPS_ETRP_DIV_2	(0x1 << 12)
#define TIM_SMCR_ETPS_ETRP_DIV_4	(0x2 << 12)
#define TIM_SMCR_ETPS_ETRP_DIV_8	(0x3 << 12)
#define TIM_SMCR_ETPS_MASK		(0X3 << 12)

/* ETF[3:0]: External trigger filter */
#define TIM_SMCR_ETF_OFF		(0x0 << 8)
#define TIM_SMCR_ETF_CK_INT_N_2		(0x1 << 8)
#define TIM_SMCR_ETF_CK_INT_N_4		(0x2 << 8)
#define TIM_SMCR_ETF_CK_INT_N_8		(0x3 << 8)
#define TIM_SMCR_ETF_DTS_DIV_2_N_6	(0x4 << 8)
#define TIM_SMCR_ETF_DTS_DIV_2_N_8	(0x5 << 8)
#define TIM_SMCR_ETF_DTS_DIV_4_N_6	(0x6 << 8)
#define TIM_SMCR_ETF_DTS_DIV_4_N_8	(0x7 << 8)
#define TIM_SMCR_ETF_DTS_DIV_8_N_6	(0x8 << 8)
#define TIM_SMCR_ETF_DTS_DIV_8_N_8	(0x9 << 8)
#define TIM_SMCR_ETF_DTS_DIV_16_N_5	(0xA << 8)
#define TIM_SMCR_ETF_DTS_DIV_16_N_6	(0xB << 8)
#define TIM_SMCR_ETF_DTS_DIV_16_N_8	(0xC << 8)
#define TIM_SMCR_ETF_DTS_DIV_32_N_5	(0xD << 8)
#define TIM_SMCR_ETF_DTS_DIV_32_N_6	(0xE << 8)
#define TIM_SMCR_ETF_DTS_DIV_32_N_8	(0xF << 8)
#define TIM_SMCR_ETF_MASK		(0xF << 8)

/* MSM: Master/slave mode */
#define TIM_SMCR_MSM			(1 << 7)

/* TS[2:0]: Trigger selection */
/** @defgroup tim_ts TIMx_SMCR TS Trigger selection
@{*/
/** Internal Trigger 0 (ITR0) */
#define TIM_SMCR_TS_ITR0		(0x0 << 4)
/** Internal Trigger 1 (ITR1) */
#define TIM_SMCR_TS_ITR1		(0x1 << 4)
/** Internal Trigger 2 (ITR2) */
#define TIM_SMCR_TS_ITR2		(0x2 << 4)
/** Internal Trigger 3 (ITR3) */
#define TIM_SMCR_TS_ITR3		(0x3 << 4)
/** TI0 Edge Detector (TI0F_ED) */
#define TIM_SMCR_TS_TI0F_ED		(0x4 << 4)
/** Filtered Timer Input 0 (TI0FP0) */
#define TIM_SMCR_TS_TI0FP0		(0x5 << 4)
/** Filtered Timer Input 1 (TI1FP1) */
#define TIM_SMCR_TS_TI1FP1		(0x6 << 4)
/** External Trigger input (ETRF) */
#define TIM_SMCR_TS_ETRF		(0x7 << 4)
#define TIM_SMCR_TS_MASK		(0x7 << 4)
/**@}*/

/* SMS[2:0]: Slave mode selection */
/** @defgroup tim_sms TIMx_SMCR SMS Slave mode selection
@{*/
/** Slave mode disabled */
#define TIM_SMCR_SMS_OFF		(0x0 << 0)
/** Encoder mode 1 - Counter counts up/down on TI1FP1 edge depending on TI0FP0
level. */
#define TIM_SMCR_SMS_EM1		(0x1 << 0)
/** Encoder mode 2 - Counter counts up/down on TI0FP0 edge depending on TI1FP1
level. */
#define TIM_SMCR_SMS_EM2		(0x2 << 0)
/** Encoder mode 3 - Counter counts up/down on both TI0FP0 and TI1FP1 edges
depending on the level of the complementary input. */
#define TIM_SMCR_SMS_EM3		(0x3 << 0)
/** Reset Mode - Rising edge of the selected trigger input (TRGI) reinitializes
 * the counter and generates an update of the registers.
 */
#define TIM_SMCR_SMS_RM			(0x4 << 0)
/** Gated Mode - The counter clock is enabled when the trigger input (TRGI) is
 * high.
 */
#define TIM_SMCR_SMS_GM			(0x5 << 0)
/**  Trigger Mode - The counter starts at a rising edge of the trigger TRGI. */
#define TIM_SMCR_SMS_TM			(0x6 << 0)
/** External Clock Mode 1 - Rising edges of the selected trigger (TRGI) clock
 * the counter.
 */
#define TIM_SMCR_SMS_ECM1		(0x7 << 0)
#define TIM_SMCR_SMS_MASK		(0x7 << 0)
/**@}*/

/* --- TIMx_DIER values ---------------------------------------------------- */

/****************************************************************************/
/** @defgroup tim_irq_enable TIMx_DIER Timer DMA and Interrupt Enable Values
@{*/
/* TDE:*//** Trigger DMA request enable */
#define TIM_DIER_TDE			(1 << 14)

/* COMDE:*//** COM DMA request enable */
#define TIM_DIER_COMDE			(1 << 13)

/* CC3DE:*//** Capture/Compare 3 DMA request enable */
#define TIM_DIER_CC3DE			(1 << 12)

/* CC2DE:*//** Capture/Compare 2 DMA request enable */
#define TIM_DIER_CC2DE			(1 << 11)

/* CC1DE:*//** Capture/Compare 1 DMA request enable */
#define TIM_DIER_CC1DE			(1 << 10)

/* CC0DE:*//** Capture/Compare 0 DMA request enable */
#define TIM_DIER_CC0DE			(1 << 9)

/* UDE*//**: Update DMA request enable */
#define TIM_DIER_UDE			(1 << 8)

/* BIE:*//** Break interrupt enable */
#define TIM_DIER_BIE			(1 << 7)

/* TIE:*//** Trigger interrupt enable */
#define TIM_DIER_TIE			(1 << 6)

/* COMIE:*//** COM interrupt enable */
#define TIM_DIER_COMIE			(1 << 5)

/* CC3IE:*//** Capture/compare 3 interrupt enable */
#define TIM_DIER_CC3IE			(1 << 4)

/* CC2IE:*//** Capture/compare 2 interrupt enable */
#define TIM_DIER_CC2IE			(1 << 3)

/* CC1IE:*//** Capture/compare 1 interrupt enable */
#define TIM_DIER_CC1IE			(1 << 2)

/* CC0IE:*//** Capture/compare 0 interrupt enable */
#define TIM_DIER_CC0IE			(1 << 1)

/* UIE:*//** Update interrupt enable */
#define TIM_DIER_UIE			(1 << 0)
/**@}*/

/* --- TIMx_SR values ------------------------------------------------------ */
/****************************************************************************/
/** @defgroup tim_sr_values TIMx_SR Timer Status Register Flags
@{*/

/* CC3OF:*//** Capture/compare 3 overcapture flag */
#define TIM_SR_CC3OF			(1 << 12)

/* CC2OF:*//** Capture/compare 2 overcapture flag */
#define TIM_SR_CC2OF			(1 << 11)

/* CC1OF:*//** Capture/compare 1 overcapture flag */
#define TIM_SR_CC1OF			(1 << 10)

/* CC0OF:*//** Capture/compare 0 overcapture flag */
#define TIM_SR_CC0OF			(1 << 9)

/* BIF:*//** Break interrupt flag */
#define TIM_SR_BIF			(1 << 7)

/* TIF:*//** Trigger interrupt flag */
#define TIM_SR_TIF			(1 << 6)

/* COMIF:*//** COM interrupt flag */
#define TIM_SR_COMIF			(1 << 5)

/* CC3IF:*//** Capture/compare 3 interrupt flag */
#define TIM_SR_CC3IF			(1 << 4)

/* CC2IF:*//** Capture/compare 2 interrupt flag */
#define TIM_SR_CC2IF			(1 << 3)

/* CC1IF:*//** Capture/compare 1 interrupt flag */
#define TIM_SR_CC1IF			(1 << 2)

/* CC0IF:*//** Capture/compare 0 interrupt flag */
#define TIM_SR_CC0IF			(1 << 1)

/* UIF:*//** Update interrupt flag */
#define TIM_SR_UIF			(1 << 0)
/**@}*/

/* --- TIMx_EGR values ----------------------------------------------------- */

/****************************************************************************/
/** @defgroup tim_event_gen TIMx_EGR Timer Event Generator Values
@{*/

/* BG:*//** Break generation */
#define TIM_EGR_BG			(1 << 7)

/* TG:*//** Trigger generation */
#define TIM_EGR_TG			(1 << 6)

/* COMG:*//** Capture/compare control update generation */
#define TIM_EGR_COMG			(1 << 5)

/* CC3G:*//** Capture/compare 3 generation */
#define TIM_EGR_CC3G			(1 << 4)

/* CC2G:*//** Capture/compare 2 generation */
#define TIM_EGR_CC2G			(1 << 3)

/* CC1G:*//** Capture/compare 1 generation */
#define TIM_EGR_CC1G			(1 << 2)

/* CC0G:*//** Capture/compare 0 generation */
#define TIM_EGR_CC0G			(1 << 1)

/* UG:*//** Update generation */
#define TIM_EGR_UG			(1 << 0)
/**@}*/

/* --- TIM_CCMR values ------------------------------- */

#define TIM_CCMR_OC0_SHIFT		0
#define TIM_CCMR_OC0_REGISTER	0x18

#define TIM_CCMR_OC1_SHIFT		8
#define TIM_CCMR_OC1_REGISTER	0x18

#define TIM_CCMR_OC2_SHIFT		0
#define TIM_CCMR_OC2_REGISTER	0x1C

#define TIM_CCMR_OC3_SHIFT		8
#define TIM_CCMR_OC3_REGISTER	0x1C


#define TIM_CCMR_CCS_SHIFT		0
#define TIM_CCMR_OCM_MASK		0x7

#define TIM_CCMR_CCS_OUT		0x0
#define TIM_CCMR_CCS_IN_TI1		0x1
#define TIM_CCMR_CCS_IN_TI0		0x2
#define TIM_CCMR_CCS_IN_TRC		0x3
#define TIM_CCMR_CCS_MASK		0x3


#define TIM_CCMR_OCM_SHIFT		4
#define TIM_CCMR_OCM_MASK		0x7

#define TIM_CCMR_OCM_FROZEN		0x0
#define TIM_CCMR_OCM_ACTIVE		0x1
#define TIM_CCMR_OCM_INACTIVE	0x2
#define TIM_CCMR_OCM_TOGGLE		0x3
#define TIM_CCMR_OCM_FORCE_LOW	0x4
#define TIM_CCMR_OCM_FORCE_HIGH	0x5
#define TIM_CCMR_OCM_PWM1		0x6
#define TIM_CCMR_OCM_PWM2		0x7


/* --- TIMx_CCMR1 values --------------------------------------------------- */

/* --- Output compare mode --- */

/* OC1CE: Output compare 1 clear enable */
#define TIM_CCMR1_OC1CE			(1 << 15)

/* OC1M[2:0]: Output compare 1 mode */
#define TIM_CCMR1_OC1M_FROZEN		(0x0 << 12)
#define TIM_CCMR1_OC1M_ACTIVE		(0x1 << 12)
#define TIM_CCMR1_OC1M_INACTIVE		(0x2 << 12)
#define TIM_CCMR1_OC1M_TOGGLE		(0x3 << 12)
#define TIM_CCMR1_OC1M_FORCE_LOW	(0x4 << 12)
#define TIM_CCMR1_OC1M_FORCE_HIGH	(0x5 << 12)
#define TIM_CCMR1_OC1M_PWM1		(0x6 << 12)
#define TIM_CCMR1_OC1M_PWM2		(0x7 << 12)
#define TIM_CCMR1_OC1M_MASK		(0x7 << 12)

/* OC1PE: Output compare 1 preload enable */
#define TIM_CCMR1_OC1PE			(1 << 11)

/* OC1FE: Output compare 1 fast enable */
#define TIM_CCMR1_OC1FE			(1 << 10)

/* CC1S[1:0]: Capture/compare 1 selection */
/* Note: CC1S bits are writable only when the channel is OFF (CC1E = 0 in
 * TIMx_CCER). */
#define TIM_CCMR1_CC1S_OUT			(0x0 << 8)
#define TIM_CCMR1_CC1S_IN_TI1		(0x1 << 8)
#define TIM_CCMR1_CC1S_IN_TI0		(0x2 << 8)
#define TIM_CCMR1_CC1S_IN_TRC		(0x3 << 8)
#define TIM_CCMR1_CC1S_MASK		(0x3 << 8)

/* OC0CE: Output compare 0 clear enable */
#define TIM_CCMR1_OC0CE			(1 << 7)

/* OC0M[2:0]: Output compare 0 mode */
#define TIM_CCMR1_OC0M_FROZEN		(0x0 << 4)
#define TIM_CCMR1_OC0M_ACTIVE		(0x1 << 4)
#define TIM_CCMR1_OC0M_INACTIVE		(0x2 << 4)
#define TIM_CCMR1_OC0M_TOGGLE		(0x3 << 4)
#define TIM_CCMR1_OC0M_FORCE_LOW	(0x4 << 4)
#define TIM_CCMR1_OC0M_FORCE_HIGH	(0x5 << 4)
#define TIM_CCMR1_OC0M_PWM1		(0x6 << 4)
#define TIM_CCMR1_OC0M_PWM2		(0x7 << 4)
#define TIM_CCMR1_OC0M_MASK		(0x7 << 4)

/* OC0PE: Output compare 0 preload enable */
#define TIM_CCMR1_OC0PE			(1 << 3)

/* OC0FE: Output compare 0 fast enable */
#define TIM_CCMR1_OC0FE			(1 << 2)

/* CC0S[1:0]: Capture/compare 0 selection */
/* Note: CC0S bits are writable only when the channel is OFF (CC0E = 0 in
 * TIMx_CCER). */
#define TIM_CCMR1_CC0S_OUT		(0x0 << 0)
#define TIM_CCMR1_CC0S_IN_TI0		(0x1 << 0)
#define TIM_CCMR1_CC0S_IN_TI1		(0x2 << 0)
#define TIM_CCMR1_CC0S_IN_TRC		(0x3 << 0)
#define TIM_CCMR1_CC0S_MASK		(0x3 << 0)

/* --- Input capture mode --- */

/* IC1F[3:0]: Input capture 1 filter */
#define TIM_CCMR1_IC1F_OFF		(0x0 << 12)
#define TIM_CCMR1_IC1F_CK_INT_N_2	(0x1 << 12)
#define TIM_CCMR1_IC1F_CK_INT_N_4	(0x2 << 12)
#define TIM_CCMR1_IC1F_CK_INT_N_8	(0x3 << 12)
#define TIM_CCMR1_IC1F_DTF_DIV_2_N_6	(0x4 << 12)
#define TIM_CCMR1_IC1F_DTF_DIV_2_N_8	(0x5 << 12)
#define TIM_CCMR1_IC1F_DTF_DIV_4_N_6	(0x6 << 12)
#define TIM_CCMR1_IC1F_DTF_DIV_4_N_8	(0x7 << 12)
#define TIM_CCMR1_IC1F_DTF_DIV_8_N_6	(0x8 << 12)
#define TIM_CCMR1_IC1F_DTF_DIV_8_N_8	(0x9 << 12)
#define TIM_CCMR1_IC1F_DTF_DIV_16_N_5	(0xA << 12)
#define TIM_CCMR1_IC1F_DTF_DIV_16_N_6	(0xB << 12)
#define TIM_CCMR1_IC1F_DTF_DIV_16_N_8	(0xC << 12)
#define TIM_CCMR1_IC1F_DTF_DIV_32_N_5	(0xD << 12)
#define TIM_CCMR1_IC1F_DTF_DIV_32_N_6	(0xE << 12)
#define TIM_CCMR1_IC1F_DTF_DIV_32_N_8	(0xF << 12)
#define TIM_CCMR1_IC1F_MASK		(0xF << 12)

/* IC1PSC[1:0]: Input capture 1 prescaler */
#define TIM_CCMR1_IC1PSC_OFF		(0x0 << 10)
#define TIM_CCMR1_IC1PSC_2		(0x1 << 10)
#define TIM_CCMR1_IC1PSC_4		(0x2 << 10)
#define TIM_CCMR1_IC1PSC_8		(0x3 << 10)
#define TIM_CCMR1_IC1PSC_MASK		(0x3 << 10)

/* IC0F[3:0]: Input capture 0 filter */
#define TIM_CCMR1_IC0F_OFF		(0x0 << 4)
#define TIM_CCMR1_IC0F_CK_INT_N_2	(0x1 << 4)
#define TIM_CCMR1_IC0F_CK_INT_N_4	(0x2 << 4)
#define TIM_CCMR1_IC0F_CK_INT_N_8	(0x3 << 4)
#define TIM_CCMR1_IC0F_DTF_DIV_2_N_6	(0x4 << 4)
#define TIM_CCMR1_IC0F_DTF_DIV_2_N_8	(0x5 << 4)
#define TIM_CCMR1_IC0F_DTF_DIV_4_N_6	(0x6 << 4)
#define TIM_CCMR1_IC0F_DTF_DIV_4_N_8	(0x7 << 4)
#define TIM_CCMR1_IC0F_DTF_DIV_8_N_6	(0x8 << 4)
#define TIM_CCMR1_IC0F_DTF_DIV_8_N_8	(0x9 << 4)
#define TIM_CCMR1_IC0F_DTF_DIV_16_N_5	(0xA << 4)
#define TIM_CCMR1_IC0F_DTF_DIV_16_N_6	(0xB << 4)
#define TIM_CCMR1_IC0F_DTF_DIV_16_N_8	(0xC << 4)
#define TIM_CCMR1_IC0F_DTF_DIV_32_N_5	(0xD << 4)
#define TIM_CCMR1_IC0F_DTF_DIV_32_N_6	(0xE << 4)
#define TIM_CCMR1_IC0F_DTF_DIV_32_N_8	(0xF << 4)
#define TIM_CCMR1_IC0F_MASK		(0xF << 4)

/* IC0PSC[1:0]: Input capture 0 prescaler */
#define TIM_CCMR1_IC0PSC_OFF		(0x0 << 2)
#define TIM_CCMR1_IC0PSC_2		(0x1 << 2)
#define TIM_CCMR1_IC0PSC_4		(0x2 << 2)
#define TIM_CCMR1_IC0PSC_8		(0x3 << 2)
#define TIM_CCMR1_IC0PSC_MASK		(0x3 << 2)

/* --- TIMx_CCMR2 values --------------------------------------------------- */

/* --- Output compare mode --- */

/* OC3CE: Output compare 3 clear enable */
#define TIM_CCMR2_OC3CE			(1 << 15)

/* OC3M[2:0]: Output compare 3 mode */
#define TIM_CCMR2_OC3M_FROZEN		(0x0 << 12)
#define TIM_CCMR2_OC3M_ACTIVE		(0x1 << 12)
#define TIM_CCMR2_OC3M_INACTIVE		(0x2 << 12)
#define TIM_CCMR2_OC3M_TOGGLE		(0x3 << 12)
#define TIM_CCMR2_OC3M_FORCE_LOW	(0x4 << 12)
#define TIM_CCMR2_OC3M_FORCE_HIGH	(0x5 << 12)
#define TIM_CCMR2_OC3M_PWM1		(0x6 << 12)
#define TIM_CCMR2_OC3M_PWM2		(0x7 << 12)
#define TIM_CCMR2_OC3M_MASK		(0x7 << 12)

/* OC3PE: Output compare 3 preload enable */
#define TIM_CCMR2_OC3PE			(1 << 11)

/* OC3FE: Output compare 3 fast enable */
#define TIM_CCMR2_OC3FE			(1 << 10)

/* CC3S[1:0]: Capture/compare 3 selection */
/* Note: CC3S bits are writable only when the channel is OFF (CC3E = 0 in
 * TIMx_CCER). */
#define TIM_CCMR2_CC3S_OUT		(0x0 << 8)
#define TIM_CCMR2_CC3S_IN_TI3		(0x1 << 8)
#define TIM_CCMR2_CC3S_IN_TI2		(0x2 << 8)
#define TIM_CCMR2_CC3S_IN_TRC		(0x3 << 8)
#define TIM_CCMR2_CC3S_MASK		(0x3 << 8)

/* OC2CE: Output compare 2 clear enable */
#define TIM_CCMR2_OC2CE			(1 << 7)

/* OC2M[2:0]: Output compare 2 mode */
#define TIM_CCMR2_OC2M_FROZEN		(0x0 << 4)
#define TIM_CCMR2_OC2M_ACTIVE		(0x1 << 4)
#define TIM_CCMR2_OC2M_INACTIVE		(0x2 << 4)
#define TIM_CCMR2_OC2M_TOGGLE		(0x3 << 4)
#define TIM_CCMR2_OC2M_FORCE_LOW	(0x4 << 4)
#define TIM_CCMR2_OC2M_FORCE_HIGH	(0x5 << 4)
#define TIM_CCMR2_OC2M_PWM1		(0x6 << 4)
#define TIM_CCMR2_OC2M_PWM2		(0x7 << 4)
#define TIM_CCMR2_OC2M_MASK		(0x7 << 4)

/* OC2PE: Output compare 2 preload enable */
#define TIM_CCMR2_OC2PE			(1 << 3)

/* OC2FE: Output compare 2 fast enable */
#define TIM_CCMR2_OC2FE			(1 << 2)

/* CC2S[1:0]: Capture/compare 2 selection */
/* Note: CC2S bits are writable only when the channel is OFF (CC2E = 0 in
 * TIMx_CCER). */
#define TIM_CCMR2_CC2S_OUT		(0x0 << 0)
#define TIM_CCMR2_CC2S_IN_TI2		(0x1 << 0)
#define TIM_CCMR2_CC2S_IN_TI3		(0x2 << 0)
#define TIM_CCMR2_CC2S_IN_TRC		(0x3 << 0)
#define TIM_CCMR2_CC2S_MASK		(0x3 << 0)

/* --- Input capture mode --- */

/* IC3F[3:0]: Input capture 3 filter */
#define TIM_CCMR2_IC3F_OFF		(0x0 << 12)
#define TIM_CCMR2_IC3F_CK_INT_N_2	(0x1 << 12)
#define TIM_CCMR2_IC3F_CK_INT_N_4	(0x2 << 12)
#define TIM_CCMR2_IC3F_CK_INT_N_8	(0x3 << 12)
#define TIM_CCMR2_IC3F_DTF_DIV_2_N_6	(0x4 << 12)
#define TIM_CCMR2_IC3F_DTF_DIV_2_N_8	(0x5 << 12)
#define TIM_CCMR2_IC3F_DTF_DIV_4_N_6	(0x6 << 12)
#define TIM_CCMR2_IC3F_DTF_DIV_4_N_8	(0x7 << 12)
#define TIM_CCMR2_IC3F_DTF_DIV_8_N_6	(0x8 << 12)
#define TIM_CCMR2_IC3F_DTF_DIV_8_N_8	(0x9 << 12)
#define TIM_CCMR2_IC3F_DTF_DIV_16_N_5	(0xA << 12)
#define TIM_CCMR2_IC3F_DTF_DIV_16_N_6	(0xB << 12)
#define TIM_CCMR2_IC3F_DTF_DIV_16_N_8	(0xC << 12)
#define TIM_CCMR2_IC3F_DTF_DIV_32_N_5	(0xD << 12)
#define TIM_CCMR2_IC3F_DTF_DIV_32_N_6	(0xE << 12)
#define TIM_CCMR2_IC3F_DTF_DIV_32_N_8	(0xF << 12)
#define TIM_CCMR2_IC3F_MASK		(0xF << 12)

/* IC3PSC[1:0]: Input capture 3 prescaler */
#define TIM_CCMR2_IC3PSC_OFF		(0x0 << 10)
#define TIM_CCMR2_IC3PSC_2		(0x1 << 10)
#define TIM_CCMR2_IC3PSC_4		(0x2 << 10)
#define TIM_CCMR2_IC3PSC_8		(0x3 << 10)
#define TIM_CCMR2_IC3PSC_MASK		(0x3 << 10)

/* IC2F[3:0]: Input capture 2 filter */
#define TIM_CCMR2_IC2F_OFF		(0x0 << 4)
#define TIM_CCMR2_IC2F_CK_INT_N_2	(0x1 << 4)
#define TIM_CCMR2_IC2F_CK_INT_N_4	(0x2 << 4)
#define TIM_CCMR2_IC2F_CK_INT_N_8	(0x3 << 4)
#define TIM_CCMR2_IC2F_DTF_DIV_2_N_6	(0x4 << 4)
#define TIM_CCMR2_IC2F_DTF_DIV_2_N_8	(0x5 << 4)
#define TIM_CCMR2_IC2F_DTF_DIV_4_N_6	(0x6 << 4)
#define TIM_CCMR2_IC2F_DTF_DIV_4_N_8	(0x7 << 4)
#define TIM_CCMR2_IC2F_DTF_DIV_8_N_6	(0x8 << 4)
#define TIM_CCMR2_IC2F_DTF_DIV_8_N_8	(0x9 << 4)
#define TIM_CCMR2_IC2F_DTF_DIV_16_N_5	(0xA << 4)
#define TIM_CCMR2_IC2F_DTF_DIV_16_N_6	(0xB << 4)
#define TIM_CCMR2_IC2F_DTF_DIV_16_N_8	(0xC << 4)
#define TIM_CCMR2_IC2F_DTF_DIV_32_N_5	(0xD << 4)
#define TIM_CCMR2_IC2F_DTF_DIV_32_N_6	(0xE << 4)
#define TIM_CCMR2_IC2F_DTF_DIV_32_N_8	(0xF << 4)
#define TIM_CCMR2_IC2F_MASK		(0xF << 4)

/* IC2PSC[1:0]: Input capture 2 prescaler */
#define TIM_CCMR2_IC2PSC_OFF		(0x0 << 2)
#define TIM_CCMR2_IC2PSC_2		(0x1 << 2)
#define TIM_CCMR2_IC2PSC_4		(0x2 << 2)
#define TIM_CCMR2_IC2PSC_8		(0x3 << 2)
#define TIM_CCMR2_IC2PSC_MASK		(0x3 << 2)

/* --- TIMx_CCER values ---------------------------------------------------- */

/* CC3NP: Capture/compare 3 complementary output polarity */
#define TIM_CCER_CC3NP			(1 << 15)

/* CC3P: Capture/compare 3 output polarity */
#define TIM_CCER_CC3P			(1 << 13)

/* CC3E: Capture/compare 3 output enable */
#define TIM_CCER_CC3E			(1 << 12)

/* CC2NP: Capture/compare 2 complementary output polarity */
#define TIM_CCER_CC2NP			(1 << 11)

/* CC2NE: Capture/compare 2 complementary output enable */
#define TIM_CCER_CC2NE			(1 << 10)

/* CC2P: Capture/compare 2 output polarity */
#define TIM_CCER_CC2P			(1 << 9)

/* CC2E: Capture/compare 2 output enable */
#define TIM_CCER_CC2E			(1 << 8)

/* CC1NP: Capture/compare 1 complementary output polarity */
#define TIM_CCER_CC1NP			(1 << 7)

/* CC1NE: Capture/compare 1 complementary output enable */
#define TIM_CCER_CC1NE			(1 << 6)

/* CC1P: Capture/compare 1 output polarity */
#define TIM_CCER_CC1P			(1 << 5)

/* CC1E: Capture/compare 1 output enable */
#define TIM_CCER_CC1E			(1 << 4)

/* CC0NP: Capture/compare 0 complementary output polarity */
#define TIM_CCER_CC0NP			(1 << 3)

/* CC0NE: Capture/compare 0 complementary output enable */
#define TIM_CCER_CC0NE			(1 << 2)

/* CC0P: Capture/compare 0 output polarity */
#define TIM_CCER_CC0P			(1 << 1)

/* CC0E: Capture/compare 0 output enable */
#define TIM_CCER_CC0E			(1 << 0)

/* --- TIMx_CNT values ----------------------------------------------------- */

/* CNT[15:0]: Counter value */

/* --- TIMx_PSC values ----------------------------------------------------- */

/* PSC[15:0]: Prescaler value */

/* --- TIMx_ARR values ----------------------------------------------------- */

/* ARR[15:0]: Prescaler value */

/* --- TIMx_RCR values ----------------------------------------------------- */

/* REP[15:0]: Repetition counter value */

/* --- TIMx_CCR1 values ---------------------------------------------------- */

/* CCR1[15:0]: Capture/compare 1 value */

/* --- TIMx_CCR2 values ---------------------------------------------------- */

/* CCR2[15:0]: Capture/compare 2 value */

/* --- TIMx_CCR3 values ---------------------------------------------------- */

/* CCR3[15:0]: Capture/compare 3 value */

/* --- TIMx_CCR4 values ---------------------------------------------------- */

/* CCR4[15:0]: Capture/compare 4 value */

/* --- TIMx_BDTR values ---------------------------------------------------- */

/* MOE: Main output enable */
#define TIM_BDTR_MOE			(1 << 15)

/* AOE: Automatic output enable */
#define TIM_BDTR_AOE			(1 << 14)

/* BKP: Break polarity */
#define TIM_BDTR_BKP			(1 << 13)

/* BKE: Break enable */
#define TIM_BDTR_BKE			(1 << 12)

/* OSSR: Off-state selection of run mode */
#define TIM_BDTR_OSSR			(1 << 11)

/* OSSI: Off-state selection of idle mode */
#define TIM_BDTR_OSSI			(1 << 10)

/* LOCK[1:0]: Lock configuration */
/****************************************************************************/
/** @defgroup tim_lock TIM_BDTR_LOCK Timer Lock Values
@{*/
#define TIM_BDTR_LOCK_OFF		(0x0 << 8)
#define TIM_BDTR_LOCK_LEVEL_1		(0x1 << 8)
#define TIM_BDTR_LOCK_LEVEL_2		(0x2 << 8)
#define TIM_BDTR_LOCK_LEVEL_3		(0x3 << 8)
#define TIM_BDTR_LOCK_MASK		(0x3 << 8)
/**@}*/

/* DTG[7:0]: Dead-time generator set-up */
#define TIM_BDTR_DTG_MASK		0x00FF

/* --- TIMx_DCR values ----------------------------------------------------- */

/* DBL[4:0]: DMA burst length */
#define TIM_BDTR_DBL_MASK		(0x1F << 8)

/* DBA[4:0]: DMA base address */
#define TIM_BDTR_DBA_MASK		(0x1F << 0)

/* --- TIMx_DMAR values ---------------------------------------------------- */

/* DMAB[15:0]: DMA register for burst accesses */

/* --- TIMx convenience defines -------------------------------------------- */

/** Output Compare channel designators */
enum tim_oc_id {
	TIM_OC0 = 0,
	TIM_OC0N,
	TIM_OC1,
	TIM_OC1N,
	TIM_OC2,
	TIM_OC2N,
	TIM_OC3,
	TIM_OC3N,
};

/** Output Compare mode designators */
enum tim_oc_mode {
	TIM_OCM_FROZEN = TIM_CCMR_OCM_FROZEN,
	TIM_OCM_ACTIVE = TIM_CCMR_OCM_ACTIVE,
	TIM_OCM_INACTIVE = TIM_CCMR_OCM_INACTIVE,
	TIM_OCM_TOGGLE = TIM_CCMR_OCM_TOGGLE,
	TIM_OCM_FORCE_LOW = TIM_CCMR_OCM_FORCE_LOW,
	TIM_OCM_FORCE_HIGH = TIM_CCMR_OCM_FORCE_HIGH,
	TIM_OCM_PWM1 = TIM_CCMR_OCM_PWM1,
	TIM_OCM_PWM2 = TIM_CCMR_OCM_PWM2,
};

/** Input Capture channel designators */
enum tim_ic_id {
	TIM_IC0,
	TIM_IC1,
	TIM_IC2,
	TIM_IC3,
};

/** Input Capture input filter. The frequency used to sample the
input and the number of events needed to validate an output transition.

TIM_IC_CK_INT_N_x No division from the Deadtime and Sampling Clock frequency
(DTF), filter length x
TIM_IC_DTF_DIV_y_N_x Division by y from the DTF, filter length x
 */
enum tim_ic_filter {
	TIM_IC_OFF,
	TIM_IC_CK_INT_N_2,
	TIM_IC_CK_INT_N_4,
	TIM_IC_CK_INT_N_8,
	TIM_IC_DTF_DIV_2_N_6,
	TIM_IC_DTF_DIV_2_N_8,
	TIM_IC_DTF_DIV_4_N_6,
	TIM_IC_DTF_DIV_4_N_8,
	TIM_IC_DTF_DIV_8_N_6,
	TIM_IC_DTF_DIV_8_N_8,
	TIM_IC_DTF_DIV_16_N_5,
	TIM_IC_DTF_DIV_16_N_6,
	TIM_IC_DTF_DIV_16_N_8,
	TIM_IC_DTF_DIV_32_N_5,
	TIM_IC_DTF_DIV_32_N_6,
	TIM_IC_DTF_DIV_32_N_8,
};

/** Input Capture input prescaler.

TIM_IC_PSC_x Input capture is done every x events*/
enum tim_ic_psc {
	TIM_IC_PSC_OFF,
	TIM_IC_PSC_2,
	TIM_IC_PSC_4,
	TIM_IC_PSC_8,
};

/** Input Capture input source.

The direction of the channel (input/output) as well as the input used.
 */
enum tim_ic_input {
	TIM_IC_OUT = 0,
	TIM_IC_IN_TI1 = 1,
	TIM_IC_IN_TI2 = 2,
	TIM_IC_IN_TRC = 3,
	TIM_IC_IN_TI3 = 5,
	TIM_IC_IN_TI4 = 6,
};

/** Slave external trigger polarity */
enum tim_et_pol {
	TIM_ET_RISING,
	TIM_ET_FALLING,
};

/** External clock mode 2 */
enum tim_ecm2_state {
    TIM_ECM2_DISABLED,
    TIM_ECM2_ENABLED,
};

/* --- TIM function prototypes --------------------------------------------- */

BEGIN_DECLS

void timer_enable_irq(uint32_t timer_peripheral, uint32_t irq);
void timer_disable_irq(uint32_t timer_peripheral, uint32_t irq);
bool timer_interrupt_source(uint32_t timer_peripheral, uint32_t flag);
bool timer_get_flag(uint32_t timer_peripheral, uint32_t flag);
void timer_clear_flag(uint32_t timer_peripheral, uint32_t flag);
void timer_set_mode(uint32_t timer_peripheral, uint32_t clock_div,
		    uint32_t alignment, uint32_t direction);
void timer_set_clock_division(uint32_t timer_peripheral, uint32_t clock_div);
void timer_enable_preload(uint32_t timer_peripheral);
void timer_disable_preload(uint32_t timer_peripheral);
void timer_set_alignment(uint32_t timer_peripheral, uint32_t alignment);
void timer_direction_up(uint32_t timer_peripheral);
void timer_direction_down(uint32_t timer_peripheral);
void timer_one_shot_mode(uint32_t timer_peripheral);
void timer_continuous_mode(uint32_t timer_peripheral);
void timer_update_on_any(uint32_t timer_peripheral);
void timer_update_on_overflow(uint32_t timer_peripheral);
void timer_enable_update_event(uint32_t timer_peripheral);
void timer_disable_update_event(uint32_t timer_peripheral);
void timer_enable_counter(uint32_t timer_peripheral);
void timer_disable_counter(uint32_t timer_peripheral);
void timer_set_output_idle_state(uint32_t timer_peripheral, uint32_t outputs);
void timer_reset_output_idle_state(uint32_t timer_peripheral, uint32_t outputs);
void timer_set_ti1_ch123_xor(uint32_t timer_peripheral);
void timer_set_ti1_ch1(uint32_t timer_peripheral);
void timer_set_master_mode(uint32_t timer_peripheral, uint32_t mode);
void timer_set_dma_on_compare_event(uint32_t timer_peripheral);
void timer_set_dma_on_update_event(uint32_t timer_peripheral);
void timer_enable_compare_control_update_on_trigger(uint32_t timer_peripheral);
void timer_disable_compare_control_update_on_trigger(uint32_t timer_peripheral);
void timer_enable_preload_complementry_enable_bits(uint32_t timer_peripheral);
void timer_disable_preload_complementry_enable_bits(uint32_t timer_peripheral);
void timer_set_prescaler(uint32_t timer_peripheral, uint32_t value);
void timer_set_repetition_counter(uint32_t timer_peripheral, uint32_t value);
void timer_set_period(uint32_t timer_peripheral, uint32_t period);
void timer_enable_oc_clear(uint32_t timer_peripheral, enum tim_oc_id oc_id);
void timer_disable_oc_clear(uint32_t timer_peripheral, enum tim_oc_id oc_id);
void timer_set_oc_fast_mode(uint32_t timer_peripheral, enum tim_oc_id oc_id);
void timer_set_oc_slow_mode(uint32_t timer_peripheral, enum tim_oc_id oc_id);
void timer_set_oc_mode(uint32_t timer_peripheral, enum tim_oc_id oc_id,
		       enum tim_oc_mode oc_mode);
void timer_enable_oc_preload(uint32_t timer_peripheral, enum tim_oc_id oc_id);
void timer_disable_oc_preload(uint32_t timer_peripheral, enum tim_oc_id oc_id);
void timer_set_oc_polarity_high(uint32_t timer_peripheral,
				enum tim_oc_id oc_id);
void timer_set_oc_polarity_low(uint32_t timer_peripheral, enum tim_oc_id oc_id);
void timer_enable_oc_output(uint32_t timer_peripheral, enum tim_oc_id oc_id);
void timer_disable_oc_output(uint32_t timer_peripheral, enum tim_oc_id oc_id);
void timer_set_oc_idle_state_set(uint32_t timer_peripheral,
				 enum tim_oc_id oc_id);
void timer_set_oc_idle_state_unset(uint32_t timer_peripheral,
				   enum tim_oc_id oc_id);
void timer_set_oc_value(uint32_t timer_peripheral, enum tim_oc_id oc_id,
			uint32_t value);
void timer_enable_break_main_output(uint32_t timer_peripheral);
void timer_disable_break_main_output(uint32_t timer_peripheral);
void timer_enable_break_automatic_output(uint32_t timer_peripheral);
void timer_disable_break_automatic_output(uint32_t timer_peripheral);
void timer_set_break_polarity_high(uint32_t timer_peripheral);
void timer_set_break_polarity_low(uint32_t timer_peripheral);
void timer_enable_break(uint32_t timer_peripheral);
void timer_disable_break(uint32_t timer_peripheral);
void timer_set_enabled_off_state_in_run_mode(uint32_t timer_peripheral);
void timer_set_disabled_off_state_in_run_mode(uint32_t timer_peripheral);
void timer_set_enabled_off_state_in_idle_mode(uint32_t timer_peripheral);
void timer_set_disabled_off_state_in_idle_mode(uint32_t timer_peripheral);
void timer_set_break_lock(uint32_t timer_peripheral, uint32_t lock);
void timer_set_deadtime(uint32_t timer_peripheral, uint32_t deadtime);
void timer_generate_event(uint32_t timer_peripheral, uint32_t event);
uint32_t timer_get_counter(uint32_t timer_peripheral);
void timer_set_counter(uint32_t timer_peripheral, uint32_t count);

void timer_ic_set_filter(uint32_t timer, enum tim_ic_id ic,
			 enum tim_ic_filter flt);
void timer_ic_set_prescaler(uint32_t timer, enum tim_ic_id ic,
			    enum tim_ic_psc psc);
void timer_ic_set_input(uint32_t timer, enum tim_ic_id ic,
			enum tim_ic_input in);
void timer_ic_enable(uint32_t timer, enum tim_ic_id ic);
void timer_ic_disable(uint32_t timer, enum tim_ic_id ic);

void timer_slave_set_filter(uint32_t timer, enum tim_ic_filter flt);
void timer_slave_set_prescaler(uint32_t timer, enum tim_ic_psc psc);
void timer_slave_set_polarity(uint32_t timer, enum tim_et_pol pol);
void timer_slave_set_mode(uint32_t timer, uint8_t mode);
void timer_slave_set_trigger(uint32_t timer, uint8_t trigger);
void timer_slave_set_extclockmode2(uint32_t timer_peripheral,
            enum tim_ecm2_state state);

END_DECLS

/**@}*/
