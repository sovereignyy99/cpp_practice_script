/*
 * @Author: MatthewPerry
 * @Date: 2018-04-04 11:48:17
 * @Last Modified by: MatthewPerry
 * @Last Modified time: 2018-04-05 22:02:14
 */

#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <cstdlib>
#include <iostream>
#include <string>

//
// ──────────────────────────────────────────────────────────────────────────────────────────── I ──────────
//   :::::: D E C L E R A T I O N   A N D   D E F I N I T I O N : :  :   :    :     :        :          :
// ──────────────────────────────────────────────────────────────────────────────────────────────────────
//

class sales_data_cl
{
  friend std::istream &read(std::istream &is, sales_data_cl &item);
  friend std::ostream &print(std::ostream &os, const sales_data_cl &item);

public:
  //
  // ─── CONSTRUCTOR ────────────────────────────────────────────────────────────────
  //
  sales_data_cl(std::string f_strIsbn, uint16_t f_uiUnitSold, double f_dPrice) : strBookNo(f_strIsbn), uiUnitSold(f_uiUnitSold), dRevenue(f_dPrice * f_uiUnitSold)
  {
    std::cout << "constructor 0\n";
  }
  sales_data_cl() : sales_data_cl("", 0, 0)
  {
    std::cout << "constructor 1\n";
  }
  sales_data_cl(std::string f_strIsbn) : sales_data_cl(f_strIsbn, 0, 0)
  {
    std::cout << "constructor 2\n";
  }
  sales_data_cl(std::istream &is) : sales_data_cl()
  {
    read(is, *this);
    std::cout << "constructor 3\n";
  }

  //
  // ─── MEMBER FUNCTION ────────────────────────────────────────────────────────────
  //
  std::string isbn(void) const { return strBookNo; }
  sales_data_cl &combine(const sales_data_cl &obj);

private:
  //
  // ─── MEMBER FUNCTION ────────────────────────────────────────────────────────────
  //
  double avg_price(void) const { return (uiUnitSold ? (dRevenue / uiUnitSold) : 0); }

  //
  // ─── DATA MEMBER ────────────────────────────────────────────────────────────────
  //
  std::string strBookNo;
  uint16_t uiUnitSold = 0;
  double dRevenue = 0.0;
};

#if 0
class sales_data_cl
{
  friend std::istream &read(std::istream &is, sales_data_cl &item);
  friend std::ostream &print(std::ostream &os, const sales_data_cl &item);

public:
  //
  // ─── CONSTRUCTOR ────────────────────────────────────────────────────────────────
  //
  // sales_data_cl() : strBookNo("random"), uiUnitSold(0), dRevenue(0.0) {}
  // sales_data_cl(std::string f_strIsbn = "default") : strBookNo(f_strIsbn) {}
  // sales_data_cl(std::string f_strIsbn="default", uint16_t f_uiUnitSold=1, double f_dPrice=10.0) : strBookNo(f_strIsbn), uiUnitSold(f_uiUnitSold), dRevenue(f_dPrice * f_uiUnitSold) {}
  sales_data_cl(std::string f_strIsbn) : strBookNo(f_strIsbn) {}
  sales_data_cl(std::string f_strIsbn, uint16_t f_uiUnitSold, double f_dPrice) : strBookNo(f_strIsbn), uiUnitSold(f_uiUnitSold), dRevenue(f_dPrice * f_uiUnitSold) {}
  sales_data_cl(std::istream &is = std::cin) { read(is, *this); }
  // sales_data_cl(std::istream &is) { read(is, *this); }

  //
  // ─── MEMBER FUNCTION ────────────────────────────────────────────────────────────
  //
  std::string isbn(void) const { return strBookNo; }
  sales_data_cl &combine(const sales_data_cl &obj);

private:
  //
  // ─── MEMBER FUNCTION ────────────────────────────────────────────────────────────
  //
  double avg_price(void) const { return (uiUnitSold ? (dRevenue / uiUnitSold) : 0); }

  //
  // ─── DATA MEMBER ────────────────────────────────────────────────────────────────
  //
  std::string strBookNo;
  uint16_t uiUnitSold = 0;
  double dRevenue = 0.0;
};
#endif

//
// ────────────────────────────────────────────────────────────────────── II ──────────
//   :::::: M E M B E R   F U N C T I O N : :  :   :    :     :        :          :
// ────────────────────────────────────────────────────────────────────────────────
//

/**
 * @brief combine rhs to lhs
 *
 * @param rhs
 * @return sales_data_cl&
 */
sales_data_cl &sales_data_cl::combine(const sales_data_cl &rhs)
{
  uiUnitSold += rhs.uiUnitSold;
  dRevenue += rhs.dRevenue;
  return *this;
}

//
// ────────────────────────────────────────────────────────────────────────────── III ──────────
//   :::::: N O N   M E M B E R   F U N C T I O N : :  :   :    :     :        :          :
// ────────────────────────────────────────────────────────────────────────────────────────
//

/**
 * @brief add lhs and rhs
 *
 * @param lhs
 * @param rhs
 * @return sales_data_cl
 */
sales_data_cl add(const sales_data_cl &lhs, const sales_data_cl &rhs)
{
  sales_data_cl sum = lhs;
  sum.combine(rhs);
  return sum;
}

/**
 * @brief read item through istream
 *
 * @param is
 * @param item
 * @return std::istream&
 */
std::istream &read(std::istream &is, sales_data_cl &item)
{
  double price = 0.0;
  is >> item.strBookNo >> item.uiUnitSold >> price;
  item.dRevenue = price * item.uiUnitSold;
  return is;
}

/**
 * @brief print item through ostream
 *
 * @param os
 * @param item
 * @return std::ostream&
 */
std::ostream &print(std::ostream &os, const sales_data_cl &item)
{
  os << item.isbn() << " "
     << item.uiUnitSold << " "
     << item.dRevenue << " "
     << item.avg_price();
  return os;
}

#endif
