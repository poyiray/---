#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
char mp[N], vis[N];
string a, b, c;

int main()
{
	cin >> a >> b >> c;
	if (a.size() != b.size()) { cout << "Failed"; return 0; }

	for (int i = 0; i < a.size(); i++)
	{
		char x = a[i], y = b[i];
		if (mp[x] == y) continue;
		if (vis[y] || (mp[x] && mp[x] != y)) { cout << "Failed"; return 0; }
		vis[y] = 1;
		mp[x] = y;
	}
	for (int i = 'A'; i <= 'Z'; i++)
	{
		if (!vis[i]) { cout << "Failed"; return 0; }
	}
	for (int i = 0; i < c.size(); i++)
	{
		cout << (char)mp[c[i]];
	}

	return 0;
}