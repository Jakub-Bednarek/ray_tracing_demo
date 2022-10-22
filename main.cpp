#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>

#include "include/EasyFileWriter.hpp"
#include "include/RenderAlgorithms.hpp"
#include "include/Vec3.hpp"

void runAll()
{
	EasyFileWriter::generateToFile("rayGradientY.ppm", RenderAlgorithms::generateRayGradientY, 1280,
								   1280);
	EasyFileWriter::generateToFile("rayGradientXY.ppm", RenderAlgorithms::generateRayGradientXY, 1280,
								   1280);
	EasyFileWriter::generateToFile("rayGradientXYSphere.ppm", RenderAlgorithms::generateRayGradientXYWithSphere, 1280,
								   1280);
	EasyFileWriter::generateToFile("rayGradientInSphere.ppm", RenderAlgorithms::generateRayGradientInSphere, 1280,
								   1280);
}

void runSingle()
{

}

int main()
{
	runAll();
	return 0;
}
