#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, y, res = 0; cin >> n >> y;
	for (int i = 1; i <= n; i++)
	{
		int x = i;
		while (x)
		{
			if(x % 10 == y) res++;
			x /= 10;
		}
	}
	cout << res;

	return 0;
}