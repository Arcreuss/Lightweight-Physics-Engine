#include "math/vec2.hpp"

std::string vec2::ToString() const
{
    std::ostringstream oss;
    oss << "x = " << x << " y = " << y;
    return oss.str();
}
