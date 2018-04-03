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
#include <stdexcept>
#include <string>
#include <vector>

// using namespace std;
using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::iterator;
using std::pair;
using std::runtime_error;
using std::string;
using std::vector;

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

// using namespace std;
using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::initializer_list;
using std::iterator;
using std::pair;
using std::runtime_error;
using std::string;
using std::vector;

#if 1
// 6.56
inline int f(const int, const int);
typedef decltype(f) fp; //fp is just a function type not a function pointer

inline int NumAdd(const int n1, const int n2) { return n1 + n2; }
inline int NumSub(const int n1, const int n2) { return n1 - n2; }
inline int NumMul(const int n1, const int n2) { return n1 * n2; }
inline int NumDiv(const int n1, const int n2) { return n1 / n2; }

vector<fp *> v{NumAdd, NumSub, NumMul, NumDiv};

int main(int argc, char **argv)
{
	for (vector<fp *>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << (*it)(2, 2) // here shows how to use it!
			 << std::endl;
	}

	cout << "\nawesome!\n";
	return 0;
}
#endif

#if 0
// 6.56
int MyAdd(int a, int b)
{
	return a + b;
}
int MyDec(int a, int b)
{
	return a - b;
}
int MyMul(int a, int b)
{
	return a * b;
}
int MyDiv(int a, int b)
{
	return (b != 0 ? a / b : 0);
}
using fp = int (*)(int, int);
int main(int argc, char **argv)
{
	vector<fp> fpvec;
	fpvec.push_back(MyAdd);
	fpvec.push_back(MyDec);
	fpvec.push_back(MyMul);
	fpvec.push_back(MyDiv);

	int a = 100, b = 10;

	for (auto fp1 : fpvec)
	{
		cout << fp1(a, b) << endl;
	}

	cout << "very good stuff.";
	return 0;
}
#endif

#if 0
// 6.54
int Foo(int, int);
using fp = int (*)(int, int);
vector<fp> fpvec;
int main(int argc, char **argv)
{

	cout << "very good stuff.";
	return 0;
}
#endif

#if 0
// 6.51
void f()
{
    cout << "f()" << endl;
}

void f(int)
{
    cout << "f(int)" << endl;
}

void f(int, int)
{
    cout << "f(int, int)" << endl;
}

void f(double, double)
{
    cout << "f(double, double)" << endl;
}

int main(int argc, char **argv)
{
	// f(2.56, 42); // error: 'f' is ambiguous.
    f(42);
    f(42, 0);
    f(2.56, 3.14);

	cout << "very good stuff.";
	return 0;
}
#endif

#if 0
// 6.47
// assert and NDEBUG
#define NDEBUG

void printVec(vector<int> &vec)
{
#ifdef NDEBUG
	cout << "vector size: " << vec.size() << endl;
#endif
	if (!vec.empty())
	{
		auto tmp = vec.back();
		vec.pop_back();
		printVec(vec);
		cout << tmp << " ";
	}
}
int main(int argc, char **argv)
{
	vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
	printVec(vec);
	cout << endl;

	cout << "very good stuff.";
	return 0;
}
#endif

#if 0
// 6.42
// 默认实参
string make_plural(size_t ctr, const string &word, const string &ending = "s")
{
	return (ctr > 1) ? word + ending : word;
}
int main(int argc, char **argv)
{
	cout << "singual: " << make_plural(1, "success") << " "
		 << make_plural(1, "failure") << endl;
	cout << "plural : " << make_plural(2, "success") << " "
		 << make_plural(2, "failure") << endl;

	cout << "very good stuff.";
	return 0;
}
#endif

#if 0
// 6.41
// 默认实参
char *init(int ht, int wd = 86, char bckgrnd = ' ')
{
	cout << "ht : " << ht << endl;
	cout << "wd : " << wd << endl;
	cout << "bckgrnd : " << bckgrnd << endl;
	return 0;
}
int main(int argc, char **argv)
{
	// init();	// 非法
	// init(24, 10);
	init(14, '*');	//合法，但与意图不符

	cout << "very good stuff.";
	return 0;
}
#endif

#if 0
// 6.34
// 返回数组指针
string (*Foo1(void))[10];
using sarrT = string[10];
sarrT *Foo2(void);
typedef  string sarrT2[10];
sarrT2 *Foo3(void);
string arr[10];
decltype(arr) *Foo4(void);
auto Foo5(void) -> string(*)[10];
// 返回数组引用
string (&Foo6(void))[10];
using arrT3 = string [10];
arrT3& Foo7(void);
typedef string arrT4[10];
arrT4 &Foo8(void);
decltype(arr) &Foo9(void);
auto Foo10(void) -> string (&)[10];

int main(int argc, char **argv)
{
	// 编写函数声明，返回数组引用，数组含10个string

	cout << "very good stuff.";
	return 0;
}
#endif

