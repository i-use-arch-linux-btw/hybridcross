//
// Created by ap on 11/25/21.
//
#include <iostream>
#include "header.h"

void data::makeGametes(data &data)
{
    for(int i=0; i<2; i++) // Yy
    {
        for(int j=2; j<4; j++)
        {
            for(int k=4; k<6; k++)
            {
                std::string gamete1 = "";
                std::string gamete2 = "";

                gamete1.push_back(data.parent1[i]);
                gamete1.push_back(data.parent1[j]);
                gamete1.push_back(data.parent1[k]);

                gamete2.push_back(data.parent2[i]);
                gamete2.push_back(data.parent2[j]);
                gamete2.push_back(data.parent2[k]);

                data.firstRow.push_back(gamete1);
                data.firstColumn.push_back(gamete2);

            }
        }
    }
}

void data::populate(data &data)
{
    for(int i=0; i<data.firstRow.size(); i++) // first column and row
    {
        data.arr[i+1][0] = data.firstRow[i];
        data.arr[0][i+1] = data.firstColumn[i];

    }

    for(int i=1; i<9; i++) // all the middle
    {
        for(int j=1; j<9; j++)
        {
            std::string cross;

            for(int k=0; k<data.arr[j][0].size(); k++)
            {
                cross += data.arr[j][0][k];
                cross += data.arr[0][i][k];
            }
            data.arr[j][i]=cross;
        }
    }

}

void data::sortGenotypes(data &data)
{
    for(int i = 1; i<sizeof(data.arr)/sizeof(data.arr[0]); i++)
    {
        for(int j = 1; j<sizeof(data.arr)/sizeof(data.arr[0]); j++)
        {
            for(int k = 0; k<data.parent1.size(); k++)
            {
                if(data.arr[i][j][2*k]>data.arr[i][j][2*k+1]) // is the first lowercase and second upper?
                {
                    char swap = data.arr[i][j][2*k];
                    data.arr[i][j][2*k] = data.arr[i][j][2*k+1];
                    data.arr[i][j][2*k+1] = swap;
                }
            }
        }
    }
}

void data::countGenotypes(data &data, int outputToConsole)
{
    for(int i=1; i<data.firstColumn.size()+1; i++) // iterating through all genotype cells
    {
        for(int j=1; j< data.firstRow.size() + 1; j++)
        {
            data.genotypesCount[data.arr[i][j]] += 1;
        }

    }
    std::cout<<std::endl;

    int counter = 0;
    if (outputToConsole)
    {
        for(auto count : data.genotypesCount)
        {
            std::cout << count.first << " " << count.second << "\n";
            counter += count.second;
        }

        std::cout<<BOLDBLUE<<"Total: "<<counter<<RESET<<std::endl;
    }

}

void data::calcGenotypicRatio(data &data, int outputToConsole)
{

}

void data::print(data &data)
{
    std::cout << BOLDGREEN <<"\n\n-------------------------> TRIHYBRID CROSS <-------------------------" << data.printLog << RESET << std::endl;

    for(int i=0; i<data.firstColumn.size()+1; i++)
    {
        for(int j=0; j< data.firstRow.size() + 1; j++)
        {
            if(data.arr[j][i].empty())
                std::cout<<".";

            data.arr[j][i].size()<6 ? std::cout<<BOLDBLUE<<data.arr[j][i]<<RESET<<"\t\t" : std::cout<<data.arr[j][i]<<"\t";

        }
        std::cout<<std::endl;

    }

    std::cout<< BOLDGREEN << "----------------------------------------------------------------------" << RESET;
    data.printLog++;

}