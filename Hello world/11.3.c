#define MSG "I'm spaceial"

#include <stdio.h>
int main(void)
{
    char ar[] = MSG;
    const char *pt = MSG;
    printf("address of \"I'm spaceial\": %p \n", "I'm spaceial");
    printf("               address ar: %p\n", ar);
    printf("               address pt: %p\n", pt);
    printf("           address of MSG: %p\n", MSG);
    printf("address of \"I'm spaceial\": %p \n", "I'm spaceial");

    return 0;
}
