#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5 + 10;
int n, c, a[N], res;
map<int, int> cnt;

signed main()
{
	cin >> n >> c;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		cnt[a[i]]++;
	}
	sort(a, a + n + 1);
	int len = unique(a, a + n + 1) - a - 1;

	for (int i = 1; i <= len; i++)
	{
		int x = cnt[a[i]];
		int y = cnt[a[i] - c];
		res += x * y;
	}
	cout << res;

	return 0;
}