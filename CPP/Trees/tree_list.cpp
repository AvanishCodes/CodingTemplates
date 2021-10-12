#include <bits/stdc++.h>
using namespace std;
#define max_nodes 10000

vector<int> arr[max_nodes];

int main()
{
  int n, a, b; //  n = number of vertices;
  cin >> n;
  // Set the connected nodes
  // If the problem assumes that each node is connected to itself
  // Tree will always have n-1 edges
  for (int i = 1; i < n; i++)
    arr[i][i] = 1;
  for (int i = 0; i < n; i++)
    cin >> a >> b, arr[a].push_back(b), arr[b].push_back(a);
  for (int i = 0; i < n; i++)
  {
    for (auto it : arr[i])
      cout << it << ' ';
    cout << '\n';
  }
}