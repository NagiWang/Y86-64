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

//***************************** Y86ConditionCodes ********************************

template <typename CCTagType>
const Y86CCTag& Y86ConditionCodes<CCTagType>::get() const
{
    return m_cc;
}

template <typename CCTagType>
typename Y86ConditionCodes<CCTagType>::CCTag& Y86ConditionCodes<CCTagType>::get()
{
    return const_cast<CCTag&>(static_cast<const Y86ConditionCodes*>(this)->get());
}

template <typename CCTagType>
void Y86ConditionCodes<CCTagType>::set(const CCTag& cc_tag)
{
    m_cc |= cc_tag;
}

template <typename CCTagType>
void Y86ConditionCodes<CCTagType>::clear(const CCTag& cc_tag)
{
    m_cc &= ~cc_tag;
}

template <typename CCTagType>
void Y86ConditionCodes<CCTagType>::show() const
{
    std::cout << "Condition Code:\n"
              << std::format("ZF {:01b}\tSF {:01b}\tOF {:01b}\n\n",
                             static_cast<bool>(m_cc & ZF<CCTag>),
                             static_cast<bool>(m_cc & SF<CCTag>),
                             static_cast<bool>(m_cc & OF<CCTag>));
}

#endif  //Y86_64_CC_IPP
