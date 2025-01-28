#include <bits/stdc++.h>
using namespace std;
char *p1, *p2, buf[100000];
#define nc() (p1==p2 && (p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
int rd()
{
	int x = 0;
	char ch = nc();
	while (ch < 48 || ch>57) ch = nc();
	while (ch >= 48 && ch <= 57)
		x = x * 10 + ch - 48, ch = nc();
	return x;
}

const int N = 1e6 + 10;
int n, a[N], f[N], c[N], d[N];
vector<int> cnt[N];

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	n = rd();
	for (int i = 1; i <= n; i++) a[i] = rd();
	for (int i = 1; i <= n; i++) cnt[rd()].push_back(i);

	memset(f, 0x3f, sizeof f);
	for (int i = 1; i <= n; i++)
	{
		if (!cnt[a[i]].size()) { cout << -1; return 0; }
		int x = cnt[a[i]].back(); 
		cnt[a[i]].pop_back();
		int t = lower_bound(f + 1, f + n + 1, x) - f;
		f[t] = x;
		c[i] = t;
		d[x] = t;
	}

	int len = lower_bound(f + 1, f + n + 1, 1e6 + 10) - f - 1;
	cout << len << '\n';
	for (int i = 1; i <= n; i++) cout << c[i] << " "; cout << '\n';
	for (int i = 1; i <= n; i++) cout << d[i] << " ";

	return 0;
}