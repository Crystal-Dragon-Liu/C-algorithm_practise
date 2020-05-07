//
//  Graph_practise.hpp
//  Dat_Structure
//
//  Created by  云子谣 on 2020/4/10.
//  Copyright © 2020  云子谣. All rights reserved.
//

#ifndef Graph_practise_hpp
#define Graph_practise_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <set>
#include <list>
#include <stack>
using namespace std;
#endif /* Graph_practise_hpp */

//顶点类
class Vertex
{
public:
    Vertex(int val)
    {
        in_out = 0;
        value = val;
    };
    int value;
    int in_out;
    list<Vertex *> neighbours;
};


class undirect_Graph
{
public:
    undirect_Graph(string path);
    int countOfVertex();  //获得顶点数
    int countOfEdge();  // 边数
    void addEdge(int firstVertex, int secondVertex);
    void print_allVertexAndEdge();
    map<int, Vertex*> getGraphVertexSet();
private:
    int m_countOfVertex;
    int m_countOfEdge;
    map<int, Vertex *> VertexSet;
    bool isInserted(int v, map<int, Vertex*> VertexSet);
    
//    vector<Vertex *> neighbourVertexs;
};


class DepthFirstGraph
{
public:
    DepthFirstGraph(undirect_Graph uGraph, int s);
    bool isMarked(int w);
    int getCount();
private:
    vector<bool> marked;
    int count;
    void dfs(undirect_Graph uGraph, int v);
};


class DepthFirstGraphForSearchPaths
{
public:
    DepthFirstGraphForSearchPaths(undirect_Graph uGraph, int s);
    bool isMarked(int w);
    int getCount();
    int getStartPoint();
    int getEdgeStart(int v);
    void printPaths();
    bool hasPathTo(int v);
    stack<int> pathStore(int v);
private:
    map<int, int> EdgeTo;//记录每个顶点第一次被谁访问
    vector<bool> marked;
    int count;
    int startPoint;
    void dfs(undirect_Graph uGraph, int v);
    
    
};
