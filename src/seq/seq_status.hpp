#ifndef Y86_64_SEQ_STATUS_HPP
#define Y86_64_SEQ_STATUS_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif  // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "headers.hpp"

struct SeqY86Status {
    // clang-format off
    constexpr SeqY86Status(const SeqY86Status&)            = delete;
    constexpr SeqY86Status(SeqY86Status&&)                 = delete;
    constexpr SeqY86Status& operator=(const SeqY86Status&) = delete;
    constexpr SeqY86Status& operator=(SeqY86Status&&)      = delete;

    enum class Tag { AOK, HLT, ADR, INS };
    // clang-format on

    static Tag value;

    static std::string tag2string(Tag status_tag);
    static void show();

protected:
    constexpr SeqY86Status() = default;
};

#include "impl/seq_status.ipp"

#endif  //Y86_64_SEQ_STATUS_HPP
