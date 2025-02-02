#include <bits/stdc++.h>
using namespace std;

const int N = 2e4 + 10;
int vis[N], n, m;
vector<string> res;
char a[N];

bool judge(char x, char y)
{
	memset(vis, 0, sizeof vis);
	int cnt = 0;
	for (int i = 1; i <= n - 2; i++)
	{
		if (vis[i] || vis[i + 1] || vis[i + 2]) continue;
		if (a[i] == x && a[i + 1] == y && a[i + 2] == y)
		{
			vis[i] = vis[i + 1] = vis[i + 2] = 1;
			cnt++;
		}
	}
	if (cnt >= m) return true;
	if (cnt < m - 1) return false;

	for (int i = 1; i <= n - 2; i++)
	{
		if (vis[i] || vis[i + 1] || vis[i + 2]) continue;
		int sum = 0;
		if (a[i] == x) sum++;
		if (a[i + 1] == y) sum++;
		if (a[i + 2] == y) sum++;
		if (sum >= 2)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	cin >> n >> m >> a + 1;

	for (char i = 'a'; i <= 'z'; i++)
	{
		for (char j = 'a'; j <= 'z'; j++)
		{
			if (i == j) continue;
			if (judge(i, j))
			{
				string s;
				s += i, s += j, s += j;
				res.push_back(s);
			}
		}
	}
	cout << res.size() << '\n';
	for (auto v : res) cout << v << '\n';

	return 0;
}