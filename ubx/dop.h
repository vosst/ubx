#ifndef UBX_DOP_H_
#define UBX_DOP_H_

namespace ubx
{
namespace tag
{
struct Horizontal {};
struct Positional {};
struct Vertical   {};
}
template<typename T>
struct DillusionOfPrecision
{
    explicit DillusionOfPrecision(float value = -1) : value{value}
    {
    }

    DillusionOfPrecision(const DillusionOfPrecision<T>& rhs) : value{rhs.value}
    {
    }

    DillusionOfPrecision& operator=(const DillusionOfPrecision<T>& rhs)
    {
        value = rhs.value;
        return *this;
    }
    
    float value;
};

template<typename T>
using Dop = DillusionOfPrecision<T>;
}

#endif // UBX_DOP_H_
