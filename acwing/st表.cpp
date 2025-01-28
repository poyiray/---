#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 10, M = 30;
int f[N][M][2], n, m; // 从i点开始长度为2^j的区间 + 最大 和 最小

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		f[i][0][0] = f[i][0][1] = x;
	}

	//初始化st表
	for (int j = 1; j <= 20; j++) // 枚举长度
	{
		for (int i = 1; i + (1 << j) - 1 <= n; i++) // 枚举i的起始位置
		{
			f[i][j][0] = min(f[i][j - 1][0], f[i + (1 << j - 1)][j - 1][0]);
			f[i][j][1] = max(f[i][j - 1][1], f[i + (1 << j - 1)][j - 1][1]);
		}
	}

	//查询
	while (m--)
	{
		int l, r; cin >> l >> r;
		int k = log2(r - l + 1);
		int minn = min(f[l][k][0], f[r - (1 << k) + 1][k][0]);
		int maxn = max(f[l][k][1], f[r - (1 << k) + 1][k][1]);
		cout << maxn - minn << endl;
	}

	return 0;
}