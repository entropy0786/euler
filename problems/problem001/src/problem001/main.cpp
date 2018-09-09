/**
Problem Statement:
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
**/

#include "header.hpp"

#include <vector>
#include <iostream>

void main()
{
    std::vector<unsigned long> factors = { 3, 5 };
    
    unsigned long numberBelow;
    std::cout << "pick a number to accrue all numbers below that are multiples of the input factors: ";
    std::cin >> numberBelow;
    std::cout << "calculating...";

    auto totalSum = getSumOfFactors(factors, numberBelow);
    std::cout << "done!\n";
    std::cout << "the sum is: " << totalSum << "\n";

    std::cout << " \nPress any key to continue\n";
    std::cin.ignore();
    std::cin.get();
}