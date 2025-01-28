#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
struct node
{
	int v, w;
	bool operator<(const node& n) const
	{
		return w < n.w;
	}
};
int dis[N], n, m, res;
vector<node> e1[N], e2[N];
priority_queue<node> q;

int main()
{
	cin >> n >> m;
	while (m--)
	{
		int u, v, w; cin >> u >> v >> w;
		e1[u].push_back({ v,w });
		e2[v].push_back({ u,w });
	}

	memset(dis, 0x3f, sizeof dis);
	q.push({ 1, 0 });
	dis[1] = 0;
	while (q.size())
	{
		int u = q.top().v; q.pop();
		for (auto &[v, w] : e1[u])
		{
			if (dis[u] + w < dis[v])
			{
				dis[v] = dis[u] + w;
				q.push({ v,-dis[v] });
			}
		}
	}
	for (int i = 1; i <= n; i++) res += dis[i];
	memset(dis, 0x3f, sizeof dis);
	q.push({ 1, 0 });
	dis[1] = 0;
	while (q.size())
	{
		int u = q.top().v; q.pop();
		for (auto &[v, w] : e2[u])
		{
			if (dis[u] + w < dis[v])
			{
				dis[v] = dis[u] + w;
				q.push({ v,-dis[v] });
			}
		}
	}
	for (int i = 1; i <= n; i++) res += dis[i];
	cout << res;

	return 0;
}