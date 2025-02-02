#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int a[2 * N], n, k;

void solve()
{
	memset(a, 0, sizeof a);
	int res = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		a[x]++;
	}

	for (int i = 1; i * 2 <= k; i++)
	{
		if (i == k - i) res += a[i] / 2;
		else res += min(a[i], a[k - i]);
	}
	cout << res << endl;
}

int main()
{
	int _;  cin >> _;
	while (_--) solve();

	return 0;
}