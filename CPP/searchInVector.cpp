#include <iostream>
#include <vector>
using namespace std;
#define deb_vec(v)                   \
  for (int i = 0; i < v.size(); i++) \
    cout << v[i] << ' ';

// #define debug_vector(v) \
//   for (element : v)     \
//     cout << element << ' ';

// Function for linear search
// int linearSearch(vector<int> v, int key) // For value based search, the changes to the vector are not reflected to the original array
bool linearSearchBool(vector<int> &v, int value) // For address based search, any change to the vector will be refected to the original array
{
  for (auto element : v)
    if (element == value)
      return true;
  return false;
}

// Index based linear search
int linearSearchIndex(vector<int> &v, int value) // For address based search, any change to the vector will be refected to the original array
{
  int resultIndex = -1;
  for (auto element : v)
    if (element == value)
      return (resultIndex + 1);
    else
      resultIndex++;
  return resultIndex == v.size() - 1 ? -1 : resultIndex;
}

// Return the indices containing the value, if no value exists, return empty vector
vector<int> linearSearchIndices(vector<int> &v, int value) // For address based search, any change to the vector will be refected to the original array
{
  vector<int> result;
  for (auto element : v)
    if (element == value)
      result.push_back(element);
  return result;
}

// Driver Code
int main()
{
#ifndef ONLINE_JUDGE
  // For getting input from input.txt file
  freopen("input.txt", "r", stdin);
  // Printing the Output to output.txt file
  freopen("output.txt", "w", stdout);
#else
  // online submission
#endif
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  int element;
  cin >> element;
  bool res = linearSearchBool(v, element);
  // To check if the search is successful or not
  string end = (res ? "YES" : "NO");
  cout << "\nThe element with value " << element << " in vector " << end << endl;
  // TO check the index of the element
  cout << "\nThe index of the element with value " << element << " in vector is: " << linearSearchIndex(v, element) << endl;

  // Element found at the indices

  vector<int> indices = linearSearchIndices(v, element);
  if (indices.size() == 0)
    cout << "\nThe element with value " << element << " is not found in the vector" << endl;
  else
  {
    cout << "\nThe indices of the element with value " << element << " in vector are: ";
    for (auto index : indices)
      cout << index << " ";
    cout << endl;
  }
  // debug_vector(v);
  deb_vec(v);
  return 0;
}