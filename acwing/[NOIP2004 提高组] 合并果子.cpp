#include <bits/stdc++.h>
using namespace std;

int n, res;
priority_queue<int, vector<int>, greater<int>> q;

signed main()
{
	cin >> n;
	while (n--)
	{
		int x; cin >> x;
		q.push(x);
	}
	while (q.size() > 1)
	{
		int a = q.top(); q.pop();
		int b = q.top(); q.pop();
		res += a + b;
		q.push(a + b);
	}
	cout << res;

	return 0;
}