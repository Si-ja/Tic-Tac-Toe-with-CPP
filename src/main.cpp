#include <cstdlib>
#include <chrono>
#include <thread>
#include <memory>
#include "components/field.h"
#include "components/piece_states.h"
#include "logic/key_reading.h"
#include  "visuals/visuals.h"

int main()
{
    // Somewhat great the player
    Visuals::printLogo();
    std::this_thread::sleep_for(std::chrono::seconds(3));

    // ================= MAIN CODE =================
    // Initialize the game with empty fields
    std::unique_ptr<Components::Field> field { new Components::Field() };
    field->printFields();

    // Initialize the state of the player
    Logic::PlayerActions currentActions { Logic::PlayerActions::Unknown };
    Components::Winners winner { Components::Winners::None };
    bool isPlayersTurn { true };

    // Prompt the user to enter information until we understand what they are doing
    while (currentActions == Logic::PlayerActions::Unknown || winner == Components::Winners::None)
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
        winner = field->checkWinningConditions();

        if (winner != Components::Winners::None)
        {
            continue;
        }

        if (!isPlayersTurn)
        {
            field->makeOponentMove();
            isPlayersTurn = true;
            field->printFields();
            winner = field->checkWinningConditions();
        }
    }

    field->printWinner(winner);

    return EXIT_SUCCESS; 
}
