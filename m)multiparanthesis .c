//Stack using Array
#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack* ptr){
    if(ptr->top == -1){
        return 1;
    }else{
        return 0;
    }
}
int isFull(struct stack* ptr){
    if(ptr->top == ptr->size-1)//full size
    {
        return 1;
    }else{
        return 0;
    }
}

void push(struct stack * ptr ,char val){
   if(isFull(ptr)){
      printf("Stack overflow! Cannot push %d to the Stack\n",val);
   }else{
      ptr-> top ++;
      ptr-> arr[ptr->top] =val;
   }
}

char pop(struct stack * ptr ){
   if(isEmpty(ptr)){
      printf("Stack underflow! Cannot pop  to the Stack\n");
      return -1;
   }else{
      char val = ptr->arr[ptr->top];
      ptr->top--;
      return val;
   }
}

int match(char a, char b){
    if(a== '{' && b=='}'){
        return 1;
    }
    if(a== '(' && b==')'){
        return 1;
    }
    if(a== '[' && b==']'){
        return 1;
    }
return 0;
}
int paranthesiscatch(char *exp){
    //createand initialize theb stack
   struct stack* sp;
   sp->size = 100;
   sp->top =-1 ;//-1 means stack is empty
   sp ->arr = (char*) malloc(sp->size* sizeof(char));
   char popped_ch;

   for(int i=0; exp[i]!= '\0';i++){
    if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
        push(sp,exp[i]);
    }else if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
    {
        if(isEmpty(sp)){
            return 0;
        }
        popped_ch = pop(sp);
        if(!match(popped_ch, exp[i])){
             return 0;
        }

    }
   }

   if(isEmpty(sp)){
    return 1;
   }else{
    return 0;
   }
}
int main(){
   char *exp = "{(8*9) -(8/4)}";

    
    if(paranthesiscatch(exp)){
        printf("The parenthesis is balanced");
    }else{
        printf("The parenthesis is not balanced");
    }
    return 0; 

}

//parenthesis is balanced