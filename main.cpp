#include <iostream>
#include "header.h"

int main()
{
    std::cout << BOLDGREEN << "--------------------------> TRIHYBRID CROSS <--------------------------" << RESET << std::endl;

    data data;

    data.firstRow = {"YRS", "YRs", "YrS", "Yrs", "yRS", "yRs", "yrS", "yrs"};
    data.firstColumn = {"YRS", "YRs", "YrS", "Yrs", "yRS", "yRs", "yrS", "yrs"};
    data.populate(data);

    data.print(data);

    return 0;
}
