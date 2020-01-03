#include <iostream>
#include <memory>

using namespace std;

// Saját típus.
struct MyClass
{
	shared_ptr<MyClass> next;

	// Konstruktor.
	MyClass(shared_ptr<MyClass> next)
	{
		this->next = next;
		cout << "Constructor completed for a MyClass object." << endl;
	}
	
	// Destruktor.
	virtual ~MyClass()
	{
		cout << "Destructor completed for a MyClass object." << endl;
	}
};

// Főprogram.
int main() 
{
	shared_ptr<MyClass> nullp;
	shared_ptr<MyClass> sp1(new MyClass(nullp));
	shared_ptr<MyClass> sp2(new MyClass(sp1));
	
	{
		cout << "Entered inner block." << endl;
		shared_ptr<MyClass> sp3(new MyClass(sp2));
		sp1->next = sp3;	// Körkörös hivatkozás létrehozása
		cout << "sp3 use count: " << sp3.use_count() << endl;
		cout << "Leaving inner block." << endl;
	}
	cout << "Left inner block." << endl;
	
	cout << "sp1 use count: " << sp1.use_count() << endl;
	cout << "sp2 use count: " << sp2.use_count() << endl;
	cout << "sp3 use count: " << sp1->next.use_count() << endl;
	
	sp1.reset();
	sp2.reset();

	cout << "Released sp1 and sp2, dtors still not executed." << endl;
	
	return 0;
}
