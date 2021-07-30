#ifndef Y86_64_RUNNER_HPP
#define Y86_64_RUNNER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif  // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "sequential.hpp"
#include "y86.hpp"

template <typename SEQType = Y86SEQ<>>
struct Y86Runner {
    using SEQ = SEQType;

    static void fetch();
    static void stepi(bool debug = true);
    static void execute(bool debug = true);

    static uint8_t icode;
    static uint8_t ifun;
};

#include "impl/runner.ipp"

#endif  //Y86_64_RUNNER_HPP
