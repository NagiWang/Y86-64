#include <registers.hpp>

int main()
{
    Y86Registers<>::write(Y86RFTag::RAX, 100);
    Y86Registers<>::show();

    Y86ConditionCodes::show();
    Y86ConditionCodes::ZF = true;
    Y86ConditionCodes::OF = true;
    Y86ConditionCodes::show();

    Y86ConditionCodes::ZF = false;
    Y86ConditionCodes::SF = true;
    Y86ConditionCodes::show();
    Y86ConditionCodes::clear();
    Y86ConditionCodes::show();
}
