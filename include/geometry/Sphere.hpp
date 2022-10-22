#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "Ray.hpp"
#include "Vec3.hpp"

#include <cmath>

namespace Shapes 
{
class Sphere
{
public:
    Sphere() : center(0.0, 0.0, 0.0), radius(1.0) {}
    Sphere(const Point3d& center, const double radius): center(center), radius(radius) {}

    double getIntersectingDiscriminant(const Utils::Ray& ray) const
    {
        Vec3d originCenter = ray.getOrigin() - center;

        auto a = ray.getDirection().dot(ray.getDirection());
        auto b = 2.0 * originCenter.dot(ray.getDirection());
        auto c = originCenter.dot(originCenter) - (radius * radius);
        auto discriminant = (b * b) - (4 * a * c);

        return discriminant;
    }

    double getGradientVal(const Utils::Ray& ray) const
    {
        Vec3d originCenter = ray.getOrigin() - center;

        auto a = ray.getDirection().dot(ray.getDirection());
        auto b = 2.0 * originCenter.dot(ray.getDirection());
        auto c = originCenter.dot(originCenter) - (radius * radius);
        auto discriminant = (b * b) - (4 * a * c);

        if(discriminant < 0.0)
        {
            return -1.0;
        }
        else
        {
            return (-b - std::sqrt(discriminant) / (2.0 * a));
        }
    }

    bool intersectsWith(const Utils::Ray& ray) const
    {
        return getIntersectingDiscriminant(ray) > 0;
    }
private:
    Point3d center;
    double radius;
};
}

#endif // SPHERE_HPP
