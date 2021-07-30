#include <status.hpp>

int main()
{
    Y86Status::show();

    Y86Status::value = Y86Status::Tag::ADR;
    Y86Status::show();

    std::cout << std::format("Status == ADR ? {}\n", Y86Status::value == Y86Status::Tag::ADR);
    Y86Status::show();

    std::cout << std::format("Status: {}\n", Y86Status::tag2string(Y86Status::value));
    Y86Status::show();

    return 0;
}
