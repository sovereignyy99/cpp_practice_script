/*
 * @Author: MatthewPerry
 * @Date: 2018-04-20 21:07:48
 * @Last Modified by: MatthewPerry
 * @Last Modified time: 2018-04-27 16:52:33
 */

#ifndef STRING_BLOB_H
#define STRING_BLOB_H

#include <exception>
#include <initializer_list>
#include <memory>
#include <string>
#include <vector>

class StrBlobPtr;
class ConstStrBlobPtr;
class StrBlob
{
  public:
    typedef std::vector<std::string>::size_type size_type;
    friend class StrBlobPtr;
    StrBlobPtr begin();
    StrBlobPtr end();
    friend class ConstStrBlobPtr;
    ConstStrBlobPtr begin() const; // should add const
    ConstStrBlobPtr end() const;   // should add const

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

class StrBlobPtr
{
  public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}

    bool operator!=(const StrBlobPtr &p) { return p.curr != curr; }
    std::string &deref() const
    {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    StrBlobPtr &incr()
    {
        check(curr, "increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }

  private:
    std::shared_ptr<std::vector<std::string>> check(size_t i, const std::string &msg) const
    {
        auto ret = wptr.lock();
        if (!ret)
            throw std::runtime_error("unbound StrBlobPtr");
        if (i >= ret->size())
            throw std::out_of_range(msg);
        return ret;
    }
    std::weak_ptr<std::vector<std::string>> wptr;
    size_t curr;
};

class ConstStrBlobPtr
{
  public:
    ConstStrBlobPtr() : curr(0) {}
    ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    bool operator!=(ConstStrBlobPtr &p) { return p.curr != curr; }
    const std::string &deref() const
    { // return value should add const
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    ConstStrBlobPtr &incr()
    {
        check(curr, "increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }

  private:
    std::shared_ptr<std::vector<std::string>> check(size_t i, const std::string &msg) const
    {
        auto ret = wptr.lock();
        if (!ret)
            throw std::runtime_error("unbound StrBlobPtr");
        if (i >= ret->size())
            throw std::out_of_range(msg);
        return ret;
    }
    std::weak_ptr<std::vector<std::string>> wptr;
    size_t curr;
};

#endif