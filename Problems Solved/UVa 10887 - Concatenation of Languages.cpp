//Question link: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1828

#include <iostream>
#include <string>

using namespace std;

#define max 1503*1503

string hashTable[max];

void init(){
    for(int i = 0; i < max; i++){
        hashTable[i] = "#";
    }
}

int hashFunction(string &word){
    int s = word.size(), sum = 0;
    for(int i = 0; i < s; i++){
        sum += word[i]*7919*(i+1);
    }   
    return abs(sum)%max;
}

bool checkIfIsAlready(string &word, int hashAdress){
    if(hashTable[hashAdress] == word){
        return true;
    }
    return false;
}

bool tryToInsert(string &word, int hashAdress){
    if(hashTable[hashAdress] == "#"){
        hashTable[hashAdress] = word;
        return true;
    }else if(checkIfIsAlready(word, hashAdress)){
        return false;
    }else{
        while(1){
            if((hashAdress+1) > max-1){
                hashAdress = 0;
            }else{
                hashAdress += 1;
            }
            if(hashTable[hashAdress] == "#"){
                hashTable[hashAdress] = word;
                return true;
            }else if(checkIfIsAlready(word, hashAdress)){
                return false;
            }
        }
    }
}

int main(){

    int testCases, m, n, k = 1, size, hashAdress;
    string a[1501], b[1501], temp;
    scanf("%d", &testCases);

    while(testCases--){
        size = 0;
        init();
        scanf("%d", &m);
        scanf("%d", &n);
        getchar();

        for(int i = 0; i < m; i++){
            getline(cin, a[i]);
        }
        for(int i = 0; i < n; i++){
            getline(cin, b[i]);
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                temp = a[i]+b[j];
                hashAdress = hashFunction(temp);
                if(tryToInsert(temp, hashAdress)){
                    size++;
                }
            }    
        }
        printf("Case %d: %d\n", k++, size);
        a->clear();
        b->clear();
    }

    return 0;
}