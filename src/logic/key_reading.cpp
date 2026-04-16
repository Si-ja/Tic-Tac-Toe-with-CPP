#include <iostream>
#include <limits> // for std::numeric_limits
#include "key_reading.h"
#include "utils.h"

Logic::PlayerActions Logic::getKeyStroke()
{
    Logic::clearTerminalLine();
    std::cout << "Move around with [W], [S], [A], [D]. Select space with [X]: ";

    char key;
    key = getchar();

    // To ignore everything up to and including the next ‘\n’ character
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (key)
    {
        case 'w':
        case 'W':
            return Logic::PlayerActions::Up;

        case 's':
        case 'S':
            return Logic::PlayerActions::Down;

        case 'a':
        case 'A':
            return Logic::PlayerActions::Left;

        case 'd':
        case 'D':
            return Logic::PlayerActions::Right;

        case 'x':
        case 'X':
            return Logic::PlayerActions::Enter;
        
        default:
            return Logic::PlayerActions::Unknown;
    }
}