//
// Created by Donghui Zheng on 2020/12/21 8:46.
//

#ifndef OPERATION_OF_LARGE_INTEGERS_LINKLIST_H
#define OPERATION_OF_LARGE_INTEGERS_LINKLIST_H

#include <iostream>
#include "Node.h"
using namespace std;
//双向链表类.
class linkList {
public:
    /**
     * @details 返回头指针.
     * @param void.
     * @return node*:头指针对象.
     */
    node* returnHeadPoint();
    /**
     * @details 返回链表长度.
     * @param void.
     * @return int&:返回一个引用.
     */
    int& returnLinkListLength();
    /**
     * @details 返回链表符号标记.
     * @param void.
     * @return int&:返回一个引用.
     */
    int& returnLinkListFlag();
    /**
     * @details 获取链表的长度.
     * @param void.
     * @return int:返回双向链表的长度.
     */
    int linkListSize() const;
    /**
     * @details 获取链表的符号.
     * @param void.
     * @return int:返回双向链表的符号.
     */
    int linkListFlag() const;
    /**
     * @details 无参构造函数.
     * @param void.
     * @return
     */
    linkList();
    /**
     * @details 拷贝构造函数,防止浅拷贝.
     * @param object:被拷贝链表对象.
     * @return
     */
    linkList(const linkList &object);
     /**
      * @details 赋值运算符重载.
      * @param rightHandObject:赋值运算符右对象.
      * @return linkList &:复制后的新对象.
      */
    linkList & operator=(const linkList &rightHandObject);
    /**
     * @details 析构函数,释放内存.
     * @param void.
     * @return
     */
    ~linkList();
    /**
     * @details 输出函数,用于输出链表.
     * @param out:输出对象.
     * @return void.
     */
    void display(ostream &out);
    /**
     * @details 创建长度为length的双向链表,节点data不进行赋值.
     * @param length:双向链表的长度.
     * @return void.
     */
    void createLinkListWithoutForValue(int length);
    /**
     * @details 创建长度为length的双向链表,节点data进行赋值为0.
     * @param length:双向链表的长度.
     * @return void.
     */
    void createLinkListWithForValue(int length);
    /**
     * @details 在position位置后面插入节点.
     * @param item:插入的数据.
     * @param position:插入的位置.
     * @return void.
     */
    void insert(int item, int position);
    /**
     * @details 删除position位置的节点.
     * @param position:删除的位置.
     * @return void.
     */
    void erase(int position);
private:
    //头指针.
    node *headPoint;
    //链表长度.
    int linkListLength;
    //大整数正负标记.
    int flag;
};
/**
 * @details 输出运算符重载.
 * @param ostream &:输出对象, linkList &:待输出对象.
 * @return ostream &:待输出对象.
 */
ostream & operator<<(ostream &, linkList &);

#endif //OPERATION_OF_LARGE_INTEGERS_LINKLIST_H
