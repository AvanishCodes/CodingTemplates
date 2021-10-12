#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;
int main()
{
    cout << "Iterating over a vector of integers" << endl;
    vector<int> v = {1, 2, 3, 4, 5};
    vector<int>::iterator it = v.begin(); // iterator to the first element

    // Use iterator to get any element
    cout << "Use iterator to get third(index 2) element: Use with caution, reset the iterator if required" << endl;
    advance(it, 2);
    cout << *it << endl;

    cout << "opration using iterator: v[2] = 100" << endl;
    *it = 100;

    it = v.begin();

    vector<int>::iterator ite = v.end(); // iterator to the last element
    for (; it != ite; it = next(it))
        cout << *it << " ";
    cout << endl;

    cout << "Iterating over a vector of integers in reverse" << endl;
    vector<int>::reverse_iterator r_end = v.rbegin();
    for (; r_end != v.rend(); r_end = next(r_end))
        cout << *r_end << " ";
    cout << endl;

    cout << "Iterating over a vector of integers in reverse --> Overcomplicated use of prev()" << endl;
    vector<int>::iterator rend = prev(v.end());
    for (; rend != prev(v.begin()); rend = prev(rend))
        cout << *rend << " ";
    cout << endl;

    cout << "Iterating over a vector of pairs" << endl;
    vector<pair<int, int>> vp = {{1, 2}, {3, 4}, {5, 6}};
    vector<pair<int, int>>::iterator itp = vp.begin();
    for (; itp != vp.end(); itp++)
        cout << itp->first << " " << itp->second << endl;
    return 0;
}