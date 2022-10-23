#include "Renderer.hpp"

#include "Camera.hpp"
#include "GlobalConfig.hpp"
#include "geometry/Sphere.hpp"

#include <sstream>
#include <vector>

std::string Renderer::renderDefaultScene()
{
    using namespace Config;

    Camera camera(viewportHeight, focalLength, { 0.0, 0.0, 0.0 });
    std::stringstream imageBuffer;

    std::vector<Shapes::Sphere> spheres = { {}, {{2.0, 2.0, -1.0}, 0.4}, {{4.4, 1.4, -1.0}, 0.6}};

    auto hit = false;
    for(auto i = imageHeight - 1; i >= 0; i--)
    {
        for(auto j = 0; j < imageWidth; j++)
        {
            const auto u = static_cast<double>(j) / (imageWidth - 1);
            const auto v = static_cast<double>(i) / (imageHeight - 1);
            const auto ray = Utils::Ray { camera.getOrigin(), camera.getLowerLeftCorner() + (u * camera.getHorizontal()) + (v * camera.getVertical()) - camera.getOrigin() };
            HitRecord hitRecord {};


            for(const auto sphere : spheres)
            {
                if(sphere.hit(ray, -1.0, 1.0, hitRecord))
                {
                    writeAs256Color(imageBuffer, { 1.0, 0.0, 0.0 });
                    hit = true;
                    break;
                }
            }

            if(!hit)
            {
                writeAs256Color(imageBuffer, calculateBackgroundColor(ray));
            }
            else
            {
                hit = false;
            }
        }
    }

    return imageBuffer.str();
}

void Renderer::writeAs256Color(std::stringstream& ss, const Color3d& color)
{
    ss << static_cast<std::uint64_t>(color.x() * 255.99) << ' '
	   << static_cast<std::uint64_t>(color.y() * 255.99) << ' '
	   << static_cast<std::uint64_t>(color.z() * 255.99) << '\n';
}

Color3d Renderer::calculateBackgroundColor(const Utils::Ray& ray)
{
    Vec3d unitDirection = Vec3d { ray.getDirection() }.unitVector();
    auto t = 0.5 * (unitDirection.y() + 1.0);

    return (1.0 - t) * Color3d(1.0, 1.0, 1.0) + t * Color3d(0.0, 0.0, 1.0);
}