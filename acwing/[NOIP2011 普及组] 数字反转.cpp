#include <bits/stdc++.h>
using namespace std;

const int N = 20;
char c[N];
int len;

int main()
{
	cin >> c + 1; len = strlen(c + 1);
	while (len > 1 && c[len] == '0') len--;
	if (c[1] == '-') cout << '-';
	for (int i = len; i >= 1; i--)
	{
		if (c[i] == '-') continue;
		cout << c[i];
	}

	return 0;
}