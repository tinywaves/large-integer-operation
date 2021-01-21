//
// Created by Donghui Zheng on 2020/12/21 11:10.
//

#include "LinkList.h"

node * linkList::returnHeadPoint() {
    return headPoint;
}
int & linkList::returnLinkListLength() {
    return linkListLength;
}
int & linkList::returnLinkListFlag() {
    return flag;
}
int linkList::linkListSize() const {
    return this->linkListLength;//直接返回linkListLength成员.
}
int linkList::linkListFlag() const {
    return this->flag;//直接返回flag成员.
}
linkList::linkList() {
    node *headNode = new node();//创建头节点.
    headNode->prev = headNode;//头节点前驱指向自己.
    headNode->next = headNode;//头节点后继指向自己.
    headPoint = headNode;//头指针指向头节点.
    linkListLength = 0;//双向链表长度为0.
    flag = 0;//正负标记设置为0.
}
linkList::linkList(const linkList &object) {
    if (object.linkListSize() == 0) {//双向链表为空链表,链表中仅有头节点.
        node *headNode = new node();//创建头节点.
        headNode->prev = headNode;//头节点前驱指向自己.
        headNode->next = headNode;//头节点后继指向自己.
        headPoint = headNode;//头指针指向头节点.
        linkListLength = 0;//双向链表长度为0.
        flag = 0;//正负标记设置为0.
    } else {//双向链表非空.
        //头节点的建立.
        node *headNode = new node();
        headNode->prev = headNode;
        headNode->next = headNode;
        headPoint = headNode;
        linkListLength = 0;
        node *tempPoint = object.headPoint->next;//第一个节点.
        /**
         * frontNode : 指向第一个节点的指针.
         * behindNode : 记录目前的链的最后一个节点.
         * newNode : 新创建的待加入的指针.
         */
        node *frontNode = new node();//指向第一个节点的指针,第一个节点的深拷贝.
        frontNode->data = tempPoint->data;
        node *behindNode = frontNode;//记录目前的链的最后一个节点.
        tempPoint = tempPoint->next;
        int size = object.linkListSize();//链表长度,即应当复制的节点数量.
        int index = 1;//已复制的节点数量.
        while (index < size) {
            node *newNode = new node();//复制新节点.
            behindNode->next = newNode;
            newNode->prev = behindNode;
            behindNode = behindNode->next;//更新最后一个节点为新节点.
            behindNode->data = tempPoint->data;
            tempPoint = tempPoint->next;
            ++index;
        }
        headNode->next = frontNode;//将新链加到头节点后.
        frontNode->prev = headNode;
        behindNode->next = headNode;//将最后一个节点指向头节点,构成循环链.
        headNode->prev = behindNode;
        linkListLength = size;
        flag = object.flag;//正负标记设置为object的flag.
    }
}
linkList & linkList::operator=(const linkList &rightHandObject) {
    if (this == &rightHandObject) {//判断进行自我赋值.
        return *this;
    } else {
        if (rightHandObject.linkListSize() == 0) {//双向链表为空链表,链表中仅有头节点.
            node *headNode = new node();//创建头节点.
            headNode->prev = headNode;//头节点前驱指向自己.
            headNode->next = headNode;//头节点后继指向自己.
            headPoint = headNode;//头指针指向头节点.
            linkListLength = 0;//双向链表长度为0.
            flag = 0;//正负标记设置为0.
        } else {//双向链表非空.
            //头节点的建立.
            node *headNode = new node();
            headNode->prev = headNode;
            headNode->next = headNode;
            headPoint = headNode;
            linkListLength = 0;
            node *tempPoint = rightHandObject.headPoint->next;//第一个节点.
            /**
             * frontNode : 指向第一个节点的指针.
             * behindNode : 记录目前的链的最后一个节点.
             * newNode : 新创建的待加入的指针.
             */
            node *frontNode = new node();//指向第一个节点的指针,第一个节点的深拷贝.
            frontNode->data = tempPoint->data;
            node *behindNode = frontNode;//记录目前的链的最后一个节点.
            tempPoint = tempPoint->next;
            int size = rightHandObject.linkListSize();//链表长度,即应当复制的节点数量.
            int index = 1;//已复制的节点数量.
            while (index < size) {
                node *newNode = new node();//复制新节点.
                behindNode->next = newNode;
                newNode->prev = behindNode;
                behindNode = behindNode->next;//更新最后一个节点为新节点.
                behindNode->data = tempPoint->data;
                tempPoint = tempPoint->next;
                ++index;
            }
            headNode->next = frontNode;//将新链加到头节点后.
            frontNode->prev = headNode;
            behindNode->next = headNode;//将最后一个节点指向头节点,构成循环链.
            headNode->prev = behindNode;
            linkListLength = size;
            flag = rightHandObject.flag;//正负标记设置为rightHandObject的flag.
        }
        return *this;
    }
}
linkList::~linkList() {
    node *tempPoint = headPoint;
    for (int i = 0; i <= this->linkListLength; ++i) {
        node *deletePoint = tempPoint;
        tempPoint = tempPoint->next;
        delete deletePoint;
    }
}
void linkList::display(ostream &out) {
    if (flag == -1) {
        out << '-';
    }
    node *tempPoint = headPoint->next;
    for (int i = 0; i < this->linkListLength; ++i) {//依个遍历.
        out << tempPoint->data;
        tempPoint = tempPoint->next;
    }
    cout << endl << "digit:" << linkListLength;
}
void linkList::createLinkListWithoutForValue(int length) {
    //头节点的建立.
    node *headNode = new node();
    headNode->prev = headNode;
    headNode->next = headNode;
    headPoint = headNode;
    linkListLength = 0;
    node *frontNode = new node();//指向第一个节点的指针,第一个节点的创建.
    node *behindNode = frontNode;//记录目前的链的最后一个节点.
    int number = 1;//已创建的新节点数量.
    while (number < length) {
        node *newNode = new node();
        behindNode->next = newNode;
        newNode->prev = behindNode;
        behindNode = behindNode->next;
        ++number;
    }
    headNode->next = frontNode;//头指针指向第一个节点.
    frontNode->prev = headNode;
    behindNode->next = headNode;//将最后一个节点指向头节点,构成循环链.
    headNode->prev = behindNode;
    linkListLength = length;
    flag = 0;//正负标记设置为0.
}
void linkList::createLinkListWithForValue(int length) {
    //头节点的建立.
    node *headNode = new node(0, nullptr, nullptr);
    headNode->prev = headNode;
    headNode->next = headNode;
    headPoint = headNode;
    linkListLength = 0;
    node *frontNode = new node(0, nullptr, nullptr);//指向第一个节点的指针,第一个节点的创建.
    node *behindNode = frontNode;//记录目前的链的最后一个节点.
    int number = 1;//已创建的新节点数量.
    while (number < length) {
        node *newNode = new node(0, nullptr, nullptr);
        behindNode->next = newNode;
        newNode->prev = behindNode;
        behindNode = behindNode->next;
        ++number;
    }
    headNode->next = frontNode;//头指针指向第一个节点.
    frontNode->prev = headNode;
    behindNode->next = headNode;//将最后一个节点指向头节点,构成循环链.
    headNode->prev = behindNode;
    linkListLength = length;
    flag = 0;//正负标记设置为0.
}
void linkList::insert(int item, int position) {
    node *newPoint = new node(item, nullptr);//待插入的新节点.
    node *prePoint = headPoint;
    node *point = prePoint->next;
    for (int i = 0; i < position; ++i) {
        prePoint = prePoint->next;
        point = point->next;
    }
    newPoint->next = prePoint->next;
    prePoint->next = newPoint;
    point->prev = newPoint;
    newPoint->prev = prePoint;
    linkListLength += 1;//长度自增1.
}
void linkList::erase(int position) {
    node *prePoint = headPoint;
    node *point = prePoint->next;
    node *behindPoint = point->next;
    for (int i = 1; i < position; ++i) {
        prePoint = prePoint->next;//位置前.
        point = point->next;//删除节点的位置.
        behindPoint = behindPoint->next;//位置后.
    }
    prePoint->next = behindPoint;
    behindPoint->prev = prePoint;
    delete point;
    linkListLength -= 1;//长度自减1.
}
ostream & operator<<(ostream &out, linkList &printList) {
    printList.display(out);//调用display函数.
    return out;
}
