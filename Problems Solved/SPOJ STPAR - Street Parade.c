//Question link: https://www.spoj.com/problems/STPAR/

#include <stdio.h>
#include <stdlib.h>

typedef struct Link{
    int element;
    struct Link *next;
} Link;

typedef struct{
    Link *top;
    int size;
} Stack;

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

Stack *create_stack(){
    Stack *s;
    s = (Stack*) malloc(sizeof(Stack));
    s->top = NULL;
    s->size = 0;
    return s;
}

void push(Stack *s, int it){
    s->top = create_link(it, s->top);
    s->size++;
}

int pop(Stack *s){
    int it;
    Link *n;
    if(s->top == NULL){
        return -1;
    }
    it = s->top->element;
    n = s->top;
    s->top = s->top->next ;
    free(n);
    s->size--;
    return it;
}

int topValue(Stack *s){
    if(s->top == NULL){
        return -1;
    }
    return s->top->element;
}

void clearStack(Stack *s){
    while(s->top != NULL){
        pop(s);
    }
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

int frontValue(Queue *q){
    if(q->size==0){
        return -1;
    }
    return q->front->next->element;
}

void clearQueue(Queue *q){
    q->rear = create_Link(NULL);
    q->front = q->rear;
    q->size = 0;
}

int main(){

    Stack *s = create_stack();
    Queue *q = create_queue();
    int n, proc, temp;
    
    scanf("%d", &n);

    while(n != 0){
        proc = 1;

        for(int i = 0; i < n; i++){
            scanf("%d", &temp);
            enqueue(q, temp);
        }

        while((q->size > 0) || (s->size > 0)){
            if(frontValue(q) == proc){
                dequeue(q);
                proc++;
            }else if(topValue(s) == proc){
                pop(s);
                proc++;
            }else if((q->size == 0) && (topValue(s) != proc)){
                break;
            }else{
                push(s, dequeue(q));
            }
        }

        if((q->size == 0) && (s->size == 0)){
            printf("yes\n");
        }else{
            printf("no\n");
        }

        clearStack(s);
        clearQueue(q);

        scanf("%d", &n);
    }

    return 0;
}