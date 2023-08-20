//insertion in array
//size=used space
//index: position to insert
#include<stdio.h>

void display(int arr[], int n){
  //Traversel
  for(int i=0; i<n; i++){
    printf("%d ",arr[i]);
  }
  printf("\n");
}
//i=size-1=5-1=4. which is 88, push this element 1 space forward & do this for every element
//do this upto given index, it makes the index position empty, then insert the element at index posn
int IndInsertion(int arr[],int size,int element, int capacity, int index){

  if(size>=capacity){
    return -1;//insertion not succesfull if it is greater than capacity
  }else if(index>size){
    printf("insertion not successfull, please give insertion position less than size\n");
  }
  for(int i=size-1; i>=index; i--){
    arr[i+1] = arr[i];
  }
  arr[index]=element;//at last insert the element in index=3 
  return 1;
}
//index= where we want to insert
int main(){
  int arr[100]={7,8,12,27,88};
  int size = 5,element,index; //using 5 space among 100 space
  display(arr,size);
  printf("Enter element which you want  to insert ");
  scanf("%d",&element);
  printf("Enter the position where you want to insert ");
  scanf("%d",&index);
  IndInsertion(arr,size,element,100,index);//insert the element
  size +=1;
  display(arr,size);
  
  return 0;
}

/*output- 7,8,12,27,88
       -7,8,12,45,27,88
*/
