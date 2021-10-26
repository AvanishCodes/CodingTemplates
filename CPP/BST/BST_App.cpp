#include "BST.cpp"
using namespace std;
int main()
{
    BST<int> *root = new BST<int>();
    root->setData(15);
    root->insert(5);
    root->insert(3);
    root->insert(7);
    root->insert(2);
    root->insert(4);
    root->insert(6);
    root->insert(8);
    root->insert(1);
    root->insert(9);
    root->insert(10);
    root->insert(11);
    root->insert(12);
    root->insert(13);
    root->insert(14);
    root->insert(16);
    root->insert(17);
    root->insert(18);
    root->insert(19);
    root->insert(20);
    root->insert(21);
    root->insert(22);
    root->insert(23);
    root->insert(24);
    root->insert(25);
    root->insert(26);
    root->insert(27);
    root->insert(28);
    root->insert(29);
    root->insert(30);
    root->insert(31);
    root->insert(32);
    // Now, print the BST in order
    cout << "In Order: ";
    root->printInOrder();
    cout << endl;
    // Now, print the BST pre order
    cout << "Pre Order: ";
    root->printPreOrder();
    cout << endl;
    // Now, print the BST post order
    cout << "Post Order: ";
    root->printPostOrder();
    cout << endl;
    // Now, print the BST level order
    cout << "Level Order: ";
    root->printLevelOrder();
    cout << endl;
    // Now, search for a node
    string result;
    result = root->search(5) ? "YES" : "NO";
    cout << "Searching for node with data = 5: " << result << endl;
    result = root->search(20) ? "YES" : "NO";
    cout << "Searching for node with data = 20: " << result << endl;
    // Remove a node
    root->remove(5);
    cout << "After removing node with data = 5: " << endl;

    // Now, print the BST in order
    cout << "In Order: ";
    root->printInOrder();
    cout << endl;
    // Now, print the BST pre order
    cout << "Pre Order: ";
    root->printPreOrder();
    cout << endl;
    // Now, print the BST post order
    cout << "Post Order: ";
    root->printPostOrder();
    cout << endl;
    // Now, print the BST level order
    cout << "Level Order: ";
    root->printLevelOrder();
    cout << endl;
    // Now, search for a node
    result = root->search(5) ? "YES" : "NO";
    cout << "Searching for node with data = 5: " << result << endl;
    result = root->search(15) ? "YES" : "NO";
    cout << "Searching for node with data = 15: " << result << endl;

    return 0;
}