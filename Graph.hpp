// Id: 315284554 ,Email : gilada8892@gmail.com

#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <vector>
#include <iostream>
namespace ariel{
    class Graph {
        private:
        std::vector<std::vector<int>> graphMatrix;
        int verticesCount;
        int edgesCount;
        bool isDirected;
        bool isWeighted;

        public:
        Graph();
        //output stream;
        friend std::ostream& operator<<(std::ostream& output,  Graph& graph);
        //adition;
        friend Graph operator+(Graph& graph1, Graph& graph2);
        Graph& operator+(int scalar);
        Graph& operator+=(Graph& other);
        Graph& operator++();
        Graph& operator++(int);
        Graph& operator+();

        //subtraction;
        friend Graph operator-(Graph& graph1, Graph& graph2);
        Graph& operator-(int scalar);
        Graph& operator-=(Graph& other);
        Graph& operator--();
        Graph& operator--(int);
        Graph& operator-();


        //multipcation;
        friend Graph operator*(Graph& graph1, Graph& graph2);
        Graph& operator*=(int scalar);
        Graph& operator/=(int scalar);
        //comprasion;
        friend bool operator==(Graph& graph1, Graph& graph2);
        bool operator!=(Graph& graph1);
        bool operator>(Graph& graph1);
        bool operator>=(Graph& graph1);
        bool operator<(Graph& graph1);
        bool operator<=(Graph& graph1);


       //helpers , getters an setters;
        bool isSubGraph(Graph& g1 , Graph& g2);
        void loadGraph(std::vector<std::vector<int>> &graph);
        std::string printGraph();
        int getNumVertices();
        int getEdgesCount();
        bool getIsDirected();
        bool getIsWeighted();
        std::vector<std::vector<int>>& getMatrix();
    };
}
#endif