#include <iostream>
#include <vector>
#include <string>
#define VI vector<int>
#define fn for (int i = 0; i < n; i++)
using namespace std;

// Class for Naive Pattern Matching
class NaivePatternMatching
{
  string text;
  string pattern;

public:
  // Naive Pattern Matching
  NaivePatternMatching(string text, string pattern);
  VI match_pattern(string text, string pattern);
};

// Naive Pattern Matching Constructor
NaivePatternMatching::NaivePatternMatching(string text, string pattern)
{
  this->text = text;
  this->pattern = pattern;
}

VI NaivePatternMatching::match_pattern(string text, string pattern)
{
  VI result;
  cout << "\nNaive Pattern Matching function:\n";
  int n = text.size();
  int m = pattern.size();
  int i = 0, j = 0;
  for (i = 0; i <= n - m; i++)
  {
    for (j = 0; j < m; j++)
      if (text[i + j] != pattern[j])
        break;
    if (j == m)
    {
      result.push_back(i);
      cout << "Match found at " << i << endl;
    }
    if (i >= n - m) // If the text is exhausted
      break;
  }
  cout << "Naive pattern matching function completed with " << result.size() << " found patterns." << '\n';
  return result;
}

// Driver Code
int main()
{
  string str, pat;
  cin >> str >> pat;
  NaivePatternMatching obj(str, pat);
  VI result = obj.match_pattern(str, pat);
  for (int i = 0; i < result.size(); i++)
    cout << result[i] << " ";
  return 0;
}