#include <seq.hpp>

int main()
{
    SeqY86Status::show();

    SeqY86Status::value = SeqY86Status::Tag::ADR;
    SeqY86Status::show();

    std::cout << std::format("Status == ADR ? {}\n", SeqY86Status::value == SeqY86Status::Tag::ADR);
    SeqY86Status::show();

    std::cout << std::format("Status: {}\n", SeqY86Status::tag2string(SeqY86Status::value));
    SeqY86Status::show();

    return 0;
}
