#include <iostream>
#include "blank.h"

void printSomething()
{
    // 33 is some magical escape indicator for colors to be applied
    // the code after it before m indicates what should be things colored to
    // Codes found in this stackoverflow post: https://stackoverflow.com/questions/4053837/colorizing-text-in-the-console-with-c
    std::cout << "Hello from algos!" << std::endl;
    std::cout << "\x1B[31mTexting\033[0m\t\t" << std::endl;
    std::cout << "\033[41mHey\033[0m\t\t" << std::endl;
}