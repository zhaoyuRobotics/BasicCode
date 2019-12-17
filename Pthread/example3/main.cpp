/*
 * Main.cpp
 *
 *  Created on: 2016年6月28日
 *      Author: administrator
 */
 
#include "p_c.h"
 
int main()
{
    pthread_t pid1,pid2;
    int error1,error2;
    error1 = 0;
    error2 = 0;
    SynchronizedStack * quyu = new SynchronizedStack ();
    error2=pthread_create(&pid2,NULL,Producer,quyu);
    error1=pthread_create(&pid1,NULL,Consumer,quyu);
    if(error1!=0 || error2!=0)
    {
        printf("pthread_cread failed");
        return 0;
    }
    pthread_join(pid1,NULL);
    pthread_join(pid2,NULL);
    return 0;
}
 
 
