/*
 * @Author: MattewPerry
 * @Date: 2018-03-12 14:15:31
 * @Last Modified by: MattewPerry
 * @Last Modified time: 2018-03-13 10:27:23
 */

#include "sales_data.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#if 1
//2.39
//struct and sales_data.h
int main(int argc, char **agrv)
{
    sales_data_st SalesData1_st, SalesData2_st;

    cin >> SalesData1_st.strBookNo >> SalesData1_st.uiUnitSold >> SalesData1_st.dRevenue;
    cin >> SalesData2_st.strBookNo >> SalesData2_st.uiUnitSold >> SalesData2_st.dRevenue;
    if (SalesData1_st.strBookNo == SalesData1_st.strBookNo)
    {
        uint16_t uiTotalSold = SalesData1_st.uiUnitSold + SalesData2_st.uiUnitSold;
        double dTotalRevenue = SalesData1_st.dRevenue + SalesData2_st.dRevenue;

        if (uiTotalSold != 0)
        {
            cout << SalesData1_st.strBookNo << " : " << uiTotalSold << " " << dTotalRevenue / uiTotalSold << endl;
        }
        else
        {
            cout << "No book sold.\n";
        }
    }
    else
    {
        cout << "Data error.\n";
    }

    cout << "\r\nDone!\a\r\n";
    // system("pause");
    // getchar();
    // getchar();
    return 0;
}
#endif

#if 0
//2.38
//decltype

uint16_t g_uiTestNum = 1; //如果打印出来是1说明decltype不计算函数，仅分析返回值类型
float Func(void);

int main(int argc, char **agrv)
{
    //decltype选择并返回操作数的类型，在此过程中，编译器分析表达式，但并不实际计算表达式的值
    decltype(Func()) sum = 10.9f;
    cout << sum << endl;
    cout << g_uiTestNum << endl;

    //decltype处理顶层const和引用的方式与auto不同
    //如果decltype使用的表达式是一个变量，则返回该变量类型，包括顶层const和引用
    const int kiVar1 = 100, &kirVar2 = kiVar1;
    decltype(kiVar1) dtVar3 = 200;
    decltype(kirVar2) dtVar4 = dtVar3;

    //如果decltype使用的表达式不是一个变量，则返回表达式结果对应的数据类型
    //有些表达式将向decltype返回引用类型，一般这种情况发生时，意味着该表达式的结果对象能作为一条赋值语句的左值
    //变量加()会变成表达式，由于变量可以作为左值，加括号变成可以赋值的特殊表达式，故会得到引用类型
    int iVar5 = 500.555555, *ipVar6 = &iVar5, &irVar7 = iVar5;
    decltype(iVar5) dtVar8 = iVar5;       //int
    decltype(ipVar6) dtVar9 = &iVar5;     //int*
    decltype(*ipVar6) dtVar10 = iVar5;    //int& 表达式得到的是整型数，而且可以赋值故引用
    decltype(irVar7) dtVar11 = iVar5;     //int&
    decltype(irVar7 + 0) dtVar12 = iVar5; //int 表达式得到是int
    decltype((iVar5)) dtVar13 = iVar5;    //int&

    cout << iVar5 << endl;
    cout << dtVar8 << endl;
    cout << dtVar9 << endl;
    cout << *dtVar9 << endl;
    cout << dtVar10 << endl;
    cout << dtVar11 << endl;
    cout << dtVar12 << endl;
    cout << dtVar13 << endl;

    int a = 3, b = 4;
    decltype(a) c = a;
    decltype((b)) d = a;
    //赋值经常会产生引用类型
    decltype(a = b) e = a; //int&
    // ++c;
    // ++d;
    // ++e;
    cout << "a= " << a << endl;
    cout << "b= " << b << endl;
    cout << "c= " << c << endl;
    cout << "d= " << d << endl;
    cout << "e= " << e << endl;

    int f = 111, &ijk = f;
    auto g = f;          //int
    decltype(f) h = f;   //int
    auto l = ijk;        //int
    decltype(ijk) m = f; //int&
    cout << g << endl;
    cout << h << endl;
    cout << l << endl;
    cout << m << endl;

    cout << "\r\nDone!\a\r\n";
    // system("pause");
    // getchar();
    // getchar();
    return 0;
}

float Func(void)
{
    g_uiTestNum = 2;
    return 100.0f;
}
#endif

