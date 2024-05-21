// Id: 315284554 ,Email : gilada8892@gmail.com

#include "Graph.hpp"
#include <iostream>
using namespace std;
namespace ariel{
    Graph::Graph() : verticesCount(0),isDirected(false),isWeighted(false),edgesCount(0){}

    std::ostream& operator<<(std::ostream& output,  Graph& graph) {
        vector<vector<int>>& matrix = graph.getMatrix();
        for (size_t i = 0; i < matrix.size(); i++){
        output <<"[";
            for (size_t j = 0; j < matrix.size(); j++)
            {
                if(j!=0){output<<", ";}
                output<<matrix[i][j];
            }
            output << "] \n";
        }
        return output;
    }

    Graph operator+(Graph& graph1, Graph& graph2) {
        vector<vector<int>>& matrix1 = graph1.getMatrix();
        vector<vector<int>>& matrix2 = graph2.getMatrix();
        Graph result;
        if(matrix1.size() != matrix2.size() || matrix1[0].size() != matrix2[0].size()){
            throw invalid_argument("graph are not from the same size");
        }
        vector<vector<int>> resultMatrix(matrix1.size(), vector<int>(matrix1[0].size(), 0));
        for (int i = 0; i < matrix1.size(); i++){
            for (int j = 0; j < matrix1[0].size(); j++){
                resultMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        result.loadGraph(resultMatrix);
    return result;
    }

    Graph operator-(Graph& graph1, Graph& graph2) {
        vector<vector<int>>&  matrix1 = graph1.getMatrix();
        vector<vector<int>>& matrix2 = graph2.getMatrix();
        Graph result;
        if(matrix1.size() != matrix2.size() || matrix1[0].size() != matrix2[0].size()){
            throw invalid_argument("graph are not from the same size");
        }
        vector<vector<int>> resultMatrix(matrix1.size(), vector<int>(matrix1[0].size(), 0));
        for (int i = 0; i < matrix1.size(); i++){
            for (int j = 0; j < matrix1[0].size(); j++){
                resultMatrix[i][j] = matrix1[i][j] - matrix2[i][j];
            }
        }
        result.loadGraph(resultMatrix);
    return result;
    }

    Graph operator*(Graph& graph1, Graph& graph2){
        Graph g3;
        vector<vector<int>>& matrix1 = graph1.getMatrix();
        vector<vector<int>>& matrix2 = graph2.getMatrix();
        if(matrix1.size()!= matrix2.size()){
            throw invalid_argument("graph are not from the same size");
        }
        vector<vector<int>> g3Matrix(matrix1.size(), vector<int>(matrix1[0].size(), 0));
        for (size_t i = 0; i < matrix1.size(); i++){
            for (size_t j = 0; j < matrix1.size(); j++){
                for (size_t k = 0; k< matrix1.size(); k++) {
                    g3Matrix[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
            }
            g3.loadGraph(g3Matrix);
            return g3;
        }


    Graph& Graph::operator+(){
        return *this;
    }
    Graph& Graph::operator-(){
    vector<vector<int>>& gMatrix = this->getMatrix();
        for (size_t i = 0; i < gMatrix.size(); i++){
            for (size_t j = 0; j < gMatrix.size(); j++)
            {gMatrix[i][j] *= -1;
            }
        }
        return *this;
    };

    Graph& Graph::operator++(){
        vector<vector<int>>& gMatrix = this->getMatrix();
        for (size_t i = 0; i < gMatrix.size(); i++){
            for (size_t j = 0; j < gMatrix.size(); j++)
            {
               if(gMatrix[i][j] != 0){
                   ++gMatrix[i][j];
                }
            }
        }
        return *this;
    }

    Graph& Graph::operator++(int){
        vector<vector<int>>& gMatrix = this->getMatrix();
        for (size_t i = 0; i < gMatrix.size(); i++){
            for (size_t j = 0; j < gMatrix.size(); j++)
            {
               if(gMatrix[i][j] != 0){
                   gMatrix[i][j]++;
                }
            }
        }
        return *this;
    }

    Graph& Graph::operator--(){
        vector<vector<int>>& gMatrix = this->getMatrix();
        for (size_t i = 0; i < gMatrix.size(); i++){
            for (size_t j = 0; j < gMatrix.size(); j++)
            {
                if(gMatrix[i][j] != 0){
                   --gMatrix[i][j];
                }
            }
        }
        return *this;
    }

    Graph& Graph::operator--(int){
        vector<vector<int>>& gMatrix = this->getMatrix();
        for (size_t i = 0; i < gMatrix.size(); i++){
            for (size_t j = 0; j < gMatrix.size(); j++)
            {
                if(gMatrix[i][j] != 0){
                   gMatrix[i][j]--;
                }
            }
        }
        return *this;
    }

    bool operator==(Graph& graph1,Graph& graph2){
        vector<vector<int>>& g1Matrix = graph1.getMatrix();
        vector<vector<int>>& g2Matrix = graph2.getMatrix();
        if(g1Matrix.size()!= g2Matrix.size()){
            return false;
        }
        for (size_t i = 0; i < g2Matrix.size(); i++){
            for (size_t j = 0; j < g2Matrix.size(); j++)
            {
                if(g1Matrix[i][j] != g2Matrix[i][j]) return false;
            }
        }
        return true;
    }

    bool Graph::operator!=(Graph& graph1){
        return !(*this == graph1);

    }

    Graph& Graph::operator+=(Graph& graph){
        vector<vector<int>>& matrixToAdd =this->getMatrix();
        vector<vector<int>>& matrix2 =graph.getMatrix();
        if(matrixToAdd.size() != matrix2.size() || matrixToAdd[0].size() != matrix2[0].size()){
            throw invalid_argument("graph are not from the same size");
        }
        for (size_t i = 0; i < matrixToAdd.size() ; i++){
            for (size_t j = 0; j < matrixToAdd.size() ; j++){
                matrixToAdd[i][j] +=  matrix2[i][j];
            }
        }
        return *this;
    }

    Graph& Graph::operator-=(Graph& graph){
        vector<vector<int>>& matrix =this->getMatrix();
        vector<vector<int>>& matrix2 =graph.getMatrix();
        if(matrix.size() != matrix2.size() || matrix[0].size() != matrix2[0].size()){
            throw invalid_argument("graph are not from the same size");
        }
        for (size_t i = 0; i < matrix.size() ; i++){
            for (size_t j = 0; j < matrix.size() ; j++){
                matrix[i][j] -=  matrix2[i][j];
            }
        }
        return *this;
    }

    Graph& Graph::operator*=(int scalar){
        vector<vector<int>>& matrixToMult = this->getMatrix();
        for (size_t i = 0; i < matrixToMult.size(); i++) {
            for (size_t j = 0; j < matrixToMult.size() ; j++){
                matrixToMult[i][j] *=  scalar;
            }
        }
        return *this;
    }

    Graph& Graph::operator/=(int scalar){
        vector<vector<int>>& matrixToMult = this->getMatrix();
        for (size_t i = 0; i < matrixToMult.size(); i++) {
            for (size_t j = 0; j < matrixToMult.size() ; j++){
                matrixToMult[i][j] /=  scalar;
            }
        }
        return *this;
    }

    bool Graph::operator>(Graph& graph2){
        if(!isSubGraph(graph2,*this)){
            if(this->getEdgesCount() > graph2.getEdgesCount()){
                return true;
            }else{
                return (this->getNumVertices() > graph2.getNumVertices());
            }
        }
        return true;
    }

   bool Graph::operator>=(Graph& graph2){
    if(*this == graph2){
        return true;
    }
    return (*this>graph2);
   }

   bool Graph::operator<=(Graph& graph2){
    return !(*this > graph2);
   }

   bool Graph::isSubGraph(Graph& g1 , Graph& g2){
    //g1 cant be subgraph if g1 bigger then g2;
    if(g1.getNumVertices() > g2.getNumVertices()){
        return false;
    }
    vector<vector<int>>& matrix1 = g1.getMatrix();
    vector<vector<int>>& matrix2 = g2.getMatrix();
    // checking if g1 is subgraph of g2;
    for (size_t i = 0; i < g1.getNumVertices(); i++){
        for (size_t j = 0; j < g1.getNumVertices(); j++){
            if(matrix1[i][j] && matrix2[i][j]==0){
        return false;
        }
    }
   }
   return true;
   }

   bool Graph::operator<(Graph& graph2){
    return !(*this >= graph2);
   }

   Graph& Graph::operator+(int scalar){
    vector<vector<int>>& matrix = this->getMatrix();
    for (size_t i = 0; i < matrix.size(); i++){
        for (size_t j = 0; j < matrix.size(); j++)
            {
                if(matrix[i][j] != 0){
                   matrix[i][j] += scalar;
                }
            }
        }
        return *this;
  }

    Graph& Graph::operator-(int scalar){
    vector<vector<int>>& matrix = this->getMatrix();
    for (size_t i = 0; i < matrix.size(); i++){
        for (size_t j = 0; j < matrix.size(); j++)
            {
                if(matrix[i][j] != 0){
                   matrix[i][j] -= scalar;
                }
            }
        }
        return *this;
  }

    void Graph::loadGraph(std::vector<std::vector<int>> &graph){
        verticesCount=graph.size();
        int col = graph[0].size();
        if(col == verticesCount){
        graphMatrix=graph;
        edgesCount=0;
        for (size_t i = 0; i < verticesCount; i++){
            for (size_t j = 0; j < verticesCount; j++){
                if(graphMatrix[i][j]!=0){
                    ++edgesCount;
                }
                if(graphMatrix[i][j]!=graphMatrix[j][i]){
                    isDirected=true;
                }
                if(graphMatrix[i][j]>1){
                    isWeighted=true;
                }
            }
        }

        }else{
            throw std::invalid_argument("Invalid graph");
        }



    }

    string Graph::printGraph(){
        vector<vector<int>>& matrix = this->getMatrix();
        string output ="";
        for (size_t i = 0; i < matrix.size(); i++){
        output +="[";
            for (size_t j = 0; j < matrix.size(); j++)
            {
                if(j!=0){output+=", ";}
                output+=to_string(matrix[i][j]);
            }
            output += "]\n";
        }
        return output;
    }

    int Graph::getNumVertices(){
        return verticesCount;
    }
    int Graph::getEdgesCount(){
        return edgesCount;
    }

    bool Graph::getIsDirected(){
        return isDirected;
    }

    bool Graph::getIsWeighted(){
        return isWeighted;
    }

    std::vector<std::vector<int>> &Graph::getMatrix(){
        return graphMatrix;
    }

};