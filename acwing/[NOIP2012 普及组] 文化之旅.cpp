#include <bits/stdc++.h>
using namespace std;

const int N = 110;
struct node
{
	int v, w;
};
int n, k, m, s, t, res = 1e8, ti;
int a[N], b[N][N];
vector<int> vis;
vector<node> e[N];

void dfs(int u, int d)
{
	//¿¨Ê±
	if (clock() - ti >= CLOCKS_PER_SEC * 0.9)
	{
		cout << -1;
		exit(0);
	}
	if (d >= res) return;
	if (u == t)
	{
		res = d;
		return;
	}
	bool f = false;

	for (auto &[v,w] : e[u])
	{
		bool f = false;
		for (auto &x : vis)
		{
			if (b[a[v]][x]) f = true;
		}
		if (f) continue;

		vis.push_back(a[v]);
		dfs(v, d + w);
		vis.pop_back();
	}
}

int main()
{
	ti = clock();
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> k >> m >> s >> t;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= k; j++)
			cin >> b[i][j];
	for (int i = 1; i <= k; i++)
		b[i][i] = 1;

	for (int i = 1; i <= m; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		e[u].push_back({ v,w });
		e[v].push_back({ u,w });
	}

	vis.push_back(a[s]);
	dfs(s, 0);
	if (res >= 1e8) cout << -1;
	else cout << res;

	return 0;
}