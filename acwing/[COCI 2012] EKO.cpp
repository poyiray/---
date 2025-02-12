#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e6 + 10;
int a[N], n, m;

bool judge(int x)
{
	int res = 0;
	for (int i = 1; i <= n; i++)
		res += max((long long)0, a[i] - x);
	return res >= m;
}

signed main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];

	int l = -1, r = 4e5 + 1;
	while (l + 1 != r)
	{
		int mid = l + r >> 1;
		if (judge(mid)) l = mid;
		else r = mid;
	}
	cout << l;

	return 0;
}