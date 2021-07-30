#include <registers.hpp>

int main()
{
    Y86Registers::write(Y86Registers::Tag::RAX, 100);
    Y86Registers::show();

    Y86CC::show();
    Y86CC::ZF = true;
    Y86CC::OF = true;
    Y86CC::show();

    Y86CC::ZF = false;
    Y86CC::SF = true;
    Y86CC::show();
    Y86CC::clear();
    Y86CC::show();
}
