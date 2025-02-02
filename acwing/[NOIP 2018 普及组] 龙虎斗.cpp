#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 10;
int a[N], p, s1, s2, n, m, l, r, res, pos;

signed main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cin >> m >> p >> s1 >> s2;
	a[p] += s1;
	for (int i = 1; i < m; i++) l += a[i] * (m - i);
	for (int i = m + 1; i <= n; i++) r += a[i] * (i - m);

	res = abs(l - r);
	pos = m;
	for (int i = 1; i <= n; i++)
	{
		if (i <= m)
		{
			if (abs((l + s2 * (m - i)) - r) < res)
			{
				res = abs((l + s2 * (m - i)) - r);
				pos = i;
			}
		}
		else
		{
			if (abs(l - (r + s2 * (i - m))) < res)
			{
				res = abs(l - (r + s2 * (i - m)));
				pos = i;
			}
		}
	}
	cout << pos;

	return 0;
}