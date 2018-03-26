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
using std::runtime_error;
using std::string;
using std::vector;


#if 1
// 5.12
int main(int argc, char **agrv)
{
	 unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, spaceCnt = 0, tabCnt = 0, newLineCnt = 0, ffCnt = 0, flCnt = 0, fiCnt = 0;
    char ch, prech = '\0';
    while (cin >> std::noskipws >> ch)
    {
        switch (ch)
        {
            case 'a':
            case 'A':
                ++aCnt;
                break;
            case 'e':
            case 'E':
                ++eCnt;
                break;
            case 'i':
                if (prech == 'f') ++fiCnt;
            case 'I':
                ++iCnt;
                break;
            case 'o':
            case 'O':
                ++oCnt;
                break;
            case 'u':
            case 'U':
                ++uCnt;
                break;
            case ' ':
                ++spaceCnt;
                break;
            case '\t':
                ++tabCnt;
                break;
            case '\n':
                ++newLineCnt;
                break;
            case 'f':
                if (prech == 'f') ++ffCnt;
                break;
            case 'l':
                if (prech == 'f') ++flCnt;
                break;
        }
        prech = ch;
    }

    cout << "Number of vowel a(A): \t" << aCnt << '\n'
        << "Number of vowel e(E): \t" << eCnt << '\n'
        << "Number of vowel i(I): \t" << iCnt << '\n'
        << "Number of vowel o(O): \t" << oCnt << '\n'
        << "Number of vowel u(U): \t" << uCnt << '\n'
        << "Number of space: \t" << spaceCnt << '\n'
        << "Number of tab char: \t" << tabCnt << '\n'
        << "Number of new line: \t" << newLineCnt << '\n'
        << "Number of ff: \t" << ffCnt << '\n'
        << "Number of fl: \t" << flCnt << '\n'
        << "Number of fi: \t" << fiCnt << endl;

    return 0;
}
#endif

#if 0
// 5.11
int main(int argc, char **agrv)
{
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, spaceCnt = 0, tabCnt = 0, newLineCnt = 0;
	char ch;
	while (cin >> std::noskipws >> ch)
		switch (ch)
		{
		case 'a':
		case 'A':
			++aCnt;
			break;
		case 'e':
		case 'E':
			++eCnt;
			break;
		case 'i':
		case 'I':
			++iCnt;
			break;
		case 'o':
		case 'O':
			++oCnt;
			break;
		case 'u':
		case 'U':
			++uCnt;
			break;
		case ' ':
			++spaceCnt;
			break;
		case '\t':
			++tabCnt;
			break;
		case '\n':
			++newLineCnt;
			break;
		}

	cout << "Number of vowel a(A): \t" << aCnt << '\n'
		 << "Number of vowel e(E): \t" << eCnt << '\n'
		 << "Number of vowel i(I): \t" << iCnt << '\n'
		 << "Number of vowel o(O): \t" << oCnt << '\n'
		 << "Number of vowel u(U): \t" << uCnt << '\n'
		 << "Number of space: \t" << spaceCnt << '\n'
		 << "Number of tab char: \t" << tabCnt << '\n'
		 << "Number of new line: \t" << newLineCnt << endl;

	return 0;
}
#endif

#if 0
// 5.11
int main(int argc, char **agrv)
{
	//统计输入文本中有多少元音字母
	string strText;
	vector<int> Count_a(9, 0);
	auto it = Count_a.begin();
	while (getline(cin,strText))
	{
		for (auto aX : strText)
		{
			switch (aX)
			{
			case 'a':
			case 'A':
				(*it)++;
				(*(it + 8))++;
				break;

			case 'e':
			case 'E':
				(*(it + 1))++;
				(*(it + 8))++;
				break;

			case 'i':
			case 'I':
				(*(it + 2))++;
				(*(it + 8))++;
				break;

			case 'o':
			case 'O':
				(*(it + 3))++;
				(*(it + 8))++;
				break;

			case 'u':
			case 'U':
				(*(it + 4))++;
				(*(it + 8))++;
				break;

			case ' ':
				(*(it + 5))++;
				(*(it + 8))++;
				break;

			case '\t':
				(*(it + 6))++;
				(*(it + 8))++;
				break;

			case '\r':
				(*(it + 7))++;
				(*(it + 8))++;
				break;

			default:
				break;
			}
		}
	}
	cout << "a : " << Count_a[0] << endl;
	cout << "e : " << Count_a[1] << endl;
	cout << "i : " << Count_a[2] << endl;
	cout << "o : " << Count_a[3] << endl;
	cout << "u : " << Count_a[4] << endl;
	cout << "space : " << Count_a[5] << endl;
	cout << "tab : " << Count_a[6] << endl;
	cout << "enter : " << Count_a[7] << endl;
	cout << "all : " << Count_a[8] << endl;

	return 0;
}
#endif

#if 0
// 5.10
int main(int argc, char **agrv)
{
	//统计输入文本中有多少元音字母
	string strText;
	vector<int> Count_a = {0, 0, 0, 0, 0, 0};
	auto it = Count_a.begin();
	while (cin >> strText)
	{
		for (auto aX : strText)
		{
			switch (aX)
			{
			case 'a':
			case 'A':
				(*it)++;
				(*(it + 5))++;
				break;

			case 'e':
			case 'E':
				(*(it + 1))++;
				(*(it + 5))++;
				break;

			case 'i':
			case 'I':
				(*(it + 2))++;
				(*(it + 5))++;
				break;

			case 'o':
			case 'O':
				(*(it + 3))++;
				(*(it + 5))++;
				break;

			case 'u':
			case 'U':
				(*(it + 4))++;
				(*(it + 5))++;
				break;

			default:
				break;
			}
		}
	}
	cout << "a : " << Count_a[0] << endl;
	cout << "e : " << Count_a[1] << endl;
	cout << "i : " << Count_a[2] << endl;
	cout << "o : " << Count_a[3] << endl;
	cout << "u : " << Count_a[4] << endl;
	cout << "all : " << Count_a[5] << endl;

	return 0;
}
#endif

#if 0
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