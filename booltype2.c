/*
 * _Bool is C99 newly added  keyword,
 * It is defined in stdbool.h
 *
 * #define bool	_Bool
 * #define false 0
 * #define true	1
*/

#include <stdio.h> 
#include <stdbool.h>   // #define bool _Bool ,1:true, 0:falsei   

int main(void){

     //_Bool x0 = -100, x1 = 30, x2 = 0;
     bool  x0 = -100, x1 = 30, x2 = 0, x3 = true, x4 = false;
   
     //printf("x0:%d, x1:%d, x2:%d\n",x0, x1, x2);
     printf("x0:%d, x1:%d, x2:%d, x3:%d, x4:%d\n",x0, x1, x2, x3, x4);


   return 0;
}

//Result: x0:1, x1:1, x2:0, x3:1, x4:0

/*
 * The program was compiled and passed in gcc (GCC) 4.4.7 20120313.
 * $ gcc -o booltype  booltype.c
 *
 */

