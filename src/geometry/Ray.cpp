#include "geometry/Ray.hpp"
#include "geometry/Sphere.hpp"

#include <cmath>

namespace Utils
{

namespace RayColorFunctions
{
Color3d gradientYParam(const Ray& ray) 
{
    Vec3d unitDirection = Vec3d { ray.getDirection() }.unitVector();
    auto t = 0.5 * (unitDirection.y() + 1.0);

    return (1.0 - t) * Color3d(1.0, 1.0, 1.0) + t * Color3d(0.0, 0.0, 1.0);
}

Color3d gradientXYParam(const Ray& ray)
{
    Vec3d unitDirection = Vec3d { ray.getDirection() }.unitVector();
    auto t = 0.5 * (unitDirection.y() + 1.0);
    auto t2 = 0.5 * (unitDirection.x() + 1.0);

    return (1.0 - t) * Color3d(1.0, 1.0, 1.0) + t * Color3d(0.0, 0.0, 1.0) + t2 * Color3d(1.0, 0.5, 0.0);
}

Color3d gradientXYParamWithSphere(const Ray& ray, const Shapes::Sphere& sphere)
{
    const auto intersects = sphere.intersectsWith(ray);
    if(intersects)
    {
        return { 1.0, 0.0, 0.0 };
    }

    Vec3d unitDirection = Vec3d { ray.getDirection() }.unitVector();
    auto t = 0.5 * (unitDirection.y() + 1.0);

    return (1.0 - t) * Color3d(1.0, 1.0, 1.0) + t * Color3d(0.0, 0.0, 1.0);
}

Color3d gradientInsideSphere(const Ray& ray, const Shapes::Sphere& sphere)
{
    const auto hitColorVal = sphere.getIntersectingDiscriminant(ray);
    std::cout << "HitColorVal: " << hitColorVal;
    if(hitColorVal > 0.0)
    {
        Vec3d nFactor = (ray.at(hitColorVal) - Vec3d(0.0, 0.0, -1.0)).unitVector();

        return 0.5 * Color3d(nFactor.x() + 1.0, nFactor.y() + 1.0, nFactor.z() + 1.0);
    }

    Vec3d unitDirection = Vec3d { ray.getDirection() }.unitVector();
    auto t = 0.5 * (unitDirection.y() + 1.0);

    return (1.0 - t) * Color3d(1.0, 1.0, 1.0) + t * Color3d(0.0, 0.0, 1.0);
}
}

std::ostream& operator<<(std::ostream& out, const Ray& ray)
{
    return out << "(" << ray.getOrigin() << ", " << ray.getDirection() << ")";
}

}