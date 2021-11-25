//
// Created by ap on 11/25/21.
//
#include "iostream"
#include "header.h"

void data::populate(data &data)
{
    for(int i=0; i<data.firstRow.size(); i++) // first collumn and row
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

void data::print(data &data)
{
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
    std::cout<<std::endl;

}