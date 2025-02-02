#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int a[N], n;

void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int i = 0; i <= n - 2; i++)
	{
		a[i + 1] -= min(a[i + 1], a[i]);
		if (a[i + 1] > a[i + 2])
		{
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main()
{
	int _; cin >> _;
	while (_--) solve();

	return 0;
}