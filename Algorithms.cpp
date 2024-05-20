// Id: 315284554 ,Email : gilada8892@gmail.com
#include "Algorithms.hpp"
#include "Graph.hpp"
#include <vector>
#include <queue>
#include <iostream>
#include <limits>
#include <limits.h>
#include <string>

#include <stack>
#define INF INT_MAX
using namespace std;

namespace ariel{    
    string Algorithms::shortestPath(Graph& graph, int start , int end){
    int vertixSize = graph.getMatrix().size();

    // Initialize distance array and parent array
    std::vector<int> distArr(vertixSize, std::numeric_limits<int>::max());
    std::vector<int> parent(vertixSize, -1);

    // Initialize the distance from the start vertex to itself as 0
    distArr[start] = 0; 

    // Relax all edges |V| - 1 times
    for(int i = 0; i < vertixSize - 1; i++){
        for(int u = 0; u < vertixSize; u++){
            for(int v = 0; v < vertixSize; v++){
                if(graph.getMatrix()[u][v] != 0 && distArr[u] != INT_MAX && distArr[u] + graph.getMatrix()[u][v] < distArr[v]){
                    distArr[v] = distArr[u] + graph.getMatrix()[u][v];
                    parent[v] = u;
                }
            }
        }
    }

    // Check for negative weight cycles
    for(int u = 0; u < vertixSize; u++){
        for(int v = 0; v < vertixSize; v++){
            if(graph.getMatrix()[u][v] != 0 && distArr[u] != INT_MAX && distArr[u] + graph.getMatrix()[u][v] < distArr[v]){
                std::cout << "Graph contains negative weight cycle" << std::endl;
                return "-1";
            }
        }
    }

    // If distArr[end] != INF, there is a path from start vertex to end vertex
    if(distArr[end] != std::numeric_limits<int>::max()){
        // Print the shortest path from start vertex to end vertex
        std::vector<int> shortestPath;
        std::string path;
        for(int i = end; i != -1; i = parent[i]){
            shortestPath.push_back(i);
        }

        for(int j = shortestPath.size() - 1; j >= 0; j--){
            path += std::to_string(shortestPath[j]);
            if(j != 0){
                path+="->";
            }
        }
        return path;
    } else {
        // No path exists
        std::cout << "No Path" << std::endl;
        return "-1";
    }
    return "-1";

    }

    bool Algorithms::isConnected(Graph& graph){
    int verticesNum = graph.getNumVertices();
    vector<vector<int>> matrix = graph.getMatrix();
    vector<bool> visi(verticesNum, false);
    
    // Declaring visited vector and q queue outside of the loop
    vector<bool> visited(verticesNum, false);
    queue<int> q;

    for (int j = 0; j < verticesNum; j++){
        visited.assign(verticesNum, false);
        q = queue<int>();
        visited[j] = true;
        q.push(j);

        while(!q.empty()){
            int currentVer = q.front();
            q.pop();
            for (int i = 0; i < verticesNum; i++){
                if(matrix[currentVer][i] && !visited[i]){
                    q.push(i);
                    visited[i] = true;
                }
            }
        }

        // now we want to make sure that all visited is filled with true!
        bool isConnected = true;
        for(bool vec : visited){
            if(!vec){
                isConnected = false;
                break;
            }
        }
        visi[j]= isConnected;
    }
    
    for(int v = 0; v<verticesNum; v++){
        if(!visi[v]){
            std::cout << "Graph is not strongly connected!" << std::endl;
            return false;
        }
    }
    std::cout << "Graph is strongly connected!" << std::endl;
    return true;
    }

   bool Algorithms::isContainsCycle(Graph& graph) {
    vector<vector<int>> matrix = graph.getMatrix();
    int vSize = matrix.size();
    vector<bool> visited(vSize, false);
    vector<int> parent(vSize, -1);
    
    // We run DFS from every vertex and look for a cycle
    for (int i = 0; i < vSize; i++) {
        if (!visited[i] && dfsUtil(matrix, visited, parent, i, -1))
            return true;
    }
    
    cout << "No cycle found" << endl;
    return false;
   }
   
