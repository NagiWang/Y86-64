#ifndef Y86_64_RUNNER_IPP
#define Y86_64_RUNNER_IPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif  // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "runner.hpp"

// clang-format off
template <typename SEQType> uint8_t Y86Runner<SEQType>::icode = 0;
template <typename SEQType> uint8_t Y86Runner<SEQType>::ifun  = 0;
// clang-format on

template <typename SEQType>
void Y86Runner<SEQType>::fetch()
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
void Y86Runner<SEQType>::stepi(bool debug)
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
void Y86Runner<SEQType>::execute(bool debug)
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

#endif  //Y86_64_RUNNER_IPP
