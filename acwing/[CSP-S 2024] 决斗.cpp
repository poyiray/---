#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N], n, res;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		res = max(res, ++a[x]);
	}
	cout << res;

	return 0;
}