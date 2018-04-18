/*
 * @Author: MatthewPerry
 * @Date: 2018-04-04 11:48:29
 * @Last Modified by: MatthewPerry
 * @Last Modified time: 2018-04-16 14:48:54
 */

#include "Sales_item.h"
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
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#if 1
// 11.12
int main(int argc, char **argv)
{
    std::pair<std::string, std::string> anon{"James", "Joyce"};
    std::pair<std::string, std::size_t> word_count;
    std::pair<std::string, std::vector<int>> line;

    std::cout << anon.first << " " << anon.second << "\n";

    return 0;
}
#endif

#if 0
// pair type
int main(int argc, char **argv)
{
    std::pair<std::string, std::string> anon{"James", "Joyce"};
    std::pair<std::string, std::size_t> word_count;
    std::pair<std::string, std::vector<int>> line;

    std::cout << anon.first << " " << anon.second << "\n";

    return 0;
}
#endif

#if 0
// 11.9-11
bool CompareIsbn(const sales_data_cl &lhs, const sales_data_cl &rhs);
int main(int argc, char **argv)
{
    // 定义一个map，单词与行号的list关联，list保存的是单词出现的行号
    std::map<std::string, std::list<std::size_t>> words_lno;
    // 可以定义如下形式
    std::map<std::vector<int>::iterator, int> m1;
    std::map<std::list<int>::iterator, int> m2;
    // 不使用decltype
    using fp1 = bool (*)(const sales_data_cl &lhs, const sales_data_cl &rhs);
    std::multiset<sales_data_cl, fp1> BookStore1(&CompareIsbn);

    typedef bool (*fp2)(const sales_data_cl &lhs, const sales_data_cl &rhs);
    std::multiset<sales_data_cl, fp2> BookStore2(&CompareIsbn);

    std::multiset<sales_data_cl, bool (*)(const sales_data_cl &lhs, const sales_data_cl &rhs)> BookStore3(&CompareIsbn);

    return 0;
}

bool CompareIsbn(const sales_data_cl &lhs, const sales_data_cl &rhs)
{
    return lhs.isbn() < rhs.isbn();
}
#endif

#if 0
// key word type
bool CompareIsbn(const sales_data_cl &lhs, const sales_data_cl &rhs);
int main(int argc, char **argv)
{
    std::multiset<sales_data_cl, decltype(CompareIsbn) *> BookStore(&CompareIsbn);

    return 0;
}

bool CompareIsbn(const sales_data_cl &lhs, const sales_data_cl &rhs)
{
    return lhs.isbn() < rhs.isbn();
}
#endif

#if 0
// 11.8
int main(int argc, char **argv)
{
    std::vector<std::string> exclude = {"aa", "bb", "cc"};
    for (std::string word; std::cin >> word;)
    {
        if (std::find(exclude.begin(), exclude.end(), word) != exclude.end())
            std::cout << "excluded!" << std::endl;
        else
            exclude.push_back(word);
    }
    for (auto const &s : exclude)
        std::cout << s << " ";
    std::cout << std::endl;

    return 0;
}
#endif

#if 0
// 11.7
// very good stuff..
int main(int argc, char **argv)
{
    std::map<std::string, std::vector<std::string>> family;
    std::string LastName, ChildrenName;

    while ([&]() -> bool {
        std::cout << "Please enter last name:\n";
        return std::cin >> LastName && LastName != "@q";
    }())
    {
        std::cout << "Please enter children's name:\n";
        while (std::cin >> ChildrenName && ChildrenName != "@q")
        {
            family[LastName].push_back(ChildrenName);
        }
    }

    for (auto e : family)
    {
        std::cout << e.first << ":\n";

        for (auto c : e.second)
            std::cout << c << " ";
        std::cout << "\n";
        std::cout << "========================================================\n";
    }

    return 0;
}
#endif

