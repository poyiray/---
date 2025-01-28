#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 400;
int a[N], n;

signed main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	int i = 0, j = n, res = 0;
	while (i < j)
	{
		int ans = (a[j] - a[i]) * (a[j] - a[i]);
		i++;
		ans += (a[j] - a[i]) * (a[j] - a[i]);
		j--;
		res += ans;
	}
	cout << res;

	return 0;
}