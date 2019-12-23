#ifndef KCOLORABLE_H_
#define KCOLORABLE_H_

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;


/**
 * Given a graph, find if it is k-colorable or not and print all possible configuration of 
 * assignment of colors to its vertices
 * 
 * the vertex coloring
 * 
 */

namespace KColorableConfig{
struct Edge{
    int src, dest;
};
const int n = 6; // vectex
const int k = 3; // color 

vector<Edge> edges = { {0, 1}, {0, 4}, {0, 5}, {4, 5}, {1, 4}, {1, 3}, {2, 3}, {2, 4}};

vector<int> color(n, 0);

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

string COLORS[] = {"", "BLUE", "GREEN", "RED", "YELLOW", "ORANGE",
				"PINK", "BLACK", "BROWN", "WHITE", "PURPLE"};

// 构建一个color list,索引表示不同节点的值
bool isSafe(Graph const & graph, vector<int>& color, int v, int c){
    for(int u: graph.adjList[v]){
        if(color[u] == c){
            return false;
        }
    }
    return true;
}

void kColorable(Graph const & graph, vector<int>& color, int k, int v, int n){
    if(v == n){
        for(int v =0; v < n; v++){
            cout<<setw(8)<<left<<COLORS[color[v]];
        }
        cout<<endl;
        return;
    }
    for(int c=1; c<=k; c++){
        if(isSafe(graph, color, v, c)){
            color[v] = c;
            kColorable(graph, color, k, v +1, n);
            color[v] = 0;
        }
    }
}

}

#endif // !KCOLORABLE_H_



