#include <errno.h>
//#include <pthread.h>
//#include <semaphore.h>
#include <signal.h>
//#include "buffer.h"
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
pthread_t thid1,thid2;

pthread_mutex_t sh;  

struct shrea{
int count1;
int count2;
};
struct shrea a1;  // created the structure of shared memory variable

int global = 10;   // global varibale
//static int flag=1;
/*****************************************************************/
void *dispaly2(void *arg)
{
int i=6000000;
printf("START thread 2\n");

pthread_mutex_lock(&sh);
while(i--){
a1.count1--;
a1.count2++;

}
pthread_mutex_unlock(&sh);


pthread_exit(NULL);
}



/*****************************************************************/
void *dispaly1(void *arg)
{
printf("START thread 1\n");

int j=6000000;
pthread_mutex_lock(&sh);
while(j--){
a1.count1++;
a1.count2--;


}
pthread_mutex_unlock(&sh);

pthread_exit(NULL);
}


/*****************************************************************/


int main(){
/*****************/
// Initializing the shared memory
a1.count1=1000;
a1.count2=2000;
/*************/

//this step of initialization is a must 
       	pthread_mutexattr_init(&ma1);//initialize to default attributes !!




int ret;
printf("address of local variable %p \n",&ret);
 ret = pthread_create(&thid1,NULL,dispaly1,NULL);
   if(ret>0) { perror("error in thread creation 5\n");
               exit(4); }   

ret = pthread_create(&thid2,NULL,dispaly2,NULL);
   if(ret>0) { perror("error in thread creation 4\n");
               exit(4); }   

  printf("display address of thread 1 %p \n",dispaly1);
  printf("display address of thread 2 %p \n",dispaly2);
  printf("display address of MAIN %p \n",main);
  
  printf("display address of global variable --> %p\n",&global);


  int *ptr = malloc(10000);
 printf("display address of dynamic variable --> %p\n",ptr);



pthread_join(thid1,NULL);
pthread_join(thid2,NULL);

printf("count1=%d\n",a1.count1);
printf("count2=%d\n",a1.count2);
while(1);
exit(0);
}
