#include <iostream>

using namespace std;

int main(){
    int s, X = 0;
    string op;

    cin>>s;

    while(s--){
        cin>>op;

        if(op[0] == 'X'){
            if(op[1] == '+' && op[2] == '+'){
                X++;
            }else if(op[1] == '-' && op[2] == '-'){
                X--;
            }
        }else{
            if(op[0] == '+' && op[1] == '+'){
                X++;
            }else if(op[0] == '-' && op[1] == '-'){
                X--;
            }
        }
    }

    cout<<X;

    return 0;
}