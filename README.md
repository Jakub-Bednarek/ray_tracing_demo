# Ray tracing demo
Simple C++ project to learn, experiment and discover ray tracing world. \

**Contents**

- [Available generation algorithms demo](#available-generation-algorithms-demo)
- [Global settings](#global-settings)
- [Choosing algorithms to use](#choosing-algorithms-to-use)
- [Building and running project](#building-and-running-project)

# Available generation algorithms demo

**generateRayGradientY**</br>
======
Generates simple gradient blue -> white based on ray.y() coordinate.

<img src="https://i.imgur.com/1nZklcn.jpg" width="720" height="405" />
</br></br>

**generateRayGradientXY**</br>
======
Generates gradient based on ray.x() and ray.y() coordinates.

<img src="https://i.imgur.com/GpfRTP6.jpg" width="720" height="405" />
</br></br>

**generateRayGradientXYWithSphere**</br>
======
Generates simple gradient as background with red circle in the middle.

<img src="https://i.imgur.com/FT1ATsd.jpg" width="720" height="405" />
</br></br>

**generateRayGradientInSphere**</br>
======
Same functionality as generateRayGradientXYWithSphere, but generated circle is colored with gradient instead of static color. </br></br>

<img src="https://i.imgur.com/CbYasdU.jpg" width="720" height="405" />
</br></br></br>

# Global settings
1. In GlobalConfig.hpp set imageWidth and imageHeight to whatever you wish.
```cpp
namespace Settings
{
constexpr auto imageWidth = YOUR_VALUE_OF_CHOICE;
constexpr auto imageHeight = YOUR_VALUE_OF_CHOICE;
constexpr auto aspectRatio = static_cast<double>(imageWidth) / static_cast<double>(imageHeight); // DO NOT TOUCH THIS!
}
```

# Choosing algorithms to use
Currently there are 2 methods to run algorithms:
1. Using runAll() function in main.cpp 
    1. Uncomment runAll() from main.cpp file (comment runSingle() if you don't want multiple functions running) 
    2. (**!Optional!**) Specify custom file name for each algorithm (it doesn't affect destination directory -> they all go to render/). \
        Simply replace **!MY_CUSTOM_FILE_NAME_STRING!** in algorithm of your choice and you're ready to go!
</br>
```cpp
EasyFileWriter::generateToFile(**!MY_CUSTOM_FILE_NAME_STRING!**, RenderAlgorithms::generateRayGradientY, imageWidth,
                                imageHeight);
```
1. You can also render using single algorithm:
    1. Uncomment runSingle() function in main.cpp, then go to runSingle() and uncomment algorithm you wish to use.
    2. (**!Optional!**)If you want to specify custom file name it's exactly the same as in runAll() function, feel free to use it!

</br>

# Building and running project
Project uses cmake and make to build and run project. Currently available targets:
    - make clean -> clean ./build/ directory
    - make config -> runs cmake config
    - make build -> builds target
    - make run -> runs previously built target
    - make -> configures, builds and runs the target
    - make cpp_tests -> builds and runs cpp uint tests (! currently bugged !)
    - make cpp_config -> runs cmake for cpp unit tests target

Simpliest way to render your beautiful scene:
```
make clean && make
```

That's it!