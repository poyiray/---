#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int f[3][N], n, a[N];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	memset(f[0], -0x3f, sizeof f[0]);
	for (int i = 1; i <= n; i++)
	{
		f[0][i] = max(f[0][i - 1], f[2][i - 1] - a[i]);
		f[1][i] = f[0][i - 1] + a[i];
		f[2][i] = max(f[2][i - 1], f[1][i - 1]);
	}
	cout << max(f[1][n], f[2][n]);

	return 0;
}