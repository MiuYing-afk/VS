#include <stdio.h>
#include <math.h>
#include <string.h>
#define max 105
int main()
{
	int a[max][max] = {0};
	int x,y,o,p;
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &x);
		scanf("%d", &y);
		for (int dx = -2; dx <= 2; dx++)
		{
			for (int dy = -2; dy <= 2; dy++)
			{
				if (fabs(dx) + fabs(dy) <= 2)
				{
					int nx = x + dx;
					int ny = y + dy;
					if (nx >= 1&&nx<=n&&ny<=n && ny >= 1)
						a[nx][ny] = 1;
				}
			}
		}
	}
	for (int j = 0; j < k; j++)
	{
		scanf("%d", &o);
		scanf("%d", &p);
		for (int dx = -2; dx <= 2; dx++)
		{
			for (int dy = -2; dy <= 2; dy++)
			{
				int no = o + dx;
				int np = p + dy;
				if (no >= 1&&no<=n&&np<=n && np >= 1)
					a[no][np] = 1;
			}

		}
	}
	int cnt = 0;
	for (int i = 1; i <=n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (a[i][j] == 0)
				cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}