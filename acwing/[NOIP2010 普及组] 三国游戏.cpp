#include <bits/stdc++.h>
using namespace std;

const int N = 600;
int n, len, res, a[N][N];

int main()
{
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			int x; cin >> x;
			a[i][j] = a[j][i] = x;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		sort(a[i] + 1, a[i] + n + 1);
		res = max(res, a[i][n - 1]);
	}
	cout << 1 << '\n' << res;

	return 0;
}