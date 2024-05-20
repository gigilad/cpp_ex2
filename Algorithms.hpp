// Id: 315284554 ,Email : gilada8892@gmail.com

#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP
#include "Graph.hpp"
#include <vector>
#include <stack>
#include <string>

using namespace std;

namespace ariel {
    class Algorithms{
        public:
        static bool isConnected(Graph& graph);
        static string shortestPath(Graph& graph,int start, int end);
        static bool isContainsCycle(Graph& graph);
        static string isBipartite(Graph &graph);
        static void negativeCycle(Graph &graph);
        static bool dfsUtil(const vector<vector<int>>& matrix, vector<bool>& visited, vector<int>& parent, int node, int parentNode);
    };
}
#endif