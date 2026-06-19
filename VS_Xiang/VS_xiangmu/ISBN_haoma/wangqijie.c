#include <stdio.h>
int main()
{
	char a[14];
	int b[9];
	for (int i = 0; i < 13; i++)
	{
		scanf("%c", &a[i]);
	}
	for (int i = 0, j = 0; i < 12; i++)
	{
		if (i == 1 || i == 5 || i == 11)
			continue;
		b[j++] = a[i] - '0';
	}
	int sum = 0;
	for (int j = 1, k = 0; j < 10; j++, k++)
	{
		sum += b[k] * j;
	}
	int mod = sum % 11;
	if (a[12] == 'X')
		a[12] = 10 + '0';
	if (a[12] - '0' == mod)
		printf("Right");
	else
	{
		if (mod == 10)
			a[12] = 'X';
		else
		{
			a[12] = mod + '0';

		}
		for (int k = 0; k < 13; k++)
		{
			printf("%c", a[k]);
		}
	}
	return 0;
}