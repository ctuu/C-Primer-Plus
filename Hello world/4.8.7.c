#include <stdio.h>
#include <float.h>
int main(void)
{
    float fnum = 1.0/3.0;
    double dnum = 1.0/3.0;
    printf("float:\n%.6f %.12f %.16f\n", fnum, fnum, fnum);
    printf("double:\n%.6f %.12f %.16f\n", dnum, dnum, dnum);
    printf("FLT_DIG:%d\nDBL_DIG:%d",FLT_DIG , DBL_DIG);
    return 0;
}