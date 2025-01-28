#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int a[N], n, m, t;

int lowbit(int x) { return x & -x; }

void add(int x, int k)
{
	for (; x <= n; x += lowbit(x)) a[x] += k;
}

int sum(int x)
{
	int res = 0;
	for (; x; x -= lowbit(x)) res += a[x];
	return res;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int k; cin >> k;
		add(i, k - t);
		t = k;
	}
	while (m--)
	{
		int op, x, y, k; cin >> op;
		if (op == 1)
		{
			cin >> x >> y >> k;
			add(x, k), add(y + 1, -k);
		}
		else
		{
			cin >> x;
			cout << sum(x) << '\n';
		}
	}

	return 0;
}