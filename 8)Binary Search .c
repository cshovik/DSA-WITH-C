//binary  search
#include<stdio.h>

int binarySearch(int arr[], int size,int element){
  int low, mid, high;
  low =0;
  high = size-1;
 
 //keep searcing until low <= high
  while(low<= high){
      mid = (low + high)/2;
      if (arr[mid]==element){
         return mid;
      }
      else if(arr[mid] < element){
         low = mid+1;
       }
      else{
         high = mid-1;
       }
     }
     //searching ends
     return -1;  //if not find element
  }

int main(){
   int arr[] = {1,3,4,5,23,56,75,245};
   int size = sizeof(arr)/sizeof(int); //to find the no of element
   int element;
   printf("Write the element that you want to search ");
   scanf("%d",&element);
   int searchIndex= binarySearch(arr,size,element);
   if(searchIndex = -1){
    printf("not found");
   }else{
   printf("The element %d found at index %d \n",element,searchIndex);
   }
  return 0;
}

//output: 3 (The element 3 found ar=t index 1)
//        300(not found)
