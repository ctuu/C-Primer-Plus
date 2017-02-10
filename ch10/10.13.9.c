#include <stdio.h>
void copy_vla(int n, int m, double tar[n][m], double sou[n][m]);
void pr(int n, int m, double tar[n][m], double sou[n][m]);
int main(void)
{
    int n = 3;
    int m = 5;
    double source[3][5] = {
        {1.8, 2.6, 3.5, 4.7, 5.8},
        {9.2, 2.4, 5.5, 6.3, 7.8},
        {2.3, 4.5, 6.8, 2.3, 8.3}};
    double target[n][m];
    copy_vla(n, m, target, source);
    pr(n, m, target, source);
    return 0;
}

void copy_vla(int n, int m, double tar[n][m], double sou[n][m])
{
    int a, b;
    for (a = 0; a < n; a++)
        for (b = 0; b < m; b++)
            tar[a][b] = sou[a][b];
}

void pr(int n, int m, double tar[n][m], double sou[n][m])
{
    int a, b;
    printf("source:\n");
    for (a = 0; a < n; a++)
    {
        for (b = 0; b < m; b++)
            printf("%.1lf ", sou[a][b]);
        printf("\n");
    }

    printf("\ntarget:\n");
    for (a = 0; a < n; a++)
    {
        for (b = 0; b < m; b++)
            printf("%.1lf ", tar[a][b]);
        printf("\n");
    }
}