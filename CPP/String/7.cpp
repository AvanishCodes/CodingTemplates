#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define VI vector<int>
// Z-algorithm
// Time Complexity: O(n)
// Space Complexity: O(n)

// Function to get an augmented string
string getAugmentedString(string pattern, string text, string augmentCharacter = "$")
{
  return pattern + augmentCharacter + text;
}
// Create the Z-array for a given string
vector<int> createZArray(string s, vector<int> z)
{
  int n = s.length();
  int L, R, k;
  L = R = 0;
  z.resize(n);
  // z.push_back(0);
  // [L, R] is a window which matches with the pattern
  for (int i = 1; i < n; i++)
  {
    // if i>R, nothing matches so we'll calculate the Z-array i nnaive way
    if (i > R)
    {
      L = R = i;
      while (R < n && s[R - L] == s[R])
        R++;
      z[i] = R - L; // Danger: This index is accordng to the augmented string
      R--;
    }
    else
    {
      // k = i-L so k corresponds to the number which matches is [L, R] interval
      k = i - L;
      if (z[k] < R - i + 1)
        z[i] = z[k];
      else
      {
        L = i;
        while (R < n && s[R - L] == s[R])
          R++;
        z[i] = R - L;
        R--;
      }
    }
  }
  return z;
}

// Fucntion to match the two strings
vector<int> findMatchIndices(string pattern, string text)
{
  string newString = getAugmentedString(pattern, text);
  int n = newString.length();
  vector<int> z = createZArray(newString, vector<int>());
  VI res;
  // Get the indices where pattern matching is same as the length of pattern
  for (int i = 0; i < n; ++i)
    if (z[i] == pattern.size())
      res.push_back(i - pattern.size() - 1);
  return res;
  // return vector<int>();
}

// Driver Code
int main()
{
  string s = "ramramramramjaishriram";
  string pattern = "ram";
  cout << "Pattern found at indices: ";
  for (auto i : findMatchIndices(pattern, s))
    cout << i << " ";
  cout << endl;
  return 0;
}