#ifndef Y86_64_ASM_HPP
#define Y86_64_ASM_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif  // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "headers.hpp"

#include "seq/seq_reg.hpp"

template <typename RegistersType = SeqY86Registers>
struct Processor {
    using Registers = RegistersType;
    using RFTag     = typename RegistersType::Tag;

    using FuncType = std::function<void(std::ifstream&)>;
    // static std::array<uint8_t,16> RFTag;
    static std::unordered_map<std::string, FuncType> funcmap;
    static std::vector<std::uint8_t> binary_code;

    static void halt_func(std::ifstream&);
    static void nop_func(std::ifstream&);
    static void rrmovq_func(std::ifstream& ifs);

    static std::vector<std::uint8_t> execute(std::string_view filename)
    {
        binary_code.clear();

        std::ifstream ifs{filename.data()};
        std::string ins;

        char ch;

        while (!ifs.eof()) {
            ch = ifs.peek();
            switch (ch) {
                case '\n':
                case '#': ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); break;
                case '/':
                    ifs.get();
                    switch (ifs.peek()) {
                        case '/': ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); break;
                        case '*':
                            do ifs.ignore(std::numeric_limits<std::streamsize>::max(), '*');
                            while (ifs.peek() != '/');
                            ifs.get();
                            break;
                        default:
                            throw std::runtime_error("SyntaxError: invalid syntax !\n");
                    }
                    break;
                case '\t':
                case '\f':
                case '\v':
                case '\r':
                case ' ':
                    for (ch = ifs.peek(); ch == '\t'
                                          || ch == '\f'
                                          || ch == '\v'
                                          || ch == '\r'
                                          || ch == ' ';
                         ch = ifs.peek()) { ifs.get(); }
                    break;
                default:
                    ifs >> ins;
                    if (funcmap.find(ins) != funcmap.end())
                        funcmap[ins](ifs);
            }
        }

        return binary_code;
    }
};

template <typename RegistersType>
void Processor<RegistersType>::halt_func(std::ifstream&)
{
    binary_code.emplace_back(0x00);
}

template <typename RegistersType>
void Processor<RegistersType>::nop_func(std::ifstream&)
{
    binary_code.emplace_back(0x10);
}

template <typename RegistersType>
void Processor<RegistersType>::rrmovq_func(std::ifstream& ifs)
{
    binary_code.emplace_back(0x10);
    std::string rA, rB;
    ifs >> rA >> rB;
    binary_code.emplace_back(Registers::tag2code[rA]);
    binary_code.emplace_back(Registers::tag2code[rB]);
}

template <typename RegistersType>
std::unordered_map<std::string, typename Processor<RegistersType>::FuncType> Processor<RegistersType>::funcmap{
    {"halt", Processor<RegistersType>::halt_func},
    {"nop", Processor<RegistersType>::nop_func},
    {"rrmovq", Processor<RegistersType>::rrmovq_func},
};

template <typename RegistersType>
std::vector<std::uint8_t> binary_code{};

#endif  //Y86_64_ASM_HPP
