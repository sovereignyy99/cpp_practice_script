/*
 * @Author: MatthewPerry
 * @Date: 2018-04-04 11:48:29
 * @Last Modified by: MatthewPerry
 * @Last Modified time: 2018-04-09 12:08:41
 */

#include "sales_data.h"
#include <cctype>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <list>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#if 1
// 9.23
int main(int argc, char **argv)
{

    return 0;
}
#endif

#if 0
// 9.22
using std::vector;

void insertDoubleValue(vector<int> &iv, int some_val)
{
    auto cursor = iv.size() / 2;
    auto iter = iv.begin(), mid = iv.begin() + cursor;
    while (iter != mid) {
        if (*iter == some_val) {
            iter = iv.insert(iter, 2 * some_val);
            ++iter; ++cursor;
            mid = iv.begin() + cursor;
        }
        ++iter;
    }
}

void print(const vector<int> &iv)
{
    for (auto i : iv)
        std::cout << i << " ";
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    vector<int> iv = {1, 1, 1, 1, 1, 7, 1, 9};
    insertDoubleValue(iv, 1);
    print(iv);

    return 0;
}
#endif

#if 0
// 9.20
int main(int argc, char **argv)
{
    // list<int>拷贝到两个deque，偶数一个，奇数一个
    std::list<int> iVar1_cl{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::deque<int> iVar2_cl;
    std::deque<int> iVar3_cl;

    for (auto atVar4 = iVar1_cl.cbegin(); atVar4 != iVar1_cl.cend(); ++atVar4)
    {
        if (*atVar4 % 2)
        {
            iVar3_cl.push_back(*atVar4);
        }
        else
        {
            iVar2_cl.push_back(*atVar4);
        }
    }

    for (const auto &v : iVar2_cl)
    {
        std::cout << v << std::endl;
    }

    for (const auto &v : iVar3_cl)
    {
        std::cout << v << std::endl;
    }

    return 0;
}
#endif

#if 0
// 9.20
int main(int argc, char **argv)
{
    // list<int>拷贝到两个deque，偶数一个，奇数一个
    std::list<int> iVar1_cl{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::deque<int> iVar2_cl;
    std::deque<int> iVar3_cl;

    for (auto atVar4 = iVar1_cl.cbegin(); atVar4 != iVar1_cl.cend(); ++atVar4)
    {
        if (*atVar4 % 2)
        {
            iVar3_cl.push_back(*atVar4);
        }
        else
        {
            iVar2_cl.push_back(*atVar4);
        }
    }

    for (const auto &v : iVar2_cl)
    {
        std::cout << v << std::endl;
    }

    for (const auto &v : iVar3_cl)
    {
        std::cout << v << std::endl;
    }

    return 0;
}
#endif

#if 0
// 9.19
int main(int argc, char **argv)
{
    // 从标准输入读取string序列，存入list，用迭代器打印出来
    using std::cin;
    using std::cout;
    using std::list;
    using std::endl;
    using std::string;

    list<string> input;
    for (string str; cin >> str; input.push_back(str))
        ;
    for (auto iter = input.cbegin(); iter != input.cend(); ++iter)
        cout << *iter << endl;

    return 0;
}
#endif

#if 0
// 9.18
int main(int argc, char **argv)
{
    // 从标准输入读取string序列，存入deque，用迭代器打印出来
    using std::cin;
    using std::cout;
    using std::deque;
    using std::endl;
    using std::string;

    deque<string> input;
    for (string str; cin >> str; input.push_back(str))
        ;
    for (auto iter = input.cbegin(); iter != input.cend(); ++iter)
        cout << *iter << endl;

    return 0;
}
#endif

#if 0
// 9.18
int main(int argc, char **argv)
{
    // 从标准输入读取string序列，存入deque，用迭代器打印出来
    std::deque<std::string> strVar1_cl;
    std::string strVar2;
    while (std::cin >> strVar2)
    {
        strVar1_cl.push_back(strVar2);
    }

    if (strVar1_cl.size())
    {
        for (auto katVar3 = strVar1_cl.cbegin(); katVar3 != strVar1_cl.cend(); katVar3++)
        {
            std::cout << *katVar3 << std::endl;
        }
    }
    else
    {
        std::cerr << "No data.\n";
    }

    return 0;
}
#endif

#if 0
// 9.16
int main(int argc, char **argv)
{
    std::vector<int> iVar1_cl{0, 1, 2, 3};
    std::vector<int> iVar2_cl{0, 1, 2, 3, 4};
    std::list<int> iVar3_cl{0, 1, 2, 3};
    if (iVar1_cl == iVar2_cl)
    {
        std::cout << "equal.\n";
    }
    else
    {
        std::cout << "not equal.\n";
    }

    std::cout << (std::vector<int>(iVar3_cl.cbegin(), iVar3_cl.cend()) == iVar1_cl ? true : false) << std::endl;
    std::cout << (std::vector<int>(iVar3_cl.cbegin(), iVar3_cl.cend()) == iVar2_cl ? true : false) << std::endl;

    return 0;
}
#endif

#if 0
// 9.14
int main(int argc, char **argv)
{
    // 将list的一段char*赋予vector的string
    std::list<const char*> l{"Mooophy", "pezy", "Queeuqueg"};
    std::vector<std::string> v;
    v.assign(l.cbegin(), l.cend());

    for (const auto &ch : v)
        std::cout << ch << std::endl;

    return 0;
}
#endif

#if 0
// 9.14
int main(int argc, char **argv)
{
    // 将list的一段char*赋予vector的string
    std::vector<std::string> strVar1_cl;
    std::list<const char *> kcpVar2_cl{"Hello, cpp world."};
    strVar1_cl.assign(kcpVar2_cl.cbegin(), kcpVar2_cl.cend());
    for (const auto &katVar3 : strVar1_cl)
    {
        std::cout << katVar3 << std::endl;
    }

    strVar1_cl.assign(3, "hello");
    for (const auto &katVar3 : strVar1_cl)
    {
        std::cout << katVar3 << std::endl;
    }

    std::vector<std::string> strVar4_cl(3, "world");
    swap(strVar1_cl, strVar4_cl);
    for (const auto &katVar3 : strVar1_cl)
    {
        std::cout << katVar3 << std::endl;
    }
    for (const auto &katVar3 : strVar4_cl)
    {
        std::cout << katVar3 << std::endl;
    }

    return 0;
}
#endif

#if 0
// 9.13
int main(int argc, char **argv)
{
    // 将vector的一段char*赋予list的string
    std::list<std::string> strVar1_cl;
    std::vector<const char *> kcpVar2_cl{"Hello, cpp world."};
    strVar1_cl.assign(kcpVar2_cl.cbegin(), kcpVar2_cl.cend());
    for (const auto &katVar3 : strVar1_cl)
    {
        std::cout << katVar3 << std::endl;
    }

    strVar1_cl.assign(10, "hello");
    for (const auto &katVar3 : strVar1_cl)
    {
        std::cout << katVar3 << std::endl;
    }

    std::list<std::string> strVar4_cl(10, "world");
    swap(strVar1_cl, strVar4_cl);
    for (const auto &katVar3 : strVar1_cl)
    {
        std::cout << katVar3 << std::endl;
    }
    for (const auto &katVar3 : strVar4_cl)
    {
        std::cout << katVar3 << std::endl;
    }

    return 0;
}
#endif

#if 0
// 9.13
int main(int argc, char **argv)
{
    using std::cout;
    using std::endl;
    using std::list;
    using std::vector;

    list<int> ilst(5, 4);
    vector<int> ivc(5, 5);

    //! from list<int> to vector<double>
    vector<double> dvc(ilst.begin(), ilst.end());
    for (auto i : ilst)
        cout << i;
    cout << endl;
    for (auto t : dvc)
        cout << t;
    cout << endl;

    //! from vector<int> to vector<double>
    vector<double> dvc2(ivc.begin(), ivc.end());
    for (auto i : ivc)
        cout << i;
    cout << endl;
    for (auto t : dvc2)
        cout << t;

    return 0;
}
#endif

#if 0
// 9.13
int main(int argc, char **argv)
{
    // 从list<int>初始化vector<double>
    // 从vector<int>初始化vector<double>
    std::list<int> iVar1_cl(10, 1);
    std::vector<double> dVar2_cl(iVar1_cl.cbegin(), iVar1_cl.cend());
    for (const auto &katVar3 : dVar2_cl)
    {
        std::cout << katVar3 << std::ends;
    }
    std::vector<int> iVar4_cl(10, 100);
    std::vector<double> dVar5_cl(iVar4_cl.cbegin(),iVar4_cl.cend());
    for (const auto &katVar3 : dVar5_cl)
    {
        std::cout << katVar3 << std::ends;
    }

    return 0;
}
#endif

#if 0
// 9.12
int main(int argc, char **argv)
{
    // 6种创建和初始化vector对象的方法
    std::vector<int> ivec1{0, 1, 2};
    std::vector<int> ivec2(3, 1);
    std::vector<int> ivec3(3);
    std::vector<int> ivec4(ivec1.cbegin(), ivec1.cend());
    std::vector<int> ivec5(ivec1);
    std::vector<int> ivec6;
    for (int i = 0; i < 3; ++i)
    {
        ivec6.push_back(i);
    }

    for (int i = 0; i < 3; ++i)
    {
        std::cout << ivec1[i] << std::endl;
        std::cout << ivec2[i] << std::endl;
        std::cout << ivec3[i] << std::endl;
        std::cout << ivec4[i] << std::endl;
        std::cout << ivec5[i] << std::endl;
        std::cout << ivec6[i] << std::endl;
    }

    return 0;
}
#endif

#if 0
// 9.5
std::vector<int>::iterator Foo(std::vector<int>::iterator it1, std::vector<int>::iterator it2, int i);
int main(int argc, char **argv)
{
    std::vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int>::iterator it0 = Foo(ivec.begin(), ivec.end(), 5);
    if (it0 != ivec.end())
    {
        std::cout << "data found: " << *it0 << std::endl;
    }
    else
    {
        std::cerr << "Not found.\n";
    }

    return 0;
}

std::vector<int>::iterator Foo(std::vector<int>::iterator it1, std::vector<int>::iterator it2, int i)
{
    for (; it1 != it2; ++it1)
    {
        if (*it1 == i)
        {
            return it1;
        }
    }
    return it2;
}
#endif

#if 0
// 9.4
bool Foo(std::vector<int>::iterator it1, std::vector<int>::iterator it2, int i);
int main(int argc, char **argv)
{
    std::vector<int> ivec{0, 1, 2, 3, 4, 6, 7, 8, 9};
    std::cout << Foo(ivec.begin(), ivec.end(), 5) << std::endl;

    return 0;
}

bool Foo(std::vector<int>::iterator it1, std::vector<int>::iterator it2, int i)
{
    for (; it1 != it2; ++it1)
    {
        if (*it1 == i)
        {
            return true;
        }
    }
    return false;
}
#endif