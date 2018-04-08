/*
 * @Author: MatthewPerry
 * @Date: 2018-03-15 15:11:54
 * @Last Modified by:   MatthewPerry
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

#if 0
// 5.24
int main(int argc, char **agrv)
{
    // 输入两个整数，输出第一个数/第二个数
    int i1, i2;
    cin >> i1 >> i2;
    if(i2!=0){
        cout << i1 / i2 << endl;
    }else
    {
        throw runtime_error("i2 = 0 is wrong.");
    }

    return 0;
}
#endif

#if 0
// 5.23
int main(int argc, char **agrv)
{
    // 输入两个整数，输出第一个数/第二个数
    int i1, i2;
    cin >> i1 >> i2;
    if(i2!=0){
        cout << i1 / i2 << endl;
    }else
    {
        cout << "divider should not equal 0.";
    }

    return 0;
}
#endif

#if 0
// 5.21
int main(int argc, char **agrv)
{
    string read, tmp;
    while ( cin >> read )
        if (read == tmp && isupper(read[0])) break;
        else tmp = read;

    if (cin.eof()) cout << "no word was repeated." << endl;
    else cout << read << " occurs twice in succession." << endl;

    return 0;
}
#endif

#if 0
// 5.20
int main(int argc, char **agrv)
{
    // 读取string对象的序列直到出现两个相同的单词或所有单词读完为止
    // 使用while循环一次读取一个单词，输出连续重复出现的单词或输出没有连续
    string read, tmp;
    while (cin >> read)
        if (read == tmp)
            break;
        else
            tmp = read;

    if (cin.eof())
        cout << "no word was repeated." << endl;
    else
        cout << read << " occurs twice in succession." << endl;

    return 0;
}
#endif

#if 0
// 5.20
int main(int argc, char **agrv)
{
    // 读取string对象的序列直到出现两个相同的单词或所有单词读完为止
    // 使用while循环一次读取一个单词，输出连续重复出现的单词或输出没有连续
    string strCurr, strPrev;
    bool blFlag = false;
    cout << "Enter words: \n";
    while (cin >> strCurr)
    {
        if (strCurr == strPrev)
        {
            cout << "continuous word: " << strCurr << endl;
            blFlag = true;
            break;
        }
        strPrev = strCurr;
    }
    if (!blFlag)
    {
        cout << "no continuous words." << endl;
    }

    return 0;
}
#endif

#if 0
// 5.19
int main(int argc, char **agrv)
{
	string rsp;
	do
	{
		cout << "Input two strings: ";
		string str1, str2;
		cin >> str1 >> str2;
		cout << (str1 <= str2 ? str1 : str2)
			 << " is less than the other. "
			 << "\n\n"
			 << "More? Enter yes or no: ";
		cin >> rsp;
	} while (!rsp.empty() && rsp[0] == 'y');
	return 0;
}
#endif

#if 0
// 5.17
int main(int argc, char **agrv)
{
	// 两个包含整数的vector,判断其中一个是否是另一个的前缀
	// 0 1 1 2 和 0 1 1 2 3 4 5 则是前缀
    vector<int> vec1{0, 1, 1, 2};
    vector<int> vec2{0, 1, 1, 2, 3, 5, 8};

    auto size = vec1.size() < vec2.size() ? vec1.size() : vec2.size();
    for (decltype(vec1.size()) i = 0; i != size; ++i) {
        if (vec1[i] != vec2[i]) { cout << "false" << endl; break; }
        if (i == size - 1) cout << "true" << endl;
    }
	// 很简便，其实只需要知道小的vector的size就可以了
	// 并不需要确定那个vector比较小
	// 比我的代码简洁

    return 0;
}
#endif

#if 0
// 5.14
int main(int argc, char **agrv)
{
	vector<string> svec;
	string str;
	while (cin >> str)
	{
		svec.push_back(str);
	}

	vector<string>::iterator it = svec.begin(); //auto it = svec.begin();
	int bigNum = 1, countNum = 1;
	string bigStr, countStr;
	while (svec.size() > 0 && it != svec.end() - 1)
	{
		if (*it == *(it + 1))
		{
			++countNum;
			countStr = *it;
		}
		else
		{
			countNum = 1;
		}
		if (countNum > bigNum)
		{
			bigStr = countStr;
			bigNum = countNum;
		}
		++it;
	}

	if (bigNum == 1)
	{
		cout << "there is no duplicated string." << endl;
	}
	else
	{
		cout << "the word " << bigStr << " occurred  " << bigNum << " times." << endl;
	}
	return 0;
}
#endif

#if 0
// 5.14
int main(int argc, char **agrv)
{
	pair<string, int> max_duplicated;
	int count = 0;
	for (string str, prestr; cin >> str; prestr = str)
	{
		if (str == prestr)
			++count;
		else
			count = 0;
		if (count > max_duplicated.second)
			max_duplicated = {prestr, count};
	}

	if (max_duplicated.first.empty())
		cout << "There's no duplicated string." << endl;
	else
		cout << "the word " << max_duplicated.first << " occurred " << max_duplicated.second + 1 << " times. " << endl;

	return 0;
}
#endif

#if 0
// 5.14
int main(int argc, char **agrv)
{
	// 读入一段文本，记录连续出现的单词的最大次数，并打印该单词，若没有则输出没有连续单词
	string strCurr, strPrev,strMax;
	int iCnt=1,iMaxCnt=0;
	while(cin>>strCurr)
	{
		if(strCurr==strPrev)
		{
			++iCnt;
			if(iCnt>iMaxCnt)
			{
				iMaxCnt = iCnt;
				strMax = strCurr;
			}
		}else
		{
			iCnt = 1;
		}
		strPrev = strCurr;
	}
	if(!strMax.empty())
	{
		cout << strMax << " : " << iMaxCnt << " times. " << endl;
	}else
	{
		cout << "there is no pair chars." << endl;
	}

	return 0;
}
#endif

#if 0
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