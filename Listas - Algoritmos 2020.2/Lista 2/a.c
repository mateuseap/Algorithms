//Question link: https://codeforces.com/problemset/problem/892/A

#include <stdio.h>
#include <stdlib.h>

long long int HoarePartition(long long int *vet, int l, int r){
    int i = l, j = r+1, p = vet[l];
    long long int temp;
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
    }while(i <j);
    temp = vet[j];
    vet[j] = vet[i];
    vet[i] = temp;
    temp = vet[j];
    vet[j] = vet[l];
    vet[l] = temp;
    return j;
}

long long int quickSort(long long int *vet, int l, int r){
    int s;
    if(l < r){
        s = HoarePartition(vet, l, r); 
        quickSort(vet, l, s-1);
        quickSort(vet, s+1, r);
    }
}

#define max 100000

int main(){

    int n;
    long long int cansVolumes, cansCapacities[max], cansV = 0, cansC;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%lld", &cansVolumes);
        cansV += cansVolumes;
    }

    for(int i = 0; i < n; i++){
        scanf("%lld", &cansCapacities[i]);
    }

    quickSort(cansCapacities, 0, n-1);

    cansC = cansCapacities[0]+cansCapacities[1];

    if(cansC-cansV >= 0){
        printf("YES");
    }else{
        printf("NO");
    }

    return 0;
}