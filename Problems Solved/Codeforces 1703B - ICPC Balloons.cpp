//Question link: https://codeforces.com/contest/1703/problem/B

#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n, nOfProblems, quantityOfBalloons;
    string problem;
    char temp;
 
    cin>>n;
 
    while(n > 0) {
        cin>>nOfProblems;
        cin>>problem;
 
        quantityOfBalloons = 0;
        temp = '.';
 
        sort(problem.begin(), problem.end());
        for(int i = 0; i < nOfProblems; i++) {
            if(problem[i] == temp) {
                quantityOfBalloons += 1;
            } else {
                quantityOfBalloons += 2;
                temp = problem[i];
            }
        }
 
        cout<<quantityOfBalloons;
        if (n - 1 != 0){
            cout<<"\n";
        }
        n--;
    }
 
    return 0;
}