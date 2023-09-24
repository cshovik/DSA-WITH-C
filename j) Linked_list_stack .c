#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct Node* top = NULL;

void linkedListTraversel(struct Node* ptr){

  //print upto ptr become Null
  while(ptr != NULL){
    printf("Element: %d\n", ptr->data);
    ptr = ptr->next;
  }
}

//top is act as ahead of node
int isEmpty(struct Node*  top){
    if(top == NULL){
        return 1;
    }else{
        return 0; //not neccessary to write else
    }
}

//iterate the p 
int isFull(struct Node*  top){
    struct Node* p= (struct Node*)malloc(sizeof(struct Node));
    if(p == NULL){
        return 1;
    }else{
        return 0; //not neccessary to write else
    }
}

struct Node* push(struct Node* top, int x){
   if(isFull(top)){
    printf("Stack Overflow");
   }else{
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->next = top;
    top = n;
    return top;
   }
};

//give pointer to the top and call the address of top in main 
/*int  pop(struct Node** top ){
    if(isEmpty(*top)){
    printf("Stack underflow");
   }else{
     struct Node* n = *top;
     *top = (*top)->next;
     int x = n->data;
     free(n);

     return x;
   }
}


//or we can make the top global variavle, then we can ignotere using &
int main(){
    struct Node* top = NULL;
    top =push(top, 78);
    top = push(top, 50);
    top = push(top, 34);

    int element = pop(&top);
    printf("popped element is %d\n",element);
    linkedListTraversel(top);
    return 0;
}
*/
//we have to change local variable name top
int  pop(struct Node* tp ){
    if(isEmpty(tp)){
    printf("Stack underflow");
   }else{
     struct Node* n = tp;
     top = tp->next;
     int x = n->data;
     free(n);

     return x;
   }
}


//or we can make the top global variavle, then we can ignotere using &
int main(){
    top =push(top, 78);
    top = push(top, 50);
    top = push(top, 34);

    int element = pop(top);
    printf("popped element is %d\n",element);
    linkedListTraversel(top);
    return 0;
}
// popped element is 34
// Element: 50
// Element: 78
