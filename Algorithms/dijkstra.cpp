#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define int_max 1000

void dijkstra(vector<vector<pair<int,int>>> g, int v, int source){
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
                return;
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
    for(int i = 0; i < v; i++){
        printf("Distance: %d\n", distance[i]);
    }
}

int main(){

    vector<vector<pair<int,int>>> g(5); //Grafo

    g[0].push_back(make_pair(10,1));  // 0 -- 10 -- 1
    g[0].push_back(make_pair(3,2));   // 0 -- 03 -- 2 
    g[0].push_back(make_pair(20,3));  // 0 -- 20 -- 3
    g[1].push_back(make_pair(5,3));   // 1 -- 05 -- 3
    g[2].push_back(make_pair(2,1));   // 2 -- 02 -- 1
    g[2].push_back(make_pair(15,4));  // 2 -- 15 -- 4
    g[3].push_back(make_pair(11,4));  // 3 -- 11 -- 4

    dijkstra(g, 5, 0); //Passamos para a função o grafo, a quantidade de vértices e a origem a qual iremos utilizar para iniciar a exececução do algoritmo de menor caminho de Dijkstra.

    return 0;
}