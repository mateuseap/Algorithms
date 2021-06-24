#include <stdio.h>
#include <stdlib.h>

void merge(int *v, int l, int m, int r){
    int tam = (r-l)+1, i1 = 0, i2 = (m+1)-l, curr = l;
    int *temp = (int*) malloc(sizeof(int)*tam);
    for(int i = 0, j = l; i <= r-l; i++, j++){
        temp[i] = v[j];
    }
    while(curr <= r){
        if(i1 == (m+1)-l){
            v[curr] = temp[i2++];
        }else if(i2 > r-l){
            v[curr] = temp[i1++];
        }else if(temp[i1] <= temp[i2]){
            v[curr] = temp[i1++];
        }else{
            v[curr] = temp[i2++];
        }
        curr++;
    }
    free(temp);
}

void mergeSort(int *v, int l, int r){
    int m;
    if(l < r){
        m = (l+r)/2;
        mergeSort(v,l,m);
        mergeSort(v,m+1,r);
        merge(v,l,m,r);
    }
}

#define max 100

int main(){
    
    int n, v[max]; //n is the size of the array

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }

    mergeSort(v, 0, n-1);
    
    printf("\n");

    for(int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }

    return 0;
}