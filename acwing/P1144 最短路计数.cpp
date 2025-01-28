#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10, M = 100003;
int n, m, dis[N], cnt[N], vis[N];
vector<int> e[N];

int main()
{
	cin >> n >> m;
	while (m--)
	{
		int u, v; cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	memset(dis, 0x3f, sizeof dis);
	queue<int> q;
	q.push(1);
	dis[1] = 0;
	cnt[1] = 1;
	vis[1] = 1;
	while (q.size())
	{
		int u = q.front(); q.pop();
		for (auto &v : e[u])
		{
			if (!vis[v]) q.push(v);
			vis[v] = 1;
			if (dis[u] + 1 <= dis[v])
			{
				dis[v] = dis[u] + 1;
				cnt[v] = (cnt[v] + cnt[u]) % M;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << cnt[i] << '\n';
	}

	return 0;
}