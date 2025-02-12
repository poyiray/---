#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5e4 + 10;
int a[N], len, n, m;

bool judge(int x)
{
	int cnt = 0;
	int i = 0;
	while (i <= n)
	{
		int j = i + 1;
		while (j <= n + 1 && a[j] - a[i] < x) j++, cnt++;
		i = j;
	}
	return cnt <= m;
}

signed main()
{
	cin >> len >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	a[n + 1] = len;
	int l = 0, r = len + 1;
	while (l + 1 != r)
	{
		int mid = l + r >> 1;
		if (judge(mid)) l = mid;
		else r = mid;
	}
	cout << l;

	return 0;
}