#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int a[N], maxn = -1e9, minn = 1e9;

bool isprime(int x)
{
	if (x <= 1) return false;
	for (int i = 3; i * i <= x; i++)
	{
		if (x % i == 0) return false;
	}
	return true;
}

int main()
{
	string s; cin >> s;
	for (auto &c : s) a[c]++;
	for (int i = 'a'; i <= 'z'; i++)
	{
		if (!a[i]) continue;
		maxn = max(maxn, a[i]);
		minn = min(minn, a[i]);
	}
	int res = maxn - minn;
	if (isprime(res)) cout << "Lucky Word\n" << res;
	else cout << "No Answer\n" << 0;
	return 0;
}