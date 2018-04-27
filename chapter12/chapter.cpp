/*
 * @Author: MatthewPerry
 * @Date: 2018-04-04 11:48:29
 * @Last Modified by: MatthewPerry
 * @Last Modified time: 2018-04-27 16:55:35
 */

#include "Sales_item.h"
#include "my_little_functions.h"
#include "sales_data.h"
#include "string_blob.h"
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
#include <memory>
#include <new>
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
// dynamic array
int main(int argc, char **argv)
{
    std::cout << "\n================================================================\n";
    std::cout << "hello cpp world!\nvery good stuff!\n";
    std::cin.get();

    return 0;
}
#endif

#if 0
// 12.22
int main(int argc, char **argv)
{
    std::cout << "\n================================================================\n";
    std::cout << "hello cpp world!\nvery good stuff!\n";
    std::cin.get();

    return 0;
}
#endif

#if 0
// 12.20
int main(int argc, char **argv)
{
    std::ifstream ifs("K:/workspace/codeblocks/cppprimer5th/practice/chapter12/input/essay.txt");
    StrBlob blob;
    for (std::string str; std::getline(ifs, str); )
        blob.push_back(str);
    for (StrBlobPtr pbeg(blob.begin()), pend(blob.end()); pbeg != pend; pbeg.incr())
        std::cout << pbeg.deref() << std::endl;

    std::cout << "\n================================================================\n";
    std::cout << "hello cpp world!\nvery good stuff!\n";
    std::cin.get();

    return 0;
}
#endif

#if 0
// weak_ptr
int main(int argc, char **argv)
{
    auto sp = std::make_shared<int>(99);
    std::weak_ptr<int> wp(sp);
    wp.reset();
    wp = sp;
    std::cout << "use count: " << wp.use_count() << "\n";
    std::cout << "expired: " << wp.expired() << "\n";
    std::cout << "lock: " << wp.lock() << "\n";
    std::cout << "*lock: " << *(wp.lock()) << "\n";
    wp.reset();
    if (std::shared_ptr<int> np = wp.lock())
    {
        std::cout << "never display this msg.\n";
    }
    else
    {
        std::cout << "weak_ptr -> shared_ptr released.";
    }

    wp = sp;
    if (std::shared_ptr<int> np = wp.lock())
    {
        std::cout << "assigned: " << *np << std::endl;
        ;
    }

    std::cout << "\n================================================================\n";
    std::cout << "hello cpp world!\nvery good stuff!\n";
    std::cin.get();

    return 0;
}
#endif

#if 0
// 12.17
int main(int argc, char **argv)
{
    int ix = 1024, *pi = &ix, *pi2 = new int(2048);
    typedef std::unique_ptr<int> IntP;

    /**
     * @brief  error: invalid conversion from 'int' to
     * 'std::unique_ptr<int>::pointer {aka int*}' [-fpermissive]
     */
    // IntP p0(ix);

    /**
     * @brief The code below can compile, but will cause error at run time.
     *        The reason is that when the unique_ptr p1 is out of scope, delete
     * will be called
     *        to free th object. But the object is not allocate using new.Thus,
     * an error
     *        would be thrown by operating system.
     *  @badcode
     */
    // IntP p1(pi);

    /**
     * @brief This code can compile, but cause a dangling pointer at run time.
     *        The reason is that the unique_ptr will free the object the raw
     * pointer
     *        is pointing to.
     * @badcode
     */
    //{IntP p2(pi2);}

    /**
     * @brief   When the unique_ptr goes out of scope, it will call delete to
     * free an
     *          obeject not allocated using new.
     * @badcode
     */
    // IntP p3(&ix);

    /**
     * @brief   Recommended.
     */
    // IntP p4(new int(2048));

    /**
     * @brief   error:   double free or corruption at run time
     *          two unique_ptr are pointing to the same object. Thus, when both
     * are out of
     *          scope, Operating system will throw double free or corruption.
     * @badcode
     */
    // IntP p2(new int(555));
    // IntP p5(p2.get());

    std::cout << "\n================================================================\n";
    std::cout << "hello cpp world!\nvery good stuff!\n";
    std::cin.get();

    return 0;
}
#endif

