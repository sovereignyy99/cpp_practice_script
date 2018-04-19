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
// 11.38
void WordCount(void);
void wordTransformation(void);

int main(int argc, char **argv)
{
    WordCount();
    wordTransformation();

    return 0;
}
void WordCount(void)
{
    std::ifstream ifs_map("./input/essay.txt");
    if (!ifs_map)
        return;
    std::unordered_map<std::string, size_t> word_count;

    for (std::string word; ifs_map >> word; ++word_count[word])
    {
        ;
    }

    for (const auto &w : word_count)
    {
        std::cout << w.first << " occurs " << w.second
                  << (w.second > 1 ? " times." : " time.") << std::endl;
    }
}

void wordTransformation(void)
{
    std::ifstream ifs_map("./input/trans_rules.txt"), ifs_content("./input/trans_input.txt");
    if (!ifs_map || !ifs_content)
    {
        std::cerr << "can't find the documents." << std::endl;
        return;
    }

    std::unordered_map<std::string, std::string> trans_map;
    for (std::string key, value; ifs_map >> key && getline(ifs_map, value);)
        if (value.size() > 1)
            trans_map[key] = value.substr(1).substr(0, value.find_last_not_of(' '));

    for (std::string text, word; getline(ifs_content, text); std::cout << std::endl)
        for (std::istringstream iss(text); iss >> word;)
        {
            auto map_it = trans_map.find(word);
            std::cout << (map_it == trans_map.cend() ? word : map_it->second) << " ";
        }
}
#endif

#if 0
// unordered associative container
int main(int argc, char **argv)
{
    std::unordered_map<std::string, size_t> word_count;
    std::string word;
    while (std::cin >> word)
    {
        ++word_count[word];
    }
    for (const auto &w : word_count)
    {
        std::cout << w.first << " occurs " << w.second
                  << ((w.second > 1) ? " times." : " time.") << std::endl;
    }

    std::cout << "bucket_count:\n"
              << word_count.bucket_count();

    return 0;
}
#endif

#if 0
// 11.35
int main(int argc, char **argv)
{

    // In buildMap, what effect, if any, would there be from rewriting trans_map[key]
    // = value.substr(1); astrans_map.insert({key, value.substr(1)})?
    // • use subscript operator: if a word does appear multiple times, our loops will put
    // the last corresponding phrase into trans_map
    // • use insert: if a word does appear multiple times, our loops will put
    // the first corresponding phrase into trans_map

    std::cout << "hello,world.";

    return 0;
}
#endif

#if 0
// 11.33
// trans using map
std::map<std::string, std::string> BuildMap(std::ifstream &ifs);
const std::string &TransformWord(std::string &s, const std::map<std::string, std::string> &m);
void TextTransform(std::ifstream &imap, std::ifstream &itext, std::ofstream &otext);

int main(int argc, char **argv)
{
    std::ifstream ifs_map("./input/trans_rules.txt");
    std::ifstream ifs_content("./input/trans_input.txt");
    std::ofstream ofs_OText("./output/trans_output.txt");

    if (ifs_map && ifs_content && ofs_OText)
    {
        TextTransform(ifs_map, ifs_content, ofs_OText);
    }
    else
    {
        std::cerr << "Fail to open files.\n";
    }

    return 0;
}

/**
 * @brief build map
 *
 * @param ifs
 * @return std::map<std::string, std::string>
 */
std::map<std::string, std::string> BuildMap(std::ifstream &ifs)
{
    std::map<std::string, std::string> m1;
    for (std::string key, value; ifs >> key && getline(ifs, value);)
    {
        if (value.size() > 1) // 防止out of range
        {
            m1[key] = value.substr(1).substr(0, value.find_last_not_of(' '));
        }
    }

    return m1;
}

const std::string &TransformWord(std::string &s, const std::map<std::string, std::string> &m)
{
    return m.find(s) == m.end() ? s : m.at(s);
}

void TextTransform(std::ifstream &imap, std::ifstream &itext, std::ofstream &otext)
{
    std::map<std::string, std::string> tmap = BuildMap(imap);
    for (std::string line; getline(itext, line);) // i love for loop..
    {
        std::istringstream issLine(line);
        for (std::string s; issLine >> s;)
        {
            otext << TransformWord(s, tmap) << " ";
        }
        otext << std::endl;
    }
}
#endif

