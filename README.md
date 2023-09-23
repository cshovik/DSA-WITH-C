# DSA-WITH-C


<h1>linked list</h1>

![image](https://github.com/cshovik/DSA-WITH-C/assets/113230439/592e0979-a9ea-450c-b4e0-f51e5aff96c2)

<h1>Introduction to Stack </h1>
<h2>Application of Stack</h2>
1) Used in Function Call
<br>
2)Infix to Postfix conversion
<br>
3) Parenthasis matching and more

![image](https://github.com/cshovik/DSA-WITH-C/assets/113230439/d6cbcfec-f059-49ed-a23e-2e36e068353e)

<h1>Stack using Array</h1>
struct stack{ <br>
    int size; <br>
    int top; <br>
    int* arr; <br>
} <br>
int main(){ <br>
  struct stack S; <br>
    S.size = 80; <br>
    S.top = -1; <br>
    S.arr = (int*)malloc(S.size*sizeof(int)); <br>
}

![image](https://github.com/cshovik/DSA-WITH-C/assets/113230439/033a51a5-f21f-4678-a3b8-8cabbd09d8b4)

<h2>Peek (Stack ADT)</h2>
int peek(struct stack *sp, int i){ <br>
    int arrayInd = sp->top -i +1; <br>
    if(arrayInd <0){ <br>
        printf("Not a valid position for stack\n"); <br>
        return -1; <br>
    }else{ <br>
        return sp->arr[arrayInd]; <br>
    } <br>
}

![image](https://github.com/cshovik/DSA-WITH-C/assets/113230439/fd1b187c-1c6e-4d40-8ad6-dcbf3506c3e8)




