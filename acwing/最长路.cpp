#include <bits/stdc++.h>
using namespace std;

const int N = 1510;
struct node
{
	int v, w;
};
int a[N], n, m, dis[N], in[N];
vector<node> e[N];

int main()
{
	memset(dis, -0x3f, sizeof dis);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		in[v]++;
		e[u].push_back({ v,w });
	}

	queue<int> q;
	for (int i = 2; i <= n; i++)
		if (!in[i]) q.push(i);
	
	while (q.size())
	{
		int u = q.front(); q.pop();
		for (auto[v, w] : e[u])
		{
			if (!--in[v]) q.push(v);
		}
	}
	q.push(1);
	dis[1] = 0;
	while (q.size())
	{
		int u = q.front(); q.pop();
		for (auto[v,w] : e[u])
		{
			if (!--in[v]) q.push(v);
			dis[v] = max(dis[v], dis[u] + w);
		}
	}
	if (dis[n] < -1e8) cout << -1;
	else cout << dis[n]; 

	return 0;
}