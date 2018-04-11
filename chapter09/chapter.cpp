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
#include <forward_list>
#include <fstream>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <list>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>

//
// ──────────────────────────────────────────────────────────────────────── I ──────────
//   :::::: R E G U L A R   F U N C T I O N : :  :   :    :     :        :          :
// ──────────────────────────────────────────────────────────────────────────────────
//

/**
 * @brief print vector<int>
 *
 * @param os
 * @param iv
 * @param sep
 * @return std::ostream&
 */
std::ostream &print(std::ostream &os, const std::vector<int> &iv, std::string sep)
{
    for (const auto &a : iv)
    {
        os << a << sep;
    }
    return os;
}

std::ostream &print(std::ostream &os, const std::list<int> &iv, std::string sep)
{
    for (const auto &a : iv)
    {
        os << a << sep;
    }
    return os;
}

std::ostream &print(std::ostream &os, const std::deque<int> &iv, std::string sep)
{
    for (const auto &a : iv)
    {
        os << a << sep;
    }
    return os;
}

std::ostream &print(std::ostream &os, const std::vector<std::string> &iv, std::string sep)
{
    for (const auto &a : iv)
    {
        os << a << sep;
    }
    return os;
}

std::ostream &print(std::ostream &os, const std::forward_list<int> &iv, std::string sep)
{
    for (const auto &a : iv)
    {
        os << a << sep;
    }
    return os;
}

std::ostream &print(std::ostream &os, const std::forward_list<std::string> &iv, std::string sep)
{
    for (const auto &a : iv)
    {
        os << a << sep;
    }
    return os;
}

//
// ──────────────────────────────────────────────────────────────────────── II ──────────
//   :::::: C H A P T E R   E X E R C I S E : :  :   :    :     :        :          :
// ──────────────────────────────────────────────────────────────────────────────────
//

#if 1
// 9.52
int main(int argc, char **argv)
{
    using std::cout;
    using std::endl;
    using std::stack;
    using std::string;
    auto &expr = "This is (Mooophy(awesome)((((wooooooooo))))) and (ocxs) over";
    auto repl = '#';
    auto seen = 0;

    stack<char> stk;

    for (auto c : expr)
    {
        stk.push(c);
        if (c == '(')
            ++seen; // open
        if (seen && c == ')')
        { // pop elements down to the stack
            while (stk.top() != '(')
                stk.pop();
            stk.pop();      // including the open parenthesis
            stk.push(repl); // push a value indicate it was replaced
            --seen;         // close
        }
    }

    // Test
    string output;
    for (; !stk.empty(); stk.pop())
        output.insert(output.begin(), stk.top());
    cout << output << endl; // "This is # and # over"

    return 0;
}
#endif

#if 0
// 9.38
int main(int argc, char **argv)
{
    std::vector<std::string> v;
    std::string word;

    while (std::cin >> word)
    {
        v.push_back(word);
        std::cout << v.capacity() << "\n";
    }

    return 0;
}
#endif

#if 0
// 9.35
int main(int argc, char **argv)
{
    std::vector<int> iVar1_cl{0, 1, 2, 3, 4};

    std::cout << iVar1_cl.capacity() << std::endl;
    std::cout << iVar1_cl.size() << std::endl;

    return 0;
}
#endif

#if 0
// 9.34
int main(int argc, char **argv)
{
    using std::cout;
    using std::endl;
    using std::vector;
    vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = vi.begin();
    while (iter != vi.end())
    {
        if (*iter % 2)
        {
            iter = vi.insert(iter, *iter);
            ++iter;
        }
        ++iter;
    }
    print(std::cout, vi, " ");

    return 0;
}
#endif

#if 0
// 9.33
int main(int argc, char **argv)
{
    using std::cout;
    using std::endl;
    using std::vector;
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto begin = v.begin();
    while (begin != v.end())
    {
        ++begin;
        begin = v.insert(begin, 42);
        ++begin;
    }

    print(std::cout, v, " ");

    return 0;
}
#endif

#if 0
// 9.32
int main(int argc, char **argv)
{
    using std::cout;
    using std::endl;
    using std::vector;
    vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = vi.begin();
    while (iter != vi.end())
    {
        if (*iter % 2)
        {
            iter = vi.insert(iter, *iter);
            iter += 2;
        }
        else
            iter = vi.erase(iter);
    }

    print(std::cout, vi, " ");

    return 0;
}
#endif

#if 0
// 9.31
int main(int argc, char **argv)
{
    using std::advance;
    using std::cout;
    using std::endl;
    using std::list;
    list<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = vi.begin();
    while (iter != vi.end())
    {
        if (*iter % 2)
        {
            iter = vi.insert(iter, *iter);
            advance(iter, 2);
        }
        else
            iter = vi.erase(iter);
    }
    print(std::cout, vi, " ");

    return 0;
}
#endif

#if 0
// 9.28
void insert(std::forward_list<std::string> &flst, std::string find, std::string insrt)
{
    auto prev = flst.before_begin();
    for (auto curr = flst.begin(); curr != flst.end(); prev = curr++)
    {
        if (*curr == find)
        {
            flst.insert_after(curr, insrt);
            return;
        }
    }
    flst.insert_after(prev, insrt);
}

int main(int argc, char **argv)
{
    std::forward_list<std::string> strVar1_cl{"hello", "cpp", "world", "!"};
    insert(strVar1_cl, "cpp", "c++");
    print(std::cout, strVar1_cl, " ");

    return 0;
}
#endif

#if 0
// 9.27
int main(int argc, char **argv)
{
    std::forward_list<int> iVar1_cl{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (auto prev = iVar1_cl.before_begin(), curr = iVar1_cl.begin(); curr != iVar1_cl.end();)
    {
        if (*curr & 0x01)
        {
            curr = iVar1_cl.erase_after(prev);
        }
        else
        {
            prev = curr++;
        }
    }
    print(std::cout, iVar1_cl, " ") << std::endl;

    return 0;
}
#endif

#if 0
// 9.26
int main(int argc, char **argv)
{
    // array -> vector,list 从list删除奇数，v删除偶数
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    std::vector<int> iVar1_cl(ia, std::end(ia));
    std::list<int> iVar2_cl(iVar1_cl.begin(), iVar1_cl.end());
    std::vector<std::string> strVar4_cl{"hello", "cpp", "world"};

    std::cout << "vector:\n";
    print(std::cout, iVar1_cl, " ") << std::endl;

    std::cout << "list:\n";
    print(std::cout, iVar2_cl, " ") << std::endl;

    for (auto it = iVar1_cl.begin(); it != iVar1_cl.end();)
    {
        if (*it & 0x01)
        {
            it = iVar1_cl.erase(it);
        }
        else
        {
            ++it;
        }
    }

    for (auto it = iVar2_cl.begin(); it != iVar2_cl.end();)
    {
        if (!(*it & 0x01))
        {
            it = iVar2_cl.erase(it);
        }
        else
        {
            ++it;
        }
    }

    std::cout << "vector:\n";
    print(std::cout, iVar1_cl, " ") << std::endl;

    std::cout << "list:\n";
    print(std::cout, iVar2_cl, " ") << std::endl;

    return 0;
}
#endif

#if 0
// 9.24
int main(int argc, char **argv)
{
    // 提取vector中第一个元素
    std::vector<int> iVar1_cl{10, 1, 2, 3};
    std::vector<int> iVar2_cl;

    std::cout << iVar1_cl.at(0) << std::endl;
    std::cout << iVar1_cl[0] << std::endl;
    std::cout << iVar1_cl.front() << std::endl;
    std::cout << *iVar1_cl.begin() << std::endl;

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