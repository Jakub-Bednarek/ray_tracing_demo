#include "geometry/Ray.hpp"
#include "geometry/Sphere.hpp"

#include <cmath>

namespace Utils
{

std::ostream& operator<<(std::ostream& out, const Ray& ray)
{
    return out << "(" << ray.getOrigin() << ", " << ray.getDirection() << ")";
}

}