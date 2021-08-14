#include <iostream>
#include <vector>
#include <algorithm>
#define VI vector<int>
using namespace std;
#define ASCII_SIZE 256
#define ll long long
#define MOD 1000000007
// Function for Rabin Karp pattern searching
VI RabinKarp(string text, string pattern)
{
  int m = pattern.size();
  int n = text.size();
  ll p = 0;  // pattern hash value
  ll t = 0;  // text hash value
  int h = 1; // pattern multiplier
  VI res;
  int i;
  int j = 0;
  // Calculate hash values of pattern and first windows of text
  for (i = 0; i < m; i++)
  {
    p = ((p * ASCII_SIZE) + pattern[i]) % MOD;
    t = ((t * ASCII_SIZE) + text[i]) % MOD;
  }
  // Calculate the value of h
  for (int i = 0; i < m - 1; i++) // h = pow(ASCII_SIZE, m-1) % MOD
    h = (h * ASCII_SIZE) % MOD;

  // Now slide the pattern
  for (i = 0; i <= n - m; i++)
  {
    // Check the hash values of current window of text
    // and pattern. If the hash values match then only
    // check for characters one by one
    if (p == t) // hash values match
    {
      for (j = 0; j < m; j++)
        if (text[i + j] != pattern[j])
          break;
      if (j == m)
        res.push_back(i);
    }
    // Calculate hash value for next window of text
    if (i < n - m)
    {
      t = ((ASCII_SIZE * (t - text[i] * h)) + text[i + m]) % MOD;
      if (t < 0)
        t += MOD;
    }
  }
  return res;
}

int main()
{
  string str = "AABAACAADAABAAABAA";
  string pattern = "AABA";
  VI res = RabinKarp(str, pattern);
  cout << "The pattern is found at following positions: ";
  for (int i = 0; i < res.size(); i++)
    cout << res[i] << " ";
  cout << endl;
  return 0;
}