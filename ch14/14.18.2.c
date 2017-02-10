#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct month
{
    char name[10];
    char abbrev[3];
    int days;
    int monumb;
};

struct month months[12] =
    {
        {"January", "jan", 31, 1},
        {"February", "feb", 28, 2},
        {"March", "mar", 31, 3},
        {"April", "apr", 30, 4},
        {"May", "may", 31, 5},
        {"June", "jun", 30, 6},
        {"July", "jul", 31, 7},
        {"August", "aug", 31, 8},
        {"September", "sep", 30, 9},
        {"October", "oct", 31, 10},
        {"November", "Nov", 30, 11},
        {"December", "dec", 31, 12}};

int getin(void);
int calc(int y, int m, int d);
int dealm(void);

int main(void)
{
    printf("Please enter day, month, and year(month can be \"January\" or \"jan\" or \"1\"):\n");
    while (getin() == 0)
        printf("Next:\nPlease enter day, month, and year(month can be \"January\" or \"jan\" or \"1\":\n");
    printf("Bye.");
    return 0;
}

int getin(void)
{
    int y, m, d;
    if (scanf("%d", &d) == 1)
    {
        m = dealm();
        scanf("%d", &y);
        printf("%d\n", calc(y, m, d));
    }
    else
        return (-1);
    return 0;
}

int calc(int y, int m, int d)
{
    int total, index;
    if (m > 2 && ((y % 4 == 0 && y % 100 != 4) || y % 400 == 0))
        total = 1;
    else
        total = 0;

    for (index = 0; index < m - 1; index++)
        total += months[index].days;
    return (total + d);
}

int dealm(void)
{
    char mon[10];
    int index;
    char temp;
    getchar();
    for (index = 0; index < 10 && temp != ' ' && temp != '\n'; index++)
    {
        temp = getchar();
        mon[index] = temp;
        if (mon[index] == ' ' || mon[index] == '\n')
            mon[index] = '\0';
    }
    for (index = 0; index < 12; index++)
    {
        if (strcmp(months[index].name, mon) == 0 || strcmp(months[index].abbrev, mon) == 0)
            return index + 1;
    }
    return atoi(mon);
}