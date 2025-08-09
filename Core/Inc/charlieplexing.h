#ifndef __CHARLIEPLEXING_H
#define __CHARLIEPLEXING_H

#include "main.h"

enum Led
{
    None,
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
    D_1_Altar
};

void charlieplexing_SetLed(enum Led led);

#endif