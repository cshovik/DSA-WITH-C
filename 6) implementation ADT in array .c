//implementation of array adt
#include<stdio.h>
#include<stdlib.h>

//my array is abstruct data type which contal total sizw..
struct myArray
{
   int total_size;
   int used_size;
   int *ptr;
};

//total size, use size allocate
void createArray(struct myArray* a, int tSize, int uSize){
  // (*a).total_size = tSize;
  // (*a).used_size = uSize;
  // (*a).ptr = (int *) malloc(tSize*sizeof(int));

  a->total_size = tSize;
  a->used_size = uSize;
  a->ptr = (int *) malloc(tSize*sizeof(int));
}
//ptr used to allocate dynamic memory .
//we reserved by malloc.which request to heap to give extra
//meory. like we use 2 space out of 10. if we need more ,we 
// request to haep by malloc
void show(struct myArray *a){
  for(int i=0; i< a->used_size;i++){
    printf("%d\n",(a->ptr)[i]);
  }
}

void setVal(struct myArray *a){
  for(int i=0; i< a->used_size;i++){
    int n;
    printf("Enter element %d \n",i);
    scanf("%d",&n);
    (a->ptr)[i]=n;
  }
}
//total size: 10 used size: 2
int main(){
  struct myArray marks;
  createArray(&marks, 10, 2);
  printf("We are running setVAl now\n");
  setVal(&marks);

  printf("We are runnng show now\n");
  show(&marks);

  return 0;
}
//The will not dellocate automatically like list , we have to use free() for deallocation
