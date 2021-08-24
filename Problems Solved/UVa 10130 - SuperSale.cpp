//Question link: https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1071

#include <iostream>
#include <vector>

using namespace std;

int **F;

int max_val(int a, int b){
    if(a < b){
        return b;
    }else{
        return a;
    }
}

void knapsack(int n, int W, vector<pair<int,int>> wv){
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= W; j++){
            if((i == 0) || (j == 0)){
                F[i][j] = 0;
            }else if(wv[i].first <= j){
                F[i][j] = max_val(F[i-1][j], wv[i].second+F[i-1][j-wv[i].first]);
            }else{
                F[i][j] = F[i-1][j];
            }
        }
    }
}

int main(){

    int t, objects, price, weight, people, res, mw;
    vector<pair<int,int>> pw;

    scanf("%d", &t);

    while(t--){
        scanf("%d", &objects);
        pw.push_back(make_pair(0,0));
        for(int i = 0; i < objects; i++){
            scanf("%d %d", &price, &weight);
            pw.push_back(make_pair(weight,price));
        }
        F = (int**) malloc(sizeof(int*)*(objects+1));
        for(int i = 0; i <= objects; i++){
            F[i] = (int*) malloc(sizeof(int)*31);
        }
        knapsack(objects, 30, pw);
        scanf("%d", &people);
        res = 0;
        for(int i = 0; i < people; i++){
            scanf("%d", &mw);
            res += F[objects][mw];
        }
        printf("%d\n", res);
        pw.clear();
    }

    return 0;
}