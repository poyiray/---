#include <bits/stdc++.h>
using namespace std;

const int N = 2e4 + 10;
struct node
{
	int l, r;
};
node a[N];
int f[N][2], n;

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int l, r; cin >> l >> r;
		a[i] = { l,r };
	}

	a[0] = { 1,1 };
	a[n + 1] = { n,n };
	for (int i = 1; i <= n + 1; i++)
	{
		f[i][0] = min(f[i - 1][0] + abs(a[i - 1].l - a[i].r),
			          f[i - 1][1] + abs(a[i - 1].r - a[i].r)) + abs(a[i].r - a[i].l);
		f[i][1] = min(f[i - 1][0] + abs(a[i - 1].l - a[i].l),
			          f[i - 1][1] + abs(a[i - 1].r - a[i].l)) + abs(a[i].l - a[i].r);
	}
	cout << f[n + 1][0] + n - 1;

	return 0;
}