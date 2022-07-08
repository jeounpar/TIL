// https://www.acmicpc.net/problem/2156

#include <iostream>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int a[n + 1];
	a[0] = 0;
	for (int i = 1; i < n + 1; i++)
	{
		int tmp;
		cin >> tmp;
		a[i] = tmp;
	}

	int d[10001][3];
	d[1][0] = 0;
	d[1][1] = a[1];
	d[1][2] = a[1];
	for (int i = 2; i < 10001; i++)
	{
		d[i][0] = max(max(d[i - 1][0], d[i - 1][1]), d[i - 1][2]);
		d[i][1] = a[i] + d[i - 1][0];
		d[i][2] = a[i] + d[i - 1][1];
	}
	cout << max(max(d[n][0], d[n][1]), d[n][2]) << "\n";
	return 0;
}
