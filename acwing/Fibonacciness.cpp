#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int res = 0, a, b, c, d, e; cin >> a >> b >> d >> e;
	for (c = -100; c <= 100; c++)
	{
		int ans = 0;
		if (c == a + b) ans++;
		if (d == b + c) ans++;
		if (e == c + d) ans++;
		res = max(res, ans);
	}
	cout << res << endl;
}

int main()
{
	int _; cin >> _;
	while (_--) solve();

	return 0;
}
