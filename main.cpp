#include <iostream>
#include <math.h>
#include "header.h"

int main()
{
    Data data;

    data.parent1 = "YyRrSsAa";
    data.parent2 = "YyRrSsAa";

    data.checkParents(data);
    data.prepVArr(data);
    data.generate_genes(data);

    data.populate(data);
    std::cout<<"Populated"<<std::endl;
    data.print(data);

    data.sortGenotypes(data);
    data.print(data);

    data.countGenotypes(data,0);

    data.calcPhenotypicRatio(data, 0);

    return 0;
}
