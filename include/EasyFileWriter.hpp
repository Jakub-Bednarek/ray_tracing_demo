#include <cstdint>
#include <fstream>
#include <functional>
#include <iostream>
#include <string_view>

struct EasyFileWriter
{
	using ContextGeneratorFunctionPtr =
		std::function<std::string(const std::uint32_t, const std::uint32_t)>;

	static void generateToFile(std::string_view fileName, ContextGeneratorFunctionPtr functionPtr,
					  const std::uint32_t width, const std::uint32_t height)
	{
        std::cout << "Starting generating file: " << fileName.data() << '\n';

		auto fileHandle = std::ofstream(fileName.data());
        if(fileHandle.is_open())
        {
		    fileHandle << "P3\n" << width << " " << height << "\n255\n" << functionPtr(width, height);

            std::cout << "Saving data to file. \n";
            fileHandle.close();
        }
        else
        {
            std::cout << "Error: failed to open file!";
        }
        
        std::cout << "Done.\n";
	}
};