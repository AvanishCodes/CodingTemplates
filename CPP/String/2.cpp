#include <iostream>
#include <string>
using namespace std;
/*
 *  Problem Statement: Given a string, find if it's alphanumeric characters form a string or not?
 *  Note: A character is alphanumeric if it's an alphabet (a-z, A-Z) or a digit (0-9).
 *    Example:
 *      Input:  "ab12"
 *      Output: true
 *      Input:  "12ab"
 *      Output: true
 *  Example palindrome strings: "madam", "racecar", "a man, a plan, a canal: panama."
 *  Restriction: Do not iterate over the array twice.
 **/

class AlphaNumericPalindrome
{
  string s;

public:
  AlphaNumericPalindrome(string s);
  bool is_alpha_numeric_character(char c);
  bool is_palindrome();
};

// Constructor
AlphaNumericPalindrome::AlphaNumericPalindrome(string s)
{
  this->s = s;
}

// is_alpha_numeric_character
bool AlphaNumericPalindrome::is_alpha_numeric_character(char c)
{
  return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'));
}

// is_palindrome
bool AlphaNumericPalindrome::is_palindrome()
{
  int i = 0, j = s.length() - 1;
  while (i < j)
  {
    while (i < j && !is_alpha_numeric_character(s[i]))
      i++;
    while (i < j && !is_alpha_numeric_character(s[j]))
      j--;
    if (i < j && s[i] != s[j])
      return false;
    i++;
    j--;
  }
  return true;
}

int main()
{
  string s;
  cin >> s;
  AlphaNumericPalindrome anp(s);
  if (anp.is_palindrome())
    cout << "true";
  else
    cout << "false";
  return 0;
}