#if 0
//2.35
//auto
int main(int argc, char **agrv)
{
    //由初始值推断类型，auto定义的变量必须有初始值
    int iV1, iV2;
    auto aV3 = iV1 + iV2;

    //auto可以用来声明多个变量，一条声明语句只能有一个基本数据类型，故多个变量的基本数据类型必须一致
    auto aV4 = 0, *apV5 = &aV4;
    // auto aV6 = 0, aV7 = 3.14f;  //非法

    //编译器推导的类型有时候和初始值类型不完全一样，会适当的改变结果，使结果类型更符合初始化规则

    //引用做初始值，类型参考引用的对象的类型
    int iV8 = 8, &irV9 = iV8;
    auto aV10 = irV9; //aV10类型为int，不是int&

    //!auto经常会忽略顶层const，保留底层const
    const int kiV11 = iV8, &kirV12 = kiV11;
    auto aV13 = kiV11;  //int，顶层被忽略
    auto aV14 = kirV12; //int，引用指向的对象，顶层const被忽略
    auto aV15 = &iV8;   //int*，指向int的指针，整型变量的地址即指向整型的指针
    auto aV16 = &kiV11; //const int*，底层const保留

    //希望获得顶层const，需要明确指出
    const auto kaV17 = kiV11;   //const int

    //可以讲引用的类型设置为auto，初始化规则仍然适用
    auto &arV18 = kiV11;
    // auto &arV19 = 42;   //非法，不能为非常量绑定字面值
    const auto &karV20 = 42;

    //!设置一个类型为auto的引用时，初始值中的顶层const属性仍然保留
    //如果给初始值绑定一个引用，则此时的常量就不是顶层常量了
    //利用auto在一条语句中定义多个变量，初始值必须是同一类型
    auto aV21 = kiV11, &arV22 = iV8;
    auto &arV23 = kiV11, *apV24 = &kiV11;
    // auto aV25 = iV1, *apV26 = &kiV11;   //非法，int，const int

    //推断类型，并编程验证
    const int kiV27 = 42;
    auto aV28 = kiV27;  //int
    const auto &karV28 = kiV27; //const int&
    auto *apV29 = &kiV27;    //const int*
    const auto kaV30 = kiV27, &karV31 = kiV27;  //const int,const int&

    cout << kiV27 << endl;
    cout << aV28 << endl;
    cout << karV28 << endl;
    cout << *apV29 << endl;
    cout << kaV30 << endl;
    cout << karV31 << endl;


    cout << "\r\nDone!\a\r\n";
    // system("pause");
    // getchar();
    // getchar();
    return 0;
}
#endif

#if 0
//2.35
//typedef/using

typedef char *cpString;
using dWages = double;

int main(int argc, char **agrv)
{
    //!不要把类型别名替换为本来的样子
    const cpString ckpP1 = nullptr;
    const cpString *ckppP2;
    //声明中cpString的基本数据类型为指针，替换后基本数据类型为char（或const char）两种含义截然不同
    const char *kcpP3;
    dWages dMyWage = 5000;

    cout << dMyWage << endl;

    cout << "\r\nDone!\a\r\n";
    // system("pause");
    // getchar();
    // getchar();
    return 0;
}
#endif

#if 0
//2.32
//constexpr

int GetSize(void);
constexpr int GetSize2(void) { return 200; };

int main(int argc, char **agrv)
{
    const int kiV1 = 100;
    const int kiV2 = kiV1 + 100;

    //实际使用中，我们需要一个常量表达式，但const不能完全满足这种需求
    const int kiSize = GetSize(); //可以定义，但不是常量表达式

    //constexpr可以使编译器帮助检测是否属于常量表达式
    //建议：如果一个变量是常量表达式，就把它声明为constexpr类型
    constexpr int kiSize2 = GetSize2(); //不可以定义，因为GetSize()函数不是constexpr函数

    //constexpr将被定义对象置为顶层const，故只能修饰指针，不能修饰指针指向的对象
    const int *kipP1 = nullptr;     //指向整型常量的指针
    constexpr int *kipP2 = nullptr; //指向整型变量的常量指针

    int null = 0, *p = null; //指针赋值非法

    cout << kiV2 << endl;
    cout << kiSize << endl;
    cout << kiSize2 << endl;

    cout << "\r\nDone!\a\r\n";
    // system("pause");
    // getchar();
    // getchar();
    return 0;
}

int GetSize(void)
{
    return 100;
}
#endif

#if 0
//2.31
//top level const and low level const
int main(int argc, char **agrv)
{
    //顶层const，拷贝时不影响
    //底层const，拷贝时，必须具有相同的底层const资格，或者两个对象的数据类型可以相互转化
    //一般来说，非常量可以转化为常量，反之不可
    const int v2 = 0;
    int v1 = v2;
    int *p1 = &v1, &r1 = v1;
    const int *p2 = &v2, *const p3 = &v1, &r2 = v2;

    r1 = v2; //合法，顶层const，拷贝时不影响
    p1 = p2; //非法，底层const
    p2 = p1; //合法，可以转化
    p1 = p3; //非法，底层const
    p2 = p3; //合法

    cout << "\nDone!\a\r\n";
    // system("pause");
    // getchar();
    // getchar();
    return 0;
}
#endif

