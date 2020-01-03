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
    unique_ptr<MyClass> up1;
	
    {
        cout << "Entered inner block." << endl;
        unique_ptr<MyClass> up2(new MyClass);
 
        //up1 = up2;		// Fordítási hiba.
        up1 = move(up2);
        up2.reset();	  // Nem szabadítja fel a memóriát, mert átadtuk az objektum referenciáját p1-nek. 
        cout << "Leaving inner block." << endl;
    }
    cout << "Left inner block." << endl;
 
    up1.reset();		    // Felszabadítja a lefoglalt memóriát. Hiányában majd akkor szabadul fel, ha p1 kikerül a veremből a main függvény végén.
    cout << "Leaving main() function." << endl;
	
    return 0;
}
