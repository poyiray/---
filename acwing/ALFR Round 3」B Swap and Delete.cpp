#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N], t, n, len, c[N], cnt[N];

int find(int x)
{
	return lower_bound(c + 1, c + len, x) - c;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> t;
	while (t--)
	{
		memset(cnt, 0, sizeof cnt);
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			c[i] = a[i];
		}
		len = unique(c + 1, c + 1 + n) - c;
		sort(c + 1, c + len);

		for (int i = 1; i <= n; i++) cnt[find(a[i])]++;

		bool f = false;
		if (a[1] == a[n]) cout << 1 << '\n';
		else if (cnt[find(a[1])] >= 2 || cnt[find(a[n])] >= 2) cout << 2 << '\n';
		else
		{
			for (int i = 1; i <= n; i++)
			{
				if (cnt[find(a[i])] >= 2)
				{
					cout << 3 << '\n';
					f = true;
					break;
				}
			}
			if (!f) cout << n << '\n';
		}
	}

	return 0;
}