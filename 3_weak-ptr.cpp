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
	
	weak_ptr<MyClass> wp = sp1;
	cout << "Use count: " << sp1.use_count() << endl;	// A use_count csak a shared_ptr-eket tartja számon.
	cout << "Use count: " << wp.use_count() << endl;
 
	{
		cout << "Entered inner block." << endl;
		shared_ptr<MyClass> sp2 = wp.lock();
		cout << "Use count: " << sp1.use_count() << endl;
		
		if(sp2)
			cout << "Lock acquired." << endl;
		cout << "Leaving inner block." << endl;
	}
	cout << "Left inner block." << endl;
	cout << "Use count: " << sp1.use_count() << endl;
 
	cout << "About to delete the last shared pointer." << endl;
	sp1.reset();
	cout << "Deleted the last shared pointer." << endl;
	
	shared_ptr<MyClass> sp3 = wp.lock();
	if(!sp3)
		cout << "Shared object does not exists anymore." << endl;
		
	if(wp.expired())	// Párhuzamos programoknál nem ekvivalens az előbbivel!
		cout << "Shared object does not exists anymore." << endl;
	
	return 0;
}
