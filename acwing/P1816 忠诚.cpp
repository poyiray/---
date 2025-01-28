#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, M = 20;
int f[N][M], n, m;

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> f[i][0];

	for (int j = 1; j <= (int)log2(n); j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
			f[i][j] = min(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
	while (m--)
	{
		int l, r; cin >> l >> r;
		int k = log2(r - l + 1);
		cout << min(f[l][k], f[r - (1 << k) + 1][k]) << ' ';
	}

	return 0;
}