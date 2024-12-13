#include "die.h"

int Die::roll()
{
    auto rndm = (std::rand() % sides) + 1;
    return rndm;
}