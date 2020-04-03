//
//  select_problem.cpp
//  Dat_Structure
//
//  Created by  云子谣 on 2020/3/22.
//  Copyright © 2020  云子谣. All rights reserved.
//

#include "select_problem.hpp"
#include <math.h>

bool Select_Problem::less(int i, int j) const
{
    
    return (i<j) ? true : false;
}

void Select_Problem::exch(vector<int> &a, int i, int j)
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

int Select_Problem::partition(vector<int> &aa, int lo, int hi)
{
    int lo_c = lo;
    int hi_c = hi + 1;
    int v = aa[lo];
    cout << "____v____" << v << endl;
    while (true)
    {
        while(less(aa[++lo_c], v))
        {
            if(lo_c == hi) break;
        }
        while (less(v, aa[--hi_c]))
        {
            if(hi_c == lo) break;
        }
        if(lo_c >= hi_c)
            break;
        exch(aa, lo_c, hi_c);
        
    }
    show(aa);
    exch(aa, lo, hi_c);
    show(aa);
    cout << "-----hi_c-----" << endl;
    cout << hi_c << endl;
    return hi_c;
}
void Select_Problem::select_x(vector<int> &aa, int k)
{
    if(k > aa.size()-1)
        return;
    int x = select(aa, k , 0, int(aa.size()-1));
    cout << "序列中，第K大的数是：" << x << endl;
}





int Select_Problem::select(vector<int> &aa, int k, int lo, int hi)
{
    int j = partition(aa, lo, hi);
    //cout << j << endl;
    
    if(k == j) return aa[j];
    //k-j+lo
    else if (k > j+1) return select(aa, k-abs(j-lo)-1, j+1, hi);
    else return select(aa, k, lo, j-1);
}






void  Select_Problem::show(vector<int> aa) const
{
    cout << "-------------display all the element--------------" << endl;
    for (vector<int>::iterator iter = aa.begin(); iter != aa.end(); iter++)
    {
        cout << *iter;
    }
    cout << endl;
}
