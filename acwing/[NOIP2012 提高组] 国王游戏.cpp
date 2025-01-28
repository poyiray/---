#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
struct node
{
	int a, b, c;
	bool operator<(const node& n) const
	{
		return c < n.c;
	}
};
node arr[N];
int n, x[N], y[N];
vector<int> maxn, sum;

vector<int> div(int num)
{
	vector<int> res;
	res.resize(sum.size());
	int r = 0;
	for (int i = sum.size() - 1; ~i; i--)
	{
		r = r * 10 + sum[i];
		res[i] = r / num;
		r %= num;
	}
	while (res.size() && !res.back()) res.pop_back();
	return res;
}

vector<int> MAX(vector<int> a, vector<int> b)
{
	if (a.size() > b.size()) return a;
	if (b.size() > a.size()) return b;
	if (!a.size() && !b.size()) return a;
	for (int i = a.size() - 1; ~i; i--)
	{
		if (a[i] > b[i]) return a;
		if (b[i] > a[i]) return b;
	}
	return a;
}

vector<int> mul(int num)
{
	vector<int> res;
	res.resize(sum.size() + 10);
	for (int i = 0; i < sum.size(); i++)
	{
		res[i] += sum[i] * num;
		res[i + 1] += res[i] / 10;
		res[i] %= 10;
	}
	for (int i = sum.size() - 1; i < res.size() - 1; i++)
	{
		res[i + 1] += res[i] / 10;
		res[i] %= 10;
	}
	while (res.size() && !res.back()) res.pop_back();
	return res;
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n + 1; i++)
	{
		int l, r; cin >> l >> r;
		arr[i] = { l, r, l * r };
	}
	sort(arr + 2, arr + n + 2);
	
	string s = to_string(arr[1].a);
	reverse(s.begin(), s.end());
	for (int i = 0; i < s.size(); i++)
		sum.push_back(s[i] - '0');

	for (int i = 2; i <= n + 1; i++)
	{
		maxn = MAX(maxn, div(arr[i].b));
		sum = mul(arr[i].a);
	}
	if (!maxn.size())
	{
		cout << 0;
		return 0;
	}
	for (int i = maxn.size() - 1; ~i; i--)
	{
		cout << maxn[i];
	}

	return 0;
}