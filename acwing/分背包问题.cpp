#include <bits/stdc++.h>
using namespace std;

const int N = 110;
struct node
{
	int m, v;
	bool operator<(const node& n) const
	{
		return 1.0 * v / m > 1.0 * n.v / n.m;
	}
};
int n, t;
double res;
node a[N];

int main()
{
	int n, t; cin >> n >> t;
	for (int i = 1; i <= n; i++) cin >> a[i].m >> a[i].v;
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++)
	{
		res += (1.0 * a[i].v / a[i].m) * min(t, a[i].m);
		t -= min(t, a[i].m);
	}
	cout << setprecision(2) << fixed << res;

	return 0;
}