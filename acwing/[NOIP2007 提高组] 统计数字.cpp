#include <bits/stdc++.h>
using namespace std;

int n;
map<int, int> mp;

int main()
{
	cin >> n;
	while (n--)
	{
		int x; cin >> x;
		mp[x]++;
	}
	for (auto &v : mp)
	{
		cout << v.first << " " << v.second << '\n';
	}

	return 0;
}