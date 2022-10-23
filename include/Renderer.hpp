#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "geometry/Vec3.hpp"
#include "geometry/Ray.hpp"

#include <string>

class Renderer
{
public:
    static std::string renderDefaultScene();
private:
    static void writeAs256Color(std::stringstream& ss, const Color3d& color);
    static Color3d calculateBackgroundColor(const Utils::Ray& ray);
};

#endif // RENDERER_HPP