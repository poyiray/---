#include <bits/stdc++.h>
using namespace std;

const int N = 30;
struct node
{
	int x, y, v;
	bool operator<(const node& n) const
	{
		return v > n.v;
	}
};
int n, m, k, res, len;
node a[N * N];

int main()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int v; cin >> v;
			if (v) a[++len] = { i,j,v };
		}
	}
	sort(a + 1, a + len + 1);
	a[0] = { 0, a[1].y, 0 };
	for (int i = 1; i <= len; i++)
	{
		int x = a[i].x, y = a[i].y, v = a[i].v;
		if (x + abs(x - a[i - 1].x) + abs(y - a[i - 1].y) + 1 <= k)
		{
			res += v;
			k -= abs(x - a[i - 1].x) + abs(y - a[i - 1].y) + 1;
		}
		else break;
	}
	cout << res;

	return 0;
}