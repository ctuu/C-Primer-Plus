#include <stdio.h>
#include <string.h>
int main(void)
{
    char fname[40];
    char lname[40];
    int fn,ln;
    printf("Enter your first name:\n");
    scanf("%s", fname);
    printf("Enter your last name:\n");
    scanf("%s",lname);
    fn = strlen(fname);
    ln = strlen(lname);
    printf("%s %s\n", fname,lname);
    printf("%*d %*d\n", fn, fn, ln, ln);
    printf("%s %s\n", fname, lname);
    printf("%-*d %-*d", fn, fn, ln ,ln);
    return 0;
}