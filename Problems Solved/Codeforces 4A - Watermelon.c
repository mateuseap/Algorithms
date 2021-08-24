//Question link: https://codeforces.com/problemset/problem/4/A

#include <stdio.h>
#include <stdbool.h>

int main(){

    int w;
    bool print = false;

    scanf("%d", &w);

    while(w >= 1){
        if((w%2) == 0 && (w > 2)){
            printf("YES");
            print = true;
            break;
        }else{
            w -= 2;
        }
    }

    if(!print){
        printf("NO");
    }

    return 0;
}