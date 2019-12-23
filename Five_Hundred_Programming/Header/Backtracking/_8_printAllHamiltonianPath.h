#ifndef PRINTALLHAMILTONIAN_H_
#define PRINTALLHAMILTONIAN_H_

#include <iostream>
#include <vector>
using namespace std;

/**
 * Given an undirected graph, print all Hamiltonian paths present in it. Hamiltonian path 
 * is a path in an undirected graph that visits each vertex exactly once.
 */

namespace PrintHamiltonian{
struct Edge{
int src, dest;
};

// ONLY for C++11
vector<Edge> edges = {
    {0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}
};
const int start =0;
const int n = 4;


class Graph{
    public:
    vector<vector<int> > adjList;

    // constructor
    Graph(vector<Edge> const & edges, int n){
        adjList.resize(n);

        // add edges to the undirected graph
        for(unsigned i =0; i< edges.size(); i++){
            int src = edges[i].src;
            int dest = edges[i].dest;

            adjList[src].push_back(dest);
            adjList[dest].push_back(src);
        }
    }
};

Graph g(edges, n);


void printAllHamiltonianPaths(Graph const& g, int v, vector<bool> visited,
    vector<int> & path, int n){
    
    if(path.size() == n){
        for(int i :path){
            cout<<i << " ";
        }
        cout<<endl;
        return;
    }
    
    for(int w: g.adjList[v]){
        if(!visited[w]){
            visited[w] = true;

            path.push_back(w);

            printAllHamiltonianPaths(g, w, visited,path, n);

            path.pop_back();
            visited[w] = false;
        }
    }
}


} // namespace PrintHamiltonian





#endif // !PRINTALLHAMILTONIAN_H_