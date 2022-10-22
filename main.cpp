#include "EasyFileWriter.hpp"
#include "RenderAlgorithms.hpp"
#include "GlobalConfig.hpp"
#include "geometry/Vec3.hpp"

#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>

void runAll()
{
	using namespace Config;

	EasyFileWriter::generateToFile("rayGradientY.ppm", RenderAlgorithms::generateRayGradientY, imageWidth,
								   imageHeight);
	EasyFileWriter::generateToFile("rayGradientXY.ppm", RenderAlgorithms::generateRayGradientXY, imageWidth,
								   imageHeight);
	EasyFileWriter::generateToFile("rayGradientXYSphere.ppm", RenderAlgorithms::generateRayGradientXYWithSphere, imageWidth,
								   imageHeight);
	EasyFileWriter::generateToFile("rayGradientInSphere.ppm", RenderAlgorithms::generateRayGradientInSphere, imageWidth,
								   imageHeight);
}

void runSingle()
{
	using namespace Config;

	constexpr auto fileName = "out.ppm";
	// EasyFileWriter::generateToFile(fileName, RenderAlgorithms::generateRayGradientY, imageWidth,
	// 							   imageHeight);
	// EasyFileWriter::generateToFile(fileName, RenderAlgorithms::generateRayGradientXY, imageWidth,
	// 							   imageHeight);
	// EasyFileWriter::generateToFile(fileName, RenderAlgorithms::generateRayGradientXYWithSphere, imageWidth,
	// 							   imageHeight);
	EasyFileWriter::generateToFile(fileName, RenderAlgorithms::generateRayGradientInSphere, imageWidth,
								   imageHeight);
}

int main()
{
	// runAll();
	// runSingle();

	return 0;
}
