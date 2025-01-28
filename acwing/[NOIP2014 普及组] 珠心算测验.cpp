#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int a[N], n, res;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a, a + 1 + n);
	for (int i = 3; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			int f = false;
			for (int k = j + 1; k < i; k++)
			{
				if (a[j] + a[k] == a[i])
				{
					res++;
					f = true;
					break;
				}
			}
			if (f) break;
		}
	}
	cout << res;

	return 0;
}