#if 0
// 6.33
//! recursive
using Iter = vector<int>::iterator;
void print(Iter beg, Iter end)
{
	if (beg != end)
	{
		cout << *beg << " ";
		print(std::next(beg), end);
	}
}
int main(int argc, char **argv)
{
	// 利用递归函数输出vector中的内容
	vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
	print(vec.begin(), vec.end());

	cout << "very good stuff.";
	return 0;
}
#endif

#if 0
// 6.32
int &get(int *arr, int idx){
	return arr[idx];
}
int main(int argc, char **argv)
{
	int ia[10];
	for (int i = 0; i != 10;++i)
	{
		get(ia, i) = i;
	}
	for(auto i:ia)
	{
		cout << i << endl;
	}

	cout << "very good stuff.";
	return 0;
}
#endif

#if 0
// 6.28
// 可变形参列表
// initializer_list
// ...
void MySum(initializer_list<int> i1)
{
	int sum = 0;
	for (auto beg = i1.begin(); beg != i1.end(); ++beg)
	{
		sum += *beg;
	}
	cout << sum << endl;
}
void MySum(initializer_list<string> i1)
{
	string sum;
	for (auto beg = i1.begin(); beg != i1.end(); ++beg)
	{
		sum += *beg;
		sum += ' ';
	}
	cout << sum << endl;
}
void MySum(int ans, initializer_list<string> i1)
{
	string sum;
	for (auto beg = i1.begin(); beg != i1.end(); ++beg)
	{
		sum += *beg;
		sum += ' ';
	}
	cout << "i have " << ans << "kg.." << endl;
	cout << sum << endl;
}
int main(int argc, char **argv)
{
	MySum({0, 1, 2, 3, 4, 5});
	string s1("very good stuff.");
	MySum({"hello", "my", "cpp", "world", s1});
	MySum(70, {"hello", "my", "cpp", "world", s1});

	cout << "very good stuff.";

	return 0;
}
#endif

#if 0
// 6.27
// 可变形参列表
// initializer_list
// ...
void MySum(initializer_list<int> i1)
{
	int sum = 0;
	for (auto beg = i1.begin(); beg != i1.end(); ++beg)
	{
		sum += *beg;
	}
	cout << sum << endl;
}
void MySum(initializer_list<string> i1)
{
	string sum;
	for (auto beg = i1.begin(); beg != i1.end(); ++beg)
	{
		sum += *beg;
		sum += ' ';
	}
	cout << sum << endl;
}
int main(int argc, char **argv)
{
	MySum({0, 1, 2, 3, 4, 5});
	string s1("very good stuff.");
	MySum({"hello", "my", "cpp", "world", s1});

	cout << "very good stuff.";

	return 0;
}
#endif

#if 0
// 6.26
int main(int argc, char **argv)
{
	// main函数接受两个实参，连成一个string并打印
	if (argc > 2)
	{
		string s1;
		for (auto i = 0; i != argc; ++i)
		{
			s1 += argv[i];
			s1 += ' ';
		}
		cout << s1 << endl;
	}
	else
	{
		cout << "error" << endl;
	}

	return 0;
}
#endif

#if 0
// 6.25
int main(int argc, char **argv)
{
	// main函数接受两个实参，连成一个string并打印
	if (argc > 2)
	{
		string s1;
		for (auto i = 0; i != argc; ++i)
		{
			s1 += argv[i];
			s1 += ' ';
		}
		cout << s1 << endl;
	}
	else
	{
		cout << "error" << endl;
	}

	return 0;
}
#endif

#if 0
// 6.23

void print(const int *pi)
{
    if(pi)
        cout << *pi << endl;
}

void print(const char *p)
{
    if (p)
        while (*p)
            cout << *p++;
    cout << endl;
}

void print(const int *beg, const int *end)
{
    while (beg != end)
        cout << *beg++ << endl;
}

void print(const int ia[], size_t size)
{
    for (size_t i = 0; i != size; ++i) {
        cout << ia[i] << endl;
    }
}

void print(int (&arr)[2])
{
    for (auto i : arr)
        cout << i << endl;
}

int main()
{
    int i = 0, j[2] = {0, 1};
    char ch[5] = "pezy";

    print(ch);
    print(begin(j), end(j));
    print(&i);
    print(j, end(j)-begin(j));
    print(j);

    return 0;
}
#endif

#if 0
// 6.22
void SwapPointer1(int *&r1, int *&r2);
void SwapPointer2(int **r1, int **r2);

int main(int argc, char **agrv)
{
	// 编写函数，交换两个整型指针
	int i = 100, j = 10, *ip = &i, *jp = &j;
	cout << "&i: " << ip << endl;
	cout << "&j: " << jp << endl;

	SwapPointer1(ip, jp);
	cout << "&i: " << ip << endl;
	cout << "&j: " << jp << endl;
	SwapPointer2(&ip, &jp);
	cout << "&i: " << ip << endl;
	cout << "&j: " << jp << endl;

	cout << "hello,world.";
	return 0;
}

