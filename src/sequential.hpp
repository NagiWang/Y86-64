#ifndef Y86_64_SEQUENTIAL_HPP
#define Y86_64_SEQUENTIAL_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif  // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "condition_codes.hpp"
#include "dmemory.hpp"
#include "program_counter.hpp"
#include "registers.hpp"

//* Sequential Y86-64 Implementation
template <typename RegistersType      = Y86Registers,
          typename ConditionCodesType = Y86CC,
          typename StatusType         = Y86Status,
          typename PCType             = Y86PC,
          typename DMemoryType        = Y86DMemory<>>
struct Y86SEQ {
    using Registers = RegistersType;
    using RFTag     = typename RegistersType::Tag;
    using CC        = ConditionCodesType;
    using Status    = StatusType;
    using StatusTag = typename StatusType::Tag;
    using PC        = PCType;
    using DMemory   = DMemoryType;
    // clang-format off
    enum class OP { ADD, SUB, AND, XOR };
    // clang-format on
    static RFTag rA;
    static RFTag rB;

    static uint64_t valA;
    static uint64_t valB;
    static uint64_t valC;
    static uint64_t valE;
    static uint64_t valM;
    static uint64_t valP;

    static bool Cnd;

    static uint64_t ALU(OP op);

    // clang-format off
    constexpr Y86SEQ(const Y86SEQ&)            = delete;
    constexpr Y86SEQ(Y86SEQ&&)                 = delete;
    constexpr Y86SEQ& operator=(const Y86SEQ&) = delete;
    constexpr Y86SEQ& operator=(Y86SEQ&&)      = delete;
    // clang-format on

private:
    constexpr Y86SEQ() = default;
};

#include "impl/sequential.ipp"

#endif  //Y86_64_SEQUENTIAL_HPP
