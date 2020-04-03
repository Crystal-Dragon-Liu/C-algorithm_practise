//
//  RedBlackBST
//  Dat_Structure
//
//  Created by  云子谣 on 2020/3/19.
//  Copyright © 2020  云子谣. All rights reserved.
//

#ifndef RedBlackBST_hpp
#define RedBlackBST_hpp

#include <stdio.h>
#include <iostream>

#endif /* RedBlackBST_hpp */
static const bool RED = true;
static const bool BLACK = false;
using namespace std;
template<typename KEY, typename VALUE> class RBTNode
{
public:
    KEY m_key;
    VALUE m_value;
    RBTNode *LeftNode = NULL;
    RBTNode *RightNode = NULL;
    int m_N;
    bool m_color;
    RBTNode(KEY key, VALUE value, int N, bool m_color);
    bool isRed(RBTNode<KEY, VALUE> *rbtnode);
};
template<typename KEY, typename VALUE> RBTNode<KEY, VALUE>::RBTNode(KEY key, VALUE value, int N, bool color)
{
    m_key = key;
    m_value = value;
    m_N = N;
    m_color = color;
}
template<typename KEY, typename VALUE> bool  RBTNode<KEY, VALUE>::isRed(RBTNode<KEY, VALUE> *rbtnode)
{
    if(rbtnode == NULL) return false;
    return rbtnode->m_color == RED;
}


template<typename KEY, typename VALUE> class RBT
{
private:
    int size(RBTNode<KEY, VALUE> *rbtnode);
    RBTNode<KEY, VALUE> *m_root = NULL;
    RBTNode<KEY, VALUE>* rotateLeft(RBTNode<KEY, VALUE> *rbtnode);
    RBTNode<KEY, VALUE>* rotateRight(RBTNode<KEY, VALUE> *rbtnode);
    void flipColors(RBTNode<KEY, VALUE> *rbtnode);
    void flipColors_delete(RBTNode<KEY, VALUE> *rbtnode);
    RBTNode<KEY, VALUE>* put(RBTNode<KEY, VALUE>* rbtnode, KEY key, VALUE value);
    bool isRed(RBTNode<KEY, VALUE> *rbtnode);
    RBTNode<KEY, VALUE>* moveRedLeft(RBTNode<KEY, VALUE> *rbtnode);
    RBTNode<KEY, VALUE>* moveRedRight(RBTNode<KEY, VALUE> *rbtnode);
    RBTNode<KEY, VALUE>* deleteMin(RBTNode<KEY, VALUE> *rbtnode);
    RBTNode<KEY, VALUE>* deleteMax(RBTNode<KEY, VALUE> *rbtnode);
    RBTNode<KEY, VALUE>* balance(RBTNode<KEY, VALUE> *rbtnode);
    void print_all(RBTNode<KEY, VALUE> *rbtnode);
    VALUE get(RBTNode<KEY, VALUE> *rbtnode, KEY key);
    RBTNode<KEY, VALUE>* delete_RBTNode(RBTNode<KEY, VALUE> *rbtnode, KEY key);
    RBTNode<KEY, VALUE>* min(RBTNode<KEY, VALUE> *rbtnode);
public:
    KEY min();
    int size();
    void put(KEY key, VALUE value);
    void deleteMin();
    void deleteMax();
    void print_all();
    int check_size();
    VALUE get(KEY key);
    bool contains(KEY key);
    void delete_RBTNode(KEY key);
};
//min
template<typename KEY, typename VALUE> KEY RBT<KEY, VALUE>::min()
{
    return min(m_root)->m_key;
}
template<typename KEY, typename VALUE> RBTNode<KEY, VALUE>* RBT<KEY, VALUE>::min(RBTNode<KEY, VALUE> *rbtnode)
{
    if(rbtnode->LeftNode == NULL) return rbtnode;
    else return min(rbtnode->LeftNode);
}
//delete
template<typename KEY, typename VALUE> void RBT<KEY, VALUE>::delete_RBTNode(KEY key)
{
    if (!isRed(m_root->LeftNode) && !isRed(m_root->RightNode)) {
        m_root->m_color = RED;
    }
    m_root = delete_RBTNode(m_root, key);
    if(m_root != NULL) m_root->m_color = BLACK;
}

