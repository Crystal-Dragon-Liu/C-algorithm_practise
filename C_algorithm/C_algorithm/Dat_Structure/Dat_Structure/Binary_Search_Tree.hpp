//
//  Binary_Search_Tree.hpp
//  Dat_Structure
//
//  Created by  云子谣 on 2020/2/29.
//  Copyright © 2020  云子谣. All rights reserved.
//

#ifndef Binary_Search_Tree_hpp
#define Binary_Search_Tree_hpp

#include <stdio.h>
#include <iostream>
#include <queue>





#endif /* Binary_Search_Tree_hpp */
using namespace std;
//节点类
template<typename KEY, typename VALUE> class BSTNode
{
public:
    KEY key;
    VALUE value;
    BSTNode * LeftNode = NULL;
    BSTNode * RightNode = NULL;
    BSTNode * parent = NULL;
    int N;
    BSTNode(KEY key, VALUE value, int N);
    
};
template<typename KEY, typename VALUE> BSTNode<KEY, VALUE>::BSTNode(KEY key, VALUE value, int N)
{
    this->key = key;
    this->value = value;
    this->N = N;
}

//二叉查找树
template<typename KEY, typename VALUE>
class BST
{
private:
    BSTNode<KEY, VALUE> *m_root;
    VALUE get(BSTNode<KEY, VALUE> *bstnode, KEY key);
    
    BSTNode<KEY, VALUE>* put(BSTNode<KEY, VALUE> *bstnode, KEY key, VALUE value);
    
    BSTNode<KEY, VALUE>* min(BSTNode<KEY, VALUE> *bstnode);
    BSTNode<KEY, VALUE>* max(BSTNode<KEY, VALUE> *bstnode);
    BSTNode<KEY, VALUE>* floor(BSTNode<KEY, VALUE>* bstnode, KEY key);
    BSTNode<KEY, VALUE>* ceiling(BSTNode<KEY, VALUE>* bstnode, KEY key);
    BSTNode<KEY, VALUE>* select(BSTNode<KEY, VALUE> *bstnode, int k);
    int rank(BSTNode<KEY, VALUE> *bstnode, KEY key);
    BSTNode<KEY, VALUE>* deleteMin(BSTNode<KEY, VALUE> *bstnode);
    BSTNode<KEY, VALUE>* deleteMax(BSTNode<KEY, VALUE> *bstnode);
    BSTNode<KEY, VALUE>* deleteNode(BSTNode<KEY, VALUE> *bstnode, KEY key);
    void keys(BSTNode<KEY, VALUE> *x, KEY lok, KEY hik);
    int size(BSTNode<KEY, VALUE> *bstnode);
    void print_queue(queue<KEY> queue, KEY lo, KEY hi);
    void print_all(BSTNode<KEY, VALUE> *bstnode);
    queue<KEY> *m_q;
    
    
    
public:
    int size();
    VALUE get(KEY key);
    void put(KEY key, VALUE value);
    KEY min();
    KEY max();
    KEY floor(KEY key);
    KEY ceiling(KEY key);
    KEY select(int K);
    int rank(KEY key);
    void deleteMin();
    void deleteMax();
    void deleteNode(KEY key);
    BSTNode<KEY, VALUE>* deleteMin_tool(BSTNode<KEY, VALUE> *bstnode);
    void print_queue();
    void print_all();
    queue<KEY> keys();
    void keys(KEY lok, KEY hik);
 
};

