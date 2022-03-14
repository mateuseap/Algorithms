//Question link: https://www.spoj.com/problems/BSEARCH1/en/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int binarySearch(int vet[], int k, int tam){
    int l = 0, r = tam-1, m;
    while(l <= r){
        m = ((l+r)/2);
        if(k == vet[m]){
            return m;
        }else if(k < vet[m]){
            r = m-1;
        }else{
            l = m+1;
        }
    }
    return -1;
}

#define tam 1000000000
int vet[tam];

int main(){

    int temp, n, q, res;
    scanf("%d %d", &n, &q);

    for(int i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    }
    
    for(int i = 0; i < q; i++){
        scanf("%d", &temp);
        res = binarySearch(vet, temp, n);
        int oi;
        oi = res;
        while(1){
            if(oi == 0){
                res = 0;
                break;
            }
            oi--;
            if(vet[oi] == temp){
                res = oi;
            }else{
                break;
            }
        }
        printf("%d\n\n", res);
    }

    return 0;
}