#if 0
//2.29
//const reference and const pointer
int main(int argc, char **agrv)
{
    //2.27
    int i = -1, i2 = -2, &r = 0; //r非法，int&不可引用字母常量
    int *const p2 = &i2;         //合法
    const int i3 = -1, &r2 = 0;  //合法
    const int *const p3 = &i2;   //合法，指向整型常量的常量指针可以绑定非常量整型变量
    const int *p1 = &i2;         //合法
    const int &const r3;         //非法,未初始化
    const int i4 = i, &r4 = i;   //合法

    //2.28
    int i5, *const kip1; //i5合法，kip1非法，指针未定义，无法使用
    int *p3, *const p4;  //p3合法，p4非法
    const int ki6=-3, &kir1=ki6;   //合法
    const int *const kikp1; //非法
    const int *ki7; //非法

    //2.29
    i5 = ki6;   //合法
    p3 = kikp1; //合法
    p3 = &ki6;  //非法
    kikp1 = &ki6;   //非法
    p4 = p3;    //非法
    ki6 = *kikp1;   //非法


    cout << "\nDone!\a\r\n";
    // system("pause");
    // getchar();
    // getchar();
    return 0;
}
#endif

#if 0
//2.25
//pointer
int main(int argc, char **agrv)
{
    int *ip, i, &ri = i;
    int i2, *ip2 = nullptr;
    int *ip3, i3;

    cout << ip << endl;
    cout << i << endl;
    cout << ri << endl;
    cout << i2 << endl;
    cout << ip2 << endl;
    cout << ip3 << endl;
    cout << i3 << endl;

    cout << "\nDone!\a\r\n";
    // system("pause");
    // getchar();
    // getchar();
    return 0;
}
#endif

#if 0
//2.17
//lreference
int main(int argc, char **agrv)
{
    int i, &ri = i;
    i = 5;
    ri = 10;
    std::cout << "i = " << i << ". ri = " << ri << "." << '\n';

    cout << "\nDone!\a\r\n";
    // system("pause");
    // getchar();
    // getchar();
    return 0;
}
#endif

#if 0
//2.14
int main(int argc, char **agrv)
{
    int i = 100, sum << endl;

    cout << "\n\n\n\n\n\nDone!\a\r\n";
    // system("pause");
    // getchar();
    // getchar();
    return 0;
}
#endif

#if 0
string g_strS1;
int g_iV1;
//2.10
//变量的默认初始值，与类型、位置有关
//内置类型在函数内部，未定义
//类自己决定
int main()
{
    cout<<"global string: "<<g_strS1<<endl;
    cout<<"global int: "<<g_iV1<<endl;

    int a_iV2;
    string a_strS2;
    cout<<"local string: "<<a_strS2<<endl;
    cout<<"local int: "<<a_iV2<<endl;

    cout << "\n\n\n\n\n\nDone!\a\r\n";
    return 0;
}
#endif

#if 0
//2.8
//利用转义序列先输出2M，转到新的一行
//先输出2，然后输出制表符，再输出M，转到新一行
int main()
{
    int *a_ipPtr = nullptr;

    cout << "2M" << endl;
    cout << "2\tM\n";

    cout << "\n\n\n\n\n\nDone!\a\r\n";
    return 0;
}
#endif

#if 0
//2.5
//0开头的是八进制
//08会报编译错误
int main()
{
    int i = 08, i2 = 070, i3 = 010;

    cout << i << endl
         << i2 << endl
         << i3 << endl;

    cout << "\n\n\n\n\n\nDone!\n";
    return 0;
}
#endif

#if 0
//2.4
//数据类型转换
//有时候系统会自动转换
//!自动转换经常bug
int main()
{
    //算术表达式既有有符号数又有无符号数
    unsigned int a_uiValue = 10;
    int a_iValue = -42;
    cout << "int + int = " << a_iValue + a_iValue << endl;
    cout << "uint + uint = " << a_iValue + a_uiValue << endl;
    cout << "int * uint = " << a_iValue * a_uiValue << endl;

    unsigned int u = 10, u2 = 42;
    int i = 10, i2 = 42;
    cout << "u-u2=" << u - u2 << endl;
    cout << "u2-u=" << u2 - u << endl;
    cout << "i-i2=" << i - i2 << endl;
    cout << "i2-i=" << i2 - i << endl;
    cout << "u-i=" << u - i << endl;
    cout << "i-u=" << i - u << endl;

    //求值顺序不确定，避免相互影响

    cout << "\n\n\n\n\n\nDone!\n";
    return 0;
}
#endif

#if 0
//2.1
//!遇到有疑问的时候，不要浪费工具啊..
//在电脑上想办法编程验证，比如bool的大小
//输出各种基本数据类型的大小
int main()
{
    cout << "bool: " << sizeof(bool) << endl;
    cout << "char: " << sizeof(char) << endl;
    cout << "wchar_t: " << sizeof(wchar_t) << endl;
    cout << "char16_t: " << sizeof(char16_t) << endl;
    cout << "char32_t: " << sizeof(char32_t) << endl;
    cout << "short: " << sizeof(short) << endl;
    cout << "int: " << sizeof(int) << endl;
    cout << "long: " << sizeof(long) << endl;
    cout << "long long: " << sizeof(long long) << endl;
    cout << "float: " << sizeof(float) << endl;
    cout << "double: " << sizeof(double) << endl;
    cout << "long double: " << sizeof(long double) << endl;

    cout << "\n\n\n\n\n\nDone!\n";
    return 0;
}
#endif