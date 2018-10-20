/**
Problem Statement:
A palindromic number reads the same both ways. The largest palindrome made from the product of two 
2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
**/

#include "header.hpp"

#include <vector>
#include <iostream>

void main()
{    
    unsigned long numberBelow;
    std::cout << "pick a number to accrue all numbers below that are multiples of the input factors: ";
    std::cin >> numberBelow;

	euler::LargestPalendromeFunctor functor(numberBelow);
    std::cout << "calculating...";
	{
		auto totalSum = functor.getLargest<euler::details::EAlgoTypes::eNaive>();
		std::cout << "done!\n";
		std::cout << "the largest Palendrome is: " << totalSum[0] << " x " << totalSum[1] << " = " << (long)totalSum[0] * (long)totalSum[1] << "\n";
	}
    std::cout << " \nPress any key to continue\n";
    std::cin.ignore();
    std::cin.get();
}