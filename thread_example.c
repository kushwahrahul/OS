#include <errno.h>
//#include <pthread.h>
//#include <semaphore.h>
#include <signal.h>
//#include "buffer.h"
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
pthread_t thid1,thid2,thid3,thid4,thid5;

/*****************************************************************/
void *dispaly5(void *arg)
{
printf("START thread 5\n");
//sleep(2);
while(1){
printf("Hey I am thread 5\n");
//sleep(2);
}
pthread_exit(NULL);
}

/******************#include <pthread.h>***********************************************/
void *dispaly4(void *arg)
{
printf("START thread 4\n");
//sleep(2);
while(1){
printf("Hey I am thread 4\n");
//sleep(2);
}
pthread_exit(NULL);
}


/*****************************************************************/

void *dispaly3(void *arg){
printf("START thread 3\n");
//sleep(2);
while(1){
printf("Hey I am thread 3\n");
//sleep(2);
}
pthread_exit(NULL);
}



/*****************************************************************/
void *dispaly2(void *arg)
{
printf("START thread 2\n");
//sleep(2);
while(1){
printf("Hey I am thread 2\n");
//sleep(2);
}
pthread_pthread_exitexit(NULL);
}



/*****************************************************************/
void *dispaly1(void *arg)
{
printf("START thread 1\n");
//sleep(2);
while(1){
printf("Hey I am thread 1\n");
//sleep(2);
}
pthread_exit(NULL);
}


/*****************************************************************/

int main(){

int ret;

 ret = pthread_create(&thid5,NULL,dispaly5,NULL);
   if(ret>0) { printf("error in thread creation 5\n");
               exit(4); }   

ret = pthread_create(&thid4,NULL,dispaly4,NULL);
   if(ret>0) { printf("error in thread creation 4\n");
               exit(4); }   

ret = pthread_create(&thid3,NULL,dispaly3,NULL);
   if(ret>0) { printf("error in thread creation 3\n");
               exit(4); }   


ret = pthread_create(&thid2,NULL,dispaly2,NULL);
   if(ret>0) { printf("error in thread creation 2\n");
               exit(4); }   


ret = pthread_create(&thid1,NULL,dispaly1,NULL);
   if(ret>0) { printf("error in thread creation 1\n");
               exit(4); }   


pthread_join(thid1,NULL);
pthread_join(thid2,NULL);
pthread_join(thid3,NULL);
pthread_join(thid4,NULL);
pthread_join(thid5,NULL);
exit(0);


}

