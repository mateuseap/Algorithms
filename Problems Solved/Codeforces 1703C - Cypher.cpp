//Question link: https://codeforces.com/contest/1703/problem/C

#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
 
    int t, vecSize, temp;
    vector<int> digits;
    string operations;
 
    cin>>t;
 
    while(t--){
        cin>>vecSize;
        for(int i = 0; i < vecSize; i++){
            cin>>temp;
            digits.push_back(temp);
        }
        for(int j = 0; j < vecSize; j++){
            cin>>temp>>operations;
            for(int k = 0; k < operations.size(); k++){
                if(operations[k] == 'D'){
                   digits[j] += 1;
                   digits[j] %= 10;
                } else {
                   digits[j] -= 1;
                   digits[j] += 10; 
                   digits[j] %= 10;
                }
            }
        }
        for(int i = 0; i < digits.size(); i++){
            if(i + 1 == digits.size()){
                cout<<digits[i]<<endl;   
            } else {
                cout<<digits[i]<<" ";
            }
        }
        digits.clear();
    }
 
 
    return 0;
}