#if 0
// 12.15
// 智能指针管理的不是内存类的资源，结合删除器
// 网络通信，既用于C又用于C++

struct connection
{
    std::string ip;
    int port;
    connection(std::string ip_, int port_) : ip(ip_), port(port_) {}
};
struct destination
{
    std::string ip;
    int port;
    destination(std::string ip_, int port_) : ip(ip_), port(port_) {}
};

connection connect(destination *pDest)
{
    std::shared_ptr<connection> pConn(new connection(pDest->ip, pDest->port));
    std::cout << "creating connection(" << pConn.use_count() << ")" << std::endl;
    return *pConn;
}

void disconnect(connection pConn)
{
    std::cout << "connection close(" << pConn.ip << ":" << pConn.port << ")" << std::endl;
}

void f(destination &d)
{
    connection conn = connect(&d);
    std::shared_ptr<connection> p(&conn, [](connection *p){disconnect(*p);});
    std::cout << "connecting now(" << p.use_count() << ")" << std::endl;
}

int main(int argc, char **argv)
{
    destination dest("202.118.176.67", 3316);
    f(dest);

    std::cout
        << "\n================================================================\n";
    std::cout << "hello cpp world!\nvery good stuff!\n";
    std::cin.get();

    return 0;
}
#endif

#if 0
// 12.14
// 智能指针管理的不是内存类的资源，结合删除器
// 网络通信，既用于C又用于C++

struct connection
{
    std::string ip;
    int port;
    connection(std::string ip_, int port_) : ip(ip_), port(port_) {}
};
struct destination
{
    std::string ip;
    int port;
    destination(std::string ip_, int port_) : ip(ip_), port(port_) {}
};

connection connect(destination *pDest)
{
    std::shared_ptr<connection> pConn(new connection(pDest->ip, pDest->port));
    std::cout << "creating connection(" << pConn.use_count() << ")" << std::endl;
    return *pConn;
}

void disconnect(connection pConn)
{
    std::cout << "connection close(" << pConn.ip << ":" << pConn.port << ")" << std::endl;
}

void end_connection(connection *pConn)
{
    disconnect(*pConn);
}

void f(destination &d)
{
    connection conn = connect(&d);
    std::shared_ptr<connection> p(&conn, end_connection);
    std::cout << "connecting now(" << p.use_count() << ")" << std::endl;
}

int main(int argc, char **argv)
{
    destination dest("202.118.176.67", 3316);
    f(dest);

    std::cout
        << "\n================================================================\n";
    std::cout << "hello cpp world!\nvery good stuff!\n";
    std::cin.get();

    return 0;
}
#endif

#if 0
// 12.14
// 智能指针管理的不是内存类的资源，结合删除器
// 网络通信，既用于C又用于C++
struct destination
{
    int i = 10;
};

struct connection
{
    int i = 100;
};

connection connect(destination *d)
{
    connection c;
    return c;
}

void disconnect(connection)
{
    return;
}

void end_connection(connection *cp)
{
    disconnect(*cp);
}

void func(destination &d)
{
    connection c = connect(&d);
    // 利用智能指针+deleter管理资源
    std::shared_ptr<connection> sp(&c, end_connection);
    // 使用连接
    // 退出f或异常时，shared_ptr 管理资源，防止资源泄露
}

int main(int argc, char **argv)
{
    destination ds;
    func(ds);

    std::cout
        << "\n================================================================\n";
    std::cout << "hello cpp world!\nvery good stuff!\n";
    std::cin.get();

    return 0;
}
#endif

#if 0
// 12.12
void process(std::shared_ptr<int> p)
{
    std::cout << "inside the process function:" << p.use_count() << "\n";
    return;
}

int main(int argc, char **argv)
{
    auto p = new int();
    auto sp = std::make_shared<int>();

    process(sp);                      // 合法
    // process(new int());               // 非法
    // process(p);                       // 非法
    process(std::shared_ptr<int>(p)); // 合法，容易bug
    std::cout << sp.use_count() << "\n";

    std::cout << "\n================================================================\n";
    std::cout << "hello cpp world!\nvery good stuff!\n";
    std::cin.get();

    return 0;
}
#endif

