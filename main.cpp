#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>

#include "EasyFileWriter.hpp"
#include "RenderAlgorithms.hpp"
#include "geometry/Vec3.hpp"

void runAll()
{
	EasyFileWriter::generateToFile("rayGradientY.ppm", RenderAlgorithms::generateRayGradientY, 400,
								   400);
	EasyFileWriter::generateToFile("rayGradientXY.ppm", RenderAlgorithms::generateRayGradientXY, 400,
								   400);
	EasyFileWriter::generateToFile("rayGradientXYSphere.ppm", RenderAlgorithms::generateRayGradientXYWithSphere, 400,
								   400);
	EasyFileWriter::generateToFile("rayGradientInSphere.ppm", RenderAlgorithms::generateRayGradientInSphere, 400,
								   400);
}

void runSingle()
{

}

int main()
{
	runAll();
	return 0;
}
