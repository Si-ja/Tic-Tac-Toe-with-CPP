#include <iostream>
#include <cstdlib>
#include <iostream>
#include "components/field.h"
#include "components/piece_states.h"
#include "logic/key_reading.h"

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

    // Initialize the state of the player
    Logic::PlayerActions currentActions { Logic::PlayerActions::Unknown };
    bool isPlayersTurn { true };

    // Prompt the user to enter information until we understand what they are doing
    while (currentActions == Logic::PlayerActions::Unknown || isPlayersTurn)
    {
        currentActions = Logic::getKeyStroke();
        if (currentActions == Logic::PlayerActions::Enter)
        {
            isPlayersTurn = not (field->applyX());
        }
        else
        {
            field->moveCursor(currentActions);
        }

        field->printFields();
    }

    // Cleanup all resources (a bit of an overkill, but a good practice)
    field->cleanUp();
    delete field;

    return EXIT_SUCCESS; 
}