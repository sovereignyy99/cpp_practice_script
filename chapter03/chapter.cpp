/*
 * @Author: MattewPerry
 * @Date: 2018-03-15 15:11:54
 * @Last Modified by:   MattewPerry
 * @Last Modified time: 2018-03-15 15:11:54
 */

#include <cctype>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

// using namespace std;
using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::iterator;
using std::string;
using std::vector;

#if 1
//3.45
//multidimensional array
int main(int argc, char **agrv)
{
    int ia[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}};

    // a range for to manage the iteration
    for (auto &p : ia)
        for (int q : p)
            cout << q << " ";
    cout << endl;

    // ordinary for loop using subscripts
    for (size_t i = 0; i != 3; ++i)
        for (size_t j = 0; j != 4; ++j)
            cout << ia[i][j] << " ";
    cout << endl;

    // using pointers.
    for (auto p = ia; p != ia + 3; ++p)
        for (int *q = *p; q != *p + 4; ++q)
            cout << *q << " ";
    cout << endl;

    return 0;
}
#endif

#if 0
//3.44
//multidimensional array
int main(int argc, char **agrv)
{
    int ia[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}};

    // a range for to manage the iteration
    // use type alias
    using int_array = int[4];
    for (int_array &p : ia)
        for (int q : p)
            cout << q << " ";
    cout << endl;

    // ordinary for loop using subscripts
    for (size_t i = 0; i != 3; ++i)
        for (size_t j = 0; j != 4; ++j)
            cout << ia[i][j] << " ";
    cout << endl;

    // using pointers.
    // use type alias
    for (int_array *p = ia; p != ia + 3; ++p)
        for (int *q = *p; q != *p + 4; ++q)
            cout << *q << " ";
    cout << endl;

    return 0;
}
#endif

#if 0
//3.43
//multidimensional array
int main(int argc, char **agrv)
{
    int ia[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}};

    // a range for to manage the iteration
    for (const int(&p)[4] : ia)
        for (int q : p)
            cout << q << " ";
    cout << endl;

    // ordinary for loop using subscripts
    for (size_t i = 0; i != 3; ++i)
        for (size_t j = 0; j != 4; ++j)
            cout << ia[i][j] << " ";
    cout << endl;

    // using pointers.
    for (int(*p)[4] = ia; p != ia + 3; ++p)
        for (int *q = *p; q != *p + 4; ++q)
            cout << *q << " ";
    cout << endl;

    return 0;
}
#endif

#if 0
//3.41
//vector and array
int main(int argc, char **agrv)
{
    //vector 数组
    vector<int> v1(10, 1);
    vector<int> va[10];
    for (size_t i = 0; i < 10; ++i)
    {
        va[i] = v1;
    }

    //利用整型数组初始化vector对象
    int v2[10];
    vector<int> va2(begin(v2), end(v2));

    //拷贝vector里面的数据到整型数组
    vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int int_arr[10];

    for (int *i = begin(int_arr); i != end(int_arr); ++i)
        *i = ivec[i - begin(int_arr)];

    for (auto i : int_arr)
        cout << i << " ";
    cout << endl;

    return 0;
}
#endif

#if 0
//3.40
//c-style charater
int main(int argc, char **agrv)
{
    const char* cs1 = "Wangyue";
    const char* cs2 = "Pezy";

    size_t size = strlen(cs1) + strlen(cs2) + 1;
    char* cs3 = new char(size);

    strcpy(cs3, cs1);
    strcat(cs3, " ");
    strcat(cs3, cs2);

    cout << cs3 << endl;

    delete cs3;

    return 0;
}
#endif

#if 0
//3.39
//c-style charater
int main(int argc, char **agrv)
{
    // use string.
    string s1("Mooophy");
    string s2("Pezy");

    if (s1 == s2)
      cout << "same string." << endl;
    else if (s1 > s2)
      cout << "Mooophy > Pezy" << endl;
    else
      cout << "Mooophy < Pezy" << endl;

    cout << "=========" << endl;
    // use C-Style character strings.
    const char* cs1 = "Wangyue";
    const char* cs2 = "Pezy";

    auto result = strcmp(cs1, cs2);
    if (result == 0)
      cout << "same string." << endl;
    else if (result < 0)
      cout << "Wangyue < Pezy" << endl;
    else
      cout << "Wangyue > Pezy" << endl;

    return 0;
}
#endif

