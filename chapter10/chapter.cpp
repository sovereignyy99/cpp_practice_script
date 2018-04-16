/*
 * @Author: MatthewPerry
 * @Date: 2018-04-04 11:48:29
 * @Last Modified by: MatthewPerry
 * @Last Modified time: 2018-04-16 14:48:54
 */

#include "my_little_functions.h"
#include "sales_data.h"
#include <algorithm>
#include <cctype>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <forward_list>
#include <fstream>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <list>
#include <numeric>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>

#if 1

int main(int argc, char *argv[])
{

    return 0;
}
#endif

#if 0
// 10.25
using std::string; using std::vector;
using namespace std::placeholders;

void elimdups(vector<string> &vs)
{
    std::sort(vs.begin(), vs.end());
    vs.erase(unique(vs.begin(),vs.end()), vs.end());
}

bool check_size(const string &s, string::size_type sz)
{
    return s.size() >= sz;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimdups(words);
    auto iter = std::stable_partition(words.begin(), words.end(), bind(check_size, _1, sz));
    for_each(words.begin(), iter, [](const string &s){ std::cout << s << " "; });
}

int main()
{
    std::vector<std::string> v{
        "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"
    };
    biggies(v, 4);
}
#endif

#if 0
// 10.24
bool CheckSize(const std::string &s, std::string::size_type sz);
int main(int argc, char **argv)
{
    // 给定一个string，使用bind和check_size 在一个int的vector中查找第一个大于string长度的值
    std::string s1{"hello"};
    std::vector<int> ivec{1, 3, 5, 7, 9};
    auto it = std::find_if(ivec.begin(), ivec.end(), bind(CheckSize, s1, std::placeholders::_1));//learn!
    std::cout << *it << std::endl;

    return 0;
}
bool CheckSize(const std::string &s, std::string::size_type sz)
{
    return s.size() < sz;
}
#endif

#if 0
// 10.22
bool IsShorterThan(const std::string &s, unsigned int i);
int main(int argc, char **argv)
{
    // 统计<=6的单词数量
    std::vector<std::string> s1{"hello", "worldddddd", "cpppppppppp", "fox"};
    auto c = std::count_if(s1.begin(), s1.end(), bind(IsShorterThan, std::placeholders::_1, 6));
    std::cout << c;

    return 0;
}
bool IsShorterThan(const std::string &s, unsigned int i)
{
    return s.size() <= i;
}
#endif

#if 0
// bind
bool CheckSize(const std::string &s, std::string::size_type sz);
int main(int argc, char **argv)
{
    auto check6 = std::bind(CheckSize, std::placeholders::_1, 6);
    std::string s2{"hellooo"};
    std::cout << check6(s2);
    std::vector<std::string> words{"hello", "world"};
    std::find_if(words.begin(), words.end(), check6);

    return 0;
}
bool CheckSize(const std::string &s, std::string::size_type sz)
{
    return s.size() >= sz;
}
#endif

#if 0
// 10.21
int main(int argc, char **argv)
{
    // 写lambda 捕获一个局部int变量，并递减，直到变为0
    // 一旦变为0，再调用lambda应该不再递减变量
    // lambda应该返回一个bool值，指出捕获的变量是否为0
    int i = 100;
    auto f = [&i]() -> bool { return i != 0 ? --i : 0; };

    int j = 1;
    while (f())
    {
        std::cout << ++j << std::endl;
    }
    std::cout << "i == " << j << std::endl;

    return 0;
}
#endif

#if 0
// 10.20
int main(int argc, char **argv)
{
    std::ifstream ifs("./input/i_fox.txt");
    std::ofstream ofs("./output/o_fox.txt");
    if (ifs && ofs)
    {
        std::vector<std::string> words;
        read(ifs, words);
        if (words.size())
        {
            print(ofs, words, " ") << std::endl;

            auto it = std::count_if(words.begin(), words.end(),
                                    [](const std::string &s) { return s.size() >= 6; });
            ofs << it << " items >= 6 \n";
        }
        else
        {
            std::cerr << "No data.\n";
        }
    }
    else
    {
        std::cerr << "Fail to open files.\n";
    }

    return 0;
}
#endif

