#ifndef Y86_64_CC_HPP
#define Y86_64_CC_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif  // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "headers.hpp"

//* Condition Codes Tag
struct Y86CCTag {
    constexpr explicit Y86CCTag(uint8_t value = 0) noexcept(false);

    Y86CCTag& operator|=(const Y86CCTag& other);
    Y86CCTag& operator&=(const Y86CCTag& other);

    friend Y86CCTag operator|(const Y86CCTag& lval, const Y86CCTag& rval);
    friend Y86CCTag operator&(const Y86CCTag& lval, const Y86CCTag& rval);
    friend Y86CCTag operator~(const Y86CCTag& other);

    explicit operator bool() const;

private:
    uint8_t m_value = 0;
};

#include "impl/CC.ipp"

constexpr Y86CCTag ZF{0x1};  // 0 0 1
constexpr Y86CCTag SF{0x2};  // 0 1 0
constexpr Y86CCTag OF{0x4};  // 1 0 0

#endif  //Y86_64_CC_HPP