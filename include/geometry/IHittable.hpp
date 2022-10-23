#ifndef I_HITTABLE_HPP
#define I_HITTABLE_HPP

#include "Vec3.hpp"
#include "Ray.hpp"

struct HitRecord
{
    HitRecord() : position(0.0, 0.0, 0.0), normal(0.0, 0.0, 0.0), t(0.0) {}

    Point3d position;
    Vec3d normal;
    double t;
    bool frontFace;

    inline void setFaceNormal(const Utils::Ray& ray, const Vec3d& outwardNormal)
    {
        frontFace = ray.getDirection().dot(outwardNormal) < 0;
        normal = frontFace ? outwardNormal : -outwardNormal;
    }
};

class IHittable
{
public:
    virtual bool hit(const Utils::Ray& ray, const double tMin, const double tMax, HitRecord& hitRecord) const = 0;
};

#endif // I_HITTABLE_HPP