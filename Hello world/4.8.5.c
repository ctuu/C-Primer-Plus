#include <stdio.h>
int main(void)
{
    float Mbs;
    float MB;
    float time;
    printf("Enter your download speed(Mb/s):\n");
    scanf("%f", &Mbs);
    printf("Enter the size of file you are downloading(MB):\n");
    scanf("%f",&MB);
    time = MB / (Mbs / 8);
    printf("At %.2f megabits per second, a file of %.2f megabytes\n", Mbs, MB);
    printf("downloads in %.2f seconds.", time);
    return 0;
}