#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int vis[N];
vector<int> prime;

int main()
{
	int n; cin >> n;
	for (int i = 2; i <= 45000; i++)
	{
		if (!vis[i]) prime.push_back(i);
		for (int j = i * i; j <= 45000; j *= i) vis[j] = 1;
	}

	for (int i = 0; i < prime.size(); i++)
	{
		int p = prime[i];
		if (n % p == 0 && p * (n / p) == n)
		{
			cout << n / p;
			return 0;
		}
	}

	return 0;
}