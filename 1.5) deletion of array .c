//deletion
#include<stdio.h>

void display(int arr[], int n){
  //Traversel
  for(int i=0; i<n; i++){
    printf("%d ",arr[i]);
  }
  printf("\n");
}
//deletion
int IndDeletion(int arr[],int size, int index){
//it starts to arrange after the deleted position. The next position came to one step backword to fill the gap of deleted position 
//I want to count from 1 , 2, 3 duringb position set thastwhy index-1. if want to count from 0 , then write index=0
  for(int i=index-1; i< size-1; i++){
    arr[i] = arr[i+1];
  }
  return 1;
}

int main(){
  int arr[100]={7,8,12,27,88};
  int size = 5,index; 
  display(arr,size);
  printf("Enter the position which you want to delete ");
  scanf("%d",&index);
  IndDeletion(arr,size,index);
  size -=1; //size decrease due to the deletion
  display(arr,size);
  
  return 0;
}

/*output-7,8,12,27,88
position :2
7,12,27,88
*/
