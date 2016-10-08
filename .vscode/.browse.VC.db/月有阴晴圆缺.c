#include <stdio.h>
int main(void)
{
    int co, day, i;
    for (scanf("%d", &co); co > 0; co--)
    {
        while (getchar() != '\n')
            continue;
        scanf("%d", &day);
        while (day < 1 || day > 92)
            scanf("%d", &day);
        while (getchar() != '\n')
            continue;
        int count[day];
        for (i = 0; i < day; i++)
            scanf("%d", &count[i]);
        if (day == 1)
            if (count[0] == 0)
                printf("UP\n");
            else if (count[0] == 15)
                printf("DOWN\n");
            else
                printf("-1\n");
        else if (count[day - 1] == 15)
            printf("DOWN\n");
        else if (count[day - 1] == 0)
            printf("UP\n");
        else if (count[day - 1] > count[day - 2])
            printf("UP\n");
        else
            printf("DOWN\n");
    }
    return 0;
}