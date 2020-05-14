////
////  main.cpp
////  Dat_Structure
////
////  Created by  云子谣 on 2019/11/26.
////  Copyright © 2019  云子谣. All rights reserved.
////
//
//#include <iostream>
//#include <stack>
//#include <queue>
//#include <deque> //双端队列
//#include <string>
//#include "Sor.hpp"
//#include <ctime>
//#include "breadthFirstSearch.hpp"
//#include "Dijkstra_Algorithm.hpp"
//#include "approximation_algorithm.hpp"
//#include "sorting_LowLevel.hpp"
//#include "Priority_Queue_practise.hpp"
//#include "The_symbol_table.hpp"
//#include "Binary_Search_Tree.hpp"
//#include "select_problem.hpp"
//#include "merge_inversion_count.hpp"
//#include "RedBlackBST.hpp"
//#include "Longest_Increasing_Subsequence.hpp"
//using namespace std;
//
#include <string>
#include <fstream>
#include "Graph_practise.hpp"
#include<math.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
//#include "Branch_and_Bound_Method.hpp"
//#include "Branch_and_Bound_Method.cpp"


using namespace std;
//#define N 6
//struct BBMNode
//{
//    BBMNode()
//    {
//        items_Value =0;
//        items_Weight = 0;
//        items_Bound = 0;
//        level = 0;
//        parent = 0;
//    }
//    int items_Value; //搜索到该节点时的价值
//    int items_Weight; // 搜索到该节点时的重量
//    float items_Bound; //搜索到该节点为根的子树能达到的价值上界
//    int level; //该节点所属层
//    struct BBMNode *parent = NULL;//指向父节点
//};
//
//
////修改比较方法
//
//struct cmp
//{
//  bool operator()(BBMNode *a, BBMNode *b)
//    {
//        return a->items_Bound < b->items_Bound;
//    }
//};
//struct Item_Information
//{
//    int item_ID;
//    int item_Value;
//    int item_Weight;
//    float Value_Weight_Ratio; //价值和重量比值
//};
//
//bool ItemCmp(Item_Information item1, Item_Information item2)
//{
//    return item1.Value_Weight_Ratio  > item2.Value_Weight_Ratio;
//}
//
//void Print_AllValues(int v[6])
//{
//    cout << "商品价值依次为：" ;
//    for(int i = 0; i < N; i++)
//    {
//        cout << v[i] << " ";
//    }
//    cout << endl;
//}
//void Print_AllWeight(int w[6])
//{
//    cout << "商品重量依次为：" ;
//    for(int i = 0; i < N; i++)
//    {
//        cout << w[i] << " ";
//    }
//    cout << endl;
//}
//
//
//
//class BranchandBround
//{
//public:
//    int maxSize;
//    int maxValue; //当前搜索到的最大价值
//    int searchCount; //搜索次数
//    BBMNode *maxNode = NULL;
//    priority_queue<BBMNode *, vector<BBMNode *>, cmp> maxQueue; //最大价值优先序列
//    BBMNode *firstNode;
//    BBMNode *curNode = NULL;
//    BranchandBround(Item_Information items[], int c);
//    float maxBound(BBMNode *bbmnode, Item_Information items[], int c);
//};
//
//
//BranchandBround::BranchandBround(Item_Information items[], int c)
//{
//    maxSize=0;
//    int x[N] = {0};
//    searchCount = 1;
//    firstNode = new BBMNode();
//    firstNode->items_Bound = maxBound(firstNode, items, c);
//    firstNode->parent = NULL;
//    maxQueue.push(firstNode);
//    maxValue = 0;
//    maxNode = firstNode;
//    while(!maxQueue.empty())
//    {
//        curNode = maxQueue.top();
//        maxQueue.pop();
//        //扩展左子节点
//        if((curNode->items_Weight + items[curNode->level].item_Weight) <= c) //最大重量界限
//        {
//            BBMNode *leftNode = new BBMNode();
//            leftNode->items_Value = curNode->items_Value + items[curNode->level].item_Value;
//            leftNode->items_Weight = curNode->items_Weight + items[curNode->level].item_Weight;
//            leftNode->level = curNode->level + 1;
//            leftNode->parent = curNode;
//            leftNode->items_Bound = curNode->items_Bound;
//            if(leftNode->level < N)
//            {
//                maxQueue.push(leftNode);
//                searchCount++;
//            }
//            if(maxValue < leftNode->items_Value)
//            {
//                maxValue = leftNode->items_Value;
//                maxNode = leftNode;
//            }
//        }
//
//        if(maxBound(curNode, items, c) > maxValue)//最大价值上界限
//        {
//            BBMNode *rightNode = new BBMNode();
//            rightNode->items_Value =curNode->items_Value;
//            rightNode->items_Weight = curNode->items_Weight;
//            rightNode->level = curNode->level + 1;
//            rightNode->parent = curNode;
//            rightNode->items_Bound = maxBound(rightNode, items, c);
//            if(rightNode->level < N)
//            {
//                maxQueue.push(rightNode);
//                searchCount++;
//            }
//        }
//        if(maxQueue.size() > maxSize)//更新队列大小
//        {
//            maxSize = int(maxQueue.size());
//        }
//    }
//    curNode = maxNode;
//    while(curNode)
//    {
//        int tempValue = curNode->items_Value;
//        curNode = curNode->parent;
//        if(curNode && curNode->items_Value != tempValue)
//            x[items[curNode->level].item_ID] = 1;
//    }
//    for(int i = 0; i < N; i++)
//    {
//        cout << x[i] << " ";
//    }
//    cout << endl;
//}
//
//
//float BranchandBround::maxBound(BBMNode *bbmnode, Item_Information items[], int c) //求以该节点为根的子树能达到的价值上界
//{
//    float maxValue;
//    int restCapacity;//
//    int i;
//    maxValue = bbmnode->items_Value;
//    restCapacity = c - bbmnode->items_Weight;
//    i = bbmnode->level;
//    while( i < N && restCapacity > items[i].item_Weight)
//    {
//        maxValue += items[i].item_Value;
//        restCapacity -= items[i].item_Weight;
//        i++;
//    }
//    if(restCapacity != 0)
//        maxValue += restCapacity*items[i].Value_Weight_Ratio;
//    return maxValue;
//}



