#include <iostream>
using namespace std;
#define fn for (int i = 0; i < n; ++i)

int main()
{
    int n;
    cin >> n;

    cout << "Value of variable before postfix operation: " << n++ << endl;
    cout << "Value of variable after postfix operation: " << n << endl;

    cout << "Value of variable before postfix operation: " << (n += 2)++ << endl;
    cout << "Value of variable after postfix operation: " << n << endl;

    cout << "Value of variable before prefix operation: " << ++(n += 2) << endl;
    cout << "Value of variable before prefix operation: " << n << endl;

    return 0;
}
