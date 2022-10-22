#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>

#include "EasyFileWriter.hpp"
#include "RenderAlgorithms.hpp"
#include "geometry/Vec3.hpp"

void runAll()
{
	constexpr auto imageWidth = 600;
	constexpr auto imageHeight = 600;

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

}

int main()
{
	runAll();
	return 0;
}
