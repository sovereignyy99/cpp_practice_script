/*
 * @Author: MatthewPerry
 * @Date: 2018-04-09 09:37:58
 * @Last Modified by: MatthewPerry
 * @Last Modified time: 2018-04-09 09:40:38
 */

#ifndef PERSON_INFO_H
#define PERSON_INFO_H

#include <string>
#include <vector>

//
// ──────────────────────────────────────────────────────────────────────────────────────────── I ──────────
//   :::::: D E C L E R A T I O N   A N D   D E F I N I T I O N : :  :   :    :     :        :          :
// ──────────────────────────────────────────────────────────────────────────────────────────────────────
//

class person_info_cl
{
  public:
    std::string strName;
    std::vector<std::string> strPhones_a;
};

#endif