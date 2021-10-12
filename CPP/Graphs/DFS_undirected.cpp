#include <bits/stdc++.h>
using namespace std;

class undirected
{
  int v; // Number of vertices(nodes)
  vector<vector<int>> edges;

public:
  undirected(int nodes);
  void add_edge(int start, int end);
  void print_sizes();
  void print_graph();
  void DFS_helper(int start);
  void DFS(int start, bool visited[]);
};
undirected::undirected(int nodes)
{
  v = nodes;
  vector<int> x;
  for (int i = 0; i < v; i++)
    edges.push_back(x);
}
void undirected::add_edge(int start, int end)
{
  edges[start].push_back(end);
  edges[end].push_back(start);
}
void undirected::print_sizes()
{
  for (int i = 0; i < v; i++)
    cout << "Number of edges emerging from vertex " << i
         << " --> " << edges[i].size() << '\n';
}
void undirected::print_graph()
{
  for (int i = 0; i < v; i++)
  {
    cout << "Vertex " << i << " is connected to :";
    for (auto it : edges[i])
      cout << it << ", ";
    cout << '\n';
  }
}

void undirected::DFS_helper(int start)
{
  bool visited[v];
  memset(visited, false, v);
  DFS(start, visited);
  for (int i = 0; i < v; i++)
    DFS(i, visited);
}

void undirected::DFS(int start, bool visited[])
{
  // for (int i = 0; i < v; i++)
  // {
  if (!visited[start])
  {
    visited[start] = true;
    cout << start << ' ';
    // for (int i = 0; i < v; i++)      //   cout << visited[i] << ' ';      // cout << '\n';
    for (int j = 0; j < edges[start].size(); j++)
      if (!visited[edges[start][j]])
        DFS(edges[start][j], visited);
  }
  // }
}

int main()
{
  // #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  // #else
  //   online submission
  // #endif
  int n;
  // cout << "Enter the number of vertices in the graph: ";
  cin >> n;
  undirected G(n);
  int e;
  // cout << "Enter the number of edges in the graph: ";
  cin >> e;
  int src, dest;
  for (int i = 0; i < e; i++)
  {
    // cout << "Enter source and destination of the edge";
    cin >> src >> dest;
    G.add_edge(src, dest);
  }
  G.print_sizes();
  G.print_graph();
  G.DFS_helper(4);
  return 0;
}