#include "Ray.hpp"

namespace Utils
{

bool hitSphere(const Point3d& center, const double radius, const Ray& ray)
{
    Vec3d originCenter = ray.getOrigin() - center;
    auto a = ray.getDirection().dot(ray.getDirection());
    auto b = 2.0 * originCenter.dot(ray.getDirection());
    auto c = originCenter.dot(originCenter) - (radius * radius);
    auto discriminant = (b * b) - (4 * a * c);

    return (discriminant > 0);
}

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

Color3d gradientXYParamWithSphere(const Ray& ray)
{
    if(hitSphere(Point3d(0.0, 0.0, -1.0), 0.5, ray))
    {
        return { 1.0, 0.0, 0.0 };
    }
    Vec3d unitDirection = Vec3d { ray.getDirection() }.unitVector();
    auto t = 0.5 * (unitDirection.y() + 1.0);
    auto t2 = 0.5 * (unitDirection.x() + 1.0);

    return (1.0 - t) * Color3d(1.0, 1.0, 1.0) + t * Color3d(0.0, 0.0, 1.0) + t2 * Color3d(1.0, 0.5, 0.0);
}
}

std::ostream& operator<<(std::ostream& out, const Ray& ray)
{
    return out << "(" << ray.getOrigin() << ", " << ray.getDirection() << ")";
}

}