#if 0
//3.37
//c-style charater
int main(int argc, char **agrv)
{
    const char ch[] = {'h', 'e', 'l', 'l', 'o'};
    const char ch2[] = {'h', 'e', 'l', 'l', 'o'};
    const char *pch = ch;

    //非法，本意输出ch，但是会输出到ch2
    while (*pch)
    {
        cout << *pch << endl;
        ++pch;
    }

    return 0;
}
#endif

#if 0
//3.30
//array
int main(int argc, char **agrv)
{
    //p1 p2 指向同一数组的元素，p1+=p2-p1
    int a1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *p1 = &a1[2];
    int *p2 = &a1[9];

    p1 += p2 - p1;
    cout << *p1 << endl;
    cout << a1[9] << endl;

    //利用指针将数组元素置为0
    for (auto ip = 0; ip < 10; ++ip)
    {
        cout << a1[ip] << endl;
    }
    int *pbeg = begin(a1);
    int *pend = end(a1);
    for (auto ip = pbeg; ip != pend; ++ip)
    {
        *ip = 0;
    }
    for (auto ip = 0; ip < 10; ++ip)
    {
        cout << a1[ip] << endl;
    }

    return 0;
}
#endif

#if 0
//3.30
//array
int main(int argc, char **agrv)
{
    // 定义含有10个int的数组，值=下标
    int iV1_a[10], iV3_a[10];
    for (auto aV2 = 0; aV2 < 10; ++aV2)
    {
        iV1_a[aV2] = aV2;
        iV3_a[aV2] = iV1_a[aV2];
    }

    vector<int> iV4_a;
    for (auto aV2 = 0; aV2 < 10; ++aV2)
    {
        iV4_a.push_back(aV2);
    }
    vector<int> iV5_a(iV4_a);

    for(auto aV2:iV1_a)
    {
        cout << aV2 << endl;
    }
    for(auto aV2:iV3_a)
    {
        cout << aV2 << endl;
    }
    for(auto aV2:iV4_a)
    {
        cout << aV2 << endl;
    }
    for(auto aV2:iV5_a)
    {
        cout << aV2 << endl;
    }

    return 0;
}
#endif

#if 0
//3.25
//iterator
int main(int argc, char **agrv)
{
    // 假设有一组成绩组合为0~100分，输入一组成绩，每10分为一段，统计每个分数段的成绩个数
    // 用迭代器重做
    vector<unsigned> scores(11, 0);
    unsigned grade;
    while (cin >> grade)
        if (grade <= 100)
            ++(*(scores.begin() + grade / 10)); //表达相当简洁

    for (auto score : scores)
        cout << score << " ";
    cout << endl;

    return 0;
}
#endif

#if 0
//3.25
//iterator
//binary search
int main(int argc, char **agrv)
{
    //!二分搜索
    //有序序列中，查找某个元素，取中间值，如果是所需元素则结束
    //否则，假设小于要找的值，则在后半段继续，大于要找的值，在前半段继续
    vector<string> strText_a;
    string strIn;
    while (getline(cin, strIn))
    {
        strText_a.push_back(strIn);
    }

    const string kstrSought = "z";
    auto it_beg = strText_a.begin();
    auto it_end = strText_a.end();
    auto it_mid = it_beg + (it_end - it_beg) / 2;

    while(*it_mid!=kstrSought && it_mid!=it_end)
    {
        if(*it_mid>kstrSought)
        {
            it_end = it_mid;
        }else{
            it_beg = it_mid + 1;
        }
        it_mid = it_beg + (it_end - it_beg) / 2;
    }
    cout << *it_mid << endl;

    return 0;
}
#endif

