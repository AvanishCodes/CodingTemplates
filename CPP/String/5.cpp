#include <iostream>
#include <vector>
using namespace std;

#define VI vector<int>
// Function to search a pattern in a string using sliding window approach
VI searchPattern(string str, string pattern)
{
  int i, j, k, m, n;
  VI res;
  // Length of the string and pattern
  n = str.length();
  m = pattern.length();
  if (m > n)
    return res;
  for (int i = 0; i <= n - m; i++)
    if (str.substr(i, m) == pattern) // Check if the pattern is present in the string
      res.push_back(i);              // If yes, store the starting index
  return res;
}

int main()
{

  string str = "AABAACAADAABAAABAA";
  string pattern = "AABA";
  VI res = searchPattern(str, pattern);
  cout << "The pattern is found at following positions: ";
  for (int i = 0; i < res.size(); i++)
    cout << res[i] << " ";
  cout << endl;
  return 0;
}