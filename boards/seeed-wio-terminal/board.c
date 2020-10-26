/*
 * Copyright (C) 2020 Benjamin doumenc <bdoumenc@gmail.com>
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     boards_seeed-wio-terminal
 * @{
 *
 * @file
 * @brief       Board specific implementation of direct mapped GPIOs
 *
 * @author      Benjamin Doumenc <bdoumenc@gmail.com>
 * @}
 */

#include "board.h"
#include "periph/gpio.h"

void board_init(void)
{

    /* initialize the CPU */
    cpu_init();
    gpio_init(LCD_BACKLIGHT_PIN, GPIO_OUT);
}
