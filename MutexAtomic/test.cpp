#include <pthread.h>
#include <atomic> 
#include <iostream>
#include <time.h>
#include <mutex>
#include <atomic> 
 
//　参考：https://blog.csdn.net/yockie/article/details/8838686
// g++ test.cpp -o test -lpthread -std=c++11

using namespace std;

typedef struct totalClass
{
  int a=0;
  int b=0;
}totalClass;


/**
// 全局的结果数据 
//long total = 0; 
totalClass total; 
// 点击函数
void *click(void *ptr)
{
    for(int i=0; i<1000000;++i)
    {
        // 对全局数据进行无锁访问 
        total.a += 1;     
	total.b += 1;     
    }
}
**/


/**
//long total = 0;
totalClass total; 
// 对共享资源进行保护的互斥对象
mutex m;

void *click(void *ptr)
{
    for(int i=0; i<1000000;++i)
    {
        // 访问之前，锁定互斥对象
        m.lock();
        total.a += 1;     
	total.b += 1;     
        // 访问完成后，释放互斥对象 
        m.unlock();
    }
}
**/




// 用原子数据类型作为共享资源的数据类型
//atomic_long total(0);
atomic<totalClass> total;
 
void *click(void *ptr)
{
    totalClass temp;

    for(int i=0; i<1000000;++i)
    {
        // 仅仅是数据类型的不同而以，对其的访问形式与普通数据类型的资源并无区别
        //total.a += 1;
	temp.a++;
	temp.b++;
	total.store(temp,memory_order_relaxed);
    }
}

 


int main(int argc, char* argv[])
{
    // 计时开始
    clock_t start = clock();
    // 创建100个线程模拟点击统计
    pthread_t thread_id[100];
    for(int i=0; i<100;++i) 
    {
        pthread_create(&thread_id[i],NULL,click,(void*)NULL);
    }

    for(int i=0; i<100;++i) 
    {
        pthread_join(thread_id[i],NULL);
    }

    
    // 计时结束
    clock_t finish = clock();
    // 输出结果
    //cout<<"result:"<<total.a<<":"<<total.b<<endl;
    cout<<"result:"<<total.load(memory_order_relaxed).a<<":"<<total.load(memory_order_relaxed).b<<endl;
    cout<<"duration:"<<finish -start<<"ms"<<endl;
    return 0;
}
