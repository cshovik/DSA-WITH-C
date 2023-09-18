#include<stdio.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isFull(struct stack* ptr){
   if(ptr->top == ptr ->size-1){
    return 1;
   }else{
    return 0;
   }
}

int isEmpty(struct stack* ptr){
    if(ptr->top == -1){
        return 1;
    }else{
        return 0;
    }

}

void push(struct stack * ptr ,int val){
   if(isFull(ptr)){
      printf("Stack overflow! Cannot push %d to the Stack\n",val);
   }else{
      ptr-> top ++;
      ptr-> arr[ptr->top] =val;
   }
}

int pop(struct stack * ptr ){
   if(isEmpty(ptr)){
      printf("Stack underflow! Cannot pop  to the Stack\n");
      return -1;
   }else{
      int val = ptr->arr[ptr->top];
      ptr->top--;
      return val;
   }
}


int main(){
    struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
    sp ->size =10;
    sp ->top =-1;
    sp->arr = (int* ) malloc(sp->size * sizeof(int));
    printf("Stack has been created succesfully\n");

    printf("Before Pushing Full %d\n", isFull(sp));
    printf("Before Pushing Empty %d\n", isEmpty(sp));
    
    //push  the value
    for(int i=0; i<12; i++){
    push(sp,i); //cannot push 10 and 11 to the stack because it crossed size , overflow
    }

    printf("After Pushing Full %d\n", isFull(sp));
    printf("After Pushing Empty %d\n", isEmpty(sp));
    
    printf("popped %d from the stack\n",pop(sp)); //lifo- last in fast out , last is 9

    return 0;
}

// Stack has been created succesfully
// Before Pushing Full 0
// Before Pushing Empty 1
// Stack overflow! Cannot push 10 to the Stack
// Stack overflow! Cannot push 11 to the Stack
// After Pushing Full 1
// After Pushing Empty 0
// popped 9 from the stack
