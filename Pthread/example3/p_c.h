/*
 * p_c.h
 *
 *  Created on: 2016年6月28日
 *      Author: ZhangXianYi
 */
 
#ifndef P_C_H_
#define P_C_H_
//============================================================================
// Name        : p_c.cpp
// Author      : ZhangXianYi
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : 模拟生产者/消费者的程序
//============================================================================
//析构函数  和  赋初值   注意一下
#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
 
class SynchronizedStack
{
public:
    char ss[100];
    int index;
    pthread_mutex_t mutex;
 
    SynchronizedStack ();
 
    ~SynchronizedStack ();
    void push(char c);
    char pop();
 
};
 
void * Consumer(void *arg);
 
void * Producer(void *arg);
 
 
#endif /* P_C_H_ */
