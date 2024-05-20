#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;
TEST_CASE("Test equal and not equal operators"){
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);

   ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g2.loadGraph(graph2);
    CHECK(g1==g2);
   ariel::Graph g3;
   g3 = g1 + g2;
   CHECK(g3 != g2);
}

TEST_CASE("Test graph addition")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(graph2);
    ariel::Graph g3 = g1 + g2;

    vector<vector<int>> graph4 = {
        //this is the sum of g1+g2;
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
        ariel::Graph g4;
    g4.loadGraph(graph4);
    CHECK(g3 == g4);
    g4 += g3;
    ariel::Graph g5;
    vector<vector<int>> graph5={
        {0, 4, 2},
        {4, 0, 6},
        {2, 6, 0}
    };
    g5.loadGraph(graph5);
    CHECK(g4==g5);

    g5++;
    ariel::Graph g6;
    vector<vector<int>> graph6={
        {0, 5, 3},
        {5, 0, 7},
        {3, 7, 0}
    };
    g6.loadGraph(graph6);

    CHECK(g6 == g5);


    ++g4;
    CHECK(g4 == g5);

    g4 = g4 +2;
    g5 = g5 +2;

    CHECK(g4==g5);

}

TEST_CASE("Test graph subtraction"){
        ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0, 4},
        {1, 0, 1, 5},
        {0, 1, 0, 3},
        {1, 2, 3, 0}};
    g1.loadGraph(graph);

   ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 2},
        {1, 0, 0, 3},
        {0, 1, 1, 2},
        {1, 0, 2, 0}};
    g2.loadGraph(graph2);
    ariel::Graph g4;
    g4 = g1-g2;

   ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {0, 0, 0, 2},
        {0, 0, 1, 2},
        {0, 0, -1, 1},
        {0, 2, 1, 0}};
    g3.loadGraph(graph3);
    CHECK(g3 == g4);

    g4 = g4-2;
    g3 = g3-2;
    CHECK(g3 == g4);

    --g3;
    --g4;
    CHECK(g3 == g4);

    g4 -= g3;
    ariel::Graph g5;
    vector<vector<int>> graph5 = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}};
    g5.loadGraph(graph5);
    CHECK(g4 == g5);
}
TEST_CASE("Test graph multiplication")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;

    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);

    ariel::Graph g4 = g1 * g2;
    ariel::Graph g5;
    vector<vector<int>> expectedGraph = {
        {1, 0, 2},
        {1, 3, 1},
        {1, 0, 2}};
        g5.loadGraph(expectedGraph);

        CHECK(g5 == g4);

    g4*=3;
    ariel::Graph g6;
    vector<vector<int>> expectedg = {
        {3, 0, 6},
        {3, 9, 3},
        {3, 0, 6}};
    g6.loadGraph(expectedg);
    CHECK(g4 == g6);
    g4/=3;
    CHECK(g4 == g5);


}

TEST_CASE("Test > ,<, >=, <="){
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0, 4},
        {1, 0, 1, 2},
        {0, 2, 0, 3},
        {1, 3, 4, 0}};
    g1.loadGraph(graph);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 2, 0}
       };
    g2.loadGraph(graph2);
    CHECK(g2 <= g1);
    CHECK(g2 < g1);
    CHECK(g1 >= g2);
    CHECK(g1 > g2);
    g2 = g2 + 1;

    ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {0, 2, 3, 4},
        {1, 0, 1, 2},
        {0, 2, 0, 3},
        {1, 3, 4, 0}};
    g3.loadGraph(graph3);

    ariel::Graph g4;
    vector<vector<int>> graph4 = {
        {0, 1, 0, 4},
        {1, 0, 1, 2},
        {0, 2, 0, 3},
        {0, 0, 0, 0}};
    g4.loadGraph(graph4);
    // no graph is subgraph of the other
    //graph3 > graph4 beacuse he have more edges;
    CHECK(g3>g4);
    CHECK(g3!=g4);

}


TEST_CASE("Invalid operations")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1, 1},
        {1, 0, 2, 1},
        {1, 2, 0, 1},
        {1, 2, 0, 1}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g5;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS(g5 * g1);
    CHECK_THROWS(g1 * g2);

    // Addition of two graphs with different dimensions
    ariel::Graph g6;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g6.loadGraph(graph3);
    CHECK_THROWS(g1 + g6);
}