#include <stdio.h>
#include <stdlib.h>
int n,sum=0;
int book[101], e[101][101];
void dfs(int cur)
{
	int i = 0;
	printf("%d ", cur);
	sum++;
	if (sum == n)
		return;
	for (i = 1; i <= n; i++)
		if (e[cur][i] == 1 && book[i] == 0)
		{
			book[i] = 1;
			dfs(i);
		}
	return;
}
int main(void)
{
	int i = 0;
	int j = 0;
	int a = 0;
	int b = 0;
	scanf("%d",&n);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (i == j)
				e[i][j] = 0;
			else
				e[i][j] = 999999999;
	for (i = 1; i <= n; i++)
	{
		scanf("%d%d",&a,&b);
		e[a][b] = 1;
		e[b][a] = 1;
	}
	book[1] = 1;
	dfs(1);
}
