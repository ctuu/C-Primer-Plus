#include <stdio.h>
void copy_arr(double tar[], double sou[], int n);
void copy_ptr(double * tar, double * sou, int n);
void copy_ptrs(double * tar, double * sou, double * end);
int main(void)
{
    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5];
    double target2[5];
    double target3[5];
    copy_arr(target1, source, 5);
    copy_ptr(target2, source, 5);
    copy_ptrs(target3, source, source + 5);
 return 0;
}

void copy_arr(double tar[], double sou[], int n)
{
    int i = 0;
    printf("\n copy_arr: ");
    for (;i < n; i++)
        {
            tar[i] = sou[i];
            printf("%.1lf ", tar[i]);
        }  
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

void copy_ptrs(double * tar, double * sou, double * end)
{
    int i = 0;
    printf("\n copy_ptrs: ");
    for (;sou < end; i++, tar++, sou++)
        {
            *tar = *sou;
            printf("%.1lf ", *tar);
        }  
}