#include <bits/stdc++.h>
using namespace std;

const int N = 3000;
struct node
{
	int v, w;
	bool operator<(const node& n) const
	{
		return w < n.w;
	}
};

priority_queue<node> q;
int n, m, s, t, dis[N];
vector<node> e[N];

int main()
{
	cin >> n >> m >> s >> t;
	while (m--)
	{
		int u, v, w; cin >> u >> v >> w;
		e[u].push_back({ v,w });
		e[v].push_back({ u,w });
	}

	memset(dis, 0x3f, sizeof dis);
	q.push({ s,0 });
	dis[s] = 0;

	while (q.size())
	{
		int u = q.top().v; q.pop();
		for (auto &[v, w] : e[u])
		{
			if (dis[u] + w < dis[v])
			{
				dis[v] = dis[u] + w;
				q.push({ v,-dis[v] });
			}
		}
	}
	cout << dis[t];

	return 0;
}