#include <seq/seq_pc.hpp>

int main()
{
    SeqY86PC::show();

    SeqY86PC::value = 100_sz;
    SeqY86PC::show();

    SeqY86PC::value += 10_sz;
    SeqY86PC::show();

    SeqY86PC::value -= 10_sz;
    SeqY86PC::show();

    SeqY86PC::value++;
    SeqY86PC::show();

    ++SeqY86PC::value;
    SeqY86PC::show();

    return 0;
}
