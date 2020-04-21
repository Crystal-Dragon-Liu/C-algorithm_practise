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
private:
    int m_countOfVertex;
    int m_countOfEdge;
    map<int, Vertex *> VertexSet;
    bool isInserted(int v, map<int, Vertex*> VertexSet);
    
//    vector<Vertex *> neighbourVertexs;
};

//
//class SimpleGraph
//{
//public:
//    SimpleGraph(string path);
//    SimpleGraph(int v); // 创建含有V个顶点的图
//    int V(); //获得顶点数
//    int E();//边数
//    void addEdge(int v, int w); //向图中添加一条边 v-w
//    vector<int> adjoin(int v);
//    string  toString(); //对象的字符串表示
//private:
//    int m_V;//顶点数目
//    int m_E;//边数
//    vector< vector<int> > m_adj;
//    void print_adj();
//};
//
//class Vertex
//{
//public:
//    Vertex(int val)
//    {
//        m_value = val;
//        m_number_of_link =0;
//
//    };
//private:
//    int m_value;
//    int m_number_of_link;
//    vector<Vertex* > neighbour;
//
//};
