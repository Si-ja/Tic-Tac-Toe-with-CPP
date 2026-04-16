#include <iostream>
#include <cstdlib>
#include <iostream>
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

    // ================= MAIN CODE
    // Initialize the game with empty fields
    Components::Field* field{ new Components::Field {} };
    field->init();
    field->printFields();

    // Cleanup all resources (a bit of an overkill, but a good practice)
    field->cleanUp();
    delete field;

    return EXIT_SUCCESS; 
}