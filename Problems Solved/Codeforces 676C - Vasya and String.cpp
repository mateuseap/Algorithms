//Question link: https://codeforces.com/problemset/problem/676/C

#include <iostream>

using namespace std;

int max(int x, int y){
    if(x > y){
        return x;
    }else{
        return y;
    }
}

int min(int x, int y){
    if(x < y){
        return x;
    }else{
        return y;
    }
}

int twoPointers(string &vasya, int k, bool a){
    int l, r, ans;
    char atual = a? 'a':'b';
    
    l = r = ans = 0;

    while(r < vasya.size()){
        if(vasya[r] == atual){
            r++;
        }
        else{
            if(k > 0){
                r++;
                k--;
            }else{
                l++;
                if(vasya[l-1] != atual){
                    k++;
                }
            }
        }
        ans = max(ans,r-l);
    }
    return ans;
}

bool testa(int m, string &vasya, int k, bool a){
    int l, r, nOutraLetra;
    char atual = a? 'a':'b';
    
    l = nOutraLetra = 0; 
    r = m-1;
    
    for(int i=0; i < min(m, vasya.size()); i++){
        if(vasya[i] != atual)nOutraLetra++;    
    }
    
    if(nOutraLetra <= k){
        return true;
    }
    
    for(int i = 0; i < vasya.size()-m; i++){
        l++, r++;
        if(vasya[l-1] != atual){
            nOutraLetra--;
        }
        if(vasya[r] != atual){
            nOutraLetra++;
        }
        if(nOutraLetra <= k){
            return true;
        }
    }
    return false;
}

int binarySearch(string &vasya, int k, bool a){
    int l, r, m, ans = 0;
    
    l = 0, r = vasya.size();
    
    while(l <= r){
        m = (l + r)/2;
        if(testa(m,vasya,k,a)){
            ans = max(ans,m);
            l = m+1;
        }else{
            r = m-1;
        }
    }
    return ans;
}

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n, k, l, r, ans;
    string vasya;
    
    cin>>n>>k;
    cin>>vasya;
    
    cout<<max(twoPointers(vasya,k,false),twoPointers(vasya,k,true));
    
    return 0;
}
