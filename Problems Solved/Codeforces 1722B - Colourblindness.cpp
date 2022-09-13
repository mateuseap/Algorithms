//Question link: https://codeforces.com/contest/1722/problem/B

#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
    int cT, size;
    string str1, str2;
 
    cin>>cT;
 
    while(cT--){
        cin>>size;
        cin>>str1;
        cin>>str2;
 
        for(int i = 0; i < size; i++) {
            if(str1[i] == 'B') {
                str1[i] = 'G';
            }
            if(str2[i] == 'B') {
                str2[i] = 'G';
            }
        }
 
        if(str1 == str2) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
 
    return;
}
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    solve();
 
    return 0;
}