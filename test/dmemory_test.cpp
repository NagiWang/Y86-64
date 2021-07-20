#include <DMemory.hpp>

int main()
{
    Y86DMemory<30>::execute().show();
    Y86DMemory<30>::execute()[15] = 0x15;
    Y86DMemory<30>::execute().show(15);

    return 0;
}
