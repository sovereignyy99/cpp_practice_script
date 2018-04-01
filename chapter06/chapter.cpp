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

#if 1
// 6.11
int main(int argc, char **agrv)
{

	return 0;
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