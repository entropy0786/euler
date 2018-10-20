/**
Problem Statement:
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
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