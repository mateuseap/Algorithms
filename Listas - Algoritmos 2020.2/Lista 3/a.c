//Question link: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=3769

#include <stdio.h>
#include <stdlib.h>

typedef struct bstnode{
    int key;
    int element;
    struct bstnode *left;
    struct bstnode *right;
} BSTNode;

typedef struct{
    BSTNode *root;
    int nodecount;
} BST;

BSTNode *create_bstnode(int k, int e){
    BSTNode *n = (BSTNode*) malloc(sizeof(BSTNode));
    n->key = k;
    n->element = e;
    n->left = n->right = NULL;
    return n;
}

BST *create_bst(){
    BST *bst = (BST*) malloc(sizeof(BST));
    bst->root = NULL;
    bst->nodecount = 0;
    return bst;
}

BSTNode *inserthelp(BSTNode *rt, int k, int e){
    if(rt == NULL){
        return create_bstnode(k, e);
    }
    if(rt->key > k){
        rt->left = inserthelp(rt->left, k, e);
    }else{
        rt->right = inserthelp(rt->right, k, e);
    }
    return rt;
}

void insert(BST *bst, int k, int e){
    bst->root = inserthelp(bst->root, k, e);
    bst->nodecount++;
}

void posorder(BSTNode *rt){
    if(rt != 0){
        posorder(rt->left);
        posorder(rt->right);
        printf("%d\n", rt->key);
    }
}

int main(){

    BST *bst = create_bst();
    int key, node = 0;

    while(scanf("%d", &key) != EOF){
        insert(bst, key, node);
        node++;
    }
    
    posorder(bst->root->left);
    posorder(bst->root->right);
    printf("%d\n", bst->root->key);

    return 0;
}