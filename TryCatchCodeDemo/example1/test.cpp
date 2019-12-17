#include <iostream>

using namespace std;

int divide(double x, int y )           // 抛异常
{
	if (y ==0)
	{
		throw x;
	}
	return x/y;
}
 
int main()
{
	try               //接异常
	{
		cout << "8/2 = " << divide(8, 2) << endl;
		cout << "10/0 =" << divide(10, 0) << endl;
	}
	catch (double a)
	{
		cout<< "a: "<< a << " is divided by zero!" << endl;
	}

	catch(...)
	{
		cout << "未知异常" << endl;
	}
	
	cout << "ok" << endl;

	return 1;
}