//size
template<typename KEY, typename VALUE> int BST<KEY, VALUE>:: size()
{
    return size(m_root);
}
template<typename KEY, typename VALUE> int BST<KEY, VALUE>::size(BSTNode<KEY, VALUE> *bstnode)
{
    if(bstnode == NULL) return 0;
    else return bstnode->N;
    
}
//get
template<typename KEY, typename VALUE> VALUE BST<KEY, VALUE>::get(KEY key)
{
    cout << "准备从根节点开始查询" << endl;
    return get(m_root, key);
}
template<typename KEY, typename VALUE> VALUE BST<KEY, VALUE>::get(BSTNode<KEY, VALUE> *bstnode, KEY key)
{
    
    if(bstnode == NULL)
    {
        cout << "未找到数据" << endl;
        return NULL;
    }
    if(key < bstnode->key)
    {
        cout << "指定键小于 " << bstnode->key << "向左子树方向查询" << endl;
         return get(bstnode->LeftNode, key);
    }
    else if (key > bstnode->key)
    {
         cout << "指定键大于 " << bstnode->key << "向右子树方向查询" << endl;
         return get(bstnode->RightNode, key);
    }
    else
    {
        cout << "已找到数据" << endl;
        return bstnode->value;
    }
}
//put
template<typename KEY, typename VALUE> void BST<KEY, VALUE>::put(KEY key, VALUE value)
{
    m_root = put(m_root, key, value);
}


template<typename KEY, typename VALUE> BSTNode<KEY, VALUE> * BST<KEY, VALUE>::put(BSTNode<KEY, VALUE> *bstnode, KEY key, VALUE value)
{
    if(bstnode == NULL)
        return new BSTNode<KEY, VALUE>(key, value, 1);
    //如果节点为空，则从此节点添加一个新的
    if(key < bstnode->key) bstnode->LeftNode = put(bstnode->LeftNode, key, value);
    else if(key > bstnode->key) bstnode->RightNode = put(bstnode->RightNode, key, value);
    else bstnode->value = value;
    bstnode->N = size(bstnode->RightNode) + size(bstnode->LeftNode) + 1;
    return bstnode;
}
// min

template<typename KEY, typename VALUE> KEY BST<KEY, VALUE>::min()
{
    return min(m_root)->key;
}
template<typename KEY, typename VALUE> BSTNode<KEY, VALUE>* BST<KEY, VALUE>::min(BSTNode<KEY, VALUE> *bstnode)
{
    if(bstnode->LeftNode == NULL)
        return bstnode;
    return min(bstnode->LeftNode);
}



//floor
template<typename KEY, typename VALUE> KEY BST<KEY, VALUE>::floor(KEY key)
{
    BSTNode<KEY, VALUE> *bstnode = floor(m_root, key);
    if(bstnode == NULL)
    {
        return NULL;
    }
    return bstnode->key;
}

template<typename KEY, typename VALUE> BSTNode<KEY, VALUE>* BST<KEY, VALUE>::floor(BSTNode<KEY, VALUE>* bstnode, KEY key)
{
    if(bstnode == NULL)
        return NULL;
    if(key == bstnode->key) return bstnode;
    if(key < bstnode->key)
        return floor(bstnode->LeftNode, key);
    BSTNode<KEY, VALUE> *bstnode_r = floor(bstnode->RightNode, key);
    if(bstnode_r != NULL) return bstnode_r; //找到比 bstnode->key大，但比key小的节点
    else return bstnode;//未找到比bstnode->key大，比 key小的节点
}



// ceiling 找到比key大的最小键

template<typename KEY, typename VALUE> KEY BST<KEY, VALUE>::ceiling(KEY key)
{
    BSTNode<KEY, VALUE> *bstnode = ceiling(m_root, key);
    if(bstnode == NULL)
        return NULL;
    else return bstnode->key;
}
template<typename KEY, typename VALUE> BSTNode<KEY, VALUE>* BST<KEY, VALUE>::ceiling(BSTNode<KEY, VALUE> * bstnode, KEY key)
{
    if(bstnode == NULL)
        return NULL;
    if(bstnode->key == key)
        return bstnode;
    //找到等于key的节点
    if(key > bstnode->key)
        return ceiling(bstnode->RightNode, key);
    //如果key比 bstnode->key大，说明 比key大的最小键只会出现在 bstnode的右子树中
    BSTNode<KEY, VALUE> *bstnode_l = ceiling(bstnode->LeftNode, key);
    if(bstnode_l != NULL) return bstnode_l;
    else return bstnode;
    //如果key比 bstnode->key小，那么 bstnode的key很有可能就已经是比key大的最小键，但不确定，因此需要继续向左子树前进，查看是否有比bstnode更小，但是比key更大的键存在，如果遍历到底部，仍然没有找到，那就确认bstnode就是比key大的最小键
}


