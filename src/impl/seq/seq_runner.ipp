#ifndef Y86_64_SEQ_IPP
#define Y86_64_SEQ_IPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif  // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "../seq_runner.hpp"

// clang-format off
template <> SeqY86<>::RFTag SeqY86<>::rA = SeqY86<>::RFTag::F;
template <> SeqY86<>::RFTag SeqY86<>::rB = SeqY86<>::RFTag::F;

template <> uint64_t SeqY86<>::valA = 0x0;
template <> uint64_t SeqY86<>::valB = 0x0;
template <> uint64_t SeqY86<>::valC = 0x0;
template <> uint64_t SeqY86<>::valE = 0x0;
template <> uint64_t SeqY86<>::valM = 0x0;
template <> uint64_t SeqY86<>::valP = 0x0;

template <> bool SeqY86<>::Cnd = true;
// clang-format on

template <typename RegistersType,
          typename ConditionCodesType,
          typename StatusType,
          typename PCType,
          typename DMemoryType>
uint64_t SeqY86<RegistersType, ConditionCodesType, StatusType, PCType, DMemoryType>::ALU(SeqY86::OP op)
{
    CC::clear();

    uint64_t result = 0;

    // clang-format off
    switch (op) {
        case OP::ADD: result = SeqY86::valB + SeqY86::valA; break;
        case OP::SUB: result = SeqY86::valB - SeqY86::valA; break;
        case OP::AND: result = SeqY86::valB & SeqY86::valA; break;
        case OP::XOR: [[fallthrough]];
        default:      result = SeqY86::valB ^ SeqY86::valA;
    }

    int64_t n_result = static_cast<int64_t>(result) & 0xffffffffll;

    if (n_result == 0)      CC::ZF = true;
    if (n_result <  0)      CC::SF = true;
    if (n_result != result) CC::OF = true;
    // clang-format on

    return result;
}

// clang-format off
template <typename SEQType> uint8_t SeqY86Runner<SEQType>::icode = 0;
template <typename SEQType> uint8_t SeqY86Runner<SEQType>::ifun  = 0;
// clang-format on

template <typename SEQType>
void SeqY86Runner<SEQType>::fetch()
{
    icode = SEQ::DMemory::readb(SEQ::PC::value);
    ifun  = icode & 0xf;
    icode >>= 4;

    uint8_t irA = SEQ::DMemory::readb(SEQ::PC::value + 1);
    uint8_t irB = irA & 0xf;
    irA >>= 4;

    SEQ::rA = SEQ::Registers::index2tag(irA);
    SEQ::rB = SEQ::Registers::index2tag(irB);
}

template <typename SEQType>
void SeqY86Runner<SEQType>::stepi(bool debug)
{
    if (debug) {
        SEQ::Registers::show();
        SEQ::PC::show();
        SEQ::CC::show();
        SEQ::Status::show();
    }

    fetch();

    // clang-format off
    switch (icode) {
        case 0:
            SEQ::valP = SEQ::PC::value + 1;
            HALT::execute();
            break;
        case 1:
            SEQ::valP = SEQ::PC::value + 1;
            NOP::execute();
            break;
        case 2:
            SEQ::valP = SEQ::PC::value + 2;
            switch (ifun) {
                case 0: RRMOVQ::execute(); break;
                case 1: CMOVLE::execute(); break;
                case 2: CMOVL ::execute(); break;
                case 3: CMOVE ::execute(); break;
                case 4: CMOVNE::execute(); break;
                case 5: CMOVGE::execute(); break;
                case 6: CMOVG ::execute(); break;
                default: SEQ::Status::value = SEQ::StatusTag::INS;
            }
            break;
        case 3:
            SEQ::valC = SEQ::DMemory::readq(SEQ::PC::value + 2);
            SEQ::valP = SEQ::PC::value + 10;
            IRMOVQ::execute();
            break;
        case 4:
            SEQ::valC = SEQ::DMemory::readq(SEQ::PC::value + 2);
            SEQ::valP = SEQ::PC::value + 10;
            RMMOVQ::execute();
            break;
        case 5:
            SEQ::valC = SEQ::DMemory::readq(SEQ::PC::value + 2);
            SEQ::valP = SEQ::PC::value + 10;
            MRMOVQ::execute();
            break;
        case 6:
            SEQ::valP = SEQ::PC::value + 2;
            switch (ifun) {
                case 0: ADDQ::execute(); break;
                case 1: SUBQ::execute(); break;
                case 2: ANDQ::execute(); break;
                case 3: XORQ::execute(); break;
                default: SEQ::Status::value = SEQ::StatusTag::INS;
            }
            break;
        case 7:
            SEQ::valC = SEQ::DMemory::readq(SEQ::PC::value + 1);
            SEQ::valP = SEQ::PC::value + 9;
            switch (ifun) {
                case 0: JMP::execute(); break;
                case 1: JLE::execute(); break;
                case 2: JL ::execute(); break;
                case 3: JE ::execute(); break;
                case 4: JNE::execute(); break;
                case 5: JGE::execute(); break;
                case 6: JG ::execute(); break;
                default: SEQ::Status::value = SEQ::StatusTag::INS;
            }
            break;
        case 8:
            SEQ::valC = SEQ::DMemory::readq(SEQ::PC::value + 1);
            SEQ::valP = SEQ::PC::value + 9;
            CALL::execute();
            break;
        case 9:
            SEQ::valP = SEQ::PC::value + 1;
            RET::execute();
            break;
        case 0xA:
            SEQ::valP = SEQ::PC::value + 2;
            PUSHQ::execute();
            break;
        case 0xB:
            SEQ::valP = SEQ::PC::value + 2;
            POPQ::execute();
            break;
        default:
            SEQ::Status::value = SEQ::StatusTag::INS;
    }
    // clang-format on
}

