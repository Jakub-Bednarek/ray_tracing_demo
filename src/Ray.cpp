#include "Ray.hpp"

namespace Utils
{

Color3d rayColor(const Ray& ray) 
{
    Vec3d unitDirection = Vec3d { ray.getDirection() }.unitVector();
    auto t = 0.5 * (unitDirection.y() + 1.0);

    return (1.0 - t) * Color3d(1.0, 1.0, 1.0) + t * Color3d(0.0, 0.0, 1.0);
}

std::ostream& operator<<(std::ostream& out, const Ray& ray)
{
    return out << "(" << ray.getOrigin() << ", " << ray.getDirection() << ")";
}

}