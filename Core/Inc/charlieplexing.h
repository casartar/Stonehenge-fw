#ifndef __CHARLIEPLEXING_H
#define __CHARLIEPLEXING_H

#include "main.h"
#include <stdbool.h>

enum Leds
{
    D_158,
    D_122,
    D_152,
    D_154,
    D_105,
    D_107,
    D_102,
    D_101,
    D_130,
    D_2_Sun,
    D_1_Altar,
    D_Size
};

void charlieplexing_Handler();
void charlieplexing_SetLedState(enum Leds led, bool state);
void charlieplexing_SetAllLedsOff();

#endif