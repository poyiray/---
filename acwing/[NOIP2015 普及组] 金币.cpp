#include <bits/stdc++.h>
using namespace std;

int n, res, cnt = 1;

int main()
{
	cin >> n;
	while (n > 0)
	{
		res += min(cnt, n) * cnt;
		n -= cnt++;
	}
	cout << res;

	return 0;
}