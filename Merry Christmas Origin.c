#include <stdio.h>
int main()
{
    int i, j, n;
    printf("输入今天是12月几日(仅输数字):\n");
    scanf("%d", &n);
    if (n == 25)
    {
	for (i = 1; i <= n; i++)
	{
	    for (j = 1; j <= n - i; j++)
		printf(" ");
	    putchar('0');
	    for (j = 2; j <= 2 * i - 2; j++)
		printf("1");
	    for (; j <= 2 * i - 1; j++)
		printf("0");
	    printf("\n");
	}
	for (i = n; i <= n + n / 4; i++)
	{
	    for (j = 1; j <= (2 * n + 1) / 3; j++)
		printf(" ");
	    for (j = 1; j <= 2 * n / 3; j++)
		printf("0");
	    printf("\n");
	}
	printf("Merry Christmas!!\n");
    }
    else
	printf("答案有误\n");
    return 0;
}