#include <iostream>
#include <memory>

using namespace std;

// Saját típus.
struct MyClass
{
    MyClass() { cout << "MyClass ctor runned." << endl; }
    ~MyClass() { cout << "MyClass dtor runned." << endl; }
};

// Főprogram.
int main() 
{
	shared_ptr<MyClass> sp1(new MyClass);
	cout << "Use count: " << sp1.use_count() << endl;
	
	shared_ptr<MyClass> sp2 = sp1;
	cout << "Use count: " << sp1.use_count() << endl;
 
	sp1.reset();
	cout << "Use count: " << sp2.use_count() << endl;
	
	{
		cout << "Entered inner block." << endl;
		shared_ptr<MyClass> sp3 = sp2;
		cout << "Use count: " << sp2.use_count() << endl;
		cout << "Leaving inner block." << endl;
	}
	cout << "Left inner block." << endl;
	cout << "Use count: " << sp2.use_count() << endl;
	
	cout << "About to delete the last shared pointer." << endl;
	sp2.reset();
	cout << "Deleted the last shared pointer." << endl;
	
	return 0;
}