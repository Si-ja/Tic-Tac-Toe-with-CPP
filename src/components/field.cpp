#include <iostream>
#include "field.h"
#include "piece_states.h"

void Components::Field::init()
{
    // The center field is always #5. When indexed, that's 4.
    // So it needs to be visible as a selection.
    // The player can move from there. As we are dealing with structs on our choice
    // we can set certainn members of their directly, no need for setters and getters.

    cells[4].bg = Components::getBGColorString(Components::Color::red);
    cells[4].fg = Components::getFGColorString(Components::Color::black);
}

void Components::Field::cleanUp()
{
    if (cells)
        delete cells;
}

void Components::Field::printFields()
{
    // First clear screen in a terminal. Since we are platform specific, it looks a bit ugly.
    #if defined _WIN32
        system("cls");
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        system("clear");
    #elif defined (__APPLE__)
        system("clear");
    #endif

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
}