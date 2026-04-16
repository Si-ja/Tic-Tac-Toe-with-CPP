#include <iostream>
#include <cstdlib>
#include <iostream>
#include "components/cell.h"
#include "components/piece_states.h"

int main()
{
    std::cout 
        << Components::getBGColorString(Components::Color::red) 
        << Components::getFGColorString(Components::Color::black) 
        << "Hello, World!" 
        << Components::getBGColorString(Components::Color::clear) 
        << Components::getFGColorString(Components::Color::clear) 
        << std::endl;
    Components::Cell cell{ "h" };
    // cell.printConfirmation();

    return EXIT_SUCCESS; 
}