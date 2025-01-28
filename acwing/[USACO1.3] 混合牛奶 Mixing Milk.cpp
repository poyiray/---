#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10;
struct node
{
	int x, y;
	bool operator<(node& n)
	{
		return x < n.x;
	}
};
int m, n, res;
node a[N];

int main()
{
	cin >> m >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
	sort(a + 1, a + n + 1);

	for (int i = 1; i <= n; i++)
	{
		res += min(m, a[i].y) * a[i].x;
		m -= min(m, a[i].y);
	}
	cout << res;

	return 0;
}