#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "IHittable.hpp"
#include "Ray.hpp"
#include "Vec3.hpp"

#include <cmath>

namespace Shapes 
{
class Sphere : public IHittable
{
public:
    Sphere() : center(0.0, 0.0, -1.0), radius(0.5) {}
    Sphere(const Point3d& center, const double radius): center(center), radius(radius) {}

    bool hit(const Utils::Ray& ray, const double tMin, const double tMax, HitRecord& hitRecord) const override
    {
        const auto sphereEquasion = getSphereRayEquasion(ray);
        const auto discriminant = getDiscriminant(sphereEquasion);

        if (discriminant < 0) 
        {
            return false;
        }

        const auto sqrtDisc = std::sqrt(discriminant);
        auto root = (sphereEquasion.b() - sqrtDisc) / sphereEquasion.a();
        if(root < tMin || root > tMax)
        {
            root = (sphereEquasion.b() + sqrtDisc) / sphereEquasion.a();
            if(root < tMin || root > tMax)
            {
                return false;
            }
        }

        hitRecord.t = root;
        hitRecord.position = ray.at(root);
        hitRecord.normal = (hitRecord.position - center) / radius;

        return true;
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
