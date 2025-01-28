#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
int a[N], n, m, b[N];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];

	b[0] = 1e7;
	for (int i = 1; i <= n; i++)
	{
		int x = 0;
		for (int j = 1; j <= m; j++)
		{
			if (b[x] > b[j]) x = j;
		}
		b[x] += a[i];
	}

	int ans = 0;
	for (int i = 1; i <= m; i++) ans = max(ans, b[i]);
	cout << ans;

	return 0;
}