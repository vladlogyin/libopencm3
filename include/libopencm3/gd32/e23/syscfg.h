/** @defgroup syscfg_defines SYSCFG Defines
 *
 * @brief <b>Defined Constants and Types for the GD32E23 System Config</b>
 *
 * @ingroup GD32E23_defines
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2022
 * Vlad Logyin <vladlogyin@gmail.com>
 *
 * @date 31 December 2022
 *
 * LGPL License Terms @ref lgpl_license
 */
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

#ifndef LIBOPENCM3_SYSCFG_H
#define LIBOPENCM3_SYSCFG_H
/**@{*/

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/

#define SYSCFG_CFGR0			MMIO32(SYSCFG_BASE + 0x00)
#define SYSCFG_EXTICR(i)		MMIO32(SYSCFG_BASE + 0x08 + (i)*4)
#define SYSCFG_EXTICR0			SYSCFG_EXTICR(0)
#define SYSCFG_EXTICR1			SYSCFG_EXTICR(1)
#define SYSCFG_EXTICR2			SYSCFG_EXTICR(2)
#define SYSCFG_EXTICR3			SYSCFG_EXTICR(3)
#define SYSCFG_CFGR2			MMIO32(SYSCFG_BASE + 0x18)
#define SYSCFG_IRQLAT			MMIO32(SYSCFG_BASE + 0x100)

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

/* SYSCFG_CFGR0 Values -- ---------------------------------------------------*/

#define SYSCFG_CFGR0_BOOT_MODE_SHIFT		0
#define SYSCFG_CFGR0_BOOT_MODE_MASK			3
#define SYSCFG_CFGR0_BOOT_MODE_FLASH		0
#define SYSCFG_CFGR0_BOOT_MODE_SYSTEM		1
#define SYSCFG_CFGR0_BOOT_MODE_SRAM			3

#define SYSCFG_CFGR0_REMAP_PA11_PA12		(1 << 4)
#define SYSCFG_CFGR0_REMAP_DMA_ADC			(1 << 8)
#define SYSCFG_CFGR0_REMAP_DMA_USART0_TX	(1 << 9)
#define SYSCFG_CFGR0_REMAP_DMA_USART0_RX	(1 << 10)
#define SYSCFG_CFGR0_REMAP_DMA_TIMER15		(1 << 11)
#define SYSCFG_CFGR0_REMAP_DMA_TIMER16		(1 << 12)

#define SYSCFG_CFGR0_PB9_HIGH_CURRENT		(1 << 19)

/* SYSCFG_CFGR2 Values -- ---------------------------------------------------*/

#define SYSCFG_CFGR2_FWDIS		(1 << 0)

#define SYSCFG_CFGR2_I2C_PB6_FMP	(1 << 8)
#define SYSCFG_CFGR2_I2C_PB7_FMP	(1 << 9)
#define SYSCFG_CFGR2_I2C_PB8_FMP	(1 << 10)
#define SYSCFG_CFGR2_I2C_PB9_FMP	(1 << 11)

#define SYSCFG_CFGR2_I2C1_FMP		(1 << 12)
#define SYSCFG_CFGR2_I2C2_FMP		(1 << 13)
#define SYSCFG_CFGR2_I2C3_FMP		(1 << 14)

/* SYSCFG_CFGR2 Values -- ---------------------------------------------------*/

#define SYSCFG_CFGR2_LOCKUP_LOCK			(1 << 0)
#define SYSCFG_CFGR2_SRAM_PARITY_LOCK		(1 << 1)
#define SYSCFG_CFGR2_LVD_LOCK				(1 << 2)
#define SYSCFG_CFGR2_SRAM_PARITY_FLAG		(1 << 8)

/* SYSCFG_IRQLAT Values -- --------------------------------------------------*/

#define SYSCFG_IRQLAT_IRQ_LATENCY_SHIFT 	0
#define SYSCFG_IRQLAT_IRQ_LATENCY_MASK 	0xFF

/* SYSCFG_EXTICR Values -- --------------------------------------------------*/

#define SYSCFG_EXTICR_FIELDSIZE		4

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

BEGIN_DECLS

void syscfg_set_irq_latency(uint8_t cycles);
uint8_t syscfg_get_irq_latency(void);
uint8_t syscfg_set_remap(uint32_t remap);
uint8_t syscfg_clear_remap(uint32_t remap);
uint8_t syscfg_get_bootmode(void);

END_DECLS
/**@}*/

#endif
