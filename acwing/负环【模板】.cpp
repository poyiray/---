#include <bits/stdc++.h>
using namespace std;

const int N = 3e3 + 10;
struct edge
{
	int u, v, w;
} a[2 * N];
int n, m, dis[N];

void solve()
{
	memset(dis, 0x3f, sizeof dis);
	dis[1] = 0;
	cin >> n >> m;
	int len = 0;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		if (w >= 0) a[++len] = { u,v,w }, a[++len] = { v,u,w };
		else a[++len] = { u,v,w };
	}
	bool f = false;
	for (int i = 1; i <= n; i++)
	{
		f = false;
		for (int j = 1; j <= len; j++)
		{
			auto [u, v, w] = a[j];
			if (dis[u] >= 1e8) continue;
			if (dis[u] + w < dis[v])
			{
				dis[v] = dis[u] + w;
				f = true;
			}
		}
		if (!f) break;
	}
	if (f) cout << "YES\n";
	else cout << "NO\n";
}

int main()
{
	int t; cin >> t;
	while (t--) solve();

	return 0;
}