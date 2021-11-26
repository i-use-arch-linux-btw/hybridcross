#include <iostream>
#include "header.h"

int main()
{
    data data;

    data.parent1 = "YyRrSs";
    data.parent2 = "YyRrSs";

    data.makeGametes(data);

    data.populate(data);
    data.print(data);

    data.sortGenotypes(data);
    data.print(data);

    data.countGenotypes(data,1);

    return 0;
}
