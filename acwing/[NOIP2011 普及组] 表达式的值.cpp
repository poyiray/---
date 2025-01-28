#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, M = 10007;
int one[N], zero[N], n, top, cnt;
char st[N], res[2 * N];

int main()
{
	cin >> n;
	res[++cnt] = '_';
	for (int i = 1; i <= n; i++)
	{
		char c; cin >> c;
		if (c == '(' || c == '*') st[++top] = c;
		else if (c == '+')
		{
			while (st[top] == '*') res[++cnt] = st[top--];
			st[++top] = c;
		}
		else if (c == ')')
		{
			while (st[top] != '(') res[++cnt] = st[top--];
			top--;
		}
		if (c != '(' && c != ')') res[++cnt] = '_';
	}
	while (top) res[++cnt] = st[top--];

	for (int i = 1; i <= cnt; i++)
	{
		if (res[i] == '_')
		{
			one[++top] = 1;
			zero[top] = 1;
		}
		else if (res[i] == '+')
		{
			--top;
			one[top] = (zero[top] * one[top + 1] + zero[top + 1] * one[top] + one[top] * one[top + 1]) % M;
			zero[top] = (zero[top] * zero[top + 1]) % M;
		}
		else
		{
			--top;
			zero[top] = (zero[top] * one[top + 1] + zero[top + 1] * one[top] + zero[top] * zero[top + 1]) % M;
			one[top] = (one[top] * one[top + 1]) % M;
		}
	}
	cout << zero[1];

	return 0;
}