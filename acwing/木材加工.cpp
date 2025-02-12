#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N], n, m, k;

int judge(int x)
{
	int res = 0;
	for (int i = 1; i <= n; i++) res += a[i] / x;
	return res;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		k = max(k, a[i]);
	}

	int l = 0, r = k + 1;
	while (l + 1 != r)
	{
		int mid = l + r >> 1;
		if (judge(mid) < m) r = mid;
		else l = mid;
	}
	cout << l;

	return 0;
}