#if 0
//3.24
//iterator
int main(int argc, char **agrv)
{
    //迭代器运算
    // it+n   it-n   it+=n   it-=n
    // it1-it2
    // it1>/>=it2   </<=
    //测试大小关系比较
    vector<int> iV1_a(10, 100);
    auto it1 = iV1_a.begin();
    it1 += 5;
    auto it2 = it1 - 3;
    auto it_mid = iV1_a.begin() + iV1_a.size() / 2;     //中间元素的迭代器
    auto differ = it1 - it2;    //difference_type  带符号整型

    if (it1 > it2)
    {
        cout << "it1 > it2" << endl;
    }
    else
    {
        cout << "it1 < it2" << endl;        //true
    }

    // system("pause");
    // getchar();
    // getchar();
    return 0;
}
#endif

#if 0
//3.23
//iterator
int main(int argc, char **agrv)
{
    //箭头运算符    (*it).empty()====>it->empty()
    //!使用迭代器的循环体，不能向容器中添加元素，会导致迭代器失效

    //建立含10个整数的vector，用迭代器将数*2，输出
    vector<int> iV1_a(10, 5);
    for (vector<int>::iterator Iter = iV1_a.begin(); Iter != iV1_a.end();++Iter){
        *Iter = (*Iter) * 2;
    }
    for(auto aV2:iV1_a)
    {
        cout << aV2 << ' ';
    }

        // system("pause");
        // getchar();
        // getchar();
        return 0;
}
#endif

#if 0
//3.22
//iterator
int main(int argc, char **agrv)
{
    vector<string> text;
    for (string line; getline(cin, line);)
        text.push_back(line);

    for (auto it = text.begin(); it != text.end() && !it->empty(); ++it)
    {
        for (auto &c : *it)
            c = toupper(c);
        cout << *it << endl;
    }

    return 0;
}
#endif

#if 0
//3.22
//iterator
int main(int argc, char **agrv)
{
    //箭头运算符    (*it).empty()====>it->empty()
    //!使用迭代器的循环体，不能向容器中添加元素，会导致迭代器失效

    //读入一篇文章，用空白行隔绝段落，读入改成大写并打印第一段
    vector<string> strText_a;
    string strIn;
    uint16_t uiCnt = 0;
    while (getline(cin, strIn))
    {
        if (++uiCnt == 7) //第7段是空白行
        {
            string strTmp;
            strText_a.push_back(strTmp);
        }
        else
        {
            strText_a.push_back(strIn);
        }
    }

    for (auto aIter = strText_a.begin(); aIter != strText_a.end() && !aIter->empty(); ++aIter)
    {
        for (auto &aCh : *aIter)
        {
            aCh = toupper(aCh);
        }
        cout << *aIter << endl;
    }

    // system("pause");
    // getchar();
    // getchar();
    return 0;
}
#endif

#if 0
//3.22
//iterator
void check(const vector<int>& vec)
{
  if (vec.empty())
    cout << "size: 0; no values." << endl;
  else
  {
    cout << "size: " << vec.size() << "; values:";
    for (auto it = vec.begin(); it != vec.end(); ++it)
      cout << *it << ",";
    cout << "\b." << endl;
  }
}

void check(const vector<string>& vec)
{
  if (vec.empty())
    cout << "size: 0; no values." << endl;
  else
  {
    cout << "size: " << vec.size() << "; values:";
    for (auto it = vec.begin(); it != vec.end(); ++it)
      if (it->empty()) cout << "(null)" << ",";
      else cout << *it << ",";
    cout << "\b." << endl;
  }
}

int main()
{
  vector<int> v1;
  vector<int> v2(10);
  vector<int> v3(10, 42);
  vector<int> v4{10};
  vector<int> v5{10, 42};
  vector<string> v6{10};
  vector<string> v7{10, "hi"};

  check(v1);
  check(v2);
  check(v3);
  check(v4);
  check(v5);
  check(v6);
  check(v7);

  return 0;
}
#endif

