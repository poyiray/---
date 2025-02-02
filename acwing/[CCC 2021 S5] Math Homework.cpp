#include <bits/stdc++.h>
using namespace std;
char *p1, *p2, buf[100000];
#define nc() (p1==p2 && (p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
int rd()
{
	int x = 0, f = 1;
	char ch = nc();
	while (ch < 48 || ch>57) ch = nc();
	while (ch >= 48 && ch <= 57)
		x = x * 10 + ch - 48, ch = nc();
	return x;
}
const int N = 2e5, M = 30;
struct node
{
	int l, r, x;
}q[N];
int st[N][M], n, m, dif[M][N];

inline int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

inline int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	n = rd(), m = rd();
	for (int i = 1; i <= m; i++)
	{
		int l = rd(), r = rd(), x = rd();
		q[i] = { l,r,x };
		dif[x][l]++;
		dif[x][r + 1]--;
	}

	for (int i = 1; i <= 16; i++)
		for (int j = 1; j <= n; j++)
			dif[i][j] += dif[i][j - 1];
	
	for (int i = 1; i <= n; i++) st[i][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 16; j++)
			if (dif[j][i]) st[i][0] = lcm(st[i][0], j);
	
	for (int j = 1; j <= log2(n); j++)
	{
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
		{
			//是(1 << j - 1) ....看错了调了半天
			st[i][j] = gcd(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		auto[l, r, x] = q[i];
		
		int k = log2(r - l + 1);
		if (gcd(st[l][k], st[r - (1 << k) + 1][k]) != x)
		{
			cout << "Impossible";
			return 0;
		}
	}

	for (int i = 1; i <= n; i++) cout << st[i][0] << " ";

	return 0;
}