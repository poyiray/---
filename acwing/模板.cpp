#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int n, k, a[N], q[N];

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];

	int h = 0, t = -1;
	
	for (int i = 1; i <= n; i++)
	{
		while (h <= t && q[h] <= i - k) h++;
		while (h <= t && a[i] <= a[q[t]]) t--;
		q[++t] = i;
		if (i >= k) cout << a[q[h]] << " ";
	}
	cout << endl;

	h = 0, t = -1;
	for (int i = 1; i <= n; i++)
	{
		while (h <= t && q[h] <= i - k) h++;
		while (h <= t && a[i] >= a[q[t]]) t--;
		q[++t] = i;
		if (i >= k) cout << a[q[h]] << " ";
	}

	return 0;
}