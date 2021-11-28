//
// Created by ap on 11/25/21.
//
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#include "header.h"



void Data::checkParents(Data &data)
{
    if(data.parent1.size() != data.parent2.size())
    {
        std::cerr << "Check parents genes.";
        exit(1);
    }
}

void Data::prepVArr(Data &data)
{
    int size = pow(2,data.parent1.size()/2);

    data.vArr.reserve(size+1); // reserves memory for the array. +1 because of headers.

    for (int i = 0; i <= size; i++)
        data.vArr[i].reserve(size+1);
}

void Data::generate_genes(Data &data) // length is number of letter
{
    const char *parent1 = data.parent1.c_str();
    const char *parent2 = data.parent2.c_str();


    int length = strlen(parent1);
    if (length % 2 == 1) {
        return;
    }
    int size = pow(2, length / 2); //number of gametes

    char * row1[size];
    char * row2[size];

    for (int i = 0; i < size; i++) {
        row1[i] = (char*) malloc(length / 2 + 1);
        row2[i] = (char*) malloc(length / 2 + 1);
    }

    data.recurse_gen(parent1, length / 2, 0, 0, row1);

    for (int i = 0; i < size; i++) {
        printf("%s\n", row1[i]);
        data.firstRow.push_back(row1[i]);
    }
    for (int i = 0; i < size; i++) {
        free(row1[i]);
    }

    data.recurse_gen(parent2, length / 2, 0, 0, row2);

    for (int i = 0; i < size; i++) {
        printf("%s\n", row2[i]);
        data.firstColumn.push_back(row2[i]);
        free(row2[i]);
    }
}

void Data::recurse_gen(const char *parent, int length, int depth, int start,
                       char *row[]) //start is the start of the data being operated on
{

    int half = pow(2, length - depth - 1);      //half the size of the data
    for (int i = start; i < half + start; i++)  //iterates through 2 halfs
    {
        row[i][depth] = parent[2 * depth];                 //first half first parent
        row[i + half][depth] = parent[2 * depth + 1];      //first half second parent
    }
    if (half == 1)
    {
        return; //end when data operating on is size 2
    }
    recurse_gen(parent, length, depth + 1, start, row);           //first half of section
    recurse_gen(parent, length, depth + 1, half + start, row);    //second half
}


void Data::populate(Data &data)
{
    for(int i=0; i<data.firstRow.size(); i++) // first column and row
    {
        data.vArr[i+1][0] = data.firstRow[i];
        data.vArr[0][i+1] = data.firstColumn[i];

    }

    for(int i=1; i<pow(2,data.parent1.size()/2)+1; i++) // all the middle
    {

        for(int j=1; j<pow(2,data.parent1.size()/2)+1; j++)
        {
            std::string cross;

            for(int k=0; k<data.vArr[j][0].size(); k++)
            {
                cross += data.vArr[j][0][k];
                cross += data.vArr[0][i][k];
            }
            data.vArr[j][i]=cross;
        }
    }

}

void Data::sortGenotypes(Data &data)
{

    for(int i = 1; i<pow(2, data.parent1.size()/2)+1; i++)
    {
        for(int j = 1; j<pow(2, data.parent1.size()/2)+1; j++)
        {
            for(int k = 0; k<data.parent1.size(); k++)
            {
                if(data.vArr[i][j][2*k]>data.vArr[i][j][2*k+1]) // is the first lowercase and second upper?
                {
                    char swap = data.vArr[i][j][2*k];

                    data.vArr[i][j][2*k] = data.vArr[i][j][2*k+1];
                    data.vArr[i][j][2*k+1] = swap;
                }
            }
        }
    }
}

void Data::countGenotypes(Data &data, int outputToConsole)
{
    for(int i=1; i<data.firstColumn.size()+1; i++) // iterating through all genotype cells
    {
        for(int j=1; j< data.firstRow.size() + 1; j++)
        {
            data.genotypesCount[data.vArr[i][j]] += 1; // adds 1 to the map of different genotypes
        }
    }
    std::cout<<std::endl;

    int counter = 0;
    if(outputToConsole)
    {
        std::cout<<BOLDGREEN<<"\nGenotype: number"<<RESET<<std::endl;

        for(auto count : data.genotypesCount)
        {
            std::cout << count.first << ": " << count.second << "\n";
            counter += count.second;
        }

        std::cout<<BOLDBLUE<<"Total: "<<counter<<RESET<<std::endl;
    }

}

void Data::calcPhenotypicRatio(Data &data, int outputToConsole)
{

    for(auto count : data.genotypesCount)
    {

        std::string phenotype;

        for(int i=0; i<count.first.size(); i+=2)
        {
            if(isupper(count.first[i]) or isupper(count.first[i+1]))
            {
                (isupper(count.first[i])) ? phenotype += count.first[i] : phenotype += count.first[i+1]; // if either is capital, then added. otherwise, lowercase is added.
            } else {
                phenotype += count.first[i];
            }

        }

        data.phenotypesCount[phenotype] += count.second;

    }

    int counter = 0;
    if(outputToConsole)
    {
        std::cout<<BOLDGREEN<<"\nPhenotype: number"<<RESET<<std::endl;
        for(auto count : data.phenotypesCount)
        {
            std::cout << count.first << ": " << count.second << "\n";
            counter += count.second;
        }

        std::cout<<BOLDBLUE<<"Total: "<<counter<<RESET<<std::endl;
    }

}

void Data::print(Data &data)
{

    std::cout << BOLDGREEN <<"\n\n-------------------------> TRIHYBRID CROSS <-------------------------" << data.printLog << RESET << std::endl;

    for(int i=0; i<data.firstColumn.size()+1; i++)
    {
        for(int j=0; j< data.firstRow.size() + 1; j++)
        {
            if(data.vArr[j][i].empty()) std::cout<<".";

            data.vArr[j][i].size()<=data.parent1.size()/2 ? std::cout<<BOLDBLUE<<data.vArr[j][i]<<RESET<<"\t\t" : std::cout<<data.vArr[j][i]<<"\t";

        }
        std::cout<<std::endl;

    }

    std::cout<< BOLDGREEN << "----------------------------------------------------------------------" << RESET;
    data.printLog++;

}