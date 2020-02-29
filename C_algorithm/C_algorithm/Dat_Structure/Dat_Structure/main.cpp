//
//  main.cpp
//  Dat_Structure
//
//  Created by  云子谣 on 2019/11/26.
//  Copyright © 2019  云子谣. All rights reserved.
//

#include <iostream>
#include <stack>
#include <queue>
#include <deque> //双端队列
#include <string>
#include "Sor.hpp"
#include <ctime>
#include "breadthFirstSearch.hpp"
#include "Dijkstra_Algorithm.hpp"
#include "approximation_algorithm.hpp"
#include "sorting_LowLevel.hpp"
#include "Priority_Queue_practise.hpp"
#include "The_symbol_table.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    
    //stack<string> i;
    //i.push("1");
    
    
    
    
    
    
    
    
    //fast_sorting test
    
//    sort_practise *sp = new sort_practise();
//
//    vector<int> i{10,9,8,7,6,5,4,3,2,1};
//    //sp->findSmallestItem(i, i.begin());
//    clock_t startTime,endTime;
//    startTime = clock();
//    vector<int> afterSort = sp->sorting_practise(i);
//    endTime = clock();
//    for(vector<int>::iterator index = afterSort.begin();index != afterSort.end();index++)
//
//    {
//        cout << *index << endl;
//    }

    
    
    
    
    
    
    //breadthFirstSearch test
    
//    breadthFirstSearch *b = new breadthFirstSearch();
//
//
//    b->findSeller();
    
//
    
    
    
    
    
    
    //Dijkstra's algorithm
    
//    Dijkstra_Algorithm *DA = new Dijkstra_Algorithm();
//
//    //DA->print_information();
//    DA->findRoad();
    
    
    
    
    
    
    
    
    
    //Approximation_algorithm
    
//    Approx_Algo *aa = new Approx_Algo();
//
//    aa->find_bestStations();
    
    
    
    
    
    //sort practise
    
   
//    int in[9] = {9,8,7,6,5,4,3,2,1};
//    vector<int> a(in,in+9);
    //基类测试
       //Sort_P sp;
       //sp.sort(a);
       //sp.show(a);
       //bool s = sp.isSorted(a);
    
    //选择排序测试
     //Selection_sort ss;
    //ss.show(a);
    //ss.sort(a);
    //ss.show(a);
    
    //插入排序测试
//    Insertion_sort is;
//    is.show(a);
//    is.sort(a);
//    is.show(a);
    //希尔排序
//    Shell_sort ss;
//    ss.show(a);
//    ss.sort(a);
//    ss.show(a);
    //归并排序测试
//    merge_sort ms;
//    ms.show(a);
//    ms.sort(a);
//    ms.show(a);
    //快速排序测试
//    Quick_sort qs;
//    qs.show(a);
//    qs.sort(a);
//    qs.show(a);
    //快速排序三切分测试
//    Quick_sort qs;
//    qs.show(a);
//    qs.sort(a);
//    qs.show(a);
    
    //优先队列 练习
    
//    struct tmp1
//    {
//        int x;
//        tmp1(int a)
//        {
//            x = a;
//        }
//        bool  operator<(const tmp1 &a) const
//        {
//            return x <a.x; //大堆顶
//        }
//    };
//
//    struct tmp2
//    {
//    bool operator() (tmp1 a, tmp1 b)
//            {
//            return a.x < b.x;
//            }
//            };
//
//            tmp1 e1(1);
//            tmp1 e2(2);
//            tmp1 e3(3);
//            priority_queue<tmp1> d;
//            d.push(e2);
//            d.push(e3);
//            d.push(e1);
//            while (!d.empty())
//            {
//            cout << d.top().x << '\n';
//            d.pop();
//            }
//            cout << endl;
//
//            priority_queue<tmp1, vector<tmp1>, tmp2> f;
//            f.push(e2);
//            f.push(e3);
//            f.push(e1);
//            while(!f.empty())
//            {
//            cout << f.top().x << '\n';
//            f.pop();
//            }
//            cout << endl;
    
//    MaxPQ<int> maxpq(5);
//    MinPQ<int> minpq(5);
//    maxpq.insert(1);
////    maxpq.print();
//    maxpq.insert(2);
////    maxpq.print();
//    maxpq.insert(3);
////    maxpq.print();
//    maxpq.insert(4);
////    maxpq.print();
//    maxpq.insert(5);
////    maxpq.print();
//    minpq.insert(3);
//    minpq.insert(1);
//    minpq.insert(2);
//    minpq.insert(4);
//    minpq.insert(5);
//
//    cout << maxpq.deleteMax() << " " << minpq.deleteMin() << endl;
//
//   maxpq.print();
//    cout << maxpq.deleteMax() << " " << minpq.deleteMin() << endl;
//  maxpq.print();
//    cout << maxpq.deleteMax() << " " << minpq.deleteMin() << endl;
//   maxpq.print();
//    cout << maxpq.deleteMax() << " " << minpq.deleteMin() << endl;
//  maxpq.print();
//    cout << maxpq.deleteMax() << " " << minpq.deleteMin() << endl;
//
//    maxpq.print();
//    minpq.print();
//
   
    
    
//符号表 二分法有序数组 测试
    
//    vector<int> a{1,2,3,4,5,6};
//    vector<int>::iterator iter = a.end();
//    cout << a.size() << endl;
//    cout << *(a.end()-1) << endl;
    
    vector<int> key{1,3,5,7,9,11,13,15};
    //key.resize(9,14);
    //cout << *(key.end()-1) << endl;
    vector<float> value{1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8};
    
    
    //put 测试
    
    
    
    
   ArraySearch<int, float> as(key, value);
//    cout << "keyn比" << 5 << "小的key的数量为 " << as.rank_normal(5) << endl;
    cout << "插入元素" << endl;
    as.put(2, 1.11);
    as.print_as();

    //cout << as.get(9) << endl;
    cout << "删除元素" << endl;
    as.deleteKey(2);
    
//
//            
    return 0;
    
}



