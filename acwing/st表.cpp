#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 10, M = 30;
int f[N][M][2], n, m; // ��i�㿪ʼ����Ϊ2^j������ + ��� �� ��С

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		f[i][0][0] = f[i][0][1] = x;
	}

	//��ʼ��st��
	for (int j = 1; j <= 20; j++) // ö�ٳ���
	{
		for (int i = 1; i + (1 << j) - 1 <= n; i++) // ö��i����ʼλ��
		{
			f[i][j][0] = min(f[i][j - 1][0], f[i + (1 << j - 1)][j - 1][0]);
			f[i][j][1] = max(f[i][j - 1][1], f[i + (1 << j - 1)][j - 1][1]);
		}
	}

	//��ѯ
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