template<typename KEY, typename VALUE> RBTNode<KEY, VALUE>* RBT<KEY, VALUE>::delete_RBTNode(RBTNode<KEY, VALUE> *rbtnode, KEY key)
{
    if(key < rbtnode->m_key)
    {
        //如果指定键小于 当前节点的键 ，首先保证当前节点或当前左子节点不是2-节点，从父节点开始判断
        if(!isRed(rbtnode->LeftNode) && !isRed(rbtnode->LeftNode->  LeftNode))
            rbtnode = moveRedLeft(rbtnode);
        rbtnode->LeftNode = delete_RBTNode(rbtnode->LeftNode, key);//继续对🌲遍历
    }
    else
    {
        if(isRed(rbtnode->LeftNode))//判断左子节点是否为红色，如果是红色就向右旋转
            rbtnode = rotateRight(rbtnode);
        if(key == rbtnode->m_key && (rbtnode->RightNode == NULL))
            //判断待删除的节点是否为当前节点，且右子节点是否为空，此时待删除的节点为叶子节点，这里只需要判断右子节点是否为NULL即可，因为即使如果原来查找到的键所在节点是左侧的叶子节点，也会因为上面的判断条件而变为右叶子节点
        {   
            delete rbtnode;
            return NULL;
        }
        if(!isRed(rbtnode->RightNode) && !isRed(rbtnode->RightNode->LeftNode))
            rbtnode = moveRedRight(rbtnode);
        if(key == rbtnode->m_key)
        {
            RBTNode<KEY, VALUE> *x = min(rbtnode->RightNode);
            rbtnode->m_key = x->m_key;
            rbtnode->m_value = x->m_value;
            rbtnode->RightNode =  deleteMin(rbtnode->RightNode);
        }
        else rbtnode->RightNode = delete_RBTNode(rbtnode->RightNode, key);
    }
    return balance(rbtnode);
}


//contains
template<typename KEY, typename VALUE> bool RBT<KEY, VALUE>::contains(KEY key)
{
    return get(key) != 0;
}
// get
template<typename KEY, typename VALUE> VALUE RBT<KEY, VALUE>::get(KEY key)
{
    return get(m_root, key);
}
template<typename KEY, typename VALUE> VALUE RBT<KEY, VALUE>::get(RBTNode<KEY, VALUE> *rbtnode, KEY key)
{
    while (rbtnode != NULL) {
        if(key < rbtnode->m_key)
            rbtnode = rbtnode->LeftNode;
        else if(key > rbtnode->m_key)
            rbtnode = rbtnode->RightNode;
        else return rbtnode->m_value;
    }
    return static_cast<int>(0);
}

template<typename KEY, typename VALUE> int RBT<KEY, VALUE>::check_size()
{
    if(m_root == NULL) return 0;
    else return m_root->m_N;
}
//isRed
template<typename KEY, typename VALUE> bool RBT<KEY, VALUE>::isRed(RBTNode<KEY, VALUE> *rbtnode)
{
    if(rbtnode == NULL)
           return false;
    return rbtnode->m_color == RED;
}

//size
template<typename KEY,  typename VALUE> int RBT<KEY, VALUE>::size()
{
    return size(m_root);
}

template<typename KEY,  typename VALUE> int RBT<KEY, VALUE>::size(RBTNode<KEY, VALUE> *rbtnode)
{
    if(rbtnode == NULL) return 0;
    else return rbtnode->m_N;
}
//rotate
template<typename KEY, typename VALUE> RBTNode<KEY, VALUE>* RBT<KEY, VALUE>::rotateLeft(RBTNode<KEY, VALUE> *rbtnode)
{
    RBTNode<KEY, VALUE>* x = rbtnode->RightNode;
    rbtnode->RightNode = x->LeftNode;
    x->LeftNode = rbtnode;
    x->m_color = rbtnode->m_color;
    rbtnode->m_color = RED;
    x->m_N = rbtnode->m_N;
    rbtnode->m_N = 1 + size(rbtnode->LeftNode) + size(rbtnode->RightNode);
    return x;
}
template<typename KEY, typename VALUE> RBTNode<KEY, VALUE>* RBT<KEY, VALUE>::rotateRight(RBTNode<KEY, VALUE> *rbtnode)
{
    RBTNode<KEY, VALUE>* x = rbtnode->LeftNode;
    rbtnode->LeftNode = x->RightNode;
    x->RightNode = rbtnode;
    x->m_color = rbtnode->m_color;
    rbtnode->m_color = RED;
    x->m_N = rbtnode->m_N;
    rbtnode->m_N = 1 + size(rbtnode->LeftNode) + size(rbtnode->RightNode);
    return x;
}

