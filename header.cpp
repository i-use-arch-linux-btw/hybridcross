//
// Created by ap on 11/25/21.
//
#include <iostream>
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

void Data::makeGametes(Data &data)
{
    // new method

    // separate all genes pairs out here
    for(int i=0; i<data.parent1.size(); i+=2)
    {
        std::string t1;
        std::string t2;

        t1+=data.parent1[i];
        t1+=data.parent1[i+1];
        t2+=data.parent2[i];
        t2+=data.parent2[i+1];

        data.genes1.push_back(t1);
        data.genes2.push_back(t2);
    }

    // old method
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

void Data::genGametes(Data &data, std::string partialGamete, int geneCounter)
{
 for(auto i : data.genes1[geneCounter])
 {
     partialGamete += i;

     for(geneCounter=0; geneCounter<2; geneCounter++)
     {
         genGametes(data, partialGamete, geneCounter);
     }
    std::cout<<partialGamete<<std::endl;
 }
}


void Data::populate(Data &data)
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

void Data::sortGenotypes(Data &data)
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

void Data::countGenotypes(Data &data, int outputToConsole)
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
            if(data.arr[j][i].empty()) std::cout<<".";

            data.arr[j][i].size()<=data.parent1.size()/2 ? std::cout<<BOLDBLUE<<data.arr[j][i]<<RESET<<"\t\t" : std::cout<<data.arr[j][i]<<"\t";

        }
        std::cout<<std::endl;

    }

    std::cout<< BOLDGREEN << "----------------------------------------------------------------------" << RESET;
    data.printLog++;

}