#if 0
// 10.19
int main(int argc, char **argv)
{
    // the quick red fox jumps over the slow red turtle
    // sort it
    std::ifstream ifs("./input/i_fox.txt");
    std::ofstream ofs("./output/o_fox.txt");
    if (ifs && ofs)
    {
        std::vector<std::string> strVar1_cl;
        read(ifs, strVar1_cl);
        if (strVar1_cl.size())
        {
            const unsigned int kuiSize = 5;
            print(ofs, strVar1_cl, " ") << std::endl;
            std::sort(strVar1_cl.begin(), strVar1_cl.end());
            print(ofs, strVar1_cl, " ") << std::endl;
            auto atVar2 = std::unique(strVar1_cl.begin(), strVar1_cl.end());
            print(ofs, strVar1_cl, " ") << std::endl;
            strVar1_cl.erase(atVar2, strVar1_cl.cend());
            print(ofs, strVar1_cl, " ") << std::endl;

            std::stable_sort(strVar1_cl.begin(), strVar1_cl.end(),
                             [](const std::string &s1, const std::string s2) -> bool { return s1.size() < s2.size(); });
            print(ofs, strVar1_cl, " ") << std::endl;

            auto wc = std::stable_partition(strVar1_cl.begin(), strVar1_cl.end(),
                                            [kuiSize](const std::string &kstrS1) { return kstrS1.size() >= kuiSize; });
            auto count = wc - strVar1_cl.begin();
            ofs << "there are " << count << " words." << std::endl;

            std::for_each(strVar1_cl.begin(), strVar1_cl.end(),
                          [&ofs](const std::string &s) { ofs << s << " "; });
        }
        else
        {
            std::cerr << "No data.\n";
        }
    }
    else
    {
        std::cerr << "Fail to open files.\n";
    }

    return 0;
}
#endif

#if 0
// 10.18
int main(int argc, char **argv)
{
    // the quick red fox jumps over the slow red turtle
    // sort it
    std::ifstream ifs("./input/i_fox.txt");
    std::ofstream ofs("./output/o_fox.txt");
    if (ifs && ofs)
    {
        std::vector<std::string> strVar1_cl;
        read(ifs, strVar1_cl);
        if (strVar1_cl.size())
        {
            const unsigned int kuiSize = 5;
            print(ofs, strVar1_cl, " ") << std::endl;
            std::sort(strVar1_cl.begin(), strVar1_cl.end());
            print(ofs, strVar1_cl, " ") << std::endl;
            auto atVar2 = std::unique(strVar1_cl.begin(), strVar1_cl.end());
            print(ofs, strVar1_cl, " ") << std::endl;
            strVar1_cl.erase(atVar2, strVar1_cl.cend());
            print(ofs, strVar1_cl, " ") << std::endl;

            std::stable_sort(strVar1_cl.begin(), strVar1_cl.end(),
                             [](const std::string &s1, const std::string s2) -> bool { return s1.size() < s2.size(); });
            print(ofs, strVar1_cl, " ") << std::endl;

            auto wc = std::partition(strVar1_cl.begin(), strVar1_cl.end(),
                                     [kuiSize](const std::string &kstrS1) { return kstrS1.size() >= kuiSize; });
            auto count = wc - strVar1_cl.begin();
            ofs << "there are " << count << " words." << std::endl;

            std::for_each(strVar1_cl.begin(), strVar1_cl.end(),
                          [&ofs](const std::string &s) { ofs << s << " "; });
        }
        else
        {
            std::cerr << "No data.\n";
        }
    }
    else
    {
        std::cerr << "Fail to open files.\n";
    }

    return 0;
}
#endif

