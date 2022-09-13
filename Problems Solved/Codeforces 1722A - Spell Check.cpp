//Question link: https://codeforces.com/contest/1722/problem/A

#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
    int cT, sizeOfStr;
    string str, tmr = "Timur";
 
    cin>>cT;
 
    sort(tmr.begin(), tmr.end());
 
    while(cT > 0){
        cin>>sizeOfStr;
        cin>>str;
 
        sort(str.begin(), str.end());
        if(str == tmr) {
            cout<<"YES"<<endl;  
        } else {
            cout<<"NO"<<endl;  
        }
 
        cT--;
    }
 
    return;
}
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    solve();
 
    return 0;
}