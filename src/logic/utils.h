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
}

#endif // UTILS_H_INCLUDED included 