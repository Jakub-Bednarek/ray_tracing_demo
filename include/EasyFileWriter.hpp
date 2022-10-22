#ifndef EASY_FILE_WRITER_HPP
#define EASY_FILE_WRITER_HPP

#include <cstdint>
#include <fstream>
#include <functional>
#include <iostream>

struct EasyFileWriter
{
	using ContextGeneratorFunctionPtr =
		std::function<std::string(const std::uint32_t, const std::uint32_t)>;

	static void generateToFile(const std::string& fileName, ContextGeneratorFunctionPtr functionPtr,
							   const std::uint32_t width, const std::uint32_t height, const std::string& directory = "renders/")
	{
		const auto targetDir = directory + "/" + fileName;
		std::cout << "Starting generating file: " << targetDir << '\n';

		auto fileHandle = std::ofstream(targetDir);
		if (fileHandle.is_open())
		{
			fileHandle << "P3\n"
					   << width << " " << height << "\n255\n"
					   << functionPtr(width, height);

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

#endif	// EASY_FILE_WRITER_HPP
