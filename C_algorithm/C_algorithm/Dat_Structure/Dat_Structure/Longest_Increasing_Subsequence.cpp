//
//  Longest_Increasing_Subsequence.cpp
//  Dat_Structure
//
//  Created by  云子谣 on 2020/3/30.
//  Copyright © 2020  云子谣. All rights reserved.
//

#include "Longest_Increasing_Subsequence.hpp"



using namespace std;

int Solution::llis(vector<int> &nums)
{
    if(nums.size() == 0)
        return 0;
    // 以nums[i]为结尾的最长上升子序列长度
    vector<int> memo(nums.size(), 1);
    for(int i = 1; i < nums.size(); i++)
        for(int j = 0; j < i; j ++)
            //考察i之前的所有元素，一旦发现 nums[j] < nums[i] ，即 nums[i]可以跟在nums[j]后面，尝试更新memo
            if(nums[j] < nums[i])
                memo[i] = max(memo[i], 1+ memo[j]);
    //最长上升子序列的最后一个位置有可能在序列的任何位置
    int res = 1;
    for(int i = 0; i < nums.size(); i++)
    {
        res = max(res, memo[i]);
    }
    return res;
}
