//Question link: https://codeforces.com/contest/1791/problem/C

#include <bits/stdc++.h>

using namespace std;

int main() {
    int testCases, strLength;
    string str;

    cin>>testCases;

    while(testCases--) {
        cin>>strLength;
        cin>>str;

        while(1) {
            if(strLength >= 2) {
                if(str[0] == '1' && str[str.size()-1] == '0') {
                    str.erase(0, 1);
                    str.erase(str.size()-1, 1);
                    strLength -= 2;
                } else if(str[0] == '0' && str[str.size()-1] == '1') {
                    str.erase(0, 1);
                    str.erase(str.size()-1, 1);
                    strLength -= 2;
                } else {
                    cout<<strLength<<endl;
                    break;
                }
            } else {
                cout<<strLength<<endl;
                break;
            }
        }
    }

    return 0;
}