#if 0
//3.21
//iterator
int main(int argc, char **agrv)
{
    //箭头运算符    (*it).empty()====>it->empty()
    //!使用迭代器的循环体，不能向容器中添加元素，会导致迭代器失效

    //读入一篇文章，用空白行隔绝段落，读入并打印第一段
    vector<string> strText_a;
    string strIn;
    uint16_t uiCnt = 0;
    while (getline(cin, strIn))
    {
        if(++uiCnt==7)  //第7段是空白行
        {
            string strTmp;
            strText_a.push_back(strTmp);
        }else
        {
            strText_a.push_back(strIn);
        }
    }

    for (auto aIter = strText_a.cbegin(); aIter != strText_a.cend() && !aIter->empty(); ++aIter)
    {
        cout << *aIter << endl;
    }

    // system("pause");
    // getchar();
    // getchar();
    return 0;
}
#endif

#if 0
//3.21
//iterator
//iterator type
int main(int argc, char **agrv)
{
    //iterator 类型
    vector<int>::iterator V1;
    string::iterator V2;
    vector<string>::const_iterator V3;  //只能读取所指的元素，不能写入

    vector<int> iV4_a;
    const vector<int> kiV5_a;
    auto aV6 = iV4_a.begin();   //iterator
    auto aV7 = kiV5_a.begin();  //const_iterator
    *aV6 = *aV7;
    auto aV8 = iV4_a.cbegin();  //c++11===>const_iterator

    cout << "\r\n\r\n\r\n\r\n\r\nDone!\a\r\n\r\n\r\n\r\n\r\n";
    // system("pause");
    // getchar();
    // getchar();
    return 0;
}
#endif

#if 0
//3.21
//iterator
//define and operation
int main(int argc, char **agrv)
{
    //迭代器指向容器中的元素或者string的字符
    //迭代器指向某个元素或尾后（尾后迭代器） off-the-end iterator
    // *iter  =&x
    // iter->mem
    // ++iter , --iter
    // iter1==iter2  iter1!=iter2
    //!解引用迭代器得到引用，注意检查其合法性，对非法迭代器或尾后迭代器解引用的操作是未定义的

    //将string对象第一个字母改为大写
    string strV1 = "hello, world!";
    if (strV1.begin() != strV1.end())
    {
        auto aV2 = strV1.begin();
        *aV2 = toupper(*aV2); //!解引用前记得检查是否合法
    }
    cout << strV1 << endl;
    //将第一个单词大写
    for (auto aV3 = strV1.begin(); (aV3 != strV1.end()) && (!isspace(*aV3)); ++aV3)
    {
        *aV3 = toupper(*aV3);
    }
    cout << strV1 << endl;

    cout << "\r\n\r\n\r\n\r\n\r\nDone!\a\r\n\r\n\r\n\r\n\r\n";
    // system("pause");
    // getchar();
    // getchar();
    return 0;
}
#endif

#if 0
//3.20
//vector
int main(int argc, char **agrv)
{
    //读入一组整数存入vector，将相邻整数的和输出
    //改写，先输出1和最后1个的和，然后2和倒数2的和，以此类推
    //方法1
    // vector<int> iV1_a;
    // int iV2 = 0;
    // int iV3 = 0;
    // while (cin >> iV2)
    // {
    //     iV1_a.push_back(iV2);
    //     if (++iV3 >= 2)
    //     {
    //         cout << iV1_a[iV3 - 2] + iV1_a[iV3 - 1] << endl;
    //     }
    // }

    //方法2
    // vector<int> iV1_a;
    // int iV2 = 0;
    // while(cin>>iV2){
    //     iV1_a.push_back(iV2);
    // }

    // for (decltype(iV1_a.size()) dtV3 = 0; dtV3 != (iV1_a.size()-1);++dtV3){
    //     cout << iV1_a[dtV3] + iV1_a[dtV3 + 1] << endl;
    // }

    vector<int> ivec;
    int i;
    while (cin >> i)
        ivec.push_back(i);

    if (ivec.empty())
    {
        cout << "input at least one integer." << endl;
        return -1;
    }
    else if (ivec.size() == 1)
    {
        cout << ivec[0] << " don't have any adjacent elements.";
    }
    else
    {
        for (decltype(ivec.size()) i = 0; i != ivec.size() - 1; ++i)
            cout << ivec[i] + ivec[i + 1] << " ";
    }

    cout << endl;

    decltype(ivec.size()) size = ivec.size();
    if (size % 2 != 0)
        size = size / 2 + 1;
    else
        size /= 2;

    for (decltype(ivec.size()) i = 0; i != size; ++i)
        cout << ivec[i] + ivec[ivec.size() - i - 1] << " ";
    cout << endl;

    cout << "\r\n\r\n\r\n\r\n\r\nDone!\a\r\n\r\n\r\n\r\n\r\n";
    // system("pause");
    // getchar();
    // getchar();
    return 0;
}
#endif

