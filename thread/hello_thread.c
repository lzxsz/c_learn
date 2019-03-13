#include <pthread.h>
#include <stdio.h>

//thread function
void *ex()
{
    printf("this is a thread\n");
    return (void*)1;
}

void main()
{
    pthread_t   tid;     //thread id
    void        *tret;   //thread return code
    
    pthread_create(&tid,NULL,ex,NULL);  //create a thread
    pthread_join(tid, &tret);//挂起直到tid终止
    printf("thread 1 exit code %d\n", (int)tret);

}

