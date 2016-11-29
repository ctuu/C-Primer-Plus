#include <stdio.h>

#define STU struct stu
STU
{
    int num;
    char *name;
    char sex;
    float score;
};

void average(STU *ps[]);

int main()
{
    STU boy[5] = {
        {101, "Li ping", 'M', 45},
        {102, "Zhang ping", 'M', 62.5},
        {103, "He fang", 'F', 92.5},
        {104, "Cheng ling", 'F', 87},
        {105, "Wang ming", 'M', 58}};
    STU *ps = boy;
    average(ps);
    return 0;
}

void average(struct stu *ps[])
{
    int flunk = 0, i, K;
    float sum = 0;
    for (i = 0,K = 0; i < 5; i++, K++)
    {
        sum += ps[K]->score;
        if (ps[K]->score < 60)
            flunk += 1;
    }
    printf("sum=%.2f, average=%.2f, flunk=%d\n", sum, sum / 5, flunk);
}