#if 0
// 10.17
bool CompareIsbn(const sales_data_cl &b1, const sales_data_cl &b2);
int main(int argc, char **argv)
{
    // sort sales_data class
    std::ifstream ifs("./input/books_data.txt");
    std::ofstream ofs("./output/o_sales_data.txt");
    if (ifs && ofs)
    {
        std::vector<sales_data_cl> strVar1_cl;
        sales_data_cl s1;
        while (read(ifs, s1))
        {
            strVar1_cl.push_back(s1);
        }
        if (strVar1_cl.size())
        {
            for (const auto &s : strVar1_cl)
            {
                print(ofs, s) << std::endl;
            }
            std::sort(strVar1_cl.begin(), strVar1_cl.end(),
                      [](const sales_data_cl &b1, const sales_data_cl &b2) { return b1.isbn() < b2.isbn(); });
            ofs << std::endl;
            ofs << std::endl;
            ofs << std::endl;
            for (const auto &s : strVar1_cl)
            {
                print(ofs, s) << std::endl;
            }
        }
        else
        {
            std::cerr << "No data.\n";
        }
    }
    else
    {
        std::cerr << "Fail to open files.\n";
    }

    return 0;
}
bool CompareIsbn(const sales_data_cl &b1, const sales_data_cl &b2)
{
    return b1.isbn() < b2.isbn();
}
#endif

#if 0
// 10.15
void Foo(int i);
int main(int argc, char **argv)
{
    Foo(5);

    return 0;
}
void Foo(int i)
{
    auto f = [i](int j) { return i + j; };
    auto k = f(6);
    std::cout << k << "\n";
}
#endif

#if 0
// 10.14
int main(int argc, char **argv)
{
    // 编写一个lambda，接收两个int，返回和
    auto f = [](int i, int j) { return i + j; };

    return 0;
}
#endif

#if 0
// 10.14
int main(int argc, char **argv)
{
    // the quick red fox jumps over the slow red turtle
    // sort it
    std::ifstream ifs("./input/i_fox.txt");
    std::ofstream ofs("./output/o_fox.txt");
    if (ifs && ofs)
    {
        std::vector<std::string> strVar1_cl;
        read(ifs, strVar1_cl);
        if (strVar1_cl.size())
        {
            const unsigned int kuiSize = 5;
            print(ofs, strVar1_cl, " ") << std::endl;
            std::sort(strVar1_cl.begin(), strVar1_cl.end());
            print(ofs, strVar1_cl, " ") << std::endl;
            auto atVar2 = std::unique(strVar1_cl.begin(), strVar1_cl.end());
            print(ofs, strVar1_cl, " ") << std::endl;
            strVar1_cl.erase(atVar2, strVar1_cl.cend());
            print(ofs, strVar1_cl, " ") << std::endl;

            std::stable_sort(strVar1_cl.begin(), strVar1_cl.end(),
                             [](const std::string &s1, const std::string s2) -> bool { return s1.size() < s2.size(); });
            print(ofs, strVar1_cl, " ") << std::endl;

            auto wc = std::find_if(strVar1_cl.begin(), strVar1_cl.end(),
                                   [kuiSize](const std::string &kstrS1) { return kstrS1.size() >= kuiSize; });
            auto count = strVar1_cl.end() - wc;
            ofs << "there are " << count << " words." << std::endl;

            std::for_each(strVar1_cl.begin(), strVar1_cl.end(),
                          [&ofs](const std::string &s) { ofs << s << " "; });
        }
        else
        {
            std::cerr << "No data.\n";
        }
    }
    else
    {
        std::cerr << "Fail to open files.\n";
    }

    return 0;
}
#endif

#if 0
// 10.13
bool IsLongerThan5(const std::string &s1);
int main(int argc, char **argv)
{
    // 用partition算法，接受一个谓词，对内容进行划分，true的排在容器的前半部分
    // false的排在后半部分，算法返回一个迭代器，指向最后一个使谓词为true的元素之后的位置
    // 编写函数，接受一个string，返回bool，指出string是否有5个或更多字符
    // 使用此函数划分words，打印长度大于等于5的元素
    std::ifstream ifs("./input/i_fox.txt");
    std::ofstream ofs("./output/o_fox.txt");
    if (ifs && ofs)
    {
        std::vector<std::string> words;
        read(ifs, words);
        if (words.size())
        {
            print(ofs, words, " ") << std::endl;
            auto it = std::partition(words.begin(), words.end(), IsLongerThan5);
            for (auto it1 = words.begin(); it1 != it; ++it1)
            {
                ofs << *it1 << std::endl;
            }
        }
        else
        {
            std::cerr << "No data.\n";
        }
    }
    else
    {
        std::cerr << "Fail to open files.\n";
    }

    return 0;
}
bool IsLongerThan5(const std::string &s1)
{
    return s1.size() >= 5;
}
#endif

