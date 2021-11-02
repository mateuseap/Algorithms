#include <iostream>
#include <math.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int temp, i, j, ans, posI, posJ;
    int matriz[5][5];

    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            cin>>matriz[i][j];
            if(matriz[i][j] == 1){
                posI = i+1;
                posJ = j+1;
            }
        }
    }

    ans = abs(3-posI)+abs(3-posJ);
    cout<<ans;

    return 0;
}