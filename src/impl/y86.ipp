#ifndef Y86_64_Y86_IPP
#define Y86_64_Y86_IPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif  // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "../y86.hpp"

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

#endif  //Y86_64_Y86_IPP