#if 0
// 12.11
void process(std::shared_ptr<int> p)
{
    std::cout << "inside the process function:" << p.use_count() << "\n";
    return;
}

int main(int argc, char **argv)
{
    std::shared_ptr<int> p1(new int(41));
    process(std::shared_ptr<int>(p1.get()));        // 非法
    std::cout << p1.use_count() << "\n";
    auto q = p1;
    std::cout << p1.use_count() << "\n";
    std::cout << "the int p1 now points to is:" << *p1 << "\n";

    std::cout << "\n================================================================\n";
    std::cout << "hello cpp world!\nvery good stuff!\n";
    std::cin.get();

    return 0;
}
#endif

#if 0
// 12.10
void process(std::shared_ptr<int> p)
{
    std::cout << "inside the process function:" << p.use_count() << "\n";
    return;
}

int main(int argc, char **argv)
{
    std::shared_ptr<int> p1(new int(41));
    process(std::shared_ptr<int>(p1));
    std::cout << p1.use_count() << "\n";
    auto q = p1;
    std::cout << p1.use_count() << "\n";
    std::cout << "the int p1 now points to is:" << *p1 << "\n";

    std::cout << "\n================================================================\n";
    std::cout << "hello cpp world!\nvery good stuff!\n";
    std::cin.get();

    return 0;
}
#endif

#if 0
// 12.10
std::shared_ptr<int> clone(int p)
{
    return std::shared_ptr<int>(new int(p));
}

int main(int argc, char **argv)
{
    std::shared_ptr<int> p1(new int(41));
    std::cout << p1 << "\n";
    std::cout << *p1 << "\n";

    auto p2 = clone(42);
    std::cout << p2 << "\n";
    std::cout << *p2 << "\n";

    std::cout << "\n================================================================\n";
    std::cout << "hello cpp world!\nvery good stuff!\n";
    std::cin.get();

    return 0;
}
#endif

#if 0
// 12.7
void MyRead(std::istream &is, std::shared_ptr<std::vector<int>> p);
void MyPrint(std::ostream &os, const std::shared_ptr<std::vector<int>> p);
int main(int argc, char **argv)
{
    auto sp = std::make_shared<std::vector<int>>(10, 10);
    MyPrint(std::cout, sp);
    MyRead(std::cin, sp);
    MyPrint(std::cout, sp);

    std::cout << "\n================================================================\n";
    std::cout << "hello cpp world!\nvery good stuff!\n";
    std::cin.get();

    return 0;
}
void MyRead(std::istream &is, std::shared_ptr<std::vector<int>> p)
{
    for (int s; is >> s && s != 'q';)
    {
        p->push_back(s);
    }
}

void MyPrint(std::ostream &os, const std::shared_ptr<std::vector<int>> p)
{
    for (const auto &x : *p)
    {
        std::cout << x << " ";
    }
    std::cout << "\n";
}
#endif

#if 0
// 12.6
void MyRead(std::istream &is, std::vector<int> *p);
void MyPrint(std::ostream &os, std::vector<int> *p);
int main(int argc, char **argv)
{
    std::vector<int> *p = new std::vector<int>{0, 1, 2, 3, 4, 5};
    MyPrint(std::cout, p);
    MyRead(std::cin, p);
    MyPrint(std::cout, p);
    delete p;
    p = nullptr;
    // MyPrint(std::cout, p);  // error

    std::cout << "\n================================================================\n";
    std::cout << "hello cpp world!\nvery good stuff!\n";
    std::cin.get();

    return 0;
}
void MyRead(std::istream &is, std::vector<int> *p)
{
    for (int s; is >> s && s != 'q';)
    {
        p->push_back(s);
    }
}

void MyPrint(std::ostream &os, std::vector<int> *p)
{
    for (const auto &x : *p)
    {
        std::cout << x << " ";
    }
    std::cout << "\n";
}
#endif

#if 0
// new and delete
int main(int argc, char **argv)
{
    int *p1 = new int;       // 默认初始化
    int *p2 = new int(1024); // 直接初始化
    int *p3 = new int();     // 值初始化
    int i = 0;
    auto p4 = new auto(i); // 自动推断
    const int *p5 = new const int(512);
    int *p6 = new (std::nothrow) int;
    auto p7(p6);
    delete p6;
    p6 = nullptr;
    p7 = nullptr;

    std::cout << "\n================================================================\n";
    std::cout << "hello cpp world!\nvery good stuff!\n";
    std::cin.get();

    return 0;
}
#endif

