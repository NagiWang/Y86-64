#ifndef Y86_64_Y86_HPP
#define Y86_64_Y86_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif  // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "headers.hpp"

#include "sequential.hpp"

template <typename SEQType = Y86SEQ<>>
struct InstructionBase {
    using SEQ = SEQType;
};

struct HALT : public InstructionBase<> {
    static void execute();
};

struct NOP : public InstructionBase<> {
    static void execute();
};

//* Move: Register -> Register

struct RRMOVQ : public InstructionBase<> {
    static void execute();
};

//* Move: if (condition) the Register -> Register
struct CMOVLE : public InstructionBase<> {
    static void execute();
};

struct CMOVL : public InstructionBase<> {
    static void execute();
};

struct CMOVE : public InstructionBase<> {
    static void execute();
};

struct CMOVNE : public InstructionBase<> {
    static void execute();
};

struct CMOVGE : public InstructionBase<> {
    static void execute();
};

struct CMOVG : public InstructionBase<> {
    static void execute();
};

//* Move: Imm -> Register
struct IRMOVQ : public InstructionBase<> {
    static void execute();
};

//* Move:  Register(A) -> DMemory[ Register(B) + $Imm ]
struct RMMOVQ : public InstructionBase<> {
    static void execute();
};

//* Move:  DMemory[ Register(B) + $Imm ] -> Register(A)
struct MRMOVQ : public InstructionBase<> {
    static void execute();
};

//* Operators: Register(A) op Register(B) -> Register(B)

struct ADDQ : public InstructionBase<> {
    static void execute();
};

struct SUBQ : public InstructionBase<> {
    static void execute();
};

struct ANDQ : public InstructionBase<> {
    static void execute();
};

struct XORQ : public InstructionBase<> {
    static void execute();
};

//* Jump
struct JMP : public InstructionBase<> {
    static void execute();
};

struct JLE : public InstructionBase<> {
    static void execute();
};

struct JL : public InstructionBase<> {
    static void execute();
};

struct JE : public InstructionBase<> {
    static void execute();
};

struct JNE : public InstructionBase<> {
    static void execute();
};

struct JGE : public InstructionBase<> {
    static void execute();
};

struct JG : public InstructionBase<> {
    static void execute();
};

struct CALL : public InstructionBase<> {
    static void execute();
};

struct RET : public InstructionBase<> {
    static void execute();
};

struct PUSHQ : public InstructionBase<> {
    static void execute();
};

struct POPQ : public InstructionBase<> {
    static void execute();
};

#include "impl/y86.ipp"

#endif  //Y86_64_Y86_HPP
