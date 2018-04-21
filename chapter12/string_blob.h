/*
 * @Author: MatthewPerry
 * @Date: 2018-04-20 21:07:48
 * @Last Modified by: MatthewPerry
 * @Last Modified time: 2018-04-20 21:34:56
 */

#ifndef STRING_BLOB_H
#define STRING_BLOB_H

#include <exception>
#include <initializer_list>
#include <memory>
#include <string>
#include <vector>

class StrBlob
{
  public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    // 添加和删除元素
    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back();

    // 元素访问
    std::string &front();
    std::string &back();
    const std::string &front() const;
    const std::string &back() const;

  private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}

StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {}

void StrBlob::check(size_type i, const std::string &msg) const
{
    if (i >= data->size())
    {
        throw std::out_of_range(msg);
    }
}

std::string &StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}

std::string &StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

const std::string &StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}

const std::string &StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back()
{
    check(0, "pop on empty StrBlob");
    return data->pop_back();
}

#endif