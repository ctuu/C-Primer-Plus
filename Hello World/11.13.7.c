#include <stdio.h>
#define MAX 80
#define LIM 5
void mystrncpy(char *s1, char *s2, int n);
int main(void)
{
    char s1[MAX];
    char s2[MAX];
    int n = LIM;
    while (fgets(s1, MAX, stdin) != NULL && fgets(s2, MAX, stdin) != NULL)
    {
        mystrncpy(s1, s2, n);
        printf("%s\nNext:\n", s1);
    }
    return 0;
}

void mystrncpy(char *s1, char *s2, int n)
{
    while (*s1 != '\n')
        s1++;
    while (n > 0)
    {
        *s1 = *s2;
        s1++;
        s2++;
        n--;
    }
    s1 = '\0';
}


