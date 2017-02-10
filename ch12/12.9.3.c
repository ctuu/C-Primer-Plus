#include <stdio.h>
void get_info(int * dis, float * fuel, int mode);
void show_info(int dis, float fuel, int mode);
int set_mode(int mode, int * mo);
int main(void)
{
    int mode, dis, mo;
    float fuel;
    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d", &mode);
    while (mode >= 0)
    {
        set_mode(mode, &mo);
        get_info(&dis, &fuel, mo);
        show_info(dis, fuel, mo);
        printf("Enter 0 for metric mode, 1 for US mode");
        printf(" (-1 to quit): ");
        scanf("%d", &mode);
    }
    printf("Done.\n");
    return 0;
}

int set_mode(int mode, int * mo)
{
    if (mode != 0 && mode != 1)
    {
        printf("Invalid mode specified. ");
        if (*mo == 1)
            printf("Mode 1(US) used\n");
        else
            printf("Mode 0(metric) used\n");
    }
    else
        *mo = mode;
}

void get_info(int * dis, float * fuel, int mode)
{
    printf("Enter distance traveled in kilometers: ");
    scanf("%d", dis);
    if (mode == 0)
        printf("Enter fuel consumed in liters: ");
    else
        printf("Enter fuel consmed in gallons: ");
    scanf("%f", fuel);
}

void show_info(int dis, float fuel, int mode)
{
    if (mode == 0)
        printf("Fuel consumption is %.2f liters per 100 km.\n", fuel / dis * 100);
    else
        printf("Fuel consumption is %.1f miles per gallon.\n", dis / fuel);
}