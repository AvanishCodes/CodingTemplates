#include <iostream>
#include <string>
using namespace std;

/*
 * Problem Description:
 *  Given a string, find the length of the longest substring which is a palindrome.
 * For example, the longest palindrome in "aabcdcb" is "bcdcb".
 * Note:
 * The whole string is treated as a single character stream.
 * Basic Approach:
 * 1. Brute force:  Check all substrings and find the longest palindrome. It has a complexity of O(n^3).
 * 2. Outward Expand: There are (2n-1) possiblities for the center of the palindrome.
 *             For each center, expand the palindrome by one character to the left and to the right.
 *  For example, for the string "aabcdcb", the center is "d".
 *  The palindrome is "bcdcb", so the longest palindrome is "bcdcb".
 *  This brings down the complexity to O(n^2).
 **/

class LongestPalindromicSubstring
{
  string s;

public:
  LongestPalindromicSubstring(string str);
  pair<int, int> getPalindromeEnds(int left, int right);
  string longestPalindrome();
};

// Constructor
LongestPalindromicSubstring::LongestPalindromicSubstring(string str)
{
  this->s = str;
}

// Get the ends of the longest palindrome centered at the given center
pair<int, int> LongestPalindromicSubstring::getPalindromeEnds(int left, int right)
{
  while (left >= 0 && right < s.size() && s[left] == s[right])
    left--, right++;
  return make_pair(left + 1, right - 1);
}

// Function to find the longest palindromic substring
string LongestPalindromicSubstring::longestPalindrome()
{
  if (s.size() <= 1)
    return s;
  int max = 1;
  int i, j;
  int start = 0, end = 0;
  int len = s.length();
  pair<int, int> p1;
  pair<int, int> p2;
  for (i = 0; i < len; i++)
  {
    p1 = getPalindromeEnds(i, i);
    p2 = getPalindromeEnds(i, i + 1);
    int temp = p1.second - p1.first + 1;
    if (temp > max)
      max = temp, start = p1.first, end = p1.second;
    temp = p2.second - p2.first + 1;
    if (temp > max)
      max = temp, start = p2.first, end = p2.second;
  }
  return s.substr(start, end - start + 1);
}

// Driver Code
int main()
{
  string str;
  cin >> str;
  LongestPalindromicSubstring lps(str);
  cout << lps.longestPalindrome() << endl;
  return 0;
}