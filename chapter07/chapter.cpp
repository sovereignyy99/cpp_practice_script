/*
 * @Author: MatthewPerry
 * @Date: 2018-04-04 11:48:29
 * @Last Modified by: MatthewPerry
 * @Last Modified time: 2018-04-05 22:07:51
 */

#include "person.h"
#include "sales_data.h"
#include "screen.h"
#include <cctype>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <vector>

#if 1
// 7.43
int main(int argc, char **argv)
{


    return 0;
}
#endif

#if 0
// 7.41
int main(int argc, char **argv)
{
    sales_data_cl obj0("obj0",1,100);
    sales_data_cl obj1;
    sales_data_cl obj2("obj2");
    sales_data_cl obj3(std::cin);
    print(std::cout, obj0) << std::endl;
    print(std::cout, obj1) << std::endl;
    print(std::cout, obj2) << std::endl;
    print(std::cout, obj3) << std::endl;

    return 0;
}
#endif

#if 0
// 7.37
int main(int argc, char **argv)
{
    // cin作为默认实参
    sales_data_cl obj1;
    print(std::cout, obj1);

    return 0;
}
#endif

#if 0
// 7.36
sales_data_cl obj1(std::cin);
int main(int argc, char **argv)
{
    sales_data_cl obj2;
    sales_data_cl obj3("9-99-999");
    print(std::cout, obj1) << std::endl;
    print(std::cout, obj2) << std::endl;
    print(std::cout, obj3) << std::endl;

    return 0;
}
#endif

#if 0
// 7.36
int main(int argc, char **argv)
{
    sales_data_cl obj1;
    print(std::cout, obj1);

    return 0;
}
#endif

#if 0
// 7.33
int main(int argc, char **argv)
{
    screen_cl obj1(4, 4, '*');
    screen_cl obj2(8, 8, '#');
    window_mgr_cl obj3;

    obj3.AddScreen(obj1);
    obj3.AddScreen(obj2);
    int v1 = obj1.Size();
    std::cout << "obj1 size: " << v1 << std::endl;
    v1 = obj2.Size();
    std::cout << "obj2 size: " << v1 << std::endl;
    obj1.Display(std::cout);
    std::cout << std::endl;
    obj2.Display(std::cout);

    return 0;
}
#endif

#if 0
// 7.31
class Y;

class X
{
    Y *Y_cl;
};

class Y
{
    X X_cl;
};
int main(int argc, char **argv)
{
    // x包含指向y的指针，y包含x对象

    return 0;
}
#endif

#if 0
// 7.27
int main(int argc, char **argv)
{
    screen_cl MyScreen(5, 5, 'X');
    MyScreen.Move(4, 0).Set('#').Display(std::cout);
    std::cout << "\n";
    MyScreen.Display(std::cout);
    std::cout << "\n";

    return 0;
}
#endif

#if 0
// 7.24
int main(int argc, char **argv)
{
    screen_cl Screen1_cl;
    screen_cl Screen2_cl(2,3);
    screen_cl Screen3_cl(2,3,'#');
    const screen_cl Screen4_cl(2,3,'@');


    std::cout << Screen1_cl.Get() << std::endl;
    std::cout << Screen2_cl.Get() << std::endl;
    std::cout << Screen3_cl.Get() << std::endl;

    Screen1_cl.Set('*').Display(std::cout);
    Screen2_cl.Set('^').Display(std::cout);
    Screen3_cl.Display(std::cout);
    Screen4_cl.Display(std::cout);

    return 0;
}
#endif

#if 0
// 7.22
int main(int argc, char **argv)
{
    person_cl Person1_cl;

    std::string s1 = "SZY";
    std::string s2 = "Shandong";

    person_cl Person2_cl(s1, s2);
    person_cl Person3_cl(std::cin);

    print(std::cout, Person1_cl) << std::endl;
    print(std::cout, Person2_cl) << std::endl;
    print(std::cout, Person3_cl) << std::endl;

    sales_data_cl Book1_cl;
    std::string s3 = "a-1-1";
    sales_data_cl Book2_cl(s3);
    sales_data_cl Book3_cl(s3, 10, 5.00);
    sales_data_cl Book4_cl(std::cin);

    print(std::cout, Book1_cl) << std::endl;
    print(std::cout, Book2_cl) << std::endl;
    print(std::cout, Book3_cl) << std::endl;
    print(std::cout, Book4_cl) << std::endl;

    return 0;
}
#endif

