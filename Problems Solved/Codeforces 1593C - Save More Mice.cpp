//Question link: https://codeforces.com/contest/1593/problem/C

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, k;
		cin >> n >> k;

		vector<int> x(k);
		for (int i = 0; i < k; i++) cin >> x[i];
		sort(x.rbegin(), x.rend());

		int cnt = 0;
		long long sum = 0;

		while (cnt < x.size() && sum + n - x[cnt] < n)
		{
			sum += n - x[cnt++];
		}

		cout << cnt << '\n';
	}

	return 0;
}