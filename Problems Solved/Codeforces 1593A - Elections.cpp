//Question link: https://codeforces.com/contest/1593/problem/A

#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int t;
    long long int a, b, c, tot, pol1, pol2, pol3;
 
    cin>>t;
 
    while(t--){
        cin>>a>>b>>c;
 
        if((a >= b) && (a >= c)){
            tot = a;
        }else if((b >= a) && (b >= c)){
            tot = b;
        }else if((c >= a) && (c >= b)){
            tot = c;
        }
        
        if((a == b) && (b == c)){
            cout<<"1"<<" "<<"1"<<" "<<"1"<<endl;
        }else if(((a > b) && (a > c)) || ((b > a) && (b > c)) || ((c > a) && (c > b))){
            if(tot-a == 0){
                pol1 = 0;
            }else{
                pol1 = (tot-a)+1;
            }
            if(tot-b == 0){
                pol2 = 0;
            }else{
                pol2 = (tot-b)+1;
            }
            if(tot-c == 0){
                pol3 = 0;
            }else{
                pol3 = (tot-c)+1;
            }
            cout<<pol1<<" "<<pol2<<" "<<pol3<<endl;
        }else if(((a == b) && (a > c)) || ((b == c) && (b > a)) || ((c == a) && (c > b))){
            cout<<(tot-a)+1<<" "<<(tot-b)+1<<" "<<(tot-c)+1<<endl;
        }
    }
 
    return 0;
}