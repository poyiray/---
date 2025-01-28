#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1010;
struct node
{
	int x, y;
	bool operator<(const node& n) const { return y < n.y; }
};
int n, sum, res;
node a[N];

signed main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		a[i] = { i, x };
	}
	sort(a + 1, a + 1 + n);
	for (int i = 2; i <= n; i++)
	{
		sum += a[i - 1].y;
		res += sum;
	}
	for (int i = 1; i <= n; i++) cout << a[i].x << " ";
	cout << '\n';
	cout << fixed << setprecision(2) << res * 1.0 / n;

	return 0;
}