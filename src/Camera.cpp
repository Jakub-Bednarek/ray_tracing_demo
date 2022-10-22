#include "Camera.hpp"

Camera::Camera()
	: viewportHeight(4.0),
	  viewportWidth(Config::ASPECT_RATIO * viewportHeight),
	  focalLength(1.0),
	  origin(0.0, 0.0, 0.0),
	  horizontal(viewportWidth, 0.0, 0.0),
	  vertical(0.0, viewportHeight, 0.0)
{
}

Camera::Camera(const double viewportHeight, const double focalLength, const Point3d& origin)
	: viewportHeight(viewportHeight),
	  viewportWidth(Config::ASPECT_RATIO * viewportHeight),
	  focalLength(focalLength),
	  origin(origin),
	  horizontal(viewportWidth, 0.0, 0.0),
	  vertical(0.0, viewportHeight, 0.0)
{
}

Vec3d Camera::getLowerLeftCorner() const
{
    return origin - (horizontal / 2.0) - (vertical / 2.0) - Vec3d { 0.0, 0.0, focalLength };
}

const Vec3d& Camera::getOrigin() const
{
    return origin;
}

const Vec3d& Camera::getHorizontal() const
{
    return horizontal;
}

const Vec3d& Camera::getVertical() const
{
    return vertical;
}
