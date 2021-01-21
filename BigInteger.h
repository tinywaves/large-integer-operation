//
// Created by Donghui Zheng on 2020/12/22 14:58.
//

#ifndef OPERATION_OF_LARGE_INTEGERS_BIGINTEGER_H
#define OPERATION_OF_LARGE_INTEGERS_BIGINTEGER_H

#include <iostream>
#include <string>
#include <fstream>
#include "LinkList.h"
#include "Node.h"
using namespace std;
//大整数类.
class bigInteger {
public:
    /**
     * @details 将大整数（链表）转换为字符串.
     * @param list.
     * @return string:返回一个字符串.
     */
    static string translateToString(linkList &list);
    /**
     * @details 将数据写入文件.
     * @param data:待写入的数据.
     * @param url:文件路径.
     * @return void.
     */
    static void writeFile(const string& data, const string& url);
    /**
     * @details 大整数大小比较.
     * @param list1:链表1.
     * @param list2:链表2.
     * @return int:返回1代表list1>list2,-1代表list1<list2,0代表list1=list2.
     */
    static int comparisonOfSize(linkList &list1, linkList &list2);
    /**
     * @details 链表长度比较.
     * @param list1:链表1.
     * @param list2:链表2.
     * @return bool:若链表1大于链表2,返回true,反之返回false.
     */
    static bool compareListLength(linkList &list1, linkList &list2);
    /**
     * @details 不涉及文件的输入函数,将操作数存入链表.
     * @param object1:用于存储大整数1.
     * @param object2:用于存储大整数2.
     * @return void.
     */
    static void inputListWithoutFile(linkList &object1, linkList &object2);
    /**
     * @details 涉及文件的操作函数,十进制.
     * @param object1:用于存储大整数1.
     * @param object2:用于存储大整数2.
     * @param choice:运算种类.
     * @return void.
     */
    static void listOperateWithFile_decimalSystem(linkList &object1, linkList &object2, char choice);
    /**
     * @details 涉及文件的操作函数,二进制.
     * @param object1:用于存储大整数1.
     * @param object2:用于存储大整数2.
     * @param choice:运算种类.
     */
    static void listOperateWithFile_binarySystem(linkList &object1, linkList &object2, char choice);
    /**
     * @details 加法辅助函数.
     * @param object1:操作数1，即大整数1.
     * @param object2:操作数2，即大整数2.
     * @param base:进制.
     * @return linkList.
     */
    static linkList additionAuxiliaryFunction(linkList &object1, linkList &object2, int base);
    /**
     * @details 减法辅助函数.
     * @param object1:操作数1，即大整数1.
     * @param object2:操作数2，即大整数2.
     * @param base:进制.
     * @return linkList.
     */
    static linkList subtractionAuxiliaryFunction(linkList &object1, linkList &object2, int base);
    /**
     * @details 乘法辅助函数.
     * @param object1:操作数1，即大整数1.
     * @param object2:操作数2，即大整数2.
     * @param base:进制.
     * @return linkList.
     */
    static linkList multiplicationAuxiliaryFunction(linkList &object1, linkList &object2, int base);
    /**
     * @details 乘法子函数.
     * @param operator1:操作数1.
     * @param operator2:操作数2.
     * @param base:进制.
     * @return linkList.
     */
    static linkList divisionFunction(linkList &operator1, linkList &operator2, int base);
    /**
     * @details 除法辅助函数.
     * @param object1:操作数1，即大整数1.
     * @param object2:操作数2，即大整数2.
     * @param base:进制.
     * @return linkList.
     */
    static linkList divisionAuxiliaryFunction(linkList &object1, linkList &object2, int base);
    /**
     * @details 十进制加法函数,可正可负.
     * @param operation1:操作数1，即大整数1.
     * @param operation2:操作数2，即大整数2.
     * @param base:进制.
     * @return void.
     */
    static void addition_bigInteger(linkList &operation1, linkList &operation2, int base);
    /**
     * @details 二进制加法函数.
     * @param object1:操作数1，即大整数1.
     * @param object2:操作数2，即大整数2.
     * @return void.
     */
    static void addition_bigInteger_binarySystem(linkList &object1, linkList &object2);
    /**
     * @details 十进制减法函数,可正可负.
     * @param operation1:操作数1，即大整数1.
     * @param operation2:操作数2，即大整数2.
     * @param base:进制.
     * @return void.
     */
    static void subtraction_bigInteger(linkList &operation1, linkList &operation2, int base);
    /**
     * @details 二进制减法函数.
     * @param object1:操作数1，即大整数1.
     * @param object2:操作数2，即大整数2.
     * @return void.
     */
    static void subtraction_bigInteger_binarySystem(linkList &object1, linkList &object2);
    /**
     * @details 十进制乘法函数,可正可负.
     * @param operation1:操作数1，即大整数1.
     * @param operation2:操作数2，即大整数2.
     * @param base:进制.
     * @return void.
     */
    static void multiplication_bigInteger(linkList &operation1, linkList &operation2, int base);
    /**
     * @details 二进制乘法函数.
     * @param object1:操作数1，即大整数1.
     * @param object2:操作数2，即大整数2.
     * @return void.
     */
    static void multiplication_bigInteger_binarySystem(linkList &object1, linkList &object2);
    /**
     * @details 十进制除法函数,可正可负.
     * @param operation1:操作数1，即大整数1.
     * @param operation2:操作数2，即大整数2.
     * @param base:进制.
     * @return void.
     */
    static void division_bigInteger(linkList &operation1, linkList &operation2, int base);
    /**
     * @details 二进制除法函数.
     * @param object1:操作数1，即大整数1.
     * @param object2:操作数2，即大整数2.
     * @return void.
     */
    static void division_bigInteger_binarySystem(linkList &object1, linkList &object2);
    /**
     * @details 十、二进制指数运算函数.
     * @param operation1:操作数1，即大整数1.
     * @param operation2:操作数2，即大整数2.
     * @param base:进制.
     * @return void.
     */
    static void exponentialCalculation_bigInteger(linkList &operation1, linkList &operation2, int base);
};

#endif //Operation_OF_LARGE_INTEGERS_BIGINTEGER_H