#if 0
// 11.33
// trans using map
using std::ifstream;
using std::string;

std::map<string, string> buildMap(ifstream &map_file)
{
    std::map<string, string> trans_map;
    for (string key, value; map_file >> key && getline(map_file, value);)
        if (value.size() > 1)
            trans_map[key] = value.substr(1).substr(0, value.find_last_not_of(' '));
    return trans_map;
}

const string &transform(const string &s, const std::map<string, string> &m)
{
    auto map_it = m.find(s);
    return map_it == m.cend() ? s : map_it->second;
}

void word_transform(ifstream &map, ifstream &input)
{
    auto trans_map = buildMap(map);
    for (string text; getline(input, text);)
    {
        std::istringstream iss(text);
        for (string word; iss >> word;)
            std::cout << transform(word, trans_map) << " ";
        std::cout << std::endl;
    }
}
int main(int argc, char **argv)
{
    ifstream ifs_map("../data/word_transformation_bad.txt"), ifs_content("../data/given_to_transform.txt");
    if (ifs_map && ifs_content)
        word_transform(ifs_map, ifs_content);
    else
        std::cerr << "can't find the documents." << std::endl;

    return 0;
}
#endif

#if 0
// 11.33
// trans using map
int main(int argc, char **argv)
{
    // 给定一个string，转换成另一个string
    // 两个文件输入，第一个文件保存规则，另一个保存待转换文本
    std::ifstream ifsRule("./input/trans_rules.txt");
    std::ifstream ifsText("./input/trans_input.txt");
    std::ofstream ofsOutText("./output/trans_output.txt");

    if (ifsRule && ifsText && ofsOutText)
    {
        // 制作规则map
        std::map<std::string, std::vector<std::string>> rules;
        std::string strStemp;
        while (getline(ifsRule, strStemp))
        {
            std::istringstream issRules(strStemp);
            std::string s1, s2;
            issRules >> s1;
            while (issRules >> s2)
            {
                rules[s1].push_back(s2);
            }
        }

        // 读入文本
        std::vector<std::string> itext;
        std::vector<std::string> otext;
        while (getline(ifsText, strStemp))
        {
            itext.push_back(strStemp);
        }

        // 解码
        for (auto &iline : itext)
        {
            std::istringstream issLine(iline);
            std::string s1, s2;
            while (issLine >> s1)
            {
                if (rules.find(s1) != rules.end()) // 找到关键字
                {
                    for (auto &iword : rules.at(s1))
                    {
                        s2 += iword;
                        s2 += " ";
                    }
                }
                else
                {
                    s2 += s1;
                    s2 += " ";
                }
            }
            otext.push_back(s2);
        }

        // 输出文本
        for (const auto &x : otext)
        {
            ofsOutText << x << std::endl;
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
// 11.32
int main(int argc, char **argv)
{
    std::multimap<std::string, std::string> authors{
        {"alan", "DMA"},
        {"pezy", "LeetCode"},
        {"alan", "CLRS"},
        {"wang", "FTP"},
        {"pezy", "CP5"},
        {"wang", "CPP-Concurrency"}};
    std::map<std::string, std::multiset<std::string>> order_authors;

    for (const auto &author : authors)
        order_authors[author.first].insert(author.second);

    for (const auto &author : order_authors)
    {
        std::cout << author.first << ": ";
        for (const auto &work : author.second)
            std::cout << work << " ";
        std::cout << std::endl;
    }

    return 0;
}
#endif

#if 0
// 11.31
int main(int argc, char **argv)
{
    // 作者及作品 multimap  删除其中的元素，确保元素不在map时也能正常运行
    std::multimap<std::string, std::string> authors{
        {"alan", "DMA"},
        {"pezy", "LeetCode"},
        {"alan", "CLRS"},
        {"wang", "FTP"},
        {"pezy", "CP5"},
        {"wang", "CPP-Concurrency"}};
    // want to delete an element that author is [Alan], work is [112].
    std::string author = "pezy";
    std::string work = "CP5";

    auto found = authors.find(author);
    auto count = authors.count(author);
    while (count)
    {
        if (found->second == work)
        {
            authors.erase(found);
            break;
        }
        ++found;
        --count;
    }

    for (const auto &author : authors)
        std::cout << author.first << " " << author.second << std::endl;

    return 0;
}
#endif

#if 0
// 11.31
int main(int argc, char **argv)
{
    // 作者及作品 multimap  删除其中的元素，确保元素不在map时也能正常运行
    std::multimap<std::string, std::vector<std::string>> m{{"szy", {"English", "Japanese", "French"}}, {"zsy", {"Germen", "Chinese", "Spanish"}}};
    auto it = m.find("szy");
    m.erase(it);
    m.erase("syz");

    for (auto &x : m)
    {
        std::cout << x.first << ":" << std::endl;
        for (auto &y : x.second)
        {
            std::cout << y << std::endl;
        }
    }

    return 0;
}
#endif

#if 0
// 11.28
int main(int argc, char **argv)
{
    std::map<std::string, std::vector<int>> m;
    m = {{"Alan", {
                      1,
                      2,
                      3,
                      4,
                      5,
                  }},
         {"John", {1, 5, 6, 7, 8}}};

    //! ex11.28
    std::map<std::string, std::vector<int>>::iterator it;
    //! ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    //! type used to define this iterator.

    it = m.find("Alan");

    return 0;
}
#endif

#if 0
// 11.24-26
int main(int argc, char **argv)
{
    //! ex11.24
    std::map<int, int> m;
    m[0] = 1;

    for (const auto &e : m)
        std::cout << e.first << " " << e.second << "\n";

    //! ex11.25
    std::vector<int> v;
    // v[0] = 1;        //illegal

    for (const auto &e : v)
        std::cout << e << "\n";

    //! ex11.26
    std::map<int, std::string> map = {{1, "ss"}, {2, "sz"}};

    std::map<int, std::string>::key_type type_to_subscript = 1;
    //! ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    //! that is, int.

    std::map<int, std::string>::mapped_type type_to_return = map[type_to_subscript];
    //! ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    //! that is, std::string

    return 0;
}
#endif

#if 0
// 11.23
// good stuff..
int main(int argc, char **argv)
{
   std::multimap<std::string, std::string> families;
    for (std::string lastName, childName; std::cin >> childName >> lastName; families.emplace(lastName, childName));
    for (const auto &s : families)
        std::cout << s.second << " " << s.first << std::endl;

    return 0;
}
#endif

#if 0
// 11.22
int main(int argc, char **argv)
{
    std::map<std::string, std::vector<int>> m1;
    std::pair<std::map<std::string, std::vector<int>>::iterator, bool> x1 = m1.insert({"hello", std::vector<int>(10, 1)});

    std::cout << "x1: \n"
              << x1.first->first << "\n";

    for (auto &x : x1.first->second)
    {
        std::cout << x << std::endl;
    }

    std::cout << (x1.second ? "true" : "false") << "\n";

    return 0;
}
#endif

#if 0
// 11.21
int main(int argc, char **argv)
{
    std::map<std::string, size_t> word_count;
    std::string word;
    while (std::cin >> word)
    {
        ++word_count.insert(std::make_pair(word, 0)).first->second;
    }

    for (const auto &w : word_count)
    {
        std::cout << w.first << " " << w.second
                  << ((w.second > 1) ? " times" : " time") << std::endl;
    }

    return 0;
}
#endif

#if 0
// 11.20
int main(int argc, char **argv)
{
    std::map<std::string, size_t> word_count;
    std::string word;
    while (std::cin >> word)
    {
        auto ret = word_count.insert(std::make_pair(word, 1));
        if (!ret.second)
        {
            ++ret.first->second;
        }
    }

    //! print the content of the map.
    for (const auto &w : word_count)
    {
        std::cout << w.first << " " << w.second
                  << ((w.second > 1) ? " times" : " time") << std::endl;
    }

    return 0;
}
#endif

#if 0
// 11.15-16
int main(int argc, char **argv)
{
    int i(1);
    std::vector<int> ivec{1};
    std::map<int, std::vector<int>> m1;
    std::map<int, std::vector<int>>::key_type x1 = std::make_pair(i, ivec).first;
    std::map<int, std::vector<int>>::mapped_type x2 = std::make_pair(i, ivec).second;
    std::map<int, std::vector<int>>::value_type x3 = std::make_pair(i, ivec);

    m1[1] = ivec;
    m1[2] = ivec;
    std::map<int, std::vector<int>>::iterator it1 = m1.begin();
    it1->second = std::vector<int>{10};
    for (auto &x : m1)
    {
        std::cout << x.first << "\n";
        for (auto &v : x.second)
        {
            std::cout << v << "\n";
        }
    }

    return 0;
}
#endif

#if 0
// 11.14
int main(int argc, char **argv)
{
    //! define a map as required.
    std::map<std::string, std::vector<std::pair<std::string, std::string>>>
        famlies_map;
    //! declare three strings to store the input
    std::string lastName, childName, birthday;

    while ([&]() { //!   a lambda to read lastName and check if should quit
        std::cout << "last name:\n";
        std::cin >> lastName;

        return lastName != "@q";
    }())
    {
        while ([&]() { //!   a lambda to read child name and birthday and check if should quit
            std::cout << "child's name:\n";
            std::cin >> childName;
            std::cout << "his birthday:\n";
            std::cin >> birthday;

            return childName != "@q" && birthday != "@q";
        }())
        {
            famlies_map[lastName].push_back({childName, birthday});
            //!        ^^^^^^^^^^           ^^^^^^^^^^^^^^^^^^^^^
            //!  use lastName as the key    create a pair using {}.
        }
    }

    //! print the content.
    for (const auto &e : famlies_map)
    {
        std::cout << e.first << ":\n";

        for (const auto &l : e.second)
        {
            std::cout << l.first << " "
                      << l.second << " ";
        }
    }

    return 0;
}
#endif

#if 0
// 11.14
int main(int argc, char **argv)
{
    // 在11.7的基础上扩展，添加一个pair的vector保存孩子的名和生日
    std::map<std::string, std::vector<std::pair<std::string, std::string>>> family;
    std::string LastName, ChildrenName, Birthday;

    while ([&]() -> bool {
        std::cout << "please enter last name:\n";
        return std::cin >> LastName && LastName != "@q";
    }())
    {
        while ([&]() -> bool {
            std::cout << "please enter children's first name:\n";
            std::cin >> ChildrenName;
            std::cout << "please enter children's birthday:\n";
            std::cin >> Birthday;
            return ChildrenName != "@q" && Birthday != "@q";
        }())
        {
            family[LastName].emplace_back(ChildrenName, Birthday);
        }
    }

    for (auto e : family)
    {
        std::cout << e.first << ":\n";

        for (auto c : e.second)
        {
            std::cout << c.first << " : " << c.second << "\n";
        }

        std::cout << "========================================================\n";
    }

    return 0;
}
#endif

#if 0
// 11.12-13
int main(int argc, char **argv)
{
    // 读入string和int的序列，将每个string和int存入一个pair，pair保存到vector
    std::vector<std::pair<std::string, int>> vec;
    std::string s1;
    int i1;

    // 方法1
    while ([&]() -> bool {
        std::cout << "please enter a string:\n";
        return std::cin >> s1 && s1 != "@q";
    }())
    {
        std::cout << "please enter a integer:\n";
        if (std::cin >> i1)
        {
            vec.push_back(std::pair<std::string, int>(s1, i1));
            vec.push_back(std::make_pair(s1, i1));
            vec.push_back({s1, i1});
            vec.emplace_back(s1, i1);
        }
        else
        {
            std::cerr << "error: no integer.\n";
        }
    }

    // 方法2
    // while (std::cin >> s1 >> i1)
    // {
    //     vec.push_back(std::pair<std::string, int>(s1, i1));
    //     vec.push_back(std::make_pair(s1, i1));
    //     vec.push_back({s1, i1});
    //     vec.emplace_back(s1, i1);
    // }

    if (vec.size())
    {
        for (auto &x : vec)
        {
            std::cout << "first of pair: "
                      << x.first << std::endl;

            std::cout << "second of pair: "
                      << x.second << std::endl;

            std::cout << "========================================================\n";
        }
    }
    else
    {
        std::cerr << "error: no data.\n";
    }

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