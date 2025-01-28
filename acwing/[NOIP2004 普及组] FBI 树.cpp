#include <bits/stdc++.h>
using namespace std;

const int N = 2000;
char c[N];
int n, m;

char dfs(int l, int r)
{
	if (l == r)
	{
		if (c[l] == '1') cout << "I";
		else cout << "B";
		return c[l] == '1' ? 'I' : 'B';
	}

	int mid = l + r >> 1;
	char a = dfs(l, mid);
	char b = dfs(mid + 1, r);
	if (a != b) cout << "F";
	else cout << a;
	return a == b ? a : 'F';
}

int main()
{
	cin >> n;
	m = pow(2, n);
	for (int i = 1; i <= m; i++) cin >> c[i];
	dfs(1, m);
	return 0;
}