#include <bits/stdc++.h>
using namespace std;

int n, i, j;

int dfs(int sum, int cnt, int p, int x, int y, int f)
{
	if (x == i)
	{
		return sum + abs(y - j);
	}
	if (y == j)
	{
		return sum + abs(x - i);
	}

	int f_t = f;
	if ((cnt + 1) % 2 == 0) f_t = -f;

	if (cnt % 2 == 0)
	{
		return dfs(sum + p, cnt + 1, p - 1, x, y + p * f, f_t);
	}
	else
	{
		return dfs(sum + p, cnt + 1, p, x + p * f, y, f_t);
	}
}

int main()
{
	cin >> n >> i >> j;

	cout << dfs(0, 2, n, 1, 0, 1);

	return 0;
}