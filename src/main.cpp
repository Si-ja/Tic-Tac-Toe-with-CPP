#include <iostream>
#include <cstdlib>
#include <iostream>
#include "components/cell.h"

int main()
{
    std::cout << "Hello, World!" << std::endl;
    Cell cell{ 'h' };
    cell.printConfirmation();

    return EXIT_SUCCESS; 
}