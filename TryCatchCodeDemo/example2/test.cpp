#include <iostream>

using namespace std;
 
class Test
{
public:
	Test(int a=0, int b=0)
	{
		this->a = a;
		this->b = b;
		cout << "构造函数do \n";
	}
	~Test()
	{
		cout << "析构函数do \n";
	}
private:
	int a;
	int b;
};
 
void myDivide()
{
	//Test t1(1, 2), t2(3, 4);
	Test *firstTest = new Test(1,2);
	cout << "myDivide ...要发生异常\n" ;
	delete firstTest;
	throw 1;
}

int main()
{
	try           
	{
		myDivide();
	}
	catch (int a)
	{
		cout << "int类型 异常\n" ;
		cout <<a<<endl;
	}
 
	catch (...)
	{
		cout << " 未知 异常\n" ;
	}
	
 
	cout<<"finish"<<endl;

	return 1;
}
