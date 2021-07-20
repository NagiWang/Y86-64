#ifndef Y86_64_CC_IPP
#define Y86_64_CC_IPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif  // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "../CC.hpp"

constexpr Y86CCTag::Y86CCTag(uint8_t value) noexcept(false)
    : m_value(value)
{
    if (value > 7)
        throw std::runtime_error("Please use a combination of {ZF, SF, OF} for initialization!");
}

Y86CCTag operator|(const Y86CCTag& lval, const Y86CCTag& rval)
{
    return Y86CCTag(lval.m_value | rval.m_value);
}

Y86CCTag& Y86CCTag::operator|=(const Y86CCTag& other)
{
    if (this != &other) this->m_value |= other.m_value;
    return *this;
}

Y86CCTag operator&(const Y86CCTag& lval, const Y86CCTag& rval)
{
    return Y86CCTag(lval.m_value & rval.m_value);
}

Y86CCTag& Y86CCTag::operator&=(const Y86CCTag& other)
{
    if (this != &other) this->m_value &= other.m_value;
    return *this;
}

Y86CCTag operator~(const Y86CCTag& other)
{
    return Y86CCTag(~other.m_value & 0x7);
}

Y86CCTag::operator bool() const
{
    return m_value;
}

#endif  //Y86_64_CC_IPP
