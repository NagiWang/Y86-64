#ifndef Y86_64_SEQ_HPP
#define Y86_64_SEQ_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif  // defined(_MSC_VER) && (_MSC_VER >= 1200)


#include "seq_cc.hpp"
#include "seq_dmem.hpp"
#include "seq_pc.hpp"
#include "seq_reg.hpp"

//* Sequential Y86-64 Implementation
template <typename RegistersType      = SeqY86Registers,
          typename ConditionCodesType = SeqY86CC,
          typename StatusType         = SeqY86Status,
          typename PCType             = SeqY86PC,
          typename DMemoryType        = Y86DMemory<>>
struct SeqY86 {
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
    constexpr SeqY86(const SeqY86&)            = delete;
    constexpr SeqY86(SeqY86&&)                 = delete;
    constexpr SeqY86& operator=(const SeqY86&) = delete;
    constexpr SeqY86& operator=(SeqY86&&)      = delete;
    // clang-format on

private:
    constexpr SeqY86() = default;
};

template <typename SEQType = SeqY86<>>
struct SeqY86Runner {
    using SEQ = SEQType;

    static void fetch();
    static void stepi(bool debug = true);
    static void execute(bool debug = true);

    static uint8_t icode;
    static uint8_t ifun;
};

template <typename SEQType = SeqY86<>>
struct SeqInsBase {
    using SEQ = SEQType;
};

struct HALT : public SeqInsBase<> {
    static void execute();
};

struct NOP : public SeqInsBase<> {
    static void execute();
};

//* Move: Register -> Register

struct RRMOVQ : public SeqInsBase<> {
    static void execute();
};

//* Move: if (condition) the Register -> Register
struct CMOVLE : public SeqInsBase<> {
    static void execute();
};

struct CMOVL : public SeqInsBase<> {
    static void execute();
};

struct CMOVE : public SeqInsBase<> {
    static void execute();
};

struct CMOVNE : public SeqInsBase<> {
    static void execute();
};

struct CMOVGE : public SeqInsBase<> {
    static void execute();
};

struct CMOVG : public SeqInsBase<> {
    static void execute();
};

//* Move: Imm -> Register
struct IRMOVQ : public SeqInsBase<> {
    static void execute();
};

//* Move:  Register(A) -> DMemory[ Register(B) + $Imm ]
struct RMMOVQ : public SeqInsBase<> {
    static void execute();
};

//* Move:  DMemory[ Register(B) + $Imm ] -> Register(A)
struct MRMOVQ : public SeqInsBase<> {
    static void execute();
};

//* Operators: Register(A) op Register(B) -> Register(B)

struct ADDQ : public SeqInsBase<> {
    static void execute();
};

struct SUBQ : public SeqInsBase<> {
    static void execute();
};

struct ANDQ : public SeqInsBase<> {
    static void execute();
};

struct XORQ : public SeqInsBase<> {
    static void execute();
};

//* Jump
struct JMP : public SeqInsBase<> {
    static void execute();
};

struct JLE : public SeqInsBase<> {
    static void execute();
};

struct JL : public SeqInsBase<> {
    static void execute();
};

struct JE : public SeqInsBase<> {
    static void execute();
};

struct JNE : public SeqInsBase<> {
    static void execute();
};

struct JGE : public SeqInsBase<> {
    static void execute();
};

struct JG : public SeqInsBase<> {
    static void execute();
};

struct CALL : public SeqInsBase<> {
    static void execute();
};

struct RET : public SeqInsBase<> {
    static void execute();
};

struct PUSHQ : public SeqInsBase<> {
    static void execute();
};

struct POPQ : public SeqInsBase<> {
    static void execute();
};

#include "impl/seq/seq_runner.ipp"

#endif  //Y86_64_SEQ_HPP
