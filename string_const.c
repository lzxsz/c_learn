#include<stdio.h>

int main()
{
    char * const str = "apple";
    //str = "orange";  //Error!!!
    printf(str);
}
