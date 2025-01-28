#include <bits/stdc++.h>
using namespace std;

int _, n, a, b, c;

void solve()
{
	cin >> n >> a >> b >> c;
	int sum = a + b + c, res = 0;
	res = (n / sum) * 3;
	n %= sum;
	if (n > 0)
	{
		res++;
		n -= a;
	}
	if (n > 0)
	{
		res++;
		n -= b;
	}
	if (n > 0)
	{
		res++;
		n -= c;
	}
	cout << res << endl;
}

int main()
{
	cin >> _;
	while (_--) solve();

	return 0;
}