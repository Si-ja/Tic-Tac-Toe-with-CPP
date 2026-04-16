#ifndef FIELD_H_INCLUDED
#define FIELD_H_INCLUDED

#include <array>
#include "cell.h"

namespace Components
{
    struct Field
    {
        std::array<Cell, 9> field {};
    };
}

# endif // FIELD_H_INCLUDED