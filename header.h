//
// Created by ap on 11/25/21.
//

#ifndef TRIHYBRIDCROSS_HEADER_H
#define TRIHYBRIDCROSS_HEADER_H

#include <vector>
#include <string>

struct data
{
    std::string arr[9][9];
    std::vector<std::string> firstRow;
    std::vector<std::string> firstColumn;

    static void populate(data &data);
    static void print(data &data);
};



#endif //TRIHYBRIDCROSS_HEADER_H
