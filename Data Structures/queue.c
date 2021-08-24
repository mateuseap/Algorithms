#include <stdio.h>
#include <stdlib.h>

typedef struct Link{
    int element;
    struct Link *next;
} Link;

typedef struct Queue{
    Link *front;
    Link *rear;
    int size;
} Queue;

Link *create_link(int i, Link *nextval){
    Link *n = (Link*) malloc(sizeof(Link));
    n->element = i;
    n->next = nextval;
    return n;
}

Link *create_Link(Link *nextval){
    Link *n = (Link*) malloc(sizeof(Link));
    n->next = nextval;
    return n;
}

Queue *create_queue(){
    Queue *q = (Queue*) malloc(sizeof(Queue));
    q->rear = create_Link(NULL);
    q->front = q->rear;
    q->size = 0;
    return q;
}

void enqueue(Queue *q, int it){
    q->rear->next = create_link(it, NULL);
    q->rear = q->rear->next;
    q->size++;
}

int dequeue(Queue *q){
    if(q->size == 0){
        return -1;
    }
    int it = q->front->next->element;
    q->front->next = q->front->next->next;
    if(q->front->next == NULL){
        q->rear = q->front;
    }
    (q->size)--;
    return it;
}

int length(Queue *q){
    return q->size;
}

int main(){

    return 0;
}