    bool Algorithms::dfsUtil(const vector<vector<int>>& matrix, vector<bool>& visited, vector<int>& parent, int node, int parentNode){
    // updating the visited and parent vector<int>
    visited[node] = true;
    parent[node] = parentNode;
   // looking for edge to another vertex
    for (int i = 0; i < matrix.size(); i++) {
        if (matrix[node][i] != 0) {
            if (!visited[i]) {
                if (dfsUtil(matrix, visited, parent, i, node))
                    return true;
    // its mean we visited at this vertex already so we found a cycle:    
            } else if (i != parentNode) {
                cout << "Cycle detected:" << endl;
                stack<int> cycle;
                cycle.push(i);
                for (int v = node; v != i; v = parent[v]) {
                    cycle.push(v);
                }
                cycle.push(i);

                while (!cycle.empty()) {
                    cout << cycle.top();
                    cycle.pop();
                    if (!cycle.empty())
                        cout << " -> ";
                }
                cout << endl;
                return true;
            }
        }
    }
    return false;


    }
    
    string Algorithms::isBipartite(Graph &graph) {
    int V = graph.getMatrix().size();
    vector<int> color(V, -1);
    
    // Traverse all vertices
    for (int i = 0; i < V; i++) {
        // If the current vertex is not colored
        if (color[i] == -1) {
            color[i] = 1; // Color the current vertex

            // Create a queue for BFS
            queue<int> q;
            q.push(i);

            // BFS to color the vertices
            while (!q.empty()) {
                int u = q.front();
                q.pop();

                // Visit all adjacent vertices of u
                for (int v = 0; v < V; v++) {
                    // If there is an edge from u to v and v is not colored
                    if (graph.getMatrix()[u][v] && color[v] == -1) {
                        // Assign alternate color to this adjacent v of u
                        color[v] = 1 - color[u];
                        q.push(v);
                    }
                    // If there is an edge from u to v and both u and v have same color
                    else if (graph.getMatrix()[u][v] && color[v] == color[u]) {
                        return "0";
                    }
                }
            }
        }
    }

        if (color.size() > 0 && color[0] != -1) {
            string path ="The graph is bipartite: ";
            vector<int> group1, group2;
                for (int i = 0; i < V; i++) {
                    if (color[i] == 0)
                        group1.push_back(i);
                    else
                        group2.push_back(i);
                }
                path+= "A={";
                for (int i = 0; i < group2.size()-1; i++)
                    path +=to_string(group2[i])+", ";
                path+=to_string(group2[group2.size()-1])+"}, ";
                path+= "B={";
                for (int i = 0; i < group1.size()-1; i++)
                    path +=to_string(group1[i])+ ", ";
                path+=to_string(group1[group1.size()-1])+"}";

              cout<<path<<endl;
    return path;
    }
    return "0";
}
 
    void Algorithms::negativeCycle(Graph &graph){
     int vertixSize = graph.getMatrix().size();

    // Initialize distance array and parent array
    std::vector<int> distArr(vertixSize, INT_MAX);
    std::vector<int> parent(vertixSize, -1);

    // Initialize the distance from the start vertex to itself as 0
    distArr[0] = 0; 

    // Relax all edges |V| - 1 times
    for(int i = 0; i < vertixSize - 1; i++){
        for(int u = 0; u < vertixSize; u++){
            for(int v = 0; v < vertixSize; v++){
                if(graph.getMatrix()[u][v] != 0 && distArr[u] != INT_MAX && distArr[u] + graph.getMatrix()[u][v] < distArr[v]){
                    distArr[v] = distArr[u] + graph.getMatrix()[u][v];
                    parent[v] = u;
                }
            }
        }
    }

    // Check for negative weight cycles
    for(int u = 0; u < vertixSize; u++){
        for(int v = 0; v < vertixSize; v++){
            if(graph.getMatrix()[u][v] != 0 && distArr[u] != INT_MAX && distArr[u] + graph.getMatrix()[u][v] < distArr[v]){
              //using stack to reverse the cycle;
               stack<int> negativeCycle = stack<int>();           
                int j = u ;
                cout<< j << " -> ";
                for (int i = parent[j]; i != j; i=parent[i]){
                    negativeCycle.push(i);
                }
                while(!negativeCycle.empty()){
                      cout << negativeCycle.top()<< " -> " ;
                      negativeCycle.pop();
                }
                cout<< j << endl;
                std::cout << "Graph contains negative weight cycle" << std::endl;
                return;
                
            }
        }
    }
    cout<<"no negative cycle " << endl;

    }
 
 
 
 
 }