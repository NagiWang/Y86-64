#ifndef Y86_64_SEQUENTIAL_IPP
#define Y86_64_SEQUENTIAL_IPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif  // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "../sequential.hpp"

// clang-format off
template <> Y86SEQ<>::RFTag Y86SEQ<>::rA = Y86SEQ<>::RFTag::F;
template <> Y86SEQ<>::RFTag Y86SEQ<>::rB = Y86SEQ<>::RFTag::F;

template <> uint64_t Y86SEQ<>::valA = 0x0;
template <> uint64_t Y86SEQ<>::valB = 0x0;
template <> uint64_t Y86SEQ<>::valC = 0x0;
template <> uint64_t Y86SEQ<>::valE = 0x0;
template <> uint64_t Y86SEQ<>::valM = 0x0;
template <> uint64_t Y86SEQ<>::valP = 0x0;

template <> bool Y86SEQ<>::Cnd = true;
// clang-format on

template <typename RegistersType,
          typename ConditionCodesType,
          typename StatusType,
          typename PCType,
          typename DMemoryType>
uint64_t Y86SEQ<RegistersType, ConditionCodesType, StatusType, PCType, DMemoryType>::ALU(Y86SEQ::OP op)
{
    CC::clear();

    uint64_t result = 0;

    // clang-format off
    switch (op) {
        case OP::ADD: result = Y86SEQ::valB + Y86SEQ::valA; break;
        case OP::SUB: result = Y86SEQ::valB - Y86SEQ::valA; break;
        case OP::AND: result = Y86SEQ::valB & Y86SEQ::valA; break;
        case OP::XOR: [[fallthrough]];
        default:      result = Y86SEQ::valB ^ Y86SEQ::valA;
    }

    int64_t n_result = static_cast<int64_t>(result) & 0xffffffffll;

    if (n_result == 0)      CC::ZF = true;
    if (n_result <  0)      CC::SF = true;
    if (n_result != result) CC::OF = true;
    // clang-format on

    return result;
}

#endif  //Y86_64_SEQUENTIAL_IPP
