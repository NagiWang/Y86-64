#ifndef Y86_64_PC_HPP
#define Y86_64_PC_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif  // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "headers.hpp"

struct SeqY86PC {
    // clang-format off
    constexpr SeqY86PC(const SeqY86PC&)            = delete;
    constexpr SeqY86PC(SeqY86PC&&)                 = delete;
    constexpr SeqY86PC& operator=(const SeqY86PC&) = delete;
    constexpr SeqY86PC& operator=(SeqY86PC&&)      = delete;
    // clang-format on

    static std::size_t value;

    static void show();

protected:
    constexpr SeqY86PC() = default;
};

std::size_t SeqY86PC::value = 0x0;

#include "impl/seq/seq_pc.ipp"

#endif  //Y86_64_PC_HPP