void SwapPointer1(int *&r1, int *&r2)
{
	int *temp = nullptr;
	temp = r1;
	r1 = r2;
	r2 = temp;
}

void SwapPointer2(int **r1, int **r2)
{
	int *temp = nullptr;
	temp = *r1;
	*r1 = *r2;
	*r2 = temp;
}
#endif

#if 0
// 6.18
class matrix_st_tag
{
	bool flag;
};
typedef matrix_st_tag matrix;
bool Compare(matrix &m1, matrix &m2);
vector<int>::iterator change_value(int, vector<int>::iterator);

int main(int argc, char **agrv)
{
	cout << "hello,world.";
	return 0;
}
#endif

#if 0
// 6.17
bool HaveCapitalCh(const string &s1);
void ChangeToLower(string &s1);

int main(int argc, char **agrv)
{
	// 函数1：判断string对象是否有大写字母
	// 函数2：将string对象全部改为小写
	cout << "enter a string: \n";
	string s1;
	cin >> s1;
	if (HaveCapitalCh(s1))
	{
		cout << "this string has capital letters.\n";
		ChangeToLower(s1);
	}
	cout << s1 << endl;

	return 0;
}

bool HaveCapitalCh(const string &s1)
{
	bool flag;
	for (auto ch : s1)
	{
		flag = isupper(ch) ? true : false;
		if (flag)
		{
			break;
		}
	}
	return flag;
}

void ChangeToLower(string &s1)
{
	for (auto &ch : s1)
	{
		if (isupper(ch))
		{
			ch = tolower(ch);
		}
	}
}
#endif

#if 0
// 6.12
void MySwap(int &i, int &j);

int main(int argc, char **agrv)
{
	int i = 100, j = 10;
	cout << i << endl;
	cout << j << endl;
	MySwap(i, j);
	cout << i << endl;
	cout << j << endl;

	return 0;
}

void MySwap(int &i, int &j)
{
	int temp = i;
	i = j;
	j = temp;
}
#endif

#if 0
// 6.11
void MyReset(int &i);

int main(int argc, char **agrv)
{
	int i = 100;
	cout << i << endl;
	MyReset(i);
	cout << i << endl;

	return 0;
}

void MyReset(int &i)
{
	i = 0;
}
#endif

#if 0
// 6.10
void MySwap(int *f_iN1, int *f_iN2);

int main(int argc, char **agrv)
{
	// 利用指针形参交换两个整数
	int i = 10, j = 100;
	MySwap(&i, &j);
	cout << "i = " << i << endl;
	cout << "j = " << j << endl;

	return 0;
}

void MySwap(int *f_iN1, int *f_iN2)
{
	int temp = 0;
	temp = *f_iN1;
	*f_iN1 = *f_iN2;
	*f_iN2 = temp;
}
#endif

#if 0
// 6.7
uint16_t FunctionCalled(void);

int main(int argc, char **agrv)
{
	// 第一次调用时返回0 每次调用加1
	int j = 0;
	for (int i = 0; i <= 10; ++i)
	{
		j = FunctionCalled();
		cout << j << endl;
	}

	return 0;
}

uint16_t FunctionCalled(void)
{
	static uint16_t fs_iCnt = 0;

	return fs_iCnt++;
}
#endif

#if 0
// 6.5
unsigned int AbsValue(int);

int main(int argc, char **agrv)
{
	// 编写一个求阶乘的函数
	cout << "Enter number: \n";
	int i;
	cin >> i;
	unsigned int j=	AbsValue(i);
	cout << "|" << i << "| = " << j << endl;

	return 0;
}

unsigned int AbsValue(int i)
{
	return i >= 0 ? i : -i;
}
#endif

#if 0
// 6.4
// function fundamental
void factorial_with_interacts();

int main(int argc, char **agrv)
{
	// 编写一个求阶乘的函数
	factorial_with_interacts();

	return 0;
}

void factorial_with_interacts()
{
	int num;
	std::cout << "Please input a positive number: ";
	while (std::cin >> num && num < 0)
		std::cout << "Please input a positive number again: ";
	std::cout << num;

	unsigned long long result = 1;
	while (num > 1)
		result *= num--;

	std::cout << "! is ";
	if (result)
		std::cout << result << std::endl;
	else
		std::cout << "too big" << std::endl;
}
#endif

#if 0
// 6.3
// function fundamental
long long Factorial(short int f_iNumber);

int main(int argc, char **agrv)
{
	// 编写一个求阶乘的函数
	cout << "Enter number:\n";
	short i;
	cin >> i;
	long long lNum = Factorial(i);
	cout << i << " : " << lNum << endl;

	return 0;
}

long long Factorial(short int f_iNumber)
{
	long i = 1;
	while (f_iNumber >= 1)
	{
		i *= f_iNumber--;
	}

	return i;
}
#endif