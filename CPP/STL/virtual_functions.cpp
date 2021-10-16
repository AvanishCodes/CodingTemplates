#include <iostream>
using namespace std;

/**
 * @brief Base Class
 * 
 */
class Base
{
public:
    /**
     * @brief Virtual function
     * 
     */
    virtual void print()
    {
        cout << "Base" << endl;
    }
    void print1()
    {
        cout << "Base1" << endl;
    }
};

class Derived : public Base
{
public:
    /**
     * @brief print function
     * 
     */
    void print()
    {
        cout << "Derived" << endl;
    }
    void print1()
    {
        cout << "Derived1" << endl;
    }
};

/**
 * @brief Sample Program to demonstrate virtual functions
 * It shows that virtual functions are overridden in derived class  and not in base class
 * It implements run time polymorphism
 * @return int 
 */
int main()
{
    // Create a base class object
    Base base;
    base.print();
    Derived derived;
    derived.print();
    Base *pBase = &derived;
    pBase->print();
    Base *pBase1 = &derived;
    pBase1->print1();
    return 0;
}