#include "include/RenderAlgorithms.hpp"
#include "include/EasyFileWriter.hpp"

#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>

int main()
{
	EasyFileWriter::generateToFile("testShapes.ppm", RenderAlgorithms::generateCrazyShapes, 480, 320);
	EasyFileWriter::generateToFile("testGradient.ppm", RenderAlgorithms::generateGradient, 480, 320);

	return 0;
}
