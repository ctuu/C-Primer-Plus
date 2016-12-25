#include <stdio.h>

void update(void);
void display(void);
void delay(void);

int hour, minute, second;

int main(void)
{
    int i;
    second = 0;
    minute = 0;
    hour = 0;
    for (i = 0; i < 1000000; i++)
    {
        update();
        display();
        delay();
    }
    return 0;
}

void update(void)
{
    second++;
    if (second == 60)
    {
        second = 0;
        minute++;
    }
    if (minute == 60)
    {
        minute = 0;
        hour++;
    }
    if (hour == 24)
        hour = 0;
}
void display(void)
{
    printf("%02d:%02d:%02d\n", hour, minute, second);
}
void delay(void)
{
    int t;
    for (t = 0; t < 100000000; t++)
        ;
}