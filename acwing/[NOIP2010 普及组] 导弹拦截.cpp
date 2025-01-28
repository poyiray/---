#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
struct node
{
	int x, y, d;
	bool operator<(const node& n) const
	{
		return d < n.d;
	}
} a[N];
int n, lx, ly, rx, ry, res = 1e7, maxn;

int main()
{
	cin >> lx >> ly >> rx >> ry >> n;
	for (int i = 1; i <= n; i++)
	{
		int x, y; cin >> x >> y;
		a[i] = { x, y, (x - lx) * (x - lx) +  (y - ly) * (y - ly)};
	}
	sort(a + 1, a + n + 1);

	a[n + 1] = { rx, ry };
	a[0] = { lx, ly };
	for (int i = n; i >= 0; i--)
	{
		int x = a[i + 1].x, y = a[i + 1].y, d = a[i].d;
		maxn = max(maxn, (x - rx) * (x - rx) + (y - ry) * (y - ry));
		res = min(res, maxn + d);
	}
	cout << res;

	return 0;
}