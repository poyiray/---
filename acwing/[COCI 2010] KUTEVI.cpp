#include <bits/stdc++.h>
using namespace std;

const int N = 2000;
int a[N], b[N], f[N], n, m;

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];

	f[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= 1500; j++)
		{
			if (j >= a[i]) f[j % 360] |= f[(j - a[i]) % 360];
			f[j % 360] |= f[(j + a[i]) % 360];
		}
	}

	for(int i = 1; i <= m; i++)
	{
		if (f[b[i]]) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}