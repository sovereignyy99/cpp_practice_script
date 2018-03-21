/*
 * @Author: MattewPerry
 * @Date: 2018-03-13 09:58:08
 * @Last Modified by: MattewPerry
 * @Last Modified time: 2018-03-13 09:58:42
 */

#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>

typedef struct sales_data_st_tag{
    std::string strBookNo;
    uint16_t uiUnitSold = 0;
    double dRevenue = 0.0;
}sales_data_st;

#endif
