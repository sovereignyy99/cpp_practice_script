/*
 * @Author: MatthewPerry
 * @Date: 2018-04-04 11:48:11
 * @Last Modified by: MatthewPerry
 * @Last Modified time: 2018-04-04 16:50:35
 */

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class person_cl
{
  friend std::istream &read(std::istream &is, person_cl &obj);
  friend std::ostream &print(std::ostream &os, person_cl &obj);

public:
  //
  // ─── CONSTRUCTOR ────────────────────────────────────────────────────────────────
  //
  person_cl() = default;
  person_cl(std::string f_strName, std::string f_strAddress) : strName(f_strName), strAddress(f_strAddress) {}
  person_cl(std::istream &is) { read(is, *this); }
  //
  // ─── MEMBER FUNCTIONS ───────────────────────────────────────────────────────────
  //
  std::string GetName() const { return strName; }
  std::string GetName2() const { return (*this).strName; }
  std::string GetName3() const { return this->strName; }
  std::string GetAddress() const { return strAddress; }

private:
  //
  // ─── DATA MEMBER ────────────────────────────────────────────────────────────────
  //
  std::string strName;
  std::string strAddress;
};

/**
 * @brief read person obj from istream
 * @param is
 * @param obj
 * @return std::istream&
 */
std::istream &read(std::istream &is, person_cl &obj)
{
  is >> obj.strName >> obj.strAddress;
  return is;
}

/**
 * @brief print obj
 * @param os
 * @param obj
 * @return std::ostream&
 */
std::ostream &print(std::ostream &os, person_cl &obj)
{
  os << obj.strName << " : " << obj.strAddress;
  return os;
}

#endif