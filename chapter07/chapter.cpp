/*
 * @Author: MattewPerry
 * @Date: 2018-03-15 15:11:54
 * @Last Modified by: MattewPerry
 * @Last Modified time: 2018-04-03 16:56:17
 */

#include "sales_data.h"
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
// 7.3
int main(int argc, char **argv)
{
    return 0;
}
#endif

#if 0
// 7.2
int main(int argc, char **argv)
{
    sales_data_st total;
    if (read(std::cin, total))
    {
        sales_data_st trans;
        while (read(std::cin, trans))
        {
            if (total.strBookNo == trans.strBookNo)
            {
                total.combine(trans);
            }
            else
            {
                print(std::cout, total);
                total = trans;
            }
        }
        print(std::cout, total);
        std::cout << std::endl;
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
    sales_data_st total;
    if (cin >> total.strBookNo >> total.uiUnitSold >> total.dRevenue)
    {
        sales_data_st trans;
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