//Question link: https://codeforces.com/contest/1791/problem/A

#include <bits/stdc++.h>

using namespace std;

int main() {
    int testCases;
    char letter, word[] = "codeforces";
    bool isIn;

    cin>>testCases;

    while(testCases--) {
        isIn = false;
        cin>>letter;

        for(int i = 0; i < 10; i++) {
            if (word[i] == letter) {
                isIn = true;
                break;
            }
        }

        if(isIn) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }

    return 0;
}