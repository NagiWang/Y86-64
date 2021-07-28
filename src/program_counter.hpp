#ifndef Y86_64_PC_HPP
#define Y86_64_PC_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif  // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "headers.hpp"

struct Y86PC {
    // clang-format off
    constexpr Y86PC(const Y86PC&)            = delete;
    constexpr Y86PC(Y86PC&&)                 = delete;
    constexpr Y86PC& operator=(const Y86PC&) = delete;
    constexpr Y86PC& operator=(Y86PC&&)      = delete;
    // clang-format on

    static std::size_t value;

    static void show();

protected:
    constexpr Y86PC() = default;
};

std::size_t Y86PC::value = 0x0;

#include "impl/program_counter.ipp"

#endif  //Y86_64_PC_HPP
