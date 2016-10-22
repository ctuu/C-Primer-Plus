#include <stdio.h>
int main(void)
{
    float num;
    printf("Enter a number:\n");
    scanf("%f", &num);
    printf("%.3f\n%.3e\n", num, num);
    printf("%+.3f\n%.3E\n",num, num);
    return 0;
}