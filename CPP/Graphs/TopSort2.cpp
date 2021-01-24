#include<bits/stdc++.h>
using namespace std;
 
class Graph{
    int V;  // Number of nodes
    vector<int>* adj;   // Adjacency List
    public:
        Graph(int V);   // Constructor Function
        void addEdge(int src, int dest);    // Function to add an edge to the Graph
        void TopSort();
};

// Constructor Function
Graph::Graph(int V){
    this->V = V;
    adj = new vector<int>[V];
}

// Function to add a edge to the Graph
void Graph::addEdge(int src,  int dest){
    adj[src].push_back(dest);
}

// Function to perform Topological Sorting using elimination of zero indegree nodes
void Graph::TopSort(){
    // Array containing the in-degree of all nodes
    vector<int> inDegree(V, 0);

    // Traverse the adjacency list of all nodes to fill the inDegree array
    for(int i=0; i<V; i++){
        vector<int>::iterator itr;  // Iterator for an integer vector
        for(itr = adj[i].begin(); itr != adj[i].end(); itr++)
            inDegree[*itr]++;
    }

    // Create a queue and  enQueue all vertices with inDegree 0
    queue<int> q;
    for(int i=0; i<V; i++)
        if(inDegree[i] == 0)
            q.push(i);

    // Initialize count of visited vertices
    int cnt = 0;

    // Create a vector to store the result
    vector<int> TopSortOrder(V);

    // Dequeue vertices one by one till there is some vertex with inDegree 0
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        TopSortOrder.push_back(u);
        
        vector<int>::iterator itr;
        for(itr = adj[u].begin(); itr != adj[u].end(); itr++)
            if(--inDegree[*itr] == 0)
                q.push(*itr);
        cnt++;
    }

}
 
//  Driver Code
int main(){
    int tc; // Number of test cases
    cout<<"Enter the number of times you want to test the code : ";
    cin>>tc;
    while(tc--){
        int n;  // Number of nodes in Graph
        cout<<"Enter the number of nodes in the graph : ";
        cin>>n;
        // Declare the Graph
        Graph G(n);
        int e; // Number of edges in the Graph
        cout<<"Enter the number of edges in the graph : ";
        cin>>e;
        cout<<"Enter the edges in source -> destination fashion w/o spaces in each line: \n";
        while(e--){
            int source; /* The source from where the edge starts */
            int destination; /* The destination where the edge ends up */
            cin>>source>>destination;
            // G.eddEdge(source, destination);
            G.addEdge(source, destination);
        }
        G.TopSort();
    }
    return 0;    
}