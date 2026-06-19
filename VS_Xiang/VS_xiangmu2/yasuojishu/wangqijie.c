#include <stdio.h>
int main()
{
	int n,j;
	scanf("%d", &n);
	int pos=0, max = n * n;
	int index = 0;
	while (pos < max)
	{
		scanf("%d", &j);
		for (int i = 0; i < j; i++)
		{
			printf("%d", index);
			pos++;
			if (pos % n == 0&&pos!=max)
				printf("\n");
		}
		index = 1 - index;
	}
	return 0;
}

//王琦是个天才！！！