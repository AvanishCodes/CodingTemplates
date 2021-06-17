#include <bits/stdc++.h>
using namespace std;
#define max_nodes 10000

int arr[max_nodes][max_nodes] = {0};

int main()
{
  int n, a, b; //  n = number of edges;
  // Set the connected nodes
  // If the problem assumes that each node is connected to itself
  for (int i = 0; i < n; i++)
    arr[i][i] = 1;
  for (int i = 0; i < n; i++)
    cin >> a >> b, arr[a][b] = 1;
}