//int n = 20;
//vector<int> a(20, 0);
//vector<int> check(20, 0);
//
//bool isPrime(int k)
//{
//    int n;
//    n = (int)sqrt(k);
//    for(int i =2; i<= n; i++)
//        if(k%i == 0)
//            return false;
//    return true ;
//}
//
//void Prime_loop(int k)
//{
//    if(k == n && isPrime(a[0] + a[n-1]))
//    {
////        for(int i = 0; i < n; i++)
////        {
////            cout << a[i] << " ";
////        }
////        cout << endl;
//        return;
//    }
//    else
//    {
//        for(int i = 2; i <= n; i++)
//        {
//            if(check[i] == 0 && isPrime(i + a[k-1]))
//            {
//                a[k] = i;
//                check[i] = 1;
//                Prime_loop(k+1);
//                check[i] = 0;
//            }
//        }
//    }
//}
//const int N=505;
//int matchingRows1AndRows2[N][N]; //第一行元素与第二行元素的匹配矩阵
//int row1[N];
//int elementVisited[N];
//int CombinationOfElement, m, n;
//
//bool dfs(int x)
//{
//    for(int i = 1; i <= n; i++)
//    {
//        if(matchingRows1AndRows2[x][i] == 1 && elementVisited[i] == 0)
//        {
//          elementVisited[i] = 1;
//          if(row1[i] == 0 || dfs(row1[i]))
//          {
//            row1[i] = x;
//            return true;
//          }
//        }
//    }
//    return false;
//}

