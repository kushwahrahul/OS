//Attributes provide a way to specify behavior that is different from the default thread creation behavior.

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

/*****************************************************************/
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
pthread_exit(NULL);
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
/*****/
 pthread_attr_t pthread_attr1,pthread_attr4,pthread_attr2,pthread_attr3,pthread_attr5;
/****/
int ret;
struct sched_param param1,param2,param4,param5;

  

/************** Thread Atribute initializtion*/

ret = pthread_attr_init(&pthread_attr4); 
      if(ret>0) { 
              printf("error in the thread 4 attr initialization\n");  
      }

ret = pthread_attr_init(&pthread_attr2); 
      if(ret>0) { 
              printf("error in the thread 2 attr initialization\n");  
      }

ret = pthread_attr_init(&pthread_attr3); 
      if(ret>0) { 
              printf("error in the thread 3 attr initialization\n");  
      }

ret = pthread_attr_init(&pthread_attr1); 
      if(ret>0) { 
              printf("error in the thread  1 attr initialization\n");  
      }

ret = pthread_attr_init(&pthread_attr5); 
      if(ret>0) { 
              printf("error in the thread 5 attr initialization\n");  
      }

/************************************/
void *ptr = NULL;

ptr = malloc(32*1024);

   if(ptr!=NULL){
      printf("setting the stack attributes of a thread\n"); 
    } 
      /*These  attributes
       specify  the location and size of the stack that should be used by a thread
       that is created using the thread attributes object attr.
      */

      ret = pthread_attr_setstack(&pthread_attr1,ptr,32*1024);
      if(ret>0) {
              printf("error in the stack attribute settings\n");
      }

ptr = malloc(32*1024);
      ret = pthread_attr_setstack(&pthread_attr2,ptr,32*1024);
      if(ret>0) {
              printf("error in the stack attribute settings\n");
      }
    
ptr = malloc(32*1024);
      ret = pthread_attr_setstack(&pthread_attr4,ptr,32*1024);
      if(ret>0) {
              printf("error in the stack attribute settings\n");
      }
   
ptr = malloc(32*1024);
      ret = pthread_attr_setstack(&pthread_attr5,ptr,32*1024);
      if(ret>0) {
              printf("error in the stack attribute settings\n");
      }

/************Scheduling of Threads***********/
 //setting the policy to realtime, priority based 
  pthread_attr_setschedpolicy(&pthread_attr1,SCHED_FIFO);
  pthread_attr_setschedpolicy(&pthread_attr2,SCHED_RR);
 // pthread_attr_setschedpolicy(&pthread_attr3,SCHED_FIFO);
  pthread_attr_setschedpolicy(&pthread_attr4,SCHED_FIFO);
  pthread_attr_setschedpolicy(&pthread_attr5,SCHED_RR);

  //realtime priority ( 1-99 is the range) 
   // NOTE : -- JO number chota hai uski priority kam haii !! 
   param1.sched_priority = 1;
   pthread_attr_setschedparam(&pthread_attr1, &param1);

   param2.sched_priority = 10;
   pthread_attr_setschedparam(&pthread_attr2, &param2);
   
   param4.sched_priority = 34;
   pthread_attr_setschedparam(&pthread_attr4, &param4);

   param5.sched_priority = 56;
   pthread_attr_setschedparam(&pthread_attr5, &param5);
  
   /****The inherit-scheduler attribute determines whether a thread created using the thread attributes object attr will  inherit  its  scheduling
       attributes from the calling thread or whether it will take them from attr.
   ****/
   ret = pthread_attr_setinheritsched(&pthread_attr4,PTHREAD_EXPLICIT_SCHED);
 
 if(ret<0){

perror("error in scheduling");
}
   ret = pthread_attr_setinheritsched(&pthread_attr5,PTHREAD_EXPLICIT_SCHED);
 
 if(ret<0){

perror("error in scheduling");
}
ret = pthread_attr_setinheritsched(&pthread_attr2,PTHREAD_EXPLICIT_SCHED);
 
 if(ret<0){

perror("error in scheduling");
}
ret = pthread_attr_setinheritsched(&pthread_attr1,PTHREAD_EXPLICIT_SCHED);
 
 if(ret<0){

perror("error in scheduling");
}

/************************/



/**************Thread Creation*************/
 ret = pthread_create(&thid5,&pthread_attr5,dispaly5,NULL);
   if(ret>0) { printf("error in thread creation 5\n");
               exit(4); }   

ret = pthread_create(&thid4,&pthread_attr4,dispaly4,NULL);
   if(ret>0) { printf("error in thread creation 4\n");
               exit(4); }   

ret = pthread_create(&thid3,&pthread_attr3,dispaly3,NULL);
   if(ret>0) { printf("error in thread creation 3\n");
               exit(4); }   


ret = pthread_create(&thid2,&pthread_attr2,dispaly2,NULL);
   if(ret>0) { printf("error in thread creation 2\n");
               exit(4); }   


ret = pthread_create(&thid1,&pthread_attr1,dispaly1,NULL);
   if(ret>0) { printf("error in thread creation 1\n");
               exit(4); }   

/***********************************************************/


pthread_join(thid1,NULL);
pthread_join(thid2,NULL);
pthread_join(thid3,NULL);
pthread_join(thid4,NULL);
pthread_join(thid5,NULL);
exit(0);


}

