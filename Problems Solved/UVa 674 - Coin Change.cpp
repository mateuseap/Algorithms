//Question link: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=615UVA_10130

#include <iostream>

using namespace std;

int **F, coins[] = {0, 1, 5, 10, 25, 50};

void coinChange(){
    for(int i = 0; i <= 5; i++){
        for(int j = 0; j <= 7489; j++){
            if(((i == 0) || (i == 1) || (i == 2) || (i == 3) || (i == 4) || (i == 5)) && (j == 0)){
                F[i][j] = 1;
            }else if((i == 0) && (j != 0)){
                F[i][j] = 0;
            }else if(coins[i] <= j){
                F[i][j] = F[i][j-coins[i]]+F[i-1][j];
            }else{
                F[i][j] = F[i-1][j];
            }
        }
    }
}

int main(){

    int n;

    F = (int**) malloc(sizeof(int*)*6);
    for(int i = 0; i <= 5; i++){
        F[i] = (int*) malloc(sizeof(int)*7490);
    }

    coinChange();

    while(scanf("%d", &n) != EOF){
        printf("%d\n", F[5][n]);
    }

    return 0;
}
