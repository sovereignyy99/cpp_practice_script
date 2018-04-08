/*
 * @Author: MatthewPerry
 * @Date: 2018-03-10 21:14:03
 * @Last Modified by: MatthewPerry
 * @Last Modified time: 2018-03-11 12:59:54
 */

#include <iostream>
#include "Sales_item.h"

using namespace std;

#if 1
//1.25_2
//?用状态机试试-done
//读取记录销售报告的文件，统计每本书销售数量、总价、均价
//假设每本书销售记录是聚在一起的
//没有数据可以直接return -1
int main(int argc, char **agrv)
{
    int a_iCount = 1;
    static uint8_t fs_ucStatus = 0;
    Sales_item Book_st, Total_st;

    fs_ucStatus = 1;
    while (fs_ucStatus!=0)
    {
        switch (fs_ucStatus)
        {
        case 1:
            if (cin >> Total_st)
            {
                fs_ucStatus = 2;
            }
            else
            {
                cout << "No correct data input.\n";
                fs_ucStatus = 0;
                return -1;
            }
            break;

        case 2:
            if (cin >> Book_st)
            {
                if (Book_st.isbn() == Total_st.isbn())
                {
                    Total_st += Book_st;
                    ++a_iCount;
                }
                else
                {
                    cout << Total_st << " " << a_iCount << " times." << endl;
                    Total_st = Book_st;
                    a_iCount = 1;
                }
            }
            else
            {
                cout << Total_st << " " << a_iCount << " times." << endl;
                fs_ucStatus = 0;
            }
            break;

        default:
            break;
        }
    }

    cout << "\n\n\n\n\n\nDone!\n";
    return 0;
}
#endif

#if 0
//1.25_1
//?正常过程写-done
//读取记录销售报告的文件，统计每本书销售数量、总价、均价
//假设每本书销售记录是聚在一起的
int main()
{
    Sales_item Total_st, Book_st;
    if (cin >> Total_st)
    {
        int a_iCount = 1;
        while (cin >> Book_st)
        {
            if (Book_st.isbn() == Total_st.isbn())
            {
                Total_st += Book_st;
                ++a_iCount;
            }
            else
            {
                cout << Total_st << " " << a_iCount << " times." << endl;
                Total_st = Book_st;
                a_iCount = 1;
            }
        }
        cout << Total_st << " " << a_iCount << " times." << endl;
    }
    else
    {
        cout << "Input data is invalid..\n";
        return -1;

    }

    cout << "\n\n\n\n\n\nDone!\n";
    return 0;
}
#endif

#if 0
//1.22
//定义一个类的实例
//对类的实例进行输入、输出、相加
//读取多个具有相同ISBN的书籍销售记录并输出和
int main()
{
    Sales_item Book_st[2], Total_st;

    if (cin >> Total_st)
    {
        while (cin >> Book_st[1])
        {
            if (Total_st.isbn() == Book_st[1].isbn())
            {
                Total_st += Book_st[1];
            }
            else
            {
                break;
            }
        }
        cout << "Total: " << Total_st;
    }
    else
    {
        cout << "input data error..\n";
    }

    cout << "\n\n\n\n\n\nDone!\n";
    return 0;
}
#endif

#if 0
//1.18
//输入一组数，相同的数连续出现，统计并显示每个数出现的次数
//cls可以清楚cmd屏幕信息
//养成写注释的好习惯，开始的时候可能写的很多，熟练后只写关键的位置
int main()
{
    int a_iPresent = 0, a_iLast = 0;
    if (cin >> a_iLast)
    {
        int a_iOccurance = 1;
        while (cin >> a_iPresent)
        {
            if (a_iPresent == a_iLast)
            {
                ++a_iOccurance;
            }
            else
            {
                cout << a_iLast << " occurs " << a_iOccurance << " times.\n";
                a_iLast = a_iPresent;
                a_iOccurance = 1;
            }
        }
        cout << a_iLast << " occurs " << a_iOccurance << " times.\n";
    }
    else
    {
        cout << "No integer input..\n";
    }

    cout << "\n\n\n\n\n\nDone!\n";
    return 0;
}
#endif

#if 0
//1.16
//istream对象作为条件判断，错误、到达文件末尾或输入类型与期望不符等为假
//windows系统ctrl+Z为文件尾，Unix，Mac OSX中ctrl+D表示文件尾
//输入一组整数，求和
//可以重定向到文件，利用文件里面的数值求和
int main()
{
    int a_iValue = 0, a_iSum = 0;

    while (cin >> a_iValue)
    {
        a_iSum += a_iValue;
    }
    cout << "The sum is " << a_iSum << endl;

    cout << "\n\n\n\n\n\nDone!\n";
    return 0;
}
#endif

#if 0
//1.11 1.19
//输入两个整数，打印两个整数指定范围内的所有整数
int main()
{
    cout << "Enter two integers:" << endl;

    int a_iSmall = 0, a_iBig = 0;
    cin >> a_iSmall >> a_iBig;
    if (a_iSmall > a_iBig)
    {
        int tmp = a_iSmall;
        a_iSmall = a_iBig;
        a_iBig = tmp;
    }

    bool a_blTest = true;
    int a_iFoo = 100;
    for (; a_blTest && (a_iSmall <= a_iBig) && (a_iFoo <= 105); ++a_iSmall, ++a_iFoo)
    {
        cout << a_iSmall << endl;
    }

    // while (a_iSmall <= a_iBig)
    // {
    //     cout << a_iSmall << endl;
    //     ++a_iSmall;
    // }

    cout << "\n\n\n\n\n\nDone!\n";
    return 0;
}
#endif

#if 0
//1.4
//输入两个整数，打印两个整数的和与积
int main()
{
    cout << "Please enter two numbers:" << endl;

    int a_iNumber1 = 0, a_iNumber2 = 0;

    cin >> a_iNumber1 >> a_iNumber2;
    cout << "The sum of " << a_iNumber1 << " and " << a_iNumber2 << " is "
         << a_iNumber1 + a_iNumber2 << ".\n";

    cout << "The product of " << a_iNumber1 << " and " << a_iNumber2 << " is "
         << a_iNumber1 * a_iNumber2 << ".\n";

    cout << "Hello,world!\n";

    return 0;
}
#endif