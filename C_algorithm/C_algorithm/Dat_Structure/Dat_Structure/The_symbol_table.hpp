//
//  The_symbol_table.hpp
//  Dat_Structure
//
//  Created by  云子谣 on 2020/2/27.
//  Copyright © 2020  云子谣. All rights reserved.
//

#ifndef The_symbol_table_hpp
#define The_symbol_table_hpp

#include <stdio.h>
#include <vector>
#include <iostream>


#endif /* The_symbol_table_hpp */

using namespace std;
template<typename KEY,typename VALUE> class ArraySearch
{
public:
    ArraySearch(vector<KEY> kk, vector<VALUE> vv);
    ~ArraySearch();
    int Array_size();
    int rank_normal(KEY key);
    VALUE get(KEY key);
    void put(KEY key, VALUE value);
    KEY min();
    KEY max();
    KEY select(int k);
    KEY ceiling(KEY key);
    KEY floor(KEY key);
    bool isEmpty();
    void deleteKey(KEY key);
    void print_as();
private:
    vector<KEY> m_key;
    vector<VALUE> m_value;
};

template<typename KEY, typename VALUE> ArraySearch<KEY, VALUE>::ArraySearch(vector<KEY> kk, vector<VALUE> vv)
{
    m_key= kk;
    m_value = vv;
    
}
template<typename KEY, typename VALUE> ArraySearch<KEY, VALUE>::~ArraySearch(){}
template<typename KEY, typename VALUE> int ArraySearch<KEY, VALUE>::Array_size()
{
    return m_key.size();
}
template<typename KEY, typename VALUE> bool ArraySearch<KEY, VALUE>::isEmpty()
{
    return (Array_size() == 0);
}
template<typename KEY, typename VALUE> int ArraySearch<KEY, VALUE>::rank_normal(KEY key)
{
    int lo = 0, hi = Array_size()-1;
    //假如key数组为[1,2,3,4,5,6],lo = 0 指第一个元素索引，hi为该数组最后一个元素的索引5
    while(lo <= hi)
    {
        int mid = lo + (hi-lo)/2;
        if(key > m_key[mid]) lo = mid + 1;
        else if(key < m_key[mid]) hi = mid-1;
        else return mid;
    }
    return lo;//此时如果查找的数据存在，mid就是所查找的数据， 但此时应返回比查找的数组小的数据数量，在二分法算法执行的过程中，lo和hi会慢慢逼近mid，即会慢慢逼近要查找的key，所以lo最终会变成离key最近但比key小的索引
    
    

    
}
template<typename KEY, typename VALUE> void ArraySearch<KEY, VALUE>::put(KEY key, VALUE value)
{
    int i = rank_normal(key);
    if(i <= m_key.size() && m_key[i] == key)
    {
        //m_value.resize();
        //m_value[i] = value;
        //此时，i虽然代表了比key小的键值的个数，但同时，m_key[i]也代表了所要检索的键，
        //m_key[i] == key，判断 想要更新的键值对是否在表中
        //若不在需要重新插入å
        m_value[i] = value;
        return;
    }
    m_value.resize(m_value.size()+1);
    m_key.resize(m_key.size()+1);
    for(int j = m_key.size(); j > i; --j)
    {
        m_key[j] = m_key[j - 1];
        m_value[j] = m_value[j - 1];
    }
    m_key[i] = key;
    m_value[i] = value;
    
}


template<typename KEY, typename VALUE> VALUE ArraySearch<KEY, VALUE>::get(KEY key)
{
    if(isEmpty())
    {
        cout << "符号表为空" << endl;
        return m_value[0];
    }
    int i = rank_normal(key);
    if(i <= m_key.size() && m_key[i] == key)
    {
        return m_value[i];
    }
    else
    {
        cout << "未找到该键" << endl;
        return m_value[0];
    }
    
}





template<typename KEY, typename VALUE> void ArraySearch<KEY, VALUE>::print_as()
{
    typename vector<KEY>::iterator iter_k;
    typename vector<VALUE>::iterator iter_v;
 
  cout << "-------display key--------" << endl;
  for(iter_k = m_key.begin(); iter_k != m_key.end(); iter_k++)
  {
        
      cout << *(iter_k) << endl;
  }
  cout << "-------display VALUE--------" << endl;
  for(iter_v = m_value.begin();iter_v != m_value.end(); iter_v++)
  {
      cout << *(iter_v) << endl;
  }
}

template<typename KEY, typename VALUE> KEY ArraySearch<KEY, VALUE>::min()
{
    return m_key[0];
}

template<typename KEY, typename VALUE> KEY ArraySearch<KEY, VALUE>::max()
{
    return *(m_key.end()-1);
}

template<typename KEY, typename VALUE> KEY ArraySearch<KEY, VALUE>::select(int k)
{
    return m_key[k];
}

template<typename KEY, typename VALUE> KEY ArraySearch<KEY, VALUE>::ceiling(KEY key)
{
    int i = rank_normal(key);
    return m_key[i];
}
template<typename KEY, typename VALUE> KEY ArraySearch<KEY, VALUE>::floor(KEY key)
{
    int i = rank_normal(key);
    if(m_key[i] == key)
    {
        return m_key[i];
    }
    else
    {
        return m_key[i-1];
    }
}

template<typename KEY, typename VALUE> void ArraySearch<KEY, VALUE>::deleteKey(KEY key)
{
    if(isEmpty())
    {
        cout << "nothing could be deleted" << endl;
         return;
    }
    int i = rank_normal(key);
    if(m_key[i] != key)
        return;
    for(int j = i; j < m_key.size(); ++j)
    {
        m_key[j] = m_key[j+1];
        m_value[j] = m_key[j+1];
    }
    m_key.resize(m_key.size()-1);
    m_value.resize(m_value.size()-1);
    print_as();
    
       
}
