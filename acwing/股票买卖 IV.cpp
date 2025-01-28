#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N][110], b[N][110], n, k, res;

int main()
{
	cin >> n >> k;
	// a³ÖÓĞ
	// bÂô³ö
	memset(a, -0x3f, sizeof a);
	for (int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		for (int j = 1; j <= k; j++)
		{
			a[i][j] = max(a[i - 1][j], b[i - 1][j - 1] - x);
			b[i][j] = max(b[i - 1][j], a[i - 1][j] + x);
			res = max(res, b[i][j]);
		}
	}
	cout << res;

	return 0;
}