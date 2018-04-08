/*
 * @Author: MatthewPerry
 * @Date: 2018-04-07 10:50:30
 * @Last Modified by: MatthewPerry
 * @Last Modified time: 2018-04-07 10:54:26
 */

#ifndef ANY_CLASS_H
#define ANY_CLASS_H

//
// ──────────────────────────────────────────────────────────────────────────────────────────── I ──────────
//   :::::: D E C L E R A T I O N   A N D   D E F I N I T I O N : :  :   :    :     :        :          :
// ──────────────────────────────────────────────────────────────────────────────────────────────────────
//

#if 0
#include <string>
#include <iostream>

struct Person {
    friend std::istream &read(std::istream &is, Person &person);
    friend std::ostream &print(std::ostream &os, const Person &person);

public:
    Person() = default;
    Person(const std::string sname, const std::string saddr):name(sname), address(saddr){}
    explicit Person(std::istream &is){read(is, *this);}

    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
private:
    std::string name;
    std::string address;
};

std::istream &read(std::istream &is, Person &person)
{
    is >> person.name >> person.address;
    return is;
}

std::ostream &print(std::ostream &os, const Person &person)
{
    os << person.name << " " << person.address;
    return os;
}
#endif



#endif