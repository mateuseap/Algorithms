//Question link: https://www.urionlinejudge.com.br/judge/en/problems/view/1110

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

    Queue *q = create_queue();
    int n, j, vet[51], temp, qSize;

    scanf("%d", &n);

    while(n != 0){
        j = 0;
        for(int i = 1; i <= n; i++){
            enqueue(q, i);
        }

        while(1){
            qSize = length(q);
            if(qSize == 1){
                break;
            }
            vet[j] = dequeue(q);
            temp = dequeue(q);
            enqueue(q, temp);
            j++; 
        }
        
        printf("Discarded cards:");
        for(int i = 0; i < n-1; i++){
            if(n == 1){
                break;
            }else if(n == 2){
                printf(" %d", vet[i]);
                break;
            }else{
                if(i == 0){
                    printf(" %d, ", vet[i]);
                }else if(i == n-2){
                    printf("%d", vet[i]);
                }else{
                    printf("%d, ", vet[i]);
                }
            }
        }

        printf("\nRemaining card:");
        if(qSize == 1){
            printf(" %d\n", dequeue(q));
        }else{
            printf("\n");
        }
        scanf("%d", &n);
    }

    return 0;
}