template<typename KEY, typename VALUE> void RBT<KEY, VALUE>::flipColors(RBTNode<KEY, VALUE> *rbtnode)
{
    
    rbtnode->m_color = RED;
    rbtnode->RightNode->m_color = BLACK;
    rbtnode->LeftNode->m_color = BLACK;
}

//put
template<typename KEY, typename VALUE> void RBT<KEY, VALUE>::put(KEY key, VALUE value)
{
    m_root = put(m_root, key, value);
    m_root->m_color = BLACK;
}
template<typename KEY, typename VALUE> RBTNode<KEY, VALUE>* RBT<KEY, VALUE>::put(RBTNode<KEY, VALUE>* rbtnode, KEY key, VALUE value)
{
    if(rbtnode == NULL)
        return new RBTNode<KEY, VALUE>(key, value, 1, RED);
    
    if(key < rbtnode->m_key) rbtnode->LeftNode = put(rbtnode->LeftNode, key, value);
    else if (key > rbtnode->m_key) rbtnode->RightNode = put(rbtnode->RightNode, key, value);
    else rbtnode->m_value = value;
    
    if(!isRed(rbtnode->LeftNode)&&isRed(rbtnode->RightNode))
        rbtnode = rotateLeft(rbtnode);
    if(isRed(rbtnode->LeftNode) && isRed(rbtnode->RightNode))
        flipColors(rbtnode);
    if(isRed(rbtnode->LeftNode) && isRed(rbtnode->LeftNode->LeftNode))
        rbtnode = rotateRight(rbtnode);
    rbtnode->m_N = size(rbtnode->LeftNode) + 1 + size(rbtnode->RightNode);
    return rbtnode;
}

template<typename KEY, typename VALUE> void RBT<KEY, VALUE>::deleteMin()
{
   if(!isRed(m_root->LeftNode) && !isRed(m_root->RightNode)) //如果根节点的左子节点的color不是red，右子节点的color也不是red
       m_root->m_color = RED;
    m_root = deleteMin(m_root);
    if(m_root != NULL)
        m_root->m_color = BLACK;
}







