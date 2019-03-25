#include<stdio.h>

int main()
{
//    char * const str = "apple";
    char * str = "apple";
    str = "orange";  //Error!!!
    cout << str << endl;
    getchar();
}
