#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

bool sortBySecond(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}

// Avoid the use of make_pair(): It does not work with the new standard library

int main()
{
    cout << "Hello World";
    pair<int, int> p1; // Default values are 0 and Empty string
    cout << "p1.first = " << p1.first << endl;
    cout << "p1.second = " << p1.second << endl;

    pair<int, int> p2(10, 5);
    cout << "p2.first = " << p2.first << endl;
    cout << "p2.second = " << p2.second << endl;

    pair<int, int> p3(p2);
    cout << "p3.first = " << p3.first << endl;
    cout << "p3.second = " << p3.second << endl;

    pair<int, string> p4 = {1, "AvanishCodes"};
    cout << "p4.first = " << p4.first << endl;
    cout << "p4.second = " << p4.second << endl;

    cout << "\n\n\n\n\t\t\t\tChecking the equality\n";

    pair<int, int> p5(8, 15), p6(36, 21);

    if (p5 == p6)
        cout << "p5 and p6 are equal\n";
    else
        cout << "p5 and p6 are not equal\n";

    vector<pair<int, int>> v;
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p5);
    v.push_back(p6);

    // Sort in reverse order a/c to first member
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    for (auto p : v)
        cout << "(" << p.first << ", " << p.second << ")\n";

    // Sort in increasing order a/c to second member
    sort(v.begin(), v.end(), sortBySecond);
    for (auto p : v)
        cout << "(" << p.first << ", " << p.second << ")\n";

    cout << "Caution: \n";
    cout << "This inequality is reflected in sorting of the vector in :\n";
    cout << "1. vector\n";
    cout << "2. map\n";
    cout << "Heap";

    return 0;
}