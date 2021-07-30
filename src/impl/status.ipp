#ifndef Y86_64_STATUS_IPP
#define Y86_64_STATUS_IPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif  // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "../status.hpp"

Y86Status::Tag Y86Status::value = Y86Status::Tag::AOK;

std::string Y86Status::tag2string(Tag status_tag)
{
    // clang-format off
    switch (status_tag) {
        case Tag::AOK: return "AOK";
        case Tag::HLT: return "HLT";
        case Tag::ADR: return "ADR";
        case Tag::INS: return "INS";
        default:             return "AOK";
    }
    // clang-format on
}

void Y86Status::show()
{
    std::cout << std::format("Status: {}\n\n", Y86Status::tag2string(Y86Status::value));
}

#endif  //Y86_64_STATUS_IPP
