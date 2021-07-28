#ifndef Y86_64_CONDITION_CODES_HPP
#define Y86_64_CONDITION_CODES_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif  // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "headers.hpp"

//* Condition Codes
struct Y86CC {
    // clang-format off
    constexpr Y86CC(const Y86CC&)            = delete;
    constexpr Y86CC(Y86CC&&)                 = delete;
    constexpr Y86CC& operator=(const Y86CC&) = delete;
    constexpr Y86CC& operator=(Y86CC&&)      = delete;
    // clang-format on

    static bool ZF, SF, OF;

    static void clear();
    static void show();

protected:
    constexpr Y86CC() = default;
};

#include "impl/condition_codes.ipp"

#endif  //Y86_64_CONDITION_CODES_HPP
