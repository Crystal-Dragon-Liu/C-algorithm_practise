//
//  Graph_practise.cpp
//  Dat_Structure
//
//  Created by  云子谣 on 2020/4/10.
//  Copyright © 2020  云子谣. All rights reserved.
//

#include "Graph_practise.hpp"

undirect_Graph::undirect_Graph(string path)
{
    ifstream data(path);
    int dat;
    data >> dat;
    cout << "the count of Vertex : " << dat << " ";
    m_countOfVertex =dat;
    data >> dat;
    cout << "the count of Edge : " << dat << " ";
    m_countOfEdge = dat;
    cout << endl;
//    neighbourVertexs = vector<Vertex *>(m_countOfVertex);
    for(int index = 0; index < m_countOfEdge; index++)
    {
        cout << "读取顶点： " ;
        data >> dat;
        cout << dat << "   ";
        int firstVertex = dat;
        
        cout << "读取顶点： " ;
        data >> dat;
        cout << dat << endl;
        
        
        
        int secondVertex = dat;
        addEdge(firstVertex, secondVertex);
        
    }
    
}
void undirect_Graph::addEdge(int firstVertex, int secondVertex)
{
    
    Vertex *firstVertexNode = new Vertex(firstVertex);
    Vertex *secondVertexNode = new Vertex(secondVertex);
    
    firstVertexNode->neighbours.push_back(secondVertexNode);
    firstVertexNode->in_out++;
    
    secondVertexNode->neighbours.push_back(firstVertexNode);
    secondVertexNode->in_out++;
    
    pair<int, Vertex*> v(firstVertex, firstVertexNode);
    pair<int, Vertex*> w(secondVertex, secondVertexNode);
    if (!isInserted(firstVertex, VertexSet))
    {
        VertexSet.insert(v);
    }
    else
    {
        VertexSet[firstVertex]->neighbours.push_back(secondVertexNode);
        
    }
    if(!isInserted(secondVertex, VertexSet))
    {
        VertexSet.insert(w);
    }
    else
    {
        VertexSet[secondVertex]->neighbours.push_back(firstVertexNode);
    }
    
    
    
}
bool undirect_Graph::isInserted(int v, map<int, Vertex *> VertexSet)
{
    map<int, Vertex*>::iterator iter = VertexSet.begin();
    for(iter; iter != VertexSet.end(); iter++)
    {
        if(iter->first == v)
            return true;
    }
    return false;
}

void undirect_Graph::print_allVertexAndEdge()
{
    map<int, Vertex*>::iterator iter = VertexSet.begin();
    for(iter; iter != VertexSet.end(); iter++)
    {
        cout << "顶点" << iter->first << "的邻节点：";
        for(list<Vertex*>::iterator j = iter->second->neighbours.begin(); j != iter->second->neighbours.end(); j++)
        {
            cout << (*j)->value << " ";
        }
        cout << endl;
    }
    
    
}
