#include <bits/stdc++.h>
using namespace std;

const int N = 400;
struct node
{
	int x, a, b, c;
	bool operator<(const node& n) const
	{
		if (a + b + c == n.a + n.b + n.c)
		{
			if (a == n.a) return x < n.x;
			else return a > n.a;
		}
		return a + b + c > n.a + n.b + n.c;
	}
};

int n;
node arr[N];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		arr[i] = { i, a,b,c };
	}

	sort(arr + 1, arr + 1 + n);
	for (int i = 1; i <= 5; i++)
	{
		cout << arr[i].x << " " << arr[i].a + arr[i].b + arr[i].c << '\n';
	}

	return 0;
}