#include<stdio.h>
int main(void)
{
    int age;
    int day;
    printf("Enter your age: ");
   scanf("%d", &age);
    day = age * 365 ;
    printf("\n %d age = %d day", age,day);
    return 0;
}