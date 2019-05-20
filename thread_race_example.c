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


int count1 = 1000;
int count2 = 3000;

static int flag=1;
/*****************************************************************/
void *dispaly2(void *arg)
{
int i=6000000;
printf("START thread 2\n");
//sleep(2);

while(i--){
count1--;
count2++;
//sleep(2);
}


pthread_exit(NULL);
}



/*****************************************************************/
void *dispaly1(void *arg)
{
printf("START thread 1\n");
//sleep(2);
int j=6000000;

while(j--){
count1++;
count2--;
//sleep(2);

}

pthread_exit(NULL);
}


/*****************************************************************/

int main(){

int ret;

 ret = pthread_create(&thid1,NULL,dispaly1,NULL);
   if(ret>0) { perror("error in thread creation 5\n");
               exit(4); }   

ret = pthread_create(&thid2,NULL,dispaly2,NULL);
   if(ret>0) { perror("error in thread creation 4\n");
               exit(4); }   

  


pthread_join(thid1,NULL);
pthread_join(thid2,NULL);

printf("count1=%d\n",count1);
printf("count2=%d\n",count2);

exit(0);


}

