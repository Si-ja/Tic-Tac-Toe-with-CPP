#include "piece_states.h"
#include <string_view>

// 33 is some magical escape indicator for colors to be applied
// the code after it before m indicates what should be things colored to
// Codes found in this stackoverflow post: https://stackoverflow.com/questions/4053837/colorizing-text-in-the-console-with-c

std::string_view Components::getBGColorString(const Components::Color color)
{
    switch (color)
    {
        case Components::Color::clear:
            return "\033[0m";
        case Components::Color::black:
            return "\033[40m";
        case Components::Color::red:
            return "\033[41m";

        // default to blank field
        default:
            return "\033[0m";
    }
}

std::string_view Components::getFGColorString(const Components::Color color)
{
    switch (color)
    {
        case Components::Color::clear:
            return "\033[0m";
        case Components::Color::black:
            return "\x1B[30m";
        case Components::Color::red:
            return "\x1B[31m";

        // default to blank field
        default:
            return "\033[0m";
    }
}