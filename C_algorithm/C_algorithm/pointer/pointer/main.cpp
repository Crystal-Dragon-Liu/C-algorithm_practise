//
//  main.cpp
//  pointer
//
//  Created by  云子谣 on 2019/11/21.
//  Copyright © 2019  云子谣. All rights reserved.
//


#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "removeDuplicates.hpp"
using namespace std;



void const_pointer_destributeAndDropback(){
    const int *pci = new const int(1024);
    //尽管程序员不能改变 const 对象的值，但可撤销对象本身。如同其他动态,对象一样， const 动态对象也是使用删除指针来释放的:
    delete pci;
    pci = 0;
    
    //与其他常量一样，动态创建的 const 对象必须在创建时初始化，并且一经 初始化，其值就不能再修改。
    const string *pcs = new const string;
    
    delete pcs;
    pcs = 0;
}


void internalClass_Convert()
{
    int ival = 1;
    double dval = 1.0;
    if(ival >= dval)//隐式类型转换
    {
        int i = 3.14; //此时也会有隐式类型转换。
    }
    
}

void const_convert()

{
    const char *p ;
    
    char *pc = const_cast<char *>(p);
    
    //如果某些函数对数据只读不写，最好的选择是使用const作为参数，但如果只有const可用，就用const_cast对const类型作转换，也只能使用const_cast做转换。
}




//vector<int >::iterator iter;








template<typename elemType>
elemType* findSth(vector<elemType> &vec_s, elemType key)
{
    for(int ix =0;ix != vec_s.size();++ix)
    {
        if(key == vec_s[ix])
        {
            return &vec_s[ix];
        }
        
    }
    return 0;
}

int BinaryResearch(int key, vector<int> &ival )
{
    int a = ival.size()-1;
    int b = 0;
    
    
    
    while(a != b)
    {
        
    int mid =b+(a-b)/2;
    if (key<ival[mid]){a = mid-1;}
    else if(key>ival[mid]){b = mid+1 ;}
    else return mid;
        
    }
    
    return -1;
   
    
}



//LeetCode 1.从排序数组中删除重复项

int removeDuplicates(vector<int>& nums)
  
  {
      
      if(nums.size() == 0) return 0;
      
      int k = 1;
      
      int pre = nums[0];
      
      auto len = nums.size()-1;
      for (int i = 0; i < len; i++)
      {
          if(nums[i] != pre)
          {
              nums[k] = nums[i];
              k++;
              pre = nums[i];
          }
          
      }
      return 0;
  }


int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    
    
   //test findSth
    /*
     vector<string> vec_s{"M","P"};
        string key_np = "P";
        string *key = &key_np;
        key = findSth(vec_s, key_np);
        cout << *key  << endl;
     
     **/
    
    
    
   //test binaryresearch
   /*
    vector<int> ival{1,3,2,5,6,4};
       sort(ival.begin(), ival.end());
      /*
       for(auto index = ival.begin();index != ival.end();++index)
          {
              cout << *index << " " <<  endl;
          }
       
             int b = BinaryResearch(1, ival);
             cout << b << endl;
             
       */
      vector<int> ival{1,2,3,4,4,5,5};
      solution *s = new solution();
      int key = s->removeDuplicates(ival);
    cout << key << endl;
      
    
    
    
    return 0;
}
