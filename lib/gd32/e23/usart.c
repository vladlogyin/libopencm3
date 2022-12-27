#include <libopencm3/stm32/usart.h>
#include <libopencm3/stm32/rcc.h>



struct brr_t {
    uint32_t fraction   : 4;
    uint32_t integer    : 12;
    uint32_t _reserved  : 16;
};

/* --------------------------------------------------------------------------- */
/** @brief USART Set Baudrate with a specific clock.

USART0 can have one of 4 clock sources see @ref

must be correctly set before calling this function (refer to the
rcc_clock_setup-* functions in RCC).

@param[in] usart unsigned 32 bit. USART block register address base @ref
usart_reg_base
@param[in] baud unsigned 32 bit. peripheral clock.
@param[in] baud unsigned 32 bit. Baud rate specified in Hz.
*/

void usart_set_baudrate_pclk(uint32_t usart,uint32_t pclk , uint32_t baud)
{
    struct brr_t usart_brr={0};

    uint32_t pclk_div = pclk/16;
    usart_brr.integer = pclk_div/baud;
    usart_brr.fraction = (pclk_div%baud)*16/baud;

    USART_BRR(usart) = *((uint32_t*)&usart_brr);
}
