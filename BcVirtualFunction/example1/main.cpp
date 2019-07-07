#include <QCoreApplication>
#include <iostream>

using namespace std;




class TestA
{
public:
    TestA(){}
    virtual ~TestA(){}
    virtual void print();

};

void TestA::print()
{
    cout << " TestA  virtual function" <<endl;
}

//------------------------------------------------






class TestB:public TestA
{
public:
    TestB(){}
    ~TestB(){}
    virtual void print();
};

void TestB::print()
{
    cout <<" TestB virtual function "<<endl;
}


//------------------------------------------------



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TestA *A_object = new TestB();
    A_object->print();            // 在这里，A_object虽然是指向TestA的指针，但是被调用的函数print却是TestB的!

    delete  A_object;

    return a.exec();
}
