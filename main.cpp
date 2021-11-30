#include <iostream>
#include <math.h>
#include "header.h"

int main()
{
    Data data;

    data.parent1 = "AaBbCcddEEFfGgHhiI";
    data.parent2 = "AabbccDdeEFfGgHhiI";

    data.checkParents(data);
    data.prepVArr(data);
    data.generate_genes(data);

    data.populate(data);
    data.sortGenotypes(data);

    data.print(data);

    data.countGenotypes(data,0);

    data.calcPhenotypicRatio(data, 0);

    return 0;
}
