#ifndef Y86_64_STATUS_IPP
#define Y86_64_STATUS_IPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif  // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "../status.hpp"

template <typename StatusTagType>
std::string Y86Status<StatusTagType>::StatusTag2String(StatusTag status_tag)
{
    // clang-format off
    switch (status_tag) {
        case StatusTag::AOK: return "AOK";
        case StatusTag::HLT: return "HLT";
        case StatusTag::ADR: return "ADR";
        case StatusTag::INS: return "INS";
        default:             return "AOK";
    }
    // clang-format on
}

template <typename StatusTagType>
void Y86Status<StatusTagType>::show()
{
    std::cout << std::format("Status: {}\n\n", Y86Status<>::StatusTag2String(Y86Status::value));
}

#endif  //Y86_64_STATUS_IPP
