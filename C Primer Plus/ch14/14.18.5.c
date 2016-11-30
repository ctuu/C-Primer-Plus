#include <stdio.h>
#define CSIZE 4
#define LEN 10

struct name
{
    char first[LEN];
    char last[LEN];
};

struct student
{
    struct name handle;
    float grade[3];
    float aver;
};

void calc(struct student list[]);
void show(struct student list[]);
int main(void)
{
    int ct = 0;
    struct student list[CSIZE];
    while (ct < CSIZE)
    {
        printf("Please enter the student's name:\n");
        scanf("%s%s", list[ct].handle.first, list[ct].handle.last);
        printf("Please enter grade (subject A, subject B, and subject C):\n");
        scanf("%f%f%f", &list[ct].grade[0], &list[ct].grade[1], &list[ct].grade[2]);
        ct++;
    }
    calc(list);
    show(list);

    return 0;
}

void calc(struct student list[])
{
    int ct = 0;
    while (ct < CSIZE)
    {
        list[ct].aver = list[ct].grade[0] + list[ct].grade[1] + list[ct++].grade[2];
    }
}

void show(struct student list[])
{
    int ct = 0;
    float sum = 0;
    printf("    ----Name----       Subject A  Subject B  Subject C   Average\n");
    while (ct < CSIZE)
    {
        printf("%10s %-10s  %9.2f  %9.2f  %9.2f % 9.2f\n", list[ct].handle.first, list[ct].handle.last, list[ct].grade[0], list[ct].grade[1], list[ct].grade[2], list[ct].aver);
        sum += list[ct++].aver;
    }
    printf("Class Average: %7.2f\n", sum / CSIZE);
}