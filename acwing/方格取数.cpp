#include <bits/stdc++.h>
using namespace std;

const int N = 1e2;
int f[N][N][N], n, v[N][N];

int main()
{
	cin >> n;
	int x, y, w;
	while (cin >> x >> y >> w && x) v[x][y] = w;

	for (int k = 2; k <= 2 * n; k++)
	{
		for (int i = 1; i <= k - 1; i++)
		{
			for (int j = 1; j <= k - 1; j++)
			{
				f[k][i][j] = max({ f[k - 1][i][j], f[k - 1][i - 1][j], f[k - 1][i - 1][j - 1], f[k - 1][i][j - 1] }) + v[i][k - i] + v[j][k - j];
				if (i == j) f[k][i][j] -= v[i][k - i];
			}
		}
	}
	cout << f[2 * n][n][n];
	return 0;
}