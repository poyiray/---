#include <bits/stdc++.h>
using namespace std;

inline int read()
{
	int x = 0; char ch = getchar();
	while (ch<'0' || ch>'9') ch = getchar();
	while (ch >= '0' && ch <= '9')
		x = x * 10 + ch - '0', ch = getchar();
	return x;
}

#define int long long
const int N = 1e5 + 10;
struct node
{
	int num, col, id;
	bool operator<(const node& n) const
	{
		return col < n.col;
	}
};
node a[N], odd[N], even[N];
int n, m, len_odd, len_even, res;

void solve(node a[], int len)
{
	int l = 1, r = 1;
	while (l <= len)
	{
		int sum_idx = 0,
			sum_val = 0, 
			sum_idx_val = 0;
		int ans = 0;
		while (r <= len && a[r].col == a[l].col)
		{
			if (r - l + 1 >= 2)
			{
				ans = a[r].id * sum_val + a[r].num * sum_idx + (r - l) * a[r].num * a[r].id + sum_idx_val;
			}
			sum_idx += a[r].id;
			sum_val += a[r].num;
			sum_idx_val += a[r].id * a[r].num;

			res = (res + ans) % 10007;
			r++;
		}
		l = r;
	}
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	n = read(), m = read();
	for (int i = 1; i <= n; i++) a[i].num = read();
	for (int i = 1; i <= n; i++)
	{
		a[i].col = read();
		a[i].id = i;
	}

	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 0) even[++len_even] = a[i];
		else odd[++len_odd] = a[i];
	}

	stable_sort(even + 1, even + 1 + len_even);
	stable_sort(odd + 1, odd + 1 + len_odd);

	solve(even, len_even);
	solve(odd, len_odd);
	cout << res;

	return 0;
}