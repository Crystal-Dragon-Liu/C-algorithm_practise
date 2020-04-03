//
//  merge_inversion_count.cpp
//  Dat_Structure
//
//  Created by  云子谣 on 2020/3/22.
//  Copyright © 2020  云子谣. All rights reserved.
//

#include "merge_inversion_count.hpp"
using namespace std;

void inversion::mergesort(vector<int> &a, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) >> 1;
        mergesort(a, start, mid );
        mergesort(a, mid+1,end);
        merge_2(a, start, mid, end); //合并
    }
}
void inversion::merge_2(vector<int> &a, int lo, int mid, int hi)
{
    int i = lo;
    int j = mid +1;
    vector<int> aux;
    aux.resize(a.size());
    for (int k = lo; k <= hi; k++)
    {
        aux[k] = a[k];
    }
    for(int k = lo; k <= hi; k++)
    {
        if(i >mid) a[k] = aux[j++];
        else if (j > hi) a[k]= aux[i++];
        else if (aux[j] < aux[i])
        {
            cout << "检测到" << mid-i+1 << "个逆序对" << endl;
            for(int index = i; index <= mid;index++)
            {
                cout << "(" << aux[index] << ", " << aux[j] << ")" ;
                
            }
            cout << endl;
            m_count = (m_count + mid - i + 1 ) %1000000007;
            a[k] = aux[j++];
        }
        else a[k] = aux[i++];
    }
}
void inversion::merge(vector<int> &a, int start, int mid, int end)
{
    vector<int> aux;
    int i = start;
    int j = mid +1;
    while(i <= mid && j <= end)
    {
        if(a[i] >a[j])
        {
            m_count = (m_count + mid - i + 1 ) %1000000007;
            aux.push_back(a[j++]);
        }
        else aux.push_back(a[i++]);
    }
    
    while (i <= mid) {
        aux.push_back(a[i++]);
    }
    while (j <=end) {
        aux.push_back(a[j++]);
    }
    for (int i = 0; i < aux.size(); ++i)
    {
        a[start + i] = aux[i];
    }
}
int inversion::InversePairs(vector<int> &a)
{
    int n = int(a.size());
    if (n != 0)
    {
        mergesort(a, 0, n - 1);   //调用归并排序的分解函数
    }
    cout << "共检测到" << m_count << "个逆序对" << endl;
    return m_count;
}
