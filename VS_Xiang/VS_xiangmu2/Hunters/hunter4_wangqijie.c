#include <stdio.h>
#include <math.h>
#include <string.h>
#define max 100
int check(int i);
int main()
{
	int a, b,cnt=0;
	scanf("%d%d", &a, &b);
	for (int i = a; i <= b; i++)
	{
		if (check(i))
			cnt++;
	}
	printf("%d", cnt);
}
int check(int i)
{
	int digit[10],count=0;
	for (int j = 0; i > 0; j++)
	{
		digit[j] = i % 10;
		i /= 10;
		count++;
	}

	for (int k = 0; k < count - 1; k++)
	{
		if (digit[k] <= digit[k + 1])
			return 0;
	}
	return 1;
}