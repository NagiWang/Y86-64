#include <status.hpp>

int main()
{
    Y86Status<>::show();

    Y86Status<>::value = Y86StatusTag::ADR;
    Y86Status<>::show();

    std::cout << std::format("Status == ADR ? {}\n", Y86Status<>::value == Y86StatusTag::ADR);
    Y86Status<>::show();

    std::cout << std::format("Status: {}\n", StatusTag2String(Y86Status<>::value));
    Y86Status<>::show();

    return 0;
}


