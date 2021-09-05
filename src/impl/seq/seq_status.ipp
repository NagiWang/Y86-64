#ifndef Y86_64_SEQ_STATUS_IPP
#define Y86_64_SEQ_STATUS_IPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif  // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "seq/seq_status.hpp"

SeqY86Status::Tag SeqY86Status::value = SeqY86Status::Tag::AOK;

std::string SeqY86Status::tag2string(Tag status_tag)
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

void SeqY86Status::show()
{
    std::cout << std::format("Status: {}\n\n", SeqY86Status::tag2string(SeqY86Status::value));
}

#endif  //Y86_64_SEQ_STATUS_IPP
