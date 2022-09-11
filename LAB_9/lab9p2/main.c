#include <stdio.h>
#include <stdlib.h>


typedef struct lrunode{
    int key;
    int data;
    struct lrunode *next;
}lrunode;

typedef struct lru{
    lrunode *head;
    lrunode *l;
    lrunode *m;
}lru;

void createlru(lru *ptr){
    ptr->head = NULL;
    ptr->l = NULL;
    ptr->m = NULL;
}


lrunode *createNewNode(int key,int data) {lrunode *node = malloc(sizeof(lrunode));

        node->data = data;
        node->key = key;
        node->next = NULL;
    return node;
}



int Unique(int key,int data,lrunode *head,lru *ptr){
    lrunode *temp = head;
    while(temp != NULL) {
        if(temp->key == key) {
            temp->data = data;
            ptr->m = temp;
            return 0;
        }
        temp = temp->next;
    }
    return 1;
}


void traverse(int key,lru *ptr1){
    int found=0;
    lrunode *temp = ptr1->head;
    while(temp != NULL) {
        if(temp->key == key) {
            printf("%d\n", temp->data);
            ptr1->m = temp;
            if(ptr1->l == temp)
                ptr1->l = ptr1->m;
            found = 1;
            break;
        }
        temp = temp->next;
    }
    if(found == 0)
        printf("Not Found\n");
}

void insert(lrunode *pnode,lru *ptr) {
    if(ptr->l == NULL)
        ptr->l = pnode;

    pnode->next = ptr->head;
    ptr->head = pnode;
    ptr->m = pnode;
}

void deletenode(lru *ptr1){
    lrunode *temp = ptr1->head;
    lrunode *templ = ptr1->l;
    while (temp->next->next != NULL)
    temp = temp->next;
    temp->next =NULL;
    ptr1->l = temp;
    free(templ);
}



int main(){
    int n, max;
    int size=0;
    int process,key,data;
    lru lru1;
    createlru(&lru1);

    lrunode *node;

    scanf("%d %d",&n,&max);

    for(int i=0; i<n; i++){
        scanf("%d %d",&process,&key);
        if(process == 1) {
                scanf("%d", &data);
            if(max==0)
                printf("Error\n");
            else {
                if (size < max) {
                    if (Unique(key, data, lru1.head, &lru1)) {
                        node = createNewNode(key, data);
                        insert(node, &lru1);
                        size++;
                    }
                } else {
                    if (size > 1) {
                        deletenode(&lru1);
                        node = createNewNode(key, data);
                        insert(node, &lru1);
                    } else {
                        createlru(&lru1);
                        node = createNewNode(key, data);
                        insert(node, &lru1);
                    }
                }
            }
        }
        else if(process == 2) {
            if(max==0)
                printf("Not Found\n");
            else
                traverse(key,&lru1);
        }

    }



    return 0;
}
