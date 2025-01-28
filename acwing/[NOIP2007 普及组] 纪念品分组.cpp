#include <bits/stdc++.h>
using namespace std;

const int N = 3e4 + 10;
int a[N], w, n, res;

int main()
{
	cin >> w >> n;
	for (int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		a[i] = x;
	}
	sort(a + 1, a + n + 1);

	int l = 1, r = n;
	while (l <= r)
	{
		if (a[l] + a[r] <= w) l++, r--;
		else r--;
		res++;
	}
	cout << res;

	return 0;
}