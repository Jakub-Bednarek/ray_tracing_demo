#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>

#include "include/EasyFileWriter.hpp"
#include "include/RenderAlgorithms.hpp"
#include "include/Vec3.hpp"

int main()
{
	// EasyFileWriter::generateToFile("rayGradientY.ppm", RenderAlgorithms::generateRayGradientY, 1200,
	// 							   800);
	// EasyFileWriter::generateToFile("rayGradientXY.ppm", RenderAlgorithms::generateRayGradientXY, 1200,
	// 							   800);
	EasyFileWriter::generateToFile("rayGradientXYSphere.ppm", RenderAlgorithms::generateRayGradientXYWithSphere, 1280,
								   1280);

	return 0;
}
