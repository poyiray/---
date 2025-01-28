#include <bits/stdc++.h>
using namespace std;

//time complexity: O(R * NlogN)

const int N = 2e5 + 10;
struct node
{
	int x, s, k;
	bool operator<(const node& n) const
	{
		if (s == n.s) return x < n.x;
		return s > n.s;
	}
} a[N], win[N], lose[N];
int n, r, q;

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> r >> q;
	for (int i = 1; i <= 2 * n; i++) cin >> a[i].s;
	for (int i = 1; i <= 2 * n; i++)
	{
		a[i].x = i;
		cin >> a[i].k;
	}
	stable_sort(a + 1, a + 2 * n + 1);
	while (r--)
	{
		int len1 = 0, len2 = 0, len = 0;
		for (int i = 1; i <= 2 * n; i += 2)
		{
			if (a[i].k > a[i + 1].k)
			{
				a[i].s++;
				win[++len1] = a[i];
				lose[++len2] = a[i + 1];
			}
			else
			{
				a[i + 1].s++;
				win[++len1] = a[i + 1];
				lose[++len2] = a[i];
			}
		}
		int l1 = 1, l2 = 1;
		while (l1 <= len1 && l2 <= len2)
		{
			if (win[l1].s == lose[l2].s)
			{
				if (win[l1].x < lose[l2].x) a[++len] = win[l1++];
				else a[++len] = lose[l2++];
			}
			else
			{
				if (win[l1].s > lose[l2].s) a[++len] = win[l1++];
				else a[++len] = lose[l2++];
			}
		}
		while (l1 <= len1) a[++len] = win[l1++];
		while (l2 <= len2) a[++len] = lose[l2++];
	}
	cout << a[q].x;
	
	return 0;
}