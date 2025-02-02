#include <bits/stdc++.h>
using namespace std;

int t, n;
unordered_map<int, bool> vis;

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> t;
	while (t--)
	{
		vis.clear();
		cin >> n;
		while (n--)
		{
			int x; cin >> x;
			if (!vis[x])
			{
				cout << x << " ";
				vis[x] = 1;
			}
		}
		cout << '\n';
	}

	return 0;
}