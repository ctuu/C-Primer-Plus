#include <stdio.h>
int main(void)
{
    char fname[40];
    char lname[40];
    printf("Enter your first name:\n");
    scanf("%s", fname);
    printf("Enter your last name:\n");
    scanf("%s",lname);
    printf("%s,%s",fname ,lname);
    return 0;
}