//============================================================================
// Name        : p_c.cpp
// Author      : ZhangXianYi
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : 模拟生产者/消费者的程序
//============================================================================
//析构函数  和  赋初值   注意一下
 
#include "p_c.h"
 
using namespace std;
 
SynchronizedStack::SynchronizedStack ()
{
    index = -1;
    for(int i=0;i<100;i++)
    {
	ss[i] = 'a';
    }
        
    pthread_mutex_init(&mutex,NULL);
}
 
SynchronizedStack::~SynchronizedStack ()
{
    pthread_mutex_destroy(&mutex);
}
 
void SynchronizedStack::push(char c)
{
 
    if(index<100)
        ss[++index] = c;
    else
        cout << "ss满了！"<< endl;
 
}
char SynchronizedStack::pop()
{
    char s=')';
 
    if(index>=0)
        s = ss[index--];
    else
        cout << "栈空了!" << endl;
 
    return s;
}
 
void * Consumer(void *arg)
{
    SynchronizedStack  *temp = (SynchronizedStack  *)arg;
    char s;
    for(int i=0;i<30;i++)
    {
        pthread_mutex_lock(&(temp->mutex));
        s = temp->pop();
        if(s!=')')
           cout << "Consumed:" << s << endl;
        pthread_mutex_unlock(&(temp->mutex));
        sleep(1);
    }
}
 
void * Producer(void *arg)
{
    SynchronizedStack  *temp = (SynchronizedStack  *)arg;
 
    for(int i=0;i<26;i++)
    {
        pthread_mutex_lock(&(temp->mutex));
        temp->push((char)(i+65));
        cout << "Produced:" << temp->ss[temp->index] << endl;
        pthread_mutex_unlock(&(temp->mutex));
        sleep(1);
    }
}
 
 
