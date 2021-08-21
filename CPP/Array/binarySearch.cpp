#include <iostream>
#include <vector>
using namespace std;
#define fn for (int i = 0; i < n; i++)

// n = 10
// arr = [11, 15, 16, 18, 19, 24, 35, 64, 57, 89]
// Function for binary search for an index of a given element
int binarySearchIndex(vector<int> &arr, int low, int high, int value)
{
  while (low <= high)
  {
    // int medium = (low + high) / 2;     // Ignore because of edge cases
    int medium = low + (high - low) / 2;
    if (arr[medium] == value)
      return medium;
    if (arr[medium] < value)
      low = medium + 1;
    if (arr[medium] > value)
      high = medium - 1;
  }
  return -1;
}
// Function for binary search for a given element with status only
bool binarySearchBool(vector<int> &arr, int low, int high, int value)
{
  cout << "Entry point of funtion\n";
  while (low <= high)
  {
    int medium = low + (high - low) / 2;
    if (arr[medium] == value)
      return true;
    if (arr[medium] < value)
      low = medium + 1;
    if (arr[medium] > value)
      high = medium - 1;
  }
  return false;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n; // Size of vector
  cin >> n;
  int key;
  cin >> key;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << "Input taken\n";
  bool status;
  status = binarySearchBool(arr, 0, n - 1, key);
  string result = status ? "YES" : "NO";
  cout << key << " found in array: " << result << endl;
  int index = binarySearchIndex(arr, 0, n - 1, key);
  cout << "Index of " << key << " is " << index << endl;
  return 0;
}
