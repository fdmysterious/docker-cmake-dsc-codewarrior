/*
 * Copyright (c) 2013 - 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_device_registers.h"
#include "fsl_debug_console.h"

#include "../board/pin_mux.h"
#include "../board/clock_config.h"
#include "../board/peripherals.h"
#include "../board/board.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Main function
 */
int main(void)
{
    char ch;
    int count;

    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();

    BOARD_InitDebugConsole();

    LED_RED_INIT(LOGIC_LED_ON);
    LED_BLUE_INIT(LOGIC_LED_ON);
    LED_GREEN_INIT(LOGIC_LED_ON);
    LED_YELLOW_INIT(LOGIC_LED_ON);

    count = 10000;
    while(count--);

    LED_RED_OFF();
    LED_BLUE_OFF();
    LED_GREEN_OFF();
    LED_YELLOW_OFF();

    EnableIRQWithPriority(BOARD_DEBUG_UART_RX_IRQ, BOARD_DEBUG_UART_ISR_PRORITY);
    EnableIRQWithPriority(BOARD_DEBUG_UART_TX_IRQ, BOARD_DEBUG_UART_ISR_PRORITY);
    EnableIRQWithPriority(BOARD_DEBUG_UART_RX_ERR_IRQ, BOARD_DEBUG_UART_ISR_PRORITY);
    EnableIRQWithPriority(BOARD_DEBUG_UART_TX_IDLE_IRQ, BOARD_DEBUG_UART_ISR_PRORITY);
    SetIRQBasePriority(0);

    PRINTF("hello world.\r\n");

    while (1)
    {
        ch = GETCHAR();
        PUTCHAR(ch);

        GPIO_PinWrite(BOARD_LED_RED_GPIO, BOARD_LED_RED_GPIO_PIN, ((count==0)) ? LOGIC_LED_ON : LOGIC_LED_OFF);
        GPIO_PinWrite(BOARD_LED_BLUE_GPIO, BOARD_LED_BLUE_GPIO_PIN, ((count==1)) ? LOGIC_LED_ON : LOGIC_LED_OFF);
        GPIO_PinWrite(BOARD_LED_GREEN_GPIO, BOARD_LED_GREEN_GPIO_PIN, ((count==2)) ? LOGIC_LED_ON : LOGIC_LED_OFF);
        GPIO_PinWrite(BOARD_LED_YELLOW_GPIO, BOARD_LED_YELLOW_GPIO_PIN, ((count==3)) ? LOGIC_LED_ON : LOGIC_LED_OFF);

        count++;
        count %= 4;
    }
}
