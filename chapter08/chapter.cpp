/*
 * @Author: MatthewPerry
 * @Date: 2018-04-04 11:48:29
 * @Last Modified by: MatthewPerry
 * @Last Modified time: 2018-04-07 13:13:40
 */

#include <cctype>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <vector>


#if 1
// 8.6
int main(int argc, char **argv)
{


    return 0;
}
#endif

#if 0
// 8.5
void ReadFileToVec(const std::string &fileName, std::vector<std::string> &vec);
int main(int argc, char **argv)
{
    std::vector<std::string> vec;
    ReadFileToVec(".\\input\\itest.txt", vec);
    for (const auto &str : vec)
        std::cout << str << std::endl;

    return 0;
}

void ReadFileToVec(const std::string &fileName, std::vector<std::string> &vec)
{
    std::ifstream ifs(fileName);
    if (ifs)
    {
        std::string buf;
        while (ifs >> buf)
            // while (std::getline(ifs, buf))
            vec.push_back(buf);
    }
}
#endif

#if 0
// 8.4
int main(int argc, char **argv)
{
    // 读模式打开一个文件，内容读入到 string 的 vector里，将每一行作为独立元素存入vector
    std::string strInputDir = ".\\input\\itest.txt";
    std::ifstream ifsInput;
    ifsInput.open(strInputDir, std::ifstream::in);
    if (ifsInput)
    {
        std::vector<std::string> strV1_a;
        std::string s1;
        while (getline(ifsInput, s1))
        // while(ifsInput>>s1)
        {
            strV1_a.push_back(s1);
        }
        std::cout << "Done.\n";

        for (const auto &s2 : strV1_a)
        {
            std::cout << s2 << "\n";
        }
    }
    else
    {
        std::cout << "Fail to open file.\n";
    }

    return 0;
}
#endif

#if 0
// fstream
int main(int argc, char **argv)
{
    // ifstream
    // ofstream
    std::string strInputDir = ".\\input\\itest.txt";
    std::string strOutputDir = ".\\output\\otest.txt";
    std::ifstream ifsInput(strInputDir);
    std::ofstream ofsOutput(strOutputDir);

    if (ifsInput && ofsOutput)
    {
        std::string s2;
        while (ifsInput >> s2)
        {
            ofsOutput << s2 << "\n";
        }
        std::cout << "Done!\n";
    }
    else
    {
        std::cout << "File open failed.\n";
    }

    return 0;
}
#endif

#if 0
// buffer refresh
int main(int argc, char **argv)
{
    // cin 和 cout关联，故下面的语句会导致cout 刷新
    int val;
    std::cin >> val;
    std::cin.tie(&std::cout);
    // 存储旧关联
    std::ostream *OldTie = std::cin.tie(nullptr);
    // 关联到cerr
    std::cin.tie(&std::cerr);
    // 重新关联到cout
    std::cin.tie(&std::cout);

    return 0;
}
#endif

#if 0
// buffer refresh
int main(int argc, char **argv)
{
    std::cout << "hi endl" << std::endl;
    std::cout << "hi ends" << std::ends;
    std::cout << "hi flush" << std::flush;
    std::cout << std::unitbuf;
    std::cout << "hi";
    std::cout << std::nounitbuf;
    // cin 和 cout关联，故下面的语句会导致cout 刷新
    int val;
    std::cin >> val;

    return 0;
}
#endif

#if 0
// 8.2
std::istream &DisplayInStream(std::istream &is);

int main(int argc, char **argv)
{
    DisplayInStream(std::cin);
    std::cout << "hi endl" << std::endl;
    std::cout << "hi flush" << std::flush;
    std::cout << "hi ends" << std::ends;

    return 0;
}

std::istream &DisplayInStream(std::istream &is)
{
    std::string buf;
    while (is >> buf)
        std::cout << buf << std::endl;
    is.clear();

    return is;
}
#endif

#if 0
// iostream
int main(int argc, char **argv)
{
    // 保存当前流的状态，操作后恢复到原状态
    auto OldState=std::cin.rdstate();
    std::cin.clear();
    std::string s1;
    getline(std::cin,s1);
    std::cin.setstate(OldState);
    // 复位failbit和badbit，其他位不变
    std::cin.clear(std::cin.rdstate() & ~std::cin.failbit & ~std::cin.badbit);

    return 0;
}
#endif