#if 0
// 7.15
int main(int argc, char **argv)
{
    person_cl Person1_cl;

    std::string s1 = "SZY";
    std::string s2 = "Shandong";

    person_cl Person2_cl(s1,s2);
    person_cl Person3_cl(std::cin);

    print(std::cout, Person1_cl) << std::endl;
    print(std::cout, Person2_cl) << std::endl;
    print(std::cout, Person3_cl) << std::endl;

    return 0;
}
#endif

#if 0
// 7.13
int main(int argc, char **argv)
{
    sales_data_cl total(std::cin);
    if (!total.isbn().empty())
    {
        std::istream &is = std::cin;
        while (is)
        {
            sales_data_cl trans(is);
            if (total.isbn() == trans.isbn())
            {
                total.combine(trans);
            }
            else
            {
                print(std::cout, total) << std::endl;
                total = trans;
            }
        }
        // print(std::cout, total) << std::endl;
    }
    else
    {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }

    return 0;
}
#endif

#if 0
// 7.12
int main(int argc, char **argv)
{
    sales_data_cl Book1_cl;
    std::string s2 = "a-1-1";
    sales_data_cl Book2_cl(s2);
    sales_data_cl Book3_cl(s2, 10, 5.00);
    sales_data_cl Book4_cl(std::cin);

    print(std::cout, Book1_cl) << std::endl;
    print(std::cout, Book2_cl) << std::endl;
    print(std::cout, Book3_cl) << std::endl;
    print(std::cout, Book4_cl) << std::endl;

    return 0;
}
#endif

#if 0
// 7.11
int main(int argc, char **argv)
{
    sales_data_cl Book1_cl;
    std::string s2 = "a-1-1";
    sales_data_cl Book2_cl(s2);
    sales_data_cl Book3_cl(s2, 10, 5.00);
    sales_data_cl Book4_cl(std::cin);

    print(std::cout, Book1_cl) << std::endl;
    print(std::cout, Book2_cl) << std::endl;
    print(std::cout, Book3_cl) << std::endl;
    print(std::cout, Book4_cl) << std::endl;

    return 0;
}
#endif

#if 0
// 7.9
int main(int argc, char **argv)
{
    person_cl Susan_cl("Susan", "Pudongxinqu Shanghai");
    std::cout << Susan_cl.GetName() << " : " << Susan_cl.GetAddress() << std::endl;
    std::cout << Susan_cl.GetName2() << " : " << Susan_cl.GetAddress() << std::endl;
    std::cout << Susan_cl.GetName3() << " : " << Susan_cl.GetAddress() << std::endl;

    Susan_cl.strName = "Szy";
    Susan_cl.strAddress = "Shandong Tengzhou";
    print(std::cout,Susan_cl) << std::endl;

    person_cl Random_cl;
    read(std::cin, Random_cl);
    std::cout << "Random Person :\n";
    print(std::cout, Random_cl) << std::endl;

    return 0;
}
#endif

#if 0
// 7.5
int main(int argc, char **argv)
{
    // 编写一个person的类，表示人员的姓名和地址
    // 操作：返回姓名、地址
    person_cl Susan_cl("Susan", "Pudongxinqu Shanghai");
    std::cout << Susan_cl.GetName() << " : " << Susan_cl.GetAddress() << std::endl;
    std::cout << Susan_cl.GetName2() << " : " << Susan_cl.GetAddress() << std::endl;
    std::cout << Susan_cl.GetName3() << " : " << Susan_cl.GetAddress() << std::endl;

    return 0;
}
#endif

#if 0
// 7.2
int main(int argc, char **argv)
{
    sales_data_cl total;
    if (read(std::cin, total))
    {
        sales_data_cl trans;
        while (read(std::cin, trans))
        {
            if (total.strBookNo == trans.strBookNo)
            {
                total.combine(trans);
            }
            else
            {
                print(std::cout, total) << std::endl;
                total = trans;
            }
        }
        print(std::cout, total) << std::endl;
    }
    else
    {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    return 0;
}
#endif

#if 0
// 7.1
int main(int argc, char **argv)
{
    sales_data_cl total;
    if (cin >> total.strBookNo >> total.uiUnitSold >> total.dRevenue)
    {
        sales_data_cl trans;
        while (cin >> trans.strBookNo >> trans.uiUnitSold >> trans.dRevenue) {
            if (total.strBookNo == trans.strBookNo) {
                total.uiUnitSold += trans.uiUnitSold;
                total.dRevenue += trans.dRevenue;
            }
            else {
                cout << total.strBookNo << " " << total.uiUnitSold << " " << total.dRevenue << endl;
                total = trans;
            }
        }
        cout << total.strBookNo << " " << total.uiUnitSold << " " << total.dRevenue << endl;
    }
    else
    {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    return 0;
}
#endif