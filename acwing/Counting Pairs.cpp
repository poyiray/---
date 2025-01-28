#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5 + 10;
int a[N], n, x, y;

void solve()
{
	cin >> n >> x >> y;
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	sort(a + 1, a + n + 1);
	int res = 0, l = sum - y, r = sum - x;
	for (int i = 1; i <= n; i++)
	{
		int left = lower_bound(a + i + 1, a + n + 1, l - a[i]) - a;
		int right = upper_bound(a + i + 1, a + n + 1, r - a[i]) - a - 1;
		int tmp = right - left + 1;
		res += tmp;
	}
	cout << res << endl;
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int _; cin >> _;
	while (_--) solve();

	return 0;
}