#ifndef Y86_64_DMEMORY_IPP
#define Y86_64_DMEMORY_IPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif  // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "../DMemory.hpp"

template <uint64_t DMemorySize>
const uint8_t& Y86DMemory<DMemorySize>::operator[](std::size_t index) const
{
    return m_dmem[index];
}

template <uint64_t DMemorySize>
uint8_t& Y86DMemory<DMemorySize>::operator[](std::size_t index)
{
    return const_cast<uint8_t&>(static_cast<const Y86DMemory&>(*this)[index]);
}

template <uint64_t DMemorySize>
void Y86DMemory<DMemorySize>::show(std::size_t beginAddress, std::size_t num)
{
    if (beginAddress + num >= DMemSize) num = DMemSize - beginAddress;

    std::cout << std::format("Memory in (0x{:08x}, 0x{:08x})\n", beginAddress, beginAddress + num);

    std::size_t count = 0;
    std::for_each_n(m_dmem.begin() + beginAddress, num,
                    [&count](const uint8_t& value) {
                        std::cout << std::format("{:02x} ", value);
                        if (++count % 10 == 0) std::cout << '\n';
                    });
    std::cout << '\n';
}

#endif  //Y86_64_DMEMORY_IPP
