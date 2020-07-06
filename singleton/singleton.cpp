#include "singleton.h"

singleton *singleton::s_singleton = NULL;
QMutex singleton::mutex_(QMutex::NonRecursive); //在该模式下，一个互斥量只能被锁住一次。

singleton *singleton::getsingleObject()
{
    if(s_singleton == NULL)
    {
        QMutexLocker m_lock(&mutex_);
        if(s_singleton == NULL)
        {
            s_singleton = new singleton();
        }
    }
    return s_singleton;
}

void singleton::DestroysingleObject()
{
    if(s_singleton != NULL)
    {
        QMutexLocker m_lock(&mutex_);
        if(s_singleton != NULL)
        {
            delete s_singleton;
            s_singleton = NULL;
        }
    }
}

singleton::singleton()
{

}
