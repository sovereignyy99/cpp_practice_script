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
//4.34
//! 没搞透
//todo 花时间比较几种转换，画图
// cast: static_cast/dynamic_cast/const_cast/reinterpret_cast
int main(int argc, char **agrv)
{
    int i = 3000;
    double j = 3.14;

    // i *= static_cast<int>(j);
    i *=j;
    cout << i << endl;

    return 0;
}
#endif

#if 0
//4.34
// cast: static_cast/dynamic_cast/const_cast/reinterpret_cast
int main(int argc, char **agrv)
{
    cout << "hello,world.";
    cout << "test git add and commit";
    cout << "git push --set-upstream cpp_practice_script master";

    return 0;
}
#endif

#if 0
//4.33
int main(int argc, char **agrv)
{
    int V1 = 1;
    int x = 300, y = 10;
    int z = 0;

    /*
    ++,-- 优先级> ? : > = > ,
    z = ((V1 ? ++x, ++y : --x), (--y));
    */
    // z = (V1 ? ++x, ++y : --x, --y); // 301 10 10

    /*
    ++,-- 优先级> ? : > = > ,
    (z = (V1 ? ++x, ++y : --x)), (--y);
    */
    z = V1 ? ++x, ++y : --x, --y; // 301 10 11

    cout << x << endl;
    cout << y << endl;
    cout << z << endl;

    return 0;
}
#endif

#if 0
//4.29
int main(int argc, char **agrv)
{
    // 预测计算结果，并验证
    int x[10];
    int *p = x;
    cout << sizeof(x) / sizeof(*x) << endl; //10
    cout << sizeof(int) << endl;            //4
    cout << sizeof(int *) << endl;          //8
    cout << sizeof(p) / sizeof(*p) << endl; //2

    return 0;
}
#endif

#if 0
//4.28
int main(int argc, char **agrv)
{
    cout << "bool\t\tis " << sizeof(bool) << "bytes." << endl;
    cout << "char\t\tis " << sizeof(char) << "bytes." << endl;
    cout << "wchar_t\t\tis " << sizeof(wchar_t) << "bytes." << endl;
    cout << "char16_t\tis " << sizeof(char16_t) << "bytes." << endl;
    cout << "char32_t\tis " << sizeof(char32_t) << "bytes." << endl;
    cout << "short\t\tis " << sizeof(short) << "bytes." << endl;
    cout << "int\t\tis " << sizeof(int) << "bytes." << endl;
    cout << "long\t\tis " << sizeof(long) << "bytes." << endl;
    cout << "long long\tis " << sizeof(long long) << "bytes." << endl;
    cout << "float\t\tis " << sizeof(float) << "bytes." << endl;
    cout << "double\t\tis " << sizeof(double) << "bytes." << endl;
    cout << "long double\tis " << sizeof(long double) << "bytes." << endl;
    cout << endl;

    return 0;
}
#endif

#if 0
//4.25
int main(int argc, char **agrv)
{
    // 'q'<<6

    cout << ('q' << 6) << endl;
    uint8_t ucV1 = ('q' << 6);
    uint16_t ucV2 = 6ul;
    cout << ucV1 << endl;
    cout << ucV2 << endl;

    return 0;
}
#endif

#if 0
//4.22
int main(int argc, char **agrv)
{
    // 输入分数，显示分数段
    // >90 highpass 76-89 pass 60-75 low pass <60 fail

    cout << "Enter your score: \n";
    unsigned int uiScore = 0;
    cin >> uiScore;

    string strGrade;

    if (uiScore > 100)
    {
        strGrade = "are you kidding me ?\n";
    }
    else if (uiScore >= 90)
    {
        strGrade = "high pass";
    }
    else if ((uiScore >= 75) && (uiScore < 90))
    {
        strGrade = "pass";
    }
    else if ((uiScore >= 60) && (uiScore < 75))
    {
        strGrade = "low pass";
    }
    else
    {
        strGrade = "fail";
    }
    cout << "Your grade: " << strGrade << endl;

    return 0;
}
#endif

#if 0
//4.22
int main(int argc, char **agrv)
{
    // 输入分数，显示分数段
    // >90 highpass 76-89 pass 60-75 low pass <60 fail

    cout << "Enter your score: \n";
    unsigned int uiScore = 0;
    cin >> uiScore;

    string strGrade;
    strGrade = uiScore >= 90 ? "high pass" : ((uiScore >= 75) && (uiScore < 90) ? "pass" : ((uiScore >= 60) && (uiScore < 75) ? "low pass" : "fail"));
    cout << "Your grade: " << strGrade << endl;

    return 0;
}
#endif

#if 0
//4.21
int main(int argc, char **agrv)
{
    //使用条件运算符直到vector<int>里面的奇数，并翻倍
    std::vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto &i : ivec)
        i = (i % 2) ? (i * 2) : i;

    //Check
    for (auto i : ivec)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
#endif

#if 0
//4.21
int main(int argc, char **agrv)
{
    //使用条件运算符直到vector<int>里面的奇数，并翻倍
    vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto &arv : ivec)
    {
        arv % 2 ? (cout << arv << " is odd, double it ==> " << arv * 2 << endl) : (cout << arv << " is not odd, let it be ==> " << arv << endl);
    }

    return 0;
}
#endif

#if 0
//4.13
int main(int argc, char **agrv)
{
    //赋值运算符
    int i;
    double d;
    i = d = 3.15;
    d = i = 3.15;
    cout << i << " " << d << endl;

    //运算对象可以按任意顺序求值
    vector<int> ivec(10, 11);
    auto beg = ivec.begin();
    while (beg != ivec.end() && !isspace(*beg))
    {
        *beg = toupper(*beg++);     //非法的，将产生未定义的行为
    }

    return 0;
}
#endif

#if 0
//4.10

int GetValue(void);

int main(int argc, char **agrv)
{
    int i = 0;
    while((i=GetValue())!=42)
    {
        cout << i << endl;
    }
    cout << "Game over.\n";

    return 0;
}

int GetValue(void)
{
    int i;
    cin >> i;
    return i;
}
#endif

#if 0
//4.10
int main(int argc, char **agrv)
{
    char *s1 = "Hello, world!";
    while (s1 && *s1)
    {
        cout << *s1++;
    }

    //利用while循环，读取整数，直到42结束
    cout << "\nPleas enter integer: \n";
    int i1 = 0;
    while(cin>>i1 && i1!=42)
    {
        cout << i1 << endl;
    }
    cout << "Game over." << endl;

    return 0;
}
#endif