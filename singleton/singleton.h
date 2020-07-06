#ifndef SINGLETON_H
#define SINGLETON_H

#include <QMutex>
#include <QMutexLocker>

class singleton
{
public:
    static singleton *getsingleObject();
    static void DestroysingleObject();

private:
    explicit singleton();

    static singleton *s_singleton;
    static QMutex mutex_;
};

#endif // SINGLETON_H
