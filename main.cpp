#include <iostream>
#include "header.h"

int main()
{
    Data data;

    data.parent1 = "YyRrSs";
    data.parent2 = "YyRrSs";

    data.checkParents(data);

    data.makeGametes(data);
    data.genGametes(data);

    data.populate(data);
    data.print(data);

    data.sortGenotypes(data);
    data.print(data);

    data.countGenotypes(data,0);

    data.calcPhenotypicRatio(data, 0);

    return 0;
}
