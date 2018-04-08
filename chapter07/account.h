/*
 * @Author: MatthewPerry
 * @Date: 2018-04-07 13:01:22
 * @Last Modified by: MatthewPerry
 * @Last Modified time: 2018-04-07 13:03:24
 */

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
public:
    void calculate() { amount += amount * interestRate; }
    static double rate() { return interestRate; }
    static void rate(double newRate) { interestRate = newRate; }

private:
    std::string owner;
    double amount;
    static double interestRate;
    static constexpr double todayRate = 42.42;
    static double initRate() { return todayRate; }
};

double Account::interestRate = initRate();

#endif