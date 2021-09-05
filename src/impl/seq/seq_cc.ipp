#ifndef Y86_64_SEQ_CC_IPP
#define Y86_64_SEQ_CC_IPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif  // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "../seq_cc.hpp"

//***************************** SeqY86CC ********************************

// clang-format off
bool SeqY86CC::ZF = false;
bool SeqY86CC::SF = false;
bool SeqY86CC::OF = false;
// clang-format on

void SeqY86CC::clear()
{
    SeqY86CC::ZF = false;
    SeqY86CC::SF = false;
    SeqY86CC::OF = false;
}

void SeqY86CC::show()
{
    std::cout << "Condition Code:\n"
              << std::format("ZF {:01b}\tSF {:01b}\tOF {:01b}\n\n",
                             SeqY86CC::ZF,
                             SeqY86CC::SF,
                             SeqY86CC::OF);
}

#endif  //Y86_64_SEQ_CC_IPP
