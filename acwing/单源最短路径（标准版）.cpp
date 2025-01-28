#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 10;
struct node
{
	int v, w;
	bool operator<(const node& n) const
	{
		return w > n.w;
	}
};
int n, m, s, dis[N], vis[N];
vector<node> e[N];

signed main()
{
	cin >> n >> m >> s;

	for (int i = 1; i <= m; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		e[u].push_back({ v,w });
	}
	
	memset(dis, 0x3f, sizeof dis);
	priority_queue<node, vector<node>> q;
	dis[s] = 0;
	q.push({s, 0});

	while (q.size())
	{
		int u = q.top().v; q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto [v, w] : e[u])
		{
			if (dis[u] + w < dis[v])
			{
				dis[v] = dis[u] + w;
				q.push({ v, dis[v] });
			}
		}
	}
	for (int i = 1; i <= n; i++) cout << dis[i] << " ";

	return 0;
}