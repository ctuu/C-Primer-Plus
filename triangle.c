#include <stdio.h>
int main(void)
{
    float ls, lr, lt;
    printf("Enter the length of the three lines:\n");
    scanf("%f%f%f", &ls, &lr, &lt);
    if (ls + lr <= lt || ls + lt <= lr || lr + lt <= ls)
        printf("They can not constitute a triangle.");
    else
    {
        printf("This is a(an) ");
        if (ls == lr && lr == lt)
            printf("Equilateral ");
        else
        {
            if (ls == lr || ls == lt || lr == lt)
                printf("isosceles ");
            if (ls * ls + lr * lr == lt * lt || ls * ls + lt * lt == lr * lr || lt * lt + lr * lr == ls * ls)
                printf("right angle ");
            else if (ls * ls + lr * lr > lt * lt || ls * ls + lt * lt > lr * lr || lt * lt + lr * lr > ls * ls)
                printf("obtuse angle ");
            else
                printf("acute angle ");
        }
        printf("triangle.");
    }
    return 0;
}