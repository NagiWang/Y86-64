#ifndef Y86_64_PROGRAM_COUNTER_IPP
#define Y86_64_PROGRAM_COUNTER_IPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif  // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "../program_counter.hpp"

void Y86PC::show()
{
    std::cout << std::format("PC: 0x{:016x} \t{}\n\n", Y86PC::value, Y86PC::value);
}

#endif  //Y86_64_PROGRAM_COUNTER_IPP
