#ifndef Y86_64_SEQ_REG_HPP
#define Y86_64_SEQ_REG_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif  // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "headers.hpp"
#include "seq_cc.hpp"

struct SeqY86Registers {
    // clang-format off
    constexpr SeqY86Registers(const SeqY86Registers&)            = delete;
    constexpr SeqY86Registers(SeqY86Registers&&)                 = delete;
    constexpr SeqY86Registers& operator=(const SeqY86Registers&) = delete;
    constexpr SeqY86Registers& operator=(SeqY86Registers&&)      = delete;
    // clang-format on

    //* SeqY86Registers value
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
    enum class Tag
    {
        // clang-format off
        RAX,    RCX,    RDX,    RBX,
        RSP,    RBP,    RSI,    RDI,
        R8 ,    R9 ,    R10,    R11,
        R12,    R13,    R14,    F
        // clang-format on
    };

    static constexpr std::size_t tag2index(Tag rf_tag);
    static std::uint8_t tag2code(const std::string& rf_tag);
    static constexpr Tag index2tag(std::size_t index);

    static uint64_t read(Tag rf_tag);
    static void write(Tag rf_tag, uint64_t value);

    static void clear();
    static void clear(Tag rf_tag);
    static void show();

protected:
    constexpr SeqY86Registers() = default;

private:
    static std::array<uint64_t, 16> m_regs;
    static const std::unordered_map<std::string, std::uint8_t> m_tagmap;
};

#include "impl/seq_reg.ipp"

#endif  //Y86_64_SEQ_REG_HPP
