#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 10;
int a[N], n, m;

signed main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	a[0] = a[n + 1] = 1e15;
	int res = 0;
	while (m--)
	{
		int x; cin >> x;
		int l = 0, r = n + 1;
		while (l + 1 != r)
		{
			int mid = l + r >> 1;
			if (a[mid] <= x) l = mid;
			else r = mid;
		}
		res += min(abs(a[r] - x), abs(x - a[r - 1]));
	}
	cout << res;

	return 0;
}