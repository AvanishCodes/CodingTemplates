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
  pair<int, int> getPalindromeEnds(int center);
  string longestPalindrome(string s);
};

// Constructor
LongestPalindromicSubstring::LongestPalindromicSubstring(string str)
{
  this->s = str;
}

// Function to find the longest palindromic substring
string LongestPalindromicSubstring::longestPalindrome(string s)
{
  int max = 1;
  int len = s.length();
  int i, j;
  int start = 0, end = 0;
  for (i = 0; i < len; i++)
  {
  }
  return s.substr(start, end);
}

int main()
{
  string str;
  cin >> str;
  LongestPalindromicSubstring lps(str);
  cout << lps.longestPalindrome(str) << endl;
  return 0;
}