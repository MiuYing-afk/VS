#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int y(long a, long b);
long min(long a, long b);
long max(long a, long b);
int main()
{
	long a, b, c,max1,min1;
	scanf("%d%d%d", &a, &b, &c);
	max1 = max(max(a, b), max(a, c));
	min1 = min(min(a, b), min(a, c));
	int x = y(min1, max1);
	min1 /= x;
	max1 /= x;
	printf("%d/%d", min1, max1);
	return 0;
}
long min(long a, long b)
{
	if (a < b)
		return a;
	else
		return b;
}
long max(long a, long b)
{
	if (a > b)
		return a;
	else
		return b;
}
int y(long a, long b)
{
	int i;
	i = a%b;
	while (i != 0)
	{
		a = b;
		b = i;
		i = a % b;
	}
	return b;
}

//奇怪，能跑，但没过