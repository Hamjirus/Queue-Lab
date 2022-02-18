//
//  main.c
//  Queue
//
//  Created by 6272 on 1/3/2562 BE.
//  Copyright © 2562 6272. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "Queue.h"

void menu();
int customer = 0;

int main(int argc, const char * argv[]) {
    int i,ord_num,ord_qty;
    Queue Q;
    Q.head=NULL;
    Q.tail=NULL;
    Q.size=0;
    
    for(i=1;i<argc;i++){
        if(strcmp(argv[i],"x")==0){
          if(Q.size>0){
            dequeue(&Q,&ord_num,&ord_qty);
            menu(ord_num,ord_qty);
          }
          else{
            printf("\nOut of menu\n");
          }
        }
        else {
          int temp_ord = atoi(argv[i]);
          int temp_qty = atoi(argv[i+1]);
          enqueue(&Q, temp_ord,temp_qty);
          i+=1;
        }     
    }
    printf("\n=====================================\n");
    if(Q.size > 1){
      printf("There are %d ppl left in the queue\n",Q.size);
    }
    else if(Q.size == 1){
      printf("There is %d ppl left in the queue\n",Q.size);
    }
    else{
      printf("There is no ppl left in the queue\n");
    }
    return 0;
}

void menu(int ord,int qty){
  int price,money;
  printf("\nMy order is %d\n",ord);
  printf("Customer number : %d\n",++customer);

  if(ord == 1){
    printf("Menu : Hamerger\n");
    printf("Quantity : %d\nPrice : 100 Baht\n",qty);
    price = qty*100;
  }
  else if(ord == 2){
    printf("Menu : Ham Spaghetti\n");
    printf("Quantity : %d\nPrice : 150 Baht\n",qty);
    price = qty*150;
  }
  else if(ord == 3){
    printf("Menu : Ham Pizza\n");
    printf("Quantity : %d\nPrice : 300 Baht\n",qty);
    price = qty*300;
  }
  else if(ord == 3){
    printf("Menu : Easter Ham\n");
    printf("Quantity : %d\nPrice : 500 Baht\n",qty);
    price = qty*500;
  }
  else{
    printf("Menu doesn't exist");
    return;
  }
  
  printf("You have to pay : %d Baht\n",price);
  do{
    printf("Cash : ");
    if(scanf("%d",&money)){}
  }while(money < price);

  if(money > price){
    printf("change : %d Baht\n",money-price);
  }
  else if(money == price){
    printf("No change\n");
  }

  printf("Thank you!!\n");
}