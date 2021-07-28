#ifndef Y86_64_DMEMORY_HPP
#define Y86_64_DMEMORY_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif  // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "headers.hpp"

#include "status.hpp"

template <std::size_t DMemorySize = 0x10000,
          typename StatusType     = Y86Status<>>
struct Y86DMemory {
    static constexpr std::size_t DMemSize = DMemorySize;
    using Status                          = StatusType;
    using StatusTag                       = typename StatusType::StatusTag;
    // clang-format off
    constexpr Y86DMemory(const Y86DMemory&)            = delete;
    constexpr Y86DMemory(Y86DMemory&&)                 = delete;
    constexpr Y86DMemory& operator=(const Y86DMemory&) = delete;
    constexpr Y86DMemory& operator=(Y86DMemory&&)      = delete;
    // clang-format on

    static uint64_t readq(std::size_t address);
    static void writeq(size_t address, uint64_t value);
    static uint8_t readb(std::size_t address);
    static void writeb(size_t address, uint8_t value);
    static std::vector<uint8_t> read_seq(std::size_t address, std::size_t count);
    static void write_seq(size_t address, std::vector<uint8_t> values);

    static void show(std::size_t address = 0, std::size_t count = DMemSize);

protected:
    constexpr Y86DMemory() = default;

private:
    static std::array<uint8_t, DMemSize> m_dmem;
};

#include "impl/dmemory.ipp"

#endif  //Y86_64_DMEMORY_HPP
