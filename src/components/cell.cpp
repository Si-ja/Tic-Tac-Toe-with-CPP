#include <iostream>
#include "cell.h"
#include "../logic/blank.h"

void Components::Cell::printConfirmation() const
{
    std::cout << "I have been created" << std::endl;
    printSomething();
}