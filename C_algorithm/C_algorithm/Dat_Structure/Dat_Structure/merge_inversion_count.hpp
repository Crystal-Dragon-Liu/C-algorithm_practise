//
//  merge_inversion_count.hpp
//  Dat_Structure
//
//  Created by  云子谣 on 2020/3/22.
//  Copyright © 2020  云子谣. All rights reserved.
//

#ifndef merge_inversion_count_hpp
#define merge_inversion_count_hpp

#include <stdio.h>
#include <numeric>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
class inversion
{
public:
    void merge(vector<int>& a, int start, int mid, int end);
    void merge_2(vector<int>&a, int lo, int mid, int hi);
    void mergesort(vector<int>& a, int start, int end);
    int InversePairs(vector<int> &a);
    int m_count = 0;
};
#endif /* merge_inversion_count_hpp */

