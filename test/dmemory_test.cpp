#include <dmemory.hpp>

int main()
{
    Y86DMemory<30>::show();

    Y86DMemory<30>::writeq(15, 0x15);
    Y86DMemory<30>::show();

    Y86DMemory<30>::writeq(10, 0x87654321);
    Y86DMemory<30>::show();

    Y86DMemory<30>::writeq(10, 87654321);
    Y86DMemory<30>::show();

    return 0;
}
