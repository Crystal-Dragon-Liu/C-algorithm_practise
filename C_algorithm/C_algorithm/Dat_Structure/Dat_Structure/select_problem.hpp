//
//  select_problem.hpp
//  Dat_Structure
//
//  Created by  云子谣 on 2020/3/22.
//  Copyright © 2020  云子谣. All rights reserved.
//

#ifndef select_problem_hpp
#define select_problem_hpp
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
class Select_Problem
{
public:
    int partition(vector<int> &aa, int lo, int hi);
    int select(vector<int> &aa, int k, int lo, int hi);
    void select_x(vector<int> &aa, int k);
    bool less(int i , int j) const;
    void exch(vector<int> &a, int i , int j);
    void show(vector<int> aa) const;
};
#endif /* select_problem_hpp */
