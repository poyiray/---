#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int a[N][N], n, res = 0;
char b[N] = { '0','A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q','K' };
char c[N] = { '0','D','C','H','S' };

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		char x, y; cin >> x >> y;
		a[x][y]++;
	}

	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 13; j++)
		{
			if (a[c[i]][b[j]]) res++;
		}
	}
	cout << 52 - res;

	return 0;
}