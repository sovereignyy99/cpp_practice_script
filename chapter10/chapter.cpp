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
// 10.1
int main(int argc, char **argv)
{
    std::cout << "hello,world.";

    return 0;
}
#endif