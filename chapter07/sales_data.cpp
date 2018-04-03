/*
 * @Author: MattewPerry
 * @Date: 2018-04-03 16:12:39
 * @Last Modified by: MattewPerry
 * @Last Modified time: 2018-04-03 16:39:26
 */

#include "sales_data.h"

double sales_data_st::avg_price() const
{
    return (uiUnitSold ? (dRevenue / uiUnitSold) : 0);
}

sales_data_st &sales_data_st::combine(const sales_data_st &rhs)
{
    uiUnitSold += rhs.uiUnitSold;
    dRevenue += rhs.dRevenue;
    return *this;
}

sales_data_st add(const sales_data_st &lhs, const sales_data_st &rhs)
{
    sales_data_st sum = lhs;
    sum.combine(rhs);
    return sum;
}

std::istream &read(std::istream &is, sales_data_st &item)
{
    double price = 0.0;
    is >> item.strBookNo >> item.uiUnitSold >> price;
    item.dRevenue = price * item.uiUnitSold;
    return is;
}

std::ostream &print(std::ostream &os, const sales_data_st &item)
{
    os << item.isbn() << " "
       << item.uiUnitSold << " "
       << item.dRevenue << " "
       << item.avg_price();
    return os;
}
