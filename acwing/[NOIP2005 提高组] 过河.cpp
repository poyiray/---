#include <bits/stdc++.h>
using namespace std;

const int N = 9e3 + 10, M = 1e2 + 10;
int a[M], b[M], c[N], f[N], l, s, t, m, res = 1e5;;

int main()
{
	memset(f, 0x3f, sizeof f); f[0] = 0;
	cin >> l >> s >> t >> m;
	for (int i = 1; i <= m; i++) cin >> a[i];
	sort(a + 1, a + m + 1);
	if (s == t) 
	{
		res = 0;
		for (int i = 1; i <= m; i++) if (a[i] % s == 0) res++;
		cout << res;
		return 0;
	}
	for (int i = 1; i <= m; i++)
	{
		if (a[i] - a[i - 1] > 90) b[i] = b[i - 1] + 90;
		else b[i] = a[i] - a[i - 1] + b[i - 1];
		c[b[i]] = 1;
	}

	l = b[m];
	for (int i = s; i <= l + t; i++)
	{
		for (int j = s; j <= t; j++)
		{
			f[i] = min(f[i], f[i - j] + c[i]);
		}
	}
	for (int i = l; i <= l + t; i++) res = min(res, f[i]);
	cout << res;

	return 0;
}