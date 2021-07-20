#ifndef Y86_64_Y86_HPP
#define Y86_64_Y86_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif  // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "headers.hpp"

#include "CC.hpp"
#include "DMemory.hpp"
#include "PC.hpp"
#include "Registers.hpp"

template <typename RegistersType      = Y86Registers<>,
          typename ConditionCodesType = Y86ConditionCodes<>>
struct Y86 {
    using Registers = RegistersType;
    using RFTag     = Registers::RFTag;
    using CC        = ConditionCodesType;
    using CCTag     = CC::CCTag;
};

#endif  //Y86_64_Y86_HPP
