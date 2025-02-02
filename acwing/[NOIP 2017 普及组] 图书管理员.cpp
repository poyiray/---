#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int a[N], n, m;

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	while (m--)
	{
		int len, x; cin >> len >> x;
		int f = false;
		for (int i = 1; i <= n; i++)
		{
			if (x == a[i] % (int)pow(10, len))
			{
				cout << a[i] << '\n';
				f = true;
				break;
			}
		}
		if (!f) cout << -1 << '\n';
	}

	return 0;
}