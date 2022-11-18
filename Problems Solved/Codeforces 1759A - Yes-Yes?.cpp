//https://codeforces.com/problemset/problem/1759/A

#include <bits/stdc++.h>

using namespace std;

string value = "YesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYes";

bool isSubstring(string str) {
    int M = str.length();
    int N = value.length();
 
    for(int i = 0; i <= N - M; i++) {
        int j;
        for(j = 0; j < M; j++) {
            if(value[i + j] != str[j]) {
                break;
            }
        }
        if(j == M) {
            return true;
        }
    }
    return false;
}

int main() {
    int T;
    string str;

    cin>>T;

    while(T--) {
        cin>>str;
        if(isSubstring(str)) {
            if(T-1 == -1) {
                cout<<"YES";
            } else {
                cout<<"YES"<<endl;
            }
        } else {
            if(T-1 == -1) {
                cout<<"NO";
            } else {
                cout<<"NO"<<endl;
            }
        }
    }

    return 0;
}
