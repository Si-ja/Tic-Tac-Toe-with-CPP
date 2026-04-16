#ifndef PIECE_STATES_H_INCLUDE
#define PIECE_STATES_H_INCLUDE

#include <string_view>

namespace Components
{
    static const std::string_view X { "X" };
    static const std::string_view O { "O" };

    enum class Color
    {
        clear,
        black,
        red,
    };

    /// @brief Get string that will colorize a certain field
    /// in a chosen color in respect to its background.
    /// @param color Color that is prefered to be colorized into.
    /// @return string_vieww that can be used when modifying std::cout.
    std::string_view getBGColorString(const Components::Color color);

    /// @brief Get string that will colorize a certain field
    /// in a chosen color in respect to its foreground.
    /// @param color Color that is prefered to be colorized into.
    /// @return string_vieww that can be used when modifying std::cout.
    std::string_view getFGColorString(const Components::Color color);
}

# endif // PIECE_STATES_H_INCLUDE included