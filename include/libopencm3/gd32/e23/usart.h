/** @defgroup usart_defines USART Defines

@brief <b>Defined Constants and Types for the GD32E23 USART</b>

@ingroup GD32E23_defines

@version 1.0.0

@date 22 December 2022

LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
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

#ifndef LIBOPENCM3_USART_H
#define LIBOPENCM3_USART_H

#include <libopencm3/stm32/common/usart_common_all.h>
#include <libopencm3/stm32/common/usart_common_v2.h>

/**@{*/

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/

/** @defgroup usart_reg_base USART register base addresses
 * Holds all the U(S)ART peripherals supported.
 * @{
 */
#define USART0				USART0_BASE
#define USART1				USART1_BASE
/**@}*/

/**@}*/

BEGIN_DECLS

void usart_set_baudrate_pclk(uint32_t usart,uint32_t pclk , uint32_t baud);

END_DECLS

#endif