//
//  Queue.h
//  Queue
//
//  Created by 6272 on 1/3/2562 BE.
//  Copyright © 2562 6272. All rights reserved.
//

#ifndef Queue_h
#define Queue_h
#include <stdlib.h>
typedef struct node{
    struct node* next;
    int order_number;
    int qty;
}order;

typedef struct {
    order *head,*tail;
    int size;
}Queue;


void enqueue(Queue *q,int ord,int qty){
    order* new_node=(order*)malloc(sizeof(order));
    if(new_node){
        new_node->next=NULL;
        new_node->order_number=ord;
        new_node->qty=qty;
        if(q->head)/*q->size>0*/
            q->tail->next=new_node;
        else
            q->head=new_node;
        q->tail=new_node;
        q->size++;
    }
}

void dequeue(Queue *q, int* ord_num, int * ord_qty){
    if(q->size==0) {
        printf("No queue");
    }
    
    order *t =q->head;
    int x=t->order_number;
    q->head=q->head->next;
    if(!q->head) q->tail=NULL;
    q->size--;
    *ord_num = t->order_number;
    *ord_qty = t->qty;
    free(t);    
}
#endif /* Queue_h */