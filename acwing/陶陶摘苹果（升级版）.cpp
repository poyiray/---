#include <bits/stdc++.h>
using namespace std;

const int N = 1e4;
struct node
{
	int x, y;
	bool operator<(const node& n) const
	{
		return y < n.y;
	}
};

int n, s, a, b, res;
node p[N];

int main()
{
	cin >> n >> s >> a >> b;
	for (int i = 1; i <= n; i++) cin >> p[i].x >> p[i].y;

	sort(p + 1, p + 1 + n);
	for (int i = 1; i <= n; i++)
	{
		if (p[i].x > a + b || s < p[i].y) continue;
		res++;
		s -= p[i].y;
	}
	cout << res;

	return 0;
}