//
//  Priority_Queue_practise.hpp
//  Dat_Structure
//
//  Created by  云子谣 on 2020/2/20.
//  Copyright © 2020  云子谣. All rights reserved.
//

#ifndef Priority_Queue_practise_hpp
#define Priority_Queue_practise_hpp

#include <stdio.h>
#include <iostream>

#include <queue>




#endif /* Priority_Queue_practise_hpp */


using namespace std;




template<typename T>class MaxPQ
{
public:
    MaxPQ(int maxN);
    ~MaxPQ();
    bool isEmpty();
    void insert(T val);
    T deleteMax();
    void swim(int k);
    void sink(int k);
    
    friend void exch(vector<T> &a, int j, int k);
    friend bool pqless(T &a, int x, int y);
    void print();
private:
    vector<T> pq;
    int N = 0;
    
};

template<typename T> class MinPQ
{
public:
    MinPQ(int maxN);
    ~MinPQ();
    
    bool isEmpty();
    void insert(T val);
    T deleteMin();
    void swim(int k);
    void sink(int k);
    friend void exch(vector<T> &a, int j, int k);
    friend bool pqless(T &a, int x, int y);
    void print();
private:
    vector<T> pq;
    int N = 0;
    
};


template<typename T>
inline void exch(vector<T> &a, int j, int k)
{
    swap(a[j], a[k]);
}
template<typename T>
inline bool pqless(vector<T> &a, int x, int y)
{
    if(a[x] <= a[y])
        return true;
    return false;
}






template<typename T>MaxPQ<T>::MaxPQ(int maxN)
{
//  pq.assign(maxN+1, 0);
    pq.resize(1);
}
template<typename T>MaxPQ<T>::~MaxPQ()
{}

template<typename T> bool MaxPQ<T>::isEmpty()
{
    N = pq.size();
    if(N)
        return false;
    return true;
}
template<typename T> void MaxPQ<T>::insert(T val)
{
//    pq[++N] = val;
//    swim(N);
    auto i = val;
    //cout << "接收元素：" << i << endl;
    pq.push_back(i);
    int NN= pq.size()-1;
    cout << "vector容量" << NN << endl;
    cout << "插入元素：" << *(pq.end()-1)<< endl;
    cout << "---------目前vector 内容---------" << endl;
    print();
    swim(NN);
    print();
}
template<typename T> T MaxPQ<T>::deleteMax()
{
    N = pq.size()-1;
    T max = pq[1];
    exch(pq, 1, N--);// 交换最后一个元素和最大元素， 另N-1 代表 整个队列大小减一
    
    pq.assign(pq.begin(), pq.end()-1);
    sink(1);
    //pq.resize(N-1);
    return max;
    
}


template<typename T> void MaxPQ<T>::sink(int k)
{
    N = pq.size()-1;
    while (k*2 <= N)
    {
        int j = k*2;
        if((j < N) && pqless(pq, j, j+1))// 找k的两个子节点中最大的
        {
            j++;
        }
        if(!pqless(pq, k, j))
            break;
        exch(pq, k, j);
        k = j;
    }
}

template<typename T> void MaxPQ<T>::swim(int k)
{
    while((k>1)&&!pqless(pq, k, k/2))
    {
        exch(pq, k, k/2);
        k = k/2;
    }
    
}





template<typename T>MinPQ<T>::MinPQ(int maxN)
{
    pq.assign(maxN+1, 0);
    
}
template<typename T>MinPQ<T>::~MinPQ(){}
template<typename T> void MinPQ<T>::insert(T val)
{
    pq[++N] = val;
    //pq.push_back(val);
    swim(N);
}
template<typename T> bool MinPQ<T>::isEmpty()
{
    if(N) return false;
    return true;
}

template<typename T> T MinPQ<T>::deleteMin()
{
    T min = pq[1];
    exch(pq, 1, N--);
    //pq.erase(pq.end());
    //pq[N+1] = nullptr;
    sink(1);
    //pq.resize(N-1);
    return min;
}

template<typename T> void MinPQ<T>::sink(int k)
{
    while(k*2 <= N)
    {
        int j = k*2;
        if((j<N)&&!pqless(pq, j, j+1))
            j++;
        if(pqless(pq, k, j))
            break;
        exch(pq, k, j);
        k = j;
    }
}
template<typename T> void MinPQ<T>::swim(int k)
{
    while((k>1)&&!pqless(pq, k/2, k))
    {
        exch(pq, k/2, k);
        k = k/2;
    }
}

template<typename T> void MaxPQ<T>::print()
{
    cout << "-----------Max当前优先队列内容----------" << endl;
    for (auto& v : MaxPQ<T>::pq) {
        std::cout << v << " " << std::ends;
    }
    cout << endl;
    
}
template<typename T> void MinPQ<T>::print()
{
     cout << "-----------Min当前优先队列内容----------" << endl;
    for (auto& v : MinPQ<T>::pq) {
        std::cout << v << " " << std::ends;
    }
    cout << endl;
    
}
//
//054213
//04321
//0312
//021
//01
