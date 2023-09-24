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

int peek(int pos){
    struct Node* ptr = top;
    for(int i=0; (i<pos-1 && ptr!=NULL); i++)
    {
        ptr = ptr->next;
    }
    if(ptr != NULL)
    {
        return ptr->data;
    }else
    {
        return -1;

    }

}
//or we can make the top global variavle, then we can ignotere using &
int main(){
    top =push(top, 78);
    top = push(top, 50);
    top = push(top, 34);

    
    linkedListTraversel(top);
    
    for(int i =1; i<4; i++){
        printf("value at position %d is :%d\n",i,peek(i));
    }
    return 0;
}
// Element: 34
// Element: 50
// Element: 78
// value at position 1 is :34
// value at position 2 is :50
// value at position 3 is :78
