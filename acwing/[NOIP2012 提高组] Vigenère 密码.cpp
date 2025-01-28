#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
char m[N][N], k[N], c[N];
int lk, lc;

void init()
{
	for (char i = 'a'; i <= 'z'; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			m[i][j + 'a'] = (i + j - 'a') % ('z' - 'a' + 1) + 'a';
		}
	}
}

char search(char x, char y)
{
	for (char i = 'a'; i <= 'z'; i++)
	{
		if (y == m[x][i]) return i;
	}
}

int main()
{
	init();
	cin >> k >> c; lk = strlen(k), lc = strlen(c);

	for (int i = 0; i < lc; i++)
	{
		char x = tolower(c[i]), y = tolower(k[i % lk]);
		char res = search(y, x);
		cout << (char)(isupper(c[i]) ? toupper(res) : res);
	}

	return 0;
}