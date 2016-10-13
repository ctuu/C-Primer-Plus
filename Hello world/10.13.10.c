#include <stdio.h>
#define NUM 4
void add(int a[], int b[], int c[], int d);
int main(void)
{
    int one[NUM] = { 2, 4, 5, 8 };
    int two[NUM] = { 1, 0, 4, 6 };
    int three[NUM];
    int count = 0;
    add(one, two, three, NUM);
    for (;count < NUM; count++)
        printf("%d ", three[count]);
    
    return 0;
}

void add(int a[], int b[], int c[], int d)
{
    int count = 0;
    for (; count < d; count++)
        c[count] = a[count] + b[count];
}