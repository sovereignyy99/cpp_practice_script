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
using std::string;
using std::vector;
using std::runtime_error;

#if 1
// 5.25
// throw try catch
int main(int argc, char **agrv)
{
	int a, b;
	cout << "Input two integers: ";
	while (cin >> a >> b)
	{
	    try {
	        if (b == 0) throw runtime_error("divisor is 0");
	        cout << static_cast<double>(a) / b << endl;
	        cout << "Input two integers: ";
	    } catch (runtime_error err) {
	        cout << err.what() << "\n"
	             << "Try again.\nInput two integers: ";
	    }
	}
	cout << "hello,world.";

	return 0;
}
#endif