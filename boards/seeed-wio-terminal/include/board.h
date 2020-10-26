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
 * @brief       Board specific definitions for the Seeed WIO Terminal
 *              board
 *
 * @author      Benjamin Doumenc <bdoumenc@gmail.com>
 */

#ifndef BOARD_H
#define BOARD_H

#include "cpu.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @name on board LED pin definitions
 * @{
 */

#define LED0_PIN            GPIO_PIN(PA, 15)

#define LED_PORT            PORT->Group[PA]
#define LED0_MASK           (1 << 15)

#define LED0_ON             (LED_PORT.OUTCLR.reg = LED0_MASK)
#define LED0_OFF            (LED_PORT.OUTSET.reg = LED0_MASK)
#define LED0_TOGGLE         (LED_PORT.OUTTGL.reg = LED0_MASK)

/**
 * @name SW0 (Button) pin definitions
 * @{
 */
#define BTN0_PIN            GPIO_PIN(PC, 28)
#define BTN0_MODE           GPIO_IN_PU
#define BTN1_PIN            GPIO_PIN(PC, 27)
#define BTN1_MODE           GPIO_IN_PU
#define BTN2_PIN            GPIO_PIN(PC, 26)
#define BTN2_MODE           GPIO_IN_PU
/** @} */

/**
 * @name GPIO pin defines
 * @{
 */
#define LCD_DC                      GPIO_PIN(PC, 6)
#define LCD_CS                      GPIO_PIN(PB, 21)
#define LCD_RESET                   GPIO_PIN(PC, 7)

#define LCD_BACKLIGHT_PIN           GPIO_PIN(PC, 5)
#define LCD_BACKLIGHT_PORT          PORT->Group[PC]

/** @} */

/**
 * @name    Backlight control defines
 * @{
 */
#define BACKLIGHT_MASK              (1 << 5)
#define BACKLIGHT_ON                (LCD_BACKLIGHT_PORT.OUTSET.reg = BACKLIGHT_MASK)
#define BACKLIGHT_OFF               (LCD_BACKLIGHT_PORT.OUTCLR.reg = BACKLIGHT_MASK)
#define BACKLIGHT_TOGGLE            (LCD_BACKLIGHT_PORT.OUTTGL.reg = BACKLIGHT_MASK)

/**
 * @name LCD configuration
 * @{
 */
#define ILI9341_PARAM_SPI          SPI_DEV(2)
#define ILI9341_PARAM_SPI_CLK      SPI_CLK_10MHZ
#define ILI9341_PARAM_SPI_MODE     SPI_MODE_3
#define ILI9341_PARAM_CS           LCD_CS
#define ILI9341_PARAM_DCX          LCD_DC
#define ILI9341_PARAM_RST          LCD_RESET
#define ILI9341_PARAM_RGB          1
#define ILI9341_PARAM_INVERTED     1
#define ILI9341_PARAM_NUM_LINES    240U
/** @} */

/**
 * @name    Xtimer configuration
 * @{
 */
#define XTIMER_WIDTH                (32)
#define XTIMER_HZ                   (1000000ul)
/** @} */

/**
 * @brief Initialize board specific hardware, including clock, LEDs and std-IO
 */
void board_init(void);

#ifdef __cplusplus
}
#endif

#endif /* BOARD_H */
/** @} */
