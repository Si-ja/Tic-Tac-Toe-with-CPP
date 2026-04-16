#ifndef BLANK_H_INCLUDE
#define BLANK_H_INCLUDE

namespace Logic
{
    enum class PlayerActions
    {
        Unknown,
        Up,
        Left,
        Right,
        Down,
        Enter
    };

    /// @brief Based on player input, return what their
    /// intensions are in terms of interactions with the 
    /// playing field.
    /// @return An action type that the player is trying to
    /// achieve with their actions.
    PlayerActions getKeyStroke();
}

#endif // BLANK_H_INCLUDE included