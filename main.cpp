#include <iostream>
#include <math.h>
#include "header.h"

int main()
{
    Data data;

    data.parent1 = "ssbbcceeffgghh";
    data.parent2 = "ssbbcceeffgghh";

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
