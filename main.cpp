//
// Created by Donghui Zheng on 2020/12/22 15:05.
//

#include <iostream>
#include "Action.h"
using namespace std;

int main() {
    action::welcomeScreen();//调用欢迎界面.
    system("pause");
    system("cls");
    while (true) {//死循环.
        int choice;//用户输入的选择.
        int flag = 1;//用于判断是否退出运算.
        action::directorySelectionScreen();//调用目录选择界面.
        cin >> choice;
        fflush(stdin);//清除缓存.
        while (choice > 3 || choice < 1) {
            cout << "您的输入有误，请重新输入！\n" << endl;
            action::directorySelectionScreen();//调用目录选择界面.
            cin >> choice;
            fflush(stdin);//清除缓存.
        }
        int continueKey;
        switch (choice) {
            case 1://不涉及文件的大整数计算.
                while (flag) {//运算操作.
                    action::operationWithoutFile();//调用operationWithoutFile函数.
                    cout << "\n继续运算？（选择1：是/0：否）：";
                    fflush(stdin);//清除缓存.
                    cin >> continueKey;
                    flag = continueKey;
                    system("cls");
                }
                break;
            case 2://涉及文件的大整数计算.
                while (flag) {//运算操作.
                    action::operationWithFile();//调用operationWithFile函数.
                    cout << "\n继续运算？（选择1：是/0：否）：";
                    fflush(stdin);//清除缓存.
                    cin >> continueKey;
                    flag = continueKey;
                    system("cls");
                }
                break;
            default:
                action::exitSystem();
                break;
        }
    }
    return 0;
}
