/** @addtogroup timer_defines

@author @htmlonly &copy; @endhtmlonly 2023 Vlad Logyin <vladlogyin@gmail.com>

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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA TIMER.H
The order of header inclusion is important. timer.h includes the device
specific memorymap.h header before including this header file.*/

#pragma once
#include <libopencm3/gd32/common/timer_common_all.h>

/* Timer 13 option register (TIMx_OR) */
#define TIM_OR(tim_base)		MMIO32((tim_base) + 0x50)
#define TIM13_OR				TIM_OR(TIM13)

/* --- TIM13_OR values ---------------------------------------------------- */

/* IC0_RMP */
/****************************************************************************/

#define TIM13_OR_IC0_RMP_SHIFT		6
#define TIM13_OR_IC0_RMP_MASK		(0x3 << TIM13_OR_IC0_RMP_SHIFT)
/** @defgroup tim13_opt_trigger_remap TIM13_OR Timer 13 Option Register Internal Trigger 4 Remap

Only available in F2 and F4 series.
@ingroup timer_defines

@{*/
/** Internal Trigger 4 remapped to GPIO (see reference manual) */
#define TIM13_OR_IC0_RMP_GPIO		(0x0 << TIM13_OR_IC0_RMP_SHIFT)
/** Internal Trigger 4 remapped to LSI internal clock */
#define TIM13_OR_IC0_RMP_LSI		(0x1 << TIM13_OR_IC0_RMP_SHIFT)
/** Internal Trigger 4 remapped to LSE internal clock */
#define TIM13_OR_IC0_RMP_LSE		(0x2 << TIM13_OR_IC0_RMP_SHIFT)
/** Internal Trigger 4 remapped to RTC output event */
#define TIM13_OR_IC0_RMP_RTC		(0x3 << TIM13_OR_IC0_RMP_SHIFT)
/**@}*/

/** Input Capture input polarity */
enum tim_ic_pol {
	TIM_IC_RISING,
	TIM_IC_FALLING,
	TIM_IC_BOTH,
};

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void timer_set_option(uint32_t timer_peripheral, uint32_t option);
void timer_ic_set_polarity(uint32_t timer, enum tim_ic_id ic,
			   enum tim_ic_pol pol);

END_DECLS
