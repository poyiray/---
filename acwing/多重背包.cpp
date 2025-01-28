#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e4 + 10;
int n, m, f[N], q[N], g[N];

void solution1()
{
	for (int i = 1; i <= n; i++)
	{
		memcpy(g, f, sizeof f);
		int v, w, s; cin >> v >> w >> s;
		for (int j = 0; j < v; j++)
		{
			int h = 0, t = -1;
			for (int k = j; k <= m; k += v)
			{
				while (h <= t && q[h] < k - s * v) h++;
				if (h <= t) f[k] = max(g[k], g[q[h]] + (k - q[h]) / v * w);
				while (h <= t && g[k] >= g[q[t]] + (k - q[t]) / v * w) t--;
				q[++t] = k;
			}
		}
	}
}

void solution2()
{
	for (int i = 1; i <= n; i++)
	{
		vector<int> vv, ww;
		int v, w, s; cin >> v >> w >> s;
		for (int j = 1; j <= s; j <<= 1)
		{
			vv.push_back(j * v);
			ww.push_back(j * w);
			s -= j;
		}
		if (s)
		{
			vv.push_back(s * v);
			ww.push_back(s * w);
		}

		for (int j = 0; j < vv.size(); j++)
		{
			for (int k = m; k >= vv[j]; k--)
			{
				f[k] = max(f[k], f[k - vv[j]] + ww[j]);
			}
		}
	}
}

void solution3()
{
	for (int i = 1; i <= n; i++)
	{
		int v, w, s; cin >> v >> w >> s;
		for (int j = m; j >= v; j--)
		{
			for (int k = 1; k <= s && k * v <= j; k++)
			{
				f[j] = max(f[j], f[j - k * v] + k * w);
			}
		}
	}
}

signed main()
{
	cin >> n >> m;
	solution3();
	cout << f[m];

	return 0;
}