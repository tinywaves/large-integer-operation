//
// Created by Donghui Zheng on 2021/1/2 22:49.
//

#include "Action.h"
/**
 * @details 欢迎界面.
 * @param void.
 * @return void.
 */
void action::welcomeScreen() {
    cout << "***长整数运算程序***\n";
    cout << "!该程序根据屏幕提示选择想要进行的操作\n\n";
    cout << "作者：郑东晖\n";
    cout << "班级：大数据工程应用1901班\n";
    cout << "学号：201906062631\n";
    cout << "\n";
}
/**
 * @details 目录选择界面界面.
 * @param void.
 * @return void.
 */
void action::directorySelectionScreen() {
    cout << "请选择：\n";
    cout << "1.不涉及文件的大整数运算\n";
    cout << "2.涉及文件的大整数运算\n";
    cout << "3.退出程序\n";
    cout << "你的选择：";
}
/**
 * @details 选择进制运算.
 * @param void.
 * @return void.
 */
void action::baseSelection() {
    cout << "请选择:\n";
    cout << "1.十进制\n";
    cout << "2.二进制\n";
    cout << "你的选择：";
}
/**
 * @details 退出程序.
 * @param void.
 * @return void.
 */
void action::exitSystem() {
    cout << "\n欢迎下次使用！\n\n";
    system("pause");
    exit(0);
}
/**
 * @details 运算方法.
 * @param void.
 * @return void.
 */
void action::selectionDirectory() {
    cout << "输入1、2、3、4或5选择操作：\n";
    cout << "1、加法\n";
    cout << "2、减法\n";
    cout << "3、乘法\n";
    cout << "4、除法\n";
    cout << "5、指数\n";
    cout << "6、退出\n";
    cout << "你的选择：";
}
/**
 * @details 不涉及文件的大整数计算.
 * @param void.
 * @return void.
 */
void action::operationWithoutFile() {
    int choice;
    baseSelection();//调用进制选择函数.
    cin >> choice;
    fflush(stdin);//清除缓存.
    while (choice > 2 || choice < 1) {
        cout << "您的输入有误，请重新输入！\n" << endl;
        baseSelection();//调用进制选择函数.
        cin >> choice;
        fflush(stdin);//清除缓存.
    }
    if (choice == 1) {//十进制.
        int flag = 1;
        while (flag) {
            int operatorSelection;
            selectionDirectory();//调用运算方法函数.
            cin >> operatorSelection;
            fflush(stdin);//清除缓存.
            while (operatorSelection > 6 || operatorSelection < 1) {
                cout << "您的输入有误，请重新输入！\n" << endl;
                selectionDirectory();//调用运算方法函数.
                cin >> operatorSelection;
                fflush(stdin);//清除缓存.
            }
            linkList list1, list2;
            switch (operatorSelection) {
                case 1: {//加法.
                    bigInteger::inputListWithoutFile(list1, list2);
                    cout << "list1:" << list1 << endl;
                    cout << "list2:" << list2 << endl;
                    cout << "加法 —>>> (list1 + list2) = ";
                    bigInteger::addition_bigInteger(list1, list2, 10);
                    break;
                }
                case 2: {//减法.
                    bigInteger::inputListWithoutFile(list1, list2);
                    cout << "list1:" << list1 << endl;
                    cout << "list2:" << list2 << endl;
                    cout << "减法 —>>> (list1 - list2) = ";
                    bigInteger::subtraction_bigInteger(list1, list2, 10);
                    break;
                }
                case 3: {//乘法.
                    bigInteger::inputListWithoutFile(list1, list2);
                    cout << "list1:" << list1 << endl;
                    cout << "list2:" << list2 << endl;
                    cout << "乘法 —>>> (list1 * list2) = ";
                    bigInteger::multiplication_bigInteger(list1, list2, 10);
                    break;
                }
                case 4: {//除法.
                    bigInteger::inputListWithoutFile(list1, list2);
                    cout << "list1:" << list1 << endl;
                    cout << "list2:" << list2 << endl;
                    cout << "除法 —>>> (list1 / list2) = ";
                    bigInteger::division_bigInteger(list1, list2, 10);
                    break;
                }
                case 5: {//指数运算.
                    bigInteger::inputListWithoutFile(list1, list2);
                    cout << "list1:" << list1 << endl;
                    cout << "list2:" << list2 << endl;
                    cout << "指数运算 —>>> (list1 ^ list2) = ";
                    bigInteger::exponentialCalculation_bigInteger(list1, list2, 10);
                    break;
                }
                default: {
                    break;
                }
            }
            if (operatorSelection == 6) {
                cout << "Exit?(0.Yes/1.No):";
                cin >> choice;
                flag = choice;
            }
        }
    } else {//二进制.
        int flag = 1;
        while (flag) {
            int operatorSelection;
            selectionDirectory();//调用运算方法函数.
            cin >> operatorSelection;
            fflush(stdin);//清除缓存.
            while (operatorSelection > 6 || operatorSelection < 1) {
                cout << "您的输入有误，请重新输入！\n" << endl;
                selectionDirectory();//调用运算方法函数.
                cin >> operatorSelection;
                fflush(stdin);//清除缓存.
            }
            linkList list1, list2;
            switch (operatorSelection) {
                case 1: {//加法.
                    bigInteger::inputListWithoutFile(list1, list2);
                    cout << "list1:" << list1 << endl;
                    cout << "list2:" << list2 << endl;
                    cout << "加法 —>>> (list1 + list2) = ";
                    bigInteger::addition_bigInteger_binarySystem(list1, list2);
                    break;
                }
                case 2: {//减法.
                    bigInteger::inputListWithoutFile(list1, list2);
                    cout << "list1:" << list1 << endl;
                    cout << "list2:" << list2 << endl;
                    cout << "减法 —>>> (list1 - list2) = ";
                    bigInteger::subtraction_bigInteger_binarySystem(list1, list2);
                    break;
                }
                case 3: {//乘法.
                    bigInteger::inputListWithoutFile(list1, list2);
                    cout << "list1:" << list1 << endl;
                    cout << "list2:" << list2 << endl;
                    cout << "乘法 —>>> (list1 * list2) = ";
                    bigInteger::multiplication_bigInteger_binarySystem(list1, list2);
                    break;
                }
                case 4: {//除法.
                    bigInteger::inputListWithoutFile(list1, list2);
                    cout << "list1:" << list1 << endl;
                    cout << "list2:" << list2 << endl;
                    cout << "除法 —>>> (list1 / list2) = ";
                    bigInteger::division_bigInteger_binarySystem(list1, list2);
                    break;
                }
                case 5: {//指数运算.
                    bigInteger::inputListWithoutFile(list1, list2);
                    cout << "list1:" << list1 << endl;
                    cout << "list2:" << list2 << endl;
                    cout << "指数运算 —>>> (list1 ^ list2) = ";
                    bigInteger::exponentialCalculation_bigInteger(list1, list2, 2);
                    break;
                }
                default: {
                    break;
                }
            }
            if (operatorSelection == 6) {
                cout << "Exit?(0.Yes/1.No):";
                cin >> choice;
                flag = choice;
            }
        }
    }
}
/**
 * @details 涉及文件的大整数计算.
 * @param void.
 * @return void.
 */
