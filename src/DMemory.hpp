#ifndef Y86_64_DMEMORY_HPP
#define Y86_64_DMEMORY_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif  // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "headers.hpp"

template <uint64_t DMemorySize = 0x10000>
struct Y86DMemory {
    static constexpr uint64_t DMemSize = DMemorySize;
    // clang-format off
    constexpr Y86DMemory(const Y86DMemory&)            = delete;
    constexpr Y86DMemory(Y86DMemory&&)                 = delete;
    constexpr Y86DMemory& operator=(const Y86DMemory&) = delete;
    constexpr Y86DMemory& operator=(Y86DMemory&&)      = delete;
    // clang-format on

    static Y86DMemory& execute()
    {
        static std::unique_ptr<Y86DMemory> dmem{new Y86DMemory()};
        return *dmem;
    }

    const uint8_t& operator[](std::size_t index) const;
    uint8_t& operator[](std::size_t index);

    void show(std::size_t beginAddress = 0, std::size_t count = DMemSize);

protected:
    constexpr Y86DMemory() = default;

private:
    std::array<uint8_t, DMemSize> m_dmem;
};

#include "impl/DMemory.ipp"

#endif  //Y86_64_DMEMORY_HPP
