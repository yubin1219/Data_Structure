#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void inputArray(int (*a)[2])
{
	int i, j;

	for(i=0;i<2;i++)
		for (j = 0; j < 2; j++)
		{
			printf("%d행 %d열 : ", i+1, j+1);
			scanf("%d", &a[i][j]);
		}
	printf("\n");
	getchar();
}

void printArray(int (*x)[2])
{
	int i, j;
	printf("----------------");
	for (i = 0; i < 2; i++)
	{
		printf("\n");
		for (j = 0; j < 2; j++)
		{
			printf("%d ", x[i][j]);
		}
	}
	printf("\n\n");
}

int addArray(int (*c)[2], int (*a)[2], int (*b)[2])
{
	int i, j;

	for(i=0;i<2;i++)
		for (j = 0; j < 2; j++)
		{
			c[i][j] = a[i][j] + b[i][j];
		}
	return c;
}

int mulArray(int (*c)[2], int (*a)[2], int (*b)[2])
{
	int i, j;
	for(i=0;i<2;i++)
		for (j = 0; j < 2; j++)
		{
			c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
		}

	return c;
}

int main(void)
{
	int a[2][2];
	int b[2][2];
	int c[2][2];

	inputArray(a);
	inputArray(b);
	printArray(a);
	printArray(b);

	addArray(c, a, b); // a+b=c
	printArray(c);
	mulArray(c, a, b); // a*b=c
	printArray(c);

	return 0;
}
