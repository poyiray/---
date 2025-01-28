#include <bits/stdc++.h>
using namespace std;

#define int long long
int a, b, p;

int quick_pow(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b & 1) res = res * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return res;
}

signed main()
{
	cin >> a >> b >> p;
	int res = quick_pow(a, b);
	cout << a << "^" << b << " mod " << p << "=" << res;

	return 0;
}