//deleteMin
template<typename KEY, typename VALUE> RBTNode<KEY, VALUE>* RBT<KEY, VALUE>::deleteMin(RBTNode<KEY, VALUE> *rbtnode)
{
    if(rbtnode->LeftNode == NULL)
    {
        delete rbtnode;
        return NULL;
    }//如果当前节点的左节点为空，说明当前节点就是最小的节点，返回NULL，即删除当前节点。
    if(!isRed(rbtnode->LeftNode) && !isRed(rbtnode->LeftNode->LeftNode))
        //如果当前节点的左子节点color 为black， 而当前节点左子节点的左子节点的color 也是black
        moveRedLeft(rbtnode);
    rbtnode->LeftNode = deleteMin(rbtnode->LeftNode);
    return balance(rbtnode);
}
//flipcolor
template<typename KEY, typename VALUE> void RBT<KEY, VALUE>::flipColors_delete(RBTNode<KEY, VALUE> *rbtnode)
{
    rbtnode->m_color = (rbtnode->m_color == BLACK ? RED : BLACK);
    rbtnode->RightNode->m_color = (rbtnode->RightNode->m_color == BLACK ? RED : BLACK);
    rbtnode->LeftNode->m_color = (rbtnode->LeftNode->m_color == BLACK ? RED : BLACK);
}
//moveRedLeft
template<typename KEY, typename VALUE> RBTNode<KEY, VALUE>* RBT<KEY, VALUE>::moveRedLeft(RBTNode<KEY, VALUE> *rbtnode)
{
    //如果当前节点的左子节点color 为black， 而当前节点左子节点的左子节点的color 也是black
    flipColors_delete(rbtnode);
    //rbtnode的左子节点和右子节点的color都变成red，rbtnode的color变为black
    //如果用例中的树只有三个节点，此时已经可以返回一个4-节点
    if(isRed(rbtnode->RightNode->LeftNode))//如果当前节点的右子节点的左子节点的color是red
    {
        rbtnode->RightNode = rotateRight(rbtnode->RightNode);
        //旋转rbtnode->RightNode 和 rbtnode->Rightnode->LeftNode的位置，以免形成rbtnode->RightNode是red,rbtnode->RightNode->LeftNode也是红色的情况
        rbtnode = rotateLeft(rbtnode);
        flipColors_delete(rbtnode);//调整红黑链接
    }
    return rbtnode;
}
//balance
template<typename KEY, typename VALUE> RBTNode<KEY, VALUE>* RBT<KEY, VALUE>::balance(RBTNode<KEY, VALUE> *rbtnode)
{
    if(isRed(rbtnode->RightNode)) rbtnode = rotateLeft(rbtnode);
    if(isRed(rbtnode->LeftNode) && isRed(rbtnode->LeftNode->LeftNode))
        rbtnode = rotateRight(rbtnode);
    if(isRed(rbtnode->LeftNode) && isRed(rbtnode->RightNode))
        flipColors_delete(rbtnode);
    rbtnode->m_N = size(rbtnode->LeftNode) + 1 + size(rbtnode->RightNode);
    return rbtnode;
}

template<typename KEY, typename VALUE> void RBT<KEY, VALUE>::print_all()
{
    print_all(m_root);
}

template<typename KEY, typename VALUE> void RBT<KEY, VALUE>::print_all(RBTNode<KEY, VALUE> *rbtnode)
{
    if(rbtnode == NULL) return;
    print_all(rbtnode->LeftNode);
    cout << rbtnode->m_key << endl;
    print_all(rbtnode->RightNode);
}


//deleteMax
template<typename KEY, typename VALUE> void RBT<KEY, VALUE>::deleteMax()
{
    if(m_root == NULL)
    {
        cout << "🌲为空" << endl;
        return;
    }
    if(!isRed(m_root->LeftNode) && !isRed(m_root->RightNode))
        m_root->m_color = RED;//此步骤不明白
    m_root = deleteMax(m_root);
    if(m_root != NULL)
        m_root->m_color = BLACK;
}
template<typename KEY, typename VALUE> RBTNode<KEY, VALUE>* RBT<KEY, VALUE>::deleteMax(RBTNode<KEY, VALUE> *rbtnode)
{
    if(isRed(rbtnode->LeftNode))
        rbtnode = rotateRight(rbtnode); //保证最大键是红节点
    if(rbtnode->RightNode == NULL)
    {
        delete rbtnode;
        return NULL;
    }
    if(!isRed(rbtnode->RightNode) && !isRed(rbtnode->RightNode->LeftNode))
        //此处之所以不判断rbtnode->RightNode->RightNode是因为rbtnode->RightNode->RightNode此时不可能是红色的，但在往下深入的过程中，会遇到判断LeftNode是否为红色,是就旋转，因此判断rbtnode->RightNode->LeftNode的效果就是判断当前节点是否为红色或者当前节点的右节点是否为红色
        rbtnode = moveRedRight(rbtnode);
    
    rbtnode->RightNode = deleteMax(rbtnode->RightNode);
    return balance(rbtnode);
}
//moveRedRight
template<typename KEY, typename VALUE> RBTNode<KEY, VALUE>* RBT<KEY, VALUE>::moveRedRight(RBTNode<KEY, VALUE> *rbtnode)
{
    flipColors_delete(rbtnode);
    if(isRed(rbtnode->LeftNode->LeftNode))
    {
        rbtnode = rotateRight(rbtnode);
        flipColors_delete(rbtnode);
    }
    return rbtnode;
}



