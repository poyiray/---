#include <bits/stdc++.h>
using namespace std;

const int N = 5e6 + 10;
int a[N], n, k;

int qsort(int l, int r)
{
	int i = l, j = r, num = a[l + r >> 1];
	while (i <= j)
	{
		while (a[i] < num) i++;
		while (a[j] > num) j--;
		if (i <= j) swap(a[i++], a[j--]);
	}
	if (k <= j) return qsort(l, j);
	else if (k >= i) return qsort(i, r);
	else return a[k];
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	cout << qsort(0, n - 1);

	return 0;
}