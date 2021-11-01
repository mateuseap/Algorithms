//Question link: https://codeforces.com/contest/1593/problem/D2

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

set<int> divs(int n) {  
    set<int> d;
    for (int dd = 1; dd * dd <= n; dd++)
        if (n % dd == 0) {
            d.insert(n / dd);
            d.insert(dd);
        }
    return d;
}

int main() {
    int t;
    cin >> t;
    forn(tt, t) {
        int n;
        cin >> n;
        vector<int> a(n);
        forn(i, n)
            cin >> a[i];
        int k = -1;

        forn(i, n) {
            int minv = a[i];
            int same = 0;
            vector<int> d;
            forn(j, n) {
                if (a[j] == minv)
                    same++;
                else if (a[j] > minv)
                    d.push_back(a[j] - minv);
            }
            if (same >= n / 2) {
                k = INT_MAX;
                continue;
            }
            map<int,int> div_counts;
            for (int di: d)
                for (int dd: divs(di))
                    div_counts[dd]++;
            for (auto p: div_counts)
                if (p.second >= n / 2 - same)
                    k = max(k, p.first);
        }

        cout << (k == INT_MAX ? -1 : k) << endl;
    }
}