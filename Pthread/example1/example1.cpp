#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

#define NUM_THREADS 5

void* say_hello(void* args)
{
  sleep(1);
  cout << "hello Runnoob" << endl;
  return 0;
}


int main()
{

  pthread_t tids[NUM_THREADS];

  for(int i=0;i<NUM_THREADS;++i)
  {
     cout << "for Num:" << i <<endl;  
     int ret = pthread_create(&tids[i],NULL,say_hello,NULL);
     if(ret != 0)
     {
	cout << "pthread_create error , ret = " << ret << endl;
     }
  }

  pthread_exit(NULL);
}
