#include <stdio.h>

struct font {
    unsigned int fid   : 8;
    unsigned int size  : 7;
    unsigned int align : 2;
    _Bool bold;
    _Bool italic;
    _Bool unline;
}

int main(void)
{

}