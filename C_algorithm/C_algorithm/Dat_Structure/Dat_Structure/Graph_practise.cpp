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


BreadthFirstPaths::BreadthFirstPaths(undirect_Graph uGraph, int s)
{
    marked = vector<bool>(uGraph.countOfVertex(), false);
    startPoint = s;
    bfs(uGraph, startPoint);
}

void BreadthFirstPaths::bfs(undirect_Graph uGraph, int s)
{
    queue<int> NeighbourNotMarked;
    //将起点先加入队列
    marked[s] = true;
    NeighbourNotMarked.push(s);
    //开始广度优先搜索
    while(!NeighbourNotMarked.empty()) //队列为空就意味着，已经连通图没有未被标记的顶点了
    {
        
        int v = NeighbourNotMarked.front();//获得队列当中第一个顶点
        cout << "-------------the first Vertex " << v << " in Queue will be deleted-------------" << endl;
        NeighbourNotMarked.pop();//把第一个顶点从队列删除，因为它已经被标注，并且它的邻接点马上要被check
        list<Vertex*> V_uGraphVertexSet = uGraph.getGraphVertexSet()[v]->neighbours;
        //获得v顶点的邻接表
        list<Vertex*>::iterator iter = V_uGraphVertexSet.begin();
        for(iter; iter != V_uGraphVertexSet.end(); iter++)
        {
            if(!isMarked((*iter)->value))
            {
                EdgeTo.insert(pair<int, int>((*iter)->value, v));
                marked[(*iter)->value] = true;
                NeighbourNotMarked.push((*iter)->value);
                cout << (*iter)->value << "has been pushed into the Queue we created  " << endl;
            }
        }
        
    }
    cout << "Queue is empty!" << endl;
}

bool BreadthFirstPaths::isMarked(int v)
{
    return marked[v];
}

bool BreadthFirstPaths::hasPathTo(int v)
{
    return isMarked(v);
}

void BreadthFirstPaths::printPaths()
{
    map<int, int>::iterator iter = EdgeTo.begin();
    cout << "-----------print edge-----------" <<  endl;
    for(iter; iter != EdgeTo.end(); iter++)
    {
        cout << (*iter).first << "<---" << (*iter).second << endl;
    }
}
stack<int> BreadthFirstPaths::pathStore(int v)
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
int BreadthFirstPaths::getStartPoint()
{
    return startPoint;
}
int BreadthFirstPaths::getEdgeStart(int v)
{
    auto iter = EdgeTo.find(v);
       if(iter != EdgeTo.end())
       {
           return iter->second;
       }
       return -1;
}


connected_components::connected_components(undirect_Graph uGraph)
{
    marked = vector<bool>(uGraph.countOfVertex(), false);
    for(int s = 0; s < uGraph.countOfVertex(); s++)
    {
        if(!marked[s])
        {
            dfs(uGraph, s);
            count++;
        }
    }
    int countOfComponents = getCountOfCom();
    cout << "连通分量个数： " << countOfComponents << endl;
    vector<vector<int> > a_temp(countOfComponents);
    for(int i = 0; i < countOfComponents; i++)
    {
        for(int j = 0; j < uGraph.countOfVertex(); j++)
        {
            if(isBelongTo(j, i))
            {
                a_temp[i].push_back(j);
            }
        }
    }
}

void connected_components::dfs(undirect_Graph uGraph, int v)
{
    marked[v] = true;
    pair<int, int> id_element(v, count);
    id.insert(id_element);
    list<Vertex*> V_uGraphVertexSet = uGraph.getGraphVertexSet()[v]->neighbours;
    //获得v顶点的邻接表
    list<Vertex*>::iterator iter = V_uGraphVertexSet.begin();
    for(iter; iter != V_uGraphVertexSet.end(); iter++)
    {
        if(!marked[(*iter)->value])
            dfs(uGraph, (*iter)->value);
    }
}

bool connected_components::connected(int v, int w)
{
 
    return id.find(v)->second == id.find(w)->second;
}

int connected_components::getId(int v)
{
    return id[v];
}
int connected_components::getCount()
{
    return count;
}

void connected_components::printConnectedComponents()
{
    map<int, int>::iterator iter = id.begin();
    for(iter; iter != id.end(); iter++)
    {
        cout << (*iter).first << " " << (*iter).second << endl;
    }
    
}

int connected_components::getCountOfCom()
{
    int c = 1;
    int index = id.find(0)->second;
    map<int, int>::iterator iter = id.begin();
    for(iter; iter != id.end(); iter++)
    {
        if((*iter).second != index)
        {
          c++;
            index = (*iter).second;
        }
            
    }
    return c;
}
bool connected_components::isBelongTo(int v, int component)
{
    if(id.find(v)->second == component)
        return true;
    else
        return false;
}




