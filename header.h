//
// Created by ap on 11/25/21.
//

#ifndef TRIHYBRIDCROSS_HEADER_H
#define TRIHYBRIDCROSS_HEADER_H

#include <vector>
#include <string>
#include <unordered_map>

struct data
{
    int printLog=0;
    std::string parent1;
    std::string parent2;
    std::string arr[9][9];
    std::vector<std::string> firstRow;
    std::vector<std::string> firstColumn;
    std::unordered_map<std::string, int> genotypesCount;

    static void makeGametes(data &data);
    static void populate(data &data);
    static void sortGenotypes(data &data);
    static void countGenotypes(data &data, int outputToConsole=1);
    static void calcGenotypicRatio(data &data, int outputToConsole=1);
    static void print(data &data);
};

//the following are UBUNTU/LINUX, and MacOS ONLY terminal color codes.
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */


#endif //TRIHYBRIDCROSS_HEADER_H
