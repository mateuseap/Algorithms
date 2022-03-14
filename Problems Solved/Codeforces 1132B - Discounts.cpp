//Question link: https://codeforces.com/problemset/problem/1132/B

#include <bits/stdc++.h>

using namespace std;

int main(){

	vector<long long int> v;
	long long int tam, k, sum = 0, cupons;

	cin>>tam;
	for(int i = 0; i < tam; i++){
		cin>>k;
		v.push_back(k);
		sum+=k;
	}
	sort(v.begin(),v.end());
	cin>>cupons;
	for(int i = 0; i < cupons; i++){
		cin>>k;
		cout<<sum-v[tam-k]<<endl;
	}

	return 0;
}
