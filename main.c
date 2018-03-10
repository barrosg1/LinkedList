//
//  main.c
//  Linked_list_exercises
//
//  Created by Gabriel Barros on 10/4/17.
//  Copyright © 2017 Gabriel Barros. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int item;
    struct Node *next;
} Node;

typedef struct List
{
    Node *head;
    Node *tail;
} List;

List SLL_new()
{
    List list;
    
    list.head = NULL;
    list.tail = NULL;
    
    return list;
}

int SLL_empty(List *list){
    return list->head == NULL;
}

void SLL_insert(List *list, int item)
{
    Node *node = malloc(sizeof(Node));
    
    node->item = item;
    node->next = list->head;
    
    if(SLL_empty(list)){
        list->tail = node;
    }
    
    list->head = node;
    
}

int SLL_pop(List *list)
{
    Node *node = list->head;
    
    int item = node->item;
    list->head = node->next;
    
    
    if(SLL_empty(list)){
        list->tail = NULL;
    }
    
    free(node);
    return item;
}

void SLL_append(List *list, int item)
{
    if(SLL_empty(list))
    {
        SLL_insert(list, item);
    }
    else
    {
        Node *node = malloc(sizeof(Node));
        
        node->item = item;
        node->next = NULL;
        list->tail->next = node;
        list->tail = node;
        
    }
    
}

int SSL_length(struct List *list) {
    /* return the number of items in the list */
    struct Node *p;
    
    int n = 0;
    for (p = list->head; p != NULL; p = p->next) {
        ++n;
    }
    return n;
}


/*
int main(int argc, const char * argv[])
{

    List list = SLL_new();
    
    int num_nodes;
    printf("Input the number of nodes: ");
    scanf("%d", &num_nodes);
    
    for (int i=0; i < num_nodes; i++)
    {
        int c;
        printf("Input data for node %d :", i+1);
        scanf("%d", &c);
        SLL_append(&list, c);
    }
    
    printf("Data entered in the list :\n");
    while(!SLL_empty(&list))
    {
        printf("Data = %d\n", SLL_pop(&list));
    }
    
    
    return 0;
}

*/































