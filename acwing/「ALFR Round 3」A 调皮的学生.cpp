#include <bits/stdc++.h>
using namespace std;

const int N = 400;
int a[N], n;

int main()
{
	cin >> n;
	for (int i = 1; i <= 3; i++)
	{
		int _; cin >> _;
		while (_--)
		{
			int x; cin >> x;
			a[x]++;
		}
	}

	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == 0 || a[i] > 1) res++;
	}
	cout << res;

	return 0;
}