#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int top, len, res[N];
char st[N];

int main()
{
	char c;
	int tmp = 0;
	while (cin >> c)
	{
		if (c != '+' && c != '*') tmp = tmp * 10 + c - '0';
		else if (c == '*')
		{
			st[++top] = c;
			res[++len] = tmp % 10000;
			tmp = 0;
		}
		else if (c == '+')
		{
			res[++len] = tmp % 10000;
			tmp = 0;
			while (st[top] == '*')
			{
				top--;
				len--;
				res[len] = (res[len + 1] * res[len]) % 10000;
			}
			st[++top] = c;
		}
	}
	res[++len] = tmp % 10000;
	while (top)
	{
		if (st[top] == '+')
		{
			len--;
			res[len] = (res[len + 1] + res[len]) % 10000;
		}
		else if (st[top] == '*')
		{
			len--;
			res[len] = (res[len + 1] * res[len]) % 10000;
		}
		top--;
	}
	
	cout << res[1];

	return 0;
}