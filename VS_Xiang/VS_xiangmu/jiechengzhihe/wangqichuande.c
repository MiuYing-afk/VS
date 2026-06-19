#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int a(int n);
int main()
{
	int n, sum = 0;
	scanf("%d", &n);
	for (int i = 1; i < n + 1; i++)
	{
		sum += a(i);
	}
	printf("%d的阶乘数列求和（从1开始）是%d",n, sum);
	return 0;
}
int a(int n)
{
	if (n == 0)
		return 1;
	return n * a(n - 1);
}