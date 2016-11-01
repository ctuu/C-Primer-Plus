#include <stdio.h>
#include <string.h>
#define LIST 10
#define MAX 80

char *s_gets(char *st, int n);
void m1(char ch[][MAX], int k);
void m2(char *ch[], int i);
void m3(char *ch[], int i);
void m4(char ch[][MAX], int k);

int main(void)
{
    char ch[LIST][MAX];
    char *ch_1[LIST];
    int i;
    int k = 0;
    while (k < LIST && s_gets(ch[k], MAX) != NULL)
    {
        ch_1[k] = ch[k];
        k++;
    }
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
            m1(ch, k);
            break;
        case 2:
            m2(ch_1, k);
            break;
        case 3:
            m3(ch_1, k);
            break;
        case 4:
            m4(ch, k);
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

void m1(char ch[][MAX], int k)
{
    int i;
    for (i = 0; i < k; i++)
        puts(ch[i]);
}

void m2(char *ch[], int k)
{
    char *temp;
    int top, seek;
    for (top = 0; top < k - 1; top++)
        for (seek = top + 1; seek < k; seek++)
            if (strcmp(ch[top], ch[seek]) > 0)
            {
                temp = ch[top];
                ch[top] = ch[seek];
                ch[seek] = temp;
            }
    for (seek = 0; seek < k; seek++)
        puts(ch[seek]);
}

void m3(char *ch[], int k)
{
    char *temp;
    int top, seek;
    for (top = 0; top < k - 1; top++)
        for (seek = top + 1; seek < k; seek++)
            if (strlen(ch[top]) > strlen(ch[seek]))
            {
                temp = ch[top];
                ch[top] = ch[seek];
                ch[seek] = temp;
            }
    for (seek = 0; seek < k; seek++)
        puts(ch[seek]);
}

void m4(char ch[][MAX], int k)
{
    int i, u;
    for (i = 0; i < k; i++)
    {
        for (u = 0; ch[i][u] != '\0' && u < MAX; u++)
        {
            if (ch[i][u + 1] == ' ')
                ch[i][u + 1] = '\0';
            printf("%c", ch[i][u]);
        }
        printf("\n");
    }
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}