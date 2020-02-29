//
//  Sor.cpp
//  Dat_Structure
//
//  Created by  云子谣 on 2019/11/27.
//  Copyright © 2019  云子谣. All rights reserved.
//

#include "Sor.hpp"
using namespace std;
//找最小的值
int sort_practise::findSmallestItem(std::vector<int> i)
{
    int smallest = *i.begin();
    int smallest_index = 0;
    for(int index = 1 ; index < i.size(); index++)
    {
        if (i[index] <  smallest )
        {
            smallest = i[index];
            smallest_index = index;
        }
    }
    return smallest_index;
}

vector<int>::iterator sort_practise::findSmallestItem(std::vector<int>&i, std::vector<int>::iterator b)
{
    //int smallest = *b;
    
    vector<int>::iterator s;
    
    for(s = b+1;b != i.end();++b)
    {
        if(*s > *b)
        {
            s = b;
            //cout << "此时 b =  " << *b << endl;
            //cout << "此时 s = " << *s << endl;

        }
    }
    cout << "the mini value is :" << *s << endl;
    return s;

    
    
}

vector<int> sort_practise::sorting_practise(std::vector<int> &i)
{
    for(vector<int>::iterator begin = i.begin(); begin != i.end()-1;begin++)
    {
        vector<int>::iterator smallest = findSmallestItem(i, begin);
       // cout << "the value of begin : " << *begin << endl;
        
        
        swap(*begin, *smallest);
        
        
    }
    return i;
    
}

