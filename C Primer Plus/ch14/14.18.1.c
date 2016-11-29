#include <stdio.h>
#include <string.h>

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
        {"April", "Apr", 30, 4},
        {"May", "may", 31, 5},
        {"June", "jun", 30, 6},
        {"July", "jul", 31, 7},
        {"August", "aug", 31, 8},
        {"September", "sep", 30, 9},
        {"October", "oct", 31, 10},
        {"November", "Nov", 30, 11},
        {"December", "dec", 31, 12}};

int days(char *month);

int main(void)
{
    char mon[10];
    scanf("%s", mon);
    printf("%d", days(mon));
    return 0;
}

int days(char *month)
{
    int index, total, en;
    for (en = -1, index = 0; index < 12; index++)
        if (strcmp(months[index].name, month) == 0)
            en = index;
    if (en == -1)
        return (-1);
    else
    {
        for (index = 0, total = 0; index <= en; index++)
            total += months[index].days;
        return (total);
    }
}