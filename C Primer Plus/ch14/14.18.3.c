#include <stdio.h>
#include <string.h>
char *s_gets(char *st, int n);

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100

struct book
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

void list_of_ch(struct book *lib[MAXBKS], int ct);
void show(const struct book *library, int count);

int main(void)
{
    struct book library[MAXBKS];
    int count = 0;
    int index;

    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
    {
        printf("Now enter the author.\n");
        s_gets(library[count].author, MAXAUTL);
        printf("Now enter the value.\n");
        scanf("%f", &library[count++].value);
        while (getchar() != '\n')
            continue;
        if (count < MAXBKS)
            printf("Enter the next title.\n");
    }
    if (count > 0)
    {
        show(library, count);
    }
    else
        printf("No books? Too bad.\n");

    return 0;
}

void show(const struct book *library, int count)
{
    int index;
    printf("Here is the list of your books:\n");
    for (index = 0; index < count; library++, index++)
        printf("%s by %s: $%.2f\n", library->title,
               library->author, library->value);
}

void list_of_ch(struct book *lib[MAXBKS], int ct)
{
    struct book *temp;
    int top, seek;
    for (top = 0; top < ct; top++)
        for (seek = top + 1; seek < ct; seek++)
        {
            if (strcmp(lib[seek]->title, lib[top]->title) > 0)
            {
                temp = lib[top];
                lib[top] = lib[seek];
                lib[seek] = temp;
            }
        }
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}