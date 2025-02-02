#include <bits/stdc++.h>
using namespace std;

const int N = 110;
struct node
{
	int x, y, c, d;
};
int a[N][N], n, m, dis[N][N];

int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

int main()
{
	memset(a, -1, sizeof a);
	memset(dis, 0x3f, sizeof dis);
	cin >> n >> m;
	while (m--)
	{
		int x, y, c; cin >> x >> y >> c;
		a[x][y] = c;
	}

	queue<node> q;
	q.push({ 1,1,a[1][1],0 });
	dis[1][1] = 0;
	while (q.size())
	{
		auto[x, y, c, d] = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			int vx = x + dx[i], vy = y + dy[i];
			if (vx <= 0 || vx > n || vy <= 0 || vy > n) continue;
			if (!~a[x][y] && !~a[vx][vy]) continue;

			int w = 0;
			if (c != a[vx][vy]) w = 1;
			if (!~a[vx][vy]) w = 2;

			if (d + w < dis[vx][vy])
			{
				dis[vx][vy] = d + w;
				if(!~a[vx][vy]) q.push({ vx,vy,a[x][y],dis[vx][vy] });
				else q.push({ vx,vy,a[vx][vy],dis[vx][vy] });
			}
		}
	}
	if (dis[n][n] >= 1e7) cout << -1;
	else cout << dis[n][n];

	return 0;
}