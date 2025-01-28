#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
__int128 a[N], b[N], c[N], res;
int n, p;

__int128 cmp(__int128 x, __int128 y) { return x > y ? x : y; }

signed main()
{
	cin >> n >> p;
	for (int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		a[i] = x;
	}
	if (n == 1)
	{
		cout << (int)(a[1] % p);
		return 0;
	}
	res = a[1] + a[1];
	b[1] = c[1] = a[1];
	for (int i = 2; i <= n; i++)
	{
		a[i] = cmp(a[i], a[i - 1] + a[i]);
		b[i] = cmp(a[i], b[i - 1]); // ¹±Ï×Öµ
	}
	for (int i = 2; i <= n; i++)
	{
		res = cmp(b[i - 1] + c[i - 1], res);
		c[i] = res; //·ÖÊý
	}

	cout << (int)(cmp(res, b[1]) % p);

	return 0;
}