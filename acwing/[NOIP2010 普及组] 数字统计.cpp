#include <bits/stdc++.h>
using namespace std;

int main()
{
	int l, r, res = 0; cin >> l >> r;
	for (int i = l; i <= r; i++)
	{
		int x = i;
		while (x)
		{
			if (x % 10 == 2) res++;
			x /= 10;
		}
	}
	cout << res;

	return 0;
}