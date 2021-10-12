#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// Augment a string with a suffix
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

int findMinimumDifference(string s)
{
  vector<int> z = createZArray(s, vector<int>());            // Create the Z-array
  vector<int>::iterator res = max_element(begin(z), end(z)); // Find the maximum element
  return z[distance(begin(z), res)];                         // Return the maximum element
}

// FUnction to find the minimum characters to be added to make a string palindromic
int findMinimumCharacters(string s)
{
  string augmentedString = getAugmentedString(s, string(s.rbegin(), s.rend())); // Augment the string with the reverse of the same string
  // Calulcate the result using the augmented string
  int temp = findMinimumDifference(augmentedString);
  return s.length() - temp;
}

// Driver Code
int main()
{
  string s = "dada";
  cout << findMinimumCharacters(s) << endl;
  return 0;
}