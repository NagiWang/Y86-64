#ifndef Y86_64_STATUS_HPP
#define Y86_64_STATUS_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif  // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "headers.hpp"

enum class Y86StatusTag
{
    AOK,
    HLT,
    ADR,
    INS
};

template <typename StatusTagType = Y86StatusTag>
std::string StatusTag2String(const StatusTagType status_tag)
{
    // clang-format off
    switch (status_tag) {
        case StatusTagType::AOK: return "AOK";
        case StatusTagType::HLT: return "HLT";
        case StatusTagType::ADR: return "ADR";
        case StatusTagType::INS: return "INS";
        default:                 return "AOK";
    }
    // clang-format on
}

template <typename StatusTagType = Y86StatusTag>
struct Y86Status {
    using StatusTag = StatusTagType;
    // clang-format off
    constexpr Y86Status(const Y86Status&)            = delete;
    constexpr Y86Status(Y86Status&&)                 = delete;
    constexpr Y86Status& operator=(const Y86Status&) = delete;
    constexpr Y86Status& operator=(Y86Status&&)      = delete;
    // clang-format on
    static StatusTag value;

    static std::string StatusTag2String(StatusTag status_tag);
    static void show();

protected:
    constexpr Y86Status() = default;
};

template <>
typename Y86Status<>::StatusTag Y86Status<>::value = Y86Status<>::StatusTag::AOK;

#include "impl/status.ipp"

#endif  //Y86_64_STATUS_HPP
