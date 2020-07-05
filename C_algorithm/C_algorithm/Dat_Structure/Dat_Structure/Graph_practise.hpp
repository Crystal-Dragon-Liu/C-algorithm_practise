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
#include <queue>
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

class BreadthFirstPaths
{
private:
    vector<bool> marked;
    map<int, int> EdgeTo;
    int startPoint;
public:
    bool isMarked(int v);
    BreadthFirstPaths(undirect_Graph uGraph, int s);
    void bfs(undirect_Graph uGraph, int s);
    bool hasPathTo(int v);
    void printPaths();
    int getEdgeStart(int v);
    stack<int> pathStore(int v);
    int getStartPoint();
};


class connected_components
{
private:
    vector<bool> marked;
    map<int, int> id;
    int count=0;
public:
    connected_components(undirect_Graph uGraph);
    void dfs(undirect_Graph uGraph, int v);
    bool connected(int v, int w);
    int getCount();
    int getId(int v);
    void printConnectedComponents();
    int getCountOfCom();
    bool isBelongTo(int v, int component);
    
};


class Cycle
{
private:
    vector<bool> marked;
    bool hasCycle;
public:
    Cycle(undirect_Graph uGraph);
    void dfs_ForQueryOfCycle(undirect_Graph uGraph, int v, int u);
    bool hasCycleOrNot();
    
};

class TwoColors
{
private:
    vector<bool> marked;
    vector<bool> color;
    bool isTwocolorable = true;
    void dfsForcolor(undirect_Graph uGraph, int v);
    
public:
    TwoColors(undirect_Graph uGraph);
    bool isBipartite();
};


















//模版类型的图，后续讲之前的代码都整合进去

/* 节点类，图的节点数据类型可以任意给定 */
template<typename VertexType> class Vertex_new
{
public:
    Vertex_new(VertexType val)
    {
        in_out = 0;
        value = val;
    }
    VertexType value;
    int in_out;
    list<Vertex_new<VertexType> *> neighbours;
};




/* 模版图类，图的节点数据类型可以任意给定 */
template<typename VertexType> class undirectGraph_new
{
public:
    /*************************************************
    Function:   undirectGraph_new
    Description:    依据txt中对图的描述，对图进行初始化操作
    Calls:          addEdge
    Input:          string path 一个路径字符串
    Output:       一张可以代表每个节点连接情况的邻接表
    *************************************************/
    undirectGraph_new(string path);
    
    /*************************************************
    Function:   countOfVertex()
    Description:    一般在初始化后调用，用于返回图的节点数量
    Return:   int 类型的数据，代表节点数量
    *************************************************/
    int countOfVertex();
    
    /*************************************************
    Function:   countOfEdge()
    Description:    一般在初始化后调用，用于返回图的节点的边数数量
    Output:      int 类型的数据，代表边的数量
    *************************************************/
    int countOfEdge();
    
    /*************************************************
    Function:   addEdge
    Description:    一般在初始化图时使用，作用是根据具体情况，将节点加入邻接表
    Calls:          isInserted
    Input:          两个VertexType A和B ,代表两个节点的值
    *************************************************/
    void addEdge(VertexType firstVertex, VertexType secondVertex);
    
    /*************************************************
    Function:   print_allVertexAndEdge
    Description:    打印图的结构
    Output:      图中的每个节点及节点对应的邻居节点
    *************************************************/
    void print_allVertexAndEdge();
    
    /*************************************************
       Function:   isInserted
       Description:   判断一个节点的值是否已经是邻接表的某一个key(即判断这个节点是否已经被初始化)
       Input:          一个VertexType类型的节点值
       *************************************************/
    bool isInserted(VertexType v);
    
    
    //connectedComponent
    
    /*************************************************
       Function:   findConnectComponent
       Description:    找到图中的连通分量，并保存在id_cc当中
       *************************************************/
    void findConnectComponent();
    /*************************************************
       Function:   printConnectComponent
       Description:   打印连通分量
       *************************************************/
    void printConnectComponent();
    
    /*************************************************
       Function:   connected
       Description:    判断两个节点是否在一个连通分量里,  该函数需要在调用findConnectComponent()之后才有效
       Input:          两个value为VertexType 类型的顶点v和w
       *************************************************/
    bool connected(Vertex_new<VertexType> v, Vertex_new<VertexType> w);
    
    /*************************************************
       Function:   countOfCC()
       Description:    获得连通分量的个数
       Return:   int类型，连通分量的个数
       *************************************************/
    int countOfCC();//连通分量的个数
    
    
    /*************************************************
          Function:   id
          Description:    获得某顶点的连通分量id
          Return:   int类型，连通分量id
          *************************************************/
    int id(VertexType v);
   
    
    void createGraphMatrix();
    void printGraphMatrix();
    vector<vector<int> > getGraphMatrix();
    
    
    
private:
    
    /*************************************************
    Function:   initialVertexMarked_cc
    Description:    初始化每个节点的检测状况，全部初始化为“未检测”状态
    *************************************************/
    void initialVertexMarked_cc();
    
    /*************************************************
       Function:   isMarked_cc
       Description:   判断一个节点是否已经被检测
       Return:   返回true/false
       *************************************************/
    bool isMarked_cc(VertexType v);
    
    /*************************************************
    Function:   dfs_cc
    Description:   为连通算法专用的深度优先搜索，在搜索过程中记录路径上的点并赋予其连通分量id
    *************************************************/
    void dfs_cc(VertexType v);
    
    
    int m_countOfVertex;//顶点数
    int m_countOfEdge;//边数
    int cc_id;//代表在图中检测到的节点数
    map<VertexType, Vertex_new<VertexType>* > VertexSet;//邻接矩阵
    vector<vector<int> > m_GraphMatrix;
    multimap<int, VertexType> id_cc;//按所属的连通分量组id来存储各节点
    map<VertexType, bool> VertexMarked_cc;//VertexMarked_cc存储了各节点是否已经被访问过的信息，true代表访问过，VertexType代表节点的值
    
    
};









