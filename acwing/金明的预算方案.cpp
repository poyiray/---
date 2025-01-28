#include <bits/stdc++.h>
using namespace std;

const int N = 4e4;
int f[N], n, m, v[3][N], w[3][N], len[N], a[N];

int main()
{
	cin >> m >> n;
	for (int i = 1; i <= n; i++)
	{
		int V, W, q; cin >> V >> W >> q;
		if (!q)
		{
			a[++a[0]] = i;
			v[0][i] = V;
			w[0][i] = W;
		}
		else
		{
			v[++len[q]][q] = V;
			w[len[q]][q] = W;
		}
	}

	for (int t = 1; t <= a[0]; t++)
	{
		int i = a[t];
		for (int j = m; j >= 0; j--)
		{
			int x = f[j];
			if (j - v[0][i] >= 0) x = max(x, f[j - v[0][i]] + v[0][i] * w[0][i]);
			if (j - v[0][i] - v[1][i] >= 0) x = max(x, f[j - v[1][i] - v[0][i]] + v[0][i] * w[0][i] + v[1][i] * w[1][i]);
			if (j - v[2][i] - v[0][i] >= 0) x = max(x, f[j - v[2][i] - v[0][i]] + v[0][i] * w[0][i] + v[2][i] * w[2][i]);
			if(j - v[1][i] - v[2][i] - v[0][i] >= 0) x = max(x, f[j - v[2][i] - v[1][i] - v[0][i]] + v[2][i] * w[2][i] + v[1][i] * w[1][i] + v[0][i] * w[0][i]);
			f[j] = x;
		}
	}
	cout << f[m];

	return 0;
}