//Question link: https://codeforces.com/problemset/problem/158/A

#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k, ans = 0;
    vector<int> scores;

    cin>>n>>k;

    for(int i = 0; i < n; i++){
        cin>>scores[i];
    }
    
    for(int i = n-1; i >= 0; i--){
        if(scores[i] >= scores[k-1] && scores[i] > 0){
            ans++;
        }
    }
    cout<<ans;

    return 0;
}
