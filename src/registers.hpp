#ifndef Y86_64_REGISTERS_HPP
#define Y86_64_REGISTERS_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif  // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "condition_codes.hpp"
#include "headers.hpp"

//* Y86Registers value
//* %rax  0    %r8   8
//* %rcx  1    %r9   9
//* %rdx  2    %r10  A
//* %rbx  3    %r11  B
//* %rsp  4    %r12  C
//* %rbp  5    %r13  D
//* %rsi  6    %r14  E
//* %rdi  7          F
//* Register ID 15 (0xF) indicates “no register”
//* This will be used in the hardware design
enum class Y86RFTag
{
    // clang-format off
    RAX,    RCX,    RDX,    RBX,
    RSP,    RBP,    RSI,    RDI,
    R8 ,    R9 ,    R10,    R11,
    R12,    R13,    R14,    F
    // clang-format on
};

template <typename RFTagType = Y86RFTag>
struct Y86Registers {
    using RFTag = RFTagType;
    // clang-format off
    constexpr Y86Registers(const Y86Registers&)            = delete;
    constexpr Y86Registers(Y86Registers&&)                 = delete;
    constexpr Y86Registers& operator=(const Y86Registers&) = delete;
    constexpr Y86Registers& operator=(Y86Registers&&)      = delete;
    // clang-format on

    static constexpr std::size_t tag2index(RFTag rf_tag);
    static constexpr RFTag index2tag(std::size_t index);

    static uint64_t read(RFTag rf_tag);
    static void write(RFTag rf_tag, uint64_t value);

    static void clear();
    static void clear(RFTag rf_tag);
    static void show();

protected:
    constexpr Y86Registers() = default;

private:
    static std::array<uint64_t, 16> m_regs;
};

#include "impl/registers.ipp"

#endif  //Y86_64_REGISTERS_HPP
