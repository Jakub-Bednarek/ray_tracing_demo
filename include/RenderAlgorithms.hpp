#include <sstream>
#include <cmath>
#include <iostream>
#include <iomanip>

namespace RenderAlgorithms
{

constexpr auto BLUE_GRADIENT_VAL = static_cast<int>(0.25 * 255.99);

std::string generateCrazyShapes(const std::uint32_t width, const std::uint32_t height)
{
	std::stringstream ss {};
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			auto r = static_cast<int>(std::abs(double(j) / double(width)) * 255.99);
			auto g = static_cast<int>(std::abs(std::sin(i * j)) * 255.99);
			auto b = static_cast<int>(std::abs(std::cos(i + j)) * 255.99);

			ss << r << ' ' << g << ' ' << b << '\n';
		}
        
        if(i % 10 == 0)
        {
            std::cout << "Progress: " << std::setprecision(2) << (double(i) / height) * 100.0 << "%\n";
        }
	}

    return ss.str();
}

std::string generateGradient(const std::uint32_t width, const std::uint32_t height)
{
	std::stringstream ss {};
	for (int i = height - 1; i >= 0; i--)
	{
		for (int j = width - 1; j >= 0; j--)
		{
			auto r = static_cast<int>(double(j) / double(width - 1) * 255.99);
			auto g = static_cast<int>(double(i) / double(height - 1)  * 255.99);

			ss << r << ' ' << g << ' ' << BLUE_GRADIENT_VAL << '\n';
		}
        
        if(i % 10 == 0)
        {
            std::cout << "Progress: " << std::setprecision(2) << ((height - double(i + 1)) / (height + 1)) * 100.0 << "%\n";
        }
	}

    return ss.str();
}

}