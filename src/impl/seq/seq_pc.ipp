#ifndef Y86_64_SEQ_PC_IPP
#define Y86_64_SEQ_PC_IPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif  // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "seq/seq_pc.hpp"

void SeqY86PC::show()
{
    std::cout << std::format("PC: 0x{:016x} \t{}\n\n", SeqY86PC::value, SeqY86PC::value);
}

#endif  //Y86_64_SEQ_PC_IPP
