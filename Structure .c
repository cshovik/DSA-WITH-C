#include<stdio.h>

//declaration of structure with name str1
struct str1{
    int i;
    char c;
    float f;
    char s[30];//character array
}; //variable dclaration with structure template


//declaration of str2
struct str2{
    int ii;
    char cc;
    float ff;
}var;  // variable declaration with structure template


int main(){


// variable declaration after structure template
    // initialization with initializer list and designated
    //    initializer list
    struct str1  var1= {1,'A',1.00,"Shovik"},
                 var2; //empty
    struct str2  var3= { .ff = 5.00, .ii=5, .cc='a'};


    var2 =var1;

    printf("Struct1: i=%d, c=%c, f=%f, s=%s \n", var1.i, var1.c, var1.f, var1.s);
    printf("Struct2: i=%d, c=%c, f=%f, s=%s \n", var2.i, var2.c, var2.f, var2.s);
    printf("Struct3: ii=%d, cc=%c, ff=%f \n", var3.ii, var3.cc, var3.ff);
    
    return 0;
    } 
