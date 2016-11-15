#include <stdio.h>
#include <stdlib.h>
int *make_array(int elem, int val);
void show_array(const int ar[], int n);
int main(void)
{
    int *pa;
    int size;
    int value;
    printf("Enter the number of elements: ");
    while (scanf("%d", &size) == 1 && size > 0)
    {
        printf("Enter the initiallization value: ");
        scanf("%d", &value);
        pa = make_array(size, value);
        if (pa)
        {
            show_array(pa, size);
            free(pa);
        }
        printf("Enter the number of elements (<1 to quit): ");
    }
    printf("Done.\n");
    return 0;
}

int *make_array(int elem, int val)
{
    int ct = 0;
    int *ptd;
    ptd = (int *)malloc(elem * sizeof(int));
    ptd[ct] = val;
    for (ct = 1; ct < elem; ct++)
        scanf("%d", &ptd[ct]);
    return ptd;
}

void show_array(const int ar[], int n)
{
    int ct;
    int cz;
    for (cz = 0, ct = 0; ct < n; ct++, cz++)
    {
        if (cz > 7)
        {
            printf("\n");
            cz = 0;
        }
        printf("%d ", ar[ct]);
    }
    printf("\n");
}