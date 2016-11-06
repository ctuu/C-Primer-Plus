#include <stdio.h>
short queen[4][4] =
    {
        {0, 1, 0, 0},
        {0, 0, 0, 1},
        {1, 0, 0, 0},
        {0, 0, 1, 0}};
void find(int x, int y);
int main(void)
{
    find(0, 0);
    return 0;
}

void find(int x, int y)
{
    if (x < 4)
    {
        if (y < 4)
        {
            printf("%hd", queen[x][y]);
            find(x, y + 1);
        }
        else
        {
            printf("\n");
        find(x + 1, 0);
        }
    }
}