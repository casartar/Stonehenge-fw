#include "charlieplexing.h"

enum MultiPin
{
    D4,
    D5,
    D6,
    D7,
    D8,
    D9
};

void SetAllPinsToTristate();
void SetPin(enum MultiPin pin, GPIO_PinState PinState);

void charlieplexing_SetLed(enum Led led)
{
    SetAllPinsToTristate();

    switch (led)
    {
    case None:
        break;
    case D_158:
        SetPin(D5, GPIO_PIN_RESET);
        SetPin(D9, GPIO_PIN_SET);
        break;
    case D_122:
        SetPin(D5, GPIO_PIN_SET);
        SetPin(D9, GPIO_PIN_RESET);
        break;
    case D_152:
        SetPin(D7, GPIO_PIN_SET);
        SetPin(D8, GPIO_PIN_RESET);
        break;
    case D_154:
        SetPin(D7, GPIO_PIN_RESET);
        SetPin(D8, GPIO_PIN_SET);
        break;
    case D_105:
        SetPin(D6, GPIO_PIN_RESET);
        SetPin(D7, GPIO_PIN_SET);
        break;
    case D_107:
        SetPin(D6, GPIO_PIN_SET);
        SetPin(D7, GPIO_PIN_RESET);
        break;
    case D_102:
        SetPin(D6, GPIO_PIN_SET);
        SetPin(D8, GPIO_PIN_RESET);
        break;
    case D_101:
        SetPin(D5, GPIO_PIN_RESET);
        SetPin(D6, GPIO_PIN_SET);
        break;
    case D_130:
        SetPin(D5, GPIO_PIN_SET);
        SetPin(D7, GPIO_PIN_RESET);
        break;
    case D_2_Sun:
        SetPin(D4, GPIO_PIN_SET);
        SetPin(D7, GPIO_PIN_RESET);
        break;
    case D_1_Altar:
        SetPin(D7, GPIO_PIN_RESET);
        SetPin(D9, GPIO_PIN_SET);
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

void SetPin(enum MultiPin pin, GPIO_PinState PinState)
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