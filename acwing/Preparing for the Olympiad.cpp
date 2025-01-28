#include <bits/stdc++.h>
using namespace std;

const int N = 200;
int a[N], b[N], n;

void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	int res = 0;

	b[n + 1] = 0;
	for (int i = 1; i <= n; i++)
	{
		int x = a[i] - b[i + 1];
		if (x > 0) res += x;
	}
	
	cout << res << endl;
}

int main()
{
	int _; cin >> _;
	while (_--) solve();

	return 0;
}