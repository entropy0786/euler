#ifndef __PROBLEM001_HEADER__
#define __PROBLEM001_HEADER__

#include <vector>

namespace details
{
struct AccumulatorNaive
{
    AccumulatorNaive(const std::vector<unsigned long> &factors)
        : _factors(factors)
        , _acc(0)
    {}

    void clear()
    {
        _acc = 0;
        _factors.clear();
    }

    void operator()(const unsigned int numToCheck)
    { 
        for (const auto f : _factors)
        {
            if (numToCheck % f == 0)
            {
                _acc += numToCheck;
                return;
            }
        }
    }

    /**
    * @brief returns the current accumulated sum.
    **/
    inline unsigned long long setFactors(const std::vector<unsigned long> &factors)
    {
        _factors = factors;
    }


    /**
    * @brief returns the current accumulated sum.
    **/
    unsigned long long accumulatedSum() const
    {
        return _acc;
    }
    
private:
    std::vector<unsigned long> _factors;
    unsigned long long _acc;
};
}

template <class Accumular = details::AccumulatorNaive>
unsigned long long getSumOfFactors(const std::vector<unsigned long> &factors, const unsigned long belowDigits)
{

    Accumular acc(factors);
    for (unsigned long n = 1; n < belowDigits; ++n)
    {
        acc(n);
    }
    return acc.accumulatedSum();
}


#endif // !__PROBLEM001_HEADER__