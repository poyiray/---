#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int a[N], n, m;

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int x; cin >> x;
		a[x]++;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= a[i]; j++) cout << i << " ";
	}

	return 0;
}