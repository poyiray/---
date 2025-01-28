#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5 + 10;
int x[N], n, a[N];

int dfs(int l, int r)
{
	if (l == r) return x[l];
	int mid = l + r >> 1;
	int t = dfs(l, mid);
	int y = dfs(mid + 1, r);

	int a = -1e10, b = -1e10, sum = 0;
	for (int i = mid; i >= l; i--)
	{
		sum += x[i];
		a = max(a, sum);
	}
	sum = 0;
	for (int i = mid + 1; i <= r; i++)
	{
		sum += x[i];
		b = max(b, sum);
	}
	return max({ t,y,a + b });
}

int pre_fix()
{
	for (int i = 1; i <= n; i++) a[i] = a[i - 1] + x[i];
	int minn = 0, res = a[1];
	for (int i = 1; i <= n; i++)
	{
		res = max(res, a[i] - minn);
		minn = min(minn, a[i]);
	}
	return res;
}

int dp()
{
	int res = -1e9;
	for (int i = 1; i <= n; i++)
	{
		a[i] = max(a[i - 1] + x[i], x[i]);
		res = max(a[i], res);
	}
	return res;
}

signed main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> x[i];
	cout << dp();

	return 0;
}