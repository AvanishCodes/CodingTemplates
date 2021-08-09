#include <iostream>
#include <vector>
#define VI vector<int>
#define fn for (int i = 0; i < n; i++)
using namespace std;

// FUnction to calculate sum of elements in an array
int calculateArraySum(VI a)
{
  int sum = 0;
  // Method 1: Naive method
  // for (int i = 0; i < a.size(); i++)
  //   sum += a[i];
  // Method 2: C++ STL
  for (auto element : a)
    sum += element;
  return sum;
}

// Driver Code
int main()
{
  int n;
  cout << "Enter the number of integers that you want to take in memory: ";
  cin >> n;
  cout << "Enter the numbers: ";
  // *a ==> Variable length array
  // a = *s ==> a is a pointer to the first element of s
  // Allot 20 bytes to a, for a 64 bit machine
  // int *a = new int[n];
  // fn cin >> a[i];
  // fn cout << a[i] << ' ';
  // cout << endl;
  // // Modify the size of the array
  // a = new int[n + 1];
  // a[n] = 100;
  // n += 1;
  // fn cout << a[i] << ' ';
  VI arr(n);
  fn cin >> arr[i];
  cout << "Sum of the array is: ";
  cout << calculateArraySum(arr) << '\n';
  return 0;
}