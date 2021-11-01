//Question link: https://codeforces.com/contest/1593/problem/G

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1'000'000;

int psumOdd[MAX_N + 1];
int psumEven[MAX_N + 1];

void solve()
{
	string s;
	int q;
	cin >> s >> q;
	int n = s.length();

	psumOdd[0] = psumEven[0] = 0;
	for (int i = 0; i < n; i++)
	{
		psumOdd[i + 1] = psumOdd[i];
		psumEven[i + 1] = psumEven[i];

		if (s[i] == '[' || s[i] == ']')
		{
			if (i & 1)
				psumOdd[i + 1]++;
			else
				psumEven[i + 1]++;
		}
	}

	while (q--)
	{
		int l, r;
		cin >> l >> r;
		l--;
		int odd = psumOdd[r] - psumOdd[l];
		int even = psumEven[r] - psumEven[l];
		cout << abs(odd - even) << '\n';
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}