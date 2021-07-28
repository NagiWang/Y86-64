#include <program_counter.hpp>

int main()
{
    Y86PC::show();

    Y86PC::value = 100_sz;
    Y86PC::show();

    Y86PC::value += 10_sz;
    Y86PC::show();

    Y86PC::value -= 10_sz;
    Y86PC::show();

    Y86PC::value++;
    Y86PC::show();

    ++Y86PC::value;
    Y86PC::show();

    return 0;
}
