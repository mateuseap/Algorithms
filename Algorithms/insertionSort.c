#include <stdio.h>

void insertionSort(int *v, int n){
    int k, j;
    for(int i = 1; i < n; i++){
        k = v[i];
        j = i-1;
        while((j >= 0) && (v[j] > k)){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = k;
    }
}

#define max 100

int main(){

    int n, v[max]; //n is the size of the array

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }

    insertionSort(v,n);

    printf("\n");

    for(int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }

    return 0;
}
