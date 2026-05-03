//------------------------------------------------------------------------------
// wk13_operator_overload_sample.cpp
//------------------------------------------------------------------------------
#include <iostream>

class StopWatch
{
private:
    // overload stream insertion operator<<
    friend std::ostream& operator<<(std::ostream& os, const StopWatch& sw);

    unsigned seconds;

public:
    // constructor
    StopWatch(unsigned s) : seconds(s) { }

    // getter
    unsigned getSeconds() const { return seconds; }

    // overload addition operator +
    StopWatch operator+(StopWatch& rhs)
    {
        StopWatch addResult = StopWatch(seconds + rhs.seconds);
        return addResult;
    }

    // overload subtraction operator -
    StopWatch operator-(StopWatch& rhs)
    {
        StopWatch subtractResult = StopWatch(seconds - rhs.seconds);
        return subtractResult;
    }
};

//------------------------------------------------------------------------------
// friend operator<< overload
//  - for streaming to std::cout, or to file
//------------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& os, const StopWatch& sw)
{
    os << sw.seconds << " seconds elapsed.";
    return os;
}

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main()
{
    StopWatch sw5 = StopWatch(5);
    StopWatch sw10 = StopWatch(10);

    // addition operator +
    StopWatch sw15 = sw5 + sw10;
    std::cout << sw15 << "\n";

    // subtraction operator -
    StopWatch sw45 = StopWatch(45);
    StopWatch sw30 = sw45 - sw15;
    std::cout << sw30 << "\n";

    std::cout << "\nGoodbye!\n";
}
