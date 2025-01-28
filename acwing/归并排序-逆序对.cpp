#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5e5 + 10;
int n, a[N], tmp[N], res;

void merge_sort(int l, int r, int a[])
{
	if (l == r) return;
	int mid = l + r >> 1;
	merge_sort(l, mid, a), merge_sort(mid + 1, r, a);
	
	int i = l, j = mid + 1, k = 0;
	while (i <= mid && j <= r)
	{
		if (a[i] <= a[j]) tmp[++k] = a[j++];
		else res += r - j + 1, tmp[++k] = a[i++];
	}
	while (i <= mid) tmp[++k] = a[i++];
	while (j <= r) tmp[++k] = a[j++];
	for (int i = l; i <= r; i++) a[i] = tmp[i - l + 1];
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	merge_sort(1, n, a);
	cout << res;

	return 0;
}