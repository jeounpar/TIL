// https://www.acmicpc.net/problem/9084

#include <iostream>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t-- > 0)
	{
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int cost;
		cin >> cost;

		int d[cost + 1];
		for (int i = 0; i <= cost; i++)
			d[i] = 0;
		d[0] = 1;
		for (int i = 0; i < n; i++)
			for (int j = 1; j <= cost; j++)
				if (j - a[i] >= 0)
					d[j] += d[j - a[i]];
		cout << d[cost] << "\n";
	}
}