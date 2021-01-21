//
// Created by Donghui Zheng on 2021/1/2 21:07.
//

#ifndef OPERATION_OF_LARGE_INTEGERS_ACTION_H
#define OPERATION_OF_LARGE_INTEGERS_ACTION_H

#include <iostream>
#include "LinkList.h"
#include "BigInteger.h"
using namespace std;
//操作类.
class action {
public:
    static void welcomeScreen();
    static void directorySelectionScreen();
    static void baseSelection();
    static void exitSystem();
    static void selectionDirectory();
    static void operationWithoutFile();
    static void operationWithFile();
};

#endif //OPERATION_OF_LARGE_INTEGERS_ACTION_H
