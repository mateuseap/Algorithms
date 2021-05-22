#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int binarySearch(int vet[], int k, int n){ 
    int l = 0, r = n-1, m;
    while(l<=r){
        m = (l+r)/2;
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

#define max 100000

int main(){
    
    int array[max], tam, nProcurados, n, res;

    scanf("%d", &tam);

    for(int i = 0; i < tam; i++){
        scanf("%d", &array[i]);
    }

    scanf("%d", &nProcurados);

    while(nProcurados--){
        scanf("%d", &n);
        res = binarySearch(array, n, tam);
        if(res == -1){
            printf("x\n");
        }else{
            printf("%d\n", res);
        }
    }

    return 0;
}