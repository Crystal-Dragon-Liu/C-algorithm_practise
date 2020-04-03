//
//  sorting_LowLevel.hpp
//  Dat_Structure
//
//  Created by  云子谣 on 2020/1/29.
//  Copyright © 2020  云子谣. All rights reserved.
//

#ifndef sorting_LowLevel_hpp
#define sorting_LowLevel_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
class Sort_P
{
public:
    bool less(int i, int j) const;
    virtual void sort(std::vector<int> &aa)
    {
        std::cout << "this is a sort algorithm parent class" << std::endl;
    }
    void exch(std::vector<int> &aa, std::vector<int>::iterator i, std::vector<int>::iterator j);
    void exch(std::vector<int> &aa, int i , int j);
    void show(std::vector<int> aa) const;
    bool isSorted(std::vector<int> aa) const;
    
    
    
};
#endif /* sorting_LowLevel_hpp */
class Selection_sort:public Sort_P
{
public:
    void sort(std::vector<int> &aa);
};


class Insertion_sort:public Sort_P
{
public:
    void sort(std::vector<int> &aa);
};


class Shell_sort:public Sort_P
{
public:
    void sort(std::vector<int> &aa);
};


class merge_sort:public Sort_P
{
public:
    merge_sort();
    
    void sort(std::vector<int> &aa);
    void sort(std::vector<int> &aa, int lo, int hi);
    void merge(std::vector<int> &aa, int lo, int mid, int hi);
    
private:
    std::vector<int> aux;
    //std::vector<int>::iterator iter_aux;
};

class Quick_sort:public Sort_P
{
public:
    int partition(std::vector<int> &aa, int lo, int hi);
    void sort(std::vector<int> &aa, int lo, int hi);
    void sort(std::vector<int> &aa);
    void sort_3way(std::vector<int> &aa, int lo, int hi);
};