#if 0
// 10.12
bool CompareIsbn(const sales_data_cl &b1, const sales_data_cl &b2);
int main(int argc, char **argv)
{
    // sort sales_data class
    std::ifstream ifs("./input/books_data.txt");
    std::ofstream ofs("./output/o_sales_data.txt");
    if (ifs && ofs)
    {
        std::vector<sales_data_cl> strVar1_cl;
        sales_data_cl s1;
        while (read(ifs, s1))
        {
            strVar1_cl.push_back(s1);
        }
        if (strVar1_cl.size())
        {
            for (const auto &s : strVar1_cl)
            {
                print(ofs, s) << std::endl;
            }
            std::sort(strVar1_cl.begin(), strVar1_cl.end(), CompareIsbn);
            ofs << std::endl;
            ofs << std::endl;
            ofs << std::endl;
            for (const auto &s : strVar1_cl)
            {
                print(ofs, s) << std::endl;
            }
        }
        else
        {
            std::cerr << "No data.\n";
        }
    }
    else
    {
        std::cerr << "Fail to open files.\n";
    }

    return 0;
}
bool CompareIsbn(const sales_data_cl &b1, const sales_data_cl &b2)
{
    return b1.isbn() < b2.isbn();
}
#endif

#if 0
// 10.11
bool IsShorter(const std::string &s1, const std::string &s2);
int main(int argc, char **argv)
{
    // the quick red fox jumps over the slow red turtle
    // sort it
    std::ifstream ifs("./input/i_fox.txt");
    std::ofstream ofs("./output/o_fox.txt");
    if (ifs && ofs)
    {
        std::vector<std::string> strVar1_cl;
        read(ifs, strVar1_cl);
        if (strVar1_cl.size())
        {
            print(ofs, strVar1_cl, " ") << std::endl;
            // std::sort(strVar1_cl.begin(), strVar1_cl.end(), IsShorter);
            std::sort(strVar1_cl.begin(), strVar1_cl.end());
            print(ofs, strVar1_cl, " ") << std::endl;
            auto atVar2 = std::unique(strVar1_cl.begin(), strVar1_cl.end());
            print(ofs, strVar1_cl, " ") << std::endl;
            strVar1_cl.erase(atVar2, strVar1_cl.cend());
            print(ofs, strVar1_cl, " ") << std::endl;
            std::stable_sort(strVar1_cl.begin(), strVar1_cl.end(), IsShorter);
            print(ofs, strVar1_cl, " ") << std::endl;
        }
        else
        {
            std::cerr << "No data.\n";
        }
    }
    else
    {
        std::cerr << "Fail to open files.\n";
    }

    return 0;
}
bool IsShorter(const std::string &s1, const std::string &s2)
{
    return s1.size() < s2.size();
}
#endif

#if 0
// 10.8
int main(int argc, char **argv)
{
    // the quick red fox jumps over the slow red turtle
    // sort it
    std::ifstream ifs("./input/i_fox.txt");
    std::ofstream ofs("./output/o_fox.txt");
    if (ifs && ofs)
    {
        std::vector<std::string> strVar1_cl;
        read(ifs, strVar1_cl);
        if (strVar1_cl.size())
        {
            print(ofs, strVar1_cl, " ") << std::endl;
            std::sort(strVar1_cl.begin(), strVar1_cl.end());
            print(ofs, strVar1_cl, " ") << std::endl;
            auto atVar2 = std::unique(strVar1_cl.begin(), strVar1_cl.end());
            print(ofs, strVar1_cl, " ") << std::endl;
            strVar1_cl.erase(atVar2, strVar1_cl.cend());
            print(ofs, strVar1_cl, " ") << std::endl;
        }
        else
        {
            std::cerr << "No data.\n";
        }
    }
    else
    {
        std::cerr << "Fail to open files.\n";
    }

    return 0;
}
#endif