template<typename KEY, typename VALUE> KEY BST<KEY, VALUE>::max()
{
    return max(m_root)->key;
}

template<typename KEY, typename VALUE> BSTNode<KEY, VALUE>* BST<KEY, VALUE>::max(BSTNode<KEY, VALUE> *bstnode)
{
    if(bstnode->RightNode == NULL) return bstnode;
    else return max(bstnode->RightNode);
}
template<typename KEY, typename VALUE> KEY BST<KEY, VALUE>::select(int k)
{
    return select(m_root, k)->key;
}
template<typename KEY, typename VALUE> BSTNode<KEY, VALUE>*  BST<KEY, VALUE>::select(BSTNode<KEY, VALUE> *bstnode, int k)
{
     if(bstnode == NULL)
         return NULL;
    int t = size(bstnode->LeftNode);
    if(t > k) return select(bstnode->LeftNode, k);
    if(t < k) return select(bstnode->RightNode, k-t-1);
    else return bstnode;
}


//rank
template<typename KEY, typename VALUE> int BST<KEY, VALUE>::rank(KEY key)
{
    return rank(m_root, key);
}
template<typename KEY, typename VALUE> int BST<KEY, VALUE>::rank(BSTNode<KEY, VALUE> *bstnode, KEY key)
{
    if(bstnode == NULL) return 0;
    if(key < bstnode->key)
        return rank(bstnode->LeftNode, key);
    if(key > bstnode->key)
        return 1 + size(bstnode->LeftNode) + rank(bstnode->RightNode, key);
    else return size(bstnode->LeftNode);
}





// deletemin
template<typename KEY, typename VALUE> void BST<KEY, VALUE>::deleteMin()
{
    m_root = deleteMin(m_root);
}
template<typename KEY, typename VALUE> BSTNode<KEY, VALUE>* BST<KEY, VALUE>::deleteMin(BSTNode<KEY, VALUE> *bstnode)
{
    if(bstnode->LeftNode == NULL)
    {
        BSTNode<KEY, VALUE>* new_bstnode;
        new_bstnode = bstnode->RightNode;
        cout << "即将删除最小键为" << bstnode->key << "的节点" << endl;
        delete bstnode;
        cout << "已删除最小键" << endl;
        return new_bstnode;
    }
    cout << "键为" << bstnode->key << "的节点不是最小节点,继续向左子树遍历" << endl;
    bstnode->LeftNode = deleteMin(bstnode->LeftNode);
    bstnode->N = size(bstnode->LeftNode) + size(bstnode->RightNode) + 1;
    cout << "更新键为" << bstnode->key << "的节点计数器值为" << bstnode->N << endl;
    return bstnode;
}

template<typename KEY, typename VALUE> void BST<KEY, VALUE>::deleteMax()
{
    m_root = deleteMax(m_root);
}
template<typename KEY, typename VALUE> BSTNode<KEY, VALUE>* BST<KEY, VALUE>::deleteMax(BSTNode<KEY, VALUE> *bstnode)
{
    if(bstnode->RightNode == NULL)
    {
        BSTNode<KEY, VALUE> *new_bstnode;
        new_bstnode = bstnode->LeftNode;
        cout << "即将删除最大键为" << bstnode->key << "的节点" << endl;
        delete bstnode;
        cout << "已删除最大键" << endl;
        return new_bstnode;
    }
    cout << "键为" << bstnode->key << "的节点不是最大节点,继续向右子树遍历" << endl;
    cout << "此时键为" << bstnode->key << "的节点的右节点键为: " << bstnode->RightNode->key << endl;
    bstnode->RightNode = deleteMax(bstnode->RightNode);
    cout << "此时键为" << bstnode->key << "的节点的右节点键变为: " << bstnode->RightNode->key << endl;
    bstnode->N = size(bstnode->LeftNode) + size(bstnode->RightNode) +1;
    cout << "更新键为" << bstnode->key << "的节点计数器值为: " << bstnode->N << endl;
    return bstnode;
}


