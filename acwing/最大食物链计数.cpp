#include <bits/stdc++.h>
using namespace std;

const int N = 5100;
int n, m, in[N], res[N], out[N], ans;
vector<int> e[N];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v; cin >> u >> v;
		e[v].push_back(u);
		out[v]++;
		in[u]++;
	}

	stack<int> s;
	for (int i = 1; i <= n; i++) if (!in[i]) s.push(i), res[i] = 1;

	while (s.size())
	{
		int u = s.top(); s.pop();
		for (auto v : e[u])
		{
			if (!--in[v]) s.push(v);
			res[v] = (res[v] + res[u]) % 80112002;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (!out[i])
		{
			ans = (ans + res[i]) % 80112002;
		}
	}
	cout << ans;

	return 0;
}