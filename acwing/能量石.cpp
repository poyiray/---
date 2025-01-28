#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
struct node
{
	int s, e, l;
	bool operator<(const node& n) const
	{
		return s * n.l < n.s * l;
	}
} a[N];
int f[N], n;

int main()
{
	int _; cin >> _;
	int cnt = 0;
	while (_--)
	{
		cin >> n;
		int m = 0;
		for (int i = 1; i <= n; i++)
		{
			int s, e, l; cin >> s >> e >> l;
			a[i] = { s,e,l };
			m += s;
		}
		sort(a + 1, a + n + 1);
		memset(f, -0x3f, sizeof f); f[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = m; j >= a[i].s; j--)
			{
				f[j] = max(f[j], max(0, f[j - a[i].s] + a[i].e - a[i].l * (j - a[i].s)));
			}
		}
		int res = 0;
		for (int i = 1; i <= m; i++) res = max(res, f[i]);
		cout << "Case #" << ++cnt << ": "<< res << endl;
	}

	return 0;
}