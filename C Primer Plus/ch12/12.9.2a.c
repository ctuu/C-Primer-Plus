#include "12.9.2.h"
#include <stdio.h>

static int mode;
static int dis;
static float fuel;

void set_mode(int mo)
{
    if (mo != 0 && mo != 1)
    {
        printf("Invalid mode specified. ");
        if (mode == 1)
            printf("Mode 1(US) used\n");
        else
            printf("Mode 0(metric) used\n");
    }
    mode = mo;
}

void get_info(void)
{
    printf("Enter distance traveled in kilometers: ");
    scanf("%d", &dis);
    if (mode == 0)
        printf("Enter fuel consumed in liters: ");
    else
        printf("Enter fuel consmed in gallons: ");
    scanf("%f", &fuel);
}

void show_info(void)
{
    if (mode == 0)
        printf("Fuel consumption is %.2f liters per 100 km.\n", fuel / dis * 100);
    else
        printf("Fuel consumption is %.1f miles per gallon.\n", dis / fuel);
}