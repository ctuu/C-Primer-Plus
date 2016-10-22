#include <stdio.h>
#define ROW 3
#define COL 5
void tha(double ar[], int n);
double thb(double ar[], int n);
double thc(double ar[][COL], int n);
double thd(double ar[][COL], int n);
void the(double ar[][COL]);
int main(void)
{
    int row, col;
    double num[ROW][COL];
    for (row = 0; row < ROW; row++)
    {
        printf("Enter %d number for %d/%d row:\n", COL, row + 1, ROW);
        tha(num[row], COL);
    }
    the(num);
    /*
    int a, b;
    for (a = 0; a < ROW; a++)
    {
        for (b = 0; b < COL; b++)
            printf("%.1lf ", num[a][b]);
        printf("\n");
    }
    */
    return 0;
}

void tha(double ar[], int n)
{
    int a;
    for (a = 0; a < n; a++)
        scanf("%lf", &ar[a]);
}

double thb(double ar[], int n)
{
    int a;
    int sum = 0;
    for (a = 0; a < n; a++)
        sum += ar[a];
    return sum / n;
}

double thc(double ar[][COL], int n)
{
    int a, sum;
    for (a = 0, sum = 0; a < n * COL; a++)
        sum += ar[0][a];
    return sum / n / COL;
}

double thd(double ar[][COL], int n)
{
       int a, max;
    for (a = 0, max = 0; a < n * COL;a++)
        max = (max > ar[0][a]) ? max : ar[0][a];
    return max; 
}

void the(double ar[][COL])
{
    int row, col;
    for (row = 0; row < ROW; row++)
        printf("aver of row %d is %lf:\n", row + 1, thb(ar[row], COL));
    printf("aver of all is %lf\n", thc(ar, ROW));
    printf("the maximun of all is %lf", thd(ar, ROW));
}