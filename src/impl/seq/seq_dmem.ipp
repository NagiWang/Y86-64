#ifndef Y86_64_SEQ_DMEM_IPP
#define Y86_64_SEQ_DMEM_IPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif  // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "seq/seq_dmem.hpp"

template <std::size_t DMemorySize, typename StatusType>
std::array<uint8_t, Y86DMemory<DMemorySize, StatusType>::DMemSize> Y86DMemory<DMemorySize, StatusType>::m_dmem{};

template <std::size_t DMemorySize, typename StatusType>
uint8_t Y86DMemory<DMemorySize, StatusType>::readb(std::size_t address)
{
    if (address >= DMemSize) {
        Status::value = StatusTag::ADR;
        return 0;
    }
    return m_dmem[address];
}

template <std::size_t DMemorySize, typename StatusType>
void Y86DMemory<DMemorySize, StatusType>::writeb(size_t address, uint8_t value)
{
    if (address >= DMemSize) {
        Status::value = StatusTag::ADR;
        return;
    }
    m_dmem[address] = value;
}

template <std::size_t DMemorySize, typename StatusType>
uint64_t Y86DMemory<DMemorySize, StatusType>::readq(std::size_t address)
{
    if (address >= DMemSize || address + 8 >= DMemSize) {
        Status::value = StatusTag::ADR;
        return 0;
    }
    uint64_t result = 0;
    result |= static_cast<uint64_t>(m_dmem[address]);
    result |= static_cast<uint64_t>(m_dmem[address + 1]) << 8;
    result |= static_cast<uint64_t>(m_dmem[address + 2]) << 16;
    result |= static_cast<uint64_t>(m_dmem[address + 3]) << 24;
    result |= static_cast<uint64_t>(m_dmem[address + 4]) << 32;
    result |= static_cast<uint64_t>(m_dmem[address + 5]) << 40;
    result |= static_cast<uint64_t>(m_dmem[address + 6]) << 48;
    result |= static_cast<uint64_t>(m_dmem[address + 7]) << 56;
    return result;
}

template <std::size_t DMemorySize, typename StatusType>
void Y86DMemory<DMemorySize, StatusType>::writeq(std::size_t address, uint64_t value)
{
    if (address >= DMemSize || address + 8 >= DMemSize) {
        Status::value = StatusTag::ADR;
        return;
    }
    m_dmem[address]     = value & 0xff;
    m_dmem[address + 1] = (value >> 8) & 0xff;
    m_dmem[address + 2] = (value >> 16) & 0xff;
    m_dmem[address + 3] = (value >> 24) & 0xff;
    m_dmem[address + 4] = (value >> 32) & 0xff;
    m_dmem[address + 5] = (value >> 40) & 0xff;
    m_dmem[address + 6] = (value >> 48) & 0xff;
    m_dmem[address + 7] = (value >> 56) & 0xff;
}

template <std::size_t DMemorySize, typename StatusType>
std::vector<uint8_t> Y86DMemory<DMemorySize, StatusType>::read_seq(std::size_t address, std::size_t count)
{
    if (address >= DMemSize || address + count >= DMemSize) {
        Status::value = StatusTag::ADR;
        return {};
    }

    return std::vector<uint8_t>(m_dmem.begin() + address, m_dmem.begin() + count);
}

template <std::size_t DMemorySize, typename StatusType>
void Y86DMemory<DMemorySize, StatusType>::write_seq(size_t address, const std::vector<uint8_t>& values)
{
    if (address >= DMemSize || address + values.size() >= DMemSize) {
        Status::value = StatusTag::ADR;
        return;
    }
    std::copy(values.begin(), values.end(), m_dmem.begin() + address);
}

template <uint64_t DMemorySize, typename StatusType>
void Y86DMemory<DMemorySize, StatusType>::show(std::size_t address, std::size_t count)
{
    if (address >= DMemSize) return;
    if (address + count >= DMemSize) count = DMemSize - address;

    std::cout << std::format("Memory in (0x{:08x}, 0x{:08x})\n", address, address + count);

    std::size_t num = 0;
    std::for_each_n(m_dmem.begin() + address, count,
                    [&num](const uint8_t& value) {
                        std::cout << std::format("{:02x} ", value);
                        if (++num % 10 == 0) std::cout << '\n';
                    });
    std::cout << '\n';
}

#endif  //Y86_64_SEQ_DMEM_IPP
