#include <stdio.h>
#define LIST 10
#define MAX 80
void m1(char ch[][MAX]);
void m2(char ch[][MAX]);
void m3(char ch[][MAX]);
void m4(char ch[][MAX]);

int main(void)
{
    char ch[LIST][MAX];
    int i;
    for (i = 0; i < LIST && fgets(ch[i], MAX, stdin) != NULL; i++)
        ;
    printf("*****************************************************************************\n"
           "1).print the original list of strings\n"
           "2).print the strings in ASCII collating sequence\n"
           "3).print the strings in order of increasing length\n"
           "4).print the strings in order of the length of the first word in the string\n"
           "5).quit\n"
           "*****************************************************************************\n");
    while (~scanf("%d", &i))
    {
        switch (i)
        {
        case 1:
            m1(ch);
            break;
        case 2:
            // m2(ch);
            break;
        case 3:
            // m3(ch);
            break;
        case 4:
            //m4(ch);
            break;
        case 5:
            puts("Done.");
            return 0;
        }
        printf("*****************************************************************************\n"
               "1).print the original list of strings\n"
               "2).print the strings in ASCII collating sequence\n"
               "3).print the strings in order of increasing length\n"
               "4).print the strings in order of the length of the first word in the string\n"
               "5).quit\n"
               "*****************************************************************************\n");
    }

    puts("Done.");
    return 0;
}

void m1(char ch[][MAX])
{
    int i;
    for (i = 0; i < LIST; i++)
        puts(ch[i]);
}