void action::operationWithFile() {
    int choice;
    baseSelection();//调用进制选择函数.
    cin >> choice;
    fflush(stdin);//清除缓存.
    while (choice > 2 || choice < 1) {
        cout << "您的输入有误，请重新输入！\n" << endl;
        baseSelection();//调用进制选择函数.
        cin >> choice;
        fflush(stdin);//清除缓存.
    }
    if (choice == 1) {//十进制.
        int flag = 1;
        while (flag) {
            int operatorSelection;
            selectionDirectory();//调用运算方法函数.
            cin >> operatorSelection;
            fflush(stdin);//清除缓存.
            while (operatorSelection > 6 || operatorSelection < 1) {
                cout << "您的输入有误，请重新输入！\n" << endl;
                selectionDirectory();//调用运算方法函数.
                cin >> operatorSelection;
                fflush(stdin);//清除缓存.
            }
            linkList list1, list2;
            switch (operatorSelection) {
                case 1: {//加法.
                    bigInteger::listOperateWithFile_decimalSystem(list1, list2, '+');
                    break;
                }
                case 2: {//减法.
                    bigInteger::listOperateWithFile_decimalSystem(list1, list2, '-');
                    break;
                }
                case 3: {//乘法.
                    bigInteger::listOperateWithFile_decimalSystem(list1, list2, '*');
                    break;
                }
                case 4: {//除法.
                    bigInteger::listOperateWithFile_decimalSystem(list1, list2, '/');
                    break;
                }
                case 5: {//指数运算.
                    bigInteger::listOperateWithFile_decimalSystem(list1, list2, '^');
                    break;
                }
                default: {
                    break;
                }
            }
            if (operatorSelection == 6) {
                cout << "Exit?(0.Yes/1.No):";
                cin >> choice;
                flag = choice;
            }
        }
    } else {//二进制.
        int flag = 1;
        while (flag) {
            int operatorSelection;
            selectionDirectory();//调用运算方法函数.
            cin >> operatorSelection;
            fflush(stdin);//清除缓存.
            while (operatorSelection > 6 || operatorSelection < 1) {
                cout << "您的输入有误，请重新输入！\n" << endl;
                selectionDirectory();//调用运算方法函数.
                cin >> operatorSelection;
                fflush(stdin);//清除缓存.
            }
            linkList list1, list2;
            switch (operatorSelection) {
                case 1: {//加法.
                    bigInteger::listOperateWithFile_binarySystem(list1, list2, '+');
                    break;
                }
                case 2: {//减法.
                    bigInteger::listOperateWithFile_binarySystem(list1, list2, '-');
                    break;
                }
                case 3: {//乘法.
                    bigInteger::listOperateWithFile_binarySystem(list1, list2, '*');
                    break;
                }
                case 4: {//除法.
                    bigInteger::listOperateWithFile_binarySystem(list1, list2, '/');
                    break;
                }
                case 5: {//指数运算.
                    bigInteger::listOperateWithFile_binarySystem(list1, list2, '^');
                    break;
                }
                default: {
                    break;
                }
            }
            if (operatorSelection == 6) {
                cout << "Exit?(0.Yes/1.No):";
                cin >> choice;
                flag = choice;
            }
        }
    }
}
