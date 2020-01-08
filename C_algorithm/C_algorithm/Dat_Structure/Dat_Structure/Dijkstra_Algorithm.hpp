//
//  Dijkstra_Algorithm.hpp
//  Dat_Structure
//
//  Created by  云子谣 on 2020/1/7.
//  Copyright © 2020  云子谣. All rights reserved.
//

#ifndef Dijkstra_Algorithm_hpp
#define Dijkstra_Algorithm_hpp

#include <stdio.h>

#include <stdio.h>
#include <map>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <limits.h>
#include <typeinfo>

#endif /* Dijkstra_Algorithm_hpp */

using namespace std;
class Dijkstra_Algorithm
{
public:
    
    Dijkstra_Algorithm();
    ~Dijkstra_Algorithm();
    
    //graph
    map<string, map<string, int> > graph;
    
    pair<string, map<string, int> > start;
    pair<string, map<string, int> > A;
    pair<string, map<string, int> > B;
    pair<string,map<string, int> > fin;
    
    
    //cost散列表
    
    map<string, int> costs;
    pair<string, int> A_cost;
    pair<string, int> B_cost;
    pair<string, int> fin_cost;
    
    //parents 散列表
    
    map<string, string> parents;
    pair<string, string> A_parent;
    pair<string, string> B_parent;
    pair<string, string> fin_parent;
    
    vector<string> processed;
    int m_cost;
    //初始化方法
    void Start_initializer();
    void A_initializer();
    void B_initializer();
    void fin_initializer();
    
    void graph_initializer();
    
    void cost_initializer();
    void parents_initialzier();
    void processed_initialzier();
    void print_information();
    
    pair<string, int > find_lowest_cost_node(map<string, int>);
    bool nodeNotInProcessed(string node);
    void findRoad();
    
    
};
