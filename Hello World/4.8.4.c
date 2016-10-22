#include <stdio.h>
#define FEET 12 
int main(void)
{
    char name[40];
    float height;
    printf("Enter your first name:\n");
    scanf("%s", name);
    printf("Enter your height(inch):\n");
    scanf("%f", &height);
    height = height / FEET;
    printf("%s, you are %.3f feet tall.", name, height);
    return 0;
}