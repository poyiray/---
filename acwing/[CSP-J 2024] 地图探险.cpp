#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
char a[N][N];
int n, m, k, x, y, d;

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

void solve()
{
	cin >> n >> m >> k >> x >> y >> d;
	for (int i = 1; i <= n; i++) cin >> a[i] + 1;

	int res = 1;
	a[x][y] = 'o';
	while (k--)
	{
		int xx = x + dx[d], yy = y + dy[d];
		if (a[xx][yy] == 'x' || xx < 1 || xx > n || yy < 1 || yy > m) d = (d + 1) % 4;
		else
		{
			if (a[xx][yy] != 'o') res++;
			x = xx, y = yy;
			a[x][y] = 'o';
		}
	}
	cout << res << '\n';
}

int main()
{
	int t; cin >> t;
	while (t--) solve();

	return 0;
}