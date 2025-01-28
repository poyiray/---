#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int x[N], y[N], n, res;
double m[N][N];

int main()
{
	cin >> n;
	if (n == 1) { cout << 1; return 0; }
	for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			m[i][j] = (double)(y[i] - y[j]) / (x[i] - x[j]);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		sort(m[i] + 1, m[i] + n + 1);
		int cnt = 0;

		for (int j = 3; j <= n + 1; j++)
		{
			if (m[i][j] != m[i][j - 1])
			{
				res = max(res, cnt);
				cnt = 0;
			}
			else cnt++;
		}
	}
	cout << res + 2;

	return 0;
}