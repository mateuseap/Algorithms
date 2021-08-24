//Question link: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1927

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define int_max 1e5

void dijkstra(vector<vector<pair<int,int>>> g, int v, int source, int destiny, int index){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int, int>>> minheap;
    vector<int> mark(v), distance(v);

    minheap.push(make_pair(0,source));
    for(int i = 0; i < v; i++){
        distance[i] = int_max;
        mark[i] = 0;
    }
    distance[source] = 0;

    for(int i = 0; i < v; i++){
        pair<int,int> e;
        do{
            if(!minheap.empty()){
                e = minheap.top();
                minheap.pop();
            }else{
                goto end;
            }
        }while(mark[e.second] == 1);
        mark[e.second] = 1;
        for(auto k: g[e.second]){
            if((!mark[k.second]) && (distance[k.second] > (distance[e.second]+k.first))){
                distance[k.second] = distance[e.second]+k.first;
                minheap.push(make_pair(distance[k.second],k.second));
            }
        }
    }
    end:
    if(distance[destiny] != int_max){
        printf("Case #%d: %d\n", index, distance[destiny]);
    }else{
        printf("Case #%d: unreachable\n", index);
    }
    return;
}

int main(){

    vector<vector<pair<int,int>>> g;
    int testCases, vertices, edges, o, d, v1, v2, w, source, i = 1;

    scanf("%d", &testCases);

    while(testCases--){
        scanf("%d %d %d %d", &vertices, &edges, &o, &d);
        source = o;
        g.resize(vertices);
        for(int i = 0; i < edges; i++){
            scanf("%d %d %d", &v1, &v2, &w);
            g[v1].push_back(make_pair(w,v2));
            g[v2].push_back(make_pair(w,v1));
        }
        dijkstra(g, vertices, source, d, i);
        i++;
        g.clear();
    }

    return 0;
}