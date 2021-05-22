#include <stdio.h>
#include <string.h>
#include <math.h>

int HoarePartition(int vet[], int l, int r){
    int i = l, j = r+1, p = vet[l], temp;
    do{ 
        do{
            i = i+1;
        }while((vet[i] > p) && (i < r));
        do{
            j = j-1;
        }while(vet[j] < p);
        temp = vet[j];
        vet[j] = vet[i];
        vet[i] = temp;
    }while(i < j);
    temp = vet[j];
    vet[j] = vet[i];
    vet[i] = temp;
    temp = vet[j];
    vet[j] = vet[l];
    vet[l] = temp;
    return j;
}

int quickSort(int vet[], int l, int r){
    int s;
    if(l < r){
        s = HoarePartition(vet, l, r); 
        quickSort(vet, l, s-1);
        quickSort(vet, s+1, r);
    }
}

#define max 100000

int main(){
    
    int casosTestes, tam;

    scanf("%d", &casosTestes);

    while(casosTestes--){
        scanf("%d", &tam);
        int array[max] = {};

        for(int i = 0; i < tam; i++){
            scanf("%d", &array[i]);
        }

        quickSort(array, 0, tam);

        for(int i = 0; i < tam; i++){
            printf("%d ", array[i]);
        }
        printf("\n");
    }

    return 0;
}