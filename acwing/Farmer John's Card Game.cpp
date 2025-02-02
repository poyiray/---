#include <bits/stdc++.h>
using namespace std;

const int N = 2010;
struct node
{
	int w, id;
	bool operator<(const node& n) const
	{
		return w < n.w;
	}
};
int n, m;

void solve()
{
	vector<node> a;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int x; cin >> x;
			a.push_back({ x, i });
		}
	}
	sort(a.begin(), a.end());

	for (int i = n; i < a.size(); i++)
	{
		if (a[i % n].id != a[i].id)
		{
			cout << -1 << endl;
			return;
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		cout << a[i].id << " ";
	}
	cout << endl;
}

int main()
{
	int _; cin >> _;
	while (_--) solve();

	return 0;
}