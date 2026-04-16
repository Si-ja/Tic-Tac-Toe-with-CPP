#include <iostream>
#include "cell.h"
#include "../logic/blank.h"

void Cell::printConfirmation() const
{
    std::cout << "I have been created" << std::endl;
    printSomething();
}