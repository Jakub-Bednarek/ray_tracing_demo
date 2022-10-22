#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "geometry/Ray.hpp"
#include "geometry/Vec3.hpp"

namespace Config
{
constexpr auto ASPECT_RATIO = 1.0;
}  // namespace Config

class Camera
{
public:
	Camera();
	Camera(const double viewportHeight, const double focalLength, const Point3d& origin);

	Vec3d getLowerLeftCorner() const;

    const Vec3d& getOrigin() const;
    const Vec3d& getHorizontal() const;
    const Vec3d& getVertical() const;

private:
	double viewportHeight;
	double viewportWidth;
	double focalLength;

	Point3d origin;
	Vec3d horizontal;
	Vec3d vertical;
};

#endif	// CAMERA_HPP