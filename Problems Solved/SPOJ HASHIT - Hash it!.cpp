//Question link: https://www.spoj.com/problems/HASHIT/en/

#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>

using namespace std;

int hashFunc(char x[], int m){
    int s, sum = 0;
    s = strlen(x);
    for(int i = 0; i < s; i++){
        sum = sum+(x[i]*(i+1));
    }
    sum*=19;
    return sum%101;
}

typedef struct{
    string nome;
} armazen;

#define max 2000

int main(){

    int testC, entr, m, save, flag, k = 0, tot = 0, reposition;
    char action[max], name[max];
    int resp[1005];

    cin>>testC;

    while(testC--){
        cin>>entr;
        tot = 0;
        k = 0;
        armazen dale[1];
        armazen dic[1001];
        memset(resp, 0, sizeof(resp));
        while(entr--){
            scanf(" %[^:]:%[^\n]", action, name);
            m = strlen(name);
            save = hashFunc(name, m);
            flag = 0;
            dale[0].nome = name;
            for(int i = 101; i >= 0; i--){
                if(dale[0].nome == dic[i].nome){
                    flag = 1;
                    break;
                }
            }
            if((strcasecmp(action, "ADD") == 0) && (flag == 0)){
                if(resp[save] == 0){
                    resp[save] = 1;
                    dic[save].nome = name;
                    tot++;
                }else{
                    for(int j = 1; j <= 19; j++){
                        reposition = ((save)+(j*j)+(23*j))%101;
                        if(resp[reposition] == 0){
                            resp[reposition] = 1;
                            dic[reposition].nome = name;
                            tot++;
                            break;
                        }
                    }
                }
            }else{
                if((strcasecmp(action, "DEL") == 0) && (flag == 1)){
                    for(int j = 0; j < 101; j++){
                        if(dale[0].nome == dic[j].nome){
                            resp[j] = 0;
                            dic[j].nome = "";
                            tot--;
                            break;
                        }
                    }
                }
            }
        }
        printf("%d\n", tot);
        for(int i = 0; i < 1001; i++){
            if(resp[i] == 1){
                printf("%d:", i);
                cout<<dic[i].nome<<endl;
            }
        }
    }

    return 0;   
}
