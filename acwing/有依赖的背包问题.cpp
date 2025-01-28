#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int f[N][N], n, m, v[N], w[N];
vector<int> e[N];

void dfs(int u)
{
	f[u][v[u]] = w[u];
	for (auto son : e[u])
	{
		dfs(son);
		for (int i = m; i >= v[u]; i--)
		{
			for (int j = v[u]; j <= i; j++)
			{
				f[u][i] = max(f[u][i], f[u][j] + f[son][i - j]);
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int V, W, p; cin >> V >> W >> p;
		v[i] = V;
		w[i] = W;
		if (!~p) p = 0;
		e[p].push_back(i);
	}

	dfs(0);
	cout << f[0][m];

	return 0;
}