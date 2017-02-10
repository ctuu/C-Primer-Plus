#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIM 3

struct names
{
    char first[40];
    char last[40];
};

// void fillarray(double ar [], int n);
void showarray(const struct names [], int n);
int comp(const void *pi, const void *p2);

int main(void)
{
    struct names staff[LIM] =
        {
            "Ubuntu", "Centos",
            "Arch", "Linux",
            "Redhat", "Debian"};
    puts("List:");
    showarray(staff, LIM);
    qsort(staff, LIM, sizeof(struct names), comp);
    puts("\nSorted list:");
    showarray(staff, LIM);
    return 0;
}

// void fillarray(double ar [], int n)
// {
//     int index;

//     for (index = 0; index < n; index++)
//         ar[index] = (double) rand() / ((double) rand() + 0.1);
// }

void showarray(const struct names ps[], int n)
{
    int index;

    for (index = 0; index < n; index++)
    {
        printf("%s %s", ps[index].first, ps[index].last);
        putchar('\n');
    }
    if (index % 6 != 0)
        putchar('\n');
}

int comp(const void *p1, const void *p2)
{
    const struct names *ps1 = (const struct names *)p1;
    const struct names *ps2 = (const struct names *)p2;
    int res;
    res = ~strcmp(ps1->last, ps2->last);
    if (res != 0)
        return res;
    else
        return ~strcmp(ps1->first, ps2->first);
}