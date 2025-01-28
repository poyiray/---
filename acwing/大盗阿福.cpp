#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N];

int main()
{
	int t; cin >> t;
	while (t--)
	{
		memset(a, 0, sizeof a);
		int n; cin >> n;
		for (int i = 1; i <= n; i++)
		{
			int x; cin >> x;
			a[i] = max(a[i - 2] + x, a[i - 1]);
		}
		cout << a[n] << endl;
	}

	return 0;
}