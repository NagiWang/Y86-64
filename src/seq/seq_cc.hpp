#ifndef Y86_64_SEQ_CC_HPP
#define Y86_64_SEQ_CC_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif  // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "headers.hpp"

//* Condition Codes
struct SeqY86CC {
    // clang-format off
    constexpr SeqY86CC(const SeqY86CC&)            = delete;
    constexpr SeqY86CC(SeqY86CC&&)                 = delete;
    constexpr SeqY86CC& operator=(const SeqY86CC&) = delete;
    constexpr SeqY86CC& operator=(SeqY86CC&&)      = delete;
    // clang-format on

    static bool ZF, SF, OF;

    static void clear();
    static void show();

protected:
    constexpr SeqY86CC() = default;
};

#include "impl/seq_cc.ipp"

#endif  //Y86_64_SEQ_CC_HPP
