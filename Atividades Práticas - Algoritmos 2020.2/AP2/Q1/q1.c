#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct link{
    int element;
    struct link *next;
} Link;

typedef struct{
    Link *top;
    int size;
} Stack;

Link *create_link(int it, Link *nextval){
    Link *n;
    n = (Link*) malloc(sizeof(Link));
    n->element = it;
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

int pop(Stack *s, int qtd){
    int it = 0;
    while(qtd--){
        Link *n;
        if(s->top == NULL){
            return -1;
        }
        it += s->top->element;
        n = s->top;
        s->top = s->top->next ;
        free(n);
        s->size--;
    }
    return it;
}

void clear(Stack *s){
    while(s->top != NULL){
        pop(s, 1);
    }
    s->top = NULL;
    s->size = 0;
}

int main(){
    Stack *s = create_stack();
    int casosTeste, number, i = 1;
    char operacao[10];

    scanf("%d", &casosTeste);

    while(casosTeste--){
        scanf(" %s %d", operacao, &number);
        printf("Caso %d:\n", i);
        while(strcmp(operacao, "end") == 1){
            if(strcmp(operacao, "push") == 0){
                push(s, number);
            }else if(strcmp(operacao, "pop") == 0){
                int res;
                res = pop(s, number);
                printf("%d\n", res);
            }
            scanf(" %s %d", operacao, &number);
        }
        i++;
        clear(s);
    }

    return 0;
}