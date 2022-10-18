#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>

#include "include/EasyFileWriter.hpp"
#include "include/RenderAlgorithms.hpp"
#include "include/Vec3.hpp"

int main()
{
	EasyFileWriter::generateToFile("testShapes.ppm", RenderAlgorithms::generateCrazyShapes, 1280,
								   720);
	// EasyFileWriter::generateToFile("testGradient.ppm", RenderAlgorithms::generateGradient, 400,
	// 							   225);

	return 0;
}
