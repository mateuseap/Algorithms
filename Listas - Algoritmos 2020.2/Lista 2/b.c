//Question link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1998

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
        }else if(temp[i1] >= temp[i2]){
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

#define max 10001

int main(){
    int n;
    int money, temp, i, j, firstBookP, secondBookP;
    
    while(scanf("%d", &n) != EOF){
        int booksCost[max];   
        for(int i = 0; i < n; i++){
            scanf("%d", &booksCost[i]);
        }
        scanf("%d", &money);
        mergeSort(booksCost, 0, n-1);
        i = n-1;
        j = 0;
        while(j < i){
            if((booksCost[j]+booksCost[i]) > money){
                j++;
            }if((booksCost[j]+booksCost[i]) == money){
                firstBookP = booksCost[i];
                secondBookP = booksCost[j];
                j++;
                i--;
            }else if((booksCost[j]+booksCost[i]) < money){
                i--;
            }
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n", firstBookP, secondBookP);
    } 

    return 0;
}