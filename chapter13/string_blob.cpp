/*
 * @Author: MatthewPerry
 * @Date: 2018-04-27 10:58:27
 * @Last Modified by: MatthewPerry
 * @Last Modified time: 2018-04-27 16:52:17
 */

#include "string_blob.h"

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>())
{
}

StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il))
{
}

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

StrBlobPtr StrBlob::begin(void)
{
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end(void)
{
    return StrBlobPtr(*this, data->size());
}

ConstStrBlobPtr StrBlob::begin() const // should add const
{
    return ConstStrBlobPtr(*this);
}
ConstStrBlobPtr StrBlob::end() const // should add const
{
    return ConstStrBlobPtr(*this, data->size());
}