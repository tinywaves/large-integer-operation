//
// Created by Donghui Zheng on 2020/12/22 15:02.
//

#include "BigInteger.h"

string bigInteger::translateToString(linkList &list) {
    node *back;
    int length = list.linkListSize();
    string result(length, 0);//创建长度为l,初始化为0的字符串.
    back = list.returnHeadPoint()->prev;
    for (int i = length - 1; i >= 0; i--) {//循环将链表数据输入到字符串中.
        result[i] = back->data + '0';
        back = back->prev;
    }
    if (list.linkListFlag() == -1) {
        result = "-" + result;
    }
    return result;
}
void bigInteger::writeFile(const string& data, const string& url) {
    ofstream fileStream;//文件流对象.
    fileStream.open(url, ios::out | ios::app);
    //文件不存在.
    if (!fileStream.is_open()) {
        fileStream.close();
        return;
    }
    fileStream << data << endl;
    fileStream.close();
}
int bigInteger::comparisonOfSize(linkList &list1, linkList &list2) {
    int length1 = list1.returnLinkListLength();
    int length2 = list2.returnLinkListLength();
    int flag = 0;
    if (length1 > length2) {//list1长度大于list2长度.
        flag = 1;
    } else if (length1 == length2) {//长度相等.
        node *point1 = list1.returnHeadPoint()->next;
        node *point2 = list2.returnHeadPoint()->next;
        for (int i = 0; i < length1; i++) {//从高位开始比较大小.
            if (point1->data > point2->data) {
                flag = 1;
                break;
            } else if (point1->data < point2->data) {
                flag = -1;
                break;
            }
            point1 = point1->next;
            point2 = point2->next;
        }
    } else {//list1长度小于list2长度.
        flag = -1;
    }
    return flag;
}
bool bigInteger::compareListLength(linkList &list1, linkList &list2) {
    int listLength1 = list1.linkListSize();
    int listLength2 = list2.linkListSize();
    return listLength1 > listLength2;
}
void bigInteger::inputListWithoutFile(linkList &object1, linkList &object2) {
    int length;
    node *back;
    int flag;//符号标记.
    //第一个长整数的输入及存储.
    cout << "请输入第一个操作数：";
    string string1;
    cin >> string1;
    flag = 1;
    if (string1[0] == '-') {
        string1 = string1.substr(1);
        flag = -1;
    }
    length = string1.length();
    object1.createLinkListWithoutForValue(length);//创建长度为length1的双向循环链表,赋值给object1.
    back = object1.returnHeadPoint()->prev;
    object1.returnLinkListFlag() = flag;
    //将大整数存储到链表内.
    for (int i = length - 1; i >= 0; --i) {
        back->data = string1[i] - '0';
        back = back->prev;
    }
    //第二个长整数的输入及存储.
    cout << "请输入第二个操作数：";
    string string2;
    cin >> string2;
    flag = 1;
    if (string2[0] == '-') {
        string2 = string2.substr(1);
        flag = -1;
    }
    length = string2.length();
    object2.createLinkListWithoutForValue(length);//创建长度为length1的双向循环链表,赋值给object2.
    back = object2.returnHeadPoint()->prev;
    object2.returnLinkListFlag() = flag;
    //将大整数存储到链表内.
    for (int i = length - 1; i >= 0; --i) {
        back->data = string2[i] - '0';
        back = back->prev;
    }
}
void bigInteger::listOperateWithFile_decimalSystem(linkList &object1, linkList &object2, char choice) {
    int flag;//符号标记.
    ifstream fileStream;//文件流对象.
    fileStream.open(R"(C:\Users\15590\Desktop\Operation of large integers\file\file_decimalSystem.txt)", ios::in);//打开文件.
    //文件不存在.
    if (!fileStream.is_open()) {
        fileStream.close();
        return;
    }
    //文件存在,但为空文件.
    char testData;
    fileStream >> testData;
    if (fileStream.eof()) {
        cout << "文件为空！\n";
        fileStream.close();
        return;
    }
    //若文件存在，并且数据存在.
    string string1, string2;
    int length;
    node *back;
    while (fileStream >> string1 >> string2) {
        flag = 1;
        if (string1[0] == '-') {
            string1 = string1.substr(1);
            flag = -1;
        }
        length = string1.length();
        object1.createLinkListWithoutForValue(length);//创建长度为length1的双向循环链表,赋值给object1.
        back = object1.returnHeadPoint()->prev;
        object1.returnLinkListFlag() = flag;
        //将大整数存储到链表内.
        for (int i = length - 1; i >= 0; --i) {
            back->data = string1[i] - '0';
            back = back->prev;
        }
        flag = 1;
        if (string2[0] == '-') {
            string2 = string1.substr(1);
            flag = -1;
        }
        length = string2.length();
        object2.createLinkListWithoutForValue(length);//创建长度为length1的双向循环链表,赋值给object2.
        back = object2.returnHeadPoint()->prev;
        object2.returnLinkListFlag() = flag;
        //将大整数存储到链表内.
        for (int i = length - 1; i >= 0; --i) {
            back->data = string2[i] - '0';
            back = back->prev;
        }
        cout << "list1:" << object1 << endl;
        cout << "list2:" << object2 << endl;
        switch (choice) {
            case '+': {
                cout << "加法 —>>> (list1 + list2) = ";
                addition_bigInteger(object1, object2, 10);
                break;
            }
            case '-': {
                cout << "减法 —>>> (list1 - list2) = ";
                subtraction_bigInteger(object1, object2, 10);
                break;
            }
            case '*': {
                cout << "乘法 —>>> (list1 * list2) = ";
                multiplication_bigInteger(object1, object2, 10);
                break;
            }
            case '/': {
                cout << "除法 —>>> (list1 / list2) = ";
                division_bigInteger(object1, object2, 10);
                break;
            }
            default: {
                cout << "指数运算 —>>> (list1 ^ list2) = ";
                exponentialCalculation_bigInteger(object1, object2, 10);
                break;
            }
        }
    }
    fileStream.close();
}
void bigInteger::listOperateWithFile_binarySystem(linkList &object1, linkList &object2, char choice) {
    int flag;//符号标记.
    ifstream fileStream;//文件流对象.
    fileStream.open(R"(C:\Users\15590\Desktop\Operation of large integers\file\file_binarySystem.txt)", ios::in);//打开文件.
    //文件不存在.
    if (!fileStream.is_open()) {
        fileStream.close();
        return;
    }
    //文件存在,但为空文件.
    char testData;
    fileStream >> testData;
    if (fileStream.eof()) {
        cout << "文件为空！\n";
        fileStream.close();
        return;
    }
    //若文件存在，并且数据存在.
    string string1, string2;
    int length;
    node *back;
    while (fileStream >> string1 >> string2) {
        flag = 1;
        if (string1[0] == '-') {
            string1 = string1.substr(1);
            flag = -1;
        }
        length = string1.length();
        object1.createLinkListWithoutForValue(length);//创建长度为length的双向循环链表,赋值给object1.
        back = object1.returnHeadPoint()->prev;
        object1.returnLinkListFlag() = flag;
        //将大整数存储到链表内.
        for (int i = length - 1; i >= 0; --i) {
            back->data = string1[i] - '0';
            back = back->prev;
        }
        flag = 1;
        if (string2[0] == '-') {
            string2 = string1.substr(1);
            flag = -1;
        }
        length = string2.length();
        object2.createLinkListWithoutForValue(length);//创建长度为length的双向循环链表,赋值给object2.
        back = object2.returnHeadPoint()->prev;
        object2.returnLinkListFlag() = flag;
        //将大整数存储到链表内.
        for (int i = length - 1; i >= 0; --i) {
            back->data = string2[i] - '0';
            back = back->prev;
        }
        cout << "list1:" << object1 << endl;
        cout << "list2:" << object2 << endl;
        switch (choice) {
            case '+': {
                cout << "加法 —>>> (list1 + list2) = ";
                addition_bigInteger_binarySystem(object1, object2);
                break;
            }
            case '-': {
                cout << "减法 —>>> (list1 - list2) = ";
                subtraction_bigInteger_binarySystem(object1, object2);
                break;
            }
            case '*': {
                cout << "乘法 —>>> (list1 * list2) = ";
                multiplication_bigInteger_binarySystem(object1, object2);
                break;
            }
            case '/': {
                cout << "除法 —>>> (list1 / list2) = ";
                division_bigInteger_binarySystem(object1, object2);
                break;
            }
            default: {
                cout << "指数运算 —>>> (list1 ^ list2) = ";
                exponentialCalculation_bigInteger(object1, object2, 2);
                break;
            }
        }
    }
    fileStream.close();
}
linkList bigInteger::additionAuxiliaryFunction(linkList &object1, linkList &object2, int base) {
    linkList result;
    bool lengthJudge = compareListLength(object1, object2);//判断传入的两个操作数的长度大小.
    if (lengthJudge) {//object1的长度 > object2的长度.
        int objectLength1 = object1.linkListSize();
        int objectLength2 = object2.linkListSize();
        int quotientRecord = 0;//quotient记录进位.
        node *tempPoint1 = object1.returnHeadPoint()->prev;//tempPoint1指向object1表尾节点.
        node *tempPoint2 = object2.returnHeadPoint()->prev;//tempPoint2指向object2表尾节点.
        result.createLinkListWithoutForValue(objectLength1);//创建结果链表长度为object1和object2中长度较大者.
        node *resultTempPoint = result.returnHeadPoint()->prev;//resultTempPoint指向result表尾节点.
        for (int i = 0; i < objectLength2; ++i) {//做object1和object2中长度较小者的长度次循环.
            int sum = tempPoint1->data + tempPoint2->data + quotientRecord;//sum记录每位的和.
            int valueForBit = sum % base;//valueForBit为每位应当记录的的结果.
            quotientRecord = sum / base;//quotient记录进位.
            tempPoint1 = tempPoint1->prev;
            tempPoint2 = tempPoint2->prev;
            resultTempPoint->data = valueForBit;//将结果计入和链表中.
            resultTempPoint = resultTempPoint->prev;
        }
        for (int i = objectLength2; i < objectLength1; ++i) {//做相差长度次循环.
            int sum = tempPoint1->data + quotientRecord;
            int valueForBit = sum % base;//valueForBit为每位应当记录的的结果.
            quotientRecord = sum / base;//quotient记录进位.
            tempPoint1 = tempPoint1->prev;
            resultTempPoint->data = valueForBit;//将结果计入和链表中.
            resultTempPoint = resultTempPoint->prev;
        }
        if (quotientRecord == 1) {
            result.insert(1, 0);
        }
    } else {//object1的长度 <= object2的长度.
        int objectLength1 = object1.linkListSize();
        int objectLength2 = object2.linkListSize();
        int quotientRecord = 0;//quotient记录进位.
        node *tempPoint1 = object1.returnHeadPoint()->prev;//tempPoint1指向object1表尾节点.
        node *tempPoint2 = object2.returnHeadPoint()->prev;//tempPoint2指向object2表尾节点.
        result.createLinkListWithoutForValue(objectLength2);//创建结果链表长度为object1和object2中长度较大者.
        node *resultTempPoint = result.returnHeadPoint()->prev;//resultTempPoint指向result表尾节点.
        for (int i = 0; i < objectLength1; ++i) {//做object1和object2中长度较小者的长度次循环.
            int sum = tempPoint1->data + tempPoint2->data + quotientRecord;//sum记录每位的和.
            int valueForBit = sum % base;//valueForBit为每位应当记录的的结果.
            quotientRecord = sum / base;//quotient记录进位.
            tempPoint1 = tempPoint1->prev;
            tempPoint2 = tempPoint2->prev;
            resultTempPoint->data = valueForBit;//将结果计入和链表中.
            resultTempPoint = resultTempPoint->prev;
        }
        for (int i = objectLength1; i < objectLength2; ++i) {//做相差长度次循环.
            int sum = tempPoint2->data + quotientRecord;
            int valueForBit = sum % base;//valueForBit为每位应当记录的的结果.
            quotientRecord = sum / base;//quotient记录进位.
            tempPoint1 = tempPoint1->prev;
            resultTempPoint->data = valueForBit;//将结果计入和链表中.
            resultTempPoint = resultTempPoint->prev;
        }
        if (quotientRecord == 1) {
            result.insert(1, 0);
        }
    }
    return result;
}
linkList bigInteger::subtractionAuxiliaryFunction(linkList &object1, linkList &object2, int base) {
    linkList result;
    int objectLength1 = object1.linkListSize();
    int objectLength2 = object2.linkListSize();
    if (objectLength1 > objectLength2) {//object1的长度 > object2的长度.
        int subRecord = 0;//subRecord记录借位.
        int sum = 0;
        node *tempPoint1 = object1.returnHeadPoint()->prev;//tempPoint1指向object1表尾节点.
        node *tempPoint2 = object2.returnHeadPoint()->prev;//tempPoint2指向object2表尾节点.
        result.createLinkListWithoutForValue(objectLength1);//创建结果链表长度为object1和object2中长度较大者.
        node *resultTempPoint = result.returnHeadPoint()->prev;//resultTempPoint指向result表尾节点.
        for (int i = 0; i < objectLength2; ++i) {//做object1和object2中长度较小者的长度次循环.
            if ((tempPoint1->data - subRecord) < tempPoint2->data) {//需要借位.
                sum = tempPoint1->data + base - tempPoint2->data - subRecord;//sum记录每位的差.
                subRecord = 1;//subRecord记录借位.
            } else {//不需要借位.
                sum = tempPoint1->data - tempPoint2->data - subRecord;//sum记录每位的差.
                subRecord = 0;//subRecord记录借位.
            }
            tempPoint1 = tempPoint1->prev;
            tempPoint2 = tempPoint2->prev;
            resultTempPoint->data = sum;//将结果计入和链表中.
            resultTempPoint = resultTempPoint->prev;
        }
        for (int i = objectLength2; i < objectLength1; ++i) {//做相差长度次循环.
            if (tempPoint1->data < subRecord) {//若此位为0.
                sum = tempPoint1->data - subRecord + base;//从前一位借1,sum记录每位相减的差.
                subRecord = 1;//sub记录借位.
            } else {//若此位不为为0.
                sum = tempPoint1->data - subRecord;
                subRecord = 0;//sub记录借位.
            }
            tempPoint1 = tempPoint1->prev;
            resultTempPoint->data = sum;
            resultTempPoint=resultTempPoint->prev;
        }
        if (sum == 0) {
            result.erase(1);
        }
    } else if (objectLength1 < objectLength2) {//object1的长度 < object2的长度.
        int subRecord = 0;//subRecord记录借位.
        int sum = 0;
        node *tempPoint1 = object1.returnHeadPoint()->prev;//tempPoint1指向object1表尾节点.
        node *tempPoint2 = object2.returnHeadPoint()->prev;//tempPoint2指向object2表尾节点.
        result.createLinkListWithoutForValue(objectLength2);//创建结果链表长度为object1和object2中长度较大者.
        node *resultTempPoint = result.returnHeadPoint()->prev;//resultTempPoint指向result表尾节点.
        for (int i = 0; i < objectLength1; ++i) {//做object1和object2中长度较小者的长度次循环.
            if ((tempPoint2->data - subRecord) < tempPoint1->data) {//需要借位.
                sum = tempPoint2->data + base - tempPoint1->data - subRecord;//sum记录每位的差.
                subRecord = 1;//subRecord记录借位.
            } else {//不需要借位.
                sum = tempPoint2->data - tempPoint1->data - subRecord;//sum记录每位的差.
                subRecord = 0;//subRecord记录借位.
            }
            tempPoint1 = tempPoint1->prev;
            tempPoint2 = tempPoint2->prev;
            resultTempPoint->data = sum;//将结果计入和链表中.
            resultTempPoint = resultTempPoint->prev;
        }
        for (int i = objectLength1; i < objectLength2; ++i) {//做相差长度次循环.
            if (tempPoint2->data < subRecord) {//若此位为0.
                sum = tempPoint2->data - subRecord + base;//从前一位借1,sum记录每位相减的差.
                subRecord = 1;//sub记录借位.
            } else {//若此位不为为0.
                sum = tempPoint2->data - subRecord;
                subRecord = 0;//sub记录借位.
            }
            tempPoint2 = tempPoint2->prev;
            resultTempPoint->data = sum;
            resultTempPoint=resultTempPoint->prev;
        }
        if (sum == 0) {
            result.erase(1);
        }
    } else {//object1的长度 = object2的长度.
        int sizeMark = 0;
        node *tempPoint1 = object1.returnHeadPoint()->prev;//tempPoint1指向object1表尾节点.
        node *tempPoint2 = object2.returnHeadPoint()->prev;//tempPoint2指向object2表尾节点.
        node *markPoint1 = object1.returnHeadPoint()->next;//tempPoint1指向object1第一个节点.
        node *markPoint2 = object2.returnHeadPoint()->next;//tempPoint2指向object2第一个节点.
        //循环用于比较两个长整数大小.
        for (int i = 0; i < objectLength1; ++i) {
            if (markPoint1->data > markPoint2->data) {
                sizeMark = 1;//第一个长整数大,m赋值为1.
                break;
            } else if (markPoint1->data < markPoint2->data) {
                sizeMark = 2;//第二个长整数大,m赋值为2.
                break;
            }
            markPoint1 = markPoint1->next;
            markPoint2 = markPoint2->next;
        }
        if (sizeMark == 0) {//两个长整数相等.
            result.createLinkListWithoutForValue(1);
            result.returnHeadPoint()->next->data = 0;//最后计算结果为0.
        }
        if (sizeMark == 1) {//第一个长整数大.
            result.createLinkListWithoutForValue(objectLength1);//链表长度为二者之中任意长度.
            node *resultTempPoint = result.returnHeadPoint()->prev;//resultTempPoint指向result表尾节点.
            int subRecord = 0;//subRecord记录借位.
            int sum = 0;
            for (int i = 0; i < objectLength1; i++) {//循环位数次.
                if ((tempPoint1->data - subRecord) < tempPoint2->data) {
                    sum = tempPoint1->data + base - tempPoint2->data - subRecord;//从前一位借1,sum记录每位相减的差.
                    subRecord = 1;//subRecord记录借位.
                } else {
                    sum = tempPoint1->data - tempPoint2->data - subRecord;//直接相减.
                    subRecord = 0;//sub记录借位.
                }
                tempPoint1 = tempPoint1->prev;
                tempPoint2 = tempPoint2->prev;
                resultTempPoint->data = sum;//将结果记入链表.
                resultTempPoint = resultTempPoint->prev;
            }
            if (sum == 0) {//若最大数位为0.
                result.erase(1);//将第一个节点,即数据0删除.
            }
            node *temp1 = result.returnHeadPoint()->next;
            node *temp2 = temp1->next;
            node *temp3 = result.returnHeadPoint();
            while (temp1->data == 0) {//存在0001的情况,循环用于删除多余0.
                delete temp1;//删除该节点.
                temp1 = temp2;
                temp2 = temp2->next;
                result.returnLinkListLength() = result.returnLinkListLength() - 1;//链表长度减1.
            }
            temp3->next = temp1;//删除节点之后的连接操作.
            temp1->prev = temp3;
        } else if (sizeMark == 2) {//第二个长整数大
            result.createLinkListWithoutForValue(objectLength1);//链表长度为二者之中任意长度.
            node *resultTempPoint = result.returnHeadPoint()->prev;//resultTempPoint指向result表尾节点.
            int subRecord = 0;//subRecord记录借位.
            int sum = 0;
            for (int i = 0; i < objectLength1; i++) {//循环位数次.
                if ((tempPoint2->data - subRecord) < tempPoint1->data) {
                    sum = tempPoint2->data + base - tempPoint1->data - subRecord;//从前一位借1,sum记录每位相减的差.
                    subRecord = 1;//sub记录借位.
                } else {
                    sum = tempPoint2->data - tempPoint1->data - subRecord;//直接相减.
                    subRecord = 0;//sub记录借位.
                }
                tempPoint1 = tempPoint1->prev;
                tempPoint2 = tempPoint2->prev;
                resultTempPoint->data = sum;//将结果记入链表.
                resultTempPoint = resultTempPoint->prev;
            }
            if (sum == 0) {//若最大数位为0.
                result.erase(1);//将第一个节点,即数据0删除.
            }
            node *temp1 = result.returnHeadPoint()->next;
            node *temp2 = temp1->next;
            node *temp3 = result.returnHeadPoint();
            while (temp1->data == 0) {//存在0001的情况,循环用于删除多余0.
                delete temp1;//删除该节点.
                temp1 = temp2;
                temp2 = temp2->next;
                result.returnLinkListLength() = result.returnLinkListLength() - 1;//链表长度减1.
            }
            temp3->next = temp1;//删除节点之后的连接操作.
            temp1->prev = temp3;
        }
    }
    return result;
}
linkList bigInteger::multiplicationAuxiliaryFunction(linkList &object1, linkList &object2, int base) {
    linkList result;
    int objectLength1 = object1.linkListSize();
    int objectLength2 = object2.linkListSize();
    //judgePoint1和judgePoint2用来判断两个链表是否为0链表.
    node *judgePoint1 = object1.returnHeadPoint()->next;
    node *judgePoint2 = object2.returnHeadPoint()->next;
    node *tempPoint2 = object2.returnHeadPoint()->prev;//tempPoint2指向object2表尾节点.
    //两个大整数其中有一个为0.
    if (judgePoint1->data == 0 || judgePoint2->data == 0) {
        result.insert(0,0);//相乘结果为0.
    } else {
        result.createLinkListWithForValue(objectLength1 + objectLength2);//积链表长度为两个链表长度之和,并全部初始化.
        //markPoint负责把每次相乘的结果记入链表,tempPoint往前对位.
        node *tempPoint = result.returnHeadPoint()->prev;
        node *markPoint = tempPoint;
        for (int i = 0; i < objectLength2; ++i) {
            if (tempPoint2->data == 0) {
                tempPoint2 = tempPoint2->prev;
                tempPoint = tempPoint->prev;
                markPoint = tempPoint;
                continue;
            }
            int temp = 0;
            node *tempPoint1 = object1.returnHeadPoint()->prev;//tempPoint1指向object1表尾节点.
            for (int j = 0; j < objectLength1; ++j) {
                //每次需要相加三部分数字.
                temp = temp + (tempPoint2->data) * (tempPoint1->data) + markPoint->data;
                markPoint->data = temp % base;//结果.
                temp = temp / base;//进位.
                tempPoint1 = tempPoint1->prev;
                markPoint = markPoint->prev;
            }
            markPoint->data = markPoint->data + temp;//进位后的结果记入链表.
            tempPoint2 = tempPoint2->prev;
            tempPoint = tempPoint->prev;
            markPoint = tempPoint;
        }
        if (result.returnHeadPoint()->next->data == 0)//最大数位为0.
            result.erase(1);//删除0.
    }
    return result;
}
linkList bigInteger::divisionFunction(linkList &operator1, linkList &operator2, int base) {
    int l1=operator1.linkListSize();
    int l2=operator2.linkListSize();
    node*ptr1=operator1.returnHeadPoint()->prev;//指向链表尾
    node*ptr2=operator2.returnHeadPoint()->prev;//指向链表尾
    linkList d;
    d.createLinkListWithoutForValue(l1);//较长者的长度
    node*ptr3=d.returnHeadPoint()->prev;
    int sum,sub=0;
    for(int i=0;i<l2;i++)
    {
        if((ptr1->data-sub)<ptr2->data)
        {
            sum=ptr1->data+10-ptr2->data-sub;//借位后相减
            sub=1;//记录借位
        }
        else
        {
            sum=ptr1->data-ptr2->data-sub;//直接相减
            sub=0;//记录借位
        }
        ptr1=ptr1->prev;
        ptr2=ptr2->prev;
        ptr3->data=sum;//将结果记入链表中
        ptr3=ptr3->prev;
    }
    for(int k=l2;k<l1;k++)//差位次循环
    {
        if(ptr1->data<sub)//小于0
        {
            sum=ptr1->data-sub+10;//借位相减
            sub=1;//记录借位
        }
        else
        {
            sum=ptr1->data-sub;//直接相减
            sub=0;//借位
        }
        ptr1=ptr1->prev;
        ptr3->data=sum;//将结果记入链表中
        ptr3=ptr3->prev;
    }
    node*ptr4=d.returnHeadPoint()->next;
    node*ptr5=ptr4->next;
    node*ptr6=d.returnHeadPoint();
    while(ptr4->data==0&&d.linkListSize()>1)//存在0001情况,循环用于删除多余0
    {
        delete ptr4;//删除多余0
        ptr4=ptr5;
        ptr5=ptr5->next;
        d.returnLinkListLength()=d.returnLinkListLength()-1;//链表长度减1
    }
    ptr6->next=ptr4;//删除节点之后的连接操作
    ptr4->prev=ptr6;
    return d;
}
linkList bigInteger::divisionAuxiliaryFunction(linkList &object1, linkList &object2, int base) {
    linkList result;
    if (comparisonOfSize(object1, object2) == -1) {//除数比被除数大的情况.
        result.insert(0, 0);
    } else {//除数和被除数相等或被除数比除数大的情况.
        if (object2.returnHeadPoint()->next->data == 0) {//除数为0的情况.
            cout << "Divide by 0, no result!" << endl;
        } else if (object1.returnHeadPoint()->next->data == 0) {//被除数为0的情况.
            result.insert(0, 0);
        } else {//其余情况.
            linkList tempList;
            int objectLength1 = object1.linkListSize();
            int objectLength2 = object2.linkListSize();
            if ((objectLength2 - 1) != 0) {
                tempList.createLinkListWithoutForValue(objectLength2 - 1);
                node *tempListPtr = tempList.returnHeadPoint()->next;
                node *ptr = object1.returnHeadPoint()->next;
                for (int i = 0; i < objectLength2 - 1; ++i) {//循环赋值.
                    tempListPtr->data = ptr->data;
                    tempListPtr = tempListPtr->next;
                    ptr = ptr->next;
                }
            }
            node *markPtr = object1.returnHeadPoint()->next;
            for (int i = 0; i < objectLength2 - 1; ++i) {//寻找object2最高位位于object1的位置.
                markPtr = markPtr->next;
            }
            node *erasePoint;
            for (int i = objectLength2 - 1; i < objectLength1; ++i) {
                int count = 0;//count记录相减次数.
                erasePoint = tempList.returnHeadPoint()->next;
                if (erasePoint->data == 0) {//相减之后差为0,将0后的数代替0.
                    node *change = tempList.returnHeadPoint()->next;
                    change->data = markPtr->data;
                } else {//继续插入下一位数.
                    tempList.insert(markPtr->data, tempList.linkListSize());
                }
                while ((comparisonOfSize(tempList, object2)) >= 0) {//比较两个数的大小.
                    tempList = subtractionAuxiliaryFunction(tempList, object2, base);//做连减操作.
                    count++;//记录连减次数.
                }
                markPtr = markPtr->next;
                result.insert(count, result.linkListSize());//将每次连减的次数插入到result中.
            }
            if (result.returnHeadPoint()->next->data == 0) {//若最大数为0.
                result.erase(1);
            }
        }
    }
    return result;
}
void bigInteger::addition_bigInteger(linkList &operation1, linkList &operation2, int base) {
    linkList result;
    time_t timeStart, timeEnd;//时间变量.
    time(&timeStart);//设置起始时间.
    if (operation1.linkListFlag() == -1) {//第一个加数为负数.
        if (operation2.linkListFlag() == 1) {//第二个加数为正数.
            if (comparisonOfSize(operation1, operation2) == 1) {//第一个数的绝对值大于第二个数.
                result = subtractionAuxiliaryFunction(operation1, operation2, base);
                result.returnLinkListFlag() = -1;
                cout << result;
                cout << endl;
            } else {//第一个数的绝对值小于等于第二个数.
                result = subtractionAuxiliaryFunction(operation2, operation1, base);
                cout << result;
                cout << endl;
            }
        } else {//第二个加数为负数或0.
            result = additionAuxiliaryFunction(operation1, operation2, base);
            result.returnLinkListFlag() = -1;
            cout << result;
            cout << endl;
        }
    } else {//第一个加数为正数或0.
        if (operation2.linkListFlag() == -1) {//第二个加数为负数.
            if (comparisonOfSize(operation1, operation2) == -1) {//第一个数的绝对值小于第二个数.
                result = subtractionAuxiliaryFunction(operation2, operation1,base);
                result.returnLinkListFlag() = -1;
                cout << result;
                cout << endl;
            } else {//第一个数的绝对值大于等于第二个数.
                result = subtractionAuxiliaryFunction(operation1, operation2, base);
                cout << result;
                cout << endl;
            }
        } else {//第二个加数为正数或0.
            result = additionAuxiliaryFunction(operation1, operation2, base);
            cout << result;
            cout << endl;
        }
    }
    time(&timeEnd);
    cout << "time: " << timeEnd - timeStart << endl;
    cout << "Do you want to save the results in a file:(1.Yes/2.No)";
    int choice;
    cin >> choice;
    if (choice == 1) {
        string str = translateToString(result);
        writeFile(str, R"(C:\Users\15590\Desktop\Operation of large integers\file\result_decimalSystem.txt)");
    }
}
void bigInteger::addition_bigInteger_binarySystem(linkList &object1, linkList &object2) {
    time_t timeStart, timeEnd;//时间变量.
    linkList result;
    time(&timeStart);//设置起始时间.
    bool lengthJudge = compareListLength(object1, object2);//判断传入的两个操作数的长度大小.
    if (lengthJudge) {//object1的长度 > object2的长度.
        int objectLength1 = object1.linkListSize();
        int objectLength2 = object2.linkListSize();
        int quotientRecord = 0;//quotient记录进位.
        node *tempPoint1 = object1.returnHeadPoint()->prev;//tempPoint1指向object1表尾节点.
        node *tempPoint2 = object2.returnHeadPoint()->prev;//tempPoint2指向object2表尾节点.
        result.createLinkListWithoutForValue(objectLength1);//创建结果链表长度为object1和object2中长度较大者.
        node *resultTempPoint = result.returnHeadPoint()->prev;//resultTempPoint指向result表尾节点.
        for (int i = 0; i < objectLength2; ++i) {//做object1和object2中长度较小者的长度次循环.
            int sum = tempPoint1->data + tempPoint2->data + quotientRecord;//sum记录每位的和.
            int valueForBit = sum % 2;//valueForBit为每位应当记录的的结果.
            quotientRecord = sum / 2;//quotient记录进位.
            tempPoint1 = tempPoint1->prev;
            tempPoint2 = tempPoint2->prev;
            resultTempPoint->data = valueForBit;//将结果计入和链表中.
            resultTempPoint = resultTempPoint->prev;
        }
        for (int i = objectLength2; i < objectLength1; ++i) {//做相差长度次循环.
            int sum = tempPoint1->data + quotientRecord;
            int valueForBit = sum % 2;//valueForBit为每位应当记录的的结果.
            quotientRecord = sum / 2;//quotient记录进位.
            tempPoint1 = tempPoint1->prev;
            resultTempPoint->data = valueForBit;//将结果计入和链表中.
            resultTempPoint = resultTempPoint->prev;
        }
        if (quotientRecord == 1) {
            result.insert(1, 0);
        }
    } else {//object1的长度 <= object2的长度.
        int objectLength1 = object1.linkListSize();
        int objectLength2 = object2.linkListSize();
        int quotientRecord = 0;//quotient记录进位.
        node *tempPoint1 = object1.returnHeadPoint()->prev;//tempPoint1指向object1表尾节点.
        node *tempPoint2 = object2.returnHeadPoint()->prev;//tempPoint2指向object2表尾节点.
        result.createLinkListWithoutForValue(objectLength2);//创建结果链表长度为object1和object2中长度较大者.
        node *resultTempPoint = result.returnHeadPoint()->prev;//resultTempPoint指向result表尾节点.
        for (int i = 0; i < objectLength1; ++i) {//做object1和object2中长度较小者的长度次循环.
            int sum = tempPoint1->data + tempPoint2->data + quotientRecord;//sum记录每位的和.
            int valueForBit = sum % 2;//valueForBit为每位应当记录的的结果.
            quotientRecord = sum / 2;//quotient记录进位.
            tempPoint1 = tempPoint1->prev;
            tempPoint2 = tempPoint2->prev;
            resultTempPoint->data = valueForBit;//将结果计入和链表中.
            resultTempPoint = resultTempPoint->prev;
        }
        for (int i = objectLength1; i < objectLength2; ++i) {//做相差长度次循环.
            int sum = tempPoint2->data + quotientRecord;
            int valueForBit = sum % 2;//valueForBit为每位应当记录的的结果.
            quotientRecord = sum / 2;//quotient记录进位.
            tempPoint1 = tempPoint1->prev;
            resultTempPoint->data = valueForBit;//将结果计入和链表中.
            resultTempPoint = resultTempPoint->prev;
        }
        if (quotientRecord == 1) {
            result.insert(1, 0);
        }
    }
    cout << result << endl;
    time(&timeEnd);
    cout << "time: " << timeEnd - timeStart << endl;
    cout << "Do you want to save the results in a file:(1.Yes/2.No)";
    int choice;
    cin >> choice;
    if (choice == 1) {
        string str = translateToString(result);
        writeFile(str, R"(C:\Users\15590\Desktop\Operation of large integers\file\result_binarySystem.txt)");
    }
}
void bigInteger::subtraction_bigInteger(linkList &operation1, linkList &operation2, int base) {
    linkList result;
    time_t timeStart, timeEnd;//时间变量.
    time(&timeStart);//设置起始时间.
    if (operation2.linkListFlag() == 0) {//第二个大整数为0.
        result = operation1;
    } else if (operation2.linkListFlag() == 1) {//第二个大整数为正数.
        if (operation1.linkListFlag() == 1) {//第一个大整数为正数.
            if (comparisonOfSize(operation1, operation2) == -1) {//第一个整数的绝对值小于第二个整数.
                result = subtractionAuxiliaryFunction(operation2, operation1, base);
                result.returnLinkListFlag() = -1;
                cout << result;
                cout << endl;
            } else {//第一个整数的绝对值大于等于第二个整数.
                result = subtractionAuxiliaryFunction(operation1, operation2, base);
                cout << result;
                cout << endl;
            }
        } else {//第一个大整数为负数或0.
            result = additionAuxiliaryFunction(operation1, operation2, base);
            result.returnLinkListFlag() = -1;
            cout << result;
            cout << endl;
        }
    } else {//第二个大整数为负数.
        if (operation1.linkListFlag() == -1) {//第一个大整数为负数.
            if (comparisonOfSize(operation1, operation2) == 1) {
                result = subtractionAuxiliaryFunction(operation1, operation2, base);
                result.returnLinkListFlag() = -1;
                cout << result;
                cout << endl;
            } else {//第一个整数的绝对值小于等于第二个整数.
                result = subtractionAuxiliaryFunction(operation2, operation1, base);
                cout << result;
                cout << endl;
            }
        } else {//第一个大整数为正数或0.
            result = additionAuxiliaryFunction(operation1, operation2, base);
            cout << result;
            cout << endl;
        }
    }
    time(&timeEnd);
    cout << "time: " << timeEnd - timeStart << endl;
    cout << "Do you want to save the results in a file:(1.Yes/2.No)";
    int choice;
    cin >> choice;
    if (choice == 1) {
        string str = translateToString(result);
        writeFile(str, R"(C:\Users\15590\Desktop\Operation of large integers\file\result_decimalSystem.txt)");
    }
}
void bigInteger::subtraction_bigInteger_binarySystem(linkList &object1, linkList &object2) {
    time_t timeStart, timeEnd;//时间变量.
    linkList result;
    int objectLength1 = object1.linkListSize();
    int objectLength2 = object2.linkListSize();
    time(&timeStart);//设置起始时间.
    if (objectLength1 > objectLength2) {//object1的长度 > object2的长度.
        int subRecord = 0;//subRecord记录借位.
        int sum = 0;
        node *tempPoint1 = object1.returnHeadPoint()->prev;//tempPoint1指向object1表尾节点.
        node *tempPoint2 = object2.returnHeadPoint()->prev;//tempPoint2指向object2表尾节点.
        result.createLinkListWithoutForValue(objectLength1);//创建结果链表长度为object1和object2中长度较大者.
        node *resultTempPoint = result.returnHeadPoint()->prev;//resultTempPoint指向result表尾节点.
        for (int i = 0; i < objectLength2; ++i) {//做object1和object2中长度较小者的长度次循环.
            if ((tempPoint1->data - subRecord) < tempPoint2->data) {//需要借位.
                sum = tempPoint1->data + 2 - tempPoint2->data - subRecord;//sum记录每位的差.
                subRecord = 1;//subRecord记录借位.
            } else {//不需要借位.
                sum = tempPoint1->data - tempPoint2->data - subRecord;//sum记录每位的差.
                subRecord = 0;//subRecord记录借位.
            }
            tempPoint1 = tempPoint1->prev;
            tempPoint2 = tempPoint2->prev;
            resultTempPoint->data = sum;//将结果计入和链表中.
            resultTempPoint = resultTempPoint->prev;
        }
        for (int i = objectLength2; i < objectLength1; ++i) {//做相差长度次循环.
            if (tempPoint1->data < subRecord) {//若此位为0.
                sum = tempPoint1->data - subRecord + 2;//从前一位借1,sum记录每位相减的差.
                subRecord = 1;//sub记录借位.
            } else {//若此位不为为0.
                sum = tempPoint1->data - subRecord;
                subRecord = 0;//sub记录借位.
            }
            tempPoint1 = tempPoint1->prev;
            resultTempPoint->data = sum;
            resultTempPoint=resultTempPoint->prev;
        }
        if (sum == 0) {
            result.erase(1);
        }
    } else if (objectLength1 < objectLength2) {//object1的长度 < object2的长度.
        int subRecord = 0;//subRecord记录借位.
        int sum = 0;
        node *tempPoint1 = object1.returnHeadPoint()->prev;//tempPoint1指向object1表尾节点.
        node *tempPoint2 = object2.returnHeadPoint()->prev;//tempPoint2指向object2表尾节点.
        result.createLinkListWithoutForValue(objectLength2);//创建结果链表长度为object1和object2中长度较大者.
        node *resultTempPoint = result.returnHeadPoint()->prev;//resultTempPoint指向result表尾节点.
        for (int i = 0; i < objectLength1; ++i) {//做object1和object2中长度较小者的长度次循环.
            if ((tempPoint2->data - subRecord) < tempPoint1->data) {//需要借位.
                sum = tempPoint2->data + 2 - tempPoint1->data - subRecord;//sum记录每位的差.
                subRecord = 1;//subRecord记录借位.
            } else {//不需要借位.
                sum = tempPoint2->data - tempPoint1->data - subRecord;//sum记录每位的差.
                subRecord = 0;//subRecord记录借位.
            }
            tempPoint1 = tempPoint1->prev;
            tempPoint2 = tempPoint2->prev;
            resultTempPoint->data = sum;//将结果计入和链表中.
            resultTempPoint = resultTempPoint->prev;
        }
        for (int i = objectLength1; i < objectLength2; ++i) {//做相差长度次循环.
            if (tempPoint2->data < subRecord) {//若此位为0.
                sum = tempPoint2->data - subRecord + 2;//从前一位借1,sum记录每位相减的差.
                subRecord = 1;//sub记录借位.
            } else {//若此位不为为0.
                sum = tempPoint2->data - subRecord;
                subRecord = 0;//sub记录借位.
            }
            tempPoint2 = tempPoint2->prev;
            resultTempPoint->data = sum;
            resultTempPoint=resultTempPoint->prev;
        }
        if (sum == 0) {
            result.erase(1);
        }
    } else {//object1的长度 = object2的长度.
        int sizeMark = 0;
        node *tempPoint1 = object1.returnHeadPoint()->prev;//tempPoint1指向object1表尾节点.
        node *tempPoint2 = object2.returnHeadPoint()->prev;//tempPoint2指向object2表尾节点.
        node *markPoint1 = object1.returnHeadPoint()->next;//tempPoint1指向object1第一个节点.
        node *markPoint2 = object2.returnHeadPoint()->next;//tempPoint2指向object2第一个节点.
        //循环用于比较两个长整数大小.
        for (int i = 0; i < objectLength1; ++i) {
            if (markPoint1->data > markPoint2->data) {
                sizeMark = 1;//第一个长整数大,m赋值为1.
                break;
            } else if (markPoint1->data < markPoint2->data) {
                sizeMark = 2;//第二个长整数大,m赋值为2.
                break;
            }
            markPoint1 = markPoint1->next;
            markPoint2 = markPoint2->next;
        }
        if (sizeMark == 0) {//两个长整数相等.
            result.createLinkListWithoutForValue(1);
            result.returnHeadPoint()->next->data = 0;//最后计算结果为0.
        }
        if (sizeMark == 1) {//第一个长整数大.
            result.createLinkListWithoutForValue(objectLength1);//链表长度为二者之中任意长度.
            node *resultTempPoint = result.returnHeadPoint()->prev;//resultTempPoint指向result表尾节点.
            int subRecord = 0;//subRecord记录借位.
            int sum = 0;
            for (int i = 0; i < objectLength1; i++) {//循环位数次.
                if ((tempPoint1->data - subRecord) < tempPoint2->data) {
                    sum = tempPoint1->data + 2 - tempPoint2->data - subRecord;//从前一位借1,sum记录每位相减的差.
                    subRecord = 1;//subRecord记录借位.
                } else {
                    sum = tempPoint1->data - tempPoint2->data - subRecord;//直接相减.
                    subRecord = 0;//sub记录借位.
                }
                tempPoint1 = tempPoint1->prev;
                tempPoint2 = tempPoint2->prev;
                resultTempPoint->data = sum;//将结果记入链表.
                resultTempPoint = resultTempPoint->prev;
            }
            if (sum == 0) {//若最大数位为0.
                result.erase(1);//将第一个节点,即数据0删除.
            }
            node *temp1 = result.returnHeadPoint()->next;
            node *temp2 = temp1->next;
            node *temp3 = result.returnHeadPoint();
            while (temp1->data == 0) {//存在0001的情况,循环用于删除多余0.
                delete temp1;//删除该节点.
                temp1 = temp2;
                temp2 = temp2->next;
                result.returnLinkListLength() = result.returnLinkListLength() - 1;//链表长度减1.
            }
            temp3->next = temp1;//删除节点之后的连接操作.
            temp1->prev = temp3;
        } else if (sizeMark == 2) {//第二个长整数大
            result.createLinkListWithoutForValue(objectLength1);//链表长度为二者之中任意长度.
            node *resultTempPoint = result.returnHeadPoint()->prev;//resultTempPoint指向result表尾节点.
            int subRecord = 0;//subRecord记录借位.
            int sum = 0;
            for (int i = 0; i < objectLength1; i++) {//循环位数次.
                if ((tempPoint2->data - subRecord) < tempPoint1->data) {
                    sum = tempPoint2->data + 2 - tempPoint1->data - subRecord;//从前一位借1,sum记录每位相减的差.
                    subRecord = 1;//sub记录借位.
                } else {
                    sum = tempPoint2->data - tempPoint1->data - subRecord;//直接相减.
                    subRecord = 0;//sub记录借位.
                }
                tempPoint1 = tempPoint1->prev;
                tempPoint2 = tempPoint2->prev;
                resultTempPoint->data = sum;//将结果记入链表.
                resultTempPoint = resultTempPoint->prev;
            }
            if (sum == 0) {//若最大数位为0.
                result.erase(1);//将第一个节点,即数据0删除.
            }
            node *temp1 = result.returnHeadPoint()->next;
            node *temp2 = temp1->next;
            node *temp3 = result.returnHeadPoint();
            while (temp1->data == 0) {//存在0001的情况,循环用于删除多余0.
                delete temp1;//删除该节点.
                temp1 = temp2;
                temp2 = temp2->next;
                result.returnLinkListLength() = result.returnLinkListLength() - 1;//链表长度减1.
            }
            temp3->next = temp1;//删除节点之后的连接操作.
            temp1->prev = temp3;
        }
    }
    cout << result << endl;
    time(&timeEnd);
    cout << "time: " << timeEnd - timeStart << endl;
    cout << "Do you want to save the results in a file:(1.Yes/2.No)";
    int choice;
    cin >> choice;
    if (choice == 1) {
        string str = translateToString(result);
        writeFile(str, R"(C:\Users\15590\Desktop\Operation of large integers\file\result_binarySystem.txt)");
    }
}
void bigInteger::multiplication_bigInteger(linkList &operation1, linkList &operation2, int base) {
    linkList result;
    time_t timeStart, timeEnd;//时间变量.
    time(&timeStart);//设置起始时间.
    if (operation1.linkListFlag() == operation2.linkListFlag()) {
        result = multiplicationAuxiliaryFunction(operation1, operation2, base);
        cout << result;
        cout << endl;
    } else {
        result = multiplicationAuxiliaryFunction(operation1, operation2, base);
        result.returnLinkListFlag() = -1;
        cout << result;
        cout << endl;
    }
    time(&timeEnd);
    cout << "time: " << timeEnd - timeStart << endl;
    cout << "Do you want to save the results in a file:(1.Yes/2.No)";
    int choice;
    cin >> choice;
    if (choice == 1) {
        string str = translateToString(result);
        writeFile(str, R"(C:\Users\15590\Desktop\Operation of large integers\file\result_decimalSystem.txt)");
    }
}
void bigInteger::multiplication_bigInteger_binarySystem(linkList &object1, linkList &object2) {
    time_t timeStart, timeEnd;//时间变量.
    linkList result;
    int objectLength1 = object1.linkListSize();
    int objectLength2 = object2.linkListSize();
    time(&timeStart);//设置起始时间.
    //judgePoint1和judgePoint2用来判断两个链表是否为0链表.
    node *judgePoint1 = object1.returnHeadPoint()->next;
    node *judgePoint2 = object2.returnHeadPoint()->next;
    node *tempPoint2 = object2.returnHeadPoint()->prev;//tempPoint2指向object2表尾节点.
    //两个大整数其中有一个为0.
    if (judgePoint1->data == 0 || judgePoint2->data == 0) {
        result.insert(0,0);//相乘结果为0.
    } else {
        result.createLinkListWithForValue(objectLength1 + objectLength2);//积链表长度为两个链表长度之和,并全部初始化.
        //markPoint负责把每次相乘的结果记入链表,tempPoint往前对位.
        node *tempPoint = result.returnHeadPoint()->prev;
        node *markPoint = tempPoint;
        for (int i = 0; i < objectLength2; ++i) {
            if (tempPoint2->data == 0) {
                tempPoint2 = tempPoint2->prev;
                tempPoint = tempPoint->prev;
                markPoint = tempPoint;
                continue;
            }
            int temp = 0;
            node *tempPoint1 = object1.returnHeadPoint()->prev;//tempPoint1指向object1表尾节点.
            for (int j = 0; j < objectLength1; ++j) {
                //每次需要相加三部分数字.
                temp = temp + (tempPoint2->data) * (tempPoint1->data) + markPoint->data;
                markPoint->data = temp % 2;//结果.
                temp = temp / 2;//进位.
                tempPoint1 = tempPoint1->prev;
                markPoint = markPoint->prev;
            }
            markPoint->data = markPoint->data + temp;//进位后的结果记入链表.
            tempPoint2 = tempPoint2->prev;
            tempPoint = tempPoint->prev;
            markPoint = tempPoint;
        }
        if (result.returnHeadPoint()->next->data == 0)//最大数位为0.
            result.erase(1);//删除0.
    }
    cout << result << endl;
    time(&timeEnd);
    cout << "time: " << timeEnd - timeStart << endl;
    cout << "Do you want to save the results in a file:(1.Yes/2.No)";
    int choice;
    cin >> choice;
    if (choice == 1) {
        string str = translateToString(result);
        writeFile(str, R"(C:\Users\15590\Desktop\Operation of large integers\file\result_binarySystem.txt)");
    }
}
void bigInteger::division_bigInteger(linkList &operation1, linkList &operation2, int base) {
    linkList result;
    time_t timeStart, timeEnd;//时间变量.
    time(&timeStart);//设置起始时间.
    if (operation1.linkListFlag() == operation2.linkListFlag()) {
        result = divisionAuxiliaryFunction(operation1, operation2, base);
        cout << result;
        cout << endl;
    } else {
        result = divisionAuxiliaryFunction(operation1, operation2, base);
        result.returnLinkListFlag() = -1;
        cout << result;
        cout << endl;
    }
    time(&timeEnd);
    cout << "time: " << timeEnd - timeStart << endl;
    cout << "Do you want to save the results in a file:(1.Yes/2.No)";
    int choice;
    cin >> choice;
    if (choice == 1) {
        string str = translateToString(result);
        writeFile(str, R"(C:\Users\15590\Desktop\Operation of large integers\file\result_decimalSystem.txt)");
    }
}
void bigInteger::division_bigInteger_binarySystem(linkList &object1, linkList &object2) {
    linkList result;
    time_t timeStart, timeEnd;//时间变量.
    time(&timeStart);//设置起始时间.
    if (comparisonOfSize(object1, object2) == -1) {//除数比被除数大的情况.
        result.insert(0, 0);
    } else {//除数和被除数相等或被除数比除数大的情况.
        if (object2.returnHeadPoint()->next->data == 0) {//除数为0的情况.
            cout << "Divide by 0, no result!" << endl;
        } else if (object1.returnHeadPoint()->next->data == 0) {//被除数为0的情况.
            result.insert(0, 0);
        } else {//其余情况.
            linkList tempList;
            int objectLength1 = object1.linkListSize();
            int objectLength2 = object2.linkListSize();
            if ((objectLength2 - 1) != 0) {
                tempList.createLinkListWithoutForValue(objectLength2 - 1);
                node *tempListPtr = tempList.returnHeadPoint()->next;
                node *ptr = object1.returnHeadPoint()->next;
                for (int i = 0; i < objectLength2 - 1; ++i) {//循环赋值.
                    tempListPtr->data = ptr->data;
                    tempListPtr = tempListPtr->next;
                    ptr = ptr->next;
                }
            }
            node *markPtr = object1.returnHeadPoint()->next;
            for (int i = 0; i < objectLength2 - 1; ++i) {//寻找object2最高位位于object的位置.
                markPtr = markPtr->next;
            }
            node *erasePoint;
            for (int i = objectLength2 - 1; i < objectLength1; ++i) {
                int count = 0;//count记录相减次数.
                erasePoint = tempList.returnHeadPoint()->next;
                if (erasePoint->data == 0) {//相减之后差为0,将0后的数代替0.
                    node *change = tempList.returnHeadPoint()->next;
                    change->data = markPtr->data;
                } else {//继续插入下一位数.
                    tempList.insert(markPtr->data, tempList.linkListSize());
                }
                while ((comparisonOfSize(tempList, object2)) >= 0) {//比较两个数的大小.
                    tempList = subtractionAuxiliaryFunction(tempList, object2, 2);//做连减操作.
                    count++;//记录连减次数.
                }
                markPtr = markPtr->next;
                result.insert(count, result.linkListSize());//将每次连减的次数插入到result中.
            }
            if (result.returnHeadPoint()->next->data == 0) {//若最大数为0.
                result.erase(1);
            }
        }
    }
    cout << result << endl;
    time(&timeEnd);
    cout << "time: " << timeEnd - timeStart << endl;
    cout << "Do you want to save the results in a file:(1.Yes/2.No)";
    int choice;
    cin >> choice;
    if (choice == 1) {
        string str = translateToString(result);
        writeFile(str, R"(C:\Users\15590\Desktop\Operation of large integers\file\result_binarySystem.txt)");
    }
}
void bigInteger::exponentialCalculation_bigInteger(linkList &operation1, linkList &operation2, int base) {
    linkList result;
    time_t timeStart, timeEnd;//时间变量.
    time(&timeStart);//设置起始时间.
    if (operation2.linkListSize() == 1 && operation2.returnHeadPoint()->next->data == 0) {//指数是0的情况.
        result.insert(1, 0);
    } else if (operation2.linkListSize() == 1 && operation2.returnHeadPoint()->next->data == 1) {//指数是1的情况.
        result = operation1;
    } else {
        linkList tempList;
        tempList.insert(1, 0);
        result = multiplicationAuxiliaryFunction(operation1, operation1, base);//做一次乘法,平方.
        operation2 = divisionFunction(operation2, tempList, base);//循环次数减1.
        while ((comparisonOfSize(operation2, tempList)) == 1) {
            result = multiplicationAuxiliaryFunction(result, operation1, base);//连乘.
            operation2 = subtractionAuxiliaryFunction(operation2, tempList, 10);//循环次数减1.
        }
    }
    cout << result << endl;
    time(&timeEnd);
    cout << "time: " << timeEnd - timeStart << endl;
    cout << "Do you want to save the results in a file:(1.Yes/2.No)";
    int choice;
    cin >> choice;
    if (choice == 1) {
        string url;
        if (base == 10) {
            url = R"(C:\Users\15590\Desktop\Operation of large integers\file\result_decimalSystem.txt)";
        } else {
            url = R"(C:\Users\15590\Desktop\Operation of large integers\file\result_binarySystem.txt)";
        }
        string str = translateToString(result);
        writeFile(str, url);
    }
}