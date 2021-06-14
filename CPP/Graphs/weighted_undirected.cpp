#include <bits/stdc++.h>
using namespace std;

class undirected
{
  int v; // Number of vertices(nodes)
  vector<vector<pair<int, int>>> edges;

public:
  undirected(int nodes);
  void add_edge(int start, int end, int weight);
  void print_sizes();
  void print_graph();
};
undirected::undirected(int nodes)
{
  v = nodes;
  vector<pair<int, int>> x;
  for (int i = 0; i < v; i++)
    edges.push_back(x);
}
void undirected::add_edge(int start, int end, int weight)
{
  edges[start].push_back(make_pair(end, weight));
  edges[end].push_back(make_pair(start, weight));
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
    cout << "Vertex " << i << " is connected to 0:\n";
    for (auto it : edges[i])
      cout << it.first << ", " << it.second << '\n';
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
  undirected G(n);
  int e;
  // cout << "Enter the number of edges in the graph: ";
  cin >> e;
  int src, dest, weight;
  for (int i = 0; i < e; i++)
  {
    // cout << "Enter source and destination of the edge";
    cin >> src >> dest >> weight;
    G.add_edge(src, dest, weight);
  }
  G.print_sizes();
  G.print_graph();
  return 0;
}