template <typename SEQType>
void SeqY86Runner<SEQType>::execute(bool debug)
{
    std::size_t step = 0;

    while (SEQ::Status::value == SEQ::StatusTag::AOK) {
        if (debug) std::cout << std::format("\nRunning Step {}:\n\n", step++);
        stepi(debug);
    }

    if (debug) {
        std::cout << "\nTerminate program!\n\n";
        SEQ::Registers::show();
        SEQ::PC::show();
        SEQ::CC::show();
        SEQ::Status::show();
    }
}

void HALT::execute()
{
    // Decode
    // Execute
    SEQ::Status::value = SEQ::StatusTag::HLT;
    // Memory
    // Write back
    // Update PC
    SEQ::PC::value     = 0;
}

void NOP::execute()
{
    // Decode
    // Execute
    // Memory
    // Write back
    // Update PC
    SEQ::PC::value = SEQ ::valP;
}

void RRMOVQ::execute()
{
    // Decode
    SEQ::valA = SEQ::Registers::read(SEQ::rA);
    // Execute
    SEQ::valE = SEQ::valA + 0;
    // Memory
    // Write back
    SEQ::Registers::write(SEQ::rB, SEQ::valE);
    // Update PC
    SEQ::PC::value = SEQ ::valP;
}

void CMOVLE::execute()
{
    // Decode
    SEQ::valA = SEQ::Registers::read(SEQ::rA);
    // Execute
    SEQ::valE = SEQ::valA;
    SEQ::Cnd  = SEQ::CC::ZF || SEQ::CC::SF;
    // Memory
    // Write back
    if (SEQ::Cnd) SEQ::Registers::write(SEQ::rB, SEQ::valE);
    // Update PC
    SEQ::PC::value = SEQ::valP;
}

void CMOVL::execute()
{
    // Decode
    SEQ::valA = SEQ::Registers::read(SEQ::rA);
    // Execute
    SEQ::valE = SEQ::valA;
    SEQ::Cnd  = SEQ::CC::SF;
    // Memory
    // Write back
    if (SEQ::Cnd) SEQ::Registers::write(SEQ::rB, SEQ::valE);
    // Update PC
    SEQ::PC::value = SEQ::valP;
}

void CMOVE::execute()
{
    // Decode
    SEQ::valA = SEQ::Registers::read(SEQ::rA);
    // Execute
    SEQ::valE = SEQ::valA;
    SEQ::Cnd  = SEQ::CC::ZF;
    // Memory
    // Write back
    if (SEQ::Cnd) SEQ::Registers::write(SEQ::rB, SEQ::valE);
    // Update PC
    SEQ::PC::value = SEQ::valP;
}

