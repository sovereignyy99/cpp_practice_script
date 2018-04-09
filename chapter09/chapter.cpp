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
#include <fstream>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#if 1
// 9.5
int main(int argc, char **argv)
{

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