int main(int argc, const char * argv[])
{
    
    
//    //测试二分图最大匹配
//    cout << "输入组合数: " << endl;
//    while(cin >> CombinationOfElement)
//    {
//        if(CombinationOfElement == 0) break;
//        cout << "输入第一行的元素个数 :" << endl;
//        cin >> m;
//        cout << "输入第二行的元素个数 :" << endl;
//        cin >> n;
//        memset(matchingRows1AndRows2, 0, sizeof(matchingRows1AndRows2));
//        memset(row1, 0, sizeof(row1));
//        for(int i = 1; i <= CombinationOfElement; i++)
//        {
//            int x, y;
//            cout << "输入匹配组合中的x :" << endl;
//            cin >> x;
//            cout << "输入匹配组合中的y :" << endl;
//            cin >> y;
//            matchingRows1AndRows2[x][y-4] = 1;
//        }
//        int ans = 0;
//        for(int i = 1; i <= m; i++)
//        {
//            memset(elementVisited, 0, sizeof(elementVisited));
//            if(dfs(i))
//                ans++;
//        }
//        cout << "得到的最大匹配数目：" <<ans << endl;
//    }
//
//    return 0;
//
    
    
    
    
    
    
    
    
    
    
    
    
    //测试回溯法
//    a[0] = 1;
//    check[1] = 1;
//    Prime_loop(1);
//    for(int i = 0; i < n; i++)
//    {
//       cout << a[i] << " ";
//    }
//    cout << endl;
//    return 0;
//    // insert code here...
//    //std::cout << "Hello, World!\n";
//
//    //stack<string> i;
//    //i.push("1");
//
//
//
//
//
//
//
//
//    //fast_sorting test
//
////    sort_practise *sp = new sort_practise();
////
////    vector<int> i{10,9,8,7,6,5,4,3,2,1};
////    //sp->findSmallestItem(i, i.begin());
////    clock_t startTime,endTime;
////    startTime = clock();
////    vector<int> afterSort = sp->sorting_practise(i);
////    endTime = clock();
////    for(vector<int>::iterator index = afterSort.begin();index != afterSort.end();index++)
////
////    {
////        cout << *index << endl;
////    }
//
//
//
//
//
//
//
//    //breadthFirstSearch test
//
////    breadthFirstSearch *b = new breadthFirstSearch();
////
////
////    b->findSeller();
//
////
//
//
//
//
//
//
//    //Dijkstra's algorithm
//
////    Dijkstra_Algorithm *DA = new Dijkstra_Algorithm();
////
////    //DA->print_information();
////    DA->findRoad();
//
//
//
//
//
//
//
//
//
//    //Approximation_algorithm
//
////    Approx_Algo *aa = new Approx_Algo();
////
////    aa->find_bestStations();
//
//
//
//
//
//    //sort practise
//
//
////    int in[9] = {9,8,7,6,5,4,3,2,1};
////    vector<int> a(in,in+9);
//    //基类测试
//       //Sort_P sp;
//       //sp.sort(a);
//       //sp.show(a);
//       //bool s = sp.isSorted(a);
//
//    //选择排序测试
//     //Selection_sort ss;
//    //ss.show(a);
//    //ss.sort(a);
//    //ss.show(a);
//
//    //插入排序测试
////    Insertion_sort is;
////    is.show(a);
////    is.sort(a);
////    is.show(a);
//    //希尔排序
////    Shell_sort ss;
////    ss.show(a);
////    ss.sort(a);
////    ss.show(a);
//    //归并排序测试
////    merge_sort ms;
////    ms.show(a);
////    ms.sort(a);
////    ms.show(a);
//    //快速排序测试
////    Quick_sort qs;
////    qs.show(a);
////    qs.sort(a);
////    qs.show(a);
//    //快速排序三切分测试
////    Quick_sort qs;
////    qs.show(a);
////    qs.sort(a);
////    qs.show(a);
//
//    //优先队列 练习
//
////    struct tmp1
////    {
////        int x;
////        tmp1(int a)
////        {
////            x = a;
////        }
////        bool  operator<(const tmp1 &a) const
////        {
////            return x <a.x; //大堆顶
////        }
////    };
////
////    struct tmp2
////    {
////    bool operator() (tmp1 a, tmp1 b)
////            {
////            return a.x < b.x;
////            }
////            };
////
////            tmp1 e1(1);
////            tmp1 e2(2);
////            tmp1 e3(3);
////            priority_queue<tmp1> d;
////            d.push(e2);
////            d.push(e3);
////            d.push(e1);
////            while (!d.empty())
////            {
////            cout << d.top().x << '\n';
////            d.pop();
////            }
////            cout << endl;
////
////            priority_queue<tmp1, vector<tmp1>, tmp2> f;
////            f.push(e2);
////            f.push(e3);
////            f.push(e1);
////            while(!f.empty())
////            {
////            cout << f.top().x << '\n';
////            f.pop();
////            }
////            cout << endl;
//
////    MaxPQ<int> maxpq(5);
////    MinPQ<int> minpq(5);
////    maxpq.insert(1);
//////    maxpq.print();
////    maxpq.insert(2);
//////    maxpq.print();
////    maxpq.insert(3);
//////    maxpq.print();
////    maxpq.insert(4);
//////    maxpq.print();
////    maxpq.insert(5);
//////    maxpq.print();
////    minpq.insert(3);
////    minpq.insert(1);
////    minpq.insert(2);
////    minpq.insert(4);
////    minpq.insert(5);
////
////    cout << maxpq.deleteMax() << " " << minpq.deleteMin() << endl;
////
////   maxpq.print();
////    cout << maxpq.deleteMax() << " " << minpq.deleteMin() << endl;
////  maxpq.print();
////    cout << maxpq.deleteMax() << " " << minpq.deleteMin() << endl;
////   maxpq.print();
////    cout << maxpq.deleteMax() << " " << minpq.deleteMin() << endl;
////  maxpq.print();
////    cout << maxpq.deleteMax() << " " << minpq.deleteMin() << endl;
////
////    maxpq.print();
////    minpq.print();
////
//
//
//
////符号表 二分法有序数组 测试
//
////    vector<int> a{1,2,3,4,5,6};
////    vector<int>::iterator iter = a.end();
////    cout << a.size() << endl;
////    cout << *(a.end()-1) << endl;
//
////    vector<int> key{1,3,5,7,9,11,13,15};
////    //key.resize(9,14);
////    //cout << *(key.end()-1) << endl;
////    vector<float> value{1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8};
////
////
////    //put 测试
////
////
////
////
////   ArraySearch<int, float> as(key, value);
//////    cout << "keyn比" << 5 << "小的key的数量为 " << as.rank_normal(5) << endl;
////    cout << "插入元素" << endl;
////    as.put(2, 1.11);
////    as.print_as();
////
////    //cout << as.get(9) << endl;
////    cout << "删除元素" << endl;
////    as.deleteKey(2);
////
//////
//////
////    return 0;
////
//
//
//// 二叉查找树符号表 测试
////
////    BST<int, string> bb;
////    bb.put(5, "Jack");
////    bb.put(3,"Cythia");
////    bb.put(7,"Bob");
////    bb.put(4, "Jason");
////    bb.put(6, "Justin");
////    bb.put(2, "BILI");
////    bb.put(1, "Martin");
////    bb.put(0, "kiss of death");
////    //bb.deleteNode(4);
////    //bb.print_all();
////    //queue<int> *q;
////    bb.keys(1,5);
//    //cout << q->size() << endl;
////    int n = int(q->size());
////    for(int j=0; j<n; j++)
////    {
////        int e =q->front();
////        cout << e << " ";
////        q->pop();
////    }
////    cout << endl;
//
//    //bb.get(4);
//    //bb.get(4);
//
//    //bb.put(2, "BILI");
//
//    //cout << bb.select(3) << endl;
//    //bb.deleteMax();
//    //cout << bb.get(1) << endl;
//    //cout << bb.max() << endl;
//    //cout << bb.ceiling(4) << endl;
//
//    //cout << bb.min() << endl;
//
//
////    cout << bb.get(1) << endl;
////    cout << bb.get(2) << endl;
////    cout << bb.get(3) << endl;
////    cout << bb.get(4) << endl;
////    cout << bb.get(5) << endl;
////    cout << bb.get(6) << endl;
////    cout << bb.get(7) << endl;
//
//
//
//
////选择问题
//    //vector<int> aa{7,5,3,2,6,4,1,8};
//    //Select_Problem ssp;
//   // ssp.select_x(aa, 4);
//    //inversion inv;
//    //cout << inv.InversePairs(aa) << endl;
////红黑树测试
////    static const bool RED = true;
////    static const bool BLACK = false;
////
////    bool color = BLACK;
////    color = (color == BLACK ? RED : BLACK);
////    cout << color << endl;
////    RBT<int, string> rbt;
////    rbt.put(1, "a");
////    rbt.put(2, "b");
////    rbt.put(3, "c");
////    rbt.put(4, "d");
////    rbt.put(5, "a");
////    rbt.put(6, "b");
////    rbt.put(7, "c");
////    rbt.put(8, "d");
////    rbt.print_all();
////    cout << "delete" << endl;
//////    rbt.deleteMax();
////    rbt.delete_RBTNode(5);
////    rbt.print_all();
////    cout << rbt.check_size() << endl;
////    vector<int>a{5,2,8,6,3,6,9,7};
////    Solution so;
////    cout << "最长递增子序列为：";
////    cout << so.llis(a) << endl;
//}
//
//

//
//
//const int n = 3;
//
//int r[n+1][n+1];//存放各最优二叉树搜索树的根
//
//int c[n+1][n+1];//最优二查搜索树的代价（最小平均路长）
//
//int w[n+1][n+1];//存放内部节点外部节点的累计权值
//
//
//
//void OBST(int *p,int *q,int n);
//
//void printOBST(int r[n+1][n+1],int i,int j,int n,int f,char ch);
//
//
//
//int main()
//
//{
//
//    int p[]={1,2,4,3};//内部节点的权值
//
//    int q[]={0,0,0,0};//外部节点的权值
//
//
//
//    cout<<"内部节点的权值为："<<endl;
//
//    for(int i=1;i<n+1;i++)//输出内部节点的权值
//
//    {
//
//        cout<<"p"<<i<<"="<<p[i]<<endl;
//
//    }
//
//
//
//    cout<<"外部节点的权值为："<<endl;
//
//    for(int j=0;j<n+1;j++)//输出外部节点的权值
//
//    {
//
//        cout<<"q"<<j<<"="<<q[j]<<endl;
//
//    }
//
//
//
//    cout<<endl;
//
//    OBST(p,q,n);
//
//    cout<<"最优二叉搜索树的最小平均路长为："<<c[0][n]*0.1<<endl;
//
//
//
//    cout<<"构造的最优二叉搜索树为："<<endl;//输出最优二叉树搜索树各个子树的根
//
//    printOBST(r,0,n,n,0,'0');
//
//
//
//    system("pause");
//
//    return 0;
//
//}
//
//
//
//void OBST(int *p,int *q,int n)//自底向上逐步构造w[][],c[][],r[][]
//
//{
//
//    int i,j,k,m,min,u;
//
//
//
//    for(i=0;i<n;i++){
//
//        //初始化
//
//        w[i][i]=q[i];
//
//        c[i][i]=r[i][i]=0;
//
//
//
//        //构造只有一个内部节点的最优二查搜索树
//
//        w[i][i+1]=w[i][i]+p[i+1]+q[i+1];
//
//        r[i][i+1]=i+1;
//
//        c[i][i+1]=w[i][i+1];
//
//    }
//
//
//
//    w[n][n]=q[n];
//
//    r[n][n]=c[n][n]=0;
//
//
//
//    for(m=2;m<=n;m++)//构造具有m个内部节点的最优二查搜索树
//
//    {
//
//        for(i=0;i<=n-m;i++){
//
//            //在前一颗树的基础上加以内部节点和一外部节点
//
//            //分别构造具有m，m+1...n个内部节点的最优二查搜索树
//
//            j=i+m;
//
//
//
//            w[i][j]=w[i][j-1]+p[j]+q[j];//构造出从i到j的累计权值
//
//
//
//            min=c[i+1][j];
//
//            u=i+1;//假定i+1为根
//
//
//
//            for(k=i+2;k<=j;k++)//轮流以i+2,i+3...j为根，选代价最小的送min，其根为u
//
//            {
//
//                if(c[i][k-1]+c[k][j]<min)
//
//                {
//
//                    min=c[i][k-1]+c[k][j];
//
//                    u=k;
//
//                }
//
//            }
//
//
//
//            c[i][j]=w[i][j]+min;
//
//            r[i][j]=u;
//
//        }
//
//    }
//
//}
//
//
//
//void printOBST(int r[n+1][n+1],int i,int j,int n,int f,char ch)
//
//{
//
//    int k=r[i][j];
//
//    if(k>0)
//
//    {
//
//        if(f==0)
//
//        {
//            cout<<"T("<<i<<","<<j<<")"<<"的根节点为："<<k<<endl;
//        }
//
//        else
//        {
//            cout << ch << "子树： " << "T(" << i << "," << i << ")" << "的根节点为：" << k << endl;
//        }
//
//        int t = k-1;
//        if(t >= i && t <= n)
//        {
//            printOBST(r, i, t, n, k, 'L');
//        }
//        int m = k+1;
//        if(t <= j)
//        {
//            printOBST(r, m-1, j, n, k, 'R');
//        }
//    }
    
    
    
    
    
    
    //图API测试
    //ifstream data("/Users/crystal-dragon-lyb/Documents/C-algorithm_practise/C_algorithm/C_algorithm/Dat_Structure/Dat_Structure/data/graph_initial.txt");
//    int dat;
//    while (data >> dat)
//    {
//        cout << dat <<endl;
//    }
//    string path = "/Users/crystal-dragon-lyb/Documents/C-algorithm_practise/C_algorithm/C_algorithm/Dat_Structure/Dat_Structure/data/graph_initial.txt";
//    SimpleGraph graph(path);
    
    
    
    
    
    
    
    
    // 测试分支界限法
    
//    int W[6] = {5, 3, 2, 10, 4, 2};
//    int V[6] = {11, 8, 15, 18, 12, 6};
//    int capacity = 20; //背包容量
//    Item_Information items[6];
//    //初始化Item_Information数组
//    for(int i = 0; i < 6; i++)
//    {
//        items[i].item_ID = i;
//        items[i].item_Value = V[i];
//        items[i].item_Weight = W[i];
//        items[i].Value_Weight_Ratio = (float)V[i]/W[i];
//    }
//    sort(items, items+6, ItemCmp); //对 items 根据 Value_Weight_Ratio 进行优先级排序
//    Print_AllValues(V);
//    Print_AllWeight(W);
//    //打印一下相关信息
//    BranchandBround bb(items, capacity);
//    cout << "最大价值为：" << bb.maxValue << endl;
//    cout << "队列中元素最多为：" << bb.maxSize << endl;
//    cout << "搜索次数为：" << bb.searchCount << endl;
//    return 0;
    
    
    
    
//测试二分图最大匹配
    
    //测试深度优先搜索
//    string path = "/Users/crystal-dragon-lyb/Documents/C-algorithm_practise/C_algorithm/C_algorithm/Dat_Structure/Dat_Structure/data/graph_initial_1.txt";
//    undirect_Graph graph(path);
    
//    DepthFirstGraph dfg(graph, 0);
//    cout << dfg.getCount() << endl;
//    int startPoint = 0;
//    DepthFirstGraphForSearchPaths dffsp(graph, startPoint);
//    dffsp.printPaths();
//    for(int v = 4; v < graph.countOfVertex(); v++)
//    {
//
//        auto x = dffsp.pathStore(v);
//        while(!x.empty())
//        {
//            cout << x.top() << endl;
//            x.pop();
//        }
//        break;
//    }
    //    SearchPaths sp;
    //    for(int v = 0; v < graph.countOfVertex(); v++)
    //    {
    //        cout << startPoint << " to " << v << " :  ";
    //        if(sp.hasPathTo(dffsp, v))
    //        {
    //            auto x = sp.pathStore(dffsp, v);
    //            for(int i = 0; i < x.size(); i++)
    //            {
    //                if(x.top() == startPoint)
    //                {
    //                    cout << x.top() << endl;
    //                }
    //                else
    //                {
    //                    cout << " - " << x.top() ;
    //                    x.pop();
    //                }
    //
    //
    //            }
    //            cout << endl;
    //
    //        }
    //    }
    //
    
    
    
    
    
    //测试广度优先搜索
    string path = "/Users/crystal-dragon-lyb/Documents/C-algorithm_practise/C_algorithm/C_algorithm/Dat_Structure/Dat_Structure/data/graph_initial_1.txt";
    undirect_Graph graph(path);
    graph.print_allVertexAndEdge();
    int startPoint = 0;
    
    
    BreadthFirstPaths bfs(graph, startPoint);
    bfs.printPaths();
    for(int v = 4; v < graph.countOfVertex(); v++)
        {
    
            auto x = bfs.pathStore(v);
            while(!x.empty())
            {
                cout << x.top() << endl;
                x.pop();
            }
            break;
        }
    
    
    
    
    
    
    

    
    
    
    
    return 0;
    
    
}



