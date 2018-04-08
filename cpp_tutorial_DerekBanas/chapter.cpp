/*
 * @Author: MatthewPerry
 * @Date: 2018-03-11 12:07:55
 * @Last Modified by: MatthewPerry
 * @Last Modified time: 2018-03-11 12:57:43
 */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#if 0
//010
int main(int argc, char **agrv)
{
    srand(time(NULL));
    int secretNum = rand() % 11;
    int guess = 0;

    do
    {
        cout << "Guess the number : \n";
        cin >> guess;
        if (guess > secretNum)
            cout << "Too Big\n";
        if (guess < secretNum)
            cout << "Too Small\n";
    } while (secretNum != guess);
    cout << "You guessed it\n";
    cout << time(NULL) << endl;

    return 0;
}
#endif

#if 0
//009

vector<int> Range(int start, int max, int step);

int main(int argc, char **agrv)
{
    try{
        cout << "Throwing exception\n";
        throw runtime_error("Error occurred\n");
        cout << "Can you print me?\n";
    }

    catch(exception & exp){
        cout << "Handled exception : " << exp.what() << "\n";
    }

    catch(...){
        cout << "default exception\n";
    }

    return 0;
}

vector<int> Range(int start, int max, int step)
{
    // every while statement needs an index
    // to start with
    int i = start;

    // will hold returning vector
    vector<int> range;

    // make sure we don't go past max value
    while (i <= max)
    {
        // add value to vector
        range.push_back(i);

        // increment the required amount
        i += step;
    }

    return range;
}
#endif

#if 0
//008

vector<int> Range(int start, int max, int step);

int main(int argc, char **agrv)
{
    double num1 = 0, num2 = 0;

    cout << "Enter number 1 : ";
    cin >> num1;

    cout << "Enter number 2 : ";
    cin >> num2;

    try{
        if(num2==0)
        {
            throw "Division by zero is not possible";
        }else
        {
            printf("%.1f / %.1f = %.2f", num1, num2, (num1 / num2));
        }
    }

    catch(const char* exp){
        cout << "Error : " << exp << "\n";
    }


    return 0;
}

vector<int> Range(int start, int max, int step)
{
    // every while statement needs an index
    // to start with
    int i = start;

    // will hold returning vector
    vector<int> range;

    // make sure we don't go past max value
    while (i <= max)
    {
        // add value to vector
        range.push_back(i);

        // increment the required amount
        i += step;
    }

    return range;
}
#endif

#if 1
//007

vector<int> Range(int start, int max, int step);

int main(int argc, char **agrv)
{
    /*  how tall is the tree : 5
            #
           ###
          #####
         #######
        #########
            #
    */
    /*
    1. decrement spaces by one each time through the loop
    2. increment the hashes by 2 each time
    3. save spaces to the stump by calculating tree height -1
    4. decrement from tree height until equals zero
    5. print spaces and then hashes for each row
    6. print stump spaces and then 1 hash
 */

    cout << "How tall is the tree : ";
    int treeHeight = 0, spaces = 0, hashes = 1, stumpSpaces = 0;
    cin >> treeHeight;
    spaces = treeHeight - 1;
    stumpSpaces = treeHeight - 1;

    while (treeHeight != 0)
    {
        for (auto x : Range(1, spaces, 1))
        {
            cout << " ";
        }

        for (auto x : Range(1, hashes, 1))
        {
            cout << "#";
        }

        cout << endl;
        spaces -= 1;
        hashes += 2;
        treeHeight -= 1;
    }

    for (auto x : Range(1, stumpSpaces, 1))
    {
        cout << " ";
    }
    cout << "#";

    return 0;
}

vector<int> Range(int start, int max, int step)
{
    // every while statement needs an index
    // to start with
    int i = start;

    // will hold returning vector
    vector<int> range;

    // make sure we don't go past max value
    while (i <= max)
    {
        // add value to vector
        range.push_back(i);

        // increment the required amount
        i += step;
    }

    return range;
}
#endif

#if 0
//007

vector<int> Range(int start, int max, int step);

int main(int argc, char **agrv)
{
    int i = 1;
    while (i <= 20)
    {
        if ((i % 2) == 0)
        {
            i += 1;
            continue;
        }

        if (i == 15)
            break;
        cout << i << endl;

        i += 1;
    }

    return 0;
}

vector<int> Range(int start, int max, int step)
{
    // every while statement needs an index
    // to start with
    int i = start;

    // will hold returning vector
    vector<int> range;

    // make sure we don't go past max value
    while (i <= max)
    {
        // add value to vector
        range.push_back(i);

        // increment the required amount
        i += step;
    }
}
#endif

#if 0
//007
int main(int argc, char **agrv)
{
    vector<int> myVec(10);
    iota(begin(myVec), end(myVec), 0);

    for (int i = 0; i < myVec.size(); ++i)
    {
        cout << myVec[i] << "\n";
    }

    for(auto y:myVec){
        cout << y << endl;
    }

    int val = 8;
    if((val % 2)==0)
    {
        cout << val << " is even\n";
    }else
    {
        cout << val << " is odd\n";
    }

    return 0;
}
#endif

