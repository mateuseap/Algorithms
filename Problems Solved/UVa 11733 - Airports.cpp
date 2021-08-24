//Question link: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=2833

#include <iostream>
#include <vector>

using namespace std;

typedef struct{
    int v1, w, v2; //Vertice 1 -- weight -- Vertice 2
} Edge;

int f(vector<int> &v, int curr){ //Find
    if(v[curr] == curr){
        return v[curr];
    }
    return v[curr] = f(v, v[curr]);
}

bool u(vector<int> &v, int a, int b){ //Union
    int root1 = f(v, a), root2 = f(v, b);
    if(root1 == root2){
        return false;
    }
    v[root2] = root1;
    return true;
}

int HoarePartition(Edge *vet, int l, int r){
    Edge p = vet[l], temp;
    int i = l, j = r+1;
    do{ 
        do{
            i = i+1;
        }while((vet[i].w < p.w) && (i < r));
        do{
            j = j-1;
        }while(vet[j].w > p.w);
        swap(vet[i],vet[j]);
    }while(i < j);
    swap(vet[i],vet[j]);
    swap(vet[j],vet[l]);
    return j;
}

void quickSort(Edge *vet, int l, int r){
    int s;
    if(l < r){
        s = HoarePartition(vet, l, r); 
        quickSort(vet, l, s-1);
        quickSort(vet, s+1, r);
    }
}

int main(){

    int testCases, vertices, edges, airportCost, airports, totalCost, c = 1;
    vector<int> v;
    Edge *e;

    scanf("%d", &testCases);

    while(testCases--){
        scanf("%d %d %d", &vertices, &edges, &airportCost);

        e = (Edge*) malloc(sizeof(Edge)*edges);
        v.resize(vertices+1, -1);
        airports = totalCost = 0;

        for(int i = 0; i < edges; i++){
            scanf("%d %d %d", &e[i].v1, &e[i].v2, &e[i].w);
        }
        for(int i = 1; i <= vertices; i++){
            v[i] = i;
        }
        quickSort(e, 0, edges-1);
        for(int i = 0; i < edges; i++){
            if(u(v, e[i].v1, e[i].v2)){
                if(airportCost > e[i].w){
                    totalCost += e[i].w;
                }else{
                    airports++;
                    totalCost += airportCost;
                }
            }
        }
        for(int i = 1; i <= vertices; i++){
            if(v[i] == i){
                airports++;
                totalCost += airportCost;
            }
        }
        
        printf("Case #%d: %d %d\n", c, totalCost, airports);
        v.clear();
        c++;
    }

    return 0;
}