#include <seq.hpp>

int main()
{
    SeqY86Registers::write(SeqY86Registers::Tag::RAX, 100);
    SeqY86Registers::show();

    SeqY86CC::show();
    SeqY86CC::ZF = true;
    SeqY86CC::OF = true;
    SeqY86CC::show();

    SeqY86CC::ZF = false;
    SeqY86CC::SF = true;
    SeqY86CC::show();
    SeqY86CC::clear();
    SeqY86CC::show();
}
