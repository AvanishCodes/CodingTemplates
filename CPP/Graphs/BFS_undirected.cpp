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
  void BFS_helper(int start);
  void BFS(int start, bool visited[]);
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
  return;
}

void undirected::BFS_helper(int start)
{
  bool visited[this->v];
  memset(visited, false, this->v);
  BFS(start, visited);
  for (int i = 0; i < this->v; i++)
    if (!visited[i])
      BFS(i, visited);
  return;
}

void undirected::BFS(int start, bool visited[])
{
  visited[start] = true;
  list<int> queue;
  vector<int>::iterator i;
  queue.push_back(start);
  while (!queue.empty())
  {
    start = queue.front();
    cout << start << ' ';
    queue.pop_front();
    for (i = edges[start].begin(); i != edges[start].end(); i++)
      if (!visited[*i])
        visited[*i] = true, queue.push_back(*i);
  }
  return;
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
  G.BFS_helper(3);
  return 0;
}