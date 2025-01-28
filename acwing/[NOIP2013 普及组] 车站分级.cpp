#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int in[N], n, m, a[N], dis[N], res, ed[N][N];
vector<int> e[N];

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int s, vis[N] = {0}; cin >> s;
		for (int j = 1; j <= s; j++)
		{
			cin >> a[j];
			vis[a[j]] = 1;
		}
		for (int j = a[1] + 1; j <= a[s] - 1; j++)
		{
			if (!vis[j])
			{
				for (int k = 1; k <= s; k++)
				{
					if (ed[j][a[k]]) continue;
					ed[j][a[k]] = 1;
					in[a[k]]++;
					e[j].push_back(a[k]);
				}
			}
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (!in[i]) q.push(i);
	}

	while (q.size())
	{
		int u = q.front(); q.pop();
		for (auto v : e[u])
		{
			if (!--in[v])
			{
				q.push(v);
				dis[v] = dis[u] + 1;
				res = max(res, dis[v]);
			}
		}
	}
	cout << res + 1;

	return 0;
}