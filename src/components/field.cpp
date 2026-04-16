#include <iostream>
#include "field.h"
#include "piece_states.h"
#include "../logic/utils.h"
#include "../logic/key_reading.h"

void Components::Field::init()
{
    // The center field is always #5. When indexed, that's 4.
    // So it needs to be visible as a selection.
    // The player can move from there. As we are dealing with structs on our choice
    // we can set certainn members of their directly, no need for setters and getters.
    // Hopefully 4 hasn't been ofset right from the start for some reason.

    cells[current_selected_cell].bg = Components::getBGColorString(Components::Color::red);
    cells[current_selected_cell].fg = Components::getFGColorString(Components::Color::black);
}

void Components::Field::cleanUp()
{
    if (cells)
        delete cells;
}

void Components::Field::moveCursor(const Logic::PlayerActions direction)
{
    // Though it's prefered to be done earlier, just do a sanity check
    // That actual movement is being invoked.
    if (direction == Logic::PlayerActions::Unknown ||
        direction == Logic::PlayerActions::Enter)
    {
        return;
    }

    // Applying the coloring of a default state to the currently selected field
    cells[current_selected_cell].bg = Components::getBGColorString(Components::Color::clear);
    cells[current_selected_cell].fg = Components::getFGColorString(Components::Color::clear);

    // Figure out where the movement is done on a 2D plane in terms of 1D array
    if (direction == Logic::PlayerActions::Down)
    {
        if (current_selected_cell >= 0 && current_selected_cell <= 5)
        {
            current_selected_cell += 3;
        }
        else
        {
            current_selected_cell -= 6;
        }    
    }

    if (direction == Logic::PlayerActions::Up)
    {
        if (current_selected_cell >= 3 && current_selected_cell <= 8)
        {
            current_selected_cell -= 3;
        }
        else
        {
            current_selected_cell += 6;
        }    
    }

    if (direction == Logic::PlayerActions::Left)
    {
        if (current_selected_cell == 0 ||
            current_selected_cell == 3 ||
            current_selected_cell == 6)
        {
            current_selected_cell += 2;
        }
        else
        {
            current_selected_cell -= 1;
        }
    }

    if (direction == Logic::PlayerActions::Right)
    {
        if (current_selected_cell == 2 ||
            current_selected_cell == 5 ||
            current_selected_cell == 8)
        {
            current_selected_cell -= 2;
        }
        else
        {
            current_selected_cell += 1;
        }
    }

    // Colorize the new selection now
    cells[current_selected_cell].bg = Components::getBGColorString(Components::Color::red);
    cells[current_selected_cell].fg = Components::getFGColorString(Components::Color::black);
}

void Components::Field::printFields()
{
    // First clean the screen
    Logic::clearTerminal();

    // We know for sure the array is only 9 elements long, we can utilize it to draw it
    // in a 3x3 grid
    for (int i {0}; i<9; i++)
    {
        std::cout
            << "_"
            << cells[i].bg
            << cells[i].fg
            << cells[i].piece
            << Components::getBGColorString(Components::Color::clear)
            << Components::getFGColorString(Components::Color::clear)
            << "_";

        // Make a break evey 3 pieces
        // Account for the fact that we are indexing arrays from 0
        if ((i + 1) % 3 == 0)
        {
            std::cout 
                << "\n";
        }
        else
        {
            std::cout 
                << " | ";
        }
    }
    
    // Clear everything from the buffer
    std::cout << std::endl;
}