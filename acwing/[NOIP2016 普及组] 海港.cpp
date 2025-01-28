#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int cnt[N], res, n, t[N], q[N];
vector<int> a[N];

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int y, m; cin >> y >> m;
		t[i] = y;
		for (int j = 1; j <= m; j++)
		{
			int x; cin >> x;
			a[i].push_back(x);
		}
	}

	//队列优化
	int tt = 0, hh = 0;
	for (int i = 1; i <= n; i++)
	{
		while (tt <= hh && t[q[tt]] <= t[i] - 86400)
		{
			for (auto v : a[q[tt]])
			{
				if (!--cnt[v]) res--;
			}
			tt++;
		}
		for (auto v : a[i])
		{
			if (!cnt[v]++) res++;
		}
		q[++hh] = i;
		cout << res << '\n';
	}

	return 0;
}