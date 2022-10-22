#ifndef RENDER_ALGORITHMS_HPP
#define RENDER_ALGORITHMS_HPP

#include "Ray.hpp"
#include "Vec3.hpp"
#include "Camera.hpp"

#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <functional>

namespace RenderAlgorithms
{

constexpr auto BLUE_GRADIENT_VAL = static_cast<int>(0.25 * 255.99);

using RayColorFunc = std::function<Color3d(const Utils::Ray&)>;

void writeColor(std::stringstream& ss, const Color3d& color)
{
	ss << static_cast<std::uint64_t>(color.x() * 255.99) << ' '
	   << static_cast<std::uint64_t>(color.y() * 255.99) << ' '
	   << static_cast<std::uint64_t>(color.z() * 255.99) << '\n';
}

std::string generateRayGradient(const std::uint32_t width, const std::uint32_t height, RayColorFunc rayColorFunc)
{
	std::stringstream ss{};
	Camera camera(4.0, 1.0, Point3d(0.0, 0.0, 0.0));

	std::cout << "Generating file.\n";
	for (int i = height - 1; i >= 0; i--)
	{
		for (int j = 0; j < width; j++)
		{
			const auto u = static_cast<double>(j) / static_cast<double>(width - 1);
			const auto v = static_cast<double>(i) / static_cast<double>(height - 1);
			
			Utils::Ray ray(camera.getOrigin(), camera.getLowerLeftCorner() + (u * camera.getHorizontal()) + (v * camera.getVertical()) - camera.getOrigin());
			

			writeColor(ss, rayColorFunc(ray));
		}
	}
	std::cout << "Done.\n";

	return ss.str();
}

std::string generateRayGradientY(const std::uint32_t width, const std::uint32_t height)
{
	return generateRayGradient(width, height, Utils::RayColorFunctions::gradientYParam);
}

std::string generateRayGradientXY(const std::uint32_t width, const std::uint32_t height)
{
	return generateRayGradient(width, height, Utils::RayColorFunctions::gradientXYParam);
}

std::string generateRayGradientXYWithSphere(const std::uint32_t width, const std::uint32_t height)
{
	return generateRayGradient(width, height, Utils::RayColorFunctions::gradientXYParamWithSphere);
}

std::string generateRayGradientInSphere(const std::uint32_t width, const std::uint32_t height)
{
	return generateRayGradient(width, height, Utils::RayColorFunctions::gradientInsideSphere);
}

std::string generateGradient(const std::uint32_t width, const std::uint32_t height)
{
	std::stringstream ss{};
	for (int i = height - 1; i >= 0; i--)
	{
		for (int j = width - 1; j >= 0; j--)
		{
			auto rgb = Color3d{double(j) / double(width - 1) * 255.99,
							   double(i) / double(height - 1) * 255.99, BLUE_GRADIENT_VAL};

			ss << Utils::getIntegralVector(rgb) << '\n';
		}

		if (i % 10 == 0)
		{
			std::cout << "Progress: " << std::setprecision(2)
					  << ((height - double(i + 1)) / (height + 1)) * 100.0 << "%\n";
		}
	}

	return ss.str();
}

}  // namespace RenderAlgorithms

#endif	// RENDER_ALGORITHMS_HPP
