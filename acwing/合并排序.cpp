#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, a[N], tmp[N];

// ¹é²¢ÅÅÐò°å×Ó
void merge_sort(int l, int r, int a[])
{
	if (l == r) return;
	int mid = l + r >> 1;
	merge_sort(l, mid, a);
	merge_sort(mid + 1, r, a);

	int left = l, right = mid + 1, len = 0;
	while (left <= mid && right <= r)
	{
		if (a[left] <= a[right]) tmp[++len] = a[left++];
		else tmp[++len] = a[right++];
	}
	while (left <= mid) tmp[++len] = a[left++];
	while (right <= r) tmp[++len] = a[right++];
	for (int i = l; i <= r; i++) a[i] = tmp[i - l + 1];
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	merge_sort(1, n, a);
	for (int i = 1; i <= n; i++) cout << a[i] << " ";

	return 0;
}