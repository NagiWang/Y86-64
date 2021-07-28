#ifndef Y86_64_CONDITION_CODES_IPP
#define Y86_64_CONDITION_CODES_IPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif  // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "../condition_codes.hpp"

//***************************** Y86CC ********************************

// clang-format off
bool Y86CC::ZF = false;
bool Y86CC::SF = false;
bool Y86CC::OF = false;
// clang-format on

void Y86CC::clear()
{
    Y86CC::ZF = false;
    Y86CC::SF = false;
    Y86CC::OF = false;
}

void Y86CC::show()
{
    std::cout << "Condition Code:\n"
              << std::format("ZF {:01b}\tSF {:01b}\tOF {:01b}\n\n",
                             Y86CC::ZF,
                             Y86CC::SF,
                             Y86CC::OF);
}

#endif  //Y86_64_CONDITION_CODES_IPP
