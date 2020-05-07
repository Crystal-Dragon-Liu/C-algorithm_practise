//
//  Graph_practise.cpp
//  Dat_Structure
//
//  Created by  云子谣 on 2020/4/10.
//  Copyright © 2020  云子谣. All rights reserved.

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
map<int, Vertex*> undirect_Graph::getGraphVertexSet()
{
    return VertexSet;
}
int undirect_Graph::countOfVertex()
{
    return m_countOfVertex;
}

DepthFirstGraph::DepthFirstGraph(undirect_Graph uGraph, int s)
{
    marked = vector<bool>(uGraph.countOfVertex(), false);
    cout << "----------DepthFirstSearch start------------" << endl;
    dfs(uGraph, s);
}

void DepthFirstGraph::dfs(undirect_Graph uGraph, int v)
{
    cout << "----------check " << v << " -----------" << endl;
    marked[v] = true;
    count++;
    list<Vertex*> V_uGraphVertexSet = uGraph.getGraphVertexSet()[v]->neighbours;
    
    list<Vertex*>::iterator iter = V_uGraphVertexSet.begin();
    for (iter; iter != V_uGraphVertexSet.end(); iter++)
    {
        
        if(!isMarked((*iter)->value))
        {
            cout << "---------- " << (*iter)->value << " is not marked -----------" << endl;
            dfs(uGraph, (*iter)->value);
        }
           
    }
}
bool DepthFirstGraph::isMarked(int w)
{
    return marked[w];
}
int DepthFirstGraph::getCount()
{
    return count;
}
int DepthFirstGraphForSearchPaths::getStartPoint()
{
    return startPoint;
}

DepthFirstGraphForSearchPaths::DepthFirstGraphForSearchPaths(undirect_Graph uGraph, int s)
{
    marked = vector<bool>(uGraph.countOfVertex(), false);//初始化一个markedvector，每个元素默认没有被访问
    startPoint = s;
    cout << "----------DepthFirstSearch start------------" << endl;
    dfs(uGraph, s);
}

bool DepthFirstGraphForSearchPaths::isMarked(int w)
{
    return marked[w];
}
int DepthFirstGraphForSearchPaths::getCount()
{
    return count;
}

void DepthFirstGraphForSearchPaths::dfs(undirect_Graph uGraph, int v)
{
    cout << "----------check " << v << " -----------" << endl;
    marked[v] = true;
    count++;
    list<Vertex*> V_uGraphVertexSet = uGraph.getGraphVertexSet()[v]->neighbours;
    list<Vertex*>::iterator iter = V_uGraphVertexSet.begin();
    for(iter; iter != V_uGraphVertexSet.end(); iter++)
    {
       if(!isMarked((*iter)->value))
       {
           cout << "---------- " << (*iter)->value << " is not marked -----------" << endl;
           EdgeTo.insert(pair<int, int>((*iter)->value, v));
           dfs(uGraph, (*iter)->value);
       }
    }
}

int DepthFirstGraphForSearchPaths::getEdgeStart(int v)
{
    auto iter = EdgeTo.find(v);
    if(iter != EdgeTo.end())
    {
        return iter->second;
    }
    return -1;
}

void DepthFirstGraphForSearchPaths::printPaths()
{
    map<int, int>::iterator iter = EdgeTo.begin();
    cout << "-----------print edge-----------" <<  endl;
    for(iter; iter != EdgeTo.end(); iter++)
    {
        cout << (*iter).first << "<---" << (*iter).second << endl;
    }
}


bool DepthFirstGraphForSearchPaths::hasPathTo(int v)
{
    return isMarked(v);
}

stack<int> DepthFirstGraphForSearchPaths::pathStore(int v)
{
    stack<int> pathstore;
    if(!isMarked(v)) return stack<int>();
    for(int x = v; x != getStartPoint(); x = getEdgeStart(x))
    {
        pathstore.push(x);
    }
    pathstore.push(getStartPoint());
    return pathstore;
}
