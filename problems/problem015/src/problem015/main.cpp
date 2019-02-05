/**
Problem Statement:
Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

        [RRDD], [RDRD], [RDDR], [DRRD], [DRDR], [DDRR]

How many such routes are there through a 20×20 grid?
**/

#include "header.hpp"

#include <vector>
#include <iostream>

void main()
{    
    std::vector<int> dimensions;
    dimensions.push_back(20);
    dimensions.push_back(20);
    std::cout << "calculating number of routes to a grid of ["<< dimensions[0] 
    << " x " << dimensions[1] << "].. ";

    std::cout << "calculating...";
	{
		auto totalPermutations = euler::numberPermutationsMultiSet(dimensions);
		std::cout << "the total number of routes to the bottom-right for a " << dimensions.size() << " dimension matrix of [";
		for (auto itDim = dimensions.begin(); itDim != dimensions.end(); ++itDim)
		{
			std::cout << *itDim;
			if (itDim != dimensions.rbegin().base())
				std::cout << " x ";
		}
		
		std::cout << "]: \n "<< totalPermutations << " unique Routes! \n";
	}
    std::cout << " \nPress any key to continue\n";
    std::cin.ignore();
    std::cin.get();
}