#if 0
//3.19
//vector
int main(int argc, char **agrv)
{
    //从cin读入一组词存入vector，所有词改成大学，输出，每词一行
    vector<string> strV1_a;
    string strV2;
    while(cin>>strV2){
        strV1_a.push_back(strV2);
    }

    for(auto aV3:strV1_a){
        for(auto &aV4:aV3)
        {
            aV4 = toupper(aV4);
        }
        cout << aV3 << endl;
    }

    //定义含有10个元素的vector对象，=42，三种方式实现
    bool blV8 = false;
    vector<int> iV5_a(10, 42);
    vector<int> iV6_a{42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
    vector<int> iV7_a={42, 42, 42, 42, 42, 42, 42, 42, 42, 42};

    if((iV5_a==iV6_a)&&(iV5_a==iV7_a))
    {
        blV8 = true;
    }else
    {
        blV8 = false;
    }
    cout << blV8 << endl;       // =1

    cout << "\r\n\r\n\r\n\r\n\r\nDone!\a\r\n\r\n\r\n\r\n\r\n";
    // system("pause");
    // getchar();
    // getchar();
    return 0;
}
#endif

#if 0
//3.16
//vector
int main(int argc, char **agrv)
{
    vector<int> v1;
    cout << "{\n \"v1\":{\"size\":\"" << v1.size() << "\",\"value\":[";
    for (auto i : v1)
        cout << i << ",";
    if (!v1.empty())
        cout << "\b";
    cout << "]}" << endl;

    vector<int> v2(10);
    cout << " \"v2\":{\"size\":\"" << v2.size() << "\",\"value\":[";
    for (auto i : v2)
        cout << i << ",";
    if (!v2.empty())
        cout << "\b";
    cout << "]}" << endl;

    vector<int> v3(10, 42);
    cout << " \"v3\":{\"size\":\"" << v3.size() << "\",\"value\":[";
    for (auto i : v3)
        cout << i << ",";
    if (!v3.empty())
        cout << "\b";
    cout << "]}" << endl;

    vector<int> v4{10};
    cout << " \"v4\":{\"size\":\"" << v4.size() << "\",\"value\":[";
    for (auto i : v4)
        cout << i << ",";
    if (!v4.empty())
        cout << "\b";
    cout << "]}" << endl;

    vector<int> v5{10, 42};
    cout << " \"v5\":{\"size\":\"" << v5.size() << "\",\"value\":[";
    for (auto i : v5)
        cout << i << ",";
    if (!v5.empty())
        cout << "\b";
    cout << "]}" << endl;

    vector<string> v6{10};
    cout << " \"v6\":{\"size\":\"" << v6.size() << "\",\"value\":[";
    for (auto i : v6)
        if (i.empty())
            cout << "(null)"
                 << ",";
        else
            cout << i << ",";
    if (!v6.empty())
        cout << "\b";
    cout << "]}" << endl;

    vector<string> v7{10, "hi"};
    cout << " \"v7\":{\"size\":\"" << v7.size() << "\",\"value\":[";
    for (auto i : v7)
        if (i.empty())
            cout << "(null)"
                 << ",";
        else
            cout << i << ",";
    if (!v7.empty())
        cout << "\b";
    cout << "]}\n}" << endl;

    return 0;
}
#endif

#if 0
//3.15
//vector
//add elements and subscript operation
int main(int argc, char **agrv)
{
    //对空vector执行下标操作能通过编译，但执行出错，行为未定义
    // vector<int> iV1_a;
    // cout << iV1_a[0] << endl;

    //假设有一组成绩组合为0~100分，输入一组成绩，每10分为一段，统计每个分数段的成绩个数
    //巧妙的利用vector和下标
    uint16_t ucGrade = 0;
    vector<uint16_t> ucSta_a(11, 0);

    while (cin >> ucGrade)
    {
        if (ucGrade <= 100)
        {
            ++ucSta_a[ucGrade / 10];
        }
    }

    for (auto aIdx : ucSta_a)
    {
        cout << aIdx << " ";
    }

    cout << "\r\n\r\n\r\n\r\n\r\nDone!\a\r\n\r\n\r\n\r\n\r\n";
    // system("pause");
    // getchar();
    // getchar();
    return 0;
}
#endif

#if 0
//3.15
//vector
//add elements
int main(int argc, char **agrv)
{
    //!范围for语句内不能改变其遍历序列的大小
    //读入一组数据，存入vector
    //读入整数
    vector<int> iV1_a;
    vector<string> strV4_a;
    int iV2 = 0;
    string strV3;

    // while (cin >> iV2)
    // {
    //     iV1_a.push_back(iV2);
    // }
    // for(auto aV5:iV1_a)
    // {
    //     cout << aV5 << endl;
    // }

    while (cin >> strV3)
    {
        strV4_a.push_back(strV3);
    }
    for(auto aV5:strV4_a)
    {
        cout << aV5 << endl;
    }

    cout << "\r\n\r\n\r\n\r\n\r\nDone!\a\r\n\r\n\r\n\r\n\r\n";
    // system("pause");
    // getchar();
    // getchar();
    return 0;
}
#endif

#if 0
//3.13
//vector
//define,initialization
int main(int argc, char **agrv)
{
    vector<string> strV1_a;
    vector<string> strV2_a{"ha", "hei", "he"};
    vector<string> strV3_a = {"ha", "hei", "he"};
    vector<int> iV4_a(10, -1);
    vector<string> strV5_a(10, "hello,world!");

    for (auto aV6 : strV3_a)
    {
        cout << aV6 << endl;
    }

    for (auto aV7 : iV4_a)
    {
        cout << aV7 << endl;
    }

    for (auto aV8 : strV5_a)
    {
        cout << aV8 << endl;
    }

    //下列定义是否正确
    vector<vector<int>> ivec; //正确
    // vector<string> svec = ivec; //错误
    vector<string> svec(10, "null");  //正确
    vector<string> svec2{10, "null"}; //正确

    //判断下列vector对象含多少元素，值是多少
    vector<int> v1; //0
    for (auto aV8 : v1)
    {
        cout << aV8 << endl;
    }
    vector<int> v2(10); //10    =0
    for (auto aV8 : v2)
    {
        cout << aV8 << endl;
    }
    vector<int> v3(10, 42); //10    =42
    for (auto aV8 : v3)
    {
        cout << aV8 << endl;
    }
    vector<int> v4{10}; // 1    =10
    for (auto aV8 : v4)
    {
        cout << aV8 << endl;
    }
    vector<int> v5{10, 42}; // 2   =10  42
    for (auto aV8 : v5)
    {
        cout << aV8 << endl;
    }
    vector<string> v6{10}; // 10   =空
    for (auto aV8 : v6)
    {
        cout << aV8 << endl;
    }
    vector<string> v7{10, "hi"}; // 10   hi
    for (auto aV8 : v7)
    {
        cout << aV8 << endl;
    }

    cout << "\r\n\r\n\r\n\r\n\r\nDone!\a\r\n\r\n\r\n\r\n\r\n";
    // system("pause");
    // getchar();
    // getchar();
    return 0;
}
#endif

#if 0
//3.11
//string
int main(int argc, char **agrv)
{
    //编译器不报错，但写法不好，const string无法赋值
    const string kstrV1 = "keep out";
    for (auto &arV2 : kstrV1)
    {
        ;
    }

    cout << "\r\n\r\n\r\n\r\n\r\nDone!\a\r\n\r\n\r\n\r\n\r\n";
    // system("pause");
    // getchar();
    // getchar();
    return 0;
}
#endif

#if 0
//3.10
//string
int main(int argc, char **agrv)
{
    //输入一段有标点的字符串，去掉标点输出字符串
    string strInput, strRes;
    while(getline(cin,strInput)){
            strRes += strInput;
            strRes += '\n';
    }
    cout << strRes << endl;

    for(auto aCh:strRes){
        if((!ispunct(aCh))&&(!isspace(aCh))&&(aCh!='\n')){
           cout << aCh; //直接输出即可，不用新建一个空string再存储了
        }
    }

    cout << "\r\n\r\n\r\n\r\n\r\nDone!\a\r\n\r\n\r\n\r\n\r\n";
    // system("pause");
    // getchar();
    // getchar();
    return 0;
}
#endif

#if 0
//3.6
//string
int main(int argc, char **agrv)
{
    string strV1("hello,my lovely cpp world!!!");
    // for (char &arV2 : strV1) // for(char arV2:strV1){
    // {
    //     if (!isspace(arV2))
    //     {
    //         arV2 = 'X';
    //     }
    // }
    // cout << strV1 << endl;

    // for (auto &arV2 : strV1)
    // {
    //     if (!isspace(arV2))
    //     {
    //         arV2 = 'X';
    //     }
    // }
    // cout << strV1 << endl;

    // 用for和while重写
    // for (decltype(strV1.size()) dtV2 = 0; (dtV2 != strV1.size()); ++dtV2)
    // {
    //     if (!isspace(strV1[dtV2]))
    //     {
    //         strV1[dtV2] = 'X';
    //     }
    // }

    decltype(strV1.size()) dtV2 = 0;
    while (dtV2 != strV1.size())
    {
        if (!isspace(strV1[dtV2]))
        {
            strV1[dtV2] = 'X';
        }
        ++dtV2;
    }
    cout << strV1 << endl;

    string strV3;
    strV3[0] = 1;       //错误代码，但编译器不检查

    cout << "\r\n\r\n\r\n\r\n\r\nDone!\a\r\n\r\n\r\n\r\n\r\n";
    // system("pause");
    // getchar();
    // getchar();
    return 0;
}
#endif

#if 0
//3.5
//string
int main(int argc, char **agrv)
{
    //将0-15的十进制数转化为十六进制
    //输入12 0 5 15 8 15
    //得到C05F8F

    const string kstrHexTable("0123456789ABCDEF"); //string不能用constexpr
    cout << "Please enter numbers: " << endl;

    decltype(kstrHexTable.size()) dtInput;
    string strRes;

    while (cin >> dtInput)
    {
        if (dtInput < kstrHexTable.size())  //此处用s.size()比较好，避免magic number，更接近本质
        //!每次下标操作前一定要保证不越界
        {
            strRes += kstrHexTable[dtInput];
        }
    }
    cout << "Your hexdigit: " << strRes << endl;

    cout << "\r\n\r\n\r\n\r\n\r\nDone!\a\r\n\r\n\r\n\r\n\r\n";
    // system("pause");
    // getchar();
    // getchar();
    return 0;
}
#endif

#if 0
//3.5
//string
//读入若干字符串，加空格拼接，并打印
int main(int argc, char **agrv)
{
    //范围for语句
    string strV1("Hello world!!!");
    decltype(strV1.size()) dtCount = 0;
    for (auto aV2 : strV1)
    {
        if (ispunct(aV2))
        {
            ++dtCount;
        }
    }
    cout << dtCount << endl;

    //利用范围for改变序列中的内容，要用引用变量，访问全部内容
    for (auto &arV3 : strV1)
    {
        if (isupper(arV3))
        {
            arV3 = tolower(arV3);
        }
        else
        {
            arV3 = toupper(arV3);
        }
    }
    cout << strV1 << endl;

    //如果只访问部分内容，可以两种方式，一种是下标，[]，接受string::size_type
    //下标必须>=0，小于s.size()，即0-(s.size()-1)，必须检查string是否为空
    //对空字符串用下标操作，后果未定义
    //另外一种是迭代器
    // if (strV1.size() >= 5)
    // {
    //     for (string::size_type i = 0; i < 5; ++i)
    //     {
    //         strV1[i] = tolower(strV1[i]);
    //     }
    //     cout << strV1 << endl;
    // }

    //处理全部字符，直到处理完或遇到空白
    //for的条件中最好用!=，不要用大小等于
    //逻辑与&&，会先计算第一个条件，如果为false，后面不做判断，可以灵活使用
    //c语言规定，当左侧运算为真时，才会检查右侧对象情况
    //比如，此处，先保证下标不越界，再采用下标运算
    for (decltype(strV1.size()) dtIndex = 0; (dtIndex != strV1.size()) && (!isspace(strV1[dtIndex])); ++dtIndex)
    {
        strV1[dtIndex] = tolower(strV1[dtIndex]);
    }
    cout << strV1 << endl;

    cout << "\r\n\r\n\r\n\r\n\r\nDone!\a\r\n\r\n\r\n\r\n\r\n";
    // system("pause");
    // getchar();
    // getchar();
    return 0;
}
#endif

#if 0
//3.5
//string
//读入若干字符串，加空格拼接，并打印
int main(int argc, char **agrv)
{
    string strV1, strV2;
    while(cin>>strV1)
    {
        strV2 = strV2 + strV1 + " ";
    }
    cout << strV2 << endl;


    cout << "\r\n\r\n\r\n\r\n\r\nDone!\a\r\n\r\n\r\n\r\n\r\n";
    // system("pause");
    // getchar();
    // getchar();
    return 0;
}
#endif

#if 0
//3.4
//string
//输入两个字符串，判断是否相等，不等，输出大的
int main(int argc, char **agrv)
{
    string strV1, strV2;
    cin >> strV1 >> strV2;
    if (strV1 > strV2)
    {
        cout << strV1 << endl;
    }
    else
    {
        cout << strV2 << endl;
    }

    cout << "\r\n\r\n\r\n\r\n\r\nDone!\a\r\n\r\n\r\n\r\n\r\n";
    // system("pause");
    // getchar();
    // getchar();
    return 0;
}
#endif

#if 0
//3.3
//string
//operation
int main(int argc, char **agrv)
{
    //string可以执行的操作

    //os<<s
    //in>>s
    //getline(is,s)

    //s.empty()
    //s.size()
    //s[n]

    //s1+s2
    //s1=s2

    //s1==s2
    //s1!=s2
    //s1>=s2 s1>s2
    //s1<=s2 s1<s2

    //string读取时，忽略开头的空白，直到遇到第一个空白为止
    string strV1, strV2;
    cin >> strV1; //分别输入 "   hello wolrd   " "helloworld" "hello  world"
    cout << strV1 << endl;
    cin >> strV1 >> strV2;
    cout << strV1 << " " << strV2 << endl;

    //连续读取若干数据，打印每个单词
    // string strV3;
    // while(cin>>strV3)       //作为条件语句时，在碰到文件末尾或者非法输入时，为false
    // {
    //     cout << strV3 << endl;
    // }

    //读取一行可以使用getline函数，遇到回车符停止，读入回车符，但不存入string
    //返回流，故可以作为判断条件
    string strV4, strV5;
    while (getline(cin, strV4))
    {
        if (!strV4.empty() && (strV4.size() < 80))
        {
            cout << strV4 << endl;
        }
    }

    cout << "\r\n\r\n\r\n\r\n\r\nDone!\a\r\n\r\n\r\n\r\n\r\n";
    // system("pause");
    // getchar();
    // getchar();
    return 0;
}
#endif

#if 0
//3.2
//string
//initialization:direct init,copy init
int main(int argc, char **agrv)
{
    string s1 = "hello"; //copy init
    string s2 = s1;
    string s3(s1);
    string s4("hello"); //direct init
    string s5(10, 'c'); //direct init
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
    cout << s5 << endl;

    cout << "\r\nDone!\a\r\n";
    // system("pause");
    // getchar();
    // getchar();
    return 0;
}
#endif