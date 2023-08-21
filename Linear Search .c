//linear search
#include<stdio.h>

int linearSearch(int arr[], int size, int element){
  for(int i=0; i<size; i++){
    if(arr[i]== element){
      return i;
    }

  }
  return -1; //if not found
}

int main(){
   int arr[] = {1,3,5,56,4,3,23,4,245,54,75};
   int size = sizeof(arr)/sizeof(int); //to find the no of element
   int element;
   printf("Wrrite the element that you want to search ");
   scanf("%d",&element);
   int searchIndex= linearSearch(arr,size,element);
   printf("The element %d found at index %d \n",element,searchIndex);

  return 0;
}
//output: the element 5 found at index 2
