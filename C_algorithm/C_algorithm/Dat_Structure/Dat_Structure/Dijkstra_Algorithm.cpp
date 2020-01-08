//
//  Dijkstra_Algorithm.cpp
//  Dat_Structure
//
//  Created by  云子谣 on 2020/1/7.
//  Copyright © 2020  云子谣. All rights reserved.
//

#include "Dijkstra_Algorithm.hpp"


using namespace std;

void Dijkstra_Algorithm::Start_initializer()
{
    pair<string, int> start_element_A{"A", 6};
    
    pair<string, int> start_element_B{"B", 2};
    
    map<string , int> start_element;
    start_element.insert(start_element_A);
    start_element.insert(start_element_B);
    start = {"start", start_element};
    
}

void Dijkstra_Algorithm::A_initializer()
{
    pair<string, int> A_element{"fin", 1};
    map<string, int> A_elements;
    A_elements.insert(A_element);
    
    A = {"A", A_elements};
    
}

void Dijkstra_Algorithm::B_initializer()
{
    
    pair<string, int> B_element_1{"A", 3};
    pair<string, int> B_element_2{"fin", 5};
    map<string, int> B_elements;
    B_elements.insert(B_element_1);
    B_elements.insert(B_element_2);
    
    B = {"B", B_elements};
    
    

}
void Dijkstra_Algorithm::fin_initializer()
{
//    pair<string, int> fin_nei{"nothing",NULL};
//    map<string, int> fin_nei_n;
//    fin_nei_n.insert(fin_nei);
//    fin = {"fin",fin_nei_n};
    fin = {"fin", {}};
}

void Dijkstra_Algorithm::graph_initializer()
{
    
    Start_initializer();
    A_initializer();
    B_initializer();
    fin_initializer();
    graph.insert(start);
    graph.insert(A);
    graph.insert(B);
    graph.insert(fin);
}
void Dijkstra_Algorithm::cost_initializer()
{
    A_cost = {"A", 6};
    B_cost = {"B", 2};
    fin_cost = {"fin", 10000};
    costs.insert(A_cost);
    costs.insert(B_cost);
    costs.insert(fin_cost);
    
}

void Dijkstra_Algorithm::parents_initialzier()
{
    A_parent = {"A", "start"};
    B_parent = {"B", "start"};
    fin_parent = {"fin", "unknown"};
    
    parents.insert(A_parent);
    parents.insert(B_parent);
    parents.insert(fin_parent);
    
    
}
void Dijkstra_Algorithm::processed_initialzier()
{
    processed={};
    
}
Dijkstra_Algorithm::Dijkstra_Algorithm()
{
    
    graph_initializer();
    cost_initializer();
    parents_initialzier();
    processed={"no one"};
    
}


void Dijkstra_Algorithm::print_information()
{
//cout << "-----graph-----" << endl;
//    cout << "node_1 of the graph :  start" << endl;
//    cout << "A----weight is " << endl;
//    cout << graph["start"]["A"] << endl;
//    cout << "B----weight is " << endl;
//    cout << graph["start"]["B"] << endl;
//
//   // cout << typeid(graph["A"]).name() << endl;
//
//
//    cout << "node_2 of the graph :  A" << endl;
//    cout << "final----weight is " << endl;
//    cout << graph["A"]["fin"] << endl;
//
//    cout << "node_3 of the graph :  B" << endl;
//    cout << "A----weight is " << endl;
//    cout << graph["B"]["A"] << endl;
//    cout << "fin----weight is " << endl;
//    cout << graph["B"]["fin"] << endl;
//
//    cout << "node_4 of the graph :  fin" << endl;
//    cout << "fin's ----neighbors is " << endl;
//    cout << graph["fin"][""] << endl;
    cout << "----costs----" << endl;
    cout << costs["A"] << endl;
    cout << costs["B"] << endl;
    cout << costs["fin"] << endl;
    
    
    
}
bool Dijkstra_Algorithm::nodeNotInProcessed(string node)
{
    for(vector<string>::iterator iter = processed.begin(); iter <= processed.end(); iter++)
    {
        //cout << *iter << endl;
        //cout << node << endl;
        if(*iter == node)
            return false;
           
    }
    return true;
}


pair<string,int > Dijkstra_Algorithm::find_lowest_cost_node(map<string, int> costs)
{
    
    
    int lowest_cost = 10000;
    pair<string, int> lowest_cost_node = {"None",NULL};
    map<string, int>::iterator cost_iter;
    
    
    
    
    for (cost_iter = costs.begin(); cost_iter != costs.end(); cost_iter++
)
    {
        m_cost = cost_iter->second;//获取到达该节点的权重
        if (m_cost < lowest_cost and nodeNotInProcessed(cost_iter->first))
        {
            lowest_cost = m_cost;
            lowest_cost_node = *cost_iter;
            
        }
    }
    return lowest_cost_node;
    
    
}


void Dijkstra_Algorithm::findRoad()
{
    pair<string, int> node;
    
    map<string, int> neighbors;
    
    int DA_cost;
    
   
    
    //string node_name;
    
    node = find_lowest_cost_node(costs);
    cout << "the lowest cost node : "<< endl;
    cout << node.first<< endl;
    cout << "-----------------------" << endl;
    
    
    while (node.first != "None")
    {
        //costs
     
           
        DA_cost = node.second;
        cout << "the lowest cost node's weight :  " << endl;
        cout << DA_cost << endl;
        //node_name = node.first;
        //neighbors = graph[""];
        neighbors = graph[node.first];
        
        cout << "the neighbors of the node :" << endl;
        
        for(map<string, int>::iterator i = neighbors.begin(); i != neighbors.end(); i++)
        {
            int new_cost;
            
            new_cost = DA_cost + neighbors[(*i).first];
            if(costs[(*i).first] > new_cost)
            {
                costs[(*i).first] = new_cost;
                parents[(*i).first] = node.first;
                
                cout << costs["A"] << endl;
                cout << costs["B"] << endl;
                cout << costs["fin"] << endl;
            }
            
            
            
        }
        processed.push_back(node.first);
        node = find_lowest_cost_node(costs);
        
        //costs
           cout << costs["A"] << endl;
           cout << costs["B"] << endl;
           cout << costs["fin"] << endl;
           
           // processed
           
           for(vector<string>::iterator it = processed.begin();it <= processed.end(); it++)
           {
               
               cout << *it << endl;
           }
           
        
        
    }
    
    cout << parents["A"] << endl;
    cout << parents["B"] << endl;
    cout << parents["fin"] << endl;
    
    
}

