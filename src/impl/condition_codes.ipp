#ifndef Y86_64_CONDITION_CODES_IPP
#define Y86_64_CONDITION_CODES_IPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif  // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "../condition_codes.hpp"

//***************************** Y86ConditionCodes ********************************

// clang-format off
bool Y86ConditionCodes::ZF = false;
bool Y86ConditionCodes::SF = false;
bool Y86ConditionCodes::OF = false;
// clang-format on

void Y86ConditionCodes::clear()
{
    Y86ConditionCodes::ZF = false;
    Y86ConditionCodes::SF = false;
    Y86ConditionCodes::OF = false;
}

void Y86ConditionCodes::show()
{
    std::cout << "Condition Code:\n"
              << std::format("ZF {:01b}\tSF {:01b}\tOF {:01b}\n\n",
                             Y86ConditionCodes::ZF,
                             Y86ConditionCodes::SF,
                             Y86ConditionCodes::OF);
}

#endif  //Y86_64_CONDITION_CODES_IPP
