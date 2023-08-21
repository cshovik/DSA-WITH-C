//structure ponter
#include<stdio.h>
#include<string.h>

struct Student{
    int roll_no;
    char name[30];//char arry , should use strcpy
    char branch[40];
    int batch;
}s1;

int main()
{
    
    struct Student *ptr =&s1;

    s1.roll_no = 27;
    strcpy(s1.name, "Shovik Chakraborty");
    strcpy(s1.branch, "CSE Core");
    s1.batch= 2023;

    printf("Roll number: %d\n", (*ptr).roll_no);
    printf("Name: %s\n", (*ptr).name);
    printf("branch: %s\n", (*ptr).branch);
    printf("batch: %d\n", (*ptr).batch);

    return 0;
}


//***********************************************************************************************************************************************************
//structure ponter
#include<stdio.h>
#include<string.h>

struct Student{
    int roll_no;
    char name[30];//char arry , should use strcpy
    char branch[40];
    char batch[40];
};

struct Student s1, *ptr;

int main()
{
    
   ptr =&s1;

   printf("Enter The Roll no of students\n");
   scanf("%d", &ptr->roll_no);
   printf("Enter the name of student\n");
   scanf("%s", &ptr->name);
   printf("Enter Branch of Student\n");
   scanf("%s", &ptr->branch);
   printf("Enter Batch of Student\n");
   scanf("%s", &ptr->batch);

   printf("Student details \n");

   printf("Roll No: %d\n", ptr->roll_no);
   printf("Name: %s\n", ptr->name);
   printf("Branch: %s\n", ptr->branch);
   printf("Batch: %s\n", ptr->batch);

    return 0;
}
