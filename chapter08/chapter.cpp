/*
 * @Author: MatthewPerry
 * @Date: 2018-04-04 11:48:29
 * @Last Modified by: MatthewPerry
 * @Last Modified time: 2018-04-09 12:06:15
 */

#include "person_info.h"
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
// 8.14
bool Valid(const std::string &s);
int main(int argc, char **argv)
{
    // 读取数据，保存person_info到vector中

    const std::string strInFile = "./input/i_person_info.txt";
    std::ifstream ifs;
    ifs.open(strInFile, std::ifstream::in);
    if (!ifs)
    {
        std::cerr << "Fail to open i_file.\n";
        return (-1);
    }

    std::istringstream iss;
    std::string strLine;
    std::vector<person_info_cl> People_cl_a;
    while (getline(ifs, strLine))
    {
        iss.clear();
        iss.str(strLine);
        std::string strWord;
        person_info_cl People_cl;
        if (iss >> strWord)
        {
            People_cl.strName = strWord;
        }
        while (iss >> strWord)
        {
            People_cl.strPhones_a.push_back(strWord);
        }
        People_cl_a.push_back(People_cl);
    }

    // 校验号码是否有误，最后输出到文件
    const std::string strOutFile = "./output/o_person_info.txt";
    std::ofstream ofs(strOutFile, std::ofstream::app);
    if (!ofs)
    {
        std::cerr << "Fail to open o_file.\n";
        return (-1);
    }

    for (const auto &p : People_cl_a)
    {
        std::ostringstream ossBadNo, ossFormatted;
        for (const auto &ph : p.strPhones_a)
        {
            if (!Valid(ph))
            {
                ossBadNo << "#" << ph;
            }
            else
            {
                ossFormatted << "*" << ph;
            }

            if (ossBadNo.str().empty())
            {
                ofs << p.strName << " " << ossFormatted.str() << std::endl;
            }
            else
            {
                ofs << "error: " << p.strName << " invalid number: " << ossBadNo.str() << std::endl;
            }
        }
    }

    return 0;
}

bool Valid(const std::string &s)
{
    for (const auto atCh : s)
    {
        if ((atCh < '0') || (atCh > '9'))
        {
            return false;
        }
    }

    return true;
}
#endif

#if 0
// 8.11
int main(int argc, char **argv)
{
    // 读取数据，保存person_info到vector中

    const std::string strInFile = "./input/person_info.txt";
    std::ifstream ifs;
    ifs.open(strInFile, std::ifstream::in);
    if (!ifs)
    {
        std::cerr << "Fail to open file.\n";
        return (-1);
    }

    std::istringstream iss;
    std::string strLine;
    std::vector<person_info_cl> People_cl_a;
    while (getline(ifs, strLine))
    {
        iss.clear();
        iss.str(strLine);
        std::string strWord;
        person_info_cl People_cl;
        if (iss >> strWord)
        {
            People_cl.strName = strWord;
        }
        while (iss >> strWord)
        {
            People_cl.strPhones_a.push_back(strWord);
        }
        People_cl_a.push_back(People_cl);
    }

    for (auto &p : People_cl_a)
    {
        std::cout << p.strName << std::ends;
        for (auto &ph : p.strPhones_a)
        {
            std::cout << ph << std::ends;
        }
        std::cout << std::endl;
    }

    return 0;
}
#endif

#if 0
// 8.10
int main(int argc, char **argv)
{
    // 将来自文件的行保存到vector中，使用istringstream从vector读取元素，每次读取一个单词
    // const std::string strInFile = "./input/essay_big.txt";
    const std::string strInFile = "./input/essay.txt";
    std::ifstream ifs;
    ifs.open(strInFile, std::ifstream::in);
    if (ifs)
    {
        std::string strLine;
        std::vector<std::string> strText_a;
        while (getline(ifs, strLine))
        {
            strText_a.push_back(strLine);
        }

        for (const auto &katLine : strText_a)
        {
            std::istringstream iss1(katLine);
            std::string strLineTemp;
            while (iss1 >> strLineTemp)
            {
                std::cout << strLineTemp << " ";
            }
            std::cout << std::endl;
        }
    }
    else
    {
        std::cerr << "Fail to open file.\n";
    }

    return 0;
}
#endif

