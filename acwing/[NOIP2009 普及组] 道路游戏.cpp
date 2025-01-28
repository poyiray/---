#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int f[N], n, m, p, a[N][N], cost[N];

int main()
{
	cin >> n >> m >> p;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) cin >> a[i][j];
	}
	for (int i = 1; i <= n; i++) cin >> cost[i];
	for (int i = 1; i <= m; i++) f[i] = -1e9;

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int res = f[i - 1] - cost[j];
			for (int k = 0; k < p && i + k <= m; k++)
			{
				int t = (j + k - 1) % n + 1;
				res += a[t][i + k];
				f[i + k] = max(f[i + k], res);
			}
		}
	}
	cout << f[m];

	return 0;
}