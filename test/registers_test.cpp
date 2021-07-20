#include <Registers.hpp>

int main()
{
    Y86Registers<>::execute().set(Y86RFTag::RAX, 100);
    Y86Registers<>::execute().show();

    Y86ConditionCodes<>::execute().show();
    Y86ConditionCodes<>::execute().set(ZF | OF);
    Y86ConditionCodes<>::execute().show();

    Y86ConditionCodes<>::execute().clear(ZF | SF);
    Y86ConditionCodes<>::execute().show();

    Y86ConditionCodes<>::execute().clear();
    Y86ConditionCodes<>::execute().show();
}
