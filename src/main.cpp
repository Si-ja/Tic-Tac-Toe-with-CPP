#include <iostream>
#include <cstdlib>
#include <iostream>
// #include "components/cell.h"
#include "components/field.h"
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
    // Components::Cell cell{ "h" };
    // cell.printConfirmation();

    // ================= MAIN CODE
    // Initialize the game with empty fields
    Components::Field* field{ new Components::Field {} };
    field->printFields();

    return EXIT_SUCCESS; 
}