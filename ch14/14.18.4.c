#include <stdio.h>
#include <string.h>
#define LEN 20
#define MAX 5

struct names
{
    char last[LEN];
    char middle[LEN];
    char first[LEN];
};

struct group
{
    int account;
    struct names handle;
};

void show(struct group list[], int n);

int main(void)
{
    int ct;
    char temp;
    struct group list[MAX];
    for (ct = 0; ct < MAX; ct++)
    {
        printf("Please enter your insurance account:\n");
        scanf("%d", &list[ct].account);
        while (getchar() != '\n')
            continue;
        printf("please enter your name:\n");
        scanf("%s%s", list[ct].handle.first, list[ct].handle.middle);
        if ((temp = getchar()) != '\n')
                scanf("%s", list[ct].handle.last);
        else
        {
            strcpy(list[ct].handle.last, list[ct].handle.middle);
            list[ct].handle.middle[0] = '\0';
        }
    }
    show(list, MAX);
}

void show(struct group list[], int n)
{
    int ct;
    printf("\n------------USER LIST------------\n");
    for (ct = 0; ct < n; ct++)
    {
        printf("%s, %s ", list[ct].handle.last, list[ct].handle.first);
        if (list[ct].handle.middle[0] != '\0')
            printf("%c. ", list[ct].handle.middle[0]);
        else
            printf(" ");
        printf("-- %d\n", list[ct].account);
    }
}