/*
 * @Author: MattewPerry
 * @Date: 2018-03-13 09:58:08
 * @Last Modified by: MattewPerry
 * @Last Modified time: 2018-04-03 16:52:57
 */

#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <cstdlib>
#include <iostream>
#include <string>
class sales_data_st
{
  public:
    std::string strBookNo;
    uint16_t uiUnitSold = 0;
    double dRevenue = 0.0;
    std::string isbn() const { return strBookNo; }
    sales_data_st &combine(const sales_data_st &);
    double avg_price() const;
};

sales_data_st add(const sales_data_st &lhs, const sales_data_st &rhs);
std::istream &read(std::istream &is, sales_data_st &item);
std::ostream &print(std::ostream &os, const sales_data_st &item);

#endif
