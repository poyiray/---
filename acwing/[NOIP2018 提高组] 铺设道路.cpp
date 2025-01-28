#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N], n, res;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int i = 1; i <= n; i++)
	{
		if (a[i] > a[i - 1]) res += a[i] - a[i - 1];
	}
	cout << res;

	return 0;
}