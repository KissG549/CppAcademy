#include <iostream>
#include <memory>
#include <vector>

using namespace std;

// Saját típus.
struct MyClass
{
	// Mindössze egy értéket tárol.
	int value;
	
	// Konstruktor.
	MyClass(int value)
	{
		this->value = value;
		cout << "Constructor completed for a MyClass object." << endl;
	}
	
	// Destruktor.
	virtual ~MyClass()
	{
		cout << "Destructor completed for a MyClass object." << endl;
	}
};

// Kiíró operátor az előbbi típushoz.
ostream& operator<<(ostream &out, const MyClass &obj)
{
	out << "Value: " << obj.value << endl;
	return out;
}

// Aliaszok.
typedef auto_ptr<MyClass> AutoClass;
typedef vector<AutoClass> AutoVector;
typedef unique_ptr<MyClass> UniqueClass;
typedef vector<UniqueClass> UniqueVector;
typedef shared_ptr<MyClass> SharedClass;
typedef vector<SharedClass> SharedVector;

// Főprogram.
int main() 
{
	cout << "-== Test auto_ptr begin ==-" << endl << endl;
	
	AutoVector av;
	av.push_back(AutoClass(new MyClass(1)));
	av.push_back(AutoClass(new MyClass(2)));
	av.push_back(AutoClass(new MyClass(3)));
	
	cout << "Vector elements:" << endl;
	for(int i = 0; i < av.size(); ++i)
		cout << "\t" << *av[i];
	cout << endl;
	
	{
		cout << "Entered inner block." << endl;
		AutoVector cav(av.begin(), av.end());
		cout << "Leaving inner block." << endl;
	}
	cout << "Left inner block." << endl;
	
	/*
	cout << "Vector elements:" << endl;
	for(int i = 0; i < av.size(); ++i)
		cout << "\t" << *av[i];	// Futási hiba.
	cout << endl;
	*/
	
	cout << "-== Test auto_ptr end ==-" << endl << endl;
	cout << "-== Test unique_ptr begin ==-" << endl << endl;
	
	UniqueVector uv;
	uv.push_back(UniqueClass(new MyClass(4)));
	uv.push_back(UniqueClass(new MyClass(5)));
	uv.push_back(UniqueClass(new MyClass(6)));
	
	cout << "Vector elements:" << endl;
	for(int i = 0; i < uv.size(); ++i)
		cout << "\t" << *uv[i];
	cout << endl;
	
	//UniqueVector cuv(uv.begin(), uv.end());	// Fordítási hiba.

	cout << "-== Test unique_ptr end ==-" << endl << endl;
	cout << "-== Test shared_ptr begin ==-" << endl << endl;
	
	SharedVector sv;
	sv.push_back(SharedClass(new MyClass(1)));
	sv.push_back(SharedClass(new MyClass(2)));
	sv.push_back(SharedClass(new MyClass(3)));
	
	cout << "Vector elements:" << endl;
	for(int i = 0; i < sv.size(); ++i)
		cout << "\t" << *sv[i];
	cout << endl;
	
	{
		cout << "Entered inner block." << endl;
		SharedVector csv(sv.begin(), sv.end());
		cout << "Leaving inner block." << endl;
	}
	cout << "Left inner block." << endl;
	
	cout << "Vector elements:" << endl;
	for(int i = 0; i < sv.size(); ++i)
		cout << "\t" << *sv[i];
	cout << endl;
	
	cout << "-== Test shared_ptr end ==-" << endl << endl;
	
	return 0;
}
