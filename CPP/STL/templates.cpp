#include <utility>
#include <iostream>
using namespace std;

// Function Template
template <typename T>
T MaxNum(T a, T b)
{
    return (a > b) ? a : b;
}

// Class Template
template <class T1, class T2>
class MyClass
{
    T1 x;
    T2 y;

public:
    MyClass(T1 a, T2 b);
    T1 getX();
    T2 getY();
};

template <class T1, class T2>
MyClass<T1, T2>::MyClass(T1 a, T2 b)
{
    x = a;
    y = b;
}

template <class T1, class T2>
T1 MyClass<T1, T2>::getX()
{
    return x;
}

template <class T1, class T2>
T2 MyClass<T1, T2>::getY()
{
    return y;
}

int main()
{
    // Function Template
    cout << MaxNum<int>(5, 10) << endl;
    cout << MaxNum<int>(150.6, 5.9) << endl;
    cout << MaxNum<float>(150.6, 5.9) << endl;

    // Class Template
    MyClass<int, double> myClass(5, 10.5);
    cout << myClass.getX() << endl;
    cout << myClass.getY() << endl;
    return 0;
}