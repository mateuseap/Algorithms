//Question link: https://codeforces.com/problemset/problem/1/A

#include <stdio.h>
#include <math.h>

int main(){

    double n, m, a;
    double flagstones = 0;

    scanf("%lf %lf %lf", &n, &m, &a);

    while(1){
        if(n <= 0){
            break;
        }else{
            flagstones += ceil((m/a));
        }
        n -= a;
    }

    printf("%.0lf", flagstones);

    return 0;
}