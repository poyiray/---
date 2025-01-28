#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int a[N][N], n, m, r, c, f[N][N], opt[N * 1000][N], len, val_c[N], val_r[N][N], ord[N], res = 1e8;

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m >> r >> c;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	for (int i = 1; i < (1 << m); i++)
	{
		int cnt = 0;
		for (int j = 0; j < m; j++)
			if ((i >> j) & 1) cnt++;

		if (cnt == c)
		{
			++len;
			for (int j = 0; j < m; j++)
				if ((i >> j) & 1)
					opt[len][++opt[len][0]] = j;
		}
	}

	for (int i = 1; i <= len; i++)
	{
		memset(f, 0x3f, sizeof f);
		for (int j = 1; j <= c; j++) ord[j] = opt[i][j];
		for (int j = 0; j < n; j++)
		{
			int sum = 0;
			for (int k = 1; k <= c - 1; k++)
				sum += abs(a[j][ord[k]] - a[j][ord[k + 1]]);
			val_c[j] = sum;
		}

		for (int j = 0; j < n - 1; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				int sum = 0;
				for (int l = 1; l <= c; l++)
					sum += abs(a[j][ord[l]] - a[k][ord[l]]);
				val_r[k][j] = sum;
			}
		}
		for (int j = 0; j < n; j++)
		{
			f[j][0] = 0;
			f[j][1] = val_c[j];
			for (int k = 0; k < j; k++)
			{
				for (int l = 1; l <= r; l++)
				{
					f[j][l] = min(f[j][l], f[k][l - 1] + val_c[j] + val_r[j][k]);
				}
			}
		}

		for (int j = 0; j < n; j++) res = min(res, f[j][r]);
	}
	cout << res;

	return 0;
}