void CMOVNE::execute()
{
    // Decode
    SEQ::valA = SEQ::Registers::read(SEQ::rA);
    // Execute
    SEQ::valE = SEQ::valA;
    SEQ::Cnd  = !SEQ::CC::ZF;
    // Memory
    // Write back
    if (SEQ::Cnd) SEQ::Registers::write(SEQ::rB, SEQ::valE);
    // Update PC
    SEQ::PC::value = SEQ::valP;
}

void CMOVGE::execute()
{
    // Decode
    SEQ::valA = SEQ::Registers::read(SEQ::rA);
    // Execute
    SEQ::valE = SEQ::valA;
    SEQ::Cnd  = SEQ::CC::ZF || !SEQ::CC::SF;
    // Memory
    // Write back
    if (SEQ::Cnd) SEQ::Registers::write(SEQ::rB, SEQ::valE);
    // Update PC
    SEQ::PC::value = SEQ::valP;
}

void CMOVG::execute()
{
    // Decode
    SEQ::valA = SEQ::Registers::read(SEQ::rA);
    // Execute
    SEQ::valE = SEQ::valA;
    SEQ::Cnd  = !SEQ::CC::SF;
    // Memory
    // Write back
    if (SEQ::Cnd) SEQ::Registers::write(SEQ::rB, SEQ::valE);
    // Update PC
    SEQ::PC::value = SEQ::valP;
}

void IRMOVQ::execute()
{
    // Decode
    // Execute
    SEQ::valE = SEQ::valC;
    // Memory
    // Write back
    SEQ::Registers::write(SEQ::rB, SEQ::valE);
    // Update PC
    SEQ::PC::value = SEQ::valP;
}

void RMMOVQ::execute()
{
    // Decode
    SEQ::valA = SEQ::Registers::read(SEQ::rA);
    SEQ::valB = SEQ::Registers::read(SEQ::rB);
    // Execute
    SEQ::valE = SEQ::valB + SEQ::valC;
    // Memory
    // Write back
    SEQ::DMemory::writeq(SEQ::valE, SEQ::valA);
    // Update PC
    SEQ::PC::value = SEQ::valP;
}

void MRMOVQ::execute()
{
    // Decode
    SEQ::valB = SEQ::Registers::read(SEQ::rB);
    // Execute
    SEQ::valE = SEQ::valB + SEQ::valC;
    // Memory
    SEQ::valM = SEQ::DMemory::readq(SEQ::valE);
    // Write back
    SEQ::Registers::write(SEQ::rA, SEQ::valM);
    // Update PC
    SEQ::PC::value = SEQ::valP;
}

void ADDQ::execute()
{
    // Decode
    SEQ::valA = SEQ::Registers::read(SEQ::rA);
    SEQ::valB = SEQ::Registers::read(SEQ::rB);
    // Execute
    SEQ::valE = SEQ::ALU(SEQ::OP::ADD);
    // Memory
    // Write back
    SEQ::Registers::write(SEQ::rB, SEQ::valE);
    // Update PC
    SEQ::PC::value = SEQ::valP;
}

void SUBQ::execute()
{
    // Decode
    SEQ::valA = SEQ::Registers::read(SEQ::rA);
    SEQ::valB = SEQ::Registers::read(SEQ::rB);
    // Execute
    SEQ::valE = SEQ::ALU(SEQ::OP::SUB);
    // Memory
    // Write back
    SEQ::Registers::write(SEQ::rB, SEQ::valE);
    // Update PC
    SEQ::PC::value = SEQ::valP;
}

void ANDQ::execute()
{
    // Decode
    SEQ::valA = SEQ::Registers::read(SEQ::rA);
    SEQ::valB = SEQ::Registers::read(SEQ::rB);
    // Execute
    SEQ::valE = SEQ::ALU(SEQ::OP::AND);
    // Memory
    // Write back
    SEQ::Registers::write(SEQ::rB, SEQ::valE);
    // Update PC
    SEQ::PC::value = SEQ::valP;
}

void XORQ::execute()
{
    // Decode
    SEQ::valA = SEQ::Registers::read(SEQ::rA);
    SEQ::valB = SEQ::Registers::read(SEQ::rB);
    // Execute
    SEQ::valE = SEQ::ALU(SEQ::OP::XOR);
    // Memory
    // Write back
    SEQ::Registers::write(SEQ::rB, SEQ::valE);
    // Update PC
    SEQ::PC::value = SEQ::valP;
}

