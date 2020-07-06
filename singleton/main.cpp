#include <iostream>
#include <singleton.h>

using namespace std;

int main()
{
    singleton *m_singleton1 = singleton::getsingleObject();
    printf("%x\n",m_singleton1);
    singleton *m_singleton2 = singleton::getsingleObject();
    printf("%x\n",m_singleton2);

    singleton::DestroysingleObject();
    singleton::DestroysingleObject();
    singleton::DestroysingleObject();

    return 0;
}
