#ifndef Y86_64_RUN_HPP
#define Y86_64_RUN_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif  // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "seq.hpp"
#include "y86.hpp"

template <typename SEQType = Y86SEQ<>>
struct Y86Fetch {
    using SEQ = SEQType;

    static void fetch();
    static void execute();

    static uint8_t icode;
    static uint8_t ifun;
};

template <typename SEQType>
void Y86Fetch<SEQType>::execute()
{



    

    switch (icode) {
        case 0:
            SEQ::PC::value += 1;
            HALT::execute();
            break;
        case 2:
            SEQ::PC::value += 1;
            NOP::execute();
            break;
        case 3:
    }
}

#endif  //Y86_64_RUN_HPP
