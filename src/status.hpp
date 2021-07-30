#ifndef Y86_64_STATUS_HPP
#define Y86_64_STATUS_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif  // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "headers.hpp"

struct Y86Status {
    // clang-format off
    constexpr Y86Status(const Y86Status&)            = delete;
    constexpr Y86Status(Y86Status&&)                 = delete;
    constexpr Y86Status& operator=(const Y86Status&) = delete;
    constexpr Y86Status& operator=(Y86Status&&)      = delete;

    enum class Tag { AOK, HLT, ADR, INS };
    // clang-format on

    static Tag value;

    static std::string tag2string(Tag status_tag);
    static void show();

protected:
    constexpr Y86Status() = default;
};

#include "impl/status.ipp"

#endif  //Y86_64_STATUS_HPP
