#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *v, int n){
    int temp, check = 0;
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1; j++){
            if(v[j+1] < v[j]){
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
                check++;
            }
        }
        if((i == 0) && (check == 0)){
            break;
        }
    }
}

#define max 100

int main(){

    int n, v[max]; //n is the size of the array

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }

    bubbleSort(v,n);

    printf("\n");

    for(int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }

    return 0;
}