template<typename VertexType> undirectGraph_new<VertexType>::undirectGraph_new(string path)
{
    ifstream data(path);
    VertexType dat;
    data >> dat;
    cout << "___the count of  Vertex___:" << dat <<  endl;
    m_countOfVertex = dat; //初始化图的顶点数
    data >> dat;
    cout << "___the count of  Vertex___:" << dat <<  endl;
    m_countOfEdge = dat;
    for(int index = 0; index < m_countOfEdge; index++)
    {
        cout << "读取顶点： ";
        data >> dat;
        cout << dat << " <-----> ";
        VertexType firstVertex = dat;
        
        data >> dat;
        cout << dat << endl;
        
        VertexType  secondVertex = dat;
        addEdge(firstVertex, secondVertex);
    }
    
}

template<typename VertexType> int undirectGraph_new<VertexType>::countOfVertex()
{
    return m_countOfVertex;
}


template<typename VertexType>  void undirectGraph_new<VertexType>::addEdge(VertexType firstVertex, VertexType secondVertex)
{
    Vertex_new<VertexType> *firstVertexNode = new Vertex_new<VertexType>(firstVertex);
    Vertex_new<VertexType> *secondeVertexNode = new Vertex_new<VertexType>(secondVertex);
    //初始化两个顶点
    firstVertexNode->neighbours.push_back(secondeVertexNode);
    firstVertexNode->in_out++;//给第一个顶点的in_out属性加一
    
    secondeVertexNode->neighbours.push_back(firstVertexNode);
    secondeVertexNode->in_out++;
    
    pair<VertexType, Vertex_new<VertexType>*> v(firstVertex, firstVertexNode);
    pair<VertexType, Vertex_new<VertexType>*> w(secondVertex, secondeVertexNode);
    
    if(!isInserted(firstVertex) || firstVertex==secondVertex)
    {
        VertexSet.insert(v);
    }
    else
    {
        VertexSet[firstVertex]->neighbours.push_back(secondeVertexNode);
    }
    if(!isInserted(secondVertex)|| firstVertex==secondVertex)
    {
        VertexSet.insert(w);
    }
    else
    {
        VertexSet[secondVertex]->neighbours.push_back(firstVertexNode);
    }
    
    
}

template<typename VertexType> bool undirectGraph_new<VertexType>::isInserted(VertexType v)
{
    typename map<VertexType, Vertex_new<VertexType>*>::iterator iter = VertexSet.begin();
    for(iter; iter != VertexSet.end(); iter++)
    {
        if(iter->first == v)
            return true;
    }
    return false;
}


template<typename VertexType> void undirectGraph_new<VertexType>::print_allVertexAndEdge()
{
    
    
    typename map<VertexType, Vertex_new<VertexType>* >::iterator iter = VertexSet.begin();
    for(iter; iter != VertexSet.end(); iter++)
    {
         cout << "顶点" << iter->first << "的邻节点：";
        typename list<Vertex_new<VertexType>*>::iterator j = iter->second->neighbours.begin();
        for(j; j != iter->second->neighbours.end(); j++)
        {
            cout << (*j)->value << " ";
        }
        cout << endl;
    }
}



