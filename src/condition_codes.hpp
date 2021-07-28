#ifndef Y86_64_CONDITION_CODES_HPP
#define Y86_64_CONDITION_CODES_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif  // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "headers.hpp"

//* Condition Codes value



struct Y86ConditionCodes {
    // clang-format off
    constexpr Y86ConditionCodes(const Y86ConditionCodes&)            = delete;
    constexpr Y86ConditionCodes(Y86ConditionCodes&&)                 = delete;
    constexpr Y86ConditionCodes& operator=(const Y86ConditionCodes&) = delete;
    constexpr Y86ConditionCodes& operator=(Y86ConditionCodes&&)      = delete;
    // clang-format on

    static bool ZF, SF, OF;

    static void clear();
    static void show();

protected:
    constexpr Y86ConditionCodes() = default;
};

#include "impl/condition_codes.ipp"

#endif  //Y86_64_CONDITION_CODES_HPP
