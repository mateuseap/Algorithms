//Question link: https://codeforces.com/problemset/problem/339/A

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string sum;
    vector<int> numbers;

    cin>>sum;

    for(int i = 0; i < sum.size(); i++){    
        if(sum[i]-'0' != -5){
            numbers.push_back(sum[i]-'0');
        }
    }

    sort(numbers.begin(), numbers.end());

    for(int i = 0; i < numbers.size(); i++){
        if(i != numbers.size()-1){
            cout<<numbers[i]<<"+";
        }else{
            cout<<numbers[i];
        }
    }


    return 0;
}