#if 0
//006
int main(int argc, char **agrv)
{
    string sAge = "0";
    int nGrade = 0;
    cout << "Enter your age: \n";
    getline(cin, sAge);
    int nAge = stoi(sAge);

    if (nAge < 5)
    {
        cout << "Too young for school.\n";
    }
    else if (nAge == 5)
    {
        cout << "Go to kindergarten.\n";
    }
    else if ((nAge > 5) && (nAge <= 17))
    {
        nGrade = nAge - 5;
        cout << "Go to grade " << nGrade << endl;
    }
    else
    {
        cout << "Go to college." << endl;
    }

    return 0;
}
#endif

#if 0
//005
int main(int argc, char **agrv)
{
    // 1 - 18, 21, 50, >65
    string sAge = "0"; // 如果写成string sAge=0;能编译但运行会挂；如果写成string sAge=1;不能编译
    cout << "Enter your age:" << endl;
    getline(cin, sAge);
    int nAge = stoi(sAge);

    if ((nAge >= 1) && (nAge <= 18))
    {
        cout << "Important birthday!\n";
    }
    else if ((nAge == 21) or (nAge == 50))
    {
        cout << "Important birthday!\n";
    }
    else if (nAge >= 65)
    {
        cout << "Important birthday!\n";
    }
    else
    {
        cout << "Not an important birthday..\n";
    }

    return 0;
}
#endif

#if 0
//004
int main(int argc, char **agrv)
{
    // km = miles * 1.60934
    // Enter Miles : 5
    // 5 miles equals 8.0467 kilometers.

    std::string sMiles;
    double dMiles, dKilometers;
    std::cout << "Enter Miles : ";
    getline(std::cin, sMiles);
    dMiles = std::stod(sMiles);
    dKilometers = dMiles * 1.60934;
    printf("%.1f miles equals %.4f kilometers.\n", dMiles, dKilometers);

    std::cout << "\n\n\n\n\n\nDone!\a\r\n";
    // system("pause");
    // getchar();
    // getchar();
    return 0;
}
#endif

#if 0
//003
//arithmetic operation
int main(int argc, char **agrv)
{
    std::string sQuestion("Enter Number 1 : ");
    std::string sNum1, sNum2;

    std::cout << sQuestion;
    getline(std::cin, sNum1);
    std::cout << "Enter Number 2 : ";
    getline(std::cin, sNum2);

    int nNum1 = std::stoi(sNum1);
    int nNum2 = std::stoi(sNum2);

    printf("%d + %d = %d\n", nNum1, nNum2, (nNum1 + nNum2));
    printf("%d - %d = %d\n", nNum1, nNum2, (nNum1 - nNum2));
    printf("%d * %d = %d\n", nNum1, nNum2, (nNum1 * nNum2));
    printf("%d / %d = %d\n", nNum1, nNum2, (nNum1 / nNum2));
    printf("%d %% %d = %d\n", nNum1, nNum2, (nNum1 % nNum2));

    std::cout << "\n\n\n\n\n\nDone!\a\r\n";
    // system("pause");
    // getchar();
    // getchar();
    return 0;
}
#endif

#if 0
//002
//datatypes

int g_iRandNum = 0;

const double PI = 3.14159;

int main(int argc, char **agrv)
{
    bool bMarried = true;
    char chMyGrade = 'A';
    unsigned short int u16Age = 43;
    short int siWeight = 180;
    int nDays = 7;
    long lBigNum = 1100000;
    float fPi = 3.14159;
    double dbBigFloat = 1.11111111111111111111;
    long double ldPi = 3.14159;
    auto whatWillIBe = true;

    std::cout << "Min bool: " << std::numeric_limits<bool>::min() << "\n";
    std::cout << "Max bool: " << std::numeric_limits<bool>::max() << "\n";

    std::cout << "Min unsigned short int: " << std::numeric_limits<unsigned short int>::min() << "\n";
    std::cout << "Max unsigned short int: " << std::numeric_limits<unsigned short int>::max() << "\n";

    std::cout << "Min short int: " << std::numeric_limits<short int>::min() << "\n";
    std::cout << "Max short int: " << std::numeric_limits<short int>::max() << "\n";

    std::cout << "Min int: " << std::numeric_limits<int>::min() << "\n";
    std::cout << "Max int: " << std::numeric_limits<int>::max() << "\n";

    std::cout << "Min long: " << std::numeric_limits<long>::min() << "\n";
    std::cout << "Max long: " << std::numeric_limits<long>::max() << "\n";

    std::cout << "Min float: " << std::numeric_limits<float>::min() << "\n";
    std::cout << "Max float: " << std::numeric_limits<float>::max() << "\n";

    std::cout << "Min double: " << std::numeric_limits<double>::min() << "\n";
    std::cout << "Max double: " << std::numeric_limits<double>::max() << "\n";

    std::cout << "Min long double: " << std::numeric_limits<long double>::min() << "\n";
    std::cout << "Max long double: " << std::numeric_limits<long double>::max() << "\n";

    std::cout << "Size of char: " << sizeof(char) << "\n";

    std::cout << "\n\n\n\n\n\nDone!\a\r\n";
    // system("pause");
    // getchar();
    // getchar();
    return 0;
}
#endif

#if 0
//001
//start
int main(int argc, char **agrv)
{
    std::cout << "HelloWorld!" << std::endl;

    if(argc!=1){
        std::cout << "You entered " << argc << " arguments\n";
    }

    for (int i = 0; i < argc; ++i)
    {
        std::cout << agrv[i] << "\n";
    }


    std::cout << "\n\n\n\n\n\nDone!\a\r\n";
    // system("pause");
    // getchar();
    // getchar();
    return 0;
}
#endif
