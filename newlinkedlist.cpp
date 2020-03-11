#include <bits/stdc++.h>

using namespace std;

typedef struct{
    int data;
    struct node *next;
} Node; //Estrutara básica dos elementos da lista

void inserir(Node *n, int data){
    Node *n1 = new Node();
    n1->data = data;
    n1->next = NULL;
    while(n->next != NULL){
        n = n->next;
    }
    n->next = n1;
} //Função utilizada para inserir um elemento no final da minha lista

Node *buscar(Node *n, int pos){
    int i = 0;
    while(n->next != NULL || i < pos){
        n = n->next;
        i++;
    }
    return n;
} //Buscar feita para acessar um elemento em determinada posição da lista

void display(Node *n){
    n = n->next;
    while(n != NULL){
        cout<<n->data<<" ";
        n = n->next;
    }
}

int main(){

    Node* sentinela = new Node();
    sentinela->data = -1;
    sentinela->next = NULL;
    
    inserir(sentinela, 1);
    inserir(sentinela, 2);
    inserir(sentinela, 3);

    display(sentinela);

    return 0;
}