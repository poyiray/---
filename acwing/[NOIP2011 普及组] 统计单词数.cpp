#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
string sub, s;
int len, res1, res2;
int main()
{
	cin >> sub; getchar();
	getline(cin, s);
	for (auto &c : sub) c = tolower(c);
	for (auto &c : s) c = tolower(c);
	
	int l = 0, r = 0;
	bool f = true;
	while (l < s.size())
	{
		string tmp;
		while (r < s.size() && s[r] != ' ') tmp += s[r++]; r++;
		if (tmp == sub)
		{
			res1++;
			if(f) res2 = l, f = false;
		}
		l = r;
	}
	if (res1) cout << res1 << " " << res2;
	else cout << -1;

	return 0;
}