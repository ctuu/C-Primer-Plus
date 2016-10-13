#include <stdio.h>
void copy_ptr(double * tar, double * sou, int n);
int main(void)
{
    double source[7] = { 1.1, 2.3, 4.6, 3.7, 7.3, 8.2, 5.9 };
    double target[3];
    copy_ptr(target, source + 2, 3);
    return 0;
}

void copy_ptr(double * tar, double * sou, int n)
{
    int i = 0;
    printf("\n copy_ptr: ");
    for (;i < n; i++, tar++, sou++)
        {
            *tar = *sou;
            printf("%.1lf ", *tar);
        }  
}
