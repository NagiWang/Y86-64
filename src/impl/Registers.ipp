#ifndef Y86_64_REGISTERS_IPP
#define Y86_64_REGISTERS_IPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif  // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "../Registers.hpp"

//***************************** Y86Registers ********************************

template <typename RFTagType>
const uint64_t& Y86Registers<RFTagType>::get(const RFTag& rf_tag) const noexcept(false)
{
    // clang-format off
    switch (rf_tag) {
    case RFTag::RAX: return m_registers[ 0];
    case RFTag::RBX: return m_registers[ 1];
    case RFTag::RCX: return m_registers[ 2];
    case RFTag::RDX: return m_registers[ 3];
    case RFTag::RSP: return m_registers[ 4];
    case RFTag::RBP: return m_registers[ 5];
    case RFTag::RDI: return m_registers[ 6];
    case RFTag::RSI: return m_registers[ 7];
    case RFTag::R8 : return m_registers[ 8];
    case RFTag::R9 : return m_registers[ 9];
    case RFTag::R10: return m_registers[10];
    case RFTag::R11: return m_registers[11];
    case RFTag::R12: return m_registers[12];
    case RFTag::R13: return m_registers[13];
    case RFTag::R14: return m_registers[14];
    default: throw std::runtime_error("Don't have this register!");
    }
    // clang-format on
}

template <typename RFTagType>
uint64_t& Y86Registers<RFTagType>::get(const RFTag& rf_tag) noexcept(false)
{
    return const_cast<uint64_t&>(static_cast<const Y86Registers*>(this)->get(rf_tag));
}

template <typename RFTagType>
void Y86Registers<RFTagType>::set(const RFTag& rf_tag, uint64_t value)
{
    this->get(rf_tag) = value;
}

template <typename RFTagType>
void Y86Registers<RFTagType>::Y86Registers::clear()
{
    m_registers.fill(0);
}

template <typename RFTagType>
void Y86Registers<RFTagType>::clear(const RFTag& rf_tag)
{
    this->set(rf_tag, 0);
}

template <typename RFTagType>
void Y86Registers<RFTagType>::show() const
{
    std::cout << "Y86Registers:\n"
              << std::format("rax 0x{:016x}\trbx 0x{:016x}\trcx 0x{:016x}\trdx 0x{:016x}\n"
                             "rsp 0x{:016x}\trbp 0x{:016x}\trdi 0x{:016x}\trsi 0x{:016x}\n"
                             "r8  0x{:016x}\tr9  0x{:016x}\tr10 0x{:016x}\tr11 0x{:016x}\n"
                             "r12 0x{:016x}\tr13 0x{:016x}\tr14 0x{:016x}\n\n",
                             m_registers[0],
                             m_registers[1],
                             m_registers[2],
                             m_registers[3],
                             m_registers[4],
                             m_registers[5],
                             m_registers[6],
                             m_registers[7],
                             m_registers[8],
                             m_registers[9],
                             m_registers[10],
                             m_registers[11],
                             m_registers[12],
                             m_registers[13],
                             m_registers[14]);
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
                             static_cast<bool>(m_cc & ZF),
                             static_cast<bool>(m_cc & SF),
                             static_cast<bool>(m_cc & OF));
}

#endif  //Y86_64_REGISTERS_IPP