#include <random>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    cout << "\n\n\n\t\t\t\033[1;31mCreating a new vector by picking the first 5 elements of a vector\033[0m\n\n\n";
    string benefits = "Why vectors?\n\t1. Dynamic Size.\n\t2. Rich Library Functions.\n\t3. Initialized with default values.\n";
    cout << benefits;
    vector<int> v1;
    for (int i = 0; i < 10; ++i)
        v1.push_back(rand() % 10000);

    for (auto element : v1)
        cout << element << " ";
    cout << endl;

    for (auto it = v1.begin(); it != v1.end(); ++it)
        cout << *it << " ";
    cout << endl;

    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << " ";
    cout << endl;

    cout << "\n\n\n";
    cout << "Note: front() and back() return references of a vector.";
    cout << "\n\n\n\t\t\t\033[1;31mCreating a new vector by picking the first 5 elements of a vector\033[0m\n";
    cout << "\n\t\t\t\034[1;31mInsert 3 for 4 times in the begining\034[0m\n";
    cout << "\n\n\n\t\t\t\035[1;31mInsert 10000 in the endr\035[0m\n";
    vector<int> v2;
    v2.insert(v2.begin(), v1.begin(), v1.begin() + 5);
    v2.insert(v2.begin(), 4, 3);
    v2.insert(v2.end(), 10000);
    for (auto element : v2)
        cout << element << " ";
    cout << endl;

    cout << "\n\t\t\t\033[1;31mDeleting elements of a vector\033[0m\n";
    cout << "By reference: begin():\n";
    v2.erase(v2.begin());
    for (auto element : v2)
        cout << element << " ";
    cout << endl;
    cout << "3rd to 5th elements\n";
    v2.erase(v2.begin() + 2, v2.begin() + 5);
    for (auto element : v2)
        cout << element << " ";
    cout << endl;
    cout << "\n\n\n\t\t\t\033[1;31mDeleting the whole vector\033[0m\n";
    v2.clear();
    if (v2.empty())
        cout << "Vector is now empty\n";

    cout << "\nat uses range check \n";
    for (int i = 0; i < v1.size() + 1; i++)
        cout << v1.at(i) << " ";

    return 0;
}