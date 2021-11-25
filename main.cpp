#include <iostream>
#include <vector>
#include <string>
#include "header.h"

int main()
{
    data data;
    data.firstRow = {"YRS", "YRs", "YrS", "Yrs", "yRS", "yRs", "yrS", "yrs"};
    data.firstColumn = {"YRS", "YRs", "YrS", "Yrs", "yRS", "yRs", "yrS", "yrs"};
    data.populate(data);

    data.print(data);

    return 0;
}
