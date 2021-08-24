//Question link: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=3644

#include <stdio.h>
#include <stdbool.h>

typedef struct{
    int ID;
    int period;
    int periodIn;
} Register;

Register v[1005];

void insertionSort(int l, int r){
    int j;
    Register k, temp;
    for(int i = 0; i <= r; i++){
        k = v[i];
        j = i-1;
        while((j >= 0) && (v[j].period > k.period)){
            temp = v[j+1];
            v[j+1] = v[j];
            v[j] = temp;
            j--;
        }
        v[j+1] = k;
    }
}

int main(){

    Register temp;
    char cmnd[9];
    int l = 0, ID, period, n, k;

    scanf(" %s", cmnd);

    while(cmnd[0] != '#'){
        scanf("%d %d", &ID, &period);
        v[l].ID = ID;
        v[l].period = period;
        v[l].periodIn = period;
        l++;
        scanf(" %s", cmnd);
    }

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        insertionSort(0, l-1);
        k = 1;
        while((k < l) && (v[0].period == v[k].period)){
            if(v[0].ID > v[k].ID){
                temp = v[0];
                v[0] = v[k];
                v[k] = temp;
            }
            k++;
        }
        printf("%d\n", v[0].ID);
        v[0].period += v[0].periodIn;
    }

    return 0;
}