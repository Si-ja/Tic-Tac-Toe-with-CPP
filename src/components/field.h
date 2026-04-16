#ifndef FIELD_H_INCLUDED
#define FIELD_H_INCLUDED

#include <array>
#include "cell.h"

namespace Components
{
    struct Field
    {
        Components::Cell* cells { new Components::Cell[9] {} };

        /// @brief A very vague description, but this should initialize the visuals on the
        /// field, as in the players cursor will be visible in the center of the board.
        void init();

        /// @brief Print the structure of the fields for the player to see.
        void printFields();

        /// @brief Delete all components that the struct refers to
        /// so nothing is left dangling. Maybe this should have been a class...
        void cleanUp();
    };
}

# endif // FIELD_H_INCLUDED