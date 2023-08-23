//******************************************************************* Deletion at beginning *****************************************************************
#include<stdio.h>
#include<stdlib.h>//for malloc

struct Node{
  int data;
  struct Node *next;
};

//traverse using ptr and print every element
void linkedListTraversel(struct Node* ptr){

  //print upto ptr become Null
  while(ptr != NULL){
    printf("Element: %d\n", ptr->data);
    ptr = ptr->next;
  }
}

//Deletion after Node
struct Node *DeleteFirst(struct Node *head){
  struct Node *ptr = head;
  head =head -> next;
  free(ptr);

  return head;
};


int main(){
  struct Node *head;
  struct Node *second;
  struct Node *third;
  struct Node *fourth;



  //allocate memoryb for nodes in the linked list in heap
  head = (struct Node*) malloc(sizeof(struct Node));
  second =(struct Node*) malloc(sizeof(struct Node));
  third =(struct Node*) malloc(sizeof(struct Node));
  fourth=(struct Node*) malloc(sizeof(struct Node));
  
  //link first and second node
  head ->data =7;
  head ->next =second;

  //link second and third node
  second ->data =11;
  second ->next =third;
 
  //Link and third and fourth Node
  third ->data =66;
  third ->next = fourth; 

  //terminate the node
  fourth ->data =77;
  fourth ->next = NULL;

  printf("Linked List before Deletion\n");
  linkedListTraversel(head);

  head = DeleteFirst(head);//for deleting the fiest element
  
  printf("Linked List after Deletion\n");
  linkedListTraversel(head);

  return 0;
}

/*output:
Element:7
Element:11
Element:66
Element:77


Element:11
Element:66
Element:77

*/
//******************************************************************************** Deletion in between ******************************************************
#include<stdio.h>
#include<stdlib.h>//for malloc

struct Node{
  int data;
  struct Node *next;
};

//traverse using ptr and print every element
void linkedListTraversel(struct Node* ptr){

  //print upto ptr become Null
  while(ptr != NULL){
    printf("Element: %d\n", ptr->data);
    ptr = ptr->next;
  }
}

//Deletion in between
struct Node *Deletebetween(struct Node *head, int index){
  struct Node *p = head;
  int i=0;

  //Method 1
  // struct Node *q= head->next;

  //p pint to the index-1 and q point to the index
  // for(int i=0; i<index-1; i++){
  //   p = p->next;
  //   q = q->next;
  // }
  // p->next = q->next;
  // free(q);


//method: 2
  while( i!= index-1){
    p = p->next;
    i++;

  }
  int temp = p->next;
  p->next = p ->next->next;
  free(temp);
  
  return (head);
};


int main(){
  struct Node *head;
  struct Node *second;
  struct Node *third;
  struct Node *fourth;



  //allocate memoryb for nodes in the linked list in heap
  head = (struct Node*) malloc(sizeof(struct Node));
  second =(struct Node*) malloc(sizeof(struct Node));
  third =(struct Node*) malloc(sizeof(struct Node));
  fourth=(struct Node*) malloc(sizeof(struct Node));
  
  //link first and second node
  head ->data =7;
  head ->next =second;

  //link second and third node
  second ->data =11;
  second ->next =third;
 
  //Link and third and fourth Node
  third ->data =66;
  third ->next = fourth; 

  //terminate the node
  fourth ->data =77;
  fourth ->next = NULL;

  printf("Linked List before Deletion\n");
  linkedListTraversel(head);

  head = Deletebetween(head,1);//for deleting the index element
  
  printf("Linked List after Deletion\n");
  linkedListTraversel(head);

  return 0;
}

/*output:
Element:7
Element:11
Element:66
Element:77

Element:7
Element:66
Element:77

*/
