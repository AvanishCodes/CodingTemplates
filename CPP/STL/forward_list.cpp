#include <iostream>
#include <forward_list>
using namespace std;
int main()
{
    forward_list<int> flist1 = {1, 2, 3, 4, 5, 10};
    flist1.push_front(10);
    flist1.push_front(7);
    for (auto it = flist1.begin(); it != flist1.end(); ++it)
        cout << *it << " ";
    cout << endl;
    cout << "\n\t\t\t\033[1;31m Removing an item from a list  \033[0m\n";
    flist1.remove(10);
    for (auto it = flist1.begin(); it != flist1.end(); ++it)
        cout << *it << " ";
    cout << endl;

    forward_list<int> flist2;
    flist2.assign(flist1.begin(), flist1.end());
    for (auto it = flist2.begin(); it != flist2.end(); ++it)
        cout << *it << " ";
    cout << endl;

    forward_list<int> flist3;
    flist3.assign(10, 10);
    for (auto it = flist3.begin(); it != flist3.end(); ++it)
        cout << *it << " ";
    cout << endl;

    forward_list<int> flist4;
    flist4.assign({1, 2, 3, 4, 5});
    for (auto it = flist4.begin(); it != flist4.end(); ++it)
        cout << *it << " ";
    cout << endl;

    cout << "\n\t\t\t\033[1;31m Insert an element after first element: \033[0m\n";
    auto it = flist4.insert_after(flist4.begin(), 100);
    for (auto it = flist4.begin(); it != flist4.end(); ++it)
        cout << *it << " ";
    cout << endl;

    cout << "\n\t\t\t\033[1;31m Insert many elements after first element: \033[0m\n";
    it = flist4.insert_after(flist4.begin(), {10, 20, 30});
    for (auto it = flist4.begin(); it != flist4.end(); ++it)
        cout << *it << " ";
    cout << endl;

    cout << "\n\t\t\t\033[1;31m Emplace an element after first element: for optimizations \033[0m\n";
    it = flist4.emplace_after(flist4.begin(), 45);
    for (auto it = flist4.begin(); it != flist4.end(); ++it)
        cout << *it << " ";
    cout << endl;

    cout << "\n\t\t\t\033[1;31m Erase an element after an iterator: \033[0m\n";
    it = flist4.erase_after(it);
    for (auto it = flist4.begin(); it != flist4.end(); ++it)
        cout << *it << " ";
    cout << endl;

    cout << "\n\t\t\t\033[1;31m Erase many elements after an iterator: \033[0m\n";
    it = flist4.erase_after(it, flist4.end());
    for (auto it = flist4.begin(); it != flist4.end(); ++it)
        cout << *it << " ";
    cout << endl;

    cout << "Other functions:\n\
            \n\t1. fl.clear()     : clear the list\
            \n\t2. fl.empty()     : true if list is empty\
            \n\t3. fl.reverse()   : reverse the linked list\
            \n\t4. fl1.merge(fl2) : merges fl2 into fl1, clears fl2\
            \n\t5. fl.sort        : sorts the linked list    ";

    return 0;
}