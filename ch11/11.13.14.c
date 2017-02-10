#include <stdio.h>
#include <stdlib.h>
int main(int argc, char * argv[])
{
    double total = 1;
    double x = atof(argv[1]);
    int a = atoi(argv[2]);
    for ( ;a > 0; a--)
            total *= x;
    printf("%f\n", total);
    return 0;
}