#if 0
// 8.9
std::istream &DisplayInStream(std::istream &is);

int main(int argc, char **argv)
{
    std::string strS1 = "Hello,world.\n";
    std::string strS2 = "Hello,cpp world.\n";
    std::istringstream iss1(strS1);
    std::istringstream iss2(strS2);

    std::cout << iss1.str() << std::flush;
    std::cout << iss2.str() << std::ends;

    DisplayInStream(iss1);
    DisplayInStream(iss2);

    return 0;
}

std::istream &DisplayInStream(std::istream &is)
{
    std::string buf;
    while (is >> buf)
        std::cout << buf << std::ends;
    is.clear();

    return is;
}
#endif

#if 0
// 8.8
int main(int argc, char **argv)
{
    // 从文件读入记录，文件名从main函数传入，输出追加到给定文件的末尾
    // i_sales_data.txt    o_sales_data.txt
    // isbn相同则合并，不同输出数据，直到记录末尾

    if (argc == 3)
    {
        std::string strInFile = argv[1];
        std::string strOutFile = argv[2];

        std::ifstream ifs(strInFile, std::ifstream::in);
        std::ofstream ofs(strOutFile, std::ofstream::app);

        if (ifs && ofs)
        {
            sales_data_cl Total_cl;
            if (read(ifs, Total_cl))
            {
                sales_data_cl Trans_cl;
                while (read(ifs, Trans_cl))
                {
                    if (Total_cl.isbn() == Trans_cl.isbn())
                    {
                        Total_cl.combine(Trans_cl);
                    }
                    else
                    {
                        print(ofs, Total_cl) << std::endl;
                        Total_cl = Trans_cl;
                    }
                }
                print(ofs, Total_cl) << std::endl;
            }
            else
            {
                std::cerr << "No data?\n";
            }
        }
        else
        {
            std::cerr << "Fail to open files.\n";
        }
    }
    else
    {
        std::cerr << "No file?\n";
    }

    return 0;
}
#endif

#if 0
// 8.7
int main(int argc, char **argv)
{
    // 从文件读入记录，文件名从main函数传入，输出到文件
    // i_sales_data.txt    o_sales_data.txt
    // isbn相同则合并，不同输出数据，直到记录末尾

    if (argc == 3)
    {
        std::string strInFile = argv[1];
        std::string strOutFile = argv[2];

        std::ifstream ifs(strInFile, std::ifstream::in);
        std::ofstream ofs(strOutFile, std::ofstream::out);

        if (ifs && ofs)
        {
            sales_data_cl Total_cl;
            if (read(ifs, Total_cl))
            {
                sales_data_cl Trans_cl;
                while (read(ifs, Trans_cl))
                {
                    if (Total_cl.isbn() == Trans_cl.isbn())
                    {
                        Total_cl.combine(Trans_cl);
                    }
                    else
                    {
                        print(ofs, Total_cl) << std::endl;
                        Total_cl = Trans_cl;
                    }
                }
                print(ofs, Total_cl) << std::endl;
            }
            else
            {
                std::cerr << "No data?\n";
            }
        }
        else
        {
            std::cerr << "Fail to open files.\n";
        }
    }
    else
    {
        std::cerr << "No file?\n";
    }

    return 0;
}
#endif

#if 0
// 8.6
int main(int argc, char **argv)
{
    // 读入记录，isbn相同则合并，不同输出数据，直到记录末尾
    sales_data_cl Total_cl;
    if (read(std::cin, Total_cl))
    {
        sales_data_cl Trans_cl;
        while (read(std::cin, Trans_cl))
        {
            if (Total_cl.isbn() == Trans_cl.isbn())
            {
                Total_cl.combine(Trans_cl);
            }
            else
            {
                print(std::cout, Total_cl) << std::endl;
                Total_cl = Trans_cl;
            }
        }
        print(std::cout, Total_cl) << std::endl;
    }
    else
    {
        std::cerr << "No data?\n";
    }

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