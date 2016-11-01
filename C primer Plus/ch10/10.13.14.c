#include <stdio.h>

void tha(double ar[], int n);
double thb(double ar[], int n);
double thc(int COL, double ar[][COL], int n);
double thd(int COL, double ar[][COL], int n);
void the(int ROW, int COL, double ar[][COL]);
int main(void)
{
    int ROW, COL;
    scanf("%d%d",&ROW, &COL);
    int row, col;
    double num[ROW][COL];
    for (row = 0; row < ROW; row++)
    {
        printf("Enter %d number for %d/%d row:\n", COL, row + 1, ROW);
        tha(num[row], COL);
    }
    the(ROW, COL, num);
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

double thc(int COL, double ar[][COL], int n)
{
    int a, sum;
    for (a = 0, sum = 0; a < n * COL; a++)
        sum += ar[0][a];
    return sum / n / COL;
}

double thd(int COL, double ar[][COL], int n)
{
       int a, max;
    for (a = 0, max = 0; a < n * COL;a++)
        max = (max > ar[0][a]) ? max : ar[0][a];
    return max; 
}

void the(int ROW, int COL, double ar[][COL])
{
    int row, col;
    for (row = 0; row < ROW; row++)
        printf("aver of row %d is %lf:\n", row + 1, thb(ar[row], COL));
    printf("aver of all is %lf\n", thc(COL, ar, ROW));
    printf("the maximun of all is %lf", thd(COL, ar, ROW));
}