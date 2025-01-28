#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int f[N][N], n, m, v[N], w[N];

void dfs(int x, int y)
{
	if (x > n) return;
	//一定要特判 v[x] > y, 不然可能会负下标
	if (v[x] > y || f[x + 1][y - v[x]] + w[x] != f[x][y]) dfs(x + 1, y);
	else
	{
		cout << x << " ";
		dfs(x + 1, y - v[x]);
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int a, b; cin >> a >> b;
		v[i] = a, w[i] = b;
	}

	for (int i = n; i >= 1; i--)
	{
		for (int j = 1; j <= m; j++) f[i][j] = f[i + 1][j];
		for (int j = m; j >= v[i]; j--)
		{
			f[i][j] = max(f[i][j], f[i + 1][j - v[i]] + w[i]);
		}
	}
	dfs(1, m);
	return 0;
}