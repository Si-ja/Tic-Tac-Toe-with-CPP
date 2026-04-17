#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <string_view>

namespace Logic
{
    /// @brief Single use case that can be
    /// utilized with terminal screen cleaning.
    void clearTerminal();

    /// @brief Clean only one line in a terminal.
    void clearTerminalLine();

    /// @brief Chose a random place on the board to move to. Primarily useful operation
    /// for the Automated oponent. (AI phrasing was ruined so much, I have to call it automated
    /// opponent...future is dark) 
    /// @return a value that can be appleid to the board position, between 0 and 8.
    int getRandomBoardMove();
}

#endif // UTILS_H_INCLUDED included 