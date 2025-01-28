#include <bits/stdc++.h>
using namespace std;

#define int long long
int n, m, x, y;
void exgcd(int a, int b, int &x, int &y)
{
	if (!b)
	{
		x = 1, y = 0;
		return;
	}
	int x1, y1;
	exgcd(b, a % b, x1, y1);
	x = y1, y = x1 - a / b * y1;
}

signed main()
{
	cin >> n >> m;
	exgcd(n, m, x, y);
	cout << (x % m + m) % m;

	return 0;
}