void JMP::execute()
{
    // Decode
    // Execute
    SEQ::Cnd       = SEQ::CC::ZF || SEQ::CC::SF;
    // Memory
    // Write back
    // Update PC
    SEQ::PC::value = SEQ::valC;
}

void JLE::execute()
{
    // Decode
    // Execute
    SEQ::Cnd       = SEQ::CC::ZF || SEQ::CC::SF;
    // Memory
    // Write back
    // Update PC
    SEQ::PC::value = SEQ::Cnd ? SEQ::valC : SEQ::valP;
}

void JL::execute()
{
    // Decode
    // Execute
    SEQ::Cnd       = SEQ::CC::SF;
    // Memory
    // Write back
    // Update PC
    SEQ::PC::value = SEQ::Cnd ? SEQ::valC : SEQ::valP;
}

void JE::execute()
{
    // Decode
    // Execute
    SEQ::Cnd       = SEQ::CC::ZF;
    // Memory
    // Write back
    // Update PC
    SEQ::PC::value = SEQ::Cnd ? SEQ::valC : SEQ::valP;
}

void JNE::execute()
{
    // Decode
    // Execute
    SEQ::Cnd       = !SEQ::CC::ZF;
    // Memory
    // Write back
    // Update PC
    SEQ::PC::value = SEQ::Cnd ? SEQ::valC : SEQ::valP;
}

void JGE::execute()
{
    // Decode
    // Execute
    SEQ::Cnd       = SEQ::CC::ZF || !SEQ::CC::SF;
    // Memory
    // Write back
    // Update PC
    SEQ::PC::value = SEQ::Cnd ? SEQ::valC : SEQ::valP;
}

void JG::execute()
{
    // Decode
    // Execute
    SEQ::Cnd       = !SEQ::CC::SF;
    // Memory
    // Write back
    // Update PC
    SEQ::PC::value = SEQ::Cnd ? SEQ::valC : SEQ::valP;
}

void CALL::execute()
{
    // Decode
    SEQ::valB = SEQ::Registers::read(SEQ::RFTag::RSP);
    // Execute
    SEQ::valE = SEQ::valB - 8;
    // Memory
    SEQ::DMemory::writeq(SEQ::valE, SEQ::valP);
    // Write back
    SEQ::Registers::write(SEQ::RFTag::RSP, SEQ::valE);
    // Update PC
    SEQ::PC::value = SEQ::valC;
}

void RET::execute()
{
    // Decode
    SEQ::valA = SEQ::Registers::read(SEQ::RFTag::RSP);
    SEQ::valB = SEQ::Registers::read(SEQ::RFTag::RSP);
    // Execute
    SEQ::valE = SEQ::valB + 8;
    // Memory
    SEQ::valM = SEQ::DMemory::readq(SEQ::valA);
    // Write back
    SEQ::Registers::write(SEQ::RFTag::RSP, SEQ::valE);
    // Update PC
    SEQ::PC::value = SEQ::valM;
}

void PUSHQ::execute()
{
    // Decode
    SEQ::valA = SEQ::Registers::read(SEQ::rA);
    SEQ::valB = SEQ::Registers::read(SEQ::RFTag::RSP);
    // Execute
    SEQ::valE = SEQ::valB - 8;
    // Memory
    SEQ::DMemory::writeq(SEQ::valE, SEQ::valA);
    // Write back
    SEQ::Registers::write(SEQ::RFTag::RSP, SEQ::valE);
    // Update PC
    SEQ::PC::value = SEQ::valP;
}

void POPQ::execute()
{
    // Decode
    SEQ::valA = SEQ::Registers::read(SEQ::RFTag::RSP);
    SEQ::valB = SEQ::Registers::read(SEQ::RFTag::RSP);
    // Execute
    SEQ::valE = SEQ::valB + 8;
    // Memory
    SEQ::valM = SEQ::DMemory::readq(SEQ::valA);
    // Write back
    SEQ::Registers::write(SEQ::RFTag::RSP, SEQ::valE);
    SEQ::Registers::write(SEQ::rA, SEQ::valM);
    // Update PC
    SEQ::PC::value = SEQ::valP;
}

#endif  //Y86_64_SEQ_IPP
