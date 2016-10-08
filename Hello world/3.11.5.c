#include <stdio.h>
int main(void)
{
    int age;
    float second;
    printf("Enter your age:");
    scanf("%d",&age);
    second = age * 3.156e7;
    printf("\n You have lived %e second",second);
    return 0;
}