#ifndef Y86_64_REGISTERS_HPP
#define Y86_64_REGISTERS_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif  // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "CC.hpp"
#include "headers.hpp"

//* Y86Registers Tag
enum class Y86RFTag
{
    // clang-format off
    RAX,    RBX,    RCX,    RDX,
    RSP,    RBP,    RDI,    RSI,
    R8 ,    R9 ,    R10,    R11,
    R12,    R13,    R14
    // clang-format on
};

template <typename RFTagType = Y86RFTag>
struct Y86Registers {
    using RFTag = RFTagType;
    // clang-format off
    constexpr Y86Registers(const Y86Registers&)            = delete;
    constexpr Y86Registers(Y86Registers&&)                 = delete;
    constexpr Y86Registers& operator=(const Y86Registers&) = delete;
    constexpr Y86Registers& operator=(Y86Registers&&)      = delete;
    // clang-format on

    static Y86Registers& execute()
    {
        static std::unique_ptr<Y86Registers> registers{new Y86Registers()};
        return *registers;
    }

    [[nodiscard]] const uint64_t& get(const RFTag& rf_tag) const noexcept(false);
    uint64_t& get(const RFTag& rf_tag) noexcept(false);
    void set(const RFTag& rf_tag, uint64_t value);
    void clear(const RFTag& rf_tag);
    void clear();
    void show() const;

protected:
    constexpr Y86Registers() = default;

private:
    std::array<uint64_t, 15> m_regs;
};

#include "impl/Registers.ipp"

#endif  //Y86_64_REGISTERS_HPP
