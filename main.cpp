#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>

#include "include/EasyFileWriter.hpp"
#include "include/RenderAlgorithms.hpp"
#include "include/Vec3.hpp"

int main()
{
	EasyFileWriter::generateToFile("testShapes.ppm", RenderAlgorithms::generateCrazyShapes, 480,
								   320);
	EasyFileWriter::generateToFile("testGradient.ppm", RenderAlgorithms::generateGradient, 480,
								   320);

	return 0;
}
