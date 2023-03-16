#ifndef STRVECTOR_H
#define STRVECTOR_H

#include <string>
#include <algorithm>
#include <iostream>

class StrVector {
public:
    using iterator = std::string*;
    using const_iterator = const std::string*;
    using size_type = size_t;

    const size_type kInitialSize = 2;
    StrVector() noexcept;
    StrVector(size_type n, const std::string& val) noexcept;
    Strvector(const strvector& others) noexcept;
    StrVector& operator=(const StrVector& rhs)noexcept;
    Strvector(StrVector&& other)noexcept;
    
    ~StrVector()noexcept;
    size_type size() const;
    bool empty() const;

};
