#include <iostream>
#include "utils.h"

void Logic::clearTerminal()
{
    // Since we are platform specific, it looks a bit ugly.
    #if defined _WIN32
        system("cls");
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        system("clear");
    #elif defined (__APPLE__)
        system("clear");
    #endif
}

void Logic::clearTerminalLine()
{
    std::cout 
        << "\x1b[1F"  // Return one line up
        << "\x1b[2K"  // Clean the line
        << "\r";      // Go to the beginning of the line
}