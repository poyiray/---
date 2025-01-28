#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int n, a[N], len, d[N], vis[N], res = 1e5;

vector<int> p[N];

bool ck()
{
	for (int i = 1; i <= n; i++) if (!vis[i]) return false;
	return true;
}

void dfs(int x, int y)
{
	if (x > n) return;
	if (ck()) res = min(res, y - 1);

	for (auto v : p[x])
	{
		vis[v]++;
	}
	dfs(x + 1, y + 1);
	for (auto v : p[x])
	{
		vis[v]--;
	}
	dfs(x + 1, y);
}

int main()
{
	while (cin >> n && n)
	{
		memset(vis, 0, sizeof vis);
		res = 1e5;
		len = 0;
		for (int i = 1; i <= n; i++) cin >> a[i];
		
		memset(d, 0x3f, sizeof d);
		for (int i = 1; i <= n; i++)
		{
			bool f = false;
			for (int j = 1; j <= len; j++)
			{
				if (d[j] > a[i])
					p[j].push_back(i), f = 1, d[j] = a[i];
			}
			if (!f) p[++len].push_back(i), d[len] = a[i];
		}

		memset(d, -0x3f, sizeof d);
		int tmp = len + 1;
		for (int i = 1; i <= n; i++)
		{
			bool f = false;
			for (int j = tmp; j <= len; j++)
			{
				if (d[j] < a[i])
					p[j].push_back(i), f = 1, d[j] = a[i];
			}
			if (!f) p[++len].push_back(i), d[len] = a[i];
		}
		dfs(1, 0);
		cout << res << '\n';
	}

	return 0;
}