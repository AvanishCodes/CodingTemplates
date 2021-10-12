#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define VI vector<int>
using namespace std;
#define deb_vec(x)    \
  for (auto i : x)    \
    cout << i << " "; \
  cout << endl;

/**
 * @brief KMP Algorithm uses an array to store the longest prefix suffix
 *       of the pattern.
 * It utilises the proper prefix of a substring which is also a suffix of the
 * pattern.
 * The idea is not not start a pattern search from the beginning of the string
 * but from the end of the previous match.
 * It is more useful when the search is more frequent than the pattern.
 * Time Complexity: O(size(pattern) + size(text))
 * @return int 
 **/

// Function to compute the LPS array
/**
 * @brief At each location of the LPS array, impute the length of the longest
 *       proper prefix which is also the suffix ending at that index. 
 * @param pattern : the string for which the pattern is to be calculated
 * @return lps  : the vector in which the LPS array is stored
 **/
VI computeLPSArray(string pattern)
{
  VI lps(pattern.size());
  int len = 0; // Length of the previously computed longest proper prefix suffix
  // for (auto i : lps)
  // cout << "i=" << i << endl;
  lps[0] = 0;                         // Length of the longest proper prefix suffix at index 0 is always 0, as there is no proper prefix at index 0
  int i = 1;                          // Index of the current character in the pattern
  int patternLength = pattern.size(); // Size of the pattern;
  while (i < patternLength)
  {
    if (pattern[i] == pattern[len]) // If the pattern character at the current index is equal to the pattern character at the length of the longest proper prefix suffix
      len++, lps[i] = len, i++;
    else
    {
      if (len != 0)
        len = lps[len - 1];
      else
        lps[i] = 0, i++;
    }
  }
  return lps;
}

// Function to search for the pattern in the text
/**
 * @brief KMP Search implementation using the helper function
 * 
 * @param text : the string in which the pattern is to be searched
 *        pattern : the string for which the pattern is to be searched
 * @return vector of integers 
**/
VI KMP(string text, string pattern)
{
  int patternLength = pattern.size();
  int textLength = text.size();
  VI lps = computeLPSArray(pattern);
  int i = 0, j = 0;
  VI result;
  while (i < textLength && j < patternLength)
  {
    if (text[i] == pattern[j])
      i++, j++;
    if (j == patternLength)
      result.push_back(i - j);
    else if (i < textLength && text[i] != pattern[j])
    {
      if (j != 0)
        j = lps[j - 1];
      else
        i++;
    }
  }
  return result;
}

// Driver Code
int main()
{
  string text = "shishirritu";
  string pattern = "shir";
  if (KMP(text, pattern).size() != 0)
  {
    cout << "Matches found here: \n";
    for (auto i : KMP(text, pattern))
      cout << i << " ";
  }
  else
    cout << "No match found";
  cout << endl;
  return 0;
}