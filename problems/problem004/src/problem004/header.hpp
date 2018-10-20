#ifndef __PROBLEM004_HEADER__
#define __PROBLEM004_HEADER__

#include <sstream>
#include <array>

namespace details
{

    std::string revDigits(char* in)
    {
        //reverse digits.
        return in;
    }

    std::string makePalindrome(char* in)
    {
        // input in
    }



}


std::array<int, 2> largestPalendrome(const int numDigits)
{
    std::array<int, 2> arr;
    std::stringstream ss;
    std::string pal;
    for (int n = 0; n < numDigits / 2; ++n)
    {
        // make palendrome.
        ss << n;
        pal = ss.str();
        ss.str("");

    }
}


#endif // !__PROBLEM004_HEADER__