// delete
template<typename KEY, typename VALUE> BSTNode<KEY, VALUE>* BST<KEY, VALUE>::deleteMin_tool(BSTNode<KEY, VALUE> *bstnode)
{
    if(bstnode->LeftNode == NULL)
        return bstnode->RightNode;
    bstnode->LeftNode = deleteMin_tool(bstnode->LeftNode);
    bstnode->N = size(bstnode->LeftNode) + size(bstnode->RightNode) + 1;
    return bstnode;
}

template<typename KEY, typename VALUE> void BST<KEY, VALUE>::deleteNode(KEY key)
{
    cout << m_root->N << endl;
    m_root = deleteNode(m_root, key);
    cout << m_root->N << endl;
}
template<typename KEY, typename VALUE> BSTNode<KEY, VALUE>* BST<KEY, VALUE>::deleteNode(BSTNode<KEY, VALUE> *bstnode, KEY key)
{
    if(bstnode == NULL)
        return NULL;
    if(key < bstnode->key)
    {
        cout << "指定键小于键为"<< bstnode->key << "的当前节点，深入该节点的左节点" << endl;
        bstnode->LeftNode = deleteNode(bstnode->LeftNode, key);
    }
        
    else if(key > bstnode->key)
    {
        bstnode->RightNode = deleteNode(bstnode->RightNode, key);
        cout << "指定键大于键为"<< bstnode->key << "的当前节点，深入该节点的右节点" << endl;
    }
    else
    {
        if(bstnode->LeftNode == NULL)
        {
            cout << "找到指定键，但其左节点为空，返回该节点的右节点" << endl;
            BSTNode<KEY, VALUE> *new_bstnode;
            new_bstnode = bstnode->RightNode;
            cout << "正在删除键为" << bstnode->key << "的节点" << endl;
            delete bstnode;
            cout << "已删除" << endl;
            return new_bstnode;
        }
        if(bstnode->RightNode == NULL)
        {
         cout << "找到指定键，但其右节点为空，返回该节点的左节点" << endl;
         BSTNode<KEY, VALUE> *new_bstnode;
         new_bstnode = bstnode->LeftNode;
         cout << "正在删除键为" << bstnode->key << "的节点" << endl;
         delete bstnode;
         cout << "已删除" << endl;
         return new_bstnode;
        }
        BSTNode<KEY, VALUE> *deleted_node;
        deleted_node = bstnode;
        bstnode = min(deleted_node->RightNode);
        bstnode->RightNode = deleteMin_tool(deleted_node->RightNode);
        bstnode->LeftNode = deleted_node->LeftNode;
    }
    bstnode->N = size(bstnode->LeftNode) + size(bstnode->RightNode) + 1;
    return bstnode;
}



template<typename KEY, typename VALUE> void BST<KEY, VALUE>::print_all()
{
    print_all(m_root);
}
template<typename KEY, typename VALUE> void BST<KEY, VALUE>::print_all(BSTNode<KEY, VALUE> *bstnode)
{
    if(bstnode == NULL) return;
    print_all(bstnode->LeftNode);
    cout << bstnode->key << endl;
    print_all(bstnode->RightNode);
}
template<typename KEY, typename VALUE> void BST<KEY, VALUE>::keys(KEY lok, KEY hik)
{
    keys(m_root, lok, hik);
}
template<typename KEY, typename VALUE> void BST<KEY, VALUE>::keys(BSTNode<KEY, VALUE> *x, KEY lok, KEY hik)
{
    if(x == NULL) return;
    if(lok < x->key) keys(x->LeftNode, lok, hik);
    if(lok <= x->key && hik >= x->key) cout << x->key;
    if(lok > x->key) keys(x->RightNode, lok, hik);
}
