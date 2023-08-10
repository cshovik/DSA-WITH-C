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
