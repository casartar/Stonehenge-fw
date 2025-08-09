#include "charlieplexing.h"
#include <stdbool.h>

enum MultiPin
{
    D4,
    D5,
    D6,
    D7,
    D8,
    D9
};

bool ledState[D_Size];

void SetLed(enum Leds led);
void SetAllPinsToTristate();
void SetPinState(enum MultiPin pin, GPIO_PinState PinState);

void charlieplexing_SetLedState(enum Leds led, bool state)
{
    if (led >= D_Size)
    {
        return;
    }

    ledState[led] = state;
}

void charlieplexing_SetAllLedsOff()
{
    for (size_t i = 0; i < D_Size; i++)
    {
        ledState[i] = false;
    }
    SetAllPinsToTristate();
}

// This is called from SysTick every 1 ms
void charlieplexing_Handler()
{
    static enum Leds led = 0;

    if (ledState[led])
    {
        SetLed(led);
    }
    led++;
    if (led == D_Size)
    {
        led = 0;
    }
}

void SetLed(enum Leds led)
{
    SetAllPinsToTristate();

    switch (led)
    {
    case D_158:
        SetPinState(D5, GPIO_PIN_RESET);
        SetPinState(D9, GPIO_PIN_SET);
        break;
    case D_122:
        SetPinState(D5, GPIO_PIN_SET);
        SetPinState(D9, GPIO_PIN_RESET);
        break;
    case D_152:
        SetPinState(D7, GPIO_PIN_SET);
        SetPinState(D8, GPIO_PIN_RESET);
        break;
    case D_154:
        SetPinState(D7, GPIO_PIN_RESET);
        SetPinState(D8, GPIO_PIN_SET);
        break;
    case D_105:
        SetPinState(D6, GPIO_PIN_RESET);
        SetPinState(D7, GPIO_PIN_SET);
        break;
    case D_107:
        SetPinState(D6, GPIO_PIN_SET);
        SetPinState(D7, GPIO_PIN_RESET);
        break;
    case D_102:
        SetPinState(D6, GPIO_PIN_SET);
        SetPinState(D8, GPIO_PIN_RESET);
        break;
    case D_101:
        SetPinState(D5, GPIO_PIN_RESET);
        SetPinState(D6, GPIO_PIN_SET);
        break;
    case D_130:
        SetPinState(D5, GPIO_PIN_SET);
        SetPinState(D7, GPIO_PIN_RESET);
        break;
    case D_2_Sun:
        SetPinState(D4, GPIO_PIN_SET);
        SetPinState(D7, GPIO_PIN_RESET);
        break;
    case D_1_Altar:
        SetPinState(D7, GPIO_PIN_RESET);
        SetPinState(D9, GPIO_PIN_SET);
        break;

    default:
        break;
    }
}

void SetAllPinsToTristate()
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

void SetPinState(enum MultiPin pin, GPIO_PinState PinState)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    switch (pin)
    {
    case D4:
        GPIO_InitStruct.Pin = GPIO_PIN_0;
        break;
    case D5:
        GPIO_InitStruct.Pin = GPIO_PIN_1;
        break;
    case D6:
        GPIO_InitStruct.Pin = GPIO_PIN_2;
        break;
    case D7:
        GPIO_InitStruct.Pin = GPIO_PIN_3;
        break;
    case D8:
        GPIO_InitStruct.Pin = GPIO_PIN_4;
        break;
    case D9:
        GPIO_InitStruct.Pin = GPIO_PIN_5;
        break;
    default:
        break;
    }

    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    HAL_GPIO_WritePin(GPIOA, GPIO_InitStruct.Pin, PinState);
}