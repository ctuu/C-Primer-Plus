#include <stdio.h>
int main(int argc, char *argv[])
{
    int count;

    printf("The command line has %d arguments:\n", argc - 1);
    for (count = argc - 1; count > 0; count--)
        printf("%d: %s\n", count, argv[count]);
    printf("\n");

    return 0;
}