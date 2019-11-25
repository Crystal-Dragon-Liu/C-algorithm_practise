//
//  removeDuplicates.cpp
//  pointer
//
//  Created by  云子谣 on 2019/11/25.
//  Copyright © 2019  云子谣. All rights reserved.
//

#include "removeDuplicates.hpp"


int solution::removeDuplicates(std::vector<int> &nums)
{
    
    
        if(nums.size()==0) return 0;
        int key = 1;
        int pre = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i]!=pre)
            {
                nums[key] = nums[i];
                key++;
                pre = nums[i];
                    
            }
        }
        return key;
}
