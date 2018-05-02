/*
 * @Author: MatthewPerry
 * @Date: 2018-04-16 10:03:27
 * @Last Modified by: MatthewPerry
 * @Last Modified time: 2018-04-16 10:33:17
 */

#ifndef MY_LITTLE_FUNCTIONS_H
#define MY_LITTLE_FUNCTIONS_H

#include <array>
#include <deque>
#include <forward_list>
#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <vector>

//
// ────────────────────────────────────────────────── I ──────────
//   :::::: P R I N T : :  :   :    :     :        :          :
// ────────────────────────────────────────────────────────────
//

std::ostream &print(std::ostream &os, const std::vector<int> &iv, std::string sep)
{
    for (const auto &a : iv)
    {
        os << a << sep;
    }
    return os;
}

std::ostream &print(std::ostream &os, const std::vector<double> &iv, std::string sep)
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
// ──────────────────────────────────────────────── II ──────────
//   :::::: R E A D : :  :   :    :     :        :          :
// ──────────────────────────────────────────────────────────
//

std::istream &read(std::istream &is, std::vector<int> &ivec)
{
    int i = 0;

    while (is >> i)
    {
        ivec.push_back(i);
    }

    return is;
}

std::istream &read(std::istream &is, std::list<int> &ilst)
{
    int i = 0;

    while (is >> i)
    {
        ilst.push_back(i);
    }

    return is;
}

std::istream &read(std::istream &is, std::vector<std::string> &svec)
{
    std::string s;

    while (is >> s)
    {
        svec.push_back(s);
    }

    return is;
}

std::istream &read(std::istream &is, std::list<std::string> &slst)
{
    std::string s;

    while (is >> s)
    {
        slst.push_back(s);
    }

    return is;
}

#endif