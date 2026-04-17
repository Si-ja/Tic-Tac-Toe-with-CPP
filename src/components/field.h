#ifndef FIELD_H_INCLUDED
#define FIELD_H_INCLUDED

#include <array>
#include "cell.h"
#include "../logic/key_reading.h"

namespace Components
{
    class Field
    {
    public:
        Field();
        Field(int current_selected_cell);
        ~Field();

        Components::Cell* getCells() const;
        int getCurrentSelectedCell() const;

        void setCurrentSelectedCell(const int new_current_selected_cell);

        /// @brief Print the structure of the fields for the player to see.
        void printFields();

        /// @brief Try to apply players X value onto the field that they have chosen.
        /// @return Confirmation of true/false that the value was applied. Some might be 
        /// occupied already and cannot be replaced again.
        bool applyX();

        /// @brief Move cursor on a playingfield to where the player wants to move.
        /// @param direction indication where the player needs to move further.
        void moveCursor(const Logic::PlayerActions direction);

        /// @brief Oponent is making a move depending on the availability of fields.
        /// Oponent is not responsible for checking if the game is already over. They
        /// try to make the move regardless of the situation. They will quit after trying all
        /// fields, but its more of a safety measure than actual meaningful logic.
        void makeOponentMove();

    private:
        Components::Cell* m_cells { new Components::Cell[9] {} };
        int m_current_selected_cell { 4 }; // defaults to 4 as it's the center of the field;
    };
}

# endif // FIELD_H_INCLUDED