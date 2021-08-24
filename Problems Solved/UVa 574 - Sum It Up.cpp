//Question link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=515

#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> v, p;
set<vector<int>> ans;
bool none = true;
int tam, d;

void subsetSum(int s, int i){
    if(s > d){
        return;
    }else if((s < d) && (i == tam)){
        return;
    }else if(s == d){
        none = false;
        ans.insert(p);
        return;
    }

    p.push_back(v[i]);
    s += v[i];
    subsetSum(s, i+1);

    p.pop_back();
    s -= v[i];
    subsetSum(s, i+1);
}

int main(){

    int temp;

    scanf("%d %d", &d, &tam);

    while((d != 0) && (tam != 0)){
        for(int i = 0; i < tam; i++){
            scanf("%d", &temp);
            v.push_back(temp);
        }
        printf("Sums of %d:\n", d);
        subsetSum(0,0);
        if(none){
            printf("NONE\n");
        }else{
            none = true;
            set<vector<int>>::iterator init = ans.begin();
            set<vector<int>>::iterator end = ans.end();
            for(set<vector<int>>::iterator i = prev(end,1); i != ans.begin(); i--){
                for(int j = 0; j < (*i).size(); j++){
                    if(j == ((*i).size()-1)){
                        printf("%d", (*i)[j]);
                    }else{
                        printf("%d+", (*i)[j]);
                    }
                }
                printf("\n");
            }
            for(int j = 0; j < (*init).size(); j++){
                if(j == ((*init).size()-1)){
                    printf("%d", (*init)[j]);
                }else{
                    printf("%d+", (*init)[j]);
                }
            }
            printf("\n");
        }
        v.clear();
        ans.clear();
        scanf("%d %d", &d, &tam);
    }

    return 0;
}