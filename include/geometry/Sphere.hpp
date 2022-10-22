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
        const auto sphereEquasion = getSphereRayEquasion(ray);

        return getDiscriminant(sphereEquasion);
    }

    double getGradientVal(const Utils::Ray& ray) const
    {
        const auto sphereEquasion = getSphereRayEquasion(ray);
        const auto discriminant = getDiscriminant(sphereEquasion);

        if(discriminant < 0.0)
        {
            return -1.0;
        }
        else
        {
            return (-sphereEquasion.y() - std::sqrt(discriminant) / sphereEquasion.x());
        }
    }

    bool intersectsWith(const Utils::Ray& ray) const
    {
        return getIntersectingDiscriminant(ray) > 0;
    }
private:
    Vec3d getSphereRayEquasion(const Utils::Ray& ray) const
    {
        Vec3d originCenter = ray.getOrigin() - center;
        const auto a = ray.getDirection().length_squared();
        const auto halfB = originCenter.dot(ray.getDirection());
        const auto c = originCenter.length_squared() - (radius * radius);

        return { a, halfB, c };
    }

    double getDiscriminant(const Vec3d& sphereEquasion) const
    {
        return sphereEquasion.b() * sphereEquasion.b() - (sphereEquasion.a() * sphereEquasion.c());
    }
private:
    Point3d center;
    double radius;
};
}

#endif // SPHERE_HPP
