//Dynamic memory allocaton
//allocate memory using malloc
//syntax: ptr = (typecast*)malloc(byte size)
#include<stdio.h>
#include<string.h>

int main()
{
    int* ptr;
    int n, i;

    //het the number of elements in the array
    printf("Enter the number of elements:");
    scanf("%d",&n);
    printf("the entered no of elements are: \n",n);

    //dynamically allocate memory using malloc
    ptr = (int*)malloc(n * sizeof(int));

    //check memory allocation is succesfully or not
    if(ptr == NULL){
      printf("memory not allocated.\n");
      exit(0);
    }
    else {
    printf("Memory is succesfully allocated using malloc.\n");

    //get the elements of the array
    for(i=0; i<n ;++i){
        ptr[i] =i+1; //if ptr[0]= 1, ptr[1]= 2, ptr[2]= 3

    }

    //print the element
    for(i=0; i<n; ++i){
        printf("%d, ",ptr[i] );
    }
  }
return 0;
}
/*output-Enter number of elements: 5
Memory successfully allocated using malloc.
The elements of the array are: 1, 2, 3, 4, 5,
*/

//*********************************************************************** Calloc *****************************************************************************
//Dynamic memory allocaton
//allocate memory using malloc
//syntax: ptr = (typecast*)calloc(n, byte size)
//n= number oof elements= no of blocks
#include<stdio.h>
#include<string.h>

int main()
{
    int* ptr;
    int n, i;

    //het the number of elements in the array
    printf("Enter the number of elements:");
    scanf("%d",&n);
    printf("the entered no of elements are: \n",n);

    //dynamically allocate memory using calloc
    ptr = (int*)calloc(n, sizeof(int));

    //check memory allocation is succesfully or not
    if(ptr == NULL){
      printf("memory not allocated.\n");
      exit(0);
    }
    else {
    printf("Memory is succesfully allocated using calloc.\n");

    //get the elements of the array
    for(i=0; i<n ;++i){
        ptr[i] =i+1; //if ptr[0]= 1, ptr[1]= 2, ptr[2]= 3

    }

    //print the element
    for(i=0; i<n; ++i){
        printf("%d, ",ptr[i] );
    }
  }
return 0;
}

//******************************************************************* free *******************************************************************************
#include<stdio.h>
#include<string.h>

int main()
{
    int* ptr, *ptr1;
    int n, i;

    //het the number of elements in the array
    printf("Enter the number of elements:");
    scanf("%d",&n);
    printf("the entered no of elements are: \n",n);
    

    //dynamically allocate memory using malloc 
    ptr = (int*)malloc(n * sizeof(int));
    //dynamically allocate memory using calloc
    ptr1 = (int*)calloc(n, sizeof(int));

    //check memory allocation is succesfully or not
    if(ptr == NULL || ptr1 ==NULL ){
      printf("memory not allocated.\n");
      exit(0);
    }
    else {
      printf("Memory is succesfully allocated using malloc.\n");

     //free the memory
     free(ptr);
     printf("memory is succesfully freed\n");
     
    printf("Memory is succesfully allocated using malloc.\n");
    free(ptr1);
    printf("Calloc memory freed\n");
  }
return 0;
}
