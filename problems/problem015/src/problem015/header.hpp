#ifndef __PROBLEM015_HEADER__
#define __PROBLEM015_HEADER__

#include <vector>


namespace euler
{
	namespace details
	{
		enum EAlgoTypes : int
		{
			eNaive = 0	
		};

		template<typename T>
		long long factorial(const T n)
		{
			long long nLong = static_cast<long long>(n);
			auto factor = nLong;
			while (factor > 0)
			{
				nLong *= factor--;
			};
			return nLong;
		}
	}

	/**
	* @brief This does a permutation on a multiset such that the formula is:
	*       = (Sum(dims)!) / (dims[0]! * dims[1]! * .... * dims[NumDims]!)
	* @it will overflow under normal circumstances for larger values 
	*/
	long long numberPermutationsMultiSet(const std::vector<int> dims)
	{
		long long totalOrthDist = 0;

		if (dims.size() == 0)
			return 0;
		if (dims[0] <= 0)
			return 0;
		/////////////


		for (auto d : dims)
		{
			totalOrthDist += static_cast<long long>(d);
		}

		auto perms = details::factorial(totalOrthDist);
		long long denom = 1;
		for (const auto d : dims)
		{
			denom *= details::factorial(d);
		}

		return perms / denom;
	}

}


#endif // !__PROBLEM015_HEADER__