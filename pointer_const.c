#include <stdio.h>

//1.指针常量——指针类型的常量（int *const p）
//本质上一个常量，指针用来说明常量的类型，表示该常量是一个指针类型的常量。
//在指针常量中，指针自身的值是一个常量，不可改变，始终指向同一个地址。在定义的同时必须初始化。
//用法如下：
//int a = 10, b = 20;
//int * const p = &a;
//*p = 30; // p指向的地址是一定的，但其内容可以修改
//
//2.常量指针——指向“常量”的指针（const int *p， int const *p）
//常量指针本质上是一个指针，常量表示指针指向的内容，说明该指针指向一个“常量”。
//在常量指针中，指针指向的内容是不可改变的，指针看起来好像指向了一个常量。
//用法如下：
//
//int a = 10, b = 20;
//const int *p = &a;
//p = &b; // 指针可以指向其他地址，但是内容不可以改变
//


int main() {
    int m = 10;
    const int n = 20; // 必须在定义的同时初始化
 
    const int *ptr1 = &m; // 指针指向的内容不可改变
    int * const ptr2 = &m; // 指针不可以指向其他的地方
 
    ptr1 = &n; // 正确
//    ptr2 = &n; // 错误，ptr2不能指向其他地方
 
//    *ptr1 = 3; // 错误，ptr1不能改变指针内容
    *ptr2 = 4; // 正确
 
//    int *ptr3 = &n; // 错误，常量地址不能初始化普通指针吗，常量地址只能赋值给常量指针
    const int * ptr4 = &n; // 正确，常量地址初始化常量指针
 
    int * const ptr5; // 错误，指针常量定义时必须初始化
//   ptr5 = &m; // 错误，指针常量不能在定义后赋值
 
    const int * const ptr6 = &m; // 指向“常量”的指针常量，具有常量指针和指针常量的特点，指针内容不能改变，也不能指向其他地方，定义同时要进行初始化
//    *ptr6 = 5; / 错误，不能改变指针内容
//    ptr6 = &n; // 错误，不能指向其他地方
 
    const int * ptr7; // 正确
    ptr7 = &m; // 正确
 
    int * const ptr8 = &n;   //warning: initialization discards qualifiers from pointer target type
    *ptr8 = 8;
      
     //printf("%d\n", *ptr8);    

     //注意：字符串指针常量
     char * const  str = "apple";    //*str == "a"
     //* str = "orange";  //Error!!
     printf("%s\n", str);    
    
    char *  str2 = "apple";  //Can not use: char * const  str = "apple"; 
    str2 = "orange";         //OK 
    printf("%s\n", str2);    

    return 0;
}

