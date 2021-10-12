#include <bits/stdc++.h>
using namespace std;

class directed
{
  int v; // Number of vertices(nodes)
  vector<vector<int>> edges;

public:
  directed(int nodes);
  void add_edge(int start, int end);
  void print_sizes();
  void print_graph();
};
directed::directed(int nodes)
{
  v = nodes;
  vector<int> x;
  for (int i = 0; i < v; i++)
    edges.push_back(x);
}
void directed::add_edge(int start, int end)
{
  edges[start].push_back(end);
}
void directed::print_sizes()
{
  for (int i = 0; i < v; i++)
    cout << "Number of edges emerging from vertex " << i
         << " --> " << edges[i].size() << '\n';
}
void directed::print_graph()
{
  for (int i = 0; i < v; i++)
  {
    cout << "Vertex " << i << " is connected to :";
    for (auto it : edges[i])
      cout << it << ", ";
    cout << '\n';
  }
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
  directed G(n);
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
  return 0;
}