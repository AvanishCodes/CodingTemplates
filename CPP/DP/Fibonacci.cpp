#include <iostream>
#include <vector>
using namespace std;

class Fibonacci
{
    vector<long long unsigned> fib;
    int capacity;

public:
    Fibonacci(int capacity);
    int size();
    long long unsigned get(int index);
};

/**
 * @brief Return the size of current Fibonacci sequence.
 * 
 * @return int 
 */
int Fibonacci::size()
{
    return fib.size();
}

/**
 * @brief Construct a new Fibonacci:: Fibonacci object
 * 
 * @param capacity 
 */
Fibonacci::Fibonacci(int capacity)
{
    this->capacity = capacity;
    fib.push_back(0);
    fib.push_back(1);
    // Bottom Up Approach
    for (int i = 2; i < capacity; i++)
    {
        fib.push_back(fib[i - 1] + fib[i - 2]);
    }
}

/**
 * @brief Return the value of the index-th element of the Fibonacci sequence.
 * 
 * @param index 
 * @return long long unsigned 
 */
long long unsigned Fibonacci::get(int index)
{
    return fib[index];
}

int main()
{
    int n;
    cin >> n;
    Fibonacci f(n);
    cout << f.get(n - 1) << endl;
    return 0;
}