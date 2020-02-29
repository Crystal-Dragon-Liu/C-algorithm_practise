//
//  sorting_LowLevel.cpp
//  Dat_Structure
//
//  Created by  云子谣 on 2020/1/29.
//  Copyright © 2020  云子谣. All rights reserved.
//

#include "sorting_LowLevel.hpp"
using namespace std;
//parent class
bool Sort_P::less(int i, int j) const
{
    return (i<j) ? true : false;
}
void Sort_P::exch(vector<int> &a, vector<int>::iterator i, vector<int>::iterator j)
{
    cout << "-------------------exchange start-----------------------" << endl;
    cout << "__---iterator i " << *i << " ; iterator j ---__" << *j << endl;
    int temp;
    temp = *i;
    *i = *j;
    *j = temp;
    cout << "--___iterator i " << *i << " ; iterator j ___--" << *j << endl;
     cout << "-------------------exchange end-----------------------" << endl;
}

void Sort_P::exch(vector<int> &a, int i, int j)
{
    cout << "-------------------exchange start-----------------------" << endl;
    cout << "__---iterator i " << a[i] << " ; iterator j ---__" << a[j] << endl;
    int temp;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
    cout << "--___iterator i " << a[i] << " ; iterator j ___--" << a[j] << endl;
    cout << "-------------------exchange end-----------------------" << endl;
    
}
void Sort_P::show(vector<int> aa) const
{
    cout << "-------------display all the element--------------" << endl;
    for (vector<int>::iterator iter = aa.begin(); iter != aa.end(); iter++)
    {
        cout << *iter << endl;
    }
}
bool Sort_P::isSorted(vector<int> aa) const
{
    for(vector<int>::iterator iter = aa.begin()+1; iter != aa.end(); iter++)
    {
        if(less(*iter, *(iter-1)))
        {
            cout << "-----comparation-----" << endl;
            cout << *iter << " < " << *(iter-1) << endl;
            return false;
        }
        else
        {
            cout << "-----comparation-----" << endl;
            cout << *iter << " > " << *(iter-1) << endl;
            
        }
    }
    return true;
}

//子类

void Selection_sort::sort(vector<int> &aa)
{
    
    for(vector<int>::iterator iter_i = aa.begin(); iter_i != aa.end(); iter_i++)
    {
        vector<int>::iterator min = iter_i;
        for(vector<int>::iterator iter_j = iter_i+1; iter_j != aa.end(); iter_j++)
        {
            if(less(*iter_j, *min))
            {
                cout << *min << ">" << *iter_j << "exchange the iterator" << endl;
                min = iter_j;
                
                
            }
        }
        exch(aa, min, iter_i);
    }
    
}


void Insertion_sort::sort(vector<int> &aa)
{
    for(vector<int>::iterator iter_i; iter_i != aa.end(); iter_i++)
    {
        //插入 *iter 向 *（iter+1）、*（iter+2）、............
        for (vector<int>::iterator iter_j = iter_i; iter_j > aa.begin() && less(*(iter_j), *(iter_j-1)); iter_j--  )
        {
            exch(aa, iter_j, iter_j-1);
        }
    }
}


void Shell_sort::sort(vector<int> &aa)
{
    auto N = aa.size();
    int h = 1;
    while (h < N/3) {
        h = 3*h +1;
    }
    
    
    while(h >= 1)
    {
    //将数组变得有序
        for(vector<int>::iterator iter_i = aa.begin()+h; iter_i != aa.end(); iter_i++)
        {
            for (vector<int>::iterator iter_j = iter_i; iter_j >= aa.begin()+h && less(*(iter_j), *(iter_j-h)); iter_j-=h  )
                   {
                       exch(aa, iter_j, iter_j-h);
                   }
        }
        h = h / 3;
    }
}
merge_sort::merge_sort()
{
    
}


void merge_sort::merge(vector<int> &aa, int lo, int mid, int hi)
{
    //原地归并
    int lo_c = lo;
    int mid_c = mid+1;
    for (int k = lo; k <= hi; k++)
    {
        aux[k] = aa[k];
    }
    for(int k = lo; k <= hi; k++)
    {
        if(lo_c > mid) aa[k] = aux[mid_c++];
        else if (mid_c > hi) aa[k] = aux[lo_c++];
        else if (less(aux[mid_c], aux[lo_c]))
            aa[k] = aux[mid_c++];
        else
            aa[k] = aux[lo_c];
    }
}

void merge_sort::sort(vector<int> &aa)
{
    aux.resize(aa.size());
    cout << "the size of aux :  " <<aux.size() << endl;
    cout << "the aa.size-1 = " << int(aa.size()-1) << endl;
    sort(aa, 0, int(aa.size()-1));
}

void merge_sort::sort(vector<int> &aa, int lo, int hi)
{
    if(hi <= lo) return;
    int mid = lo + (hi-lo)/2;
    sort(aa, lo, mid);
    sort(aa, mid+1, hi);
    merge(aa, lo, mid, hi);
}


void Quick_sort::sort(vector<int> &aa)
{
    //sort(aa, 0, int(aa.size()-1));
    sort_3way(aa, 0, int(aa.size()-1));
}
void Quick_sort::sort(vector<int>&aa, int lo, int hi)
{
    if(hi <= lo) return;
    int mid = partition(aa, lo, hi);
    sort(aa, lo, mid-1);
    sort(aa, mid+1, hi);
}


int Quick_sort::partition(vector<int> &aa, int lo, int hi)
{
    int lo_c = lo;
    int hi_c = hi+1;
    int mid = aa[lo];
    //切分元素 mid
    while(true)
    {
        while (less(aa[++lo_c],mid))
        {
            if(lo_c == hi) break;
        }
        while (less(mid, aa[--hi_c]))
        {
            if(hi_c == lo) break;
        }
        if(lo_c >= hi_c)
            break;
        exch(aa, lo_c, hi_c);
    }
    exch(aa, lo, hi_c);
    
    
    
    return hi_c;
    
}

void Quick_sort::sort_3way(vector<int> &aa, int lo, int hi)
{
    if(hi <= lo)
        return;
    int lt = lo, i = lo+1, gt = hi;
    //lo--------lt-----------gt-------hi
    int v = aa[lo];
    while (i <= gt)
    {
        //bool cmp = less(aa[i], v);
        if (aa[i] < v) exch(aa, lt++, i++);
        else if(aa[i] > v) exch(aa, i, gt--);
        else i++;
        //lt i
        //2 2 1
        //lt   i
        //2 2 1
        //lt   i
        //1 2 2 4
        //  lt   i
        //1 2  2 2
        //  lt     i
        //1 2  2 2 4
    }
    
    sort_3way(aa, lo, lt-1);
    sort_3way(aa, gt+1, hi);
    
}
