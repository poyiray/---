#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, t, f[N], res[N];
int a[] = { 6,2,5,5,4,5,6,3,7,6 };

void dfs(int x)
{
	if (!x) return;
	dfs(x - a[res[x]]);
	if (x == 6) cout << 6;
	else cout << res[x];
}

int main()
{
	cin >> t;
	while (t--)
	{
		memset(f, 0x3f, sizeof f);
		f[0] = 0;
		cin >> n;
		if (n <= 1)
		{
			cout << -1 << endl;
			continue;
		}
		for (int i = 0; i < 10; i++)
		{
			for (int j = a[i]; j <= n; j++)
			{
				if (f[j - a[i]] + 1 < f[j])
				{
					f[j] = f[j - a[i]] + 1;
					res[j] = i;
				}
			}
		}
		dfs(n);
		cout << endl;
	}

	return 0;
}