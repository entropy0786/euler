#ifndef __PROBLEM004_HEADER__
#define __PROBLEM004_HEADER__

#include <sstream>
#include <array>
#include <iostream>


namespace euler
{
	//struct LargestPalendromeFunctor;

	namespace details
	{
		enum EAlgoTypes : int
		{
			eNaive = 0
		};
	}

	struct LargestPalendromeFunctor
	{
		LargestPalendromeFunctor(const int numDigits = 1)
			: _numDigits(numDigits)
		{
			_startingNums.assign(makeMaxOfNdigits(numDigits));
			std::cout << "finding largest Palendrome for " << numDigits << " digits, starting with ["
				<< _startingNums[0] << ", " << _startingNums[1] << "]" << std::endl;
		}

		virtual ~LargestPalendromeFunctor()
		{
		}

		template <details::EAlgoTypes AlgorithmT>
		std::array<int, 2> getLargest();

		template<>
		std::array<int, 2> getLargest<details::EAlgoTypes::eNaive>();

	private:
		/*
		* @brief make N-digit max number
		*/
		int makeMaxOfNdigits(const int numDigits = 1)
		{
			std::stringstream ss;
			for (int n = 0; n < numDigits; ++n)
			{
				ss << '9';
			}
			return std::stoi(ss.str());
		}

		int makeMinOfNdigits(const int numDigits = 1)
		{
			std::stringstream ss;
			ss << '1';
			for (int n = 1; n < numDigits; ++n)
			{
				ss << '0';
			}
			return std::stoi(ss.str());
		}

		bool isProdPalendrome(const int a, const int b) const
		{
			std::stringstream ss;
			ss << (a*b);
			std::string strProduct = ss.str();
			auto itBegin = strProduct.begin();
			auto itEnd = strProduct.end();
			if (itBegin == itEnd)
			{
				return false;
			}
			--itEnd;

			while (itEnd > itBegin)
			{
				if (*itBegin != *itEnd)
					return false;
				++itBegin;
				--itEnd;
			};
			return true;
		}

	protected:
		int _numDigits;
		std::array<int, 2> _startingNums;
	};

	template<>
	std::array<int, 2> LargestPalendromeFunctor::getLargest<details::EAlgoTypes::eNaive>()
	{
		std::array<int, 2> largestPalProduct;
		largestPalProduct.assign(0);
		std::size_t currentIndex = 0;
		long highestProduct = -1;

		std::size_t otherIndex = 1 - currentIndex;
		int nMax0 = _startingNums[currentIndex];
		int nMax1 = _startingNums[otherIndex];
		int n0 = nMax0;
		int nMin0 = makeMinOfNdigits(_numDigits);
		while( n0 > 0)
		{
			for (int n1 = n0; n1 > largestPalProduct[1];)
			{
				if (isProdPalendrome(n0, n1) && n0*n1 > highestProduct)
				{
					long product = (long)n0 * (long)n1;
					highestProduct = (product > highestProduct) ? product : highestProduct;
					largestPalProduct[0] = n0;
					largestPalProduct[1] = n1;
				}
				--n1;
			}
			--n0;
		};

		return largestPalProduct;
	}

}


#endif // !__PROBLEM004_HEADER__