//Question link: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=2733

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void topoSort(vector<vector<int>> &g, vector<int> &degree, int nOfEdges){
    queue<int> q;
    vector<int> tps;
    int u;
    for(int i = 0; i < degree.size(); i++){
        if(degree[i] == 0){
            q.push(i);
        }
    }
    while(q.empty() != true){
        u = q.front();
        tps.push_back(u);
        q.pop();
        for(auto v: g[u]){
            degree[v]--;
            if(degree[v] == 0){
                q.push(v);
            }
        }
    }
    if(tps.size() != nOfEdges){
        printf("IMPOSSIBLE\n");
    }else{
        for(auto i: tps){
            printf("%d\n", (i+1));
        }
    }
}

int main(){

    int n, m, a, b;
    vector<vector<int>> g;
    vector<int> degree;

    scanf("%d %d", &n, &m);

    while((n != 0) || (m != 0)){
        g.resize(n);
        degree.resize(n, 0);
        for(int i = 0; i < m; i++){
            scanf("%d", &a);
            scanf("%d", &b);
            a--;
            b--;
            g[a].push_back(b);
            degree[b]++;
        }

        topoSort(g, degree, n);

        scanf("%d %d", &n, &m);
        g.clear();
        degree.clear();
    }

    return 0;
}