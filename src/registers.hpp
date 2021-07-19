#pragma once

#include <headers.hpp>

// clang-format off

//* Registers
enum class RFtag
{
    RAX,    RBX,    RCX,    RDX,
    RSP,    RBP,    RDI,    RSI,
    R8 ,    R9 ,    R10,    R11,
    R12,    R13,    R14
};

//* Condition Codes
struct CCtag {
    constexpr CCtag(uint8_t value = 0) : m_value(value)
    {
        static_assert(value < 8, "Please use a combination of {ZF, SF, OF} for initialization!");
    }
    
    CCtag operator|(const CCtag& other)
    {
        if (this == &other) return *this;
        return CCtag(m_value | other.m_value);
    }

    CCtag& operator|=(const CCtag& other)
    {
        if (this != &other) this->m_value |= other.m_value;
        return *this;
    }

    CCtag operator&(const CCtag& other)
    {
        if (this == &other) return *this;
        return CCtag(m_value & other.m_value);
    }

    CCtag& operator&=(const CCtag& other)
    {
        if (this != &other) this->m_value &= other.m_value;
        return *this;
    }
    operator bool() const{ return m_value; }

    friend CCtag operator~(const CCtag& other)
    {
        return CCtag(~other.m_value & other.m_value);
    }

private:
    uint8_t m_value = 0;
};
// clang-format on
constexpr CCtag ZF{0x1};  // 0 0 1
constexpr CCtag SF{0x2};  // 0 1 0
constexpr CCtag OF{0x4};  // 1 0 0

class Registers
{
public:
    // clang-format off
    Registers(const Registers&)            = delete;
    Registers(Registers&&)                 = delete;
    Registers& operator=(const Registers&) = delete;
    Registers& operator=(Registers&&)      = delete;
    // clang-format on

    static Registers& getInstance()
    {
        static std::unique_ptr<Registers> registers{new Registers()};
        return *registers;
    }

    const uint64_t& get(RFtag reg) const;
    uint64_t& get(RFtag reg);
    void set(RFtag reg, uint64_t value);
    void clear();
    void show() const;

protected:
    Registers() = default;

private:
    std::array<uint64_t, 15> m_registers;
};

class ConditionCodes
{
public:
    // clang-format off
    ConditionCodes(const ConditionCodes&)            = delete;
    ConditionCodes(ConditionCodes&&)                 = delete;
    ConditionCodes& operator=(const ConditionCodes&) = delete;
    ConditionCodes& operator=(ConditionCodes&&)      = delete;
    // clang-format on

    static ConditionCodes& getInstance()
    {
        static std::unique_ptr<ConditionCodes> cc{new ConditionCodes()};
        return *cc;
    }

    const CCtag& get(const CCtag& tag) const { return m_cc & tag.m_cc; }
    CCtag& get(const CCtag& tag) { return const_cast<CCtag&>(std::as_const(this)->get(tag)); }
    void set(const CCtag& tag) { m_cc |= tag; }
    void clear() { m_cc = ~ZF | ~SF | ~OF; }
    void show() const
    {
        std::cout << "Condition Code:\n"
                  << std::format("ZF {}\tSF {}\tOF {}\n\n",
                                 static_cast<bool>(m_cc & ZF),
                                 static_cast<bool>(m_cc & SF),
                                 static_cast<bool>(m_cc & OF));
    }

protected:
    ConditionCodes() = default;

private:
    CCtag m_cc;
};

// clang-format off
const uint64_t& Registers::get(RFtag reg) const 
{
    switch (reg) {
        case RFtag::RAX: return m_registers[ 0];
        case RFtag::RBX: return m_registers[ 1];
        case RFtag::RCX: return m_registers[ 2];
        case RFtag::RDX: return m_registers[ 3];
        case RFtag::RSP: return m_registers[ 4];
        case RFtag::RBP: return m_registers[ 5];
        case RFtag::RDI: return m_registers[ 6];
        case RFtag::RSI: return m_registers[ 7];
        case RFtag::R8 : return m_registers[ 8];
        case RFtag::R9 : return m_registers[ 9];
        case RFtag::R10: return m_registers[10];
        case RFtag::R11: return m_registers[11];
        case RFtag::R12: return m_registers[12];
        case RFtag::R13: return m_registers[13];
        case RFtag::R14: return m_registers[14];
    }
}
// clang-format on

uint64_t& Registers::get(RFtag reg)
{
    return const_cast<uint64_t&>(static_cast<const Register*>(this)->get(reg));
}

void Registers::set(RFtag reg, uint64_t value)
{
    this->get(reg) = std::move(value);
}

void Registers::clear()
{
    m_registers.fill(0);
}

void Registers::show()
{
    std::cout << "Registers:\n"
              << std::format("rax {}\trbx {}\trcx {}\trdx {}\n"
                             "rsp {}\trbp {}\trdi {}\trsi {}\n"
                             "r8  {}\tr9  {}\tr10 {}\tr11 {}\n"
                             "r12 {}\tr13 {}\tr14 {}\n\n",
                             m_registers[0],
                             m_registers[1],
                             m_registers[2],
                             m_registers[3],
                             m_registers[4],
                             m_registers[5],
                             m_registers[6],
                             m_registers[7],
                             m_registers[8],
                             m_registers[9],
                             m_registers[10],
                             m_registers[11],
                             m_registers[12],
                             m_registers[13],
                             m_registers[14]);
}
