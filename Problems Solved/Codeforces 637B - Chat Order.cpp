//Question link: https://codeforces.com/problemset/problem/637/B

#include <iostream>
#include <cstring>
 
using namespace std;
 
#define tam 200001
 
typedef struct{
    string nome;
    long long int pos;
} Person;

bool comp(Person a, Person b){
    if(a.pos > b.pos){
        return 1;
    }
    return 0;
}

long long int partition(Person vet1[], long long int l, long long int r){
    long long int p, i, j;
    i = l;
    p = vet1[l].pos;
    j = r+1;
    do{
        do{
            i = i+1;
        }while(!((vet1[i].pos >= p) || (i >= r)));
        do{
            j = j-1;
        }while(!(vet1[j].pos <= p));
        swap(vet1[i], vet1[j]);
    }while(!(i >= j));
    swap(vet1[i], vet1[j]);
    swap(vet1[l], vet1[j]);
    return j;
}
 
void quickSort(Person vet1[], long long int l, long long int r){
    long long int s;
    if(l < r){
        s = partition(vet1, l, r);
        quickSort(vet1, l, s-1);
        quickSort(vet1, s+1, r);
    }
}  
 
long long int hashFunc(char x[]){
    int s = strlen(x), vet[] = {6871,5501,5801,5807,5813,5821,5827,5839,5843,5849,5851,5857};
    long long int sum = 0;
    for(int i = 0; i < s-1; i++){
        sum += (x[i]*vet[i])%200000;
    }
    return sum%200000;
}
 
Person chatOrder[tam], aux;
Person respF[tam];
int check[tam];
 
int main(){
 
    int qtd, k = 1, l = 0;
    char nome[11];
    long long int key, maior;
 
    cin>>qtd;
 
    while(qtd--){
        scanf(" %[^\n]", nome);
        key = hashFunc(nome);
        if(key > maior){
            maior = key;
        }
        if(check[key] == 0){
            chatOrder[key].nome = nome;
            chatOrder[key].pos = k;
            check[key] = 1;
            k++;
        }else if((check[key] == 1) && (chatOrder[key].nome == nome)){
            chatOrder[key].pos = k;
            k++;
        }else if((check[key] == 1) && (chatOrder[key].nome != nome)){
            while(1){
                if(key < 200000){
                    key++;
                }else{
                    key = key%200000;
                }
                if(check[key] == 0){
                    chatOrder[key].nome = nome;
                    chatOrder[key].pos = k;
                    check[key] = 1;
                    k++;
                    if(key > maior){
                        maior = key;
                    }
                    break;
                }else if((check[key] == 1) && (chatOrder[key].nome == nome)){
                    chatOrder[key].pos = k;
                    k++;
                    if(key > maior){
                        maior = key;
                    }
                    break;
                }
            }
        }
    }

    for(int i = 0; i < 200001; i++){
        if(chatOrder[i].nome != ""){
            respF[l] = chatOrder[i];
            l++;
        }
    }

    quickSort(respF,0,l-1);

    for(int i = l-1; i >= 0; i--){
        cout<<respF[i].nome<<endl;
    }
 
    return 0;
}