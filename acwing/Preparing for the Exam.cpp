#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;
int a[N], q[N], n, m, k;

void solve()
{
	memset(q, 0, sizeof q);
	cin >> n >> m >> k;

	for (int i = 1; i <= m; i++) cin >> a[i];
	for (int i = 1; i <= k; i++)
	{
		int x; cin >> x;
		q[x] = 1;
	}
	if (k + 1 < n)
	{
		for (int i = 1; i <= m; i++) cout << 0;
		cout << endl;
		return;
	}
	
	int x = -1;
	for (int i = 1; i <= n; i++)
	{
		if (!q[i]) x = i;
	}

	if (!~x)
	{
		for (int i = 1; i <= m; i++) cout << 1;
		cout << endl;
		return;
	}

	for (int i = 1; i <= m; i++)
	{
		if (a[i] == x) cout << 1;
		else cout << 0;
	}
	cout << endl;
}

int main()
{
	int _; cin >> _;
	while (_--) solve();

	return 0;
}