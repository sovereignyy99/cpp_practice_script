/*
 * @Author: MatthewPerry
 * @Date: 2018-04-07 12:55:33
 * @Last Modified by: MatthewPerry
 * @Last Modified time: 2018-04-07 12:56:06
 */

#ifndef MY_DEBUG_H
#define MY_DEBUG_H

class Debug {
public:
    constexpr Debug(bool b = true) : rt(b), io(b), other(b) { }
    constexpr Debug(bool r, bool i, bool o) : rt(r), io(i), other(0) { }
    constexpr bool any() { return rt || io || other; }

    void set_rt(bool b) { rt = b; }
    void set_io(bool b) { io = b; }
    void set_other(bool b) { other = b; }

private:
    bool rt;        // runtime error
    bool io;        // I/O error
    bool other;     // the others
};

#endif