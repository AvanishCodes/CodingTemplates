#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Stack implementation using vector as underlying data structure
 *
 * @tparam T Template class for which Stack is implemented
 */
template <class T>
class Stack
{
private:
    /* data */
    vector<T> elems;     // elements
    int currentElements; // current elements in the stack

public:
    /* Methods */
    Stack();           // constructor
    ~Stack();          // destructor
    void push(T elem); // push element
    T pop();           // remove last element
    T peek();          // returns the top element
    bool isEmpty();    // returns true if stack is empty
    int size();        // Size of the stack
};

/**
 * @brief Stack constructor
 *
 * @tparam T Template class for which Stack is implemented
 */
template <class T>
Stack<T>::Stack()
{
    this->currentElements = 0;
}

/**
 * @brief Destroy the Stack<class  T>:: Stack object
 *
 * @tparam T Template class for which Stack is implemented
 */
template <class T>
Stack<T>::~Stack()
{
    delete this;
}

/**
 * @brief Push element into the stack
 *
 * @tparam T Template class for which Stack is implemented
 * @param elem element to be pushed
 */
template <class T>
void Stack<T>::push(T elem)
{
    this->elems.push_back(elem);
    this->currentElements++;
}

/**
 * @brief Pop element from the stack
 *
 * @tparam T Template class for which Stack is implemented
 * @return T value of the element which has been popped out of the stack
 */
template <class T>
T Stack<T>::pop()
{
    if (this->currentElements == 0)
    {
        cout << "Stack is empty" << endl;
        return T();
    }
    else
    {
        T elem = this->elems.back();
        this->elems.pop_back();
        this->currentElements--;
        return elem;
    }
}

/**
 * @brief Get the topmost element of the stack
 *
 * @tparam T Template class for which Stack is implemented
 * @return T the top most element of the stack
 */
template <class T>
T Stack<T>::peek()
{
    try
    {
        if (this->currentElements == 0)
        {
            cout << "Stack is empty" << endl;
            return T();
        }
        else
        {
            return this->elems.back();
        }
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught : " << e.what() << std::endl;
    }
}

/**
 * @brief Whether or not a class is empty
 *
 * @tparam T Template class for which Stack is implemented
 * @return true if stack is empty
 * @return false if stack is not empty
 */
template <class T>
bool Stack<T>::isEmpty()
{
    if (this->currentElements == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief Number of elements in the stack
 *
 * @tparam T Template class for which Stack is implemented
 * @return int number of elements in the current stack
 */
template <class T>
int Stack<T>::size()
{
    return this->currentElements;
}

/**
 * @brief Main function to display the implementation of stack
 *
 * @return int
 */
int main()
{
    Stack<float> stack;
    // Pushing elements into the stack
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);

    // Printing the topmost element
    cout << "Topmost element is: " << stack.peek() << endl;

    // Popping out the topmost element
    cout << "Popping out the topmost element: " << stack.pop() << endl;

    // Checking if the stack is empty
    string result = (stack.isEmpty() == true) ? "" : "not ";
    cout << "Stack is " << result << "empty " << endl;

    // Pop 3 elements from the stack
    cout << "Popped " << stack.pop() << '\n';
    cout << "Popped " << stack.pop() << '\n';
    cout << "Popped " << stack.pop() << '\n';

    // Printing the size of the stack
    cout << "Size of the stack is: " << stack.size() << endl;

    // Pop out the last element
    // cout << float(-1);
    stack.pop();

    return 0;
}