#if 0
// 10.8
int main(int argc, char **argv)
{
    // the quick red fox jumps over the slow red turtle
    // sort it
    std::vector<std::string> strVar1_cl;
    read(std::cin, strVar1_cl);
    if (strVar1_cl.size())
    {
        std::sort(strVar1_cl.begin(), strVar1_cl.end());
        auto atVar2 = std::unique(strVar1_cl.begin(), strVar1_cl.end());
        strVar1_cl.erase(atVar2, strVar1_cl.cend());
        print(std::cout, strVar1_cl, " ");
    }
    else
    {
        std::cerr << "No data.\n";
    }

    return 0;
}
#endif

#if 0
// 10.8
int main(int argc, char **argv)
{
    // 算法不改变容器大小，但迭代器可通过操作容器改变容器大小


    return 0;
}
#endif

#if 0
// 10.7
int main(int argc, char **argv)
{
    std::vector<int> ivec;
    ivec.resize(10);
    fill_n(ivec.begin(), 10, 0);

    return 0;
}
#endif

#if 0
// 10.7
int main(int argc, char **argv)
{
    std::vector<int> ivec;
    std::list<int> ilst;
    int i;
    while (std::cin >> i)
    {
        ilst.push_back(i);
    }
    std::copy(ilst.cbegin(), ilst.cend(), std::back_inserter(ivec));

    return 0;
}
#endif

#if 0
// 10.6
int main(int argc, char **argv)
{
    // fill_n
    std::vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    print(std::cout, ivec, " ");
    std::cout << std::endl;
    std::fill_n(ivec.begin(), ivec.size(), 0);
    print(std::cout, ivec, " ");
    std::cout << std::endl;

    return 0;
}
#endif

#if 0
// 10.5
int main(int argc, char **argv)
{
    // equal
    std::vector<const char *> strRoster1_cl{"Susan", "LiLeilei"};
    std::vector<const char *> kcpRoster2_cl{"Susan", "LiLeilei"};

    std::cout << std::equal(strRoster1_cl.cbegin(), strRoster1_cl.cend(), kcpRoster2_cl.cbegin())
              << std::endl;

    return 0;
}
#endif

#if 0
// 10.4
int main(int argc, char **argv)
{
    // 求vector<double>里的元素之和
    // 求和起点影响如何取和，设为0则结果是100，设为0.0则结果是101.0
    std::vector<double> ivec(10, 10.1);
    print(std::cout, ivec, " ");
    std::cout << "\n";
    double sum = std::accumulate(ivec.cbegin(), ivec.cend(), 0.0);
    std::cout << "sum of vector: " << sum << std::endl;

    return 0;
}
#endif

#if 0
// 10.3
int main(int argc, char **argv)
{
    // 求vector<int>里的元素之和
    std::vector<int> ivec(10, 10);
    print(std::cout, ivec, " ");
    std::cout << "\n";
    int sum = std::accumulate(ivec.cbegin(), ivec.cend(), 0);
    std::cout << "sum of vector: " << sum << std::endl;

    return 0;
}
#endif

#if 0
// 10.2
int main(int argc, char **argv)
{
    // 打印有多少个元素值等于给定
    std::vector<std::string> svec;
    read(std::cin, svec);

    if (svec.size())
    {
        std::string s1 = "hello";
        int cnt = std::count(svec.cbegin(), svec.cend(), s1);
        std::cout << "\n"
                  << cnt << std::endl;

        s1 = "world";
        auto it = std::find(svec.cbegin(), svec.cend(), s1);
        if (it != svec.cend())
        {
            std::cout << "\ndata found: " << s1 << std::endl;
        }
        else
        {
            std::cout << "no " << s1 << "in vector.\n";
        }
    }
    else
    {
        std::cerr << "no data.\n";
    }

    return 0;
}
#endif

#if 0
// 10.1
int main(int argc, char **argv)
{
    // 打印有多少个元素值等于给定
    std::vector<int> ivec;
    read(std::cin, ivec);
    if (ivec.size())
    {
        int ival = 10;
        int cnt = std::count(ivec.cbegin(), ivec.cend(), ival);
        std::cout << cnt << std::endl;
    }
    else
    {
        std::cerr << "no data.\n";
    }

    return 0;
}
#endif