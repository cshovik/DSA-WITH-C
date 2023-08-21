//************************************************************ Insert at beginning ***************************************************************************
//Insertion  at first
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

//insertion at beginning
struct Node *insertAtFirst(struct Node *head, int data){
  struct Node *ptr =(struct Node *) malloc(sizeof(struct Node *));
  ptr ->next = head;
  ptr-> data = data;

  return ptr;

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

  //called the function
  linkedListTraversel(head);
  head = insertAtFirst(head,46);

  //traversal print after insertion
  linkedListTraversel(head);

  return 0;
}

/*output:
Element:7
Element:11
Element:66
Element:77

Element:46
Element:7
Element:11
Element:66
Element:77
*/

//******************************************************************  Insert in between ***********************************************************************
//Insertion  in between
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


//Insertion At Middle
struct Node *inserAtIndex(struct Node *head, int data,int index){
  struct Node *ptr= (struct Node *) malloc(sizeof(struct Node *));
  struct Node *p = head;
  int i=0;
  
  //loop continue 1 step before the index 
  while (i!= index-1){
       p = p ->next;
       i++;
  }
  ptr -> data = data;
  ptr ->next = p-> next;
  p ->next = ptr;
  
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

  //called the function
  linkedListTraversel(head);
  head = inserAtIndex(head,56,3);

  //traversal print after insertion
  linkedListTraversel(head);

  return 0;
}

/*output:
Element:7
Element:11
Element:66
Element:77

Element:7
Element:11
Element:66
Element:56
Element:77
*/

//************************************************************* Insert at End *******************************************************************************
//Insertion  at end
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

//insertion at end
struct Node *insertAtEnd(struct Node *head, int data){

  //new node create with memoryb allocation
  struct Node *ptr =(struct Node *) malloc(sizeof(struct Node *));
  ptr-> data = data;
  struct Node *p = head;
 
 while(p-> next != NULL){
  p = p->next;
 }
 p ->next = ptr;
 ptr ->next = NULL;

  

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

  printf("Linked List before Insertion");
  linkedListTraversel(head);
  head = insertAtEnd(head, 56);

  //traversal print after insertion
  printf("Linked List after Insertion");
  linkedListTraversel(head);

  return 0;
}

/*output:
Element:7
Element:11
Element:66
Element:77

Element:7
Element:11
Element:66
Element:77
Element:56
*/
