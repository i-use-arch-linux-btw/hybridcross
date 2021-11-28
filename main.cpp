#include <iostream>
#include <math.h>
#include "header.h"

int main()
{
    Data data;

    data.parent1 = "YyRrSs";
    data.parent2 = "YyRrSs";

    data.checkParents(data);
    data.prepVArr(data);
    data.generate_genes(data);

    data.populate(data);

    data.sortGenotypes(data);
    data.print(data);

    data.countGenotypes(data,1);

    data.calcPhenotypicRatio(data, 1);

    return 0;
}
