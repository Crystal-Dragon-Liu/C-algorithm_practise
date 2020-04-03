//
//  Longest_Increasing_Subsequence.hpp
//  Dat_Structure
//
//  Created by  云子谣 on 2020/3/30.
//  Copyright © 2020  云子谣. All rights reserved.
//

#ifndef Longest_Increasing_Subsequence_hpp
#define Longest_Increasing_Subsequence_hpp

#include <stdio.h>
#include <vector>

#endif /* Longest_Increasing_Subsequence_hpp */
using namespace std;


//什么是子序列
//什么是上升
//一个序列可能有多个最长上升子序列，但这个最长的长度只有一个


//LIS（i）表示第i个数字为结尾的最长上升子序列的长度
//当我选择这个结尾数字，会发生什么
//LIS（i）表示 0-i的范围内，选择数字nums[i]可以获得的最长上升子序列的长度

// LIS（i）= max(1 + LIS(j) if nums[i] > nums[j])  此处 j < i
// 设想 如 10 9 2 5 3 7 101 18 这样的测试用例，可以使其LIS[i]初始化都为1。每一个数字都是自己的最长上升子序列

class Solution
{
public:
    //动态规划
    int llis(vector<int> &nums);
};
