#include "diceroll.h"
#include <stdio.h>
#include <stdlib.h>

int roll_count = 0;

static int rollem(int sides)
{
    int roll;

    roll = rand() % sides + 1;
    ++roll_count;

    return roll;
}

int roll_n_dice(int dice, int sides)
{
    int d;
    int total = 0;
    if (sides < 2)
    {
        printf("Need at least 2 sides.\n");
        return -2;
    }
}