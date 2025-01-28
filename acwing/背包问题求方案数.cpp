#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10, F = 1e9 + 7;
int n, m, f[N], res[N];

int main()
{
	cin >> n >> m;
	fill(res, res + m + 1, 1);
	while (n--)
	{
		int v, w; cin >> v >> w;
		for (int i = m; i >= v; i--)
		{
			if (f[i - v] + w > f[i])
			{
				f[i] = f[i - v] + w;
				res[i] = res[i - v];
			}
			else if (f[i - v] + w == f[i])
			{
				res[i] += res[i - v];
			}
			res[i] %= F;
		}
	}
	cout << res[m] % F;

	return 0;
}