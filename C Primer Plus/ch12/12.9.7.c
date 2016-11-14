#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "diceroll.h"

int main(void)
{
    int dice, roll;
    int sides;
    int status;
    int sets;
    srand((unsigned int)time(0));
    printf("Enter the number of sets; enter q to stop: ");
    while (scanf("%d", &sets) == 1 && sets > 0)
    {
        printf("Enter the sides and how many dice? ");
        scanf("%d%d", &sides, &dice) == 1;
        printf("Here are %d sets of %d %d-sided dice.\n",
               sets, dice, sides);
        while (sets > 0)
        {
            roll = roll_n_dice(dice, sides);
            printf("%d ", roll);
            sets--;
        }
        printf("\nHow many sets? Enter q to stop: ");
    }
    return 0;
}