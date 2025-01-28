#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int n, m, a[N], d[N], s[N], t[N], dif[N];

bool judge(int x)
{
	for (int i = 1; i <= n; i++) dif[i] = a[i] - a[i - 1];
	for (int i = 1; i <= x; i++)
	{
		dif[s[i]] -= d[i];
		dif[t[i] + 1] += d[i];
	}
	for (int i = 1; i <= n; i++) dif[i] += dif[i - 1];
	for (int i = 1; i <= n; i++) if (dif[i] < 0) return 1;
	return 0;
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> d[i] >> s[i] >> t[i];

	int l = -1, r = m + 1;
	while (l + 1 != r)
	{
		int mid = l + r >> 1;
		if (judge(mid)) r = mid;
		else l = mid;
	}
	if (r == m + 1) cout << 0;
	else cout << -1 << "\n" << r;

	return 0;
}