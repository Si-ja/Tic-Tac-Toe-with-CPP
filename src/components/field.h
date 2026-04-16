#ifndef FIELD_H_INCLUDED
#define FIELD_H_INCLUDED

#include <array>
#include "cell.h"

namespace Components
{
    struct Field
    {
        Components::Cell* cells { new Components::Cell[9] {} };

        /// @brief Print the structure of the fields for the player to see.
        void printFields();
    };
}

# endif // FIELD_H_INCLUDED