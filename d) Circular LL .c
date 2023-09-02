//Circular Linked List
#include<stdio.h>
#include<stdlib.h>//for malloc

struct Node{
  int data;
  struct Node *next;
};

//traverse using ptr and print every element
void linkedListTraversel(struct Node* head){
   struct Node *ptr = head;
 
  //print upto ptr become head
  do{
    printf("Element: %d\n", ptr->data);
    ptr = ptr->next; //here ptr used to traversal in linked chain
  }while(ptr != head);
}

//this ptr is differenr , Here p is used to traversal and ptr indicate new node
struct Node * insertAtFirst(struct Node *head, int data){
  struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
  ptr-> data = data; //ptr indicate new node

  struct Node *p = head->next;
  while(p->next !=head){
    p =p->next;
  }
  //At this point p indicate the last node of this circular linked list
  p->next =ptr;
  ptr->next =head;
  head = ptr;
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
  fourth ->next = head;

  printf("Circular Linked List before Insertion\n");
  linkedListTraversel(head);

   printf("Circular Linked List After Insertion\n");
   head =insertAtFirst(head,50);
   head =insertAtFirst(head,54);
   linkedListTraversel(head);




  return 0;
}

/*output:
Element:54
Element:50
Element:7
Element:11
Element:66
Element:77

*/
