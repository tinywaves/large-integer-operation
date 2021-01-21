//
// Created by Donghui Zheng on 2020/12/21 8:45.
//

#ifndef OPERATION_OF_LARGE_INTEGERS_NODE_H
#define OPERATION_OF_LARGE_INTEGERS_NODE_H

#include <iostream>
using namespace std;
//节点类.
class node {
public:
    //存储的数据.
    int data;
    //前驱指针和后继指针.
    node *prev, *next;
    /**
     * @details 无参构造函数.
     * @param void.
     * @return
     */
    node() : data(0), prev(nullptr), next(nullptr) {}
    /**
     * @details 有参构造函数.
     * @param item:数据.
     * @param prevNode:前驱指针.
     * @param nextNode:后继指针.
     * @return
     */
    explicit node(const int &item, node *prevNode = nullptr, node *nextNode = nullptr) :
            data(item), prev(prevNode), next(nextNode) {}
};

#endif //OPERATION_OF_LARGE_INTEGERS_NODE_H
