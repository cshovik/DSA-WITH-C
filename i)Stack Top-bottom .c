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

int peek(struct stack *sp, int i){
    int arrayInd = sp->top -i +1;

    if(arrayInd <0){
        printf("Not a valid position for stack\n");
        return -1;
    }else{
        return sp->arr[arrayInd];
    }
}

 //stack Top-bottom
int stackTop(struct stack* sp){
    return sp->arr[sp->top];
}
int stackBottom(struct stack*sp){
    return sp->arr[0];
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
    
   
   printf("The topmost value of stack is %d\n",stackTop(sp));
   printf("The topmost value of stack is %d\n",stackBottom(sp));

    //printing values from the stack
    for(int j=1; j<= sp->top+1; j++){
        printf("The value at Index %d is %d\n", j, peek(sp,j));
    }
    return 0;
}