#if 0
// 11.7
int main(int argc, char **argv)
{
    //! @Alan
    //!
    //! Exercise 11.7:
    //! Define a map for which the key is the familyâ€™s last name and
    //! the value is a vector of the childrenâ€™s names. Write code to
    //! add new families and to add new children to an existing family.
    //  Discussion on Stack Overflow:
    //  http://stackoverflow.com/questions/20608365/is-it-possible-to-code-this-waywhilelambda
    //!
    std::map<std::string, std::vector<std::string>> famls;
    std::string lastName, chldName;

    //! while(lambda)
    //! go to the discussions on stack overfow for more.
    while ([&]() -> bool {
        std::cout << "Please enter last name:\n";

        return std::cin >> lastName && lastName != "@q";
    }())
    //!  ^^
    //! the () used here is to call the lambda ,otherwise it does not work
    //! go to the post on stack overflow for more detail.

    {
        std::cout << "PLZ Enter children's name:\n";
        while (std::cin >> chldName && chldName != "@q")
        {
            //! add new items into the vector
            famls[lastName].push_back(chldName);
        }
    }

    //! iterate through the map.
    for (auto e : famls)
    {
        std::cout << e.first << ":\n";

        //! iterate through the vector.
        for (auto c : e.second)
            std::cout << c << " ";
        std::cout << "\n";
        std::cout << "========================================================\n";
    }

    return 0;
}
#endif

#if 0
// 11.7
int main(int argc, char **argv)
{
    // key-家庭的姓  value-孩子们的名字
    // 添加新的家庭，已有家庭添加新的孩子
    std::map<std::string, std::vector<std::string>> family;
    std::string lastname, children;

    while ((std::cout << "please enter your last name: \n") &&
           std::cin >> lastname && lastname != "@q")
    {
        std::cout << "please enter your children's name: \n";
        std::vector<std::string> strvec;
        while (std::cin >> children && children != "@q")
        {
            strvec.push_back(children);
        }
        family[lastname] = strvec;
    }

    std::cout << "family: \n";
    for (auto &fm : family)
    {
        std::cout << "last names: \n"
                  << fm.first << "\n";
        std::cout << "children: \n";
        for (auto &n : fm.second)
        {
            std::cout << n << std::endl;
        }
        std::cout << "========================================================\n";
    }

    return 0;
}
#endif

#if 0
// 11.4
int main(int argc, char **argv)
{
    // 统计输入的每个单词的出现次数
    // 用map数据结构，关键字是单词，值是次数
    std::map<std::string, size_t> words_count;
    std::set<std::string> exclude{"The", "But", "And", "Or", "An", "A",
                                  "the", "but", "and", "an", "a", "or"};
    std::string word;
    while (std::cin >> word)
    {
        // 所有的word转换为小写形式
        for (auto &ch : word)
        {
            ch = tolower(ch);
        }
        // 将标点符号去掉
        // 使用remove_if函数
        word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
        if (exclude.find(word) == exclude.end())
        {
            ++words_count[word];
        }
    }
    for (const auto &wc : words_count)
    {
        std::cout << wc.first << " occurs " << wc.second
                  << (wc.second > 1 ? " times." : " time.") << std::endl;
    }

    return 0;
}
#endif

#if 0
// map and set
typedef struct words_count_st_tag
{
    std::string word;
    size_t count;
} words_count_st;

int main(int argc, char **argv)
{
    // 统计输入的每个单词的出现次数
    // 用map数据结构，关键字是单词，值是次数
    std::vector<words_count_st> words_count;
    std::string word;
    while (std::cin >> word)
    {
        bool flag = false;
        for (auto &wc : words_count)
        {
            if (wc.word == word)
            {
                ++wc.count;
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            words_count.push_back(words_count_st{word, 1});
        }
    }

    for (auto &wc : words_count)
    {
        std::cout << wc.word << " occurs " << wc.count
                  << (wc.count > 1 ? " times." : " time.") << std::endl;
    }

    return 0;
}
#endif

#if 0
// map and set
// 11.3
int main(int argc, char **argv)
{
    // 统计输入的每个单词的出现次数
    // 用map数据结构，关键字是单词，值是次数
    std::map<std::string, size_t> words_count;
    std::set<std::string> exclude{"The", "But", "And", "Or", "An", "A",
                                  "the", "but", "and", "an", "a", "or"};
    std::string word;
    while (std::cin >> word)
    {
        if (exclude.find(word) == exclude.end())
        {
            ++words_count[word];
        }
    }
    for (auto &wc : words_count)
    {
        std::cout << wc.first << " occurs " << wc.second
                  << (wc.second > 1 ? " times." : " time.") << std::endl;
    }

    return 0;
}
#endif

#if 0
// map and set
int main(int argc, char **argv)
{
    // 统计输入的每个单词的出现次数
    // 用map数据结构，关键字是单词，值是次数
    std::map<std::string, size_t> words_count;
    std::string word;
    while (std::cin >> word)
    {
        ++words_count[word];
    }
    for (auto &wc : words_count)
    {
        std::cout << wc.first << " occurs " << wc.second
                  << (wc.second > 1 ? " times." : " time.") << std::endl;
    }

    return 0;
}
#endif