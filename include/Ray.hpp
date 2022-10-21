#ifndef RAY_HPP
#define RAY_HPP

#include "Vec3.hpp"

namespace Utils
{

class Ray
{
public:
	Ray(const Vec3d& origin, const Vec3d& direction) : origin(origin), direction(direction) {}

	const Vec3d& getOrigin() const { return origin; }
	const Vec3d& getDirection() const { return direction; }

	Vec3d at(const double t) const { return origin + (t * direction); }

private:
	Vec3d origin;
	Vec3d direction;
};

namespace RayColorFunctions
{
Color3d gradientYParam(const Ray& ray);
Color3d gradientXYParam(const Ray& ray);
Color3d gradientXYParamWithSphere(const Ray& ray);
}

std::ostream& operator<<(std::ostream& out, const Ray& ray);

}  // namespace Utils

#endif	// RAY_HPP