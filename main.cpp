#include <iostream>
#include "header.h"

int main()
{
    Data data;

    data.parent1 = "YyRrSs";
    data.parent2 = "YyRrSs";

    data.makeGametes(data);

    data.populate(data);
    data.print(data);

    data.sortGenotypes(data);
    data.print(data);

    data.countGenotypes(data,1);

    data.calcPhenotypicRatio(data, 1);

    return 0;
}
