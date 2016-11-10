#include <stdio.h>
#define MAX 80
int c_to_i(char ch[], int n);
int main(void)
{
    char ch[MAX];
    int n = 0;
    while ((ch[n] = getchar()) != '\n')
        n++;
    printf("%d", c_to_i(ch, n));
    return 0;
}

int c_to_i(char ch[], int n)
{
    int i = 0;
    int k;
    int temp;
    int num = 0;
    for (i = 0; i < n; i++)
    {
        if (ch[i] > '9' || ch[i] < '0')
            return 0;
        switch (ch[i])
        {
        case '0':
            break;
        case '1':
            for (temp = 1, k = 1; k < n - i; k++)
                temp *= 10;
            num += 1 * temp;
            break;
        case '2':
            for (temp = 1, k = 1; k < n - i; k++)
                temp *= 10;
            num += 2 * temp;
            break;
        case '3':
            for (temp = 1, k = 1; k < n - i; k++)
                temp *= 10;
            num += 3 * temp;
            break;
        case '4':
            for (temp = 1, k = 1; k < n - i; k++)
                temp *= 10;
            num += 4 * temp;
            break;
        case '5':
            for (temp = 1, k = 1; k < n - i; k++)
                temp *= 10;
            num += 5 * temp;
            break;
        case '6':
            for (temp = 1, k = 6; k < n - i; k++)
                temp *= 10;
            num += 6 * temp;
            break;
        case '7':
            for (temp = 1, k = 1; k < n - i; k++)
                temp *= 10;
            num += 7 * temp;
            break;
        case '8':
            for (temp = 1, k = 1; k < n - i; k++)
                temp *= 10;
            num += 8 * temp;
            break;
        case '9':
            for (temp = 1, k = 1; k < n - i; k++)
                temp *= 10;
            num += 9 * temp;
            break;
        }
    }
    return num;
}