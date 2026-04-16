#ifndef CELL_H_INCLUDED
#define CELL_H_INCLUDED

#include <string_view>

namespace Components
{
    struct Cell
    {
        std::string_view piece { " " };

        std::string_view fg { "\033[0m" };
        std::string_view bg { "\033[0m" };

        void printConfirmation() const;
    };
}

#endif // CELL_H_INCLUDED included 