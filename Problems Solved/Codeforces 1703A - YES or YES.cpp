//Question link: https://codeforces.com/contest/1703/problem/A

#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
 
    int n;
    char a[10];
 
    cin>>n;
 
    while(n > 0){
        cin>>a; 
        if(strcasecmp(a, "yes") == 0){
            if(n - 1 > 0){
                cout<<"YES\n";
            }else{
                cout<<"YES";
            }
        } else {
            if(n - 1 > 0){
                cout<<"NO\n";
            } else {
                cout<<"NO";
            }
        }
        n--;
    }
 
    return 0;
}