/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v11.0
processor: MC56F83789
package_id: MC56F83789VLL
mcu_data: ksdk2_0
processor_version: 11.0.1
board: MC56F83000-EVK
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

#include "fsl_common.h"
#include "fsl_gpio.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 *
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void)
{
    BOARD_InitPins();
    BOARD_InitDEBUG_UARTPins();
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list: []
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins(void)
{
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitBUTTONsPins:
- options: {callFromInitBoot: 'false', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '94', peripheral: GPIOF, signal: 'GPIO, 6', pin_signal: GPIOF6/TB2/PWMA_3X/PWMB_3X/XB_IN2, direction: INPUT, gpio_interrupt: gpioIrqFallingEdge, slew_rate: slow,
    pull_enable: disable}
  - {pin_num: '77', peripheral: GPIOF, signal: 'GPIO, 1', pin_signal: GPIOF1/CLKO1/XB_IN7/CMPD_O, direction: INPUT, gpio_interrupt: gpioIrqFallingEdge, pull_enable: disable}
  - {pin_num: '46', peripheral: GPIOF, signal: 'GPIO, 15', pin_signal: GPIOF15/RXD0/XB_IN10, direction: INPUT, gpio_interrupt: gpioIrqFallingEdge, pull_enable: disable}
  - {pin_num: '12', peripheral: GPIOC, signal: 'GPIO, 4', pin_signal: GPIOC4/TA1/CMPB_O/XB_IN8/EWM_OUT_B, direction: INPUT, gpio_interrupt: gpioIrqFallingEdge, pull_enable: disable}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBUTTONsPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitBUTTONsPins(void)
{
    /* GPIOC IPBus Clock Enable: The peripheral is clocked. */
    CLOCK_EnableClock(kCLOCK_GPIOC);
    /* GPIOF IPBus Clock Enable: The peripheral is clocked. */
    CLOCK_EnableClock(kCLOCK_GPIOF);
    /* GPIO functionality on pin GPIOC4 (pin 12) */
    GPIO_PinSetPeripheralMode(BOARD_SW5_GPIO, BOARD_SW5_PIN_MASK, kGPIO_ModeGpio);
    /* GPIO functionality on pin GPIOF1 (pin 77) */
    GPIO_PinSetPeripheralMode(BOARD_SW3_GPIO, BOARD_SW3_PIN_MASK, kGPIO_ModeGpio);
    /* GPIO functionality on pin GPIOF6 (pin 94) */
    GPIO_PinSetPeripheralMode(BOARD_SW4_GPIO, BOARD_SW4_PIN_MASK, kGPIO_ModeGpio);
    /* GPIO functionality on pin GPIOF15 (pin 46) */
    GPIO_PinSetPeripheralMode(BOARD_SW2_GPIO, BOARD_SW2_PIN_MASK, kGPIO_ModeGpio);

    /* Initialize GPIO functionality on pin GPIOC4 (pin 12)  */
    GPIO_PinSetDirection(BOARD_SW5_GPIO, BOARD_SW5_PIN_MASK, kGPIO_DigitalInput);

    /* Initialize GPIO functionality on pin GPIOF1 (pin 77)  */
    GPIO_PinSetDirection(BOARD_SW3_GPIO, BOARD_SW3_PIN_MASK, kGPIO_DigitalInput);

    /* Initialize GPIO functionality on pin GPIOF6 (pin 94)  */
    GPIO_PinSetDirection(BOARD_SW4_GPIO, BOARD_SW4_PIN_MASK, kGPIO_DigitalInput);

    /* Initialize GPIO functionality on pin GPIOF15 (pin 46)  */
    GPIO_PinSetDirection(BOARD_SW2_GPIO, BOARD_SW2_PIN_MASK, kGPIO_DigitalInput);

    /* Pin configuration on GPIOF6 (pin 94) */
    /* Slew rate control configuration: Slow slew rate is configured */
    GPIO_PinSetSlewRate(BOARD_SW4_GPIO, BOARD_SW4_PIN_MASK, kGPIO_SlewRateSlow);

    /* Interrupt configuration on GPIOC4 (pin 12): Interrupt on falling edge */
    GPIO_PinSetInterruptConfig(BOARD_SW5_GPIO, BOARD_SW5_PIN_MASK, kGPIO_InterruptFallingEdge);

    /* Interrupt configuration on GPIOF1 (pin 77): Interrupt on falling edge */
    GPIO_PinSetInterruptConfig(BOARD_SW3_GPIO, BOARD_SW3_PIN_MASK, kGPIO_InterruptFallingEdge);

    /* Interrupt configuration on GPIOF6 (pin 94): Interrupt on falling edge */
    GPIO_PinSetInterruptConfig(BOARD_SW4_GPIO, BOARD_SW4_PIN_MASK, kGPIO_InterruptFallingEdge);

    /* Interrupt configuration on GPIOF15 (pin 46): Interrupt on falling edge */
    GPIO_PinSetInterruptConfig(BOARD_SW2_GPIO, BOARD_SW2_PIN_MASK, kGPIO_InterruptFallingEdge);

    GPIOC->PUR = ((GPIOC->PUR &
                   /* Mask bits to zero which are setting */
                   (~(GPIO_PUR_PU_4_MASK)))

                  /* Pull Resistor Enable Bits: Pull resistor is disabled. */
                  | GPIO_PUR_PU(PUR_PU_4_DISABLED));

    GPIOF->PUR = ((GPIOF->PUR &
                   /* Mask bits to zero which are setting */
                   (~(GPIO_PUR_PU_1_MASK | GPIO_PUR_PU_6_MASK | GPIO_PUR_PU_15_MASK)))

                  /* Pull Resistor Enable Bits: Pull resistor is disabled. */
                  | GPIO_PUR_PU(PUR_PU_1_DISABLED)

                  /* Pull Resistor Enable Bits: Pull resistor is disabled. */
                  | GPIO_PUR_PU(PUR_PU_6_DISABLED)

                  /* Pull Resistor Enable Bits: Pull resistor is disabled. */
                  | GPIO_PUR_PU(PUR_PU_15_DISABLED));
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitLEDsPins:
- options: {callFromInitBoot: 'false', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '6', peripheral: GPIOF, signal: 'GPIO, 8', pin_signal: GPIOF8/RXD0/TB1/CMPD_O/PWMA_2X, direction: OUTPUT, gpio_init_state: 'true', pull_select: down}
  - {pin_num: '45', peripheral: GPIOF, signal: 'GPIO, 11', pin_signal: GPIOF11/TXD0/XB_IN11, direction: OUTPUT, gpio_init_state: 'true', pull_select: down}
  - {pin_num: '56', peripheral: GPIOF, signal: 'GPIO, 10', pin_signal: GPIOF10/TXD2/PWMA_FAULT6/PWMB_FAULT6/XB_OUT10, direction: OUTPUT, gpio_init_state: 'true',
    pull_select: down}
  - {pin_num: '57', peripheral: GPIOF, signal: 'GPIO, 9', pin_signal: GPIOF9/RXD2/PWMA_FAULT7/PWMB_FAULT7/XB_OUT11, direction: OUTPUT, gpio_init_state: 'true', pull_select: down}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitLEDsPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitLEDsPins(void)
{
    /* GPIOF IPBus Clock Enable: The peripheral is clocked. */
    CLOCK_EnableClock(kCLOCK_GPIOF);
    /* GPIO functionality on pin GPIOF8 (pin 6) */
    GPIO_PinSetPeripheralMode(BOARD_LED_RED_GPIO, BOARD_LED_RED_PIN_MASK, kGPIO_ModeGpio);
    /* GPIO functionality on pin GPIOF9 (pin 57) */
    GPIO_PinSetPeripheralMode(BOARD_LED_GREEN_GPIO, BOARD_LED_GREEN_PIN_MASK, kGPIO_ModeGpio);
    /* GPIO functionality on pin GPIOF10 (pin 56) */
    GPIO_PinSetPeripheralMode(BOARD_LED_BLUE_GPIO, BOARD_LED_BLUE_PIN_MASK, kGPIO_ModeGpio);
    /* GPIO functionality on pin GPIOF11 (pin 45) */
    GPIO_PinSetPeripheralMode(BOARD_LED_YELLOW_GPIO, BOARD_LED_YELLOW_PIN_MASK, kGPIO_ModeGpio);

    /* Initialize GPIO functionality on pin GPIOF8 (pin 6)  */
    GPIO_PinWrite(BOARD_LED_RED_GPIO, BOARD_LED_RED_PIN_MASK, kGPIO_OutputHigh);
    GPIO_PinSetDirection(BOARD_LED_RED_GPIO, BOARD_LED_RED_PIN_MASK, kGPIO_DigitalOutput);

    /* Initialize GPIO functionality on pin GPIOF9 (pin 57)  */
    GPIO_PinWrite(BOARD_LED_GREEN_GPIO, BOARD_LED_GREEN_PIN_MASK, kGPIO_OutputHigh);
    GPIO_PinSetDirection(BOARD_LED_GREEN_GPIO, BOARD_LED_GREEN_PIN_MASK, kGPIO_DigitalOutput);

    /* Initialize GPIO functionality on pin GPIOF10 (pin 56)  */
    GPIO_PinWrite(BOARD_LED_BLUE_GPIO, BOARD_LED_BLUE_PIN_MASK, kGPIO_OutputHigh);
    GPIO_PinSetDirection(BOARD_LED_BLUE_GPIO, BOARD_LED_BLUE_PIN_MASK, kGPIO_DigitalOutput);

    /* Initialize GPIO functionality on pin GPIOF11 (pin 45)  */
    GPIO_PinWrite(BOARD_LED_YELLOW_GPIO, BOARD_LED_YELLOW_PIN_MASK, kGPIO_OutputHigh);
    GPIO_PinSetDirection(BOARD_LED_YELLOW_GPIO, BOARD_LED_YELLOW_PIN_MASK, kGPIO_DigitalOutput);

    GPIOF->PUS = ((GPIOF->PUS &
                   /* Mask bits to zero which are setting */
                   (~(GPIO_PUS_PUS_8_MASK | GPIO_PUS_PUS_9_MASK | GPIO_PUS_PUS_10_MASK | GPIO_PUS_PUS_11_MASK)))

                  /* Pull Resistor Type Select Bits: Pulldown resistor. */
                  | GPIO_PUS_PUS(PUS_PUS_8_PULLDOWN)

                  /* Pull Resistor Type Select Bits: Pulldown resistor. */
                  | GPIO_PUS_PUS(PUS_PUS_9_PULLDOWN)

                  /* Pull Resistor Type Select Bits: Pulldown resistor. */
                  | GPIO_PUS_PUS(PUS_PUS_10_PULLDOWN)

                  /* Pull Resistor Type Select Bits: Pulldown resistor. */
                  | GPIO_PUS_PUS(PUS_PUS_11_PULLDOWN));
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitOSCsPins:
- options: {callFromInitBoot: 'false', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '3', peripheral: OCCS, signal: EXTAL, pin_signal: GPIOC0/EXTAL/CLKIN0, slew_rate: no_init, open_drain: no_init, pull_select: no_init, pull_enable: no_init}
  - {pin_num: '4', peripheral: OCCS, signal: XTAL, pin_signal: GPIOC1/XTAL, slew_rate: no_init, open_drain: no_init, pull_select: no_init, pull_enable: no_init}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitOSCsPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitOSCsPins(void)
{
    /* GPIOC IPBus Clock Enable: The peripheral is clocked. */
    CLOCK_EnableClock(kCLOCK_GPIOC);
    /* Enable peripheral functionality on pin GPIOC0 (pin 3) */
    GPIO_PinSetPeripheralMode(BOARD_EXTAL_GPIO, BOARD_EXTAL_PIN_MASK, kGPIO_ModePeripheral);
    /* Peripheral functionality on pin GPIOC0 (pin 3) */
    GPIO_PinSetPeripheralMux(kGPIO_Peri_C0_EXTAL);
    /* Enable peripheral functionality on pin GPIOC1 (pin 4) */
    GPIO_PinSetPeripheralMode(BOARD_XTAL_GPIO, BOARD_XTAL_PIN_MASK, kGPIO_ModePeripheral);
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitTHERMISTORPins:
- options: {callFromInitBoot: 'false', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '17', peripheral: ADC, signal: 'ANA, 7', pin_signal: GPIOA7/ANA7}
  - {pin_num: '19', peripheral: ADC, signal: 'ANA, 6', pin_signal: GPIOA6/ANA6}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitTHERMISTORPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitTHERMISTORPins(void)
{
    /* GPIOA IPBus Clock Enable: The peripheral is clocked. */
    CLOCK_EnableClock(kCLOCK_GPIOA);
    /* Enable peripheral functionality on pin GPIOA6 (pin 19) */
    GPIO_PinSetPeripheralMode(BOARD_THER_A_GPIO, BOARD_THER_A_PIN_MASK, kGPIO_ModePeripheral);
    /* Enable peripheral functionality on pin GPIOA7 (pin 17) */
    GPIO_PinSetPeripheralMode(BOARD_THER_B_GPIO, BOARD_THER_B_PIN_MASK, kGPIO_ModePeripheral);
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitUSBOTGPins:
- options: {callFromInitBoot: 'false', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '90', peripheral: GPIOF, signal: 'GPIO, 13', pin_signal: GPIOF13/MOSI1/PWMB_FAULT1, direction: OUTPUT, gpio_init_state: 'false', open_drain: disable,
    pull_select: up}
  - {pin_num: '91', peripheral: GPIOF, signal: 'GPIO, 14', pin_signal: GPIOF14/SCLK1/PWMB_FAULT0, direction: OUTPUT}
  - {pin_num: '39', peripheral: USB, signal: DP, pin_signal: USB_DP}
  - {pin_num: '40', peripheral: USB, signal: DM, pin_signal: USB_DM}
  - {pin_num: '89', peripheral: GPIOF, signal: 'GPIO, 12', pin_signal: GPIOF12/MISO1/PWMB_FAULT2, direction: INPUT, pull_select: up, pull_enable: enable}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitUSBOTGPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitUSBOTGPins(void)
{
    /* GPIOF IPBus Clock Enable: The peripheral is clocked. */
    CLOCK_EnableClock(kCLOCK_GPIOF);
    /* GPIO functionality on pin GPIOF12 (pin 89) */
    GPIO_PinSetPeripheralMode(BOARD_USB_OTG_ID_GPIO, BOARD_USB_OTG_ID_PIN_MASK, kGPIO_ModeGpio);
    /* GPIO functionality on pin GPIOF13 (pin 90) */
    GPIO_PinSetPeripheralMode(BOARD_USB_PWR_GPIO, BOARD_USB_PWR_PIN_MASK, kGPIO_ModeGpio);
    /* GPIO functionality on pin GPIOF14 (pin 91) */
    GPIO_PinSetPeripheralMode(BOARD_USB_OC_GPIO, BOARD_USB_OC_PIN_MASK, kGPIO_ModeGpio);

    /* Initialize GPIO functionality on pin GPIOF12 (pin 89)  */
    GPIO_PinSetDirection(BOARD_USB_OTG_ID_GPIO, BOARD_USB_OTG_ID_PIN_MASK, kGPIO_DigitalInput);

    /* Pin configuration on GPIOF12 (pin 89) */
    /* Pull mode configuration: Internal pull-up resistor is enabled */
    GPIO_PinSetPullResistorMode(BOARD_USB_OTG_ID_GPIO, BOARD_USB_OTG_ID_PIN_MASK, kGPIO_PullUp);

    /* Pin configuration on GPIOF13 (pin 90) */
    /* Pull-Pull/Open drain output mode configuration: Push pull output mode */
    GPIO_PinSetOutputMode(BOARD_USB_PWR_GPIO, BOARD_USB_PWR_PIN_MASK, kGPIO_OutputPushPull);

    /* Initialize GPIO functionality on pin GPIOF13 (pin 90)  */
    GPIO_PinWrite(BOARD_USB_PWR_GPIO, BOARD_USB_PWR_PIN_MASK, kGPIO_OutputLow);
    GPIO_PinSetDirection(BOARD_USB_PWR_GPIO, BOARD_USB_PWR_PIN_MASK, kGPIO_DigitalOutput);

    /* Initialize GPIO functionality on pin GPIOF14 (pin 91)  */
    GPIO_PinWrite(BOARD_USB_OC_GPIO, BOARD_USB_OC_PIN_MASK, kGPIO_OutputLow);
    GPIO_PinSetDirection(BOARD_USB_OC_GPIO, BOARD_USB_OC_PIN_MASK, kGPIO_DigitalOutput);

    GPIOF->PUS = ((GPIOF->PUS &
                   /* Mask bits to zero which are setting */
                   (~(GPIO_PUS_PUS_13_MASK)))

                  /* Pull Resistor Type Select Bits: Pullup resistor. */
                  | GPIO_PUS_PUS(PUS_PUS_13_PULLUP));
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitSPI_FLASHPins:
- options: {callFromInitBoot: 'false', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '48', peripheral: QSPI1, signal: MOSI, pin_signal: GPIOG11/TB3/CLKO0/MOSI1}
  - {pin_num: '47', peripheral: QSPI1, signal: MISO, pin_signal: GPIOD7/XB_OUT11/XB_IN7/MISO1}
  - {pin_num: '55', peripheral: QSPI1, signal: SCLK, pin_signal: GPIOF0/XB_IN6/TB2/SCLK1}
  - {pin_num: '95', peripheral: QSPI1, signal: SS, pin_signal: GPIOF7/TB3/CMPC_O/SS1_B/XB_IN3}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitSPI_FLASHPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitSPI_FLASHPins(void)
{
    /* GPIOD IPBus Clock Enable: The peripheral is clocked. */
    CLOCK_EnableClock(kCLOCK_GPIOD);
    /* GPIOF IPBus Clock Enable: The peripheral is clocked. */
    CLOCK_EnableClock(kCLOCK_GPIOF);
    /* GPIOG IPBus Clock Enable: The peripheral is clocked. */
    CLOCK_EnableClock(kCLOCK_GPIOG);
    /* Enable peripheral functionality on pin GPIOD7 (pin 47) */
    GPIO_PinSetPeripheralMode(BOARD_SPI_FLASH_MISO_GPIO, BOARD_SPI_FLASH_MISO_PIN_MASK, kGPIO_ModePeripheral);
    /* Peripheral functionality on pin GPIOD7 (pin 47) */
    GPIO_PinSetPeripheralMux(kGPIO_Peri_D7_MISO1);
    /* Enable peripheral functionality on pin GPIOF0 (pin 55) */
    GPIO_PinSetPeripheralMode(BOARD_SPI_FLASH_SCLK_GPIO, BOARD_SPI_FLASH_SCLK_PIN_MASK, kGPIO_ModePeripheral);
    /* Peripheral functionality on pin GPIOF0 (pin 55) */
    GPIO_PinSetPeripheralMux(kGPIO_Peri_F0_SCLK1);
    /* Enable peripheral functionality on pin GPIOF7 (pin 95) */
    GPIO_PinSetPeripheralMode(BOARD_SPI_FLASH_SS_GPIO, BOARD_SPI_FLASH_SS_PIN_MASK, kGPIO_ModePeripheral);
    /* Peripheral functionality on pin GPIOF7 (pin 95) */
    GPIO_PinSetPeripheralMux(kGPIO_Peri_F7_SS1_B);
    /* Enable peripheral functionality on pin GPIOG11 (pin 48) */
    GPIO_PinSetPeripheralMode(BOARD_SPI_FLASH_MOSI_GPIO, BOARD_SPI_FLASH_MOSI_PIN_MASK, kGPIO_ModePeripheral);
    /* Peripheral functionality on pin GPIOG11 (pin 48) */
    GPIO_PinSetPeripheralMux(kGPIO_Peri_G11_MOSI1);
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPWM_LEDsPins:
- options: {callFromInitBoot: 'false', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '68', peripheral: PWMA, signal: 'B, 0', pin_signal: GPIOE0/PWMA_0B/XB_OUT4, direction: OUTPUT}
  - {pin_num: '69', peripheral: PWMA, signal: 'A, 0', pin_signal: GPIOE1/PWMA_0A/XB_OUT5, direction: OUTPUT}
  - {pin_num: '74', peripheral: PWMA, signal: 'B, 1', pin_signal: GPIOE2/PWMA_1B/XB_OUT6, direction: OUTPUT}
  - {pin_num: '75', peripheral: PWMA, signal: 'A, 1', pin_signal: GPIOE3/PWMA_1A/XB_OUT7, direction: OUTPUT}
  - {pin_num: '82', peripheral: PWMA, signal: 'B, 2', pin_signal: GPIOE4/PWMA_2B/XB_IN2/XB_OUT8, direction: OUTPUT}
  - {pin_num: '83', peripheral: PWMA, signal: 'A, 2', pin_signal: GPIOE5/PWMA_2A/XB_IN3/XB_OUT9, direction: OUTPUT}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPWM_LEDsPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPWM_LEDsPins(void)
{
    /* GPIOE IPBus Clock Enable: The peripheral is clocked. */
    CLOCK_EnableClock(kCLOCK_GPIOE);
    /* Enable peripheral functionality on pin GPIOE0 (pin 68) */
    GPIO_PinSetPeripheralMode(BOARD_PWM_LED0_GPIO, BOARD_PWM_LED0_PIN_MASK, kGPIO_ModePeripheral);
    /* Peripheral functionality on pin GPIOE0 (pin 68) */
    GPIO_PinSetPeripheralMux(kGPIO_Peri_E0_PWMA_0B);
    /* Enable peripheral functionality on pin GPIOE1 (pin 69) */
    GPIO_PinSetPeripheralMode(BOARD_PWM_LED1_GPIO, BOARD_PWM_LED1_PIN_MASK, kGPIO_ModePeripheral);
    /* Peripheral functionality on pin GPIOE1 (pin 69) */
    GPIO_PinSetPeripheralMux(kGPIO_Peri_E1_PWMA_0A);
    /* Enable peripheral functionality on pin GPIOE2 (pin 74) */
    GPIO_PinSetPeripheralMode(BOARD_PWM_LED2_GPIO, BOARD_PWM_LED2_PIN_MASK, kGPIO_ModePeripheral);
    /* Peripheral functionality on pin GPIOE2 (pin 74) */
    GPIO_PinSetPeripheralMux(kGPIO_Peri_E2_PWMA_1B);
    /* Enable peripheral functionality on pin GPIOE3 (pin 75) */
    GPIO_PinSetPeripheralMode(BOARD_PWM_LED3_GPIO, BOARD_PWM_LED3_PIN_MASK, kGPIO_ModePeripheral);
    /* Peripheral functionality on pin GPIOE3 (pin 75) */
    GPIO_PinSetPeripheralMux(kGPIO_Peri_E3_PWMA_1A);
    /* Enable peripheral functionality on pin GPIOE4 (pin 82) */
    GPIO_PinSetPeripheralMode(BOARD_PWM_LED4_GPIO, BOARD_PWM_LED4_PIN_MASK, kGPIO_ModePeripheral);
    /* Peripheral functionality on pin GPIOE4 (pin 82) */
    GPIO_PinSetPeripheralMux(kGPIO_Peri_E4_PWMA_2B);
    /* Enable peripheral functionality on pin GPIOE5 (pin 83) */
    GPIO_PinSetPeripheralMode(BOARD_PWM_LED5_GPIO, BOARD_PWM_LED5_PIN_MASK, kGPIO_ModePeripheral);
    /* Peripheral functionality on pin GPIOE5 (pin 83) */
    GPIO_PinSetPeripheralMux(kGPIO_Peri_E5_PWMA_2A);
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitACCEL_MAGNET_I2CPins:
- options: {callFromInitBoot: 'false', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '60', peripheral: I2C1, signal: SCL, pin_signal: GPIOF2/SCL1/XB_OUT6/MISO1, open_drain: enable, pull_select: up, pull_enable: enable}
  - {pin_num: '61', peripheral: I2C1, signal: SDA, pin_signal: GPIOF3/SDA1/XB_OUT7/MOSI1, open_drain: enable, pull_select: up, pull_enable: enable}
  - {pin_num: '18', peripheral: GPIOA, signal: 'GPIO, 8', pin_signal: GPIOA8/CMPD_IN1, direction: INPUT, gpio_interrupt: gpioIrqRisingEdge, pull_enable: disable}
  - {pin_num: '14', peripheral: GPIOA, signal: 'GPIO, 9', pin_signal: GPIOA9/CMPD_IN2, direction: INPUT, gpio_interrupt: gpioIrqRisingEdge, pull_enable: disable}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitACCEL_MAGNET_I2CPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitACCEL_MAGNET_I2CPins(void)
{
    /* GPIOA IPBus Clock Enable: The peripheral is clocked. */
    CLOCK_EnableClock(kCLOCK_GPIOA);
    /* GPIOF IPBus Clock Enable: The peripheral is clocked. */
    CLOCK_EnableClock(kCLOCK_GPIOF);
    /* GPIO functionality on pin GPIOA8 (pin 18) */
    GPIO_PinSetPeripheralMode(BOARD_ACCEL_MAGNET_INT1_GPIO, BOARD_ACCEL_MAGNET_INT1_PIN_MASK, kGPIO_ModeGpio);
    /* GPIO functionality on pin GPIOA9 (pin 14) */
    GPIO_PinSetPeripheralMode(BOARD_ACCEL_MAGNET_INT2_GPIO, BOARD_ACCEL_MAGNET_INT2_PIN_MASK, kGPIO_ModeGpio);
    /* Enable peripheral functionality on pin GPIOF2 (pin 60) */
    GPIO_PinSetPeripheralMode(BOARD_ACCEL_MAGNET_SCL_GPIO, BOARD_ACCEL_MAGNET_SCL_PIN_MASK, kGPIO_ModePeripheral);
    /* Peripheral functionality on pin GPIOF2 (pin 60) */
    GPIO_PinSetPeripheralMux(kGPIO_Peri_F2_SCL1);
    /* Enable peripheral functionality on pin GPIOF3 (pin 61) */
    GPIO_PinSetPeripheralMode(BOARD_ACCEL_MAGNET_SDA_GPIO, BOARD_ACCEL_MAGNET_SDA_PIN_MASK, kGPIO_ModePeripheral);
    /* Peripheral functionality on pin GPIOF3 (pin 61) */
    GPIO_PinSetPeripheralMux(kGPIO_Peri_F3_SDA1);

    /* Initialize GPIO functionality on pin GPIOA8 (pin 18)  */
    GPIO_PinSetDirection(BOARD_ACCEL_MAGNET_INT1_GPIO, BOARD_ACCEL_MAGNET_INT1_PIN_MASK, kGPIO_DigitalInput);

    /* Initialize GPIO functionality on pin GPIOA9 (pin 14)  */
    GPIO_PinSetDirection(BOARD_ACCEL_MAGNET_INT2_GPIO, BOARD_ACCEL_MAGNET_INT2_PIN_MASK, kGPIO_DigitalInput);

    /* Pin configuration on GPIOF2 (pin 60) */
    /* Pull mode configuration: Internal pull-up resistor is enabled */
    GPIO_PinSetPullResistorMode(BOARD_ACCEL_MAGNET_SCL_GPIO, BOARD_ACCEL_MAGNET_SCL_PIN_MASK, kGPIO_PullUp);
    /* Pull-Pull/Open drain output mode configuration: Open drain output mode */
    GPIO_PinSetOutputMode(BOARD_ACCEL_MAGNET_SCL_GPIO, BOARD_ACCEL_MAGNET_SCL_PIN_MASK, kGPIO_OutputOpenDrain);

    /* Pin configuration on GPIOF3 (pin 61) */
    /* Pull mode configuration: Internal pull-up resistor is enabled */
    GPIO_PinSetPullResistorMode(BOARD_ACCEL_MAGNET_SDA_GPIO, BOARD_ACCEL_MAGNET_SDA_PIN_MASK, kGPIO_PullUp);
    /* Pull-Pull/Open drain output mode configuration: Open drain output mode */
    GPIO_PinSetOutputMode(BOARD_ACCEL_MAGNET_SDA_GPIO, BOARD_ACCEL_MAGNET_SDA_PIN_MASK, kGPIO_OutputOpenDrain);

    /* Interrupt configuration on GPIOA8 (pin 18): Interrupt on rising edge */
    GPIO_PinSetInterruptConfig(BOARD_ACCEL_MAGNET_INT1_GPIO, BOARD_ACCEL_MAGNET_INT1_PIN_MASK, kGPIO_InterruptRisingEdge);

    /* Interrupt configuration on GPIOA9 (pin 14): Interrupt on rising edge */
    GPIO_PinSetInterruptConfig(BOARD_ACCEL_MAGNET_INT2_GPIO, BOARD_ACCEL_MAGNET_INT2_PIN_MASK, kGPIO_InterruptRisingEdge);

    GPIOA->PUR = ((GPIOA->PUR &
                   /* Mask bits to zero which are setting */
                   (~(GPIO_PUR_PU_8_MASK | GPIO_PUR_PU_9_MASK)))

                  /* Pull Resistor Enable Bits: Pull resistor is disabled. */
                  | GPIO_PUR_PU(PUR_PU_8_DISABLED)

                  /* Pull Resistor Enable Bits: Pull resistor is disabled. */
                  | GPIO_PUR_PU(PUR_PU_9_DISABLED));
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitUSBtoSCIPins:
- options: {callFromInitBoot: 'false', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '5', peripheral: QSCI0, signal: TXD, pin_signal: GPIOC2/TXD0/TB0/XB_IN2/CLKO0}
  - {pin_num: '11', peripheral: QSCI0, signal: RXD, pin_signal: GPIOC3/TA0/CMPA_O/RXD0/CLKIN1}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitUSBtoSCIPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitUSBtoSCIPins(void)
{
    /* GPIOC IPBus Clock Enable: The peripheral is clocked. */
    CLOCK_EnableClock(kCLOCK_GPIOC);
    /* Enable peripheral functionality on pin GPIOC2 (pin 5) */
    GPIO_PinSetPeripheralMode(BOARD_Boot_TXD0_GPIO, BOARD_Boot_TXD0_PIN_MASK, kGPIO_ModePeripheral);
    /* Peripheral functionality on pin GPIOC2 (pin 5) */
    GPIO_PinSetPeripheralMux(kGPIO_Peri_C2_TXD0);
    /* Enable peripheral functionality on pin GPIOC3 (pin 11) */
    GPIO_PinSetPeripheralMode(BOARD_Boot_RXD0_GPIO, BOARD_Boot_RXD0_PIN_MASK, kGPIO_ModePeripheral);
    /* Peripheral functionality on pin GPIOC3 (pin 11) */
    GPIO_PinSetPeripheralMux(kGPIO_Peri_C3_RXD0);
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitCANPins:
- options: {callFromInitBoot: 'false', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '58', peripheral: CAN0, signal: TX, pin_signal: GPIOC11/CANTX/SCL1/TXD1, pull_enable: disable}
  - {pin_num: '59', peripheral: CAN0, signal: RX, pin_signal: GPIOC12/CANRX/SDA1/RXD1}
  - {pin_num: '13', peripheral: GPIOA, signal: 'GPIO, 10', pin_signal: GPIOA10/CMPD_IN3, direction: OUTPUT, pull_enable: disable}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitCANPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitCANPins(void)
{
    /* GPIOA IPBus Clock Enable: The peripheral is clocked. */
    CLOCK_EnableClock(kCLOCK_GPIOA);
    /* GPIOC IPBus Clock Enable: The peripheral is clocked. */
    CLOCK_EnableClock(kCLOCK_GPIOC);
    /* GPIO functionality on pin GPIOA10 (pin 13) */
    GPIO_PinSetPeripheralMode(BOARD_CAN_S_GPIO, BOARD_CAN_S_PIN_MASK, kGPIO_ModeGpio);
    /* Enable peripheral functionality on pin GPIOC11 (pin 58) */
    GPIO_PinSetPeripheralMode(BOARD_CAN_TX_GPIO, BOARD_CAN_TX_PIN_MASK, kGPIO_ModePeripheral);
    /* Peripheral functionality on pin GPIOC11 (pin 58) */
    GPIO_PinSetPeripheralMux(kGPIO_Peri_C11_CANTX);
    /* Enable peripheral functionality on pin GPIOC12 (pin 59) */
    GPIO_PinSetPeripheralMode(BOARD_CAN_RX_GPIO, BOARD_CAN_RX_PIN_MASK, kGPIO_ModePeripheral);
    /* Peripheral functionality on pin GPIOC12 (pin 59) */
    GPIO_PinSetPeripheralMux(kGPIO_Peri_C12_CANRX);

    /* Initialize GPIO functionality on pin GPIOA10 (pin 13)  */
    GPIO_PinWrite(BOARD_CAN_S_GPIO, BOARD_CAN_S_PIN_MASK, kGPIO_OutputLow);
    GPIO_PinSetDirection(BOARD_CAN_S_GPIO, BOARD_CAN_S_PIN_MASK, kGPIO_DigitalOutput);

    GPIOA->PUR = ((GPIOA->PUR &
                   /* Mask bits to zero which are setting */
                   (~(GPIO_PUR_PU_10_MASK)))

                  /* Pull Resistor Enable Bits: Pull resistor is disabled. */
                  | GPIO_PUR_PU(PUR_PU_10_DISABLED));

    GPIOC->PUR = ((GPIOC->PUR &
                   /* Mask bits to zero which are setting */
                   (~(GPIO_PUR_PU_11_MASK)))

                  /* Pull Resistor Enable Bits: Pull resistor is disabled. */
                  | GPIO_PUR_PU(PUR_PU_11_DISABLED));
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitANA_SENSEPins:
- options: {callFromInitBoot: 'false', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '22', peripheral: ADC, signal: 'ANA, 0', pin_signal: GPIOA0/ANA0/CMPA_IN3/CMPC_O}
  - {pin_num: '23', peripheral: ADC, signal: 'ANA, 1', pin_signal: GPIOA1/ANA1/CMPA_IN0}
  - {pin_num: '33', peripheral: ADC, signal: 'ANB, 0', pin_signal: GPIOB0/ANB0/CMPB_IN3}
  - {pin_num: '42', peripheral: ADC, signal: 'ANB, 3', pin_signal: GPIOB3/ANB3/VREFLB/CMPC_IN0}
  - {pin_num: '36', peripheral: ADC, signal: 'ANB, 2', pin_signal: GPIOB2/ANB2/VREFHB/CMPC_IN3}
  - {pin_num: '24', peripheral: ADC, signal: 'ANA, 2', pin_signal: GPIOA2/ANA2/VREFHA/CMPA_IN1}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitANA_SENSEPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitANA_SENSEPins(void)
{
    /* GPIOA IPBus Clock Enable: The peripheral is clocked. */
    CLOCK_EnableClock(kCLOCK_GPIOA);
    /* GPIOB IPBus Clock Enable: The peripheral is clocked. */
    CLOCK_EnableClock(kCLOCK_GPIOB);
    /* Enable peripheral functionality on pin GPIOA0 (pin 22) */
    GPIO_PinSetPeripheralMode(BOARD_CUR_A_GPIO, BOARD_CUR_A_PIN_MASK, kGPIO_ModePeripheral);
    /* Peripheral functionality on pin GPIOA0 (pin 22) */
    GPIO_PinSetPeripheralMux(kGPIO_Peri_A0_ANA0_and_CMPA_IN3);
    /* Enable peripheral functionality on pin GPIOA1 (pin 23) */
    GPIO_PinSetPeripheralMode(BOARD_CUR_CA_GPIO, BOARD_CUR_CA_PIN_MASK, kGPIO_ModePeripheral);
    /* Enable peripheral functionality on pin GPIOA2 (pin 24) */
    GPIO_PinSetPeripheralMode(BOARD_VOLT_DCB_GPIO, BOARD_VOLT_DCB_PIN_MASK, kGPIO_ModePeripheral);
    /* Enable peripheral functionality on pin GPIOB0 (pin 33) */
    GPIO_PinSetPeripheralMode(BOARD_CUR_B_GPIO, BOARD_CUR_B_PIN_MASK, kGPIO_ModePeripheral);
    /* Enable peripheral functionality on pin GPIOB2 (pin 36) */
    GPIO_PinSetPeripheralMode(BOARD_CUR_DCB_GPIO, BOARD_CUR_DCB_PIN_MASK, kGPIO_ModePeripheral);
    /* Enable peripheral functionality on pin GPIOB3 (pin 42) */
    GPIO_PinSetPeripheralMode(BOARD_CUR_CB_GPIO, BOARD_CUR_CB_PIN_MASK, kGPIO_ModePeripheral);
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitADC_CMPPins:
- options: {callFromInitBoot: 'false', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '26', peripheral: ADC, signal: 'ANB, 7', pin_signal: GPIOB7/ANB7/CMPB_IN2}
  - {pin_num: '28', peripheral: CMPB, signal: 'IN, 1', pin_signal: GPIOB6/ANB6/CMPB_IN1}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitADC_CMPPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitADC_CMPPins(void)
{
    /* GPIOB IPBus Clock Enable: The peripheral is clocked. */
    CLOCK_EnableClock(kCLOCK_GPIOB);
    /* Enable peripheral functionality on pin GPIOB6 (pin 28) */
    GPIO_PinSetPeripheralMode(BOARD_CMPB_IN1_GPIO, BOARD_CMPB_IN1_PIN_MASK, kGPIO_ModePeripheral);
    /* Enable peripheral functionality on pin GPIOB7 (pin 26) */
    GPIO_PinSetPeripheralMode(BOARD_ANVP_GPIO, BOARD_ANVP_PIN_MASK, kGPIO_ModePeripheral);
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitDEBUG_UARTPins:
- options: {callFromInitBoot: 'true', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '9', peripheral: QSCI2, signal: TXD, pin_signal: GPIOD6/TXD2/XB_IN4/XB_OUT8}
  - {pin_num: '10', peripheral: QSCI2, signal: RXD, pin_signal: GPIOD5/RXD2/XB_IN5/XB_OUT9}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitDEBUG_UARTPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitDEBUG_UARTPins(void)
{
    /* GPIOD IPBus Clock Enable: The peripheral is clocked. */
    CLOCK_EnableClock(kCLOCK_GPIOD);
    /* Enable peripheral functionality on pin GPIOD5 (pin 10) */
    GPIO_PinSetPeripheralMode(BOARD_RXD_BDM_GPIO, BOARD_RXD_BDM_PIN_MASK, kGPIO_ModePeripheral);
    /* Peripheral functionality on pin GPIOD5 (pin 10) */
    GPIO_PinSetPeripheralMux(kGPIO_Peri_D5_RXD2);
    /* Enable peripheral functionality on pin GPIOD6 (pin 9) */
    GPIO_PinSetPeripheralMode(BOARD_TXD_BDM_GPIO, BOARD_TXD_BDM_PIN_MASK, kGPIO_ModePeripheral);
    /* Peripheral functionality on pin GPIOD6 (pin 9) */
    GPIO_PinSetPeripheralMux(kGPIO_Peri_D6_TXD2);
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
