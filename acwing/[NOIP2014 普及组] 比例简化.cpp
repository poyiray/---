#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) { return a ? gcd(b % a, a) : b; }

int res_a, res_b;
double minn = 1e6;
int main()
{
	double a, b;
	int l;
	cin >> a >> b >> l;
	for (int i = 1; i <= l; i++)
	{
		for (int j = 1; j <= l; j++)
		{
			if (gcd(i, j) == 1 && i * 1.0 / j >= a / b && i * 1.0 / j - a / b < minn)
			{
				minn = i * 1.0 / j - a / b;
				res_a = i;
				res_b = j;
			}
		}
	}
	cout << res_a << " " << res_b;

	return 0;
}