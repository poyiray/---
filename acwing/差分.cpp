#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 10;
int a[N], p, q, n;

signed main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = n; i >= 1; i--) a[i] = a[i] - a[i - 1];
	for (int i = 2; i <= n; i++)
	{
		if (a[i] >= 0) p += a[i];
		else q -= a[i];
	}
	cout << max(q, p) << '\n' << abs(q - p) + 1;

	return 0;
}