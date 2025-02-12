#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
int a[N], in[N], n, res[N], ans;
vector<int> e[N];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int u, w, v; cin >> u >> w;
		a[u] = w;
		while (cin >> v && v)
		{
			in[u]++;
			e[v].push_back(u);
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (!in[i]) q.push(i);

	while (q.size())
	{
		int u = q.front(); q.pop();
		for (auto v : e[u])
		{
			if (!--in[v]) q.push(v);
			res[v] = max(res[u] + a[u], res[v]);
		}
	}
	for (int i = 1; i <= n; i++) ans = max(ans, res[i] + a[i]);
	cout << ans;

	return 0;
}