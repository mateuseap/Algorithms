#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct link{
    int element;
    struct link *next;
} Link;

typedef struct{
    Link *head;
    Link *tail;
    Link *curr;
    int cnt;
} List;

Link *create_link(int it, Link *nextval){
    Link *n;
    n = (Link*) malloc(sizeof(Link));
    n->element = it;
    n->next = nextval;
    return n;
}

Link *create_Link(Link *nextval){
    Link *n;
    n = (Link*) malloc(sizeof(Link));
    (*n).next = nextval;
    return n;
}

List *create_list(){
    List *l;
    l = (List*) malloc(sizeof(List));
    l->head = create_Link(NULL);
    l->tail = l->head;
    l->curr = l->tail;
    l->cnt = 0;
    return l;
}

void insert(List *l, int it){
    l->curr->next = create_link(it, l->curr->next);
    if(l->tail == l->curr){
        l->tail = l->curr->next;
    }
    l->cnt++;
}

int getValue(List *l){
    if(l->curr->next == NULL){
        return -1;
    }
    return l->curr->next->element;
}

int remover(List *l){
    Link *temp;
    if(l->curr->next == NULL){
        return -1;
    }
    if(l->tail == l->curr->next){
        l->tail = l->curr;
    }
    temp = l->curr->next;
    l->curr->next = l->curr->next->next;
    free(temp);
    l->cnt--;
    return 0;
}

void prev(List *l){
    if(l->curr == l->head){
        return;
    }
    Link *temp;
    temp = l->head;
    while(temp->next != l->curr){
        temp = temp->next;
    }
    l->curr = temp;
}

void next(List *l){
    if(l->curr != l->tail){
        l->curr = l->curr->next;
    }
}

int lenght(List *l){
    return l->cnt;
}

void moveToStart(List *l){
    l->curr = l->head;
}

void clear(List *l){
    Link *temp;
    int status = 0;

    moveToStart(l);

    while(status != -1){
        status = remover(l);
    }
    if(l->cnt > 0){
        free(l->head);
        l->head = NULL;
    }
    l->cnt = 0;
}

int count(List *l, int it){
    int res = 0;
    Link *k = l->curr;
    moveToStart(l);
    while(getValue(l) != -1){
        if(getValue(l) == it){
            res++;
        }
        next(l);
    }
    l->curr = k;
    return res;
}

#define max 100000

int main(){
    List *l = create_list();
    int qtdDeCasos, qtdOperacoes, number, i = 1;
    char operacao[10];
    bool start = true;

    scanf("%d", &qtdDeCasos);

    while(qtdDeCasos--){
        scanf("%d", &qtdOperacoes);
        while(qtdOperacoes--){
            scanf(" %s", operacao);
            if(start == true){
                printf("Caso %d:\n", i);
                start = false;
            }
            if(strcmp(operacao, "insert") == 0){
                scanf("%d", &number);
                insert(l, number);
            }else if(strcmp(operacao, "next") == 0){
                next(l);
            }else if(strcmp(operacao, "prev") == 0){
                prev(l);
            }else if(strcmp(operacao, "remove") == 0){
                remover(l);
            }else if(strcmp(operacao, "count") == 0){
                int res;
                scanf("%d", &number);
                res = count(l, number);
                printf("%d\n", res);
            }
        }
        i++;
        start = true;
        clear(l);
    }

    return 0;
}