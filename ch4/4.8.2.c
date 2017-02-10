#include <stdio.h>
#include <string.h>
int main(void)
{
    char fname[40];
    char lname[40];
    printf("Enter your first name:\n");
    scanf("%s", fname);
    printf("Enter your last name:\n");
    scanf("%s", lname);
    printf("\"%s,%s\"\n",fname ,lname);
    printf("%20s\n%20s\n", fname, lname);
    printf("%-20s\n%-20s\n", fname, lname);
    printf("   %s\n   %s\n", fname, lname);
    return 0;
}