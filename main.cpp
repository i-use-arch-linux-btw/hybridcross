#include <iostream>
#include "header.h"

int main()
{
    std::cout << BOLDGREEN << "--------------------------> TRIHYBRIDCROSS <--------------------------" << RESET << std::endl;

    data data;

    data.firstRow = {"YRS", "YRs", "YrS", "Yrs", "yRS", "yRs", "yrS", "yrs"};
    data.firstColumn = {"YRS", "YRs", "YrS", "Yrs", "yRS", "yRs", "yrS", "yrs"};
    data.populate(data);

    data.print(data);

    std::cout<< BOLDGREEN << "----------------------------------------------------------------------" << RESET;

    return 0;
}
