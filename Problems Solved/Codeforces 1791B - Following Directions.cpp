//Question link: https://codeforces.com/contest/1791/problem/B

#include <bits/stdc++.h>

using namespace std;

int main() {
    int testCases, strLength;
    string moves;
    pair<int, int> position;
    bool candyCatched;

    cin>>testCases;

    while(testCases--) {
        position.first = 0;
        position.second = 0;
        candyCatched = false;
        cin>>strLength;
        cin>>moves;

        for(int i = 0; i < strLength; i++) {
            if(moves[i] == 'L') {
                position.first -= 1;
            } else if(moves[i] == 'R') {
                position.first += 1;
            } else if(moves[i] == 'U') {
                position.second += 1;
            } else {
                position.second -= 1;
            }

            if(position.first == 1 && position.second == 1) {
                candyCatched = true;
                break;
            }
        }

        if(candyCatched) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }

    return 0;
}