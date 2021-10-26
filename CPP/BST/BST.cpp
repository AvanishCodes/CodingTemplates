#include <iostream>
using namespace std;

/**
 * @brief Template Binary Search Tree
 * 
 */
template <class T>
class BST
{
private:
    T data;
    BST *left, *right;

public:
    /** 
     * @brief Construct a new BST object
     * 
     */
    BST();
    /**
     * @brief Destroy the BST object
     * 
     */
    ~BST();
    /**
     * @brief Insert a new node into the BST
     * 
     * @param newData 
     */
    void insert(T newData);
    /**
     * @brief Search for a node in the BST
     * 
     * @param searchData 
     * @return true 
     * @return false 
     */
    bool search(T searchData);
    /**
     * @brief Print the BST in order
     * 
     */
    void printInOrder();
    /**
     * @brief Print the BST pre order
     * 
     */
    void printPreOrder();
    /**
     * @brief Print the BST post order
     * 
     */
    void printPostOrder();
    /**
     * @brief Print the BST level order
     * 
     */
    void printLevelOrder();
    /**
     * @brief Get the data of the BST
     * 
     * @return T 
     */
    T getData();
    /**
     * @brief Get the left of the BST
     * 
     * @return BST* 
     */
    BST *getLeft();
    /**
     * @brief Get the right of the BST
     * 
     * @return BST* 
     */
    BST *getRight();

    /**
     * @brief Set the data of the BST
     * 
     * @param newData 
     */
    void setData(T newData);
    /**
     * @brief Set the left of the BST
     * 
     * @param newLeft 
     */
    void setLeft(BST *newLeft);
    /**
     * @brief Set the right of the BST
     * 
     * @param newRight 
     */
    void setRight(BST *newRight);
    /**
     * @brief Remove an item from the BST
     * 
     * @param removeData
     */
    void remove(T removeData);
};

/**
 * @brief Construct a new BST<T>::BST object
 * 
 * @tparam T 
 */
template <class T>
BST<T>::BST()
{
    left = NULL;
    right = NULL;
}

template <class T>
BST<T>::~BST()
{
    if (left != NULL)
    {
        delete left;
    }
    if (right != NULL)
    {
        delete right;
    }
}

template <class T>
void BST<T>::insert(T newData)
{
    if (newData < data)
    {
        if (left == NULL)
        {
            left = new BST();
            left->data = newData;
        }
        else
        {
            left->insert(newData);
        }
    }
    else if (newData > data)
    {
        if (right == NULL)
        {
            right = new BST();
            right->data = newData;
        }
        else
        {
            right->insert(newData);
        }
    }
}

/**
 * @brief Get the left of the BST
 * 
 * @tparam T 
 * @return BST<T>* 
 */
template <class T>
BST<T> *BST<T>::getLeft()
{
    return left;
}

/**
 * @brief Get the right of the BST
 * 
 * @tparam T 
 * @return BST<T>* 
 */
template <class T>
BST<T> *BST<T>::getRight()
{
    return right;
}

/**
 * @brief Get the data of the BST
 * 
 * @tparam T 
 * @return T 
 */
template <class T>
T BST<T>::getData()
{
    return data;
}

/**
 * @brief Search Function of the BST
 * 
 * @tparam T 
 * @param searchData 
 * @return true 
 * @return false 
 */
template <class T>
bool BST<T>::search(T searchData)
{
    if (searchData == data)
    {
        return true;
    }
    else if (searchData < data)
    {
        if (left == NULL)
        {
            return false;
        }
        else
        {
            return left->search(searchData);
        }
    }
    else if (searchData > data)
    {
        if (right == NULL)
        {
            return false;
        }
        else
        {
            return right->search(searchData);
        }
    }
    return false;
}

/**
 * @brief Print the BST in order
 * 
 * @tparam T 
 */
template <class T>
void BST<T>::printInOrder()
{
    if (left != NULL)
    {
        left->printInOrder();
    }
    cout << data << " ";
    if (right != NULL)
    {
        right->printInOrder();
    }
}

/**
 * @brief Print the BST pre order
 * 
 * @tparam T 
 */
template <class T>
void BST<T>::printPreOrder()
{
    cout << data << " ";
    if (left != NULL)
    {
        left->printPreOrder();
    }
    if (right != NULL)
    {
        right->printPreOrder();
    }
}

/**
 * @brief Print the BST post order
 * 
 * @tparam T 
 */
template <class T>
void BST<T>::printPostOrder()
{
    if (left != NULL)
    {
        left->printPostOrder();
    }
    if (right != NULL)
    {
        right->printPostOrder();
    }
    cout << data << " ";
}

/**
 * @brief Print the BST level order
 * 
 * @tparam T 
 * @return void* 
 */
template <class T>
void BST<T>::printLevelOrder()
{
    if (left != NULL)
    {
        left->printLevelOrder();
    }
    if (right != NULL)
    {
        right->printLevelOrder();
    }
    cout << data << " ";
}

/**
 * @brief Set the data of the BST
 * 
 * @tparam T 
 * @param newData 
 */
template <class T>
void BST<T>::setData(T newData)
{
    data = newData;
}

/**
 * @brief Set the left of the BST
 * 
 * @tparam T 
 * @param newLeft 
 */
template <class T>
void BST<T>::setLeft(BST *newLeft)
{
    left = newLeft;
}

/**
 * @brief Set the right of the BST
 * 
 * @tparam T 
 * @param newRight 
 */
template <class T>
void BST<T>::setRight(BST *newRight)
{
    right = newRight;
}

/**
 * @brief Remove a data from the BST
 * 
 * @tparam T 
 * @param removeData 
 */
template <class T>
void BST<T>::remove(T removeData)
{
    if (removeData < data)
    {
        if (left != NULL)
        {
            left->remove(removeData);
        }
    }
    else if (removeData > data)
    {
        if (right != NULL)
        {
            right->remove(removeData);
        }
    }
    else
    {
        if (left == NULL && right == NULL)
        {
            delete this;
        }
        else if (left == NULL)
        {
            BST *temp = right;
            delete this;
            *this = *temp;
        }
        else if (right == NULL)
        {
            BST *temp = left;
            delete this;
            *this = *temp;
        }
        else
        {
            BST *temp = right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            data = temp->data;
            temp->remove(temp->data);
        }
    }
    return;
}

/**
 * @brief Driver Code
 * 
 * @return int 
 */
/**
int main()
{
    BST<int> *root = new BST<int>();
    // Set the root
    root->setData(2);
    root->insert(10);
    root->insert(5);
    root->insert(15);
    root->insert(3);
    root->insert(7);
    root->insert(13);
    root->insert(17);
    root->insert(1);
    root->insert(9);
    root->insert(11);
    root->insert(14);
    root->insert(16);
    root->insert(18);
    root->insert(6);
    root->insert(4);
    root->insert(8);
    root->insert(12);
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
*/