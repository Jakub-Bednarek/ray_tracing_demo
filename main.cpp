#include "EasyFileWriter.hpp"
#include "Renderer.hpp"
#include "GlobalConfig.hpp"

#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>

int main()
{
	auto renderedImage = Renderer::renderDefaultScene();
	
	EasyFileWriter::saveToFile("test.ppm", renderedImage);

	return 0;
}