template<typename VertexType> void undirectGraph_new<VertexType>::createGraphMatrix()
{
    // initial for GraphMatrix
    int n = countOfVertex();
    m_GraphMatrix = vector<vector<int> >(n, vector<int>(n, 0));
    if(typeid(VertexType).name() == typeid(int).name() )
    {
        
        typename map<VertexType, Vertex_new<VertexType>* >::iterator iter = VertexSet.begin();
        for(iter; iter != VertexSet.end(); iter++)
        {
            typename list<Vertex_new<VertexType>*>::iterator j = iter->second->neighbours.begin();
            for(j; j != iter->second->neighbours.end(); j++)
            {
                m_GraphMatrix[iter->first][iter->first] = 1;
                m_GraphMatrix[iter->first][(*j)->value] = 1;
            }
        }
    }
    else
    {
        cout << "类型不匹配" << endl;
    }
    
}



template<typename VertexType> void undirectGraph_new<VertexType>::printGraphMatrix()
{
    for(int i = 0; i < m_GraphMatrix.size(); i++)
    {
        for(int j = 0; j < m_GraphMatrix[0].size(); j++)
        {
            cout << m_GraphMatrix[i][j] << " ";
        }
        cout << endl;
    }
}
template<typename VertexType> vector<vector<int> > undirectGraph_new<VertexType>::getGraphMatrix()
{
    return m_GraphMatrix;
}








template<typename VertexType> void undirectGraph_new<VertexType>::initialVertexMarked_cc()
{
    typename map<VertexType, Vertex_new<VertexType>* >::iterator iter = VertexSet.begin();
    for(iter; iter != VertexSet.end(); iter++)
    {
        VertexMarked_cc.insert(pair<VertexType, bool>(iter->first, false));
    }
}

template<typename VertexType> bool undirectGraph_new<VertexType>::isMarked_cc(VertexType v)
{
    return true == VertexMarked_cc.find(v)->second;
}

template<typename VertexType> void undirectGraph_new<VertexType>::findConnectComponent()
{
    cc_id = 0;
    initialVertexMarked_cc();//初始化marked，默认所有节点都没有被检测到（false）
    typename map<VertexType, Vertex_new<VertexType>* >::iterator iter = VertexSet.begin();
    for(iter; iter != VertexSet.end(); iter++)
    {
        if(!isMarked_cc(iter->first))
        {
            dfs_cc(iter->first);//从当前节点开始一直深入搜索，返回后，该节点和路径上的所有节点都属于同一个连通分量
            cc_id++;
            
        }
    }
}


template<typename VertexType> void undirectGraph_new<VertexType>::dfs_cc(VertexType v)
{
    typename map<VertexType, bool>::iterator iter = VertexMarked_cc.find(v);
    iter->second = true;
    id_cc.insert(pair<int, VertexType>(cc_id, v));
    
    typename list<Vertex_new<VertexType> *>::iterator VertexIter = VertexSet.find(v)->second->neighbours.begin();
    for(VertexIter; VertexIter != VertexSet.find(v)->second->neighbours.end(); VertexIter++)
    {
        if(!isMarked_cc((*VertexIter)->value))
        {
            dfs_cc((*VertexIter)->value);
        }
    }
    
    
}


template<typename VertexType> void undirectGraph_new<VertexType>::printConnectComponent()
{
//    typename multimap<int, VertexType>::iterator iter = id_cc.begin();
//    for(iter; iter != id_cc.end(); iter++)
//    {
//        cout << iter->first << " " << iter->second << endl;
//    }
    for(int i = 0; i < cc_id; i++)
    {
        typename multimap<int, VertexType>::iterator iter_lower =id_cc.lower_bound(i);
        typename multimap<int, VertexType>::iterator iter_upper =id_cc.upper_bound(i);
        cout << "连通分量" << i <<" 的节点：";
        for(auto iter = iter_lower; iter != iter_upper; iter++)
        {
            cout << iter->second << ", ";
        }
        cout << endl;
    }
}


template<typename VertexType> bool undirectGraph_new<VertexType>::connected(Vertex_new<VertexType> v, Vertex_new<VertexType> w)
{
    int i = 0;
    typename multimap<int, VertexType>::iterator iter = id_cc.begin();
    for(iter; iter != id_cc.end(); iter++)
        {
//            cout << iter->first << " " << iter->second << endl;
            if(v.value == iter->second) i++;
            if(w.value == iter->second) i++;
        }
    return i==2;
}


template<typename VertexType> int undirectGraph_new<VertexType>::countOfCC()
{
    return cc_id;
}


template<typename VertexType> int undirectGraph_new<VertexType>::id(VertexType v)
{
    int result;
    typename multimap<int, VertexType>::iterator iter = id_cc.begin();
    for(iter; iter != id_cc.end(); iter++)
    {
        if(v == iter->second) result = iter->first;
    }
    return result;
}
