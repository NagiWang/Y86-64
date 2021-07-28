#ifndef Y86_64_REGISTERS_IPP
#define Y86_64_REGISTERS_IPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif  // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "../registers.hpp"

//***************************** Y86Registers ********************************

template <typename RFTagType>
std::array<uint64_t, 16> Y86Registers<RFTagType>::m_regs{};

template <typename RFTagType>
constexpr std::size_t Y86Registers<RFTagType>::tag2index(RFTag rf_tag)
{
    // clang-format off
    switch (rf_tag) {
        case RFTag::RAX: return  0;
        case RFTag::RCX: return  1;
        case RFTag::RDX: return  2;
        case RFTag::RBX: return  3;
        case RFTag::RSP: return  4;
        case RFTag::RBP: return  5;
        case RFTag::RSI: return  6;
        case RFTag::RDI: return  7;
        case RFTag::R8 : return  8;
        case RFTag::R9 : return  9;
        case RFTag::R10: return 10;
        case RFTag::R11: return 11;
        case RFTag::R12: return 12;
        case RFTag::R13: return 13;
        case RFTag::R14: return 14;
        case RFTag::F  : [[fallthrough]];
        default:         return 15;
    }
    // clang-format on
}

template <typename RFTagType>
constexpr typename Y86Registers<RFTagType>::RFTag Y86Registers<RFTagType>::index2tag(std::size_t index)
{
    // clang-format off
    switch (index) {
        case  0: return RFTag::RAX;
        case  1: return RFTag::RCX;
        case  2: return RFTag::RDX;
        case  3: return RFTag::RBX;
        case  4: return RFTag::RSP;
        case  5: return RFTag::RBP;
        case  6: return RFTag::RSI;
        case  7: return RFTag::RDI;
        case  8: return RFTag::R8;
        case  9: return RFTag::R9;
        case 10: return RFTag::R10;
        case 11: return RFTag::R11;
        case 12: return RFTag::R12;
        case 13: return RFTag::R13;
        case 14: return RFTag::R14;
        case 15: [[fallthrough]];
        default: return RFTag::F;
    }
    // clang-format on
}

template <typename RFTagType>
uint64_t Y86Registers<RFTagType>::read(RFTag rf_tag)
{
    return m_regs[tag2index(rf_tag)];
}

template <typename RFTagType>
void Y86Registers<RFTagType>::write(RFTag rf_tag, uint64_t value)
{
    m_regs[tag2index(rf_tag)] = value;
}

template <typename RFTagType>
void Y86Registers<RFTagType>::Y86Registers::clear()
{
    m_regs.fill(0);
}

template <typename RFTagType>
void Y86Registers<RFTagType>::clear(RFTag rf_tag)
{
    m_regs[tag2index(rf_tag)] = 0;
}

template <typename RFTagType>
void Y86Registers<RFTagType>::show()
{
    // clang-format on
    std::cout << "Y86Registers:\n"
              << std::format("rax 0x{:016x}\t{}\n"
                             "rcx 0x{:016x}\t{}\n"
                             "rdx 0x{:016x}\t{}\n"
                             "rbx 0x{:016x}\t{}\n"
                             "rsp 0x{:016x}\t{}\n"
                             "rbp 0x{:016x}\t{}\n"
                             "rsi 0x{:016x}\t{}\n"
                             "rdi 0x{:016x}\t{}\n"
                             "r8  0x{:016x}\t{}\n"
                             "r9  0x{:016x}\t{}\n"
                             "r10 0x{:016x}\t{}\n"
                             "r11 0x{:016x}\t{}\n"
                             "r12 0x{:016x}\t{}\n"
                             "r13 0x{:016x}\t{}\n"
                             "r14 0x{:016x}\t{}\n\n",
                             m_regs[0], m_regs[0],
                             m_regs[1], m_regs[1],
                             m_regs[2], m_regs[2],
                             m_regs[3], m_regs[3],
                             m_regs[4], m_regs[4],
                             m_regs[5], m_regs[5],
                             m_regs[6], m_regs[6],
                             m_regs[7], m_regs[7],
                             m_regs[8], m_regs[8],
                             m_regs[9], m_regs[9],
                             m_regs[10], m_regs[10],
                             m_regs[11], m_regs[11],
                             m_regs[12], m_regs[12],
                             m_regs[13], m_regs[13],
                             m_regs[14], m_regs[14]);
    // clang-format on
}

#endif  //Y86_64_REGISTERS_IPP
