#include <stdio.h>
void copy_arr(double tar[2][5], double sou[], int n, int m);
int main(void)
{
    double ori[2][5] = {0};
    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    copy_arr(ori, source, 2, 5);
    return 0;
}

void copy_arr(double tar[2][5], double sou[], int n, int m)
{
    int a, b;
    printf("copy_arr:\n");
    for (a = 0; a < n; a++)
        for (b = 0; b < m; b++)
            tar[a][b] = sou[b];
    for (a = 0; a < n; a++)
    {
        for (b = 0; b < m; b++)
            printf("%.1lf ", tar[a][b]);
        printf("\n");
    }
}