#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int data;
    struct node *next;
} Node; //Estrutara básica dos elementos da lista

void insert(Node *n, int data){
    Node *curr = n;
    Node *n1 = (Node*) malloc(sizeof(Node));
    n1->data = data;
    n1->next = NULL;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = n1;
} //Função utilizada para inserir um elemento no final da minha lista

Node *find(Node *n, int pos){
    Node *curr = n;
    int i = 0;
    while((curr->next != NULL) && (i < pos)){
        curr = curr->next;
        i++;
    }
    return curr;
} //Buscar feita para acessar um elemento em determinada posição da lista

void display(Node *n){
    n = n->next;
    while(n != NULL){
        printf("%d ", n->data);
        n = n->next;
    }
} //Função utilizada para mostrar o último elemento da lista

int main(){

    Node *sentinela = (Node*) malloc(sizeof(Node));
    sentinela->data = -1;
    sentinela->next = NULL;
    
    insert(sentinela, 1);
    insert(sentinela, 2);
    insert(sentinela, 3);

    display(sentinela);

    return 0;
}