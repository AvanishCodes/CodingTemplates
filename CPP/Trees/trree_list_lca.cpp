#include <bits/stdc++.h>
using namespace std;
#define max_nodes 10000

vector<int> arr[max_nodes];
bool visited[max_nodes];
int distance_from_start[max_nodes] = {0};

// Logic behind LCA
// There is a root node, and the LCA for two nodes is the node whose children lie on a different path for both the routes

void dfs(int start)
{
  visited[start] = true;
  cout << start << ' ';
  for (int v : arr[start])
    if (!visited[v])
      dfs(v);
  return;
}
void bfs(int start)
{

  queue<int> q;
  q.push(start);
  distance_from_start[start] = 0;
  visited[start] = 1;

  while (!q.empty())
  {
    int current = q.front();
    q.pop();

    for (int node : arr[current])
      if (!visited[node])
      {
        distance_from_start[node] = distance_from_start[current] + 1;
        visited[node] = true;
        q.push(node);
      }
  }
  return;
}

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n, a, b; //  n = number of vertices;
  cin >> n;
  // Set the connected nodes
  // If the problem assumes that each node is connected to itself
  // Tree will always have n-1 edges
  // for (int i = 0; i < n; i++)
  //   arr[i].push_back(i);
  for (int i = 1; i < n; i++)
    cin >> a >> b, arr[a].push_back(b), arr[b].push_back(a);

  for (int i = 0; i < n; i++)
  {
    for (auto it : arr[i])
      cout << it << ' ';
    cout << '\n';
  }

  // Input of the start node
  int start;
  cin >> start;
  memset(visited, max_nodes, false);
  bfs(start);
  cout << '\n';
  for (int i = 0; i < n; i++)
    cout << distance_from_start[i] << ' ';
  return 0;
}