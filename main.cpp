#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>

struct EasyFileWriter
{
  private:
	EasyFileWriter(std::string_view fileName, const std::uint32_t width, const std::uint32_t height)
		: fileName(fileName), width(width), height(height)
	{
	}

	std::string fileName;
	std::uint32_t width;
	std::uint32_t height;
};

void createSamplePPMImage(std::string_view fileName, const int width, const int height)
{
	std::cout << "Starting rendering of file\n";

	std::stringstream ss;
	for (int i = 0; i < height; i++)
	{
		std::cout << "Rendering row: " << i << '\n';
		for (int j = 0; j < width; j++)
		{
			auto r = static_cast<int>(std::abs(double(j) / double(width)) * 255.99);
			auto g = static_cast<int>(std::abs(std::sin(i * j)) * 255.99);
			auto b = static_cast<int>(std::abs(std::cos(i + j)) * 255.99);

			ss << r << ' ' << g << ' ' << b << '\n';
		}
	}

	std::cout << "Dumping data to file: " << fileName << '\n';

	auto fileHandle = std::ofstream(fileName.data());
	fileHandle << "P3\n" << width << " " << height << "\n255\n" << ss.str();
	fileHandle.flush();
	fileHandle.close();

	std::cout << "Done.\n";
}

void createGradientPPMImage(std::string_view fileName, const int width, const int height) {}

int main()
{
	createSamplePPMImage("test.ppm", 480, 360);

	return 0;
}