#if 0
// 12.2
int main(int argc, char **argv)
{
    StrBlob v2 = {"hello", "world", "cpp"};
    const StrBlob v1 = {"hello", "world", "python"};

    std::cout << v1.front() << ":" << v1.back() << "\n";
    v2.back() = "c++";
    v2.front() = "Bjarne Stroustrup";
    std::cout << v2.front() << ":" << v2.back() << "\n";

    std::cout << "\n================================================================\n";
    std::cout << "hello cpp world!\nvery good stuff!\n";
    std::cin.get();

    return 0;
}
#endif

#if 0
// 12.1
int main(int argc, char **argv)
{
    StrBlob b1;
    {
        StrBlob b2 = {"a", "an", "the"};
        b1 = b2;
        b2.push_back("about");
        std::cout << "b2.size: " << b2.size() << "\n";
    }

    // b1和b2各包含多少元素
    std::cout << "b1.size: " << b1.size() << "\n";

    std::cout << "\n================================================================\n";
    std::cout << "hello cpp world!\nvery good stuff!\n";
    std::cin.get();

    return 0;
}
#endif

#if 0
// dynamic memory
int main(int argc, char **argv)
{
    std::shared_ptr<std::string> sp1 = std::make_shared<std::string>();
    if (sp1 && sp1->empty())
    {
        *sp1 = "hello,world.\n";
    }

    std::cout << "\n================================================================\n";
    std::cout << "hello cpp world!\nvery good stuff!\n";
    std::cin.get();

    return 0;
}
#endif

#if 0
// dynamic memory
int main(int argc, char **argv)
{
    int v1 = 0, *v3 = nullptr;
    {
        int v2 = 10;
        v1 = v2;
        v3 = &v2;
    }
    int v4 = 100;
    int v5 = 100;
    int v6 = 100;
    std::cout << v1 << "\n";
    std::cout << *v3 << "\n";


    std::cout << "\n================================================================\n";
    std::cout << "hello,cpp world.\n";
    std::cin.get();

    return 0;
}
#endif

#if 0
// dynamic memory
int main(int argc, char **argv)
{
    int v1 = 0, *v3 = nullptr;
    {
        int v2 = 10;
        v1 = v2;
        v3 = &v2;
    }
    int v4 = 100;
    std::cout << v1 << "\n";
    std::cout << *v3 << "\n";


    std::cout << "\n================================================================\n";
    std::cout << "hello,cpp world.\n";
    std::cin.get();

    return 0;
}
#endif

#if 0
// dynamic memory
int main(int argc, char **argv)
{
    std::vector<int> v1;
    {
        std::vector<int> v2{1, 2, 3, 4, 5};
        v1 = v2;
    }
    print(std::cout, v1, " ") << std::endl;

    std::cout << "\n================================================================\n";
    std::cout << "hello,cpp world.\n";
    std::cin.get();

    return 0;
}
#endif

