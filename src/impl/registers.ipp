#ifndef Y86_64_REGISTERS_IPP
#define Y86_64_REGISTERS_IPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif  // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "../registers.hpp"

//***************************** Y86Registers ********************************

std::array<uint64_t, 16> Y86Registers::m_regs{};

constexpr std::size_t Y86Registers::tag2index(Tag rf_tag)
{
    // clang-format off
    switch (rf_tag) {
        case Tag::RAX: return  0;
        case Tag::RCX: return  1;
        case Tag::RDX: return  2;
        case Tag::RBX: return  3;
        case Tag::RSP: return  4;
        case Tag::RBP: return  5;
        case Tag::RSI: return  6;
        case Tag::RDI: return  7;
        case Tag::R8 : return  8;
        case Tag::R9 : return  9;
        case Tag::R10: return 10;
        case Tag::R11: return 11;
        case Tag::R12: return 12;
        case Tag::R13: return 13;
        case Tag::R14: return 14;
        case Tag::F  : [[fallthrough]];
        default:         return 15;
    }
    // clang-format on
}

constexpr typename Y86Registers::Tag Y86Registers::index2tag(std::size_t index)
{
    // clang-format off
    switch (index) {
        case  0: return Tag::RAX;
        case  1: return Tag::RCX;
        case  2: return Tag::RDX;
        case  3: return Tag::RBX;
        case  4: return Tag::RSP;
        case  5: return Tag::RBP;
        case  6: return Tag::RSI;
        case  7: return Tag::RDI;
        case  8: return Tag::R8;
        case  9: return Tag::R9;
        case 10: return Tag::R10;
        case 11: return Tag::R11;
        case 12: return Tag::R12;
        case 13: return Tag::R13;
        case 14: return Tag::R14;
        case 15: [[fallthrough]];
        default: return Tag::F;
    }
    // clang-format on
}

uint64_t Y86Registers::read(Tag rf_tag)
{
    return m_regs[tag2index(rf_tag)];
}

void Y86Registers::write(Tag rf_tag, uint64_t value)
{
    m_regs[tag2index(rf_tag)] = value;
}

void Y86Registers::Y86Registers::clear()
{
    m_regs.fill(0);
}

void Y86Registers::clear(Tag rf_tag)
{
    m_regs[tag2index(rf_tag)] = 0;
}

void Y86Registers::show()
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
