#include <iostream>
#include "field.h"
#include "piece_states.h"
#include "../logic/utils.h"
#include "../logic/key_reading.h"

Components::Field::Field()
{
    setCurrentSelectedCell(4);
    getCells()[getCurrentSelectedCell()].bg = Components::getBGColorString(Components::Color::red);
    getCells()[getCurrentSelectedCell()].fg = Components::getFGColorString(Components::Color::black);
}

Components::Field::Field(int current_selected_cell = 4)
    : m_current_selected_cell { current_selected_cell }
{
    getCells()[getCurrentSelectedCell()].bg = Components::getBGColorString(Components::Color::red);
    getCells()[getCurrentSelectedCell()].fg = Components::getFGColorString(Components::Color::black);
};

Components::Field::~Field()
{
    if (m_cells)
        delete m_cells;
}

Components::Cell* Components::Field::getCells() const
{
    return m_cells;
}

int Components::Field::getCurrentSelectedCell() const
{
    return m_current_selected_cell;
}

void Components::Field::setCurrentSelectedCell(const int new_current_selected_cell)
{
    m_current_selected_cell = new_current_selected_cell;
}

void Components::Field::moveCursor(const Logic::PlayerActions direction)
{
    // Though it's prefered to be done earlier, just do a sanity check
    // That actual movement is being invoked.
    if (direction == Logic::PlayerActions::Unknown ||
        direction == Logic::PlayerActions::Enter)
    {
        return;
    }

    // Applying the coloring of a default state to the currently selected field
    getCells()[getCurrentSelectedCell()].bg = Components::getBGColorString(Components::Color::clear);
    getCells()[getCurrentSelectedCell()].fg = Components::getFGColorString(Components::Color::clear);

    // Figure out where the movement is done on a 2D plane in terms of 1D array
    if (direction == Logic::PlayerActions::Down)
    {
        if (getCurrentSelectedCell() >= 0 && getCurrentSelectedCell() <= 5)
        {
            setCurrentSelectedCell(getCurrentSelectedCell() + 3);
        }
        else
        {
            setCurrentSelectedCell(getCurrentSelectedCell() - 6);
        }    
    }

    if (direction == Logic::PlayerActions::Up)
    {
        if (getCurrentSelectedCell() >= 3 && getCurrentSelectedCell() <= 8)
        {
            setCurrentSelectedCell(getCurrentSelectedCell() - 3);
        }
        else
        {
            setCurrentSelectedCell(getCurrentSelectedCell() + 6);
        }    
    }

    if (direction == Logic::PlayerActions::Left)
    {
        if (getCurrentSelectedCell() == 0 ||
            getCurrentSelectedCell() == 3 ||
            getCurrentSelectedCell() == 6)
        {
            setCurrentSelectedCell(getCurrentSelectedCell() + 2);
        }
        else
        {
            setCurrentSelectedCell(getCurrentSelectedCell() - 1);
        }
    }

    if (direction == Logic::PlayerActions::Right)
    {
        if (getCurrentSelectedCell() == 2 ||
            getCurrentSelectedCell() == 5 ||
            getCurrentSelectedCell() == 8)
        {
            setCurrentSelectedCell(getCurrentSelectedCell() - 2);;
        }
        else
        {
            setCurrentSelectedCell(getCurrentSelectedCell() + 1);;
        }
    }

    // Colorize the new selection now
    getCells()[getCurrentSelectedCell()].bg = Components::getBGColorString(Components::Color::red);
    getCells()[getCurrentSelectedCell()].fg = Components::getFGColorString(Components::Color::black);
}

bool Components::Field::applyX()
{
    if (getCells()[getCurrentSelectedCell()].piece == "_")
    {
        getCells()[getCurrentSelectedCell()].piece = "X";
        return true;
    }
    else
    {
        return false;
    }
}

void Components::Field::makeOponentMove()
{
    // Logic of the oponents is that movements are random. But if the random move is pre-occupied
    // then the oponent will just move to the next field. This is done so we don't get stuck in
    // an infinite loop of random value potentially never giving us the only free field available.
    // Also, quit after 9 unsuccessful tries. Likely if we reached them it means something went
    // wrong and realisttically this conditions should never be invoked.
    int attemptsMade { 0 };
    int randomCell { Logic::getRandomBoardMove() };

    while (attemptsMade < 9)
    {
        if (getCells()[randomCell].piece == "_")
        {
            getCells()[randomCell].piece = "O";
            return;
        }
        else
        {
            attemptsMade++;
            randomCell = (randomCell + 1) % 9; // We increment movements and make sure we loop in our cells array
        }
    }
}

void Components::Field::printFields()
{
    // First clean the screen
    Logic::clearTerminal();

    // We know for sure the array is only 9 elements long, we can utilize it to draw it
    // in a 3x3 grid
    for (int i {0}; i<9; i++)
    {
        std::cout
            << "_"
            << getCells()[i].bg
            << getCells()[i].fg
            << getCells()[i].piece
            << Components::getBGColorString(Components::Color::clear)
            << Components::getFGColorString(Components::Color::clear)
            << "_";

        // Make a break evey 3 pieces
        // Account for the fact that we are indexing arrays from 0
        if ((i + 1) % 3 == 0)
        {
            std::cout 
                << "\n";
        }
        else
        {
            std::cout 
                << " | ";
        }
    }
    
    // Clear everything from the buffer
    std::cout << std::endl;
}