#if 0
// dynamic memory
int main(int argc, char **argv)
{
    std::cout << "define a empty shared_pionter: \n";
    std::shared_ptr<int> sp;

    std::cout << "sp: " << sp << std::endl;
    // std::cout << "*sp: " << *sp << std::endl;
    std::cout << "&sp: " << &sp << std::endl;
    std::cout << "sp.unique: " << sp.unique() << std::endl;
    std::cout << "sp.use_count: " << sp.use_count() << std::endl;
    std::cout << "================================================================\n";

    std::cout << "define shared_pointer by \"make_shared function\": \n";
    std::shared_ptr<int> v1 = std::make_shared<int>(88);
    auto v2 = std::make_shared<std::string>(10, '9');
    std::cout << "shared_pointer: \n";
    std::cout << "v1: " << v1 << "\n";
    std::cout << "*v1 " << *v1 << "\n";
    std::cout << "&v1: " << &v1 << "\n";
    std::cout << "v1.unique: " << v1.unique() << std::endl;
    std::cout << "v1.use_count: " << v1.use_count() << std::endl;
    std::cout << "================================================================\n";
    std::cout << "v2: " << v2 << "\n";
    std::cout << "*v2 " << *v2 << "\n";
    std::cout << "&v2: " << &v2 << "\n";
    std::cout << "v2.unique: " << v2.unique() << std::endl;
    std::cout << "v2.use_count: " << v2.use_count() << std::endl;
    std::cout << "================================================================\n";
    std::cout << "copy v2 to v7:\n";
    auto v7(v2);
    std::cout << "v2: " << v2 << "\n";
    std::cout << "*v2 " << *v2 << "\n";
    std::cout << "&v2: " << &v2 << "\n";
    std::cout << "v2.unique: " << v2.unique() << std::endl;
    std::cout << "v2.use_count: " << v2.use_count() << std::endl;
    std::cout << "================================================================\n";
    std::cout << "v7: " << v7 << "\n";
    std::cout << "*v7 " << *v7 << "\n";
    std::cout << "&v7: " << &v7 << "\n";
    std::cout << "v7.unique: " << v7.unique() << std::endl;
    std::cout << "v7.use_count: " << v7.use_count() << std::endl;
    std::cout << "================================================================\n";

    std::cout << "define regular pointer: \n";
    int v3 = 88, *v4 = &v3, v5 = 99, *v6 = &v5;
    std::cout << "v4: " << v4 << "\n";
    std::cout << "*v4: " << *v4 << "\n";
    std::cout << "&v4: " << &v4 << "\n";
    std::cout << "v6: " << v6 << "\n";
    std::cout << "*v6: " << *v6 << "\n";
    std::cout << "&v6: " << &v6 << "\n";
    std::cout << "================================================================\n";

    return 0;
}
#endif

#if 0
// dynamic memory
int main(int argc, char **argv)
{
    std::cout << "define a empty shared_pionter: \n";
    std::shared_ptr<int> sp;

    std::cout << "sp.unique: " << sp.unique() << std::endl;
    std::cout << "sp: " << sp << std::endl;
    // std::cout << "*sp: " << *sp << std::endl;
    std::cout << "sp.use_count: " << sp.use_count() << std::endl;
    std::cout << "================================================================\n";

    std::cout << "define shared_pointer by \"make_shared function\": \n";
    std::shared_ptr<int> v1 = std::make_shared<int>(88);
    auto v2 = std::make_shared<std::string>(10, '9');
    std::cout << "shared_pointer: \n";
    std::cout << "v1: " << v1 << "\n";
    std::cout << "*v1 " << *v1 << "\n";
    std::cout << "v1.unique: " << v1.unique() << std::endl;
    std::cout << "v1.use_count: " << v1.use_count() << std::endl;
    std::cout << "================================================================\n";
    std::cout << "v2: " << v2 << "\n";
    std::cout << "*v2 " << *v2 << "\n";
    std::cout << "v2.unique: " << v2.unique() << std::endl;
    std::cout << "v2.use_count: " << v2.use_count() << std::endl;
    std::cout << "================================================================\n";
    std::cout << "copy v2 to v7:\n";
    auto v7(v2);
    std::cout << "v2: " << v2 << "\n";
    std::cout << "*v2 " << *v2 << "\n";
    std::cout << "v2.unique: " << v2.unique() << std::endl;
    std::cout << "v2.use_count: " << v2.use_count() << std::endl;
    std::cout << "================================================================\n";
    std::cout << "v7: " << v7 << "\n";
    std::cout << "*v7 " << *v7 << "\n";
    std::cout << "v7.unique: " << v7.unique() << std::endl;
    std::cout << "v7.use_count: " << v7.use_count() << std::endl;
    std::cout << "================================================================\n";

    std::cout << "define regular pointer: \n";
    int v3 = 88, *v4 = &v3, v5 = 99, *v6 = &v5;
    std::cout << "v4: " << v4 << "\n";
    std::cout << "*v4: " << *v4 << "\n";
    std::cout << "v6: " << v6 << "\n";
    std::cout << "*v6: " << *v6 << "\n";
    std::cout << "================================================================\n";

    return 0;
}
#endif