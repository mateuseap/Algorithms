//Question link: https://codeforces.com/problemset/problem/112/A

#include <iostream>
#include <strings.h>
#include <string.h>

using namespace std;

int main(){
    string st1, st2;
    char str1[101], str2[101];

    scanf(" %[^\n]", str1);
    scanf(" %[^\n]", str2);

    if(strcasecmp(str1,str2) == 0){
        printf("0");
    }else{
        for(int i = 0; i < strlen(str1); i++){
            str1[i] = tolower(str1[i]);
            str2[i] = tolower(str2[i]);
        }

        st1 = str1;
        st2 = str2;

        if(st1 < st2){
            printf("-1");
        }else{
            printf("1");
        }
    }

    return 0;
}
