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
