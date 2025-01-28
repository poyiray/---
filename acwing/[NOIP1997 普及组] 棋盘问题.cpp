#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int n, m, a, b;

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (i == j) a += (m - j + 1) * (n - i + 1);
			else b += (m - j + 1) * (n - i + 1);
		}
	}
	cout << a << " " << b;

	return 0;
}