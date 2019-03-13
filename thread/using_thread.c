/*****************************
* this file name is mypthread.c
*compile:gcc -o p.out -lpthread mypthread.c
*
* *run:./p.out
* *
* *****************************/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
 
void *thr_fn1(void *arg)
{
        printf("thr_fn1*****thread 1 returning\n");
        return (void *)1;
}
 
void *thr_fn2(void *arg)
{
        printf("thr_fn2*****thread 2 exiting\n");
        pthread_exit((void *)2);//终止当前进程
}
 
void *thr_fn3(void *arg)
{
        while(1) {
                printf("thr_fn3*****thread 3 writing\n");
                sleep(1);
        }
}
 
void thr_fn4(void*arg)
{
       printf("thr_fn4*****thread 4 write\n");
}
int main(void)
{
        pthread_t   tid,tid2,tid3,tid4;
        void        *tret;
 
        
        pthread_create(&tid, NULL, thr_fn1, NULL);//创建线程id，属性，句柄函数地址，各类参数
        pthread_join(tid, &tret);//挂起直到tid终止
        printf("thread 1 exit code %d\n", (int)tret);
 
        pthread_create(&tid, NULL, thr_fn2, NULL);
        pthread_join(tid, &tret);
        printf("thread 2 exit code %d\n", (int)tret);
 
        pthread_create(&tid, NULL, thr_fn3, NULL);
        sleep(3);
        pthread_cancel(tid);//发送终止信号给tid
        pthread_join(tid, &tret);
        printf("thread 3 exit code %d\n", (int)tret);
       
 
        printf("++++++++++++++++++++++++++++++\n");
       
        pthread_create(&tid, NULL, thr_fn1, NULL);//创建线程id，属性，句柄函数地址，各类参数
        pthread_join(tid, &tret);//挂起直到tid终止
        printf("thread 1 exit code %d\n", (int)tret);
 
        pthread_create(&tid2, NULL, thr_fn2, NULL);
 
 
        pthread_create(&tid3, NULL, thr_fn3, NULL);
        sleep(2);
 
 
        pthread_create(&tid4, NULL, thr_fn4, NULL);
        
        printf("before sleep(2)second\n");
        sleep(2);
        printf("after sleep(2) second\n");    
 
        pthread_join(tid2, &tret);//挂起直到tid终止
        printf("thread 2 exit code %d\n", (int)tret);
        
        printf("before sleep(4)\n");
        sleep(4);
        printf("after sleep(4)\n");
 
        pthread_cancel(tid4);//发送终止信号给tid
        pthread_join(tid4, &tret);
        printf("thread 4 exit code %d\n", (int)tret);
  
        pthread_cancel(tid3);//发送终止信号给tid
        pthread_join(tid3, &tret);
        printf("thread 3 exit code %d\n", (int)tret);
        return 0;
}

