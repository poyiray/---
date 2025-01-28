#include <bits/stdc++.h>
using namespace std;

const int N = 55;
int n, res[N], vis[N], e[N][N];

void dfs(int u, int num)
{
	if (u == 1 && num > n)
	{
		for (int i = 1; i <= n; i++)
		{
			cout << res[i] << " ";
		}
		exit(0);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!e[u][i] || vis[i]) continue;
		if (num != n && i == 1) continue;
		vis[i] = 1;
		res[num + 1] = i;
		dfs(i, num + 1);
		vis[i] = 0;
	}
}

int main()
{
	cin >> n;
	int u, v;
	while(cin >> u >> v) //输入没有处理好 （写的for循环哈哈哈）
	{
		e[u][v] = e[v][u] = 1;
	}

	res[1